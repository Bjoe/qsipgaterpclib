
#include <iostream>
#include <QDebug>
#include <QxtXmlRpcClient>
#include <QCoreApplication>

#include "rpcclientfactory.h"
#include "rpchandler.h"
#include "output.h"

#include "systemlistmethodshandler.h"
#include "systemlistmethodsrequest.h"
#include "systemlistmethodsresponse.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    std::cout << "Init xmlRpcClient" << std::endl;
    QxtXmlRpcClient *xmlRpcClient = qsipgaterpclib::RpcClientFactory::createInstance()
            .withUserName("foo")
            .withPassword("bar")
            .withUrl("https://samurai.sipgate.net/RPC2")
            .build();

    std::cout << "Init rpcHandler" << std::endl;
    qsipgaterpclib::RpcHandler *rpcHandler = new qsipgaterpclib::RpcHandler(xmlRpcClient);

    std::cout << "Init request" << std::endl;
    qsipgaterpclib::SystemListMethodsRequest *request = qsipgaterpclib::SystemListMethodsRequestFactory::createInstance()
            .build();

    std::cout << "Get handler" << std::endl;
    qsipgaterpclib::SystemListMethodsHandler *handler = request->getHandler();

    std::cout << "Create output" << std::endl;
    tests::Output *output = new tests::Output();
    QObject::connect(rpcHandler, SIGNAL(error(QString)),
                     output, SLOT(doDisplayError(QString)));
    QObject::connect(handler, SIGNAL(error(QString)),
                     output, SLOT(doDisplayError(QString)));
    QObject::connect(handler, SIGNAL(ready(qsipgaterpclib::SystemListMethodsResponse)),
                     output, SLOT(doDisplayResponse(qsipgaterpclib::SystemListMethodsResponse)));

    std::cout << "send rpc request" << std::endl;
    rpcHandler->sendRpcRequest(request);

    std::cout << "run" << std::endl;
    return app.exec();
}
