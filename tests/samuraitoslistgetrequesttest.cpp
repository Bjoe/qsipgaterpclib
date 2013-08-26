#include <QObject>
#include <QtTest/QtTest>

#include "samuraitoslistgetrequest.h"

#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QMap>
#include <QVariantList>

#include "samuraitoslistgetresponse.h"

namespace tests {

class SamuraiTosListGetRequestTest : public QObject
{
    Q_OBJECT

private slots:
    void testCreateInstance();
    void testCreateResponse();
    void testCreateResponseFailed();
};

void SamuraiTosListGetRequestTest::testCreateInstance()
{
    qsipgaterpclib::SamuraiTosListGetRequest *request =
            qsipgaterpclib::SamuraiTosListGetRequestFactory::createInstance(this)
            .build();
    QCOMPARE(request->getMethod(), QString("samurai.TosListGet"));
    QCOMPARE(request->getArguments(), QVariantList());
}

void SamuraiTosListGetRequestTest::testCreateResponse()
{
    qsipgaterpclib::SamuraiTosListGetRequest *request =
            qsipgaterpclib::SamuraiTosListGetRequestFactory::createInstance(this)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SamuraiTosListGetResponse)));

    QVariant dummy(QString("dummy"));
    QVariantMap variantMap;
    variantMap.insert("TosList", dummy);
    QVERIFY(request->createResponse(variantMap) == true);

    QCOMPARE(signalSpy.count(), 1);
    QList<QVariant> arguments = signalSpy.takeFirst();
    QCOMPARE(arguments.count(), 1);
}

void SamuraiTosListGetRequestTest::testCreateResponseFailed()
{
    qsipgaterpclib::SamuraiTosListGetRequest *request =
            qsipgaterpclib::SamuraiTosListGetRequestFactory::createInstance(this)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SamuraiTosListGetResponse)));

    QVariantMap variantMap;
    QVERIFY(request->createResponse(variantMap) == false);

    QCOMPARE(signalSpy.count(), 0);
}

}

QTEST_MAIN(tests::SamuraiTosListGetRequestTest)
#include "moc_samuraitoslistgetrequesttest.cxx"

