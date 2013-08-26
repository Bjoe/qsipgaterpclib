#ifndef QSIPGATERPCLIB_SAMURAIUSERDATAGREETINGGETREQUEST_H
#define QSIPGATERPCLIB_SAMURAIUSERDATAGREETINGGETREQUEST_H

#include <QObject>
#include <QString>
#include <QVariant>

#include "abstractrequest.h"
#include "samuraiuserdatagreetinggetresponse.h"

namespace qsipgaterpclib {

class SamuraiUserdataGreetingGetRequestFactory;

class SamuraiUserdataGreetingGetRequest : public AbstractRequest
{
    Q_OBJECT

public:
    virtual ~SamuraiUserdataGreetingGetRequest() {}

    virtual bool createResponse(const QVariantMap &aVariant);

signals:
    void ready(qsipgaterpclib::SamuraiUserdataGreetingGetResponse aResponse);

private:
    SamuraiUserdataGreetingGetRequest(QObject *aParent = 0);

    friend class SamuraiUserdataGreetingGetRequestFactory;
};

class SamuraiUserdataGreetingGetRequestFactory
{
public:
    static SamuraiUserdataGreetingGetRequestFactory createInstance(QObject *aParent = 0)
    {
        return SamuraiUserdataGreetingGetRequestFactory(aParent);
    }

    SamuraiUserdataGreetingGetRequest* build()
    {
        return request;
    }

private:
    SamuraiUserdataGreetingGetRequestFactory(QObject *aParent) : request(new SamuraiUserdataGreetingGetRequest(aParent))
    {}

    SamuraiUserdataGreetingGetRequest *request;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SAMURAIUSERDATAGREETINGGETREQUEST_H
