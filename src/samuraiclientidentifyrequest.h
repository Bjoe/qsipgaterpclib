#ifndef QSIPGATERPCLIB_SAMURAICLIENTIDENTIFYREQUEST_H
#define QSIPGATERPCLIB_SAMURAICLIENTIDENTIFYREQUEST_H

#include <QObject>
#include <QString>
#include <QMap>
#include <QVariant>
#include <QVariantMap>

#include "abstractrequest.h"
#include "samuraiclientidentifyresponse.h"

namespace qsipgaterpclib {

class SamuraiClientIdentifyRequestFactory;

class SamuraiClientIdentifyRequest : public AbstractRequest
{
    Q_OBJECT

public:
    virtual ~SamuraiClientIdentifyRequest() {}

    virtual bool createResponse(const QVariantMap &aVariant);

signals:
    void ready(qsipgaterpclib::SamuraiClientIdentifyResponse aResponse);

private:
    SamuraiClientIdentifyRequest(QObject *aParent = 0);

    friend class SamuraiClientIdentifyRequestFactory;
};

class SamuraiClientIdentifyRequestFactory
{
public:
    static SamuraiClientIdentifyRequestFactory createInstance(QObject *aParent = 0)
    {
        return SamuraiClientIdentifyRequestFactory(aParent);
    }

    SamuraiClientIdentifyRequestFactory &withClientName(const QString &aName)
    {
        map.insert("ClientName", QVariant(aName));
        return *this;
    }

    SamuraiClientIdentifyRequestFactory &withClientVersion(const QString &aVersion)
    {
        map.insert("ClientVersion", QVariant(aVersion));
        return *this;
    }

    SamuraiClientIdentifyRequestFactory &withClientVendor(const QString &aVendor)
    {
        map.insert("ClientVendor", QVariant(aVendor));
        return *this;
    }

    SamuraiClientIdentifyRequest* build()
    {
        request->addArguments(map);
        return request;
    }

private:
    SamuraiClientIdentifyRequestFactory(QObject *aParent) : request(new SamuraiClientIdentifyRequest(aParent))
    {}

    SamuraiClientIdentifyRequest *request;
    QMap<QString, QVariant> map;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SAMURAICLIENTIDENTIFYREQUEST_H
