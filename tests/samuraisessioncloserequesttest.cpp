#include <QObject>
#include <QtTest/QtTest>

#include "samuraisessioncloserequest.h"

#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QMap>
#include <QVariantList>

#include "samuraisessioncloseresponse.h"

namespace tests {

class SamuraiSessionCloseRequestTest : public QObject
{
    Q_OBJECT

private slots:
    void testCreateInstance();
    void testCreateResponse();
};

void SamuraiSessionCloseRequestTest::testCreateInstance()
{
    qsipgaterpclib::SamuraiSessionCloseRequest *request =
            qsipgaterpclib::SamuraiSessionCloseRequestFactory::createInstance(this)
            .withSessionId("foobar")
            .build();
    QCOMPARE(request->getMethod(), QString("samurai.SessionClose"));
    QVariantList list = request->getArguments();
    QMap<QString, QVariant> map = list.at(0).toMap();
    QCOMPARE(map.value("SessionID"), QVariant("foobar"));
}

void SamuraiSessionCloseRequestTest::testCreateResponse()
{
    qsipgaterpclib::SamuraiSessionCloseRequest *request =
            qsipgaterpclib::SamuraiSessionCloseRequestFactory::createInstance(this)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SamuraiSessionCloseResponse)));

    QVariantMap variantMap;
    QVERIFY(request->createResponse(variantMap) == true);

    QCOMPARE(signalSpy.count(), 1);
    QList<QVariant> arguments = signalSpy.takeFirst();
    QCOMPARE(arguments.count(), 1);
}

}

QTEST_MAIN(tests::SamuraiSessionCloseRequestTest)
#include "moc_samuraisessioncloserequesttest.cxx"

