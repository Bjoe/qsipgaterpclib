#include "systemlistmethodshandlertest.h"

#include "systemlistmethodshandler.h"

#include <QString>
#include <QVariantMap>
#include <QVariantList>
#include <QSignalSpy>

#include "systemlistmethodsresponse.h"

// TODO Q_DECLARE_METATYPE(qsipgaterpclib::SystemListMethodsResponse)

namespace tests {

class MockSystemListMethodsHandler : public qsipgaterpclib::SystemListMethodsHandler
{
public:
    bool invokeCreateResponse(const QVariantMap &aVariant)
    {
        return createResponse(aVariant);
    }
};


void SystemListMethodsHandlerTest::testCreateResponse()
{
    MockSystemListMethodsHandler *handler = new MockSystemListMethodsHandler();

    QSignalSpy signalSpy(handler, SIGNAL(ready(qsipgaterpclib::SystemListMethodsResponse)));

    QVariantList variantList;
    variantList.append("foo");
    QVariantMap variantMap;
    variantMap.insert("listMethods", variantList);
    QVERIFY(handler->invokeCreateResponse(variantMap) == true);

    QCOMPARE(signalSpy.count(), 1);
    QList<QVariant> arguments = signalSpy.takeFirst();
    QCOMPARE(arguments.count(), 1);
}

void SystemListMethodsHandlerTest::testCreateResponseFailed()
{
    MockSystemListMethodsHandler *handler = new MockSystemListMethodsHandler();

    QSignalSpy signalSpy(handler, SIGNAL(ready(qsipgaterpclib::SystemListMethodsResponse)));

    QVariantMap variantMap;
    QVERIFY(handler->invokeCreateResponse(variantMap) == false);

    QCOMPARE(signalSpy.count(), 0);
}

} // namespace tests

QTEST_MAIN(tests::SystemListMethodsHandlerTest)
#include "systemlistmethodshandlertest.moc"
