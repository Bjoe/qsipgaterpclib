#ifndef QSIPGATERPCLIB_SAMURAIUMSUMMARYGETREQUEST_H
#define QSIPGATERPCLIB_SAMURAIUMSUMMARYGETREQUEST_H

#include <QObject>
#include <QString>
#include <QList>
#include <QMap>
#include <QVariant>
#include <QVariantMap>

#include "abstractrequest.h"
#include "samuraiumsummarygetresponse.h"

namespace qsipgaterpclib {

class SamuraiUmSummaryGetRequestFactory;

class SamuraiUmSummaryGetRequest : public AbstractRequest
{
    Q_OBJECT

public:
    virtual ~SamuraiUmSummaryGetRequest() {}

    virtual bool createResponse(const QVariantMap &aVariant);

signals:
    void ready(qsipgaterpclib::SamuraiUmSummaryGetResponse aResponse);

private:
    SamuraiUmSummaryGetRequest(QObject *aParent = 0);

    friend class SamuraiUmSummaryGetRequestFactory;
};

class SamuraiUmSummaryGetRequestFactory
{
public:
    static SamuraiUmSummaryGetRequestFactory createInstance(QObject *aParent = 0)
    {
        return SamuraiUmSummaryGetRequestFactory(aParent);
    }

    SamuraiUmSummaryGetRequestFactory &withLabelNames(const QList<QString> &aList)
    {
        QVariantList variantList;
        foreach(QString value, aList) {
            variantList.append(QVariant(value));
        }

        map.insert("LabelName", QVariant(variantList));
        return *this;
    }

    SamuraiUmSummaryGetRequestFactory &withTos(const QList<QString> &aList)
    {
        QVariantList variantList;
        foreach(QString value, aList) {
            variantList.append(QVariant(value));
        }

        map.insert("TOS", QVariant(variantList));
        return *this;
    }

    SamuraiUmSummaryGetRequestFactory &withLocalUris(const QList<QString> &aList)
    {
        QVariantList variantList;
        foreach(QString value, aList) {
            variantList.append(QVariant(value));
        }

        map.insert("LocalUriList", QVariant(variantList));
        return *this;
    }

    SamuraiUmSummaryGetRequest* build()
    {
        request->addArguments(map);
        return request;
    }

private:
    SamuraiUmSummaryGetRequestFactory(QObject *aParent) : request(new SamuraiUmSummaryGetRequest(aParent))
    {}

    SamuraiUmSummaryGetRequest *request;
    QMap<QString, QVariant> map;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_REQUEST_H
