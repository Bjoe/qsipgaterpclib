#include "samuraisessioninitiatemultiresponse.h"

#include <QVariantMap>

namespace qsipgaterpclib {

SamuraiSessionInitiateMultiResponse::SamuraiSessionInitiateMultiResponse(const QVariant &aSessions) : sessionList(aSessions.toList())
{
}

QList<QList<QVariant> > SamuraiSessionInitiateMultiResponse::getSessionList() const
{
    QList<QList<QVariant> > list;

    foreach(QVariant variant, sessionList) {
        QVariantMap map = variant.toMap();
        QList<QVariant> line;

        line.append(map.value("SessionID"));
        line.append(map.value("RemoteUri"));

        list.append(line);
    }

    return list;
}

} // namespace qsipgaterpclib
