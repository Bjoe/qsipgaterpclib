#ifndef QSIPGATERPCLIB_SAMURAISERVERDATAGETREQUEST_H
#define QSIPGATERPCLIB_SAMURAISERVERDATAGETREQUEST_H

#include <QObject>
#include <QString>
#include <QMap>
#include <QVariant>
#include <QVariantMap>

#include "abstractrequest.h"
#include "samuraiserverdatagetresponse.h"

namespace qsipgaterpclib {

class SamuraiServerdataGetRequestFactory;

class SamuraiServerdataGetRequest : public AbstractRequest
{
    Q_OBJECT

public:
    virtual ~SamuraiServerdataGetRequest() {}

    virtual bool createResponse(const QVariantMap &aVariant);

signals:
    void ready(qsipgaterpclib::SamuraiServerdataGetResponse aResponse);

private:
    SamuraiServerdataGetRequest(QObject *aParent = 0);

    friend class SamuraiServerdataGetRequestFactory;
};

class SamuraiServerdataGetRequestFactory
{
public:
    static SamuraiServerdataGetRequestFactory createInstance(QObject *aParent = 0)
    {
        return SamuraiServerdataGetRequestFactory(aParent);
    }

    SamuraiServerdataGetRequest* build()
    {
        return request;
    }

private:
    SamuraiServerdataGetRequestFactory(QObject *aParent) : request(new SamuraiServerdataGetRequest(aParent))
    {}

    SamuraiServerdataGetRequest *request;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SAMURAISERVERDATAGETREQUEST_H
