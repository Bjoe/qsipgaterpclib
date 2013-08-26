#include <QObject>
#include <QtTest/QtTest>

#include <QList>
#include <QVariant>
#include <QVariantList>
#include <QVariantMap>

#include "samuraiownurilistgetresponse.h"

namespace tests {

class SamuraiOwnUriListGetResponseTest : public QObject
{
    Q_OBJECT

private slots:
    void testGet();
};

void SamuraiOwnUriListGetResponseTest::testGet()
{
    QVariantList e164InList;
    e164InList.append(QVariant("anE164IN-1"));

    QVariantList tosList;
    tosList.append(QVariant("aTOS-1"));

    QVariantMap map;
    map.insert("SipUri", QVariant("aSipUri"));
    map.insert("E164Out", QVariant("aE164Out"));
    map.insert("E164In", QVariant(e164InList));
    map.insert("TOS", QVariant(tosList));
    map.insert("DefaultUri", QVariant("aDefaultUri"));
    map.insert("UriAlias", QVariant("anUriAlias"));

    QVariantList list;
    list.append(QVariant(map));
    QVariant variant(list);
    qsipgaterpclib::SamuraiOwnUriListGetResponse
            response(variant);
    QList<QList<QVariant> > uriList = response.getOwnUriList();
    QCOMPARE(uriList.count(), 1);
    QList<QVariant> line = uriList.at(0);
    QCOMPARE(line.at(0), QVariant("aSipUri"));
    QCOMPARE(line.at(1), QVariant("aE164Out"));
    QCOMPARE(line.at(4), QVariant("aDefaultUri"));
    QCOMPARE(line.at(5), QVariant("anUriAlias"));

    QList<QVariant> eList = line.at(2).toList();
    QCOMPARE(eList.at(0), QVariant("anE164IN-1"));

    QList<QVariant> tList = line.at(3).toList();
    QCOMPARE(tList.at(0), QVariant("aTOS-1"));
}

}

QTEST_MAIN(tests::SamuraiOwnUriListGetResponseTest)
#include "moc_samuraiownurilistgetresponsetest.cxx"
