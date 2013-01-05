#include "samuraiaccountstatementgetresponse.h"
#include <QDebug>

namespace qsipgaterpclib {

SamuraiAccountStatementGetResponse::SamuraiAccountStatementGetResponse(
        const QVariant &aStartPeriod,
        const QVariant &aEndPeriod,
        const QVariant &anAccountStatement,
        const QVariant &aBalanceStart,
        const QVariant &aBalanceEnd)
    : startPeriod(aStartPeriod.toDateTime()),
      endPeriod(aEndPeriod.toDateTime()),
      accountStatements(anAccountStatement.toList()),
      balanceStart(aBalanceStart.toMap()),
      balanceEnd(aBalanceEnd.toMap())
{}

QList<QList<QVariant> > SamuraiAccountStatementGetResponse::getAccountStatements() const
{
    QList<QList<QVariant> > list;

    foreach(QVariant variant, accountStatements) {
        QList<QVariant> line;
        QVariantMap map = variant.toMap();
        line.append(map.value("Timestamp"));
        line.append(map.value("Quantity"));
        line.append(map.value("ServiceName"));
        line.append(map.value("TotalDuration"));

        QVariantMap priceType = map.value("Price").toMap();
        line.append(priceType.value("TotalExcludingVat"));
        line.append(priceType.value("VatAmount"));
        line.append(priceType.value("VatPercent"));
        line.append(priceType.value("TotalIncludingVat"));
        line.append(priceType.value("Currency"));

        list.append(line);
    }

    return list;
}

QString SamuraiAccountStatementGetResponse::getDate(const QDateTime &aDateTime) const
{
    QDate date = aDateTime.date();
    return date.toString();
}

double SamuraiAccountStatementGetResponse::getTotalIncludingVat(const QVariantMap &aMap) const
{
    return aMap.value("TotalIncludingVat").toDouble();
}

QString SamuraiAccountStatementGetResponse::getCurrency(const QVariantMap &aMap) const
{
    return aMap.value("Currency").toString();
}

double SamuraiAccountStatementGetResponse::getTotalExcludingVat(const QVariantMap &aMap) const
{
    return aMap.value("TotalExcludingVat").toDouble();
}

double SamuraiAccountStatementGetResponse::getVatAmount(const QVariantMap &aMap) const
{
    return aMap.value("VatAmount").toDouble();
}

double SamuraiAccountStatementGetResponse::getVatPercent(const QVariantMap &aMap) const
{
    return aMap.value("VatPercent").toDouble();
}

} // namespace qsipgaterpclib
