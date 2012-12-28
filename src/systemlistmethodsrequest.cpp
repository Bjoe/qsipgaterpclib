#include "systemlistmethodsrequest.h"

#include <QVariantList>

namespace qsipgaterpclib {

SystemListMethodsRequest::SystemListMethodsRequest(QObject *aParent) :
    AbstractRequest("system.listMethods", aParent)
{
}

bool SystemListMethodsRequest::createResponse(const QVariantMap &aVariant)
{
    bool result = false;
    QVariant variant = aVariant.value("listMethods");
    if(variant.isValid()) {
        QVariantList methodsList = variant.toList();
        SystemListMethodsResponse response(methodsList);
        emit ready(response);
        result = true;
    }
    return result;
}

} // namespace qsipgaterpclib
