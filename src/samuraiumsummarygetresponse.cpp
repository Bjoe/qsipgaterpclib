#include "samuraiumsummarygetresponse.h"

#include <QVariantMap>

namespace qsipgaterpclib {

SamuraiUmSummaryGetResponse::SamuraiUmSummaryGetResponse(const QVariant &aSummary) : list(aSummary.toList())
{
}

QList<QList<QVariant> > SamuraiUmSummaryGetResponse::getUmSummaryList() const
{
    QList<QList<QVariant> > summaryList;
    foreach(QVariant variant, list) {
        QVariantMap map = variant.toMap();
        QList<QVariant> line;

        line.append(map.value("Read"));
        line.append(map.value("Unread"));
        line.append(map.value("LabelName"));
        line.append(map.value("TOS"));

        summaryList.append(line);
    }

    return summaryList;
}

} // namespace qsipgaterpclib
