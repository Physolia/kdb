/* This file is part of the KDE project
   Copyright (C) 2015 Jarosław Staniek <staniek@kde.org>

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

#include "KDbTestUtils.h"

#include <KDbDriverManager>
#include <KDbDriverMetaData>
#include <KDbConnection>

#include <QFile>
#include <QTest>
#include <QMimeDatabase>

void KDbTestUtils::testDriverManager()
{
    QStringList ids = manager.driverIds();
    qDebug() << "DRIVERS:" << ids;
    QVERIFY2(!manager.result().isError(), "Error in driver manager");
    qDebug() << manager.result().message();
    QVERIFY2(!ids.isEmpty(), "No db drivers found");
}

void KDbTestUtils::testSqliteDriver()
{
    QString drv_id = "org.kde.kdb.sqlite";
    // find the metadata
    const KDbDriverMetaData* driverMetaData = manager.driverMetaData(drv_id);
    KDB_VERIFY(manager.resultable(), driverMetaData = manager.driverMetaData(drv_id), "Driver metadata not found");
    QCOMPARE(driverMetaData->id(), drv_id);
    QVERIFY(driverMetaData->isFileBased());
    // test the mimetypes
    QStringList mimeTypes(driverMetaData->mimeTypes());
    qDebug() << "mimeTypes:" << mimeTypes;
    QVERIFY2(mimeTypes.count() > 1, "Less than two MIME types found");
    QVERIFY(mimeTypes.contains("application/x-kexiproject-sqlite3"));
    QVERIFY(mimeTypes.contains("application/x-sqlite3"));
    QVERIFY(!KDb::defaultFileBasedDriverMimeType().isEmpty());
    QVERIFY2(mimeTypes.contains(KDb::defaultFileBasedDriverMimeType()), "SQLite's MIME types should include the default file based one");
    QMimeDatabase mimeDb;
    foreach(const QString &mimeName, mimeTypes) {
        QVERIFY2(mimeDb.mimeTypeForName(mimeName).isValid(),
                 qPrintable(QString("%1 MIME type not found in the MIME database").arg(mimeName)));
    }
    // find driver for the metadata
    KDB_VERIFY(manager.resultable(), driver = manager.driver(drv_id), "Driver not found");
}
