#include "samuraihistorygetbydaterequest.h"

namespace qsipgaterpclib {

SamuraiHistoryGetByDateRequest::SamuraiHistoryGetByDateRequest(QObject *aParent) : AbstractRequest("samurai.HistoryGetByDate", aParent)
{
}

bool SamuraiHistoryGetByDateRequest::createResponse(const QVariantMap &aVariant)
{
    bool result = false;

    QVariant history = aVariant.value("History");

    if(history.isValid()) {
        SamuraiHistoryGetByDateResponse response(history);
        emit ready(response);
        result = true;
    }
    return result;
}

} // namespace qsipgaterpclib
