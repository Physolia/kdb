/* This file is part of the KDE project
   Copyright (C) 2003 Jaroslaw Staniek <js@iidea.pl>

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
   the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.
*/

#include <kexidb/transaction.h>
#include <kexidb/connection.h>

#include <kdebug.h>

#include <assert.h>

using namespace KexiDB;

TransactionData::TransactionData(Connection *conn)
 : m_conn(conn)
 , m_active(true)
 , refcount(1)
{
	assert(conn);
}

TransactionData::~TransactionData()
{
}

//---------------------------------------------------

/*
class Transaction::Private
{
	public:
		Transaction::Private()
		: data(0)
		{
		}
		~Transaction::Private()
		{
			delete data;
		}
		
		Connection *conn;
		TransactionData *data;
};*/
//---------------------------------------------------

Transaction::Transaction()
	: QObject(0,"kexidb_transaction")
	, m_data(0)
{
}

Transaction::Transaction( const Transaction& trans )
	: QObject(0,"kexidb_transaction")
	, m_data(trans.m_data)
{
	if (m_data)
		m_data->refcount++;
}

Transaction::~Transaction()
{
	if (m_data) {
		m_data->refcount--;
		KexiDBDbg << "~Transaction(): m_data->refcount==" << m_data->refcount << endl;
		if (m_data->refcount==0)
			delete m_data;
	}
	else {
		KexiDBDbg << "~Transaction(): null" << endl;
	}
}

Transaction& Transaction::operator=(const Transaction& trans)
{
	if (m_data)
		m_data->refcount--;
	m_data = trans.m_data;
	if (m_data)
		m_data->refcount++;
	return *this;
}

bool Transaction::operator==(const Transaction& trans) const
{
	return m_data==trans.m_data;
}

Connection* Transaction::connection() const
{
	return m_data ? m_data->m_conn : 0;
}

bool Transaction::active() const
{
	return m_data && m_data->m_active;
}

//---------------------------------------------------

TransactionGuard::TransactionGuard( Connection* conn )
 : m_trans( conn->beginTransaction() )
{
	assert(conn);
}

TransactionGuard::TransactionGuard( const Transaction& trans )
 : m_trans(trans)
{
}

TransactionGuard::~TransactionGuard()
{
	if (m_trans.active() && m_trans.connection())
		m_trans.connection()->rollbackTransaction(m_trans);
}

bool TransactionGuard::commit()
{
	if (m_trans.active() && m_trans.connection()) {
		return m_trans.connection()->commitTransaction(m_trans);
	}
	return false;
}

