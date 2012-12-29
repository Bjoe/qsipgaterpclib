
#include <iostream>
#include <QDebug>
#include <QxtXmlRpcClient>
#include <QCoreApplication>

#include "rpcclientfactory.h"
#include "rpchandler.h"
#include "output.h"

#include "systemlistmethodsrequest.h"
#include "systemlistmethodsresponse.h"

#include "systemmethodhelprequest.h"
#include "systemmethodhelpresponse.h"

#include "systemmethodsignaturerequest.h"
#include "systemmethodsignatureresponse.h"

#include "systemserverinforequest.h"
#include "systemserverinforesponse.h"

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


/*
    std::cout << "Init request" << std::endl;
    qsipgaterpclib::SystemListMethodsRequest *request = qsipgaterpclib::SystemListMethodsRequestFactory::createInstance()
            .build();

    std::cout << "Get handler" << std::endl;

    std::cout << "Create output" << std::endl;
    tests::Output *output = new tests::Output();
    QObject::connect(rpcHandler, SIGNAL(error(QString)),
                     output, SLOT(doDisplayError(QString)));
    QObject::connect(request, SIGNAL(error(QString)),
                     output, SLOT(doDisplayError(QString)));
    QObject::connect(request, SIGNAL(ready(qsipgaterpclib::SystemListMethodsResponse)),
                     output, SLOT(doDisplayResponse(qsipgaterpclib::SystemListMethodsResponse)));
*/

/*
    std::cout << "Init request" << std::endl;
    qsipgaterpclib::SystemMethodHelpRequest *request =
            qsipgaterpclib::SystemMethodHelpRequestFactory::createInstance()
            .withMethodName("TosListGet")
            .build();

    std::cout << "Get handler" << std::endl;

    std::cout << "Create output" << std::endl;
    tests::Output *output = new tests::Output();
    QObject::connect(rpcHandler, SIGNAL(error(QString)),
                     output, SLOT(doDisplayError(QString)));
    QObject::connect(request, SIGNAL(error(QString)),
                     output, SLOT(doDisplayError(QString)));
    QObject::connect(request, SIGNAL(ready(qsipgaterpclib::SystemMethodHelpResponse)),
                     output, SLOT(doDisplayMethodHelpResponse(qsipgaterpclib::SystemMethodHelpResponse)));
*/

/*
    std::cout << "Init request" << std::endl;
    qsipgaterpclib::SystemMethodSignatureRequest *request =
            qsipgaterpclib::SystemMethodSignatureRequestFactory::createInstance()
            .withMethodName("samurai.OwnUriListGet")
            .build();

    std::cout << "Get handler" << std::endl;

    std::cout << "Create output" << std::endl;
    tests::Output *output = new tests::Output();
    QObject::connect(rpcHandler, SIGNAL(error(QString)),
                     output, SLOT(doDisplayError(QString)));
    QObject::connect(request, SIGNAL(error(QString)),
                     output, SLOT(doDisplayError(QString)));
    QObject::connect(request, SIGNAL(ready(qsipgaterpclib::SystemMethodSignatureResponse)),
                     output, SLOT(doDisplayMethodSignatureResponse(qsipgaterpclib::SystemMethodSignatureResponse)));
*/

    std::cout << "Init request" << std::endl;
    qsipgaterpclib::SystemServerInfoRequest *request =
            qsipgaterpclib::SystemServerInfoRequestFactory::createInstance()
            .build();

    std::cout << "Get handler" << std::endl;

    std::cout << "Create output" << std::endl;
    tests::Output *output = new tests::Output();
    QObject::connect(rpcHandler, SIGNAL(error(QString)),
                     output, SLOT(doDisplayError(QString)));
    QObject::connect(request, SIGNAL(error(QString)),
                     output, SLOT(doDisplayError(QString)));
    QObject::connect(request, SIGNAL(ready(qsipgaterpclib::SystemServerInfoResponse)),
                     output, SLOT(doDisplayServerInfoResponse(qsipgaterpclib::SystemServerInfoResponse)));


    std::cout << "send rpc request" << std::endl;
    rpcHandler->sendRpcRequest(request);

    std::cout << "run" << std::endl;
    return app.exec();
}
