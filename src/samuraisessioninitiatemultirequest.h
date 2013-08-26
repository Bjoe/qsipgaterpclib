#ifndef QSIPGATERPCLIB_SAMURAISESSIONINITIATEMULTIREQUEST_H
#define QSIPGATERPCLIB_SAMURAISESSIONINITIATEMULTIREQUEST_H

#include <QObject>
#include <QString>
#include <QMap>
#include <QList>
#include <QVariant>
#include <QVariantMap>
#include <QVariantList>

#include "abstractrequest.h"
#include "samuraisessioninitiatemultiresponse.h"

namespace qsipgaterpclib {

class SamuraiSessionInitiateMultiRequestFactory;

class SamuraiSessionInitiateMultiRequest : public AbstractRequest
{
    Q_OBJECT

public:
    virtual ~SamuraiSessionInitiateMultiRequest() {}

    virtual bool createResponse(const QVariantMap &aVariant);

signals:
    void ready(qsipgaterpclib::SamuraiSessionInitiateMultiResponse aResponse);

private:
    SamuraiSessionInitiateMultiRequest(QObject *aParent = 0);

    friend class SamuraiSessionInitiateMultiRequestFactory;
};

class SamuraiSessionInitiateMultiRequestFactory
{
public:
    static SamuraiSessionInitiateMultiRequestFactory createInstance(QObject *aParent = 0)
    {
        return SamuraiSessionInitiateMultiRequestFactory(aParent);
    }

    SamuraiSessionInitiateMultiRequestFactory &withLocalUri(const QString &aUri)
    {
        map.insert("LocalUri", QVariant(aUri));
        return *this;
    }

    SamuraiSessionInitiateMultiRequestFactory &withRemoteUris(const QList<QString> &aList)
    {
        QVariantList list;
        foreach(QString uri, aList) {
            list.append(uri);
        }

        map.insert("RemoteUri", QVariant(list));
        return *this;
    }

    SamuraiSessionInitiateMultiRequestFactory &withTos(const QString &aTos)
    {
        map.insert("TOS", QVariant(aTos));
        return *this;
    }

    SamuraiSessionInitiateMultiRequestFactory &withContent(const QString &aContent)
    {
        map.insert("Content", QVariant(aContent));
        return *this;
    }

    SamuraiSessionInitiateMultiRequestFactory &withSchedule(const QDateTime &aDateTime)
    {
        map.insert("Schedule", QVariant(aDateTime));
        return *this;
    }

    SamuraiSessionInitiateMultiRequest* build()
    {
        request->addArguments(map);
        return request;
    }

private:
    SamuraiSessionInitiateMultiRequestFactory(QObject *aParent) : request(new SamuraiSessionInitiateMultiRequest(aParent))
    {}

    SamuraiSessionInitiateMultiRequest *request;
    QMap<QString, QVariant> map;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SAMURAISESSIONINITIATEMULTIREQUEST_H
