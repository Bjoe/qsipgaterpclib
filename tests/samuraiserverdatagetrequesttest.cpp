#include <QObject>
#include <QtTest/QtTest>

#include "samuraiserverdatagetrequest.h"

#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QMap>
#include <QVariantList>

#include "samuraiserverdatagetresponse.h"

namespace tests {

class SamuraiServerdataGetRequestTest : public QObject
{
    Q_OBJECT

private slots:
    void testCreateInstance();
    void testCreateResponse();
    void testCreateResponseFailed();
};

void SamuraiServerdataGetRequestTest::testCreateInstance()
{
    qsipgaterpclib::SamuraiServerdataGetRequest *request =
            qsipgaterpclib::SamuraiServerdataGetRequestFactory::createInstance(this)
            .build();
    QCOMPARE(request->getMethod(), QString("samurai.ServerdataGet"));
    QVariantList list = request->getArguments();
    QCOMPARE(list, QVariantList());
}

void SamuraiServerdataGetRequestTest::testCreateResponse()
{
    qsipgaterpclib::SamuraiServerdataGetRequest *request =
            qsipgaterpclib::SamuraiServerdataGetRequestFactory::createInstance(this)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SamuraiServerdataGetResponse)));

    QVariant dummy(QString("dummy"));
    QVariantMap variantMap;
    variantMap.insert("SipRegistrar", dummy);
    variantMap.insert("SipOutboundProxy", dummy);
    variantMap.insert("StunServer", dummy);
    variantMap.insert("NtpServer", dummy);
    variantMap.insert("HttpServer", dummy);
    variantMap.insert("SamuraiServer", dummy);
    variantMap.insert("SimpleServer", dummy);
    variantMap.insert("XmppServer", dummy);
    QVERIFY(request->createResponse(variantMap) == true);

    QCOMPARE(signalSpy.count(), 1);
    QList<QVariant> arguments = signalSpy.takeFirst();
    QCOMPARE(arguments.count(), 1);
}

void SamuraiServerdataGetRequestTest::testCreateResponseFailed()
{
    qsipgaterpclib::SamuraiServerdataGetRequest *request =
            qsipgaterpclib::SamuraiServerdataGetRequestFactory::createInstance(this)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SamuraiServerdataGetResponse)));

    QVariantMap variantMap;
    QVERIFY(request->createResponse(variantMap) == false);

    QCOMPARE(signalSpy.count(), 0);
}

}

QTEST_MAIN(tests::SamuraiServerdataGetRequestTest)
#include "moc_samuraiserverdatagetrequesttest.cxx"

