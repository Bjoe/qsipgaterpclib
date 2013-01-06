#ifndef QSIPGATERPCLIB_SAMURAIACCOUNTSTATEMENTGETREQUEST_H
#define QSIPGATERPCLIB_SAMURAIACCOUNTSTATEMENTGETREQUEST_H

#include <QObject>
#include <QString>
#include <QMap>
#include <QVariant>
#include <QVariantMap>
#include <QDateTime>

#include "abstractrequest.h"
#include "samuraiaccountstatementgetresponse.h"

namespace qsipgaterpclib {

class SamuraiAccountStatementGetRequestFactory;

class SamuraiAccountStatementGetRequest : public AbstractRequest
{
    Q_OBJECT

public:
    virtual ~SamuraiAccountStatementGetRequest() {}

    virtual bool createResponse(const QVariantMap &aVariant);

signals:
    void ready(qsipgaterpclib::SamuraiAccountStatementGetResponse aResponse);

private:
    SamuraiAccountStatementGetRequest(QObject *aParent = 0);

    friend class SamuraiAccountStatementGetRequestFactory;
};

class SamuraiAccountStatementGetRequestFactory
{
public:
    static SamuraiAccountStatementGetRequestFactory createInstance(QObject *aParent = 0)
    {
        return SamuraiAccountStatementGetRequestFactory(aParent);
    }

    SamuraiAccountStatementGetRequestFactory &withPeriodStart(const QDateTime &aPeriodStart)
    {
        map.insert("PeriodStart", QVariant(aPeriodStart));
        return *this;
    }

    SamuraiAccountStatementGetRequestFactory &withPeriodEnd(const QDateTime &aPeriodEnd)
    {
        map.insert("PeriodEnd", QVariant(aPeriodEnd));
        return *this;
    }


    SamuraiAccountStatementGetRequest* build()
    {
        request->addArguments(map);
        return request;
    }

private:
    SamuraiAccountStatementGetRequestFactory(QObject *aParent) : request(new SamuraiAccountStatementGetRequest(aParent))
    {}

    SamuraiAccountStatementGetRequest *request;
    QMap<QString, QVariant> map;
};


} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SAMURAIACCOUNTSTATEMENTGETREQUEST_H
