#include "samuraiserverdatagetrequest.h"

namespace qsipgaterpclib {

SamuraiServerdataGetRequest::SamuraiServerdataGetRequest(QObject *aParent) : AbstractRequest("samurai.ServerdataGet", aParent)
{
}

bool SamuraiServerdataGetRequest::createResponse(const QVariantMap &aVariant)
{
    bool result = false;

    QVariant sipRegistrar = aVariant.value("SipRegistrar");
    QVariant sipOutboundProxy = aVariant.value("SipOutboundProxy");
    QVariant stunServer = aVariant.value("StunServer");
    QVariant ntpServer = aVariant.value("NtpServer");
    QVariant httpServer = aVariant.value("HttpServer");
    QVariant samuraiServer = aVariant.value("SamuraiServer");
    QVariant simpleServer = aVariant.value("SimpleServer");
    QVariant xmppServer = aVariant.value("XmppServer");

    if(sipRegistrar.isValid() && sipOutboundProxy.isValid() &&
            stunServer.isValid() && ntpServer.isValid() &&
            httpServer.isValid() && samuraiServer.isValid() &&
            simpleServer.isValid() && xmppServer.isValid()) {
        SamuraiServerdataGetResponse response(sipRegistrar, sipOutboundProxy, stunServer,
                                              ntpServer, httpServer, samuraiServer,
                                              simpleServer, xmppServer);
        emit ready(response);
        result = true;
    }
    return result;
}

} // namespace qsipgaterpclib
