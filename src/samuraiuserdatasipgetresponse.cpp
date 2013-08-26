#include "samuraiuserdatasipgetresponse.h"

#include <QVariantMap>

namespace qsipgaterpclib {

SamuraiUserdataSipGetResponse::SamuraiUserdataSipGetResponse(const QVariant &aList) : sipDataList(aList.toList())
{
}

QList<QList<QVariant> > SamuraiUserdataSipGetResponse::getSipDataList() const
{
    QList<QList<QVariant> > list;
    foreach(QVariant variant, sipDataList) {
        QVariantMap map = variant.toMap();
        QList<QVariant> line;

        line.append(map.value("LocalUri"));
        line.append(map.value("SipUserID"));
        line.append(map.value("SipPassword"));

        list.append(line);
    }
    return list;
}

} // namespace qsipgaterpclib
