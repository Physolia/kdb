/* This file is part of the KDE project
   Copyright (C) 2006-2012 Jarosław Staniek <staniek@kde.org>

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

#include "MysqlPreparedStatement.h"
#include "KDbConnection.h"

#include <mysql/errmsg.h>

// For example prepared MySQL statement code see:
// http://dev.mysql.com/doc/refman/4.1/en/mysql-stmt-execute.html

MysqlPreparedStatement::MysqlPreparedStatement(MysqlConnectionInternal* conn)
        : KDbPreparedStatementInterface()
        , MysqlConnectionInternal(conn->connection)
#ifdef KDB_USE_MYSQL_STMT
        , m_statement(0)
        , m_mysqlBind(0)
#endif
        , m_resetRequired(false)
{
// mysqlDebug();
    mysql_owned = false;
    mysql = conn->mysql;
    if (!init()) {
        done();
    }
}

bool MysqlPreparedStatement::init()
{
#ifdef KDB_USE_MYSQL_STMT
    m_statement = mysql_stmt_init(mysql);
    if (!m_statement) {
//! @todo err 'out of memory'
        return false;
    }
    res = mysql_stmt_prepare(m_statement,
                             (const char*)m_tempStatementString, m_tempStatementString.length());
    if (0 != res) {
//! @todo use mysql_stmt_error(stmt); to show error
        return false;
    }

    m_realParamCount = mysql_stmt_param_count(m_statement);
    if (m_realParamCount <= 0) {
//! @todo err
        return false;
    }
    m_mysqlBind = new MYSQL_BIND[ m_realParamCount ];
    memset(m_mysqlBind, 0, sizeof(MYSQL_BIND)*m_realParamCount); //safe?
#endif
    return true;
}

MysqlPreparedStatement::~MysqlPreparedStatement()
{
    done();
}

void MysqlPreparedStatement::done()
{
#ifdef KDB_USE_MYSQL_STMT
    if (m_statement) {
//! @todo handle errors of mysql_stmt_close()?
        mysql_stmt_close(m_statement);
        m_statement = 0;
    }
    delete m_mysqlBind;
    m_mysqlBind = 0;
#endif
}

bool MysqlPreparedStatement::prepare(const KDbEscapedString& sql)
{
    Q_UNUSED(sql);
    return true;
}

#ifdef KDB_USE_MYSQL_STMT
#define BIND_NULL { \
        m_mysqlBind[arg].buffer_type = MYSQL_TYPE_NULL; \
        m_mysqlBind[arg].buffer = 0; \
        m_mysqlBind[arg].buffer_length = 0; \
        m_mysqlBind[arg].is_null = &dummyNull; \
        m_mysqlBind[arg].length = &str_length; }

bool MysqlPreparedStatement::bindValue(KDbField *field, const QVariant& value, int arg)
{
    if (value.isNull()) {
        // no value to bind or the value is null: bind NULL
        BIND_NULL;
        return true;
    }

    if (field->isTextType()) {
//! @todo optimize
        m_stringBuffer[ 1024 ]; ? ? ?
        char *str = qstrncpy(m_stringBuffer, (const char*)value.toString().toUtf8(), 1024);
        m_mysqlBind[arg].buffer_type = MYSQL_TYPE_STRING;
        m_mysqlBind[arg].buffer = m_stringBuffer;
        m_mysqlBind[arg].is_null = (my_bool*)0;
        m_mysqlBind[arg].buffer_length = 1024; //?
        m_mysqlBind[arg].length = &str_length;
        return true;
    }

    switch (field->type()) {
    case KDbField::Byte:
    case KDbField::ShortInteger:
    case KDbField::Integer: {
        //! @todo what about unsigned > INT_MAX ?
        bool ok;
        const int intValue = value.toInt(&ok);
        if (ok) {
            if (field->type() == KDbField::Byte)
                m_mysqlBind[arg].buffer_type = MYSQL_TYPE_TINY;
            else if (field->type() == KDbField::ShortInteger)
                m_mysqlBind[arg].buffer_type = MYSQL_TYPE_SHORT;
            else if (field->type() == KDbField::Integer)
                m_mysqlBind[arg].buffer_type = MYSQL_TYPE_LONG;

            m_mysqlBind[arg].is_null = (my_bool*)0;
            m_mysqlBind[arg].length = 0;

            res = sqlite3_bind_int(prepared_st_handle, arg, intValue);
            if (SQLITE_OK != res) {
                //! @todo msg?
                return false;
            }
        } else
            BIND_NULL;
        break;
    }
    case KDbField::Float:
    case KDbField::Double:
        res = sqlite3_bind_double(prepared_st_handle, arg, value.toDouble());
        if (SQLITE_OK != res) {
            //! @todo msg?
            return false;
        }
        break;
    case KDbField::BigInteger: {
        //! @todo what about unsigned > LLONG_MAX ?
        bool ok;
        qint64 int64Value = value.toLongLong(&ok);
        if (ok) {
            res = sqlite3_bind_int64(prepared_st_handle, arg, value);
            if (SQLITE_OK != res) {
                //! @todo msg?
                return false;
            }
        } else {
            res = sqlite3_bind_null(prepared_st_handle, arg);
            if (SQLITE_OK != res) {
                //! @todo msg?
                return false;
            }
        }
        break;
    }
    case KDbField::Boolean:
        res = sqlite3_bind_text(prepared_st_handle, arg,
                                QString::number(value.toBool() ? 1 : 0).toLatin1(),
                                1, SQLITE_TRANSIENT /*??*/);
        if (SQLITE_OK != res) {
            //! @todo msg?
            return false;
        }
        break;
    case KDbField::Time:
        res = sqlite3_bind_text(prepared_st_handle, arg,
                                value.toTime().toString(Qt::ISODate).toLatin1(),
                                sizeof("HH:MM:SS"), SQLITE_TRANSIENT /*??*/);
        if (SQLITE_OK != res) {
            //! @todo msg?
            return false;
        }
        break;
    case KDbField::Date:
        res = sqlite3_bind_text(prepared_st_handle, arg,
                                value.toDate().toString(Qt::ISODate).toLatin1(),
                                sizeof("YYYY-MM-DD"), SQLITE_TRANSIENT /*??*/);
        if (SQLITE_OK != res) {
            //! @todo msg?
            return false;
        }
        break;
    case KDbField::DateTime:
        res = sqlite3_bind_text(prepared_st_handle, arg,
                                value.toDateTime().toString(Qt::ISODate).toLatin1(),
                                sizeof("YYYY-MM-DDTHH:MM:SS"), SQLITE_TRANSIENT /*??*/);
        if (SQLITE_OK != res) {
            //! @todo msg?
            return false;
        }
        break;
    case KDbField::BLOB: {
        const QByteArray byteArray(value.toByteArray());
        res = sqlite3_bind_blob(prepared_st_handle, arg,
                                (const char*)byteArray, byteArray.size(), SQLITE_TRANSIENT /*??*/);
        if (SQLITE_OK != res) {
            //! @todo msg?
            return false;
        }
        break;
    }
    default:
        mysqlWarning() << "unsupported field type:"
            << field->type() << "- NULL value bound to column #" << arg;
        res = sqlite3_bind_null(prepared_st_handle, arg);
        if (SQLITE_OK != res) {
            //! @todo msg?
            return false;
        }
    } //switch
    return true;
}
#endif

KDbSqlResult* MysqlPreparedStatement::execute(
    KDbPreparedStatement::Type type,
    const KDbField::List& selectFieldList,
    KDbFieldList* insertFieldList,
    const KDbPreparedStatementParameters& parameters)
{
    Q_UNUSED(selectFieldList);
#ifdef KDB_USE_MYSQL_STMT
    if (!m_statement || m_realParamCount <= 0)
        return false;
    if (mysql_stmt_errno(m_statement) == CR_SERVER_LOST) {
        //sanity: connection lost: reconnect
//! @todo KDbConnection should be reconnected as well!
        done();
        if (!init()) {
            done();
            return false;
        }
    }

    if (m_resetRequired) {
        mysql_stmt_reset(m_statement);
        res = sqlite3_reset(prepared_st_handle);
        if (SQLITE_OK != res) {
            //! @todo msg?
            return false;
        }
        m_resetRequired = false;
    }

    int par = 0;
    bool dummyNull = true;
    unsigned long str_length;

    //for INSERT, we're iterating over inserting values
    //for SELECT, we're iterating over WHERE conditions
    KDbField::List *fieldList = 0;
    if (m_type == SelectStatement)
        fieldList = m_whereFields;
    else if (m_type == InsertStatement)
        fieldList = m_fields->fields();
    else
        Q_ASSERT(0); //impl. error

    KDbField::ListIterator itFields(fieldList->constBegin());
    for (QList<QVariant>::ConstIterator it(parameters.constBegin());
            itFields != fieldList->constEnd() && arg < m_realParamCount; ++it, ++itFields, par++) {
        if (!bindValue(*itFields, it == parameters.constEnd() ? QVariant() : *it, par))
            return false;

        }//else
    }//for

    //real execution
    res = sqlite3_step(prepared_st_handle);
    m_resetRequired = true;
    if (m_type == InsertStatement && res == SQLITE_DONE) {
        return true;
    }
    if (m_type == SelectStatement) {
        //fetch result

//! @todo
    }
#else
    m_resetRequired = true;
    if (type == KDbPreparedStatement::InsertStatement) {
        const int missingValues = insertFieldList->fieldCount() - parameters.count();
        KDbPreparedStatementParameters myParameters(parameters);
        if (missingValues > 0) {
    //! @todo can be more efficient
            for (int i = 0; i < missingValues; i++) {
                myParameters.append(QVariant());
            }
        }
        KDbSqlResult* result;
        if (connection->insertRecord(insertFieldList, myParameters, &result)) {
            return result;
        }
        return nullptr;
    }
//! @todo support select
#endif // !KDB_USE_MYSQL_STMT
    return nullptr;
}
