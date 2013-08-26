#include <QObject>
#include <QtTest/QtTest>

#include "samuraibalancegetrequest.h"

#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QMap>
#include <QVariantList>

#include "samuraibalancegetresponse.h"

namespace tests {

class SamuraiBalanceGetRequestTest : public QObject
{
    Q_OBJECT

private slots:
    void testCreateInstance();
    void testCreateResponse();
    void testCreateResponseFailed();
};

void SamuraiBalanceGetRequestTest::testCreateInstance()
{
    qsipgaterpclib::SamuraiBalanceGetRequest *request =
            qsipgaterpclib::SamuraiBalanceGetRequestFactory::createInstance(this)
            .build();
    QCOMPARE(request->getMethod(), QString("samurai.BalanceGet"));
    QVariantList list = request->getArguments();
    QCOMPARE(list.count(), 0);
}

void SamuraiBalanceGetRequestTest::testCreateResponse()
{
    qsipgaterpclib::SamuraiBalanceGetRequest *request =
            qsipgaterpclib::SamuraiBalanceGetRequestFactory::createInstance(this)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SamuraiBalanceGetResponse)));

    QVariant dummy(QString("dummy"));
    QVariantMap variantMap;
    variantMap.insert("BalanceTime", dummy);
    variantMap.insert("CurrentBalance", dummy);
    QVERIFY(request->createResponse(variantMap) == true);

    QCOMPARE(signalSpy.count(), 1);
    QList<QVariant> arguments = signalSpy.takeFirst();
    QCOMPARE(arguments.count(), 1);
}

void SamuraiBalanceGetRequestTest::testCreateResponseFailed()
{
    qsipgaterpclib::SamuraiBalanceGetRequest *request =
            qsipgaterpclib::SamuraiBalanceGetRequestFactory::createInstance(this)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SamuraiBalanceGetResponse)));

    QVariantMap variantMap;
    QVERIFY(request->createResponse(variantMap) == false);

    QCOMPARE(signalSpy.count(), 0);
}

}

QTEST_MAIN(tests::SamuraiBalanceGetRequestTest)
#include "moc_samuraibalancegetrequesttest.cxx"

