#include "systemmethodhelphandler.h"

#include <QVariant>
#include <QString>

namespace qsipgaterpclib {

SystemMethodHelpHandler::SystemMethodHelpHandler(QObject *parent) :
    AbstractHandler(parent)
{
}

bool SystemMethodHelpHandler::createResponse(const QVariantMap &aVariant)
{
    bool result = false;
    QVariant variant = aVariant.value("methodHelp");
    if(variant.isValid()) {
        QString helpMessage = variant.toString();
        SystemMethodHelpResponse response(helpMessage);
        emit ready(response);
        result = true;
    }
    return result;
}

} // namespace qsipgaterpclib
