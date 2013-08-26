#ifndef QSIPGATERPCLIB_SAMURAIITEMIZEDENTRIESGETREQUEST_H
#define QSIPGATERPCLIB_SAMURAIITEMIZEDENTRIESGETREQUEST_H

#include <QObject>
#include <QString>
#include <QMap>
#include <QList>
#include <QVariant>
#include <QVariantList>
#include <QVariantMap>

#include "abstractrequest.h"
#include "samuraiitemizedentriesgetresponse.h"

namespace qsipgaterpclib {

class SamuraiItemizedEntriesGetRequestFactory;

class SamuraiItemizedEntriesGetRequest : public AbstractRequest
{
    Q_OBJECT

public:
    virtual ~SamuraiItemizedEntriesGetRequest() {}

    virtual bool createResponse(const QVariantMap &aVariant);

signals:
    void ready(qsipgaterpclib::SamuraiItemizedEntriesGetResponse aResponse);

private:
    SamuraiItemizedEntriesGetRequest(QObject *aParent = 0);

    friend class SamuraiItemizedEntriesGetRequestFactory;
};

class SamuraiItemizedEntriesGetRequestFactory
{
public:
    static SamuraiItemizedEntriesGetRequestFactory createInstance(QObject *aParent = 0)
    {
        return SamuraiItemizedEntriesGetRequestFactory(aParent);
    }

    SamuraiItemizedEntriesGetRequestFactory &withUri(const QList<QString> &aList)
    {
        QVariantList list;
        foreach(QString uri, aList) {
            list.append(QVariant(uri));
        }

        map.insert("LocalUriList", QVariant(list));
        return *this;
    }

    SamuraiItemizedEntriesGetRequestFactory &withPeriodStart(const QDateTime &aTime)
    {
        map.insert("PeriodStart", QVariant(aTime));
        return *this;
    }

    SamuraiItemizedEntriesGetRequestFactory &withPeriodEnd(const QDateTime &aTime)
    {
        map.insert("PeriodEnd", QVariant(aTime));
        return *this;
    }

    SamuraiItemizedEntriesGetRequest* build()
    {
        request->addArguments(map);
        return request;
    }

private:
    SamuraiItemizedEntriesGetRequestFactory(QObject *aParent) : request(new SamuraiItemizedEntriesGetRequest(aParent))
    {}

    SamuraiItemizedEntriesGetRequest *request;
    QMap<QString, QVariant> map;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SAMURAIITEMIZEDENTRIESGETREQUEST_H
