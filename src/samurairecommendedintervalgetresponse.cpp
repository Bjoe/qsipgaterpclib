#include "samurairecommendedintervalgetresponse.h"

#include <QVariantMap>

namespace qsipgaterpclib {

SamuraiRecommendedIntervalGetResponse::SamuraiRecommendedIntervalGetResponse(const QVariant &anInterval) : intervalList(anInterval.toList())
{
}

QList<QList<QVariant> > SamuraiRecommendedIntervalGetResponse::getIntervalList() const
{
    QList<QList<QVariant> > list;
    foreach(QVariant variant, intervalList) {
        QVariantMap map = variant.toMap();
        QList<QVariant> line;

        line.append(map.value("MethodName"));
        line.append(map.value("RecommendedInterval"));

        list.append(line);
    }

    return list;
}

} // namespace qsipgaterpclib
