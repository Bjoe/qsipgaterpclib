#ifndef QSIPGATERPCLIB_SYSTEMMETHODSIGNATURERESPONSE_H
#define QSIPGATERPCLIB_SYSTEMMETHODSIGNATURERESPONSE_H

#include <QString>

namespace qsipgaterpclib {

class SystemMethodSignatureResponse
{
public:
    SystemMethodSignatureResponse(const QString &aHelpMessage);

    QString getSignature() const;

private:
    QString signatureResponse;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SYSTEMMETHODSIGNATURERESPONSE_H
