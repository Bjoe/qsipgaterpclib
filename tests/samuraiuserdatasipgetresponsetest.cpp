#include <QObject>
#include <QtTest/QtTest>

#include <QString>
#include <QList>
#include <QVariant>
#include <QVariantList>
#include <QVariantMap>

#include "samuraiuserdatasipgetresponse.h"

namespace tests {

class SamuraiUserdataSipGetResponseTest : public QObject
{
    Q_OBJECT

private slots:
    void testGet();
};

void SamuraiUserdataSipGetResponseTest::testGet()
{
    QVariantMap map;
    map.insert("LocalUri", QVariant("aLocalUri"));
    map.insert("SipUserID", QVariant("aSipUserID"));
    map.insert("SipPassword", QVariant("aSipPassword"));

    QVariantList list;
    list.append(map);
    QVariant variant(list);
    qsipgaterpclib::SamuraiUserdataSipGetResponse
            response(variant);
    QList<QList<QVariant> > sipDataList = response.getSipDataList();
    QCOMPARE(sipDataList.count(), 1);
    QList<QVariant> line = sipDataList.at(0);
    QCOMPARE(line.at(0), QVariant("aLocalUri"));
    QCOMPARE(line.at(1), QVariant("aSipUserID"));
    QCOMPARE(line.at(2), QVariant("aSipPassword"));
}

}

QTEST_MAIN(tests::SamuraiUserdataSipGetResponseTest)
#include "moc_samuraiuserdatasipgetresponsetest.cxx"
