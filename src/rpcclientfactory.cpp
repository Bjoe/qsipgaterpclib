#include "rpcclientfactory.h"

#include <QUrl>

namespace qsipgaterpclib
{

QxtXmlRpcClient *RpcClientFactory::build() const
{
    QUrl httpUrl(url); // url, username and password lost in loss ?!?
    httpUrl.setUserName(userName);
    httpUrl.setPassword(password);
    QxtXmlRpcClient *rpcClient = new QxtXmlRpcClient(parent);
    rpcClient->setServiceUrl(httpUrl);
    return rpcClient;
}

}
