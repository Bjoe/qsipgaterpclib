#ifndef QSIPGATERPCLIB_SAMURAIPHONEBOOKLISTGETREQUEST_H
#define QSIPGATERPCLIB_SAMURAIPHONEBOOKLISTGETREQUEST_H

#include <QObject>
#include <QString>
#include <QMap>
#include <QVariant>
#include <QVariantMap>

#include "abstractrequest.h"
#include "samuraiphonebooklistgetresponse.h"

namespace qsipgaterpclib {

class SamuraiPhonebookListGetRequestFactory;

class SamuraiPhonebookListGetRequest : public AbstractRequest
{
    Q_OBJECT

public:
    virtual ~SamuraiPhonebookListGetRequest() {}

    virtual bool createResponse(const QVariantMap &aVariant);

signals:
    void ready(qsipgaterpclib::SamuraiPhonebookListGetResponse aResponse);

private:
    SamuraiPhonebookListGetRequest(QObject *aParent = 0);

    friend class SamuraiPhonebookListGetRequestFactory;
};

class SamuraiPhonebookListGetRequestFactory
{
public:
    static SamuraiPhonebookListGetRequestFactory createInstance(QObject *aParent = 0)
    {
        return SamuraiPhonebookListGetRequestFactory(aParent);
    }

    SamuraiPhonebookListGetRequest* build()
    {
        return request;
    }

private:
    SamuraiPhonebookListGetRequestFactory(QObject *aParent) : request(new SamuraiPhonebookListGetRequest(aParent))
    {}

    SamuraiPhonebookListGetRequest *request;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SAMURAIPHONEBOOKLISTGETREQUEST_H
