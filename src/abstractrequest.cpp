#include "abstractrequest.h"

namespace qsipgaterpclib {

AbstractRequest::AbstractRequest(const QString &aMethod, QObject *parent) :
    QObject(parent), arguments(), method(aMethod)
{}

void AbstractRequest::handleResponse(const QVariant &aVariant)
{
    QVariantMap variantMap = aVariant.toMap();

    QVariant statusMessage = variantMap.value("StatusString");
    QVariant statusCode = variantMap.value("StatusCode");

    if(!(statusCode.isValid() && statusCode.toInt() == 200)) {
        if(statusCode.isValid() && statusMessage.isValid()) {
            QString errorMessage = QString("%1 (%2) (%3)")
                    .arg(tr("Es ist ein Fehler aufgetreten"))
                    .arg(statusCode.toInt())
                    .arg(statusMessage.toString());
            emit error(errorMessage);
        } else {
            emit error(tr("Es ist ein Fehler aufgetreten"));
        }
    } else {
        if(createResponse(variantMap) == false) {
            emit error(tr("Es ist ein Fehler aufgetreten"));
        }
    }
}

} // namespace qsipgaterpclib
