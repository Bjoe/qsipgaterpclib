#include <QObject>
#include <QtTest/QtTest>

#include <QString>
#include <QDate>
#include <QDateTime>
#include <QVariant>
#include <QVariantList>
#include <QVariantMap>

#include "samuraihistorygetbydateresponse.h"

namespace tests {

class SamuraiHistoryGetByDateResponseTest : public QObject
{
    Q_OBJECT

private slots:
    void testGet();
};

void SamuraiHistoryGetByDateResponseTest::testGet()
{
    QDateTime time(QDate::currentDate());

    QVariantMap map;
    map.insert("EntryID", QVariant("23"));
    map.insert("Timestamp", QVariant(time));
    map.insert("LocalUri", QVariant("foo"));
    map.insert("RemoteUri", QVariant("bar"));
    map.insert("Status", QVariant("ok"));
    map.insert("TOS", QVariant("la"));

    QVariantList list;
    list.append(map);

    QVariant history(list);
    qsipgaterpclib::SamuraiHistoryGetByDateResponse
            response(history);
    QList<QList<QVariant> > historyList = response.getHistoryEntrys();
    QCOMPARE(historyList.count(), 1);
    QList<QVariant> line = historyList.at(0);
    QCOMPARE(line.at(0), QVariant(23));
    QCOMPARE(line.at(1), QVariant(time));
    QCOMPARE(line.at(2), QVariant("la"));
    QCOMPARE(line.at(3), QVariant("foo"));
    QCOMPARE(line.at(4), QVariant("bar"));
    QCOMPARE(line.at(5), QVariant("ok"));
}

}

QTEST_MAIN(tests::SamuraiHistoryGetByDateResponseTest)
#include "moc_samuraihistorygetbydateresponsetest.cxx"
