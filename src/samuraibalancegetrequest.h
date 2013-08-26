#ifndef QSIPGATERPCLIB_SAMURAIBALANCEGETREQUEST_H
#define QSIPGATERPCLIB_SAMURAIBALANCEGETREQUEST_H

#include <QObject>
#include <QVariantMap>

#include "abstractrequest.h"
#include "samuraibalancegetresponse.h"

namespace qsipgaterpclib {

class SamuraiBalanceGetRequestFactory;

class SamuraiBalanceGetRequest : public AbstractRequest
{
    Q_OBJECT

public:
    virtual ~SamuraiBalanceGetRequest() {}

    virtual bool createResponse(const QVariantMap &aVariant);

signals:
    void ready(qsipgaterpclib::SamuraiBalanceGetResponse aResponse);

private:
    SamuraiBalanceGetRequest(QObject *aParent = 0);

    friend class SamuraiBalanceGetRequestFactory;
};

class SamuraiBalanceGetRequestFactory
{
public:
    static SamuraiBalanceGetRequestFactory createInstance(QObject *aParent = 0)
    {
        return SamuraiBalanceGetRequestFactory(aParent);
    }

    SamuraiBalanceGetRequest* build()
    {
        return request;
    }

private:
    SamuraiBalanceGetRequestFactory(QObject *aParent) : request(new SamuraiBalanceGetRequest(aParent))
    {}

    SamuraiBalanceGetRequest *request;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SAMURAIBALANCEGETREQUEST_H
