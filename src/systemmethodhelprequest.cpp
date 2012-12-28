#include "systemmethodhelprequest.h"

namespace qsipgaterpclib {

SystemMethodHelpRequest::SystemMethodHelpRequest(QObject *aParent)
    : AbstractRequest("system.methodHelp", aParent)
{
}

bool SystemMethodHelpRequest::createResponse(const QVariantMap &aVariant)
{
    bool result = false;
    QVariant variant = aVariant.value("methodHelp");
    if(variant.isValid()) {
        QString helpMessage = variant.toString();
        SystemMethodHelpResponse response(helpMessage);
        emit ready(response);
        result = true;
    }
    return result;
}

} // namespace qsipgaterpclib
