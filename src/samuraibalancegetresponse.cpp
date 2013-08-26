#include "samuraibalancegetresponse.h"

namespace qsipgaterpclib {

SamuraiBalanceGetResponse::SamuraiBalanceGetResponse(const QVariant &aBalanceTime, const QVariant &aCurrentBalance)
    : balanceTime(aBalanceTime.toDateTime()), priceType(aCurrentBalance.toMap())
{
}

} // namespace qsipgaterpclib
