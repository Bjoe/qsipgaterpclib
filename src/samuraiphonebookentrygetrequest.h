#ifndef QSIPGATERPCLIB_SAMURAIPHONEBOOKENTRYGETREQUEST_H
#define QSIPGATERPCLIB_SAMURAIPHONEBOOKENTRYGETREQUEST_H

#include <QObject>
#include <QString>
#include <QList>
#include <QMap>
#include <QVariant>
#include <QVariantMap>

#include "abstractrequest.h"
#include "samuraiphonebookentrygetresponse.h"

namespace qsipgaterpclib {

class SamuraiPhonebookEntryGetRequestFactory;

class SamuraiPhonebookEntryGetRequest : public AbstractRequest
{
    Q_OBJECT

public:
    virtual ~SamuraiPhonebookEntryGetRequest() {}

    virtual bool createResponse(const QVariantMap &aVariant);

signals:
    void ready(qsipgaterpclib::SamuraiPhonebookEntryGetResponse aResponse);

private:
    SamuraiPhonebookEntryGetRequest(QObject *aParent = 0);

    friend class SamuraiPhonebookEntryGetRequestFactory;
};

class SamuraiPhonebookEntryGetRequestFactory
{
public:
    static SamuraiPhonebookEntryGetRequestFactory createInstance(QObject *aParent = 0)
    {
        return SamuraiPhonebookEntryGetRequestFactory(aParent);
    }

    SamuraiPhonebookEntryGetRequestFactory &withEntryIdList(const QList<QString> &anEntryIdList)
    {
        QVariantList list;
        foreach(QString entryId, anEntryIdList) {
            list.append(QVariant(entryId));
        }

        map.insert("EntryIDList", QVariant(list));
        return *this;

    }

    SamuraiPhonebookEntryGetRequest* build()
    {
        request->addArguments(map);
        return request;
    }

private:
    SamuraiPhonebookEntryGetRequestFactory(QObject *aParent) : request(new SamuraiPhonebookEntryGetRequest(aParent))
    {}

    SamuraiPhonebookEntryGetRequest *request;
    QMap<QString, QVariant> map;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SAMURAIPHONEBOOKENTRYGETREQUEST_H
