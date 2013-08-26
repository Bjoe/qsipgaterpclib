#include <QObject>
#include <QtTest/QtTest>

#include <QVariant>
#include <QVariantMap>
#include <QVariantList>

#include "samuraiphonebookentrygetresponse.h"

namespace tests {

class SamuraiPhonebookEntryGetResponseTest : public QObject
{
    Q_OBJECT

private slots:
    void testGet();
};

void SamuraiPhonebookEntryGetResponseTest::testGet()
{
    QVariantMap map;
    map.insert("EntryID",QVariant("anEntryId"));
    map.insert("EntryHash",QVariant("anEntryHash"));
    map.insert("Entry",QVariant("anEntry"));

    QVariantList list;
    list.append(map);

    QVariant variant(list);
    qsipgaterpclib::SamuraiPhonebookEntryGetResponse
            response(variant);
    QList<QList<QVariant> > entryIdList = response.getEntryList();
    QCOMPARE(entryIdList.count(), 1);
    QList<QVariant> entry = entryIdList.at(0);
    QCOMPARE(entry.at(0), QVariant("anEntryId"));
    QCOMPARE(entry.at(1), QVariant("anEntryHash"));
    QCOMPARE(entry.at(2), QVariant("anEntry"));
}

}

QTEST_MAIN(tests::SamuraiPhonebookEntryGetResponseTest)
#include "moc_samuraiphonebookentrygetresponsetest.cxx"
