#include "systemlistmethodshandler.h"

#include <QVariantList>

namespace qsipgaterpclib {

SystemListMethodsHandler::SystemListMethodsHandler(QObject *aParent) : AbstractHandler(aParent)
{
}

bool SystemListMethodsHandler::createResponse(const QVariantMap &aVariant)
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
