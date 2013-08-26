#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVariant>
#include <QList>
#include <QVariantList>
#include <QStringList>
#include <QDate>
#include <QDateTime>
#include <QMessageBox>
#include <QTreeWidgetItem>
#include <QDebug>

MainWindow::MainWindow(qsipgaterpclib::RpcHandler *rpcHandler, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_rpcHandler(rpcHandler),
    m_request(0)
{
    ui->setupUi(this);
    connect(m_rpcHandler, SIGNAL(error(QString)), SLOT(onHandlerError(QString)));

    connect(ui->systemMethodHelpButton, SIGNAL(clicked()), SLOT(onSystemListMethodsRequest()));
    connect(ui->samuraiEventListGetButton, SIGNAL(clicked()), SLOT(onSamuraiEventListGetRequest()));
    connect(ui->samuraiTosListGetButton, SIGNAL(clicked()), SLOT(onSamuraiTosListGetRequest()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onError(QString message)
{
    QMessageBox::critical(this,"Error",message,QMessageBox::Ok);
}

void MainWindow::onHandlerError(QString message)
{
    QMessageBox::critical(this,"Handler Error",message,QMessageBox::Ok);
}

void MainWindow::onSystemListMethodsRequest()
{
    m_request = qsipgaterpclib::SystemListMethodsRequestFactory::createInstance(this)
            .build();

    connect(m_request, SIGNAL(error(QString)), SLOT(onError(QString)));
    connect(m_request, SIGNAL(ready(qsipgaterpclib::SystemListMethodsResponse)),
                     SLOT(onSystemListMethodsResponse(qsipgaterpclib::SystemListMethodsResponse)));
    m_rpcHandler->sendRpcRequest(m_request);
}

void MainWindow::onSystemListMethodsResponse(qsipgaterpclib::SystemListMethodsResponse response)
{
    ui->systemMethodHelpWidget->addItems(response.getList());
    delete m_request;
    m_request = 0;
}

void MainWindow::onSamuraiEventListGetRequest()
{
    QString tos = ui->tosLine->text();
    QStringList tosList = tos.split(",", QString::SkipEmptyParts);

    QString eventIds = ui->eventIdLine->text();
    QStringList eventIdList = eventIds.split(",", QString::SkipEmptyParts);

    QString labels = ui->labelLine->text();
    QStringList labelList = labels.split(",", QString::SkipEmptyParts);

    if(ui->periodCheck->isChecked()) {
        m_request = qsipgaterpclib::SamuraiEventListGetRequestFactory::createInstance(this)
                .withLimit(ui->limitLine->text().toInt())
                .withOffset(ui->offsetLine->text().toInt())
                .withPeriodStart(QDateTime(ui->periodStartDate->date()))
                .withPeriodEnd(QDateTime(ui->periodEndDate->date()))
                .withTos(tosList)
                .withEventIds(eventIdList)
                .withLabels(labelList)
                .withIncrementBaseId(ui->baseIdLine->text())
                .build();
    } else {
        m_request = qsipgaterpclib::SamuraiEventListGetRequestFactory::createInstance(this)
                .withLimit(ui->limitLine->text().toInt())
                .withOffset(ui->offsetLine->text().toInt())
                .withTos(tosList)
                .withEventIds(eventIdList)
                .withLabels(labelList)
                .withIncrementBaseId(ui->baseIdLine->text())
                .build();
    }

    connect(m_request, SIGNAL(error(QString)), SLOT(onError(QString)));
    connect(m_request, SIGNAL(ready(qsipgaterpclib::SamuraiEventListGetResponse)),
            SLOT(onSamuraiEventListGetResponse(qsipgaterpclib::SamuraiEventListGetResponse)));
    m_rpcHandler->sendRpcRequest(m_request);
}

void MainWindow::onSamuraiEventListGetResponse(qsipgaterpclib::SamuraiEventListGetResponse response)
{
    QList<QVariantList> list = response.getEventList();

    QTreeWidgetItem *rootItem = ui->samuraiEventListGetWidget->invisibleRootItem();
    int x = 0;
    foreach(QVariantList line, list) {
        QTreeWidgetItem *event = new QTreeWidgetItem();
        event->setText(x, line.at(0).toString());

        QTreeWidgetItem *widgetLine = new QTreeWidgetItem();
        widgetLine->setText(0, line.at(1).toString());
        widgetLine->setText(1, line.at(2).toString());
        widgetLine->setText(2, line.at(3).toString());
        widgetLine->setText(3, line.at(4).toString());

        event->addChild(widgetLine);
        rootItem->addChild(event);
        x++;
    }

    delete m_request;
    m_request = 0;
}

void MainWindow::onSamuraiTosListGetRequest()
{
    m_request = qsipgaterpclib::SamuraiTosListGetRequestFactory::createInstance(this).build();

    connect(m_request, SIGNAL(error(QString)), SLOT(onError(QString)));
    connect(m_request, SIGNAL(ready(qsipgaterpclib::SamuraiTosListGetResponse)),
            SLOT(onSamuraiTosListGetResponse(qsipgaterpclib::SamuraiTosListGetResponse)));
    m_rpcHandler->sendRpcRequest(m_request);
}

void MainWindow::onSamuraiTosListGetResponse(qsipgaterpclib::SamuraiTosListGetResponse response)
{
    ui->samuraiTosListGetWidget->addItems(response.getTosList());
}
