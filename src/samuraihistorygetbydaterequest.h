#ifndef QSIPGATERPCLIB_SAMURAIHISTORYGETBYDATEREQUEST_H
#define QSIPGATERPCLIB_SAMURAIHISTORYGETBYDATEREQUEST_H

#include <QObject>
#include <QString>
#include <QList>
#include <QDateTime>
#include <QMap>
#include <QVariant>
#include <QVariantList>
#include <QVariantMap>

#include "abstractrequest.h"
#include "samuraihistorygetbydateresponse.h"

namespace qsipgaterpclib {

class SamuraiHistoryGetByDateRequestFactory;

class SamuraiHistoryGetByDateRequest : public AbstractRequest
{
    Q_OBJECT

public:
    virtual ~SamuraiHistoryGetByDateRequest() {}

    virtual bool createResponse(const QVariantMap &aVariant);

signals:
    void ready(qsipgaterpclib::SamuraiHistoryGetByDateResponse aResponse);

private:
    SamuraiHistoryGetByDateRequest(QObject *aParent = 0);

    friend class SamuraiHistoryGetByDateRequestFactory;
};

class SamuraiHistoryGetByDateRequestFactory
{
public:
    static SamuraiHistoryGetByDateRequestFactory createInstance(QObject *aParent = 0)
    {
        return SamuraiHistoryGetByDateRequestFactory(aParent);
    }

    SamuraiHistoryGetByDateRequestFactory &withUri(const QList<QString> &aUriList)
    {
        QVariantList list;
        foreach(QString uri, aUriList) {
            list.append(QVariant(uri));
        }

        map.insert("LocalUriList", QVariant(list));
        return *this;
    }

    SamuraiHistoryGetByDateRequestFactory &withStatus(const QList<QString> &aStatusList)
    {
        QVariantList list;
        foreach(QString status, aStatusList) {
            list.append(QVariant(status));
        }

        map.insert("StatusList", QVariant(list));
        return *this;
    }

    SamuraiHistoryGetByDateRequestFactory &withPeriodStart(const QDateTime &aPeriodStart)
    {
        map.insert("PeriodStart", QVariant(aPeriodStart));
        return *this;
    }

    SamuraiHistoryGetByDateRequestFactory &withPeriodEnd(const QDateTime &aPeriodEnd)
    {
        map.insert("PeriodEnd", QVariant(aPeriodEnd));
        return *this;
    }

    SamuraiHistoryGetByDateRequest* build()
    {
        request->addArguments(map);
        return request;
    }

private:
    SamuraiHistoryGetByDateRequestFactory(QObject *aParent) : request(new SamuraiHistoryGetByDateRequest(aParent))
    {}

    SamuraiHistoryGetByDateRequest *request;
    QMap<QString, QVariant> map;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SAMURAIHISTORYGETBYDATEREQUEST_H
