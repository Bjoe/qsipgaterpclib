#ifndef QSIPGATERPCLIB_SAMURAISESSIONSTATUSGETRESPONSE_H
#define QSIPGATERPCLIB_SAMURAISESSIONSTATUSGETRESPONSE_H

#include <QVariant>

namespace qsipgaterpclib {

class SamuraiSessionStatusGetResponse
{
public:
    SamuraiSessionStatusGetResponse(const QVariant &aStatus);

    QString getStatus() const
    {
        return status;
    }

private:
    QString status;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SAMURAISESSIONSTATUSGETRESPONSE_H
