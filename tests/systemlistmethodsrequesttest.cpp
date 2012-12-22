#include "systemlistmethodsrequesttest.h"

#include "systemlistmethodsrequest.h"

#include "systemlistmethodshandler.h"

#include <QString>
#include <QVariantList>

namespace tests {

void SystemListMethodsRequestTest::testCreateInstance()
{
    qsipgaterpclib::SystemListMethodsRequest *request = qsipgaterpclib::SystemListMethodsRequestFactory::createInstance().build();
    QCOMPARE(request->getMethod(), QString("system.listMethods"));
    QCOMPARE(request->getArguments(), QVariantList());
}

void SystemListMethodsRequestTest::testGetHandler()
{
    qsipgaterpclib::SystemListMethodsRequest *request = qsipgaterpclib::SystemListMethodsRequestFactory::createInstance().build();
    qsipgaterpclib::SystemListMethodsHandler *handler = request->getHandler();
}

} // namespace tests

QTEST_MAIN(tests::SystemListMethodsRequestTest)
#include "systemlistmethodsrequesttest.moc"
