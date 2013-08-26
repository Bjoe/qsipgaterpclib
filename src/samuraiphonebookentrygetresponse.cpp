#include "samuraiphonebookentrygetresponse.h"

#include <QVariantMap>

namespace qsipgaterpclib {

SamuraiPhonebookEntryGetResponse::SamuraiPhonebookEntryGetResponse(const QVariant &aVariant) : entryIdList(aVariant.toList())
{
}

QList<QList<QVariant> > SamuraiPhonebookEntryGetResponse::getEntryList() const
{
    QList<QList<QVariant> > list;
    foreach(QVariant variant, entryIdList) {
        QVariantMap map = variant.toMap();
        QList<QVariant> line;

        line.append(map.value("EntryID"));
        line.append(map.value("EntryHash"));
        line.append(map.value("Entry"));

        list.append(line);
    }

    return list;
}

} // namespace qsipgaterpclib
