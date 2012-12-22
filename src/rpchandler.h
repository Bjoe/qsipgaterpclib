#ifndef QSIPGATERPCLIB_RPCHANDLER_H
#define QSIPGATERPCLIB_RPCHANDLER_H

#include <QObject>
#include <QString>
#include <QVariantList>
#include <QNetworkReply>
#include <QSslError>
#include <QxtXmlRpcClient>
#include <QxtXmlRpcCall>

#include "abstracthandler.h"
#include "abstractrequest.h"

namespace qsipgaterpclib
{

class RpcHandler : public QObject
{
    Q_OBJECT

public:
    explicit RpcHandler(QxtXmlRpcClient *aXmlRpcClient, QObject *aParent = 0);
    virtual ~RpcHandler();

    bool sendRpcRequest(AbstractRequest *aRequest);

signals:
    void error(QString aMessage);

public slots:
    void rpcError(QNetworkReply::NetworkError aCode);
    void rpcSslErrors(const QList<QSslError> &anErrors);
    void rpcFinished();

private:
    QxtXmlRpcClient *xmlRpcClient;
    QxtXmlRpcCall *rpcCall;
    AbstractHandler *requestHandler;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_RPCHANDLER_H
