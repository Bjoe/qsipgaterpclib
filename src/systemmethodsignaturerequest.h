#ifndef QSIPGATERPCLIB_SYSTEMMETHODSIGNATUREREQUEST_H
#define QSIPGATERPCLIB_SYSTEMMETHODSIGNATUREREQUEST_H

#include <QObject>
#include <QString>
#include <QVariant>
#include <QMap>
#include <QVariantMap>

#include "abstractrequest.h"
#include "systemmethodsignatureresponse.h"

namespace qsipgaterpclib {

class SystemMethodSignatureRequest : public AbstractRequest
{
    Q_OBJECT

public:
    virtual ~SystemMethodSignatureRequest() {}

    virtual bool createResponse(const QVariantMap &aVariant);

signals:
    void ready(qsipgaterpclib::SystemMethodSignatureResponse aResponse);

private:
    SystemMethodSignatureRequest(QObject *aParent = 0);

    friend class SystemMethodSignatureRequestFactory;
};

class SystemMethodSignatureRequestFactory
{
public:
    static SystemMethodSignatureRequestFactory createInstance(QObject *aParent = 0)
    {
        return SystemMethodSignatureRequestFactory(aParent);
    }

    SystemMethodSignatureRequestFactory &withMethodName(const QString &aName)
    {
        map.insert("MethodName", QVariant(aName));
        return *this;
    }

    SystemMethodSignatureRequest* build()
    {
        request->addArguments(map);
        return request;
    }

private:
    SystemMethodSignatureRequestFactory(QObject *aParent) : request(new SystemMethodSignatureRequest(aParent)), map()
    {}

    SystemMethodSignatureRequest *request;
    QMap<QString, QVariant> map;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SYSTEMMETHODSIGNATUREREQUEST_H
