#include "samuraiphonebooklistgetresponse.h"

namespace qsipgaterpclib {

SamuraiPhonebookListGetResponse::SamuraiPhonebookListGetResponse(const QVariant &aPhonebook) : phonebookList(aPhonebook.toList())
{
}

QList<QList<QVariant> > SamuraiPhonebookListGetResponse::getPhonebookList() const
{
    QList<QList<QVariant> > list;
    foreach(QVariant variant, phonebookList) {
        QVariantMap map = variant.toMap();
        QList<QVariant> line;

        line.append(map.value("EntryID"));
        line.append(map.value("EntryHash"));

        list.append(line);
    }

    return list;
}

} // namespace qsipgaterpclib
