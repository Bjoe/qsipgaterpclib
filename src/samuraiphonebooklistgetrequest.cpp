#include "samuraiphonebooklistgetrequest.h"

namespace qsipgaterpclib {

SamuraiPhonebookListGetRequest::SamuraiPhonebookListGetRequest(QObject *aParent) : AbstractRequest("samurai.PhonebookListGet", aParent)
{
}

bool SamuraiPhonebookListGetRequest::createResponse(const QVariantMap &aVariant)
{
    bool result = false;

    QVariant phonebook = aVariant.value("PhonebookList");

    if(phonebook.isValid()) {
        SamuraiPhonebookListGetResponse response(phonebook);
        emit ready(response);
        result = true;
    }
    return result;
}

} // namespace qsipgaterpclib
