#include <QObject>
#include <QtTest/QtTest>
#include <QSignalSpy>

#include <QString>
#include <QVariant>
#include <QVariantMap>

#include "samuraieventlistgetrequest.h"

#include "samuraieventlistgetresponse.h"

namespace tests {

class SamuraiEventListGetRequestTest : public QObject
{
    Q_OBJECT

private slots:
    void testCreateInstance();
    void testCreateResponse();
    void testCreateResponseFailed();
};

void SamuraiEventListGetRequestTest::testCreateInstance()
{
    QList<QString> labelList;
    labelList.append("foobar");

    QList<QString> eventIdList;
    eventIdList.append("123456");

    QList<QString> tosList;
    tosList.append("sot");

    QDateTime startTime(QDate(2013,1,1));
    QDateTime endTime(QDate::currentDate());

    qsipgaterpclib::SamuraiEventListGetRequest *request =
            qsipgaterpclib::SamuraiEventListGetRequestFactory::createInstance(this)
            .withLimit(23)
            .withOffset(42)
            .withLabels(labelList)
            .withEventIds(eventIdList)
            .withTos(tosList)
            .withPeriodStart(startTime)
            .withPeriodEnd(endTime)
            .withIncrementBaseId("2342")
            .build();

    QCOMPARE(request->getMethod(), QString("samurai.EventListGet"));
    QVariantList list = request->getArguments();
    QMap<QString, QVariant> map = list.at(0).toMap();
    QCOMPARE(map.value("Limit"), QVariant(23));
    QCOMPARE(map.value("Offset"), QVariant(42));
    QCOMPARE(map.value("IncrementBaseID"), QVariant("2342"));
    QCOMPARE(map.value("PeriodStart"), QVariant(startTime));
    QCOMPARE(map.value("PeriodEnd"), QVariant(endTime));
    QVariantList labels = map.value("Labels").toList();
    QCOMPARE(labels.at(0), QVariant("foobar"));
    QVariantList events = map.value("EventIDs").toList();
    QCOMPARE(events.at(0), QVariant("123456"));
    QVariantList tos = map.value("TOS").toList();
    QCOMPARE(tos.at(0), QVariant("sot"));
}

void SamuraiEventListGetRequestTest::testCreateResponse()
{
    qRegisterMetaType<qsipgaterpclib::SamuraiEventListGetResponse>("qsipgaterpclib::SamuraiEventListGetResponse");
    qsipgaterpclib::SamuraiEventListGetRequest *request =
            qsipgaterpclib::SamuraiEventListGetRequestFactory::createInstance(this)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SamuraiEventListGetResponse)));

    QVariant dummy(QString("dummy"));
    QVariantMap variantMap;
    variantMap.insert("EventList", dummy);
    variantMap.insert("OverallCount", QVariant(1));
    QVERIFY(request->createResponse(variantMap) == true);

    QCOMPARE(signalSpy.count(), 1);
    QList<QVariant> arguments = signalSpy.takeFirst();
    QCOMPARE(arguments.count(), 1);

}

void SamuraiEventListGetRequestTest::testCreateResponseFailed()
{
    qRegisterMetaType<qsipgaterpclib::SamuraiEventListGetResponse>("qsipgaterpclib::SamuraiEventListGetResponse");
    qsipgaterpclib::SamuraiEventListGetRequest *request =
            qsipgaterpclib::SamuraiEventListGetRequestFactory::createInstance(this)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SamuraiEventListGetResponse)));

    QVariantMap variantMap;
    QVERIFY(request->createResponse(variantMap) == false);

    QCOMPARE(signalSpy.count(), 0);
}

}

QTEST_MAIN(tests::SamuraiEventListGetRequestTest)
#include "moc_samuraieventlistgetrequesttest.cxx"


