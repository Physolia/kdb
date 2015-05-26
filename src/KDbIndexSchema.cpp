/* This file is part of the KDE project
   Copyright (C) 2003-2010 Jarosław Staniek <staniek@kde.org>

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

#include "KDbIndexSchema.h"
#include "KDbDriver.h"
#include "KDbConnection.h"
#include "KDbTableSchema.h"

#include <assert.h>


KDbIndexSchema::KDbIndexSchema(KDbTableSchema *tableSchema)
        : KDbFieldList(false)//fields are not owned by KDbIndexSchema object
        , KDbObject(KDb::IndexObjectType)
        , m_tableSchema(tableSchema)
        , m_primary(false)
        , m_unique(false)
        , m_isAutoGenerated(false)
        , m_isForeignKey(false)
{
}

KDbIndexSchema::KDbIndexSchema(const KDbIndexSchema& idx, KDbTableSchema& parentTable)
        : KDbFieldList(false)//fields are not owned by KDbIndexSchema object
        , KDbObject(static_cast<const KDbObject&>(idx))
        , m_tableSchema(&parentTable)
        , m_primary(idx.m_primary)
        , m_unique(idx.m_unique)
        , m_isAutoGenerated(idx.m_isAutoGenerated)
        , m_isForeignKey(idx.m_isForeignKey)
{
    //deep copy of the fields
    foreach(KDbField *f, idx.m_fields) {
        KDbField *parentTableField = parentTable.field(f->name());
        if (!parentTableField) {
            KDbWarn << "cannot find field" << f->name() << "in parentTable. Empty index will be created!";
            KDbFieldList::clear();
            break;
        }
        addField(parentTableField);
    }

//! @todo copy relationships!
// Reference::List m_refs_to; //! list of references to table (of this index)
// Reference::List m_refs_from; //! list of references from the table (of this index),
//         //! this index is foreign key for these references
//         //! and therefore - owner of these
}

KDbIndexSchema::~KDbIndexSchema()
{
    /* It's a list of relationships to the table (of this index), i.e. any such relationship in which
     the table is at 'master' side will be cleared and relationships will be destroyed.
     So, we need to detach all these relationships from details-side, corresponding indices.
    */
    foreach(KDbRelationship* rel, m_master_owned_rels) {
        if (rel->detailsIndex()) {
            rel->detailsIndex()->detachRelationship(rel);
        }
    }
    qDeleteAll(m_master_owned_rels);
}

KDbFieldList& KDbIndexSchema::addField(KDbField *field)
{
    if (field->table() != m_tableSchema) {
        KDbWarn << (field ? field->name() : QString())
        << "WARNING: field does not belong to the same table"
        << (field && field->table() ? field->table()->name() : QString())
        << "as index!";
        return *this;
    }
    return KDbFieldList::addField(field);
}


KDbTableSchema* KDbIndexSchema::table() const
{
    return m_tableSchema;
}

bool KDbIndexSchema::isAutoGenerated() const
{
    return m_isAutoGenerated;
}

void KDbIndexSchema::setAutoGenerated(bool set)
{
    m_isAutoGenerated = set;
}

bool KDbIndexSchema::isPrimaryKey() const
{
    return m_primary;
}

void KDbIndexSchema::setPrimaryKey(bool set)
{
    m_primary = set;
    if (m_primary)
        m_unique = true;
}

bool KDbIndexSchema::isUnique() const
{
    return m_unique;
}

void KDbIndexSchema::setUnique(bool set)
{
    m_unique = set;
    if (!m_unique)
        m_primary = false;
}

bool KDbIndexSchema::isForeignKey() const
{
    return m_isForeignKey;
}

void KDbIndexSchema::setForeignKey(bool set)
{
    m_isForeignKey = set;
    if (m_isForeignKey) {
        setUnique(false);
    }
    if (fieldCount() == 1) {
        m_fields.first()->setForeignKey(true);
    }
}

KDB_EXPORT QDebug operator<<(QDebug dbg, const KDbIndexSchema& index)
{
    dbg.nospace() << QLatin1String("INDEX");
    dbg.space() << static_cast<const KDbObject&>(index) << '\n';
    dbg.space() << (index.isForeignKey() ? "FOREIGN KEY" : "");
    dbg.space() << (index.isAutoGenerated() ? "AUTOGENERATED" : "");
    dbg.space() << (index.isPrimaryKey() ? "PRIMARY" : "");
    dbg.space() << ((!index.isPrimaryKey()) && index.isUnique() ? "UNIQUE" : "");
    dbg.space() << static_cast<const KDbFieldList&>(index);
    return dbg.space();
}

void KDbIndexSchema::attachRelationship(KDbRelationship *rel)
{
    attachRelationship(rel, true);
}

void KDbIndexSchema::attachRelationship(KDbRelationship *rel, bool ownedByMaster)
{
    if (!rel)
        return;
    if (rel->masterIndex() == this) {
        if (ownedByMaster) {
            if (!m_master_owned_rels.contains(rel)) {
                m_master_owned_rels.insert(rel);
            }
        } else {//not owned
            if (!m_master_rels.contains(rel)) {
                m_master_rels.append(rel);
            }
        }
    } else if (rel->detailsIndex() == this) {
        if (!m_details_rels.contains(rel)) {
            m_details_rels.append(rel);
        }
    }
}

void KDbIndexSchema::detachRelationship(KDbRelationship *rel)
{
    if (!rel)
        return;
    m_master_owned_rels.remove(rel);   //for sanity
    m_master_rels.takeAt(m_master_rels.indexOf(rel));   //for sanity
    m_details_rels.takeAt(m_details_rels.indexOf(rel));   //for sanity
}
