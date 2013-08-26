#include <QObject>
#include <QtTest/QtTest>

#include "samuraiitemizedentriesgetrequest.h"

#include <QString>
#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QMap>
#include <QList>
#include <QVariantList>

#include "samuraiitemizedentriesgetresponse.h"

namespace tests {

class SamuraiItemizedEntriesGetRequestTest : public QObject
{
    Q_OBJECT

private slots:
    void testCreateInstance();
    void testCreateResponse();
    void testCreateResponseFailed();
};

void SamuraiItemizedEntriesGetRequestTest::testCreateInstance()
{
    QList<QString> listUri;
    listUri.append(QString("uriFoo"));

    QDateTime startTime(QDate(2013,1,1));
    QDateTime endTime(QDate::currentDate());

    qsipgaterpclib::SamuraiItemizedEntriesGetRequest *request =
            qsipgaterpclib::SamuraiItemizedEntriesGetRequestFactory::createInstance(this)
            .withUri(listUri)
            .withPeriodStart(startTime)
            .withPeriodEnd(endTime)
            .build();
    QCOMPARE(request->getMethod(), QString("samurai.ItemizedEntriesGet"));
    QVariantList list = request->getArguments();
    QMap<QString, QVariant> map = list.at(0).toMap();
    QCOMPARE(map.value("PeriodStart"), QVariant(startTime));
    QCOMPARE(map.value("PeriodEnd"), QVariant(endTime));
    QVariantList vList = map.value("LocalUriList").toList();
    QCOMPARE(vList.at(0), QVariant("uriFoo"));
}

void SamuraiItemizedEntriesGetRequestTest::testCreateResponse()
{
    qsipgaterpclib::SamuraiItemizedEntriesGetRequest *request =
            qsipgaterpclib::SamuraiItemizedEntriesGetRequestFactory::createInstance(this)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SamuraiItemizedEntriesGetResponse)));

    QVariant dummy(QString("dummy"));
    QVariantMap variantMap;
    variantMap.insert("PeriodStart", dummy);
    variantMap.insert("PeriodEnd", dummy);
    variantMap.insert("ItemizedEntries", dummy);
    QVERIFY(request->createResponse(variantMap) == true);

    QCOMPARE(signalSpy.count(), 1);
    QList<QVariant> arguments = signalSpy.takeFirst();
    QCOMPARE(arguments.count(), 1);
}

void SamuraiItemizedEntriesGetRequestTest::testCreateResponseFailed()
{
    qsipgaterpclib::SamuraiItemizedEntriesGetRequest *request =
            qsipgaterpclib::SamuraiItemizedEntriesGetRequestFactory::createInstance(this)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SamuraiItemizedEntriesGetResponse)));

    QVariantMap variantMap;
    QVERIFY(request->createResponse(variantMap) == false);

    QCOMPARE(signalSpy.count(), 0);
}

}

QTEST_MAIN(tests::SamuraiItemizedEntriesGetRequestTest)
#include "moc_samuraiitemizedentriesgetrequesttest.cxx"

