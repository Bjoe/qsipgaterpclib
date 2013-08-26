
#include <QObject>
#include <QtTest/QtTest>

#include "systemserverinforequest.h"
#include "systemserverinforesponse.h"

#include <QString>
#include <QVariantList>

namespace tests {

class SystemServerInfoRequestTest : public QObject
{
    Q_OBJECT

private slots:
    void testCreateInstance();
    void testCreateResponse();
    void testCreateResponseFailed();
};

void SystemServerInfoRequestTest::testCreateInstance()
{
    qsipgaterpclib::SystemServerInfoRequest *request =
            qsipgaterpclib::SystemServerInfoRequestFactory::createInstance(this)
            .build();
    QCOMPARE(request->getMethod(), QString("system.serverInfo"));
    QVariantList list = request->getArguments();
    QCOMPARE(list, QVariantList());
}

void SystemServerInfoRequestTest::testCreateResponse()
{
    qsipgaterpclib::SystemServerInfoRequest *request =
            qsipgaterpclib::SystemServerInfoRequestFactory::createInstance(this)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SystemServerInfoResponse)));

    QVariant specVersion(QString("123456"));
    QVariantMap variantMap;
    variantMap.insert("SpecificationVersion", specVersion);
    QVariant serverName(QString("foobar"));
    variantMap.insert("ServerName", serverName);
    QVariant serverVersion(QString("54321"));
    variantMap.insert("ServerVersion", serverVersion);
    QVariant serverVendor(QString("barfoo"));
    variantMap.insert("ServerVendor", serverVendor);

    QVERIFY(request->createResponse(variantMap) == true);

    QCOMPARE(signalSpy.count(), 1);
    QList<QVariant> arguments = signalSpy.takeFirst();
    QCOMPARE(arguments.count(), 1);
}

void SystemServerInfoRequestTest::testCreateResponseFailed()
{
    qsipgaterpclib::SystemServerInfoRequest *request =
            qsipgaterpclib::SystemServerInfoRequestFactory::createInstance(this)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SystemServerInfoResponse)));

    QVariantMap variantMap;
    QVERIFY(request->createResponse(variantMap) == false);

    QCOMPARE(signalSpy.count(), 0);
}

}

QTEST_MAIN(tests::SystemServerInfoRequestTest)
#include "moc_systemserverinforequesttest.cxx"

