#include "samuraiuserdatagreetinggetrequest.h"

namespace qsipgaterpclib {

SamuraiUserdataGreetingGetRequest::SamuraiUserdataGreetingGetRequest(QObject *aParent) : AbstractRequest("samurai.UserdataGreetingGet", aParent)
{
}

bool SamuraiUserdataGreetingGetRequest::createResponse(const QVariantMap &aVariant)
{
    bool result = false;

    QVariant gender = aVariant.value("Gender");
    QVariant firstName = aVariant.value("FirstName");
    QVariant lastName = aVariant.value("LastName");

    if(gender.isValid() && firstName.isValid() && lastName.isValid()) {
        SamuraiUserdataGreetingGetResponse response(gender, firstName, lastName);
        emit ready(response);
        result = true;
    }
    return result;
}

} // namespace qsipgaterpclib
