#include <QObject>
#include <QtTest/QtTest>

#include "samuraiaccountstatementgetrequest.h"

#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QMap>
#include <QVariantList>

#include "samuraiaccountstatementgetresponse.h"

namespace tests {

class SamuraiAccountStatementGetRequestTest : public QObject
{
    Q_OBJECT

private slots:
    void testCreateInstance();
    void testCreateResponse();
    void testCreateResponseFailed();
};

void SamuraiAccountStatementGetRequestTest::testCreateInstance()
{
    QDate startDate(2012,7,1);
    QTime startTime(7,6,5);

    QDate endDate(2013,1,4);
    QTime endTime(5,7,8);

    QDateTime startPeriod(startDate, startTime);
    QDateTime endPeriod(endDate, endTime);

    qsipgaterpclib::SamuraiAccountStatementGetRequest *request =
            qsipgaterpclib::SamuraiAccountStatementGetRequestFactory::createInstance(this)
            .withPeriodEnd(endPeriod)
            .withPeriodStart(startPeriod)
            .build();
    QCOMPARE(request->getMethod(), QString("samurai.AccountStatementGet"));
    QVariantList list = request->getArguments();
    QMap<QString, QVariant> map = list.at(0).toMap();
    QCOMPARE(map.value("PeriodStart"), QVariant(startPeriod));
    QCOMPARE(map.value("PeriodEnd"), QVariant(endPeriod));
}

void SamuraiAccountStatementGetRequestTest::testCreateResponse()
{
    QDate startDate(2012,7,1);
    QTime startTime(7,6,5);

    QDate endDate(2013,1,4);
    QTime endTime(5,7,8);

    QDateTime startPeriod(startDate, startTime);
    QDateTime endPeriod(endDate, endTime);

    qsipgaterpclib::SamuraiAccountStatementGetRequest *request =
            qsipgaterpclib::SamuraiAccountStatementGetRequestFactory::createInstance(this)
            .withPeriodEnd(endPeriod)
            .withPeriodStart(startPeriod)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SamuraiAccountStatementGetResponse)));

    QVariant dummy(QString("dummy"));
    QVariantMap variantMap;
    variantMap.insert("PeriodStart", dummy);
    variantMap.insert("PeriodEnd", dummy);
    variantMap.insert("AccountStatementChargedServices", dummy);
    variantMap.insert("BalanceStart", dummy);
    variantMap.insert("BalanceEnd", dummy);
    QVERIFY(request->createResponse(variantMap) == true);

    QCOMPARE(signalSpy.count(), 1);
    QList<QVariant> arguments = signalSpy.takeFirst();
    QCOMPARE(arguments.count(), 1);
}

void SamuraiAccountStatementGetRequestTest::testCreateResponseFailed()
{
    QDate startDate(2012,7,1);
    QTime startTime(7,6,5);

    QDate endDate(2013,1,4);
    QTime endTime(5,7,8);

    QDateTime startPeriod(startDate, startTime);
    QDateTime endPeriod(endDate, endTime);

    qsipgaterpclib::SamuraiAccountStatementGetRequest *request =
            qsipgaterpclib::SamuraiAccountStatementGetRequestFactory::createInstance(this)
            .withPeriodEnd(endPeriod)
            .withPeriodStart(startPeriod)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SamuraiAccountStatementGetResponse)));

    QVariantMap variantMap;
    QVERIFY(request->createResponse(variantMap) == false);

    QCOMPARE(signalSpy.count(), 0);
}

}

QTEST_MAIN(tests::SamuraiAccountStatementGetRequestTest)
#include "moc_samuraiaccountstatementgetrequesttest.cxx"
