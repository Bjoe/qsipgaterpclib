#include <QObject>
#include <QtTest/QtTest>

#include "samuraisessioninitiatemultirequest.h"

#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QMap>
#include <QVariantList>

#include "samuraisessioninitiatemultiresponse.h"

namespace tests {

class SamuraiSessionInitiateMultiRequestTest : public QObject
{
    Q_OBJECT

private slots:
    void testCreateInstance();
    void testCreateResponse();
    void testCreateResponseFailed();
};

void SamuraiSessionInitiateMultiRequestTest::testCreateInstance()
{
    QDateTime dateTime(QDate::currentDate());

    QList<QString> uris;
    uris.append("aRemoteUri");

    qsipgaterpclib::SamuraiSessionInitiateMultiRequest *request =
            qsipgaterpclib::SamuraiSessionInitiateMultiRequestFactory::createInstance(this)
            .withLocalUri("localUri")
            .withRemoteUris(uris)
            .withTos("tos")
            .withContent("content")
            .withSchedule(dateTime)
            .build();
    QCOMPARE(request->getMethod(), QString("samurai.SessionInitiateMulti"));
    QVariantList list = request->getArguments();
    QMap<QString, QVariant> map = list.at(0).toMap();
    QCOMPARE(map.value("LocalUri"), QVariant("localUri"));
    QVariantList uriList = map.value("RemoteUri").toList();
    QCOMPARE(uriList.at(0), QVariant("aRemoteUri"));
    QCOMPARE(map.value("TOS"), QVariant("tos"));
    QCOMPARE(map.value("Content"), QVariant("content"));
    QCOMPARE(map.value("Schedule"), QVariant(dateTime));
}

void SamuraiSessionInitiateMultiRequestTest::testCreateResponse()
{
    qsipgaterpclib::SamuraiSessionInitiateMultiRequest *request =
            qsipgaterpclib::SamuraiSessionInitiateMultiRequestFactory::createInstance(this)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SamuraiSessionInitiateMultiResponse)));

    QVariant dummy(QString("dummy"));
    QVariantMap variantMap;
    variantMap.insert("SessionList", dummy);
    QVERIFY(request->createResponse(variantMap) == true);

    QCOMPARE(signalSpy.count(), 1);
    QList<QVariant> arguments = signalSpy.takeFirst();
    QCOMPARE(arguments.count(), 1);
}

void SamuraiSessionInitiateMultiRequestTest::testCreateResponseFailed()
{
    qsipgaterpclib::SamuraiSessionInitiateMultiRequest *request =
            qsipgaterpclib::SamuraiSessionInitiateMultiRequestFactory::createInstance(this)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SamuraiSessionInitiateMultiResponse)));

    QVariantMap variantMap;
    QVERIFY(request->createResponse(variantMap) == false);

    QCOMPARE(signalSpy.count(), 0);
}

}

QTEST_MAIN(tests::SamuraiSessionInitiateMultiRequestTest)
#include "moc_samuraisessioninitiatemultirequesttest.cxx"

