#include "systemmethodhelprequest.h"

namespace qsipgaterpclib {

SystemMethodHelpRequest::SystemMethodHelpRequest(QObject *aParent)
    : AbstractRequest("system.methodHelp", aParent), handler(new SystemMethodHelpHandler(aParent))
{
}

SystemMethodHelpHandler *SystemMethodHelpRequest::getHandler()
{
    return handler;
}

} // namespace qsipgaterpclib
