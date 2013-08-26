#ifndef QSIPGATERPCLIB_SAMURAISERVERDATAGETRESPONSE_H
#define QSIPGATERPCLIB_SAMURAISERVERDATAGETRESPONSE_H

#include <QString>
#include <QVariant>

namespace qsipgaterpclib {

class SamuraiServerdataGetResponse
{
public:
    SamuraiServerdataGetResponse(const QVariant &aSipRegistrar, const QVariant &aSipOutboundProxy,
                                 const QVariant &aStunServer, const QVariant &aNtpServer,
                                 const QVariant &aHttpServer, const QVariant &aSamuraiServer,
                                 const QVariant &aSimpleServer, const QVariant &aXmppServer);

    QString getSipRegistrarServer() const
    {
        return sipRegistrarServer;
    }

    QString getSipOutboundProxy() const
    {
        return sipOutboundProxy;
    }

    QString getStunServer() const
    {
        return stunServer;
    }

    QString getNtpServer() const
    {
        return ntpServer;
    }

    QString getHttpServer() const
    {
        return httpServer;
    }

    QString getSamuraiServer() const
    {
        return samuraiServer;
    }

    QString getSimpleServer() const
    {
        return simpleServer;
    }

    QString getXmppServer() const
    {
        return xmppServer;
    }

private:
    QString sipRegistrarServer;
    QString sipOutboundProxy;
    QString stunServer;
    QString ntpServer;
    QString httpServer;
    QString samuraiServer;
    QString simpleServer;
    QString xmppServer;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SAMURAISERVERDATAGETRESPONSE_H
