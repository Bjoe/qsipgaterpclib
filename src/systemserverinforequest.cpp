#include "systemserverinforequest.h"

namespace qsipgaterpclib {

SystemServerInfoRequest::SystemServerInfoRequest(QObject *aParent)
    : AbstractRequest("system.serverInfo", aParent)
{
}

bool SystemServerInfoRequest::createResponse(const QVariantMap &aVariant)
{
    bool result = false;
    QVariant specVersion = aVariant.value("SpecificationVersion");
    QVariant serverName = aVariant.value("ServerName");
    QVariant serverVersion = aVariant.value("ServerVersion");
    QVariant serverVendor = aVariant.value("ServerVendor");

    if(specVersion.isValid() && serverName.isValid() &&
            serverVersion.isValid(), serverVendor.isValid()) {
        SystemServerInfoResponse response(specVersion.toString(),
                                          serverName.toString(),
                                          serverVersion.toString(),
                                          serverVendor.toString());
        emit ready(response);
        result = true;
    }
    return result;
}

} // namespace qsipgaterpclib
