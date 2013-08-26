#include "rpcclientfactorytest.h"

#include "rpcclientfactory.h"

#include <QxtXmlRpcClient>

namespace tests
{

void RpcClientFactoryTest::testCreateInstance()
{
    QxtXmlRpcClient *rpcClient = qsipgaterpclib::RpcClientFactory::createInstance(this)
            .withUrl("http://foo.bar")
            .withUserName("joe")
            .withPassword("bar")
            .build();

    QUrl serviceUrl = rpcClient->serviceUrl();
    QCOMPARE(serviceUrl.toString(), QString("http://joe:bar@foo.bar"));
}

} // namespace tests

QTEST_MAIN(tests::RpcClientFactoryTest)
#include "rpcclientfactorytest.moc"
