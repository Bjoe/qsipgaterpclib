#include "samuraisessioncloserequest.h"

namespace qsipgaterpclib {

SamuraiSessionCloseRequest::SamuraiSessionCloseRequest(QObject *aParent) : AbstractRequest("samurai.SessionClose", aParent)
{
}

bool SamuraiSessionCloseRequest::createResponse(const QVariantMap &aVariant)
{
    bool result = false;

    SamuraiSessionCloseResponse response;
    emit ready(response);
    result = true;
    return result;
}

} // namespace qsipgaterpclib
