#include "samuraiuserdatasipgetrequest.h"

namespace qsipgaterpclib {

SamuraiUserdataSipGetRequest::SamuraiUserdataSipGetRequest(QObject *aParent) : AbstractRequest("samurai.UserdataSipGet", aParent)
{
}

bool SamuraiUserdataSipGetRequest::createResponse(const QVariantMap &aVariant)
{
    bool result = false;

    QVariant uriList = aVariant.value("SipDataList");

    if(uriList.isValid()) {
        SamuraiUserdataSipGetResponse response(uriList);
        emit ready(response);
        result = true;
    }
    return result;
}

} // namespace qsipgaterpclib
