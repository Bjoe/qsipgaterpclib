#include "samuraiownurilistgetrequest.h"

namespace qsipgaterpclib {

SamuraiOwnUriListGetRequest::SamuraiOwnUriListGetRequest(QObject *aParent) : AbstractRequest("samurai.OwnUriListGet", aParent)
{
}

bool SamuraiOwnUriListGetRequest::createResponse(const QVariantMap &aVariant)
{
    bool result = false;

    QVariant ownUriList = aVariant.value("OwnUriList");

    if(ownUriList.isValid()) {
        SamuraiOwnUriListGetResponse response(ownUriList);
        emit ready(response);
        result = true;
    }
    return result;
}

} // namespace qsipgaterpclib
