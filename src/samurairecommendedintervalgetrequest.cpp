#include "samurairecommendedintervalgetrequest.h"

namespace qsipgaterpclib {

SamuraiRecommendedIntervalGetRequest::SamuraiRecommendedIntervalGetRequest(QObject *aParent) : AbstractRequest("samurai.RecommendedIntervalGet", aParent)
{
}

bool SamuraiRecommendedIntervalGetRequest::createResponse(const QVariantMap &aVariant)
{
    bool result = false;

    QVariant interval = aVariant.value("IntervalList");

    if(interval.isValid()) {
        SamuraiRecommendedIntervalGetResponse response(interval);
        emit ready(response);
        result = true;
    }
    return result;
}

} // namespace qsipgaterpclib
