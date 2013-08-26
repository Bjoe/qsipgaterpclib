#ifndef QSIPGATERPCLIB_SAMURAIOWNURILISTGETREQUEST_H
#define QSIPGATERPCLIB_SAMURAIOWNURILISTGETREQUEST_H

#include <QObject>
#include <QString>
#include <QMap>
#include <QVariant>
#include <QVariantMap>

#include "abstractrequest.h"
#include "samuraiownurilistgetresponse.h"

namespace qsipgaterpclib {

class SamuraiOwnUriListGetRequestFactory;

class SamuraiOwnUriListGetRequest : public AbstractRequest
{
    Q_OBJECT

public:
    virtual ~SamuraiOwnUriListGetRequest() {}

    virtual bool createResponse(const QVariantMap &aVariant);

signals:
    void ready(qsipgaterpclib::SamuraiOwnUriListGetResponse aResponse);

private:
    SamuraiOwnUriListGetRequest(QObject *aParent = 0);

    friend class SamuraiOwnUriListGetRequestFactory;
};

class SamuraiOwnUriListGetRequestFactory
{
public:
    static SamuraiOwnUriListGetRequestFactory createInstance(QObject *aParent = 0)
    {
        return SamuraiOwnUriListGetRequestFactory(aParent);
    }

    SamuraiOwnUriListGetRequest* build()
    {
        request->addArguments(map);
        return request;
    }

private:
    SamuraiOwnUriListGetRequestFactory(QObject *aParent) : request(new SamuraiOwnUriListGetRequest(aParent))
    {}

    SamuraiOwnUriListGetRequest *request;
    QMap<QString, QVariant> map;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_REQUEST_H
