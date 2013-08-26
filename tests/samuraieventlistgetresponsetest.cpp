#include <QObject>
#include <QtTest/QtTest>

#include <QString>
#include <QDate>
#include <QDateTime>
#include <QList>
#include <QVariant>
#include <QVariantMap>
#include <QVariantList>

#include "samuraieventlistgetresponse.h"

namespace tests {

class SamuraiEventListGetResponseTest : public QObject
{
    Q_OBJECT

private slots:
    void testGet();
};

void SamuraiEventListGetResponseTest::testGet()
{
    QDateTime time(QDate::currentDate());

    QVariantMap map;
    map.insert("EventID", QVariant("23"));
    map.insert("SourceUri", QVariant("suri"));
    map.insert("TargetUri", QVariant("turi"));
    map.insert("Timestamp", QVariant(time));
    map.insert("SizeDepend", QVariant(100));
    map.insert("TOS", QVariant("sot"));
    map.insert("UnRead", QVariant(true));


    QVariantMap contentMap;
    contentMap.insert("SizeBytes", QVariant(200));
    contentMap.insert("SizeDepend", QVariant(300));
    contentMap.insert("DownloadUriHttp", QVariant("http://localhost"));
    contentMap.insert("ContentType", QVariant("html/text"));

    QVariantList contentList;
    contentList.append(contentMap);

    map.insert("ContentList", QVariant(contentList));

    QStringList labelList;
    labelList.append("foolabel");

    map.insert("Labels", QVariant(labelList));

    QVariantList list;
    list.append(map);

    qsipgaterpclib::SamuraiEventListGetResponse response(1, QVariant(list));

    QCOMPARE(response.getOverallCount(), 1);

    QList<QVariantList> entryList = response.getEventList();
    QCOMPARE(entryList.count(), 1);
    QVariantList line = entryList.at(0);
    QCOMPARE(line.at(0), QVariant("23"));
    QCOMPARE(line.at(1), QVariant("suri"));
    QCOMPARE(line.at(2), QVariant("turi"));
    QCOMPARE(line.at(3), QVariant(time));
    QCOMPARE(line.at(4), QVariant(100));
    QCOMPARE(line.at(5), QVariant("sot"));
    QCOMPARE(line.at(6), QVariant(true));

    QVariant contentVariant = line.at(7);
    QVariantList contentVariantList = contentVariant.toList();
    QCOMPARE(contentVariantList.count(), 1);
    QVariantList contentLine = contentVariantList.at(0).toList();
    QCOMPARE(contentLine.at(0), QVariant(200));
    QCOMPARE(contentLine.at(1), QVariant(300));
    QCOMPARE(contentLine.at(2), QVariant("http://localhost"));
    QCOMPARE(contentLine.at(3), QVariant("html/text"));

    QVariant labelsVariant = line.at(8);
    QVariantList labels = labelsVariant.toList();
    QCOMPARE(labels.at(0), QVariant("foolabel"));
}

}

QTEST_MAIN(tests::SamuraiEventListGetResponseTest)
#include "moc_samuraieventlistgetresponsetest.cxx"

