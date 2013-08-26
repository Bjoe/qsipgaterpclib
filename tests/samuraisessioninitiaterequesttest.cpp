#include <QObject>
#include <QtTest/QtTest>

#include "samuraisessioninitiaterequest.h"

#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QMap>
#include <QVariantList>

#include "samuraisessioninitiateresponse.h"

namespace tests {

class SamuraiSessionInitiateRequestTest : public QObject
{
    Q_OBJECT

private slots:
    void testCreateInstance();
    void testCreateResponse();
    void testCreateResponseFailed();
};

void SamuraiSessionInitiateRequestTest::testCreateInstance()
{
    QDateTime dateTime(QDate::currentDate());

    qsipgaterpclib::SamuraiSessionInitiateRequest *request =
            qsipgaterpclib::SamuraiSessionInitiateRequestFactory::createInstance(this)
            .withLocalUri("localUri")
            .withRemoteUri("remoteUri")
            .withTos("tos")
            .withContent("content")
            .withSchedule(dateTime)
            .build();
    QCOMPARE(request->getMethod(), QString("samurai.SessionInitiate"));
    QVariantList list = request->getArguments();
    QMap<QString, QVariant> map = list.at(0).toMap();
    QCOMPARE(map.value("LocalUri"), QVariant("localUri"));
    QCOMPARE(map.value("RemoteUri"), QVariant("remoteUri"));
    QCOMPARE(map.value("TOS"), QVariant("tos"));
    QCOMPARE(map.value("Content"), QVariant("content"));
    QCOMPARE(map.value("Schedule"), QVariant(dateTime));
}

void SamuraiSessionInitiateRequestTest::testCreateResponse()
{
    qsipgaterpclib::SamuraiSessionInitiateRequest *request =
            qsipgaterpclib::SamuraiSessionInitiateRequestFactory::createInstance(this)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SamuraiSessionInitiateResponse)));

    QVariant dummy(QString("dummy"));
    QVariantMap variantMap;
    variantMap.insert("SessionID", dummy);
    QVERIFY(request->createResponse(variantMap) == true);

    QCOMPARE(signalSpy.count(), 1);
    QList<QVariant> arguments = signalSpy.takeFirst();
    QCOMPARE(arguments.count(), 1);
}

void SamuraiSessionInitiateRequestTest::testCreateResponseFailed()
{
    qsipgaterpclib::SamuraiSessionInitiateRequest *request =
            qsipgaterpclib::SamuraiSessionInitiateRequestFactory::createInstance(this)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SamuraiSessionInitiateResponse)));

    QVariantMap variantMap;
    QVERIFY(request->createResponse(variantMap) == false);

    QCOMPARE(signalSpy.count(), 0);
}

}

QTEST_MAIN(tests::SamuraiSessionInitiateRequestTest)
#include "moc_samuraisessioninitiaterequesttest.cxx"

