#include "abstractrequest.h"

namespace qsipgaterpclib {

AbstractRequest::AbstractRequest(const QString &aMethod, QObject *parent) :
    QObject(parent), arguments(), method(aMethod)
{}

void AbstractRequest::handleResponse(const QVariant &aVariant)
{
    QVariantMap variantMap = aVariant.toMap();

    QVariant statusCode = variantMap.value("StatusCode");
    if(statusCode.isValid() == false) {
        statusCode = variantMap.value("faultCode");
    }
    QVariant statusMessage = variantMap.value("StatusString");
    if(statusMessage.isValid() == false) {
        statusMessage = variantMap.value("faultString");
    }

    if(statusCode.isValid() && statusCode.toInt() == 200) {
        if(createResponse(variantMap) == false) {
            emit error(tr("Es ist ein Fehler beim erzeugen der Antwort aufgetreten"));
        }
    } else {
        if(statusCode.isValid() && statusMessage.isValid()) {
            QString errorMessage = QString("%1 (%2) (%3)")
                    .arg(tr("Es ist ein Fehler aufgetreten"))
                    .arg(statusCode.toInt())
                    .arg(statusMessage.toString());
            emit error(errorMessage);
        } else {
            emit error(tr("Es ist ein allgemeiner RPC Fehler aufgetreten"));
        }
    }
}

} // namespace qsipgaterpclib
