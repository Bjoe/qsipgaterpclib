#include "samuraieventlistgetrequest.h"

namespace qsipgaterpclib {

SamuraiEventListGetRequest::SamuraiEventListGetRequest(QObject *aParent) : AbstractRequest("samurai.EventListGet", aParent)
{
}

bool SamuraiEventListGetRequest::createResponse(const QVariantMap &aVariant)
{
    bool result = false;

    QVariant count = aVariant.value("OverallCount");
    QVariant eventList = aVariant.value("EventList");

    if(count.isValid() && count.toInt() > 0 && eventList.isValid()) {
        SamuraiEventListGetResponse response(count.toInt(), eventList);
        emit ready(response);
        result = true;
    }
    return result;
}

void SamuraiEventListGetRequestFactory::insertStringList(const QString key, const QList<QString> &stringList)
{
    if(stringList.size() > 0) {
        QVariantList list;
        foreach(QString string, stringList) {
            list.append(QVariant(string));
        }
        map.insert(key, QVariant(list));
    }
}

} // namespace qsipgaterpclib
