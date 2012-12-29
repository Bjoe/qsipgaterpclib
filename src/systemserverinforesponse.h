#ifndef QSIPGATERPCLIB_SYSTEMSERVERINFORESPONSE_H
#define QSIPGATERPCLIB_SYSTEMSERVERINFORESPONSE_H

#include <QString>

namespace qsipgaterpclib {

class SystemServerInfoResponse
{
public:
    SystemServerInfoResponse(const QString &aSpecVersion, const QString &aServerName, const QString aServerVersion, const QString aServerVendor);

    QString getSpecVersion() const
    {
        return specVersion;
    }

    QString getServerName() const
    {
        return serverName;
    }

    QString getServerVersion() const
    {
        return serverVersion;
    }

    QString getServerVendor() const
    {
        return serverVendor;
    }

private:
    QString specVersion;
    QString serverVersion;
    QString serverName;
    QString serverVendor;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SYSTEMSERVERINFORESPONSE_H
