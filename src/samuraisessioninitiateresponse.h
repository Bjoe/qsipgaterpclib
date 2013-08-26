#ifndef QSIPGATERPCLIB_SAMURAISESSIONINITIATERESPONSE_H
#define QSIPGATERPCLIB_SAMURAISESSIONINITIATERESPONSE_H

#include <QString>
#include <QVariant>

namespace qsipgaterpclib {

class SamuraiSessionInitiateResponse
{
public:
    SamuraiSessionInitiateResponse(const QVariant &aSesisonId);

    QString getSessionId() const
    {
        return sessionId;
    }

private:
    QString sessionId;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SAMURAISESSIONINITIATERESPONSE_H
