#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QString>
#include <QWidget>
#include <QMainWindow>

#include "rpchandler.h"

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

#include "samuraieventlistgetrequest.h"
#include "samuraieventlistgetresponse.h"

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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(qsipgaterpclib::RpcHandler *rpcHandler, QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onError(QString message);
    void onHandlerError(QString message);

    void onSystemListMethodsRequest();
    void onSystemListMethodsResponse(qsipgaterpclib::SystemListMethodsResponse response);

    void onSamuraiEventListGetRequest();
    void onSamuraiEventListGetResponse(qsipgaterpclib::SamuraiEventListGetResponse response);

    void onSamuraiTosListGetRequest();
    void onSamuraiTosListGetResponse(qsipgaterpclib::SamuraiTosListGetResponse response);
    
private:
    Ui::MainWindow *ui;
    qsipgaterpclib::RpcHandler *m_rpcHandler;
    qsipgaterpclib::AbstractRequest *m_request;
};

#endif // MAINWINDOW_H
