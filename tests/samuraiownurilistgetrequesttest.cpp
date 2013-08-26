#include <QObject>
#include <QtTest/QtTest>

#include "samuraiownurilistgetrequest.h"

#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QMap>
#include <QVariantList>

#include "samuraiownurilistgetresponse.h"

namespace tests {

class SamuraiOwnUriListGetRequestTest : public QObject
{
    Q_OBJECT

private slots:
    void testCreateInstance();
    void testCreateResponse();
    void testCreateResponseFailed();
};

void SamuraiOwnUriListGetRequestTest::testCreateInstance()
{
    qsipgaterpclib::SamuraiOwnUriListGetRequest *request =
            qsipgaterpclib::SamuraiOwnUriListGetRequestFactory::createInstance(this)
            .build();
    QCOMPARE(request->getMethod(), QString("samurai.OwnUriListGet"));
}

void SamuraiOwnUriListGetRequestTest::testCreateResponse()
{
    qsipgaterpclib::SamuraiOwnUriListGetRequest *request =
            qsipgaterpclib::SamuraiOwnUriListGetRequestFactory::createInstance(this)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SamuraiOwnUriListGetResponse)));

    QVariant dummy(QString("dummy"));
    QVariantMap variantMap;
    variantMap.insert("OwnUriList", dummy);
    QVERIFY(request->createResponse(variantMap) == true);

    QCOMPARE(signalSpy.count(), 1);
    QList<QVariant> arguments = signalSpy.takeFirst();
    QCOMPARE(arguments.count(), 1);
}

void SamuraiOwnUriListGetRequestTest::testCreateResponseFailed()
{
    qsipgaterpclib::SamuraiOwnUriListGetRequest *request =
            qsipgaterpclib::SamuraiOwnUriListGetRequestFactory::createInstance(this)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SamuraiOwnUriListGetResponse)));

    QVariantMap variantMap;
    QVERIFY(request->createResponse(variantMap) == false);

    QCOMPARE(signalSpy.count(), 0);
}

}

QTEST_MAIN(tests::SamuraiOwnUriListGetRequestTest)
#include "moc_samuraiownurilistgetrequesttest.cxx"

