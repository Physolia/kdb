/* This file is part of the KDE project
   Copyright (C) 2003-2012 Jarosław Staniek <staniek@kde.org>

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this program; see the file COPYING.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
*/

#include "SqliteConnection.h"
#include "SqliteConnection_p.h"
#include "SqliteCursor.h"
#include "SqlitePreparedStatement.h"

#include <sqlite3.h>

#include "KDbDriver.h"
#include "KDbCursor.h"
#include "KDbError.h"
#include "KDbUtils.h"

#include <QFile>
#include <QDir>
#include <QRegExp>

//remove debug
#undef KDbDrvDbg
#define KDbDrvDbg if (true); else qDebug()

SqliteConnectionInternal::SqliteConnectionInternal(KDbConnection *connection)
        : KDbConnectionInternal(connection)
        , data(0)
        , data_owned(true)
        , m_extensionsLoadingEnabled(false)
{
}

SqliteConnectionInternal::~SqliteConnectionInternal()
{
    if (data_owned && data) {
        sqlite3_close(data);
        data = 0;
    }
}

static const char* const serverResultNames[] = {
    "SQLITE_OK", // 0
    "SQLITE_ERROR",
    "SQLITE_INTERNAL",
    "SQLITE_PERM",
    "SQLITE_ABORT",
    "SQLITE_BUSY",
    "SQLITE_LOCKED",
    "SQLITE_NOMEM",
    "SQLITE_READONLY",
    "SQLITE_INTERRUPT",
    "SQLITE_IOERR",
    "SQLITE_CORRUPT",
    "SQLITE_NOTFOUND",
    "SQLITE_FULL",
    "SQLITE_CANTOPEN",
    "SQLITE_PROTOCOL",
    "SQLITE_EMPTY",
    "SQLITE_SCHEMA",
    "SQLITE_TOOBIG",
    "SQLITE_CONSTRAINT",
    "SQLITE_MISMATCH",
    "SQLITE_MISUSE",
    "SQLITE_NOLFS",
    "SQLITE_AUTH",
    "SQLITE_FORMAT",
    "SQLITE_RANGE",
    "SQLITE_NOTADB", // 26
};

void SqliteConnectionInternal::storeResult()
{
}

// static
QString SqliteConnectionInternal::serverResultName(int serverResultCode)
{
    if (serverResultCode >= 0 && serverResultCode <= SQLITE_NOTADB)
        return QString::fromLatin1(serverResultNames[serverResultCode]);
    else if (serverResultCode == SQLITE_ROW)
        return QLatin1String("SQLITE_ROW");
    else if (serverResultCode == SQLITE_DONE)
        return QLatin1String("SQLITE_DONE");
    return QString();
}

bool SqliteConnectionInternal::extensionsLoadingEnabled() const
{
    return m_extensionsLoadingEnabled;
}

void SqliteConnectionInternal::setExtensionsLoadingEnabled(bool set)
{
    if (set == m_extensionsLoadingEnabled)
        return;
    sqlite3_enable_load_extension(data, set);
    m_extensionsLoadingEnabled = set;
}

/*! Used by driver */
SqliteConnection::SqliteConnection(KDbDriver *driver, const KDbConnectionData& connData)
        : KDbConnection(driver, connData)
        , d(new SqliteConnectionInternal(this))
{
}

SqliteConnection::~SqliteConnection()
{
    KDbDrvDbg;
    //disconnect if was connected
// disconnect();
    destroy();
    delete d;
    KDbDrvDbg << "ok";
}

void SqliteConnection::storeResult()
{
    m_result.setServerMessage(
        QLatin1String( (d->data && m_result.isError()) ? sqlite3_errmsg(d->data) : 0 ));
}

bool SqliteConnection::drv_connect()
{
    return true;
}

bool SqliteConnection::drv_getServerVersion(KDbServerVersionInfo* version)
{
    KDbDrvDbg;
    version->setString(QLatin1String(SQLITE_VERSION)); //defined in sqlite3.h
    QRegExp re(QLatin1String("(\\d+)\\.(\\d+)\\.(\\d+)"));
    if (re.exactMatch(version->string())) {
        version->setMajor(re.cap(1).toUInt());
        version->setMinor(re.cap(2).toUInt());
        version->setRelease(re.cap(3).toUInt());
    }
    return true;
}

bool SqliteConnection::drv_disconnect()
{
    KDbDrvDbg;
    return true;
}

bool SqliteConnection::drv_getDatabasesList(QStringList* list)
{
    //this is one-db-per-file database
    list->append(data().databaseName());
    return true;
}

bool SqliteConnection::drv_containsTable(const QString &tableName)
{
    bool success = false;
    return resultExists(KDbEscapedString("SELECT name FROM sqlite_master WHERE type='table' AND name LIKE %1")
                        .arg(escapeString(tableName)), &success) && success;
}

bool SqliteConnection::drv_getTablesList(QStringList* list)
{
    KDbCursor *cursor;
    if (!(cursor = executeQuery(KDbEscapedString("SELECT name FROM sqlite_master WHERE type='table'")))) {
        KDbWarn << "!executeQuery()";
        return false;
    }
    list->clear();
    cursor->moveFirst();
    while (!cursor->eof() && !cursor->result().isError()) {
        *list += cursor->value(0).toString();
        cursor->moveNext();
    }
    if (cursor->result().isError()) {
        deleteCursor(cursor);
        return false;
    }
    return deleteCursor(cursor);
}

bool SqliteConnection::drv_createDatabase(const QString &dbName)
{
    Q_UNUSED(dbName);
    return drv_useDatabaseInternal(0, 0, true/*create if missing*/);
}

bool SqliteConnection::drv_useDatabase(const QString &dbName, bool *cancelled,
                                       KDbMessageHandler* msgHandler)
{
    Q_UNUSED(dbName);
    return drv_useDatabaseInternal(cancelled, msgHandler, false/*do not create if missing*/);
}

bool SqliteConnection::drv_useDatabaseInternal(bool *cancelled,
                                               KDbMessageHandler* msgHandler, bool createIfMissing)
{
//! @todo add option (command line or in kdbrc?)
//! @todo   int exclusiveFlag = KDbConnection::isReadOnly() ? SQLITE_OPEN_READONLY : SQLITE_OPEN_WRITE_LOCKED; // <-- shared read + (if !r/o): exclusive write
    int openFlags = 0;
    if (isReadOnly()) {
        openFlags |= SQLITE_OPEN_READONLY;
    }
    else {
        openFlags |= SQLITE_OPEN_READWRITE;
        if (createIfMissing) {
            openFlags |= SQLITE_OPEN_CREATE;
        }
    }

//! @todo add option
//    int allowReadonly = 1;
//    const bool wasReadOnly = KDbConnection::isReadOnly();

    int res = sqlite3_open_v2(
                 data().databaseName().toUtf8().constData(), /* unicode expected since SQLite 3.1 */
                 &d->data,
                 openFlags, /*exclusiveFlag,
                 allowReadonly *//* If 1 and locking fails, try opening in read-only mode */
                 0
             );
    if (res != SQLITE_OK) {
        m_result.setServerErrorCode(res);
    }
    storeResult();

    if (!m_result.isError()) {
        // Set the secure-delete on, so SQLite overwrites deleted content with zeros.
        // The default setting is determined by the SQLITE_SECURE_DELETE compile-time option but we overwrite it here.
        // Works with 3.6.23. Earlier version just ignore this pragma.
        // See http://www.sqlite.org/pragma.html#pragma_secure_delete
//! @todo add connection flags to the driver and global setting to control the "secure delete" pragma
        if (!drv_executeSQL(KDbEscapedString("PRAGMA secure_delete = on"))) {
            drv_closeDatabaseSilently();
            return false;
        }
        // Load ICU extension for unicode collations
        bool icuExtensionLoaded = false;
        const QStringList libraryPaths(KDb::libraryPaths());
        foreach (const QString& path, libraryPaths) {
            QString icuExtensionFilename = path + QLatin1String("/sqlite3/kdb_sqlite_icu" KDB_SHARED_LIB_EXTENSION);
            if (loadExtension(icuExtensionFilename)) {
                icuExtensionLoaded = true;
                break;
            }
        }
        if (!icuExtensionLoaded) {
            drv_closeDatabaseSilently();
            return false;
        }
        // load ROOT collation for use as default collation
        if (!drv_executeSQL(KDbEscapedString("SELECT icu_load_collation('', '')"))) {
            drv_closeDatabaseSilently();
            return false;
        }
    }

//! @todo check exclusive status
    Q_UNUSED(cancelled);
    Q_UNUSED(msgHandler);
//! @todo removed in kdb - reenable?
/*
    if (d->res == SQLITE_OK && cancelled && !wasReadOnly && allowReadonly && isReadOnly()) {
        //opened as read only, ask
        if (KDbMessageHandler::Continue !=
                askQuestion(
                    KDbMessageHandler::WarningContinueCancel,
                    futureTr("Do you want to open file \"%1\" as read-only?\n\n"
                        "The file is probably already open on this or another computer. "
                        "Could not gain exclusive access for writing the file.")
                    .arg(QDir::fromNativeSeparators(data()->databaseName())),
                    futureTr("Opening As Read-Only"),
                    KDbMessageHandler::Continue,
                    KDbMessageHandler::KDbGuiItem()
                            .setProperty("text", futureTr("Open As Read-Only"))
                            .setProperty("icon", "document-open"),
                    KDbMessageHandler::KDbGuiItem(),
                    "askBeforeOpeningFileReadOnly",
                    KDbMessageHandler::Notify,
                    msgHandler)
        {
            clearError();
            if (!drv_closeDatabase())
                return false;
            *cancelled = true;
            return false;
        }
    }

    if (d->res == SQLITE_CANTOPEN_WITH_LOCKED_READWRITE) {
        setError(ERR_ACCESS_RIGHTS,
                 futureTr("The file is probably already open on this or another computer.\n\n"
                          "Could not gain exclusive access for reading and writing the file. "
                          "Check the file's permissions and whether it is already opened and locked by another application."));
    } else if (d->res == SQLITE_CANTOPEN_WITH_LOCKED_WRITE) {
        setError(ERR_ACCESS_RIGHTS,
                 futureTr("The file is probably already open on this or another computer.\n\n"
                          "Could not gain exclusive access for writing the file. "
                          "Check the file's permissions and whether it is already opened and locked by another application."));
    }*/
    return res == SQLITE_OK;
}

void SqliteConnection::drv_closeDatabaseSilently()
{
    KDbResult result = this->result(); // save
    drv_closeDatabase();
    m_result = result;
}

bool SqliteConnection::drv_closeDatabase()
{
    if (!d->data)
        return false;

    const int res = sqlite3_close(d->data);
    if (SQLITE_OK == res) {
        d->data = 0;
        return true;
    }
    if (SQLITE_BUSY == res) {
#if 0 //this is ANNOYING, needs fixing (by closing cursors or waiting)
        setError(ERR_CLOSE_FAILED, futureTr("Could not close busy database."));
#else
        return true;
#endif
    }
    return false;
}

bool SqliteConnection::drv_dropDatabase(const QString &dbName)
{
    Q_UNUSED(dbName); // Each database is one single SQLite file.
    const QString filename = data().databaseName();
    if (QFile::exists(filename) && !QFile::remove(filename)) {
        m_result = KDbResult(ERR_ACCESS_RIGHTS,
                          QObject::tr("Could not remove file \"%1\". "
                             "Check the file's permissions and whether it is already "
                             "opened and locked by another application.")
                   .arg(QDir::fromNativeSeparators(filename)));
        return false;
    }
    return true;
}

KDbCursor* SqliteConnection::prepareQuery(const KDbEscapedString& sql, uint cursor_options)
{
    return new SqliteCursor(this, sql, cursor_options);
}

KDbCursor* SqliteConnection::prepareQuery(KDbQuerySchema* query, uint cursor_options)
{
    return new SqliteCursor(this, query, cursor_options);
}

bool SqliteConnection::drv_executeSQL(const KDbEscapedString& sql)
{
#ifdef KDB_DEBUG_GUI
    KDb::debugGUI(QLatin1String("ExecuteSQL (SQLite): ") + sql.toString());
#endif

    char *errmsg_p = 0;
    int res = sqlite3_exec(
                 d->data,
                 sql.constData(),
                 0/*callback*/,
                 0,
                 &errmsg_p);
    if (res != SQLITE_OK) {
        m_result.setServerErrorCode(res);
    }
    if (errmsg_p) {
        clearResult();
        m_result.setServerMessage(QLatin1String(errmsg_p));
        sqlite3_free(errmsg_p);
    }

    storeResult();
#ifdef KDB_DEBUG_GUI
    KDb::debugGUI(QLatin1String( res == SQLITE_OK ? "  Success" : "  Failure"));
#endif
    return res == SQLITE_OK;
}

quint64 SqliteConnection::drv_lastInsertRecordId()
{
    return (quint64)sqlite3_last_insert_rowid(d->data);
}

QString SqliteConnection::serverResultName() const
{
    return SqliteConnectionInternal::serverResultName(m_result.serverErrorCode());
}

KDbPreparedStatementInterface* SqliteConnection::prepareStatementInternal()
{
    return new SqlitePreparedStatement(d);
}

bool SqliteConnection::isReadOnly() const
{
    return KDbConnection::isReadOnly();
//! @todo port
    //return (d->data ? sqlite3_is_readonly(d->data) : false)
    //       || KDbConnection::isReadOnly();
}

bool SqliteConnection::loadExtension(const QString& path)
{
    bool tempEnable = false;
    clearResult();
    QFileInfo fileInfo(path);
    if (!fileInfo.exists()) {
        m_result = KDbResult(ERR_OBJECT_NOT_FOUND,
                             QObject::tr("Could not find SQLite extension file \"%1\".").arg(path));
        KDbWarn << "SqliteConnection::loadExtension(): Could not load SQLite extension";
        return false;
    }
    if (!d->extensionsLoadingEnabled()) {
        tempEnable = true;
        d->setExtensionsLoadingEnabled(true);
    }
    char *errmsg_p = 0;
    int res = sqlite3_load_extension(d->data, path.toUtf8().constData(), 0, &errmsg_p);
    bool ok = res == SQLITE_OK;
    if (!ok) {
        m_result.setServerErrorCode(res);
        m_result = KDbResult(ERR_CANNOT_LOAD_OBJECT,
                             QObject::tr("Could not load SQLite extension \"%1\".").arg(path));
        KDbWarn << "SqliteConnection::loadExtension(): Could not load SQLite extension"
                << path << ":" << errmsg_p;
        if (errmsg_p) {
            m_result.setServerMessage(QLatin1String(errmsg_p));
            sqlite3_free(errmsg_p);
        }
    }
    if (tempEnable) {
        d->setExtensionsLoadingEnabled(false);
    }
    return ok;
}
