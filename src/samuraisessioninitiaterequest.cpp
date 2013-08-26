#include "samuraisessioninitiaterequest.h"

namespace qsipgaterpclib {

SamuraiSessionInitiateRequest::SamuraiSessionInitiateRequest(QObject *aParent) : AbstractRequest("samurai.SessionInitiate", aParent)
{
}

bool SamuraiSessionInitiateRequest::createResponse(const QVariantMap &aVariant)
{
    bool result = false;

    QVariant sessionId = aVariant.value("SessionID");

    if(sessionId.isValid()) {
        SamuraiSessionInitiateResponse response(sessionId);
        emit ready(response);
        result = true;
    }
    return result;
}

} // namespace qsipgaterpclib
