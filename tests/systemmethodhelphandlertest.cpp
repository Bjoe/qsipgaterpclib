#include <QObject>
#include <QtTest/QtTest>

#include "systemmethodhelphandler.h"

#include <QString>
#include <QVariantMap>
#include <QVariant>
#include <QSignalSpy>

#include "systemmethodhelpresponse.h"

namespace tests {

class SystemMethodHelpHandlerTest : public QObject
{
    Q_OBJECT

private slots:
    void testCreateResponse();
    void testCreateResponseFailed();
};

class MockSystemMethodHelpHandler : public qsipgaterpclib::SystemMethodHelpHandler
{
public:
    bool invokeCreateResponse(const QVariantMap &aVariant)
    {
        return createResponse(aVariant);
    }
};

void SystemMethodHelpHandlerTest::testCreateResponse()
{
    MockSystemMethodHelpHandler *handler = new MockSystemMethodHelpHandler();

    QSignalSpy signalSpy(handler, SIGNAL(ready(qsipgaterpclib::SystemMethodHelpResponse)));

    QVariant variant(QString("Help Message"));
    QVariantMap variantMap;
    variantMap.insert("methodHelp", variant);
    QVERIFY(handler->invokeCreateResponse(variantMap) == true);

    QCOMPARE(signalSpy.count(), 1);
    QList<QVariant> arguments = signalSpy.takeFirst();
    QCOMPARE(arguments.count(), 1);
}

void SystemMethodHelpHandlerTest::testCreateResponseFailed()
{
    MockSystemMethodHelpHandler *handler = new MockSystemMethodHelpHandler();

    QSignalSpy signalSpy(handler, SIGNAL(ready(qsipgaterpclib::SystemMethodHelpResponse)));

    QVariantMap variantMap;
    QVERIFY(handler->invokeCreateResponse(variantMap) == false);

    QCOMPARE(signalSpy.count(), 0);
}

}

QTEST_MAIN(tests::SystemMethodHelpHandlerTest)
#include "moc_systemmethodhelphandlertest.cxx"

