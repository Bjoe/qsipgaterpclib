#ifndef QSIPGATERPCLIB_SAMURAIRECOMMENDEDINTERVALGETREQUEST_H
#define QSIPGATERPCLIB_SAMURAIRECOMMENDEDINTERVALGETREQUEST_H

#include <QObject>
#include <QString>
#include <QMap>
#include <QList>
#include <QVariant>
#include <QVariantMap>

#include "abstractrequest.h"
#include "samurairecommendedintervalgetresponse.h"

namespace qsipgaterpclib {

class SamuraiRecommendedIntervalGetRequestFactory;

class SamuraiRecommendedIntervalGetRequest : public AbstractRequest
{
    Q_OBJECT

public:
    virtual ~SamuraiRecommendedIntervalGetRequest() {}

    virtual bool createResponse(const QVariantMap &aVariant);

signals:
    void ready(qsipgaterpclib::SamuraiRecommendedIntervalGetResponse aResponse);

private:
    SamuraiRecommendedIntervalGetRequest(QObject *aParent = 0);

    friend class SamuraiRecommendedIntervalGetRequestFactory;
};

class SamuraiRecommendedIntervalGetRequestFactory
{
public:
    static SamuraiRecommendedIntervalGetRequestFactory createInstance(QObject *aParent = 0)
    {
        return SamuraiRecommendedIntervalGetRequestFactory(aParent);
    }

    SamuraiRecommendedIntervalGetRequestFactory &withMethodList(const QList<QString> &aList)
    {
        QVariantList methodList;
        foreach(QString value, aList) {
            methodList.append(value);
        }

        map.insert("MethodList", QVariant(methodList));
        return *this;
    }

    SamuraiRecommendedIntervalGetRequest* build()
    {
        request->addArguments(map);
        return request;
    }

private:
    SamuraiRecommendedIntervalGetRequestFactory(QObject *aParent) : request(new SamuraiRecommendedIntervalGetRequest(aParent))
    {}

    SamuraiRecommendedIntervalGetRequest *request;
    QMap<QString, QVariant> map;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SAMURAIRECOMMENDEDINTERVALGETREQUEST_H
