#include <QObject>
#include <QtTest/QtTest>

#include "systemmethodhelprequest.h"

#include <QString>
#include <QVariantList>

namespace tests {

class SystemMethodHelpRequestTest : public QObject
{
    Q_OBJECT

private slots:
    void testCreateInstance();
    void testCreateResponse();
    void testCreateResponseFailed();
};

void SystemMethodHelpRequestTest::testCreateInstance()
{
    qsipgaterpclib::SystemMethodHelpRequest *request =
            qsipgaterpclib::SystemMethodHelpRequestFactory::createInstance()
            .withMethodName("foo.bar")
            .build();
    QCOMPARE(request->getMethod(), QString("system.methodHelp"));
    QVariantList list = request->getArguments();
    QHash<QString, QVariant> map = list.at(0).toHash();
    QCOMPARE(map.value("MethodName"), QVariant(QString("foo.bar")));
}

void SystemMethodHelpRequestTest::testCreateResponse()
{
    qsipgaterpclib::SystemMethodHelpRequest *request =
            qsipgaterpclib::SystemMethodHelpRequestFactory::createInstance()
            .withMethodName("foo.bar")
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SystemMethodHelpResponse)));

    QVariant variant(QString("Help Message"));
    QVariantMap variantMap;
    variantMap.insert("methodHelp", variant);
    QVERIFY(request->createResponse(variantMap) == true);

    QCOMPARE(signalSpy.count(), 1);
    QList<QVariant> arguments = signalSpy.takeFirst();
    QCOMPARE(arguments.count(), 1);
}

void SystemMethodHelpRequestTest::testCreateResponseFailed()
{
    qsipgaterpclib::SystemMethodHelpRequest *request =
            qsipgaterpclib::SystemMethodHelpRequestFactory::createInstance()
            .withMethodName("foo.bar")
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SystemMethodHelpResponse)));

    QVariantMap variantMap;
    QVERIFY(request->createResponse(variantMap) == false);

    QCOMPARE(signalSpy.count(), 0);
}

}

QTEST_MAIN(tests::SystemMethodHelpRequestTest)
#include "moc_systemmethodhelprequesttest.cxx"
