#include <QObject>
#include <QtTest/QtTest>

#include "samuraisessionstatusgetrequest.h"

#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QMap>
#include <QVariantList>

#include "samuraisessionstatusgetresponse.h"

namespace tests {

class SamuraiSessionStatusGetRequestTest : public QObject
{
    Q_OBJECT

private slots:
    void testCreateInstance();
    void testCreateResponse();
    void testCreateResponseFailed();
};

void SamuraiSessionStatusGetRequestTest::testCreateInstance()
{
    qsipgaterpclib::SamuraiSessionStatusGetRequest *request =
            qsipgaterpclib::SamuraiSessionStatusGetRequestFactory::createInstance(this)
            .withSessionId("aSessionId")
            .build();
    QCOMPARE(request->getMethod(), QString("samurai.SessionStatusGet"));
    QVariantList list = request->getArguments();
    QMap<QString, QVariant> map = list.at(0).toMap();
    QCOMPARE(map.value("SessionID"), QVariant("aSessionId"));
}

void SamuraiSessionStatusGetRequestTest::testCreateResponse()
{
    qsipgaterpclib::SamuraiSessionStatusGetRequest *request =
            qsipgaterpclib::SamuraiSessionStatusGetRequestFactory::createInstance(this)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SamuraiSessionStatusGetResponse)));

    QVariant dummy(QString("dummy"));
    QVariantMap variantMap;
    variantMap.insert("SessionStatus", dummy);
    QVERIFY(request->createResponse(variantMap) == true);

    QCOMPARE(signalSpy.count(), 1);
    QList<QVariant> arguments = signalSpy.takeFirst();
    QCOMPARE(arguments.count(), 1);
}

void SamuraiSessionStatusGetRequestTest::testCreateResponseFailed()
{
    qsipgaterpclib::SamuraiSessionStatusGetRequest *request =
            qsipgaterpclib::SamuraiSessionStatusGetRequestFactory::createInstance(this)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SamuraiSessionStatusGetResponse)));

    QVariantMap variantMap;
    QVERIFY(request->createResponse(variantMap) == false);

    QCOMPARE(signalSpy.count(), 0);
}

}

QTEST_MAIN(tests::SamuraiSessionStatusGetRequestTest)
#include "moc_samuraisessionstatusgetrequesttest.cxx"

