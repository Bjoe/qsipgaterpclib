#ifndef QSIPGATERPCLIB_SAMURAIEVENTLISTGETREQUEST_H
#define QSIPGATERPCLIB_SAMURAIEVENTLISTGETREQUEST_H

#include <QObject>

#include "abstractrequest.h"
#include "samuraieventlistgetresponse.h"

namespace qsipgaterpclib {

class SamuraiEventListGetRequestFactory;

class SamuraiEventListGetRequest : public AbstractRequest
{
    Q_OBJECT

public:
    virtual ~SamuraiEventListGetRequest() {}

    virtual bool createResponse(const QVariantMap &aVariant);

signals:
    void ready(qsipgaterpclib::SamuraiEventListGetResponse aResponse);

private:
    SamuraiEventListGetRequest(QObject *aParent);

    friend class SamuraiEventListGetRequestFactory;
};

class SamuraiEventListGetRequestFactory
{
public:
    static SamuraiEventListGetRequestFactory createInstance(QObject *aParent = 0)
    {
        return SamuraiEventListGetRequestFactory(aParent);
    }

    SamuraiEventListGetRequestFactory &withLabels(const QList<QString> &labels)
    {
        insertStringList("Labels", labels);
        return *this;
    }

    SamuraiEventListGetRequestFactory &withEventIds(const QList<QString> &eventIds)
    {
        insertStringList("EventIDs", eventIds);
        return *this;
    }

    SamuraiEventListGetRequestFactory &withTos(const QList<QString> &tos)
    {
        insertStringList("TOS", tos);
        return *this;
    }

    SamuraiEventListGetRequestFactory &withLimit(int limit)
    {
        map.insert("Limit", QVariant(limit));
        return *this;
    }

    SamuraiEventListGetRequestFactory &withOffset(int offset)
    {
        map.insert("Offset", QVariant(offset));
        return *this;
    }

    SamuraiEventListGetRequestFactory &withPeriodStart(const QDateTime &startTime)
    {
        map.insert("PeriodStart", QVariant(startTime));
        return *this;
    }

    SamuraiEventListGetRequestFactory &withPeriodEnd(const QDateTime &endTime)
    {
        map.insert("PeriodEnd", QVariant(endTime));
        return *this;
    }

    SamuraiEventListGetRequestFactory &withIncrementBaseId(const QString &incrementBaseId)
    {
        QString trimmedString = incrementBaseId.trimmed();
        if(trimmedString.length() > 0) {
            map.insert("IncrementBaseID", QVariant(incrementBaseId));
        }
        return *this;
    }

    SamuraiEventListGetRequest* build()
    {
        request->addArguments(map);
        return request;
    }

private:
    SamuraiEventListGetRequestFactory(QObject *aParent) : request(new SamuraiEventListGetRequest(aParent))
    {}

    void insertStringList(const QString key, const QList<QString> &stringList);

    SamuraiEventListGetRequest *request;
    QMap<QString, QVariant> map;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SAMURAIEVENTLISTGETREQUEST_H
