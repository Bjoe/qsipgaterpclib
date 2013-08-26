#include "samuraitoslistgetrequest.h"

namespace qsipgaterpclib {

SamuraiTosListGetRequest::SamuraiTosListGetRequest(QObject *aParent) : AbstractRequest("samurai.TosListGet", aParent)
{
}

bool SamuraiTosListGetRequest::createResponse(const QVariantMap &aVariant)
{
    bool result = false;

    QVariant tosList = aVariant.value("TosList");

    if(tosList.isValid()) {
        SamuraiTosListGetResponse response(tosList);
        emit ready(response);
        result = true;
    }
    return result;
}

} // namespace qsipgaterpclib
