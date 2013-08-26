#include "samuraiitemizedentriesgetresponse.h"

#include <QVariantMap>

namespace qsipgaterpclib {

SamuraiItemizedEntriesGetResponse::SamuraiItemizedEntriesGetResponse(
        const QVariant &aPeriodStart,
        const QVariant &aPeriodEnd,
        const QVariant &anEntries)
    : periodStart(aPeriodStart.toDateTime()),
      periodEnd(aPeriodEnd.toDateTime()),
      entries(anEntries.toList())
{
}

QList<QList<QVariant> > SamuraiItemizedEntriesGetResponse::getItemizedEntries() const
{
    QList<QList<QVariant> > list;

    foreach(QVariant variant, entries) {
        QVariantMap map = variant.toMap();
        QList<QVariant> line;
        line.append(map.value("Timestamp"));
        line.append(map.value("SourceUri"));
        line.append(map.value("TargetUri"));

        appendPriceType(line, map, "Price");
        appendPriceType(line, map, "SetupFee");
        appendPriceType(line, map, "PricePerUnit");

        line.append(map.value("TicksA"));
        line.append(map.value("TicksB"));
        line.append(map.value("UnitsCharged"));
        line.append(map.value("TariffName"));
        line.append(map.value("Duration"));
        line.append(map.value("TOS"));

        list.append(line);
    }

    return list;
}

void SamuraiItemizedEntriesGetResponse::appendPriceType(
        QList<QVariant> &aLine, const QVariantMap &aMap, const QString &aKey) const
{
    QVariantMap priceTypeMap = aMap.value(aKey).toMap();

    aLine.append(priceTypeMap.value("TotalExcludingVat"));
    aLine.append(priceTypeMap.value("TotalIncludingVat"));
    aLine.append(priceTypeMap.value("VatAmount"));
    aLine.append(priceTypeMap.value("VatPercent"));
    aLine.append(priceTypeMap.value("Currency"));
}

} // namespace qsipgaterpclib
