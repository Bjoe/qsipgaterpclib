#include <QObject>
#include <QtTest/QtTest>

#include "samuraiclientidentifyrequest.h"

#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QMap>
#include <QVariantList>

#include "samuraiclientidentifyresponse.h"

namespace tests {

class SamuraiClientIdentifyRequestTest : public QObject
{
    Q_OBJECT

private slots:
    void testCreateInstance();
    void testCreateResponse();
    void testCreateResponseFailed();
};

void SamuraiClientIdentifyRequestTest::testCreateInstance()
{
    qsipgaterpclib::SamuraiClientIdentifyRequest *request =
            qsipgaterpclib::SamuraiClientIdentifyRequestFactory::createInstance(this)
            .withClientName("foo")
            .withClientVendor("bar")
            .withClientVersion("23")
            .build();
    QCOMPARE(request->getMethod(), QString("samurai.ClientIdentify"));
    QVariantList list = request->getArguments();
    QMap<QString, QVariant> map = list.at(0).toMap();
    QCOMPARE(map.value("ClientName"), QVariant("foo"));
    QCOMPARE(map.value("ClientVendor"), QVariant("bar"));
    QCOMPARE(map.value("ClientVersion"), QVariant("23"));
}

void SamuraiClientIdentifyRequestTest::testCreateResponse()
{
    qsipgaterpclib::SamuraiClientIdentifyRequest *request =
            qsipgaterpclib::SamuraiClientIdentifyRequestFactory::createInstance(this)
            .withClientName("foo")
            .withClientVendor("bar")
            .withClientVersion("23")
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SamuraiClientIdentifyResponse)));

    QVariantMap variantMap;
    QVERIFY(request->createResponse(variantMap) == true);

    QCOMPARE(signalSpy.count(), 1);
    QList<QVariant> arguments = signalSpy.takeFirst();
    QCOMPARE(arguments.count(), 1);
}

void SamuraiClientIdentifyRequestTest::testCreateResponseFailed()
{
    qsipgaterpclib::SamuraiClientIdentifyRequest *request =
            qsipgaterpclib::SamuraiClientIdentifyRequestFactory::createInstance(this)
            .withClientName("foo")
            .withClientVendor("bar")
            .withClientVersion("23")
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SamuraiClientIdentifyResponse)));

    QVariantMap variantMap;
    //QVERIFY(request->createResponse(variantMap) == false);

    QCOMPARE(signalSpy.count(), 0);
}

}

QTEST_MAIN(tests::SamuraiClientIdentifyRequestTest)
#include "moc_samuraiclientidentifyrequesttest.cxx"

