#ifndef QSIPGATERPCLIB_SAMURAIBALANCEGETRESPONSE_H
#define QSIPGATERPCLIB_SAMURAIBALANCEGETRESPONSE_H

#include <QString>
#include <QVariant>
#include <QDateTime>

namespace qsipgaterpclib {

class SamuraiBalanceGetResponse
{
public:
    SamuraiBalanceGetResponse() {}
    SamuraiBalanceGetResponse(const QVariant &aBalanceTime, const QVariant &aCurrentBalance);

    QDateTime getBalanceTime() const
    {
        return balanceTime;
    }

    QVariant getTotalExcludingVat() const
    {
        return priceType.value("TotalExcludingVat");
    }

    QVariant getTotalIncludingVat() const
    {
        return priceType.value("TotalIncludingVat");
    }

    QVariant getVatAmount() const
    {
        return priceType.value("VatAmount");
    }

    QVariant getVatPercent() const
    {
        return priceType.value("VatPercent");
    }

    QString getCurrency() const
    {
        return priceType.value("Currency").toString();
    }

private:
    QDateTime balanceTime;
    QMap<QString, QVariant> priceType;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SAMURAIBALANCEGETRESPONSE_H
