#include "abstractrequest.h"

namespace qsipgaterpclib {

AbstractRequest::AbstractRequest(const QString &aMethod, QObject *parent) :
    QObject(parent), arguments(), method(aMethod)
{}

} // namespace qsipgaterpclib
