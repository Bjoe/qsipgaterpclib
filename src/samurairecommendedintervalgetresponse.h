#ifndef QSIPGATERPCLIB_SAMURAIRECOMMENDEDINTERVALGETRESPONSE_H
#define QSIPGATERPCLIB_SAMURAIRECOMMENDEDINTERVALGETRESPONSE_H

#include <QList>
#include <QVariant>
#include <QVariantList>

namespace qsipgaterpclib {

class SamuraiRecommendedIntervalGetResponse
{
public:
    SamuraiRecommendedIntervalGetResponse(const QVariant &anInterval);

    QList<QList<QVariant> > getIntervalList() const;

private:
    QVariantList intervalList;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_RESPONSE_H
