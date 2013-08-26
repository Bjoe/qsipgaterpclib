#include "samuraiclientidentifyrequest.h"

namespace qsipgaterpclib {

SamuraiClientIdentifyRequest::SamuraiClientIdentifyRequest(QObject *aParent) : AbstractRequest("samurai.ClientIdentify", aParent)
{
}

bool SamuraiClientIdentifyRequest::createResponse(const QVariantMap &aVariant)
{
    SamuraiClientIdentifyResponse response;
    emit ready(response);
    return true;
}

} // namespace qsipgaterpclib
