/* This file is part of the KDE project
   Copyright (C) 2003-2010 Jarosław Staniek <staniek@kde.org>

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

#include <Predicate/Connection.h>
#include <Predicate/DriverManager.h>
#include <Predicate/Driver_p.h>
#include <Predicate/Utils.h>

#include "SqliteDriver.h"
#include "SqliteConnection.h"
#include "SqliteConnection_p.h"
#include "SqliteAdmin.h"

#include <QtDebug>

#include <sqlite3.h>

using namespace Predicate;

EXPORT_PREDICATE_DRIVER(SQLiteDriver, sqlite)

//! driver specific private data
//! @internal
class Predicate::SQLiteDriverPrivate
{
public:
    SQLiteDriverPrivate() {
    }
};

SQLiteDriver::SQLiteDriver()
        : Driver()
        , dp(0) //TODO new SQLiteDriverPrivate())
{
    d->isDBOpenedAfterCreate = true;
    d->features = SingleTransactions | CursorForward
                  | CompactingDatabaseSupported;

    //special method for autoincrement definition
    beh->SPECIAL_AUTO_INCREMENT_DEF = true;
    beh->AUTO_INCREMENT_FIELD_OPTION = ""; //not available
    beh->AUTO_INCREMENT_TYPE = "INTEGER";
    beh->AUTO_INCREMENT_PK_FIELD_OPTION = "PRIMARY KEY";
    beh->AUTO_INCREMENT_REQUIRES_PK = true;
    beh->ROW_ID_FIELD_NAME = "OID";
    beh->_1ST_ROW_READ_AHEAD_REQUIRED_TO_KNOW_IF_THE_RESULT_IS_EMPTY = true;
    beh->QUOTATION_MARKS_FOR_IDENTIFIER = '"';
    beh->SELECT_1_SUBQUERY_SUPPORTED = true;
    beh->CONNECTION_REQUIRED_TO_CHECK_DB_EXISTENCE = false;
    beh->CONNECTION_REQUIRED_TO_CREATE_DB = false;
    beh->CONNECTION_REQUIRED_TO_DROP_DB = false;

    initDriverSpecificKeywords(keywords);

    //predefined properties
    d->properties["client_library_version"] = sqlite3_libversion();
    d->properties["default_server_encoding"] = "UTF8"; //OK?

    d->typeNames[Field::Byte] = "Byte";
    d->typeNames[Field::ShortInteger] = "ShortInteger";
    d->typeNames[Field::Integer] = "Integer";
    d->typeNames[Field::BigInteger] = "BigInteger";
    d->typeNames[Field::Boolean] = "Boolean";
    d->typeNames[Field::Date] = "Date";       // In fact date/time types could be declared as datetext etc.
    d->typeNames[Field::DateTime] = "DateTime"; // to force text affinity..., see http://sqlite.org/datatype3.html
    d->typeNames[Field::Time] = "Time";       //
    d->typeNames[Field::Float] = "Float";
    d->typeNames[Field::Double] = "Double";
    d->typeNames[Field::Text] = "Text";
    d->typeNames[Field::LongText] = "CLOB";
    d->typeNames[Field::BLOB] = "BLOB";
}

SQLiteDriver::~SQLiteDriver()
{
//    delete dp;
}


Predicate::Connection*
SQLiteDriver::drv_createConnection(const ConnectionData& connData)
{
    return new SQLiteConnection(this, connData);
}

bool SQLiteDriver::isSystemObjectName(const QString& n) const
{
    return Driver::isSystemObjectName(n) || n.toLower().startsWith("sqlite_");
}

bool SQLiteDriver::drv_isSystemFieldName(const QString& n) const
{
    QString lcName = n.toLower();
    return (lcName == "_rowid_")
           || (lcName == "rowid")
           || (lcName == "oid");
}

EscapedString SQLiteDriver::escapeString(const QString& str) const
{
    return EscapedString("'") + EscapedString(str).replace('\'', "''") + '\'';
}

EscapedString SQLiteDriver::escapeString(const QByteArray& str) const
{
    return EscapedString("'") + EscapedString(str).replace('\'', "''") + '\'';
}

EscapedString SQLiteDriver::escapeBLOB(const QByteArray& array) const
{
    return EscapedString(Predicate::escapeBLOB(array, Predicate::BLOBEscapeXHex));
}

QByteArray SQLiteDriver::drv_escapeIdentifier(const QString& str) const
{
    return QByteArray(str.toUtf8()).replace('"', "\"\"");
}

QByteArray SQLiteDriver::drv_escapeIdentifier(const QByteArray& str) const
{
    return QByteArray(str).replace('"', "\"\"");
}

AdminTools* SQLiteDriver::drv_createAdminTools() const
{
    return new SQLiteAdminTools();
}
