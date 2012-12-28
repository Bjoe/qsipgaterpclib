#include <QObject>
#include <QtTest/QtTest>

#include "systemlistmethodsrequest.h"
#include "systemlistmethodsresponse.h"

#include <QString>
#include <QVariantList>

namespace tests {

class SystemListMethodsRequestTest : public QObject
{
    Q_OBJECT

private slots:
    void testCreateInstance();
    void testCreateResponse();
    void testCreateResponseFailed();
};

void SystemListMethodsRequestTest::testCreateInstance()
{
    qsipgaterpclib::SystemListMethodsRequest *request = qsipgaterpclib::SystemListMethodsRequestFactory::createInstance().build();
    QCOMPARE(request->getMethod(), QString("system.listMethods"));
    QCOMPARE(request->getArguments(), QVariantList());
}

void SystemListMethodsRequestTest::testCreateResponse()
{
    qsipgaterpclib::SystemListMethodsRequest *request = qsipgaterpclib::SystemListMethodsRequestFactory::createInstance().build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SystemListMethodsResponse)));

    QVariantList variantList;
    variantList.append("foo");
    QVariantMap variantMap;
    variantMap.insert("listMethods", variantList);
    QVERIFY(request->createResponse(variantMap) == true);

    QCOMPARE(signalSpy.count(), 1);
    QList<QVariant> arguments = signalSpy.takeFirst();
    QCOMPARE(arguments.count(), 1);
}

void SystemListMethodsRequestTest::testCreateResponseFailed()
{
    qsipgaterpclib::SystemListMethodsRequest *request = qsipgaterpclib::SystemListMethodsRequestFactory::createInstance().build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SystemListMethodsResponse)));

    QVariantMap variantMap;
    QVERIFY(request->createResponse(variantMap) == false);

    QCOMPARE(signalSpy.count(), 0);
}

} // namespace tests

QTEST_MAIN(tests::SystemListMethodsRequestTest)
#include "moc_systemlistmethodsrequesttest.cxx"
