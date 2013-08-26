#include "samuraisessioninitiatemultirequest.h"

namespace qsipgaterpclib {

SamuraiSessionInitiateMultiRequest::SamuraiSessionInitiateMultiRequest(QObject *aParent) : AbstractRequest("samurai.SessionInitiateMulti", aParent)
{
}

bool SamuraiSessionInitiateMultiRequest::createResponse(const QVariantMap &aVariant)
{
    bool result = false;

    QVariant sessions = aVariant.value("SessionList");

    if(sessions.isValid()) {
        SamuraiSessionInitiateMultiResponse response(sessions);
        emit ready(response);
        result = true;
    }
    return result;
}

} // namespace qsipgaterpclib
