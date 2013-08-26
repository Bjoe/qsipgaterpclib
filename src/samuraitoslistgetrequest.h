#ifndef QSIPGATERPCLIB_SAMURAITOSLISTGETREQUEST_H
#define QSIPGATERPCLIB_SAMURAITOSLISTGETREQUEST_H

#include <QObject>
#include <QString>
#include <QVariant>
#include <QVariantMap>

#include "abstractrequest.h"
#include "samuraitoslistgetresponse.h"

namespace qsipgaterpclib {

class SamuraiTosListGetRequestFactory;

class SamuraiTosListGetRequest : public AbstractRequest
{
    Q_OBJECT

public:
    virtual ~SamuraiTosListGetRequest() {}

    virtual bool createResponse(const QVariantMap &aVariant);

signals:
    void ready(qsipgaterpclib::SamuraiTosListGetResponse aResponse);

private:
    SamuraiTosListGetRequest(QObject *aParent = 0);

    friend class SamuraiTosListGetRequestFactory;
};

class SamuraiTosListGetRequestFactory
{
public:
    static SamuraiTosListGetRequestFactory createInstance(QObject *aParent = 0)
    {
        return SamuraiTosListGetRequestFactory(aParent);
    }

    SamuraiTosListGetRequest* build()
    {
        return request;
    }

private:
    SamuraiTosListGetRequestFactory(QObject *aParent) : request(new SamuraiTosListGetRequest(aParent))
    {}

    SamuraiTosListGetRequest *request;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SAMURAITOSLISTGETREQUEST_H
