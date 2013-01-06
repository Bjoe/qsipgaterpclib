#ifndef QSIPGATERPCLIB_SYSTEMSERVERINFOREQUEST_H
#define QSIPGATERPCLIB_SYSTEMSERVERINFOREQUEST_H

#include <QObject>
#include <QString>
#include <QVariant>
#include <QHash>
#include <QVariantList>
#include <QVariantMap>

#include "abstractrequest.h"
#include "systemserverinforesponse.h"

namespace qsipgaterpclib {

class SystemServerInfoRequestFactory;

class SystemServerInfoRequest : public AbstractRequest
{
    Q_OBJECT

public:
    virtual ~SystemServerInfoRequest() {}

    virtual bool createResponse(const QVariantMap &aVariant);

signals:
    void ready(qsipgaterpclib::SystemServerInfoResponse aResponse);

private:
    SystemServerInfoRequest(QObject *aParent = 0);

    friend class SystemServerInfoRequestFactory;
};

class SystemServerInfoRequestFactory
{
public:
    static SystemServerInfoRequestFactory createInstance(QObject *aParent = 0)
    {
        return SystemServerInfoRequestFactory(aParent);
    }

    SystemServerInfoRequest* build()
    {
        return request;
    }

private:
    SystemServerInfoRequestFactory(QObject *aParent) : request(new SystemServerInfoRequest(aParent))
    {}

    SystemServerInfoRequest *request;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SYSTEMSERVERINFOREQUEST_H
