#include <QObject>
#include <QtTest/QtTest>

#include <QVariant>

#include "samuraiserverdatagetresponse.h"

namespace tests {

class SamuraiServerdataGetResponseTest : public QObject
{
    Q_OBJECT

private slots:
    void testGet();
};

void SamuraiServerdataGetResponseTest::testGet()
{
    QVariant sipRegistrarServer("aSipRegistrarServer");
    QVariant sipOutboundProxy("aSipOutboundProxy");
    QVariant stunServer("aStunServer");
    QVariant ntpServer("aNtpServer");
    QVariant httpServer("aHttpServer");
    QVariant samuraiServer("aSamuraiServer");
    QVariant simpleServer("aSimpleServer");
    QVariant xmppServer("aXmppServer");

    qsipgaterpclib::SamuraiServerdataGetResponse
            response(sipRegistrarServer, sipOutboundProxy, stunServer, ntpServer, httpServer,
                     samuraiServer, simpleServer, xmppServer);
    QCOMPARE(response.getSipRegistrarServer(), QString("aSipRegistrarServer"));
    QCOMPARE(response.getSipOutboundProxy(), QString("aSipOutboundProxy"));
    QCOMPARE(response.getStunServer(), QString("aStunServer"));
    QCOMPARE(response.getNtpServer(), QString("aNtpServer"));
    QCOMPARE(response.getHttpServer(), QString("aHttpServer"));
    QCOMPARE(response.getSamuraiServer(), QString("aSamuraiServer"));
    QCOMPARE(response.getSimpleServer(), QString("aSimpleServer"));
    QCOMPARE(response.getXmppServer(), QString("aXmppServer"));
}

}

QTEST_MAIN(tests::SamuraiServerdataGetResponseTest)
#include "moc_samuraiserverdatagetresponsetest.cxx"
