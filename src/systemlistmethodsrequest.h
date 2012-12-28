#ifndef QSIPGATERPCLIB_SYSTEMLISTMETHODSREQUEST_H
#define QSIPGATERPCLIB_SYSTEMLISTMETHODSREQUEST_H

#include <QObject>
#include <QVariantMap>

#include "abstractrequest.h"
#include "systemlistmethodsresponse.h"

namespace qsipgaterpclib
{
class SystemListMethodsRequestFactory;

class SystemListMethodsRequest : public AbstractRequest
{
    Q_OBJECT

public:
    virtual ~SystemListMethodsRequest() {}

    virtual bool createResponse(const QVariantMap &aVariant);

signals:
    void ready(qsipgaterpclib::SystemListMethodsResponse aResponse);

private:
    SystemListMethodsRequest(QObject *aParent = 0);

    friend class SystemListMethodsRequestFactory;
};

class SystemListMethodsRequestFactory
{
public:
    static SystemListMethodsRequestFactory createInstance()
    {
        return SystemListMethodsRequestFactory();
    }

    SystemListMethodsRequest *build()
    {
        return request;
    }

private:
    SystemListMethodsRequestFactory() : request(new SystemListMethodsRequest())
    {}

    SystemListMethodsRequest *request;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SYSTEMLISTMETHODSREQUEST_H
