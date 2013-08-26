#include <QObject>
#include <QtTest/QtTest>

#include <QString>
#include <QList>
#include <QVariant>
#include <QVariantList>
#include <QVariantMap>

#include "samuraiumsummarygetresponse.h"

namespace tests {

class SamuraiUmSummaryGetResponseTest : public QObject
{
    Q_OBJECT

private slots:
    void testGet();
};

void SamuraiUmSummaryGetResponseTest::testGet()
{
    QVariantMap map;
    map.insert("Read", QVariant(23));
    map.insert("Unread", QVariant(42));
    map.insert("LabelName", QVariant("aLabel"));
    map.insert("TOS", QVariant("aTos"));

    QVariantList line;
    line.append(QVariant(map));

    QVariant variant(line);
    qsipgaterpclib::SamuraiUmSummaryGetResponse
            response(variant);
    QList<QList<QVariant> > summaryList = response.getUmSummaryList();
    QCOMPARE(summaryList.count(), 1);
    QList<QVariant> summaryLine = summaryList.at(0);
    QCOMPARE(summaryLine.at(0), QVariant(23));
    QCOMPARE(summaryLine.at(1), QVariant(42));
    QCOMPARE(summaryLine.at(2), QVariant("aLabel"));
    QCOMPARE(summaryLine.at(3), QVariant("aTos"));
}

}

QTEST_MAIN(tests::SamuraiUmSummaryGetResponseTest)
#include "moc_samuraiumsummarygetresponsetest.cxx"
