#ifndef QSIPGATERPCLIB_SAMURAIUSERDATASIPGETREQUEST_H
#define QSIPGATERPCLIB_SAMURAIUSERDATASIPGETREQUEST_H

#include <QObject>
#include <QString>
#include <QString>
#include <QMap>
#include <QVariant>
#include <QVariantList>
#include <QVariantMap>

#include "abstractrequest.h"
#include "samuraiuserdatasipgetresponse.h"

namespace qsipgaterpclib {

class SamuraiUserdataSipGetRequestFactory;

class SamuraiUserdataSipGetRequest : public AbstractRequest
{
    Q_OBJECT

public:
    virtual ~SamuraiUserdataSipGetRequest() {}

    virtual bool createResponse(const QVariantMap &aVariant);

signals:
    void ready(qsipgaterpclib::SamuraiUserdataSipGetResponse aResponse);

private:
    SamuraiUserdataSipGetRequest(QObject *aParent = 0);

    friend class SamuraiUserdataSipGetRequestFactory;
};

class SamuraiUserdataSipGetRequestFactory
{
public:
    static SamuraiUserdataSipGetRequestFactory createInstance(QObject *aParent = 0)
    {
        return SamuraiUserdataSipGetRequestFactory(aParent);
    }

    SamuraiUserdataSipGetRequestFactory &withLocalUris(const QList<QString> &aList)
    {
        QVariantList variantList;
        foreach(QString uri, aList) {
            variantList.append(uri);
        }

        map.insert("LocalUriList", QVariant(variantList));
        return *this;
    }

    SamuraiUserdataSipGetRequest* build()
    {
        request->addArguments(map);
        return request;
    }

private:
    SamuraiUserdataSipGetRequestFactory(QObject *aParent) : request(new SamuraiUserdataSipGetRequest(aParent))
    {}

    SamuraiUserdataSipGetRequest *request;
    QMap<QString, QVariant> map;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SAMURAIUSERDATASIPGETREQUEST_H
