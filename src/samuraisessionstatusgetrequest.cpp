#include "samuraisessionstatusgetrequest.h"

namespace qsipgaterpclib {

SamuraiSessionStatusGetRequest::SamuraiSessionStatusGetRequest(QObject *aParent) : AbstractRequest("samurai.SessionStatusGet", aParent)
{
}

bool SamuraiSessionStatusGetRequest::createResponse(const QVariantMap &aVariant)
{
    bool result = false;

    QVariant status = aVariant.value("SessionStatus");

    if(status.isValid()) {
        SamuraiSessionStatusGetResponse response(status);
        emit ready(response);
        result = true;
    }
    return result;
}

} // namespace qsipgaterpclib
