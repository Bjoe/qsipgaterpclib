#include "samuraiownurilistgetresponse.h"

#include <QVariantMap>

namespace qsipgaterpclib {

SamuraiOwnUriListGetResponse::SamuraiOwnUriListGetResponse(const QVariant &aOwnUriList) : uriList(aOwnUriList.toList())
{
}

QList<QList<QVariant> > SamuraiOwnUriListGetResponse::getOwnUriList() const
{
    QList<QList<QVariant> > list;

    foreach(QVariant variant, uriList) {
        QVariantMap map = variant.toMap();
        QList<QVariant> line;
        line.append(map.value("SipUri"));
        line.append(map.value("E164Out"));
        line.append(map.value(("E164In")));
        line.append(map.value("TOS"));
        line.append(map.value(("DefaultUri")));
        line.append(map.value("UriAlias"));

        list.append(line);
    }

    return list;
}

} // namespace qsipgaterpclib
