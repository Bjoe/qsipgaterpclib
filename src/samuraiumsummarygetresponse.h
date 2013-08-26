#ifndef QSIPGATERPCLIB_SAMURAIUMSUMMARYGETRESPONSE_H
#define QSIPGATERPCLIB_SAMURAIUMSUMMARYGETRESPONSE_H

#include <QList>
#include <QVariant>
#include <QVariantList>

namespace qsipgaterpclib {

class SamuraiUmSummaryGetResponse
{
public:
    SamuraiUmSummaryGetResponse(const QVariant &aSummary);

    QList<QList<QVariant> > getUmSummaryList() const;

private:
    QVariantList list;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_RESPONSE_H
