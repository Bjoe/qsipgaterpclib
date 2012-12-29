#include <QObject>
#include <QtTest/QtTest>

#include "systemserverinforesponse.h"

namespace tests {

class SystemServerInfoResponseTest : public QObject
{
    Q_OBJECT

private slots:
    void testGet();
};

void SystemServerInfoResponseTest::testGet()
{
    qsipgaterpclib::SystemServerInfoResponse
            response(QString("foo"), QString("bar"), QString("foobar"), QString("barfoo"));
    QCOMPARE(response.getSpecVersion(), QString("foo"));
    QCOMPARE(response.getServerName(), QString("bar"));
    QCOMPARE(response.getServerVersion(), QString("foobar"));
    QCOMPARE(response.getServerVendor(), QString("barfoo"));
}

}

QTEST_MAIN(tests::SystemServerInfoResponseTest)
#include "moc_systemserverinforesponsetest.cxx"
