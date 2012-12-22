#include "systemlistmethodsrequest.h"

#include <QVariantList>

namespace qsipgaterpclib {

SystemListMethodsRequest::SystemListMethodsRequest(QObject *aParent) :
    AbstractRequest("system.listMethods", aParent), handler(new SystemListMethodsHandler(aParent))
{
}

SystemListMethodsHandler *SystemListMethodsRequest::getHandler()
{
    return handler;
}

} // namespace qsipgaterpclib
