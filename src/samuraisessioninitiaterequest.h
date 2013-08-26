#ifndef QSIPGATERPCLIB_SAMURAISESSIONINITIATEREQUEST_H
#define QSIPGATERPCLIB_SAMURAISESSIONINITIATEREQUEST_H

#include <QObject>
#include <QString>
#include <QMap>
#include <QVariant>
#include <QVariantMap>

#include "abstractrequest.h"
#include "samuraisessioninitiateresponse.h"

namespace qsipgaterpclib {

class SamuraiSessionInitiateRequestFactory;

class SamuraiSessionInitiateRequest : public AbstractRequest
{
    Q_OBJECT

public:
    virtual ~SamuraiSessionInitiateRequest() {}

    virtual bool createResponse(const QVariantMap &aVariant);

signals:
    void ready(qsipgaterpclib::SamuraiSessionInitiateResponse aResponse);

private:
    SamuraiSessionInitiateRequest(QObject *aParent = 0);

    friend class SamuraiSessionInitiateRequestFactory;
};

class SamuraiSessionInitiateRequestFactory
{
public:
    static SamuraiSessionInitiateRequestFactory createInstance(QObject *aParent = 0)
    {
        return SamuraiSessionInitiateRequestFactory(aParent);
    }

    SamuraiSessionInitiateRequestFactory &withLocalUri(const QString &aUri)
    {
        map.insert("LocalUri", QVariant(aUri));
        return *this;
    }

    SamuraiSessionInitiateRequestFactory &withRemoteUri(const QString &aUri)
    {
        map.insert("RemoteUri", QVariant(aUri));
        return *this;
    }

    SamuraiSessionInitiateRequestFactory &withTos(const QString &aTos)
    {
        map.insert("TOS", QVariant(aTos));
        return *this;
    }

    SamuraiSessionInitiateRequestFactory &withContent(const QString &aContent)
    {
        map.insert("Content", QVariant(aContent));
        return *this;
    }

    SamuraiSessionInitiateRequestFactory &withSchedule(const QDateTime &aDateTime)
    {
        map.insert("Schedule", QVariant(aDateTime));
        return *this;
    }

    SamuraiSessionInitiateRequest* build()
    {
        request->addArguments(map);
        return request;
    }

private:
    SamuraiSessionInitiateRequestFactory(QObject *aParent) : request(new SamuraiSessionInitiateRequest(aParent))
    {}

    SamuraiSessionInitiateRequest *request;
    QMap<QString, QVariant> map;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SAMURAISESSIONINITIATEREQUEST_H
