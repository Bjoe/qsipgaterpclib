#ifndef QSIPGATERPCLIB_SAMURAISESSIONSTATUSGETREQUEST_H
#define QSIPGATERPCLIB_SAMURAISESSIONSTATUSGETREQUEST_H

#include <QObject>
#include <QString>
#include <QMap>
#include <QVariant>
#include <QVariantMap>

#include "abstractrequest.h"
#include "samuraisessionstatusgetresponse.h"

namespace qsipgaterpclib {

class SamuraiSessionStatusGetRequestFactory;

class SamuraiSessionStatusGetRequest : public AbstractRequest
{
    Q_OBJECT

public:
    virtual ~SamuraiSessionStatusGetRequest() {}

    virtual bool createResponse(const QVariantMap &aVariant);

signals:
    void ready(qsipgaterpclib::SamuraiSessionStatusGetResponse aResponse);

private:
    SamuraiSessionStatusGetRequest(QObject *aParent = 0);

    friend class SamuraiSessionStatusGetRequestFactory;
};

class SamuraiSessionStatusGetRequestFactory
{
public:
    static SamuraiSessionStatusGetRequestFactory createInstance(QObject *aParent = 0)
    {
        return SamuraiSessionStatusGetRequestFactory(aParent);
    }

    SamuraiSessionStatusGetRequestFactory &withSessionId(const QString &aSessionId)
    {
        map.insert("SessionID", QVariant(aSessionId));
        return *this;
    }

    SamuraiSessionStatusGetRequest* build()
    {
        request->addArguments(map);
        return request;
    }

private:
    SamuraiSessionStatusGetRequestFactory(QObject *aParent) : request(new SamuraiSessionStatusGetRequest(aParent))
    {}

    SamuraiSessionStatusGetRequest *request;
    QMap<QString, QVariant> map;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SAMURAISESSIONSTATUSGETREQUEST_H
