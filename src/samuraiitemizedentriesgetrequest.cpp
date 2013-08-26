#include "samuraiitemizedentriesgetrequest.h"

namespace qsipgaterpclib {

SamuraiItemizedEntriesGetRequest::SamuraiItemizedEntriesGetRequest(QObject *aParent) : AbstractRequest("samurai.ItemizedEntriesGet", aParent)
{
}

bool SamuraiItemizedEntriesGetRequest::createResponse(const QVariantMap &aVariant)
{
    bool result = false;

    QVariant periodStart = aVariant.value("PeriodStart");
    QVariant periodEnd = aVariant.value("PeriodEnd");
    QVariant entries = aVariant.value("ItemizedEntries");

    if(periodStart.isValid() && periodEnd.isValid() &&
            entries.isValid()) {
        SamuraiItemizedEntriesGetResponse response(periodStart, periodEnd, entries);
        emit ready(response);
        result = true;
    }
    return result;
}

} // namespace qsipgaterpclib
