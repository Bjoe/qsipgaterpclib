#ifndef QSIPGATERPCLIB_SAMURAIITEMIZEDENTRIESGETRESPONSE_H
#define QSIPGATERPCLIB_SAMURAIITEMIZEDENTRIESGETRESPONSE_H

#include <QDateTime>
#include <QList>
#include <QVariant>
#include <QVariantList>

namespace qsipgaterpclib {

class SamuraiItemizedEntriesGetResponse
{
public:
    SamuraiItemizedEntriesGetResponse(const QVariant &aPeriodStart, const QVariant &aPeriodEnd, const QVariant &anEntries);

    QDateTime getPeriodStart() const
    {
        return periodStart;
    }

    QDateTime getPeriodEnd() const
    {
        return periodEnd;
    }

    QList<QList<QVariant> > getItemizedEntries() const;

private:
    QDateTime periodStart;
    QDateTime periodEnd;
    QVariantList entries;

    void appendPriceType(QList<QVariant> &aLine, const QVariantMap &aMap, const QString &aKey) const;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SAMURAIITEMIZEDENTRIESGETRESPONSE_H
