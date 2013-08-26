#include "samuraiumsummarygetrequest.h"

namespace qsipgaterpclib {

SamuraiUmSummaryGetRequest::SamuraiUmSummaryGetRequest(QObject *aParent) : AbstractRequest("samurai.UmSummaryGet", aParent)
{
}

bool SamuraiUmSummaryGetRequest::createResponse(const QVariantMap &aVariant)
{
    bool result = false;

    QVariant summary = aVariant.value("UmSummary");

    if(summary.isValid()) {
        SamuraiUmSummaryGetResponse response(summary);
        emit ready(response);
        result = true;
    }
    return result;
}

} // namespace qsipgaterpclib
