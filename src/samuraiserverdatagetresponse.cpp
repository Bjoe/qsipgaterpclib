#include "samuraiserverdatagetresponse.h"

namespace qsipgaterpclib {

SamuraiServerdataGetResponse::SamuraiServerdataGetResponse(const QVariant &aSipRegistrar,
                                                           const QVariant &aSipOutboundProxy,
                                                           const QVariant &aStunServer,
                                                           const QVariant &aNtpServer,
                                                           const QVariant &aHttpServer,
                                                           const QVariant &aSamuraiServer,
                                                           const QVariant &aSimpleServer,
                                                           const QVariant &aXmppServer) :
    sipRegistrarServer(aSipRegistrar.toString()), sipOutboundProxy(aSipOutboundProxy.toString()),
    stunServer(aStunServer.toString()), ntpServer(aNtpServer.toString()),
    httpServer(aHttpServer.toString()), samuraiServer(aSamuraiServer.toString()),
    simpleServer(aSimpleServer.toString()), xmppServer(aXmppServer.toString())
{
}

} // namespace qsipgaterpclib
