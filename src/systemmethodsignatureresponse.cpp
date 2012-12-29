#include "systemmethodsignatureresponse.h"

namespace qsipgaterpclib {

SystemMethodSignatureResponse::SystemMethodSignatureResponse(const QString &aSignatureResponse) : signatureResponse(aSignatureResponse)
{
}

QString SystemMethodSignatureResponse::getSignature() const
{
    return signatureResponse;
}

} // namespace qsipgaterpclib
