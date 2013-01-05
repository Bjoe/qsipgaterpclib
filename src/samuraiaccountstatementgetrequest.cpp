#include "samuraiaccountstatementgetrequest.h"

namespace qsipgaterpclib {

SamuraiAccountStatementGetRequest::SamuraiAccountStatementGetRequest(QObject *aParent)
    : AbstractRequest("samurai.AccountStatementGet", aParent)
{
}

bool SamuraiAccountStatementGetRequest::createResponse(const QVariantMap &aVariant)
{
    bool result = false;

    QVariant periodStart = aVariant.value("PeriodStart");
    QVariant periodEnd = aVariant.value("PeriodEnd");
    QVariant accountStatements = aVariant.value("AccountStatementChargedServices");
    QVariant balanceStart = aVariant.value("BalanceStart");
    QVariant balanceEnd = aVariant.value("BalanceEnd");

    if(periodStart.isValid() && periodEnd.isValid() &&
            accountStatements.isValid() && balanceStart.isValid() &&
            balanceEnd.isValid()) {
        SamuraiAccountStatementGetResponse response(periodStart, periodEnd,
                                                    accountStatements,
                                                    balanceStart, balanceEnd);
        emit ready(response);
        result = true;
    }
    return result;
}

} // namespace qsipgaterpclib
