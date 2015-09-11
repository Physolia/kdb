/* This file is part of the KDE project
   Copyright (C) 2015 Laurent Montel <montel@kde.org>

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

#ifndef KDB_POSTGRESQL_DEBUG_H
#define KDB_POSTGRESQL_DEBUG_H

#include "config-kdb.h"

#include <QLoggingCategory>
Q_DECLARE_LOGGING_CATEGORY(KDB_POSTGRESQLDRIVER_LOG)

//! Debug command for the driver
#define postgresqlDebug(...) qCDebug(KDB_POSTGRESQLDRIVER_LOG, __VA_ARGS__)

//! Warning command for the driver
#define postgresqlWarning(...) qCWarning(KDB_POSTGRESQLDRIVER_LOG, __VA_ARGS__)

//! Critical command for the driver
#define postgresqlCritical(...) qCCritical(KDB_POSTGRESQLDRIVER_LOG, __VA_ARGS__)

#endif
