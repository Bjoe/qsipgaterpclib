#ifndef QSIPGATERPCLIB_REQUEST_H
#define QSIPGATERPCLIB_REQUEST_H

#include <QObject>
#include <QString>
#include <QMap>
#include <QVariant>
#include <QVariantMap>

#include "abstractrequest.h"
#include "response.h"

namespace qsipgaterpclib {

class RequestFactory;

class Request : public AbstractRequest
{
    Q_OBJECT

public:
    virtual ~Request() {}

    virtual bool createResponse(const QVariantMap &aVariant);

signals:
    void ready(qsipgaterpclib::Response aResponse);

private:
    Request(QObject *aParent = 0);

    friend class RequestFactory;
};

class RequestFactory
{
public:
    static RequestFactory createInstance(QObject *aParent = 0)
    {
        return RequestFactory(aParent);
    }

    RequestFactory &withFoo(const QString &aFoo)
    {
        map.insert("Foo", QVariant(aFoo));
        return *this;
    }

    Request* build()
    {
        request->addArguments(map);
        return request;
    }

private:
    RequestFactory(QObject *aParent) : request(new Request(aParent))
    {}

    Request *request;
    QMap<QString, QVariant> map;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_REQUEST_H
