#include "samuraiuserdatagreetinggetresponse.h"

namespace qsipgaterpclib {

SamuraiUserdataGreetingGetResponse::SamuraiUserdataGreetingGetResponse(const QVariant &aGender, const QVariant &aFirstName, const QVariant &aLastName)
    : gender(aGender.toString()), firstName(aFirstName.toString()), lastName(aLastName.toString())
{
}

} // namespace qsipgaterpclib
