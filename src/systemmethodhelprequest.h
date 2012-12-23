#ifndef QSIPGATERPCLIB_SYSTEMMETHODHELPREQUEST_H
#define QSIPGATERPCLIB_SYSTEMMETHODHELPREQUEST_H

#include <QObject>
#include <QString>
#include <QVariant>
#include <QHash>
#include <QVariantList>

#include "abstractrequest.h"
#include "systemmethodhelphandler.h"

namespace qsipgaterpclib {

class SystemMethodHelpRequestFactory;

class SystemMethodHelpRequest : public AbstractRequest
{
public:
    virtual ~SystemMethodHelpRequest() {}

    virtual SystemMethodHelpHandler *getHandler();

private:
    SystemMethodHelpRequest(QObject *aParent = 0);
    SystemMethodHelpHandler *handler;

    friend class SystemMethodHelpRequestFactory;
};

class SystemMethodHelpRequestFactory
{
public:
    static SystemMethodHelpRequestFactory createInstance()
    {
        return SystemMethodHelpRequestFactory();
    }

    SystemMethodHelpRequestFactory &withMethodName(const QString &aName)
    {
        QHash<QString, QVariant> map;
        map.insert("MethodName", QVariant(aName));
        argumentList.append(QVariant(map));

        return *this;
    }

    SystemMethodHelpRequest* build()
    {
        request->setArguments(argumentList);
        return request;
    }

private:
    SystemMethodHelpRequestFactory() : request(new SystemMethodHelpRequest()), argumentList()
    {}

    SystemMethodHelpRequest *request;
    QVariantList argumentList;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SYSTEMMETHODHELPREQUEST_H
