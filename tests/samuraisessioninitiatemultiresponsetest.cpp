#include <QObject>
#include <QtTest/QtTest>

#include <QString>
#include <QList>
#include <QVariant>
#include <QVariantList>
#include <QVariantMap>

#include "samuraisessioninitiatemultiresponse.h"

namespace tests {

class SamuraiSessionInitiateMultiResponseTest : public QObject
{
    Q_OBJECT

private slots:
    void testGet();
};

void SamuraiSessionInitiateMultiResponseTest::testGet()
{
    QVariantMap map;
    map.insert("SessionID", QVariant("sessionid"));
    map.insert("RemoteUri", QVariant("remoteuri"));

    QVariantList list;
    list.append(QVariant(map));

    QVariant variant(list);
    qsipgaterpclib::SamuraiSessionInitiateMultiResponse
            response(variant);
    QList<QList<QVariant> > sessionList = response.getSessionList();
    QCOMPARE(sessionList.count(), 1);
    QList<QVariant> line = sessionList.at(0);
    QCOMPARE(line.at(0), QVariant("sessionid"));
    QCOMPARE(line.at(1), QVariant("remoteuri"));
}

}

QTEST_MAIN(tests::SamuraiSessionInitiateMultiResponseTest)
#include "moc_samuraisessioninitiatemultiresponsetest.cxx"
