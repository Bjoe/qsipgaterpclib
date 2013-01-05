#ifndef QSIPGATERPCLIB_SAMURAIACCOUNTSTATEMENTGETRESPONSE_H
#define QSIPGATERPCLIB_SAMURAIACCOUNTSTATEMENTGETRESPONSE_H

#include <QString>
#include <QVariant>
#include <QVariantMap>
#include <QDate>
#include <QDateTime>
#include <QList>

namespace qsipgaterpclib {

class SamuraiAccountStatementGetResponse
{
public:
    SamuraiAccountStatementGetResponse(const QVariant &aStartPeriod,
                                       const QVariant &aEndPeriod,
                                       const QVariant &anAccountStatement,
                                       const QVariant &aBalanceStart,
                                       const QVariant &aBalanceEnd);

    QDateTime getStartPeriod() const
    {
        return startPeriod;
    }

    QString getStartDate() const
    {
        return getDate(startPeriod);
    }

    QDateTime getEndPeriod() const
    {
        return endPeriod;
    }

    QString getEndDate() const
    {
        return getDate(endPeriod);
    }

    double getBalanceStartTotalIncludingVat() const
    {
        return getTotalIncludingVat(balanceStart);
    }

    QString getBalanceStartCurrency() const
    {
        return getCurrency(balanceStart);
    }

    double getBalanceStartTotalExcludingVat() const
    {
        return getTotalExcludingVat(balanceStart);
    }

    double getBalanceStartVatAmount() const
    {
        return getVatAmount(balanceStart);
    }

    double getBalanceStartVatPercent() const
    {
        return getVatPercent(balanceStart);
    }

    double getBalanceEndTotalIncludingVat() const
    {
        return getTotalIncludingVat(balanceEnd);
    }

    QString getBalanceEndCurrency() const
    {
        return getCurrency(balanceEnd);
    }

    double getBalanceEndTotalExcludingVat() const
    {
        return getTotalExcludingVat(balanceEnd);
    }

    double getBalanceEndVatAmount() const
    {
        return getVatAmount(balanceEnd);
    }

    double getBalanceEndVatPercent() const
    {
        return getVatPercent(balanceEnd);
    }

    QList<QList<QVariant> > getAccountStatements() const;

private:
    QDateTime startPeriod;
    QDateTime endPeriod;
    QVariantList accountStatements;
    QVariantMap balanceStart;
    QVariantMap balanceEnd;

    QString getDate(const QDateTime &aDateTime) const;
    double getTotalIncludingVat(const QVariantMap &aMap) const;
    QString getCurrency(const QVariantMap &aMap) const;
    double getTotalExcludingVat(const QVariantMap &aMap) const;
    double getVatAmount(const QVariantMap &aMap) const;
    double getVatPercent(const QVariantMap &aMap) const;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SAMURAIACCOUNTSTATEMENTGETRESPONSE_H
