#include "systemmethodhelpresponse.h"

namespace qsipgaterpclib {

SystemMethodHelpResponse::SystemMethodHelpResponse(const QString &aHelpMessage) : helpMessage(aHelpMessage)
{
}

QString SystemMethodHelpResponse::getHelp() const
{
    return helpMessage;
}

} // namespace qsipgaterpclib
