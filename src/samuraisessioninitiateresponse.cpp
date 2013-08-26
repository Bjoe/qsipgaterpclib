#include "samuraisessioninitiateresponse.h"

namespace qsipgaterpclib {

SamuraiSessionInitiateResponse::SamuraiSessionInitiateResponse(const QVariant &aSesisonId) : sessionId(aSesisonId.toString())
{
}

} // namespace qsipgaterpclib
