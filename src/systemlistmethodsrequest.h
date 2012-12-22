#ifndef QSIPGATERPCLIB_SYSTEMLISTMETHODSREQUEST_H
#define QSIPGATERPCLIB_SYSTEMLISTMETHODSREQUEST_H

#include <QObject>
#include <QVariantMap>

#include "abstractrequest.h"

#include "systemlistmethodshandler.h"

namespace qsipgaterpclib
{
class SystemListMethodsRequestFactory;

class SystemListMethodsRequest : public AbstractRequest
{
public:
    virtual ~SystemListMethodsRequest() {}

    virtual SystemListMethodsHandler *getHandler();

private:
    SystemListMethodsHandler *handler;
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
        return new SystemListMethodsRequest();
    }

private:
    SystemListMethodsRequestFactory() : request(new SystemListMethodsRequest())
    {}

    SystemListMethodsRequest *request;
};




} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SYSTEMLISTMETHODSREQUEST_H
