#include "systemmethodsignaturerequest.h"

namespace qsipgaterpclib {

SystemMethodSignatureRequest::SystemMethodSignatureRequest(QObject *aParent)
    : AbstractRequest("system.methodSignature", aParent)
{
}

bool SystemMethodSignatureRequest::createResponse(const QVariantMap &aVariant)
{
    bool result = false;
    QVariant variant = aVariant.value("methodSignature");
    if(variant.isValid()) {
        QString signatureResponse = variant.toString();
        SystemMethodSignatureResponse response(signatureResponse);
        emit ready(response);
        result = true;
    }
    return result;
}

} // namespace qsipgaterpclib
