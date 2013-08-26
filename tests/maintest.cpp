
#include <iostream>
#include <QDebug>
#include <QString>
#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QVariant>
#include <QSettings>
#include <QxtXmlRpcClient>
#include <QApplication>

#include "mainwindow.h"

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

#include "samuraiaccountstatementgetrequest.h"
#include "samuraiaccountstatementgetresponse.h"

#include "samuraibalancegetrequest.h"
#include "samuraibalancegetresponse.h"

#include "samuraiclientidentifyrequest.h"
#include "samuraiclientidentifyresponse.h"

#include "samuraihistorygetbydaterequest.h"
#include "samuraihistorygetbydateresponse.h"

#include "samuraiitemizedentriesgetrequest.h"
#include "samuraiitemizedentriesgetresponse.h"

#include "samuraiownurilistgetrequest.h"
#include "samuraiownurilistgetresponse.h"

#include "samuraiphonebookentrygetrequest.h"
#include "samuraiphonebookentrygetresponse.h"

#include "samuraiphonebooklistgetrequest.h"
#include "samuraiphonebooklistgetresponse.h"

#include "samurairecommendedintervalgetrequest.h"
#include "samurairecommendedintervalgetresponse.h"

#include "samuraiserverdatagetrequest.h"
#include "samuraiserverdatagetresponse.h"

#include "samuraitoslistgetrequest.h"
#include "samuraitoslistgetresponse.h"

#include "samuraiumsummarygetrequest.h"
#include "samuraiumsummarygetresponse.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::setOrganizationName("devolab");
    QApplication::setOrganizationDomain("devolab.de");
    QApplication::setApplicationName("QsipgateRpc Example");

    QSettings settings;
    //settings.setValue("foo", "bar");
    QVariant username = settings.value("username");
    QVariant password = settings.value("password");
    QVariant url = settings.value("url");
    QVariant uri = settings.value("uri");

    QxtXmlRpcClient *xmlRpcClient = qsipgaterpclib::RpcClientFactory::createInstance(&app)
            .withUserName(username.toString())
            .withPassword(password.toString())
            .withUrl(url.toString())
            .build();

    qsipgaterpclib::RpcHandler *rpcHandler = new qsipgaterpclib::RpcHandler(xmlRpcClient);

    MainWindow *mainWindow = new MainWindow(rpcHandler);
    mainWindow->show();

/*

    std::cout << "Init request" << std::endl;
    qsipgaterpclib::SystemListMethodsRequest *request = qsipgaterpclib::SystemListMethodsRequestFactory::createInstance(&app)
            .build();

    std::cout << "Get handler" << std::endl;

    std::cout << "Create output" << std::endl;
    tests::Output *output = new tests::Output();
    QObject::connect(rpcHandler, SIGNAL(error(QString)),
                     output, SLOT(doDisplayError(QString)));
    QObject::connect(request, SIGNAL(error(QString)),
                     output, SLOT(doDisplayError(QString)));
    QObject::connect(request, SIGNAL(ready(qsipgaterpclib::SystemListMethodsResponse)),
                     output, SLOT(doDisplayListMethodsResponse(qsipgaterpclib::SystemListMethodsResponse)));

*/

/*
    std::cout << "Init request" << std::endl;
    qsipgaterpclib::SystemMethodHelpRequest *request =
            qsipgaterpclib::SystemMethodHelpRequestFactory::createInstance(&app)
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
            qsipgaterpclib::SystemMethodSignatureRequestFactory::createInstance(&app)
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
/*
    std::cout << "Init request" << std::endl;
    qsipgaterpclib::SystemServerInfoRequest *request =
            qsipgaterpclib::SystemServerInfoRequestFactory::createInstance(&app)
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

*/
/*
    QTime startTime(12,0,0);
    QDate startDate(2012,7,1);
    QTime endTime(0,0,0);
    QDate endDate = QDate::currentDate();


    std::cout << "Init request" << std::endl;
    qsipgaterpclib::SamuraiAccountStatementGetRequest *request =
            qsipgaterpclib::SamuraiAccountStatementGetRequestFactory::createInstance(&app)
            .withPeriodEnd(QDateTime(endDate, endTime))
            .withPeriodStart(QDateTime(startDate, startTime))
            .build();

    std::cout << "Get handler" << std::endl;

    std::cout << "Create output" << std::endl;
    tests::Output *output = new tests::Output();
    QObject::connect(rpcHandler, SIGNAL(error(QString)),
                     output, SLOT(doDisplayHandlerError(QString)));
    QObject::connect(request, SIGNAL(error(QString)),
                     output, SLOT(doDisplayError(QString)));
    QObject::connect(request, SIGNAL(ready(qsipgaterpclib::SamuraiAccountStatementGetResponse)),
                     output, SLOT(doDisplayAccountStatementResponse(qsipgaterpclib::SamuraiAccountStatementGetResponse)));

*/

/*
    std::cout << "Init request" << std::endl;
    qsipgaterpclib::SamuraiBalanceGetRequest *request =
            qsipgaterpclib::SamuraiBalanceGetRequestFactory::createInstance(&app)
            .build();

    std::cout << "Get handler" << std::endl;

    std::cout << "Create output" << std::endl;
    tests::Output *output = new tests::Output();
    QObject::connect(rpcHandler, SIGNAL(error(QString)),
                     output, SLOT(doDisplayHandlerError(QString)));
    QObject::connect(request, SIGNAL(error(QString)),
                     output, SLOT(doDisplayError(QString)));
    QObject::connect(request, SIGNAL(ready(qsipgaterpclib::SamuraiBalanceGetResponse)),
                     output, SLOT(doDisplayBalanceGetResponse(qsipgaterpclib::SamuraiBalanceGetResponse)));

*/

/*
    std::cout << "Init request" << std::endl;
    qsipgaterpclib::SamuraiClientIdentifyRequest *request =
            qsipgaterpclib::SamuraiClientIdentifyRequestFactory::createInstance(&app)
            .withClientName("QSipgateRpcLib")
            .withClientVendor("qt-project.org")
            .withClientVersion("0.0.1")
            .build();

    std::cout << "Get handler" << std::endl;

    std::cout << "Create output" << std::endl;
    tests::Output *output = new tests::Output();
    QObject::connect(rpcHandler, SIGNAL(error(QString)),
                     output, SLOT(doDisplayHandlerError(QString)));
    QObject::connect(request, SIGNAL(error(QString)),
                     output, SLOT(doDisplayError(QString)));
    QObject::connect(request, SIGNAL(ready(qsipgaterpclib::SamuraiClientIdentifyResponse)),
                     output, SLOT(doDisplayClientIdentifyResponse(qsipgaterpclib::SamuraiClientIdentifyResponse)));
*/

/*
    QDateTime start(QDate(2013,5,1));
    QDateTime end(QDate::currentDate());

    QList<QString> uriList;
    uriList.append(uri.toString());

    QList<QString> statusList;
    statusList.append(QString("accepted"));
    statusList.append(QString("outgoing"));

    std::cout << "Init request" << std::endl;
    qsipgaterpclib::SamuraiHistoryGetByDateRequest *request =
            qsipgaterpclib::SamuraiHistoryGetByDateRequestFactory::createInstance(&app)
          //  .withUri(uriList)
            .withStatus(statusList)
            .withPeriodStart(start)
            .withPeriodEnd(end)
            .build();

    std::cout << "Get handler" << std::endl;

    std::cout << "Create output" << std::endl;
    tests::Output *output = new tests::Output();
    QObject::connect(rpcHandler, SIGNAL(error(QString)),
                     output, SLOT(doDisplayHandlerError(QString)));
    QObject::connect(request, SIGNAL(error(QString)),
                     output, SLOT(doDisplayError(QString)));
    QObject::connect(request, SIGNAL(ready(qsipgaterpclib::SamuraiHistoryGetByDateResponse)),
                     output, SLOT(doDisplayHistoryResponse(qsipgaterpclib::SamuraiHistoryGetByDateResponse)));

*/
/*
    QDateTime start(QDate(2012,7,1));
    QDateTime end(QDate::currentDate());

    QList<QString> uriList;
    uriList.append(uri.toString());

    std::cout << "Init request" << std::endl;
    qsipgaterpclib::SamuraiItemizedEntriesGetRequest *request =
            qsipgaterpclib::SamuraiItemizedEntriesGetRequestFactory::createInstance(&app)
           // .withUri(uriList)
            .withPeriodStart(start)
            .withPeriodEnd(end)
            .build();

    std::cout << "Get handler" << std::endl;

    std::cout << "Create output" << std::endl;
    tests::Output *output = new tests::Output();
    QObject::connect(rpcHandler, SIGNAL(error(QString)),
                     output, SLOT(doDisplayHandlerError(QString)));
    QObject::connect(request, SIGNAL(error(QString)),
                     output, SLOT(doDisplayError(QString)));
    QObject::connect(request, SIGNAL(ready(qsipgaterpclib::SamuraiItemizedEntriesGetResponse)),
                     output, SLOT(doDisplayItemizedEntriesResponse(qsipgaterpclib::SamuraiItemizedEntriesGetResponse)));

*/


/*
    std::cout << "Init request" << std::endl;
    qsipgaterpclib::SamuraiOwnUriListGetRequest *request =
            qsipgaterpclib::SamuraiOwnUriListGetRequestFactory::createInstance(&app)
            .build();

    std::cout << "Get handler" << std::endl;

    std::cout << "Create output" << std::endl;
    tests::Output *output = new tests::Output();
    QObject::connect(rpcHandler, SIGNAL(error(QString)),
                     output, SLOT(doDisplayHandlerError(QString)));
    QObject::connect(request, SIGNAL(error(QString)),
                     output, SLOT(doDisplayError(QString)));
    QObject::connect(request, SIGNAL(ready(qsipgaterpclib::SamuraiOwnUriListGetResponse)),
                     output, SLOT(doDisplayOwnUriListResponse(qsipgaterpclib::SamuraiOwnUriListGetResponse)));
*/

/*
    QList<QString> entryList;
    entryList.append("70889");

    std::cout << "Init request" << std::endl;
    qsipgaterpclib::SamuraiPhonebookEntryGetRequest *request =
            qsipgaterpclib::SamuraiPhonebookEntryGetRequestFactory::createInstance(&app)
            .withEntryIdList(entryList)
            .build();

    std::cout << "Get handler" << std::endl;

    std::cout << "Create output" << std::endl;
    tests::Output *output = new tests::Output();
    QObject::connect(rpcHandler, SIGNAL(error(QString)),
                     output, SLOT(doDisplayHandlerError(QString)));
    QObject::connect(request, SIGNAL(error(QString)),
                     output, SLOT(doDisplayError(QString)));
    QObject::connect(request, SIGNAL(ready(qsipgaterpclib::SamuraiPhonebookEntryGetResponse)),
                     output, SLOT(doDisplayPhonebookEntryResponse(qsipgaterpclib::SamuraiPhonebookEntryGetResponse)));

*/

/*
    std::cout << "Init request" << std::endl;
    qsipgaterpclib::SamuraiPhonebookListGetRequest *request =
            qsipgaterpclib::SamuraiPhonebookListGetRequestFactory::createInstance(&app)
            .build();

    std::cout << "Get handler" << std::endl;

    std::cout << "Create output" << std::endl;
    tests::Output *output = new tests::Output();
    QObject::connect(rpcHandler, SIGNAL(error(QString)),
                     output, SLOT(doDisplayHandlerError(QString)));
    QObject::connect(request, SIGNAL(error(QString)),
                     output, SLOT(doDisplayError(QString)));
    QObject::connect(request, SIGNAL(ready(qsipgaterpclib::SamuraiPhonebookListGetResponse)),
                     output, SLOT(doDisplayPhonebookListResponse(qsipgaterpclib::SamuraiPhonebookListGetResponse)));

*/
    /*
    QList<QString> methodList;
    methodList.append("ItemizedEntriesGet");
    methodList.append("RecommendedIntervalGet");
    methodList.append("PhonebookEntryGet");

    std::cout << "Init request" << std::endl;
    qsipgaterpclib::SamuraiRecommendedIntervalGetRequest *request =
            qsipgaterpclib::SamuraiRecommendedIntervalGetRequestFactory::createInstance(&app)
            .withMethodList(methodList)
            .build();

    std::cout << "Get handler" << std::endl;

    std::cout << "Create output" << std::endl;
    tests::Output *output = new tests::Output();
    QObject::connect(rpcHandler, SIGNAL(error(QString)),
                     output, SLOT(doDisplayHandlerError(QString)));
    QObject::connect(request, SIGNAL(error(QString)),
                     output, SLOT(doDisplayError(QString)));
    QObject::connect(request, SIGNAL(ready(qsipgaterpclib::SamuraiRecommendedIntervalGetResponse)),
                     output, SLOT(doDisplayIntervalResponse(qsipgaterpclib::SamuraiRecommendedIntervalGetResponse)));

*/
/*
    std::cout << "Init request" << std::endl;
    qsipgaterpclib::SamuraiServerdataGetRequest *request =
            qsipgaterpclib::SamuraiServerdataGetRequestFactory::createInstance(&app)
            .build();

    std::cout << "Get handler" << std::endl;

    std::cout << "Create output" << std::endl;
    tests::Output *output = new tests::Output();
    QObject::connect(rpcHandler, SIGNAL(error(QString)),
                     output, SLOT(doDisplayHandlerError(QString)));
    QObject::connect(request, SIGNAL(error(QString)),
                     output, SLOT(doDisplayError(QString)));
    QObject::connect(request, SIGNAL(ready(qsipgaterpclib::SamuraiServerdataGetResponse)),
                     output, SLOT(doDisplayServerdataResponse(qsipgaterpclib::SamuraiServerdataGetResponse)));
*/
/*
    std::cout << "Init request" << std::endl;
    qsipgaterpclib::SamuraiTosListGetRequest *request =
            qsipgaterpclib::SamuraiTosListGetRequestFactory::createInstance(&app)
            .build();

    std::cout << "Get handler" << std::endl;

    std::cout << "Create output" << std::endl;
    tests::Output *output = new tests::Output();
    QObject::connect(rpcHandler, SIGNAL(error(QString)),
                     output, SLOT(doDisplayHandlerError(QString)));
    QObject::connect(request, SIGNAL(error(QString)),
                     output, SLOT(doDisplayError(QString)));
    QObject::connect(request, SIGNAL(ready(qsipgaterpclib::SamuraiTosListGetResponse)),
                     output, SLOT(doDisplayTosListResponse(qsipgaterpclib::SamuraiTosListGetResponse)));

*/


/*

    std::cout << "send rpc request" << std::endl;
    rpcHandler->sendRpcRequest(request);

    std::cout << "run" << std::endl;
    */
    return app.exec();
}
