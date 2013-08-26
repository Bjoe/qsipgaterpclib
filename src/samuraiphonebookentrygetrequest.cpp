#include "samuraiphonebookentrygetrequest.h"

namespace qsipgaterpclib {

SamuraiPhonebookEntryGetRequest::SamuraiPhonebookEntryGetRequest(QObject *aParent) : AbstractRequest("samurai.PhonebookEntryGet", aParent)
{
}

bool SamuraiPhonebookEntryGetRequest::createResponse(const QVariantMap &aVariant)
{
    bool result = false;

    QVariant entryList = aVariant.value("EntryList");

    if(entryList.isValid()) {
        SamuraiPhonebookEntryGetResponse response(entryList);
        emit ready(response);
        result = true;
    }
    return result;
}

} // namespace qsipgaterpclib
