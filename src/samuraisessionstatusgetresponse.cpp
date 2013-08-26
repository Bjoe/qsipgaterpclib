#include "samuraisessionstatusgetresponse.h"

namespace qsipgaterpclib {

SamuraiSessionStatusGetResponse::SamuraiSessionStatusGetResponse(const QVariant &aStatus) : status(aStatus.toString())
{
}

} // namespace qsipgaterpclib
