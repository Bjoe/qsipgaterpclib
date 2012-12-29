#include "systemserverinforesponse.h"

namespace qsipgaterpclib {

SystemServerInfoResponse::SystemServerInfoResponse(const QString &aSpecVersion, const QString &aServerName, const QString aServerVersion, const QString aServerVendor)
    : specVersion(aSpecVersion), serverName(aServerName), serverVersion(aServerVersion), serverVendor(aServerVendor)
{
}

} // namespace qsipgaterpclib
