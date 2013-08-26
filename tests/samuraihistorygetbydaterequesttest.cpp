#include <QObject>
#include <QtTest/QtTest>

#include "samuraihistorygetbydaterequest.h"

#include <QString>
#include <QList>
#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QMap>
#include <QVariantList>

#include "samuraihistorygetbydateresponse.h"

namespace tests {

class SamuraiHistoryGetByDateRequestTest : public QObject
{
    Q_OBJECT

private slots:
    void testCreateInstance();
    void testCreateResponse();
    void testCreateResponseFailed();
};

void SamuraiHistoryGetByDateRequestTest::testCreateInstance()
{
    QList<QString> uriList;
    uriList.append("foo");

    QList<QString> statusList;
    statusList.append("bar");

    QDateTime startTime(QDate(2013,1,1));
    QDateTime endTime(QDate::currentDate());

    qsipgaterpclib::SamuraiHistoryGetByDateRequest *request =
            qsipgaterpclib::SamuraiHistoryGetByDateRequestFactory::createInstance(this)
            .withUri(uriList)
            .withStatus(statusList)
            .withPeriodStart(startTime)
            .withPeriodEnd(endTime)
            .build();
    QCOMPARE(request->getMethod(), QString("samurai.HistoryGetByDate"));
    QVariantList list = request->getArguments();
    QMap<QString, QVariant> map = list.at(0).toMap();
    QCOMPARE(map.value("PeriodStart"), QVariant(startTime));
    QCOMPARE(map.value("PeriodEnd"), QVariant(endTime));
    QVariantList uList = map.value("LocalUriList").toList();
    QCOMPARE(uList.at(0), QVariant("foo"));
    QVariantList sList = map.value("StatusList").toList();
    QCOMPARE(sList.at(0), QVariant("bar"));
}

void SamuraiHistoryGetByDateRequestTest::testCreateResponse()
{
    qsipgaterpclib::SamuraiHistoryGetByDateRequest *request =
            qsipgaterpclib::SamuraiHistoryGetByDateRequestFactory::createInstance(this)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SamuraiHistoryGetByDateResponse)));

    QVariant dummy(QString("dummy"));
    QVariantMap variantMap;
    variantMap.insert("History", dummy);
    QVERIFY(request->createResponse(variantMap) == true);

    QCOMPARE(signalSpy.count(), 1);
    QList<QVariant> arguments = signalSpy.takeFirst();
    QCOMPARE(arguments.count(), 1);
}

void SamuraiHistoryGetByDateRequestTest::testCreateResponseFailed()
{
    qsipgaterpclib::SamuraiHistoryGetByDateRequest *request =
            qsipgaterpclib::SamuraiHistoryGetByDateRequestFactory::createInstance(this)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SamuraiHistoryGetByDateResponse)));

    QVariantMap variantMap;
    QVERIFY(request->createResponse(variantMap) == false);

    QCOMPARE(signalSpy.count(), 0);
}

}

QTEST_MAIN(tests::SamuraiHistoryGetByDateRequestTest)
#include "moc_samuraihistorygetbydaterequesttest.cxx"

