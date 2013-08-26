#ifndef QSIPGATERPCLIB_RPCCLIENTFACTORY_H
#define QSIPGATERPCLIB_RPCCLIENTFACTORY_H

#include <QObject>
#include <QxtXmlRpcClient>

namespace qsipgaterpclib
{

class RpcClientFactory
{
public:
    static RpcClientFactory createInstance(QObject *aParent = 0)
    {
        return RpcClientFactory(aParent);
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

    QxtXmlRpcClient *build() const;

private:
    RpcClientFactory(QObject *aParent) : parent(aParent), url(), userName(), password()
    {}

    QObject *parent;
    QString url;
    QString userName;
    QString password;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_RPCCLIENTFACTORY_H
