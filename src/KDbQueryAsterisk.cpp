/* This file is part of the KDE project
   Copyright (C) 2003-2016 Jarosław Staniek <staniek@kde.org>

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
*/

#include "KDbQueryAsterisk.h"
#include "KDbQuerySchema.h"
#include "KDbTableSchema.h"

KDbQueryAsterisk::KDbQueryAsterisk(KDbQuerySchema *query, KDbTableSchema *table)
        : KDbField()
        , m_table(table)
{
    Q_ASSERT(query);
    m_parent = query;
    setType(KDbField::Asterisk);
}

KDbQueryAsterisk::KDbQueryAsterisk(KDbQueryAsterisk *asterisk)
        : KDbField(*asterisk)
        , m_table(asterisk->table())
{
}

KDbQueryAsterisk::~KDbQueryAsterisk()
{
}

KDbQuerySchema *KDbQueryAsterisk::query()
{
    return static_cast<KDbQuerySchema*>(m_parent);
}

const KDbQuerySchema *KDbQueryAsterisk::query() const
{
    return static_cast<const KDbQuerySchema*>(m_parent);
}

KDbTableSchema* KDbQueryAsterisk::table()
{
    return m_table;
}

const KDbTableSchema* KDbQueryAsterisk::table() const
{
    return m_table;
}

KDbField* KDbQueryAsterisk::copy()
{
    return new KDbQueryAsterisk(this);
}

void KDbQueryAsterisk::setTable(KDbTableSchema *table)
{
    m_table = table;
}

bool KDbQueryAsterisk::isSingleTableAsterisk() const
{
    return m_table;
}

bool KDbQueryAsterisk::isAllTableAsterisk() const
{
    return !m_table;
}

QDebug operator<<(QDebug dbg, const KDbQueryAsterisk& asterisk)
{
    if (asterisk.isAllTableAsterisk()) {
        dbg.nospace() << "ALL-TABLES ASTERISK (*) ON TABLES(";
        bool first = true;
        foreach(KDbTableSchema *table, *asterisk.query()->tables()) {
            if (first)
                first = false;
            else
                dbg.nospace() << ',';
            dbg.space() << table->name();
        }
        dbg.space() << ')';
    } else {
        dbg.nospace() << "SINGLE-TABLE ASTERISK (" << asterisk.table()->name() << ".*)";
    }
    return dbg.space();
}
