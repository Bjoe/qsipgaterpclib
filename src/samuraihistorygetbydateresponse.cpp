#include "samuraihistorygetbydateresponse.h"

#include <QVariantMap>

namespace qsipgaterpclib {

SamuraiHistoryGetByDateResponse::SamuraiHistoryGetByDateResponse(const QVariant &aHistory) : historyList(aHistory.toList())
{
}

QList<QList<QVariant> > SamuraiHistoryGetByDateResponse::getHistoryEntrys() const
{
    QList<QList<QVariant> > list;

    foreach(QVariant variant, historyList) {
        QVariantMap history = variant.toMap();

        QList<QVariant> line;
        line.append(history.value("EntryID"));
        line.append(history.value("Timestamp"));
        line.append(history.value("TOS"));
        line.append(history.value("LocalUri"));
        line.append(history.value("RemoteUri"));
        line.append(history.value("Status"));

        list.append(line);
    }

    return list;
}

} // namespace qsipgaterpclib
