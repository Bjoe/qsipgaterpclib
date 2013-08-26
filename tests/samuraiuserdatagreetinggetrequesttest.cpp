#include <QObject>
#include <QtTest/QtTest>

#include "samuraiuserdatagreetinggetrequest.h"

#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QMap>
#include <QVariantList>

#include "samuraiuserdatagreetinggetresponse.h"

namespace tests {

class SamuraiUserdataGreetingGetRequestTest : public QObject
{
    Q_OBJECT

private slots:
    void testCreateInstance();
    void testCreateResponse();
    void testCreateResponseFailed();
};

void SamuraiUserdataGreetingGetRequestTest::testCreateInstance()
{
    qsipgaterpclib::SamuraiUserdataGreetingGetRequest *request =
            qsipgaterpclib::SamuraiUserdataGreetingGetRequestFactory::createInstance(this)
            .build();
    QCOMPARE(request->getMethod(), QString("samurai.UserdataGreetingGet"));
    QCOMPARE(request->getArguments(), QVariantList());
}

void SamuraiUserdataGreetingGetRequestTest::testCreateResponse()
{
    qsipgaterpclib::SamuraiUserdataGreetingGetRequest *request =
            qsipgaterpclib::SamuraiUserdataGreetingGetRequestFactory::createInstance(this)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SamuraiUserdataGreetingGetResponse)));

    QVariant dummy(QString("dummy"));
    QVariantMap variantMap;
    variantMap.insert("Gender", dummy);
    variantMap.insert("FirstName", dummy);
    variantMap.insert("LastName", dummy);
    QVERIFY(request->createResponse(variantMap) == true);

    QCOMPARE(signalSpy.count(), 1);
    QList<QVariant> arguments = signalSpy.takeFirst();
    QCOMPARE(arguments.count(), 1);
}

void SamuraiUserdataGreetingGetRequestTest::testCreateResponseFailed()
{
    qsipgaterpclib::SamuraiUserdataGreetingGetRequest *request =
            qsipgaterpclib::SamuraiUserdataGreetingGetRequestFactory::createInstance(this)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SamuraiUserdataGreetingGetResponse)));

    QVariantMap variantMap;
    QVERIFY(request->createResponse(variantMap) == false);

    QCOMPARE(signalSpy.count(), 0);
}

}

QTEST_MAIN(tests::SamuraiUserdataGreetingGetRequestTest)
#include "moc_samuraiuserdatagreetinggetrequesttest.cxx"

