#ifndef QSIPGATERPCLIB_RPCCLIENTFACTORY_H
#define QSIPGATERPCLIB_RPCCLIENTFACTORY_H

#include <QxtXmlRpcClient>

namespace qsipgaterpclib
{

class RpcClientFactory
{
public:
    static RpcClientFactory createInstance()
    {
        return RpcClientFactory();
    }

    RpcClientFactory &withUrl(const QString &anUrl)
    {
        url = anUrl;
        return *this;
    }

    RpcClientFactory &withUserName(const QString &anUserName)
    {
        userName = anUserName;
        return *this;
    }

    RpcClientFactory &withPassword(const QString &aPassword)
    {
        password = aPassword;
        return *this;
    }

    QxtXmlRpcClient *build() const
    {
        QUrl httpUrl(url);
        httpUrl.setUserName(userName);
        httpUrl.setPassword(password);
        QxtXmlRpcClient *rpcClient = new QxtXmlRpcClient();
        rpcClient->setServiceUrl(httpUrl);
        return rpcClient;
    }

private:
    RpcClientFactory() : url(), userName(), password()
    {}

    QString url;
    QString userName;
    QString password;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_RPCCLIENTFACTORY_H
