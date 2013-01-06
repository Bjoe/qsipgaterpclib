#ifndef QSIPGATERPCLIB_SYSTEMMETHODHELPREQUEST_H
#define QSIPGATERPCLIB_SYSTEMMETHODHELPREQUEST_H

#include <QObject>
#include <QString>
#include <QVariant>
#include <QMap>
#include <QVariantMap>

#include "abstractrequest.h"
#include "systemmethodhelpresponse.h"

namespace qsipgaterpclib {

class SystemMethodHelpRequestFactory;

class SystemMethodHelpRequest : public AbstractRequest
{
    Q_OBJECT

public:
    virtual ~SystemMethodHelpRequest() {}

    virtual bool createResponse(const QVariantMap &aVariant);

signals:
    void ready(qsipgaterpclib::SystemMethodHelpResponse aResponse);

private:
    SystemMethodHelpRequest(QObject *aParent = 0);

    friend class SystemMethodHelpRequestFactory;
};

class SystemMethodHelpRequestFactory
{
public:
    static SystemMethodHelpRequestFactory createInstance(QObject *aParent = 0)
    {
        return SystemMethodHelpRequestFactory(aParent);
    }

    SystemMethodHelpRequestFactory &withMethodName(const QString &aName)
    {
        map.insert("MethodName", QVariant(aName));
        return *this;
    }

    SystemMethodHelpRequest* build()
    {
        request->addArguments(map);
        return request;
    }

private:
    SystemMethodHelpRequestFactory(QObject *aParent) : request(new SystemMethodHelpRequest(aParent)), map()
    {}

    SystemMethodHelpRequest *request;
    QMap<QString, QVariant> map;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SYSTEMMETHODHELPREQUEST_H
