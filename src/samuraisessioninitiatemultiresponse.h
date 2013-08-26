#ifndef QSIPGATERPCLIB_SAMURAISESSIONINITIATEMULTIRESPONSE_H
#define QSIPGATERPCLIB_SAMURAISESSIONINITIATEMULTIRESPONSE_H

#include <QList>
#include <QVariant>
#include <QVariantList>

namespace qsipgaterpclib {

class SamuraiSessionInitiateMultiResponse
{
public:
    SamuraiSessionInitiateMultiResponse(const QVariant &aSessions);

    QList<QList<QVariant> > getSessionList() const;

private:
    QVariantList sessionList;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SAMURAISESSIONINITIATEMULTIRESPONSE_H
