#include <QObject>
#include <QtTest/QtTest>

#include "systemmethodsignaturerequest.h"

#include <QString>
#include <QMap>
#include <QVariantList>

#include "systemmethodsignatureresponse.h"

namespace tests {

class SystemMethodSignatureRequestTest : public QObject
{
    Q_OBJECT

private slots:
    void testCreateInstance();
    void testCreateResponse();
    void testCreateResponseFailed();
};

void SystemMethodSignatureRequestTest::testCreateInstance()
{
    qsipgaterpclib::SystemMethodSignatureRequest *request =
            qsipgaterpclib::SystemMethodSignatureRequestFactory::createInstance()
            .withMethodName("foo.bar")
            .build();
    QCOMPARE(request->getMethod(), QString("system.methodSignature"));
    QVariantList list = request->getArguments();
    QMap<QString, QVariant> map = list.at(0).toMap();
    QCOMPARE(map.value("MethodName"), QVariant(QString("foo.bar")));
}

void SystemMethodSignatureRequestTest::testCreateResponse()
{
    qsipgaterpclib::SystemMethodSignatureRequest *request =
            qsipgaterpclib::SystemMethodSignatureRequestFactory::createInstance()
            .withMethodName("foo.bar")
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SystemMethodSignatureResponse)));

    QVariant variant(QString("Help Message"));
    QVariantMap variantMap;
    variantMap.insert("methodSignature", variant);
    QVERIFY(request->createResponse(variantMap) == true);

    QCOMPARE(signalSpy.count(), 1);
    QList<QVariant> arguments = signalSpy.takeFirst();
    QCOMPARE(arguments.count(), 1);
}

void SystemMethodSignatureRequestTest::testCreateResponseFailed()
{
    qsipgaterpclib::SystemMethodSignatureRequest *request =
            qsipgaterpclib::SystemMethodSignatureRequestFactory::createInstance()
            .withMethodName("foo.bar")
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SystemMethodSignatureResponse)));

    QVariantMap variantMap;
    QVERIFY(request->createResponse(variantMap) == false);

    QCOMPARE(signalSpy.count(), 0);
}

}

QTEST_MAIN(tests::SystemMethodSignatureRequestTest)
#include "moc_systemmethodsignaturerequesttest.cxx"

