#ifndef QSIPGATERPCLIB_SYSTEMMETHODSIGNATUREREQUEST_H
#define QSIPGATERPCLIB_SYSTEMMETHODSIGNATUREREQUEST_H

#include <QObject>
#include <QString>
#include <QVariant>
#include <QHash>
#include <QVariantList>
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
    static SystemMethodSignatureRequestFactory createInstance()
    {
        return SystemMethodSignatureRequestFactory();
    }

    SystemMethodSignatureRequestFactory &withMethodName(const QString &aName)
    {
        QHash<QString, QVariant> map;
        map.insert("MethodName", QVariant(aName));
        argumentList.append(QVariant(map));

        return *this;
    }

    SystemMethodSignatureRequest* build()
    {
        request->setArguments(argumentList);
        return request;
    }

private:
    SystemMethodSignatureRequestFactory() : request(new SystemMethodSignatureRequest()), argumentList()
    {}

    SystemMethodSignatureRequest *request;
    QVariantList argumentList;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SYSTEMMETHODSIGNATUREREQUEST_H
