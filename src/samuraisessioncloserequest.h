#ifndef QSIPGATERPCLIB_SAMURAISESSIONCLOSEREQUEST_H
#define QSIPGATERPCLIB_SAMURAISESSIONCLOSEREQUEST_H

#include <QObject>
#include <QString>
#include <QMap>
#include <QVariant>
#include <QVariantMap>

#include "abstractrequest.h"
#include "samuraisessioncloseresponse.h"

namespace qsipgaterpclib {

class SamuraiSessionCloseRequestFactory;

class SamuraiSessionCloseRequest : public AbstractRequest
{
    Q_OBJECT

public:
    virtual ~SamuraiSessionCloseRequest() {}

    virtual bool createResponse(const QVariantMap &aVariant);

signals:
    void ready(qsipgaterpclib::SamuraiSessionCloseResponse aResponse);

private:
    SamuraiSessionCloseRequest(QObject *aParent = 0);

    friend class SamuraiSessionCloseRequestFactory;
};

class SamuraiSessionCloseRequestFactory
{
public:
    static SamuraiSessionCloseRequestFactory createInstance(QObject *aParent = 0)
    {
        return SamuraiSessionCloseRequestFactory(aParent);
    }

    SamuraiSessionCloseRequestFactory &withSessionId(const QString &aSessionId)
    {
        map.insert("SessionID", QVariant(aSessionId));
        return *this;
    }

    SamuraiSessionCloseRequest* build()
    {
        request->addArguments(map);
        return request;
    }

private:
    SamuraiSessionCloseRequestFactory(QObject *aParent) : request(new SamuraiSessionCloseRequest(aParent))
    {}

    SamuraiSessionCloseRequest *request;
    QMap<QString, QVariant> map;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SAMURAISESSIONCLOSEREQUEST_H
