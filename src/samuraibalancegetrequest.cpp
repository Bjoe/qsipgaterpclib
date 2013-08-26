#include "samuraibalancegetrequest.h"

#include <QString>

namespace qsipgaterpclib {

SamuraiBalanceGetRequest::SamuraiBalanceGetRequest(QObject *aParent) : AbstractRequest("samurai.BalanceGet", aParent)
{
}

bool SamuraiBalanceGetRequest::createResponse(const QVariantMap &aVariant)
{
    bool result = false;

    QVariant balanceTime = aVariant.value("BalanceTime");
    QVariant currentBalance = aVariant.value("CurrentBalance");

    if(balanceTime.isValid() && currentBalance.isValid()) {
        SamuraiBalanceGetResponse response(balanceTime, currentBalance);
        emit ready(response);
        result = true;
    }
    return result;
}

} // namespace qsipgaterpclib
