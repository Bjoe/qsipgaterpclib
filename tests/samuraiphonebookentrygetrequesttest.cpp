#include <QObject>
#include <QtTest/QtTest>

#include "samuraiphonebookentrygetrequest.h"

#include <QString>
#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QMap>
#include <QList>
#include <QVariantList>

#include "samuraiphonebookentrygetresponse.h"

namespace tests {

class SamuraiPhonebookEntryGetRequestTest : public QObject
{
    Q_OBJECT

private slots:
    void testCreateInstance();
    void testCreateResponse();
    void testCreateResponseFailed();
};

void SamuraiPhonebookEntryGetRequestTest::testCreateInstance()
{
    QList<QString> entryIdList;
    entryIdList.append(QString("anEntryId"));

    qsipgaterpclib::SamuraiPhonebookEntryGetRequest *request =
            qsipgaterpclib::SamuraiPhonebookEntryGetRequestFactory::createInstance(this)
            .withEntryIdList(entryIdList)
            .build();
    QCOMPARE(request->getMethod(), QString("samurai.PhonebookEntryGet"));
    QVariantList list = request->getArguments();
    QMap<QString, QVariant> map = list.at(0).toMap();
    QVariantList entrylist = map.value("EntryIDList").toList();
    QCOMPARE(entrylist.at(0), QVariant("anEntryId"));
}

void SamuraiPhonebookEntryGetRequestTest::testCreateResponse()
{
    qsipgaterpclib::SamuraiPhonebookEntryGetRequest *request =
            qsipgaterpclib::SamuraiPhonebookEntryGetRequestFactory::createInstance(this)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SamuraiPhonebookEntryGetResponse)));

    QVariant dummy(QString("dummy"));
    QVariantMap variantMap;
    variantMap.insert("EntryList", dummy);
    QVERIFY(request->createResponse(variantMap) == true);

    QCOMPARE(signalSpy.count(), 1);
    QList<QVariant> arguments = signalSpy.takeFirst();
    QCOMPARE(arguments.count(), 1);
}

void SamuraiPhonebookEntryGetRequestTest::testCreateResponseFailed()
{
    qsipgaterpclib::SamuraiPhonebookEntryGetRequest *request =
            qsipgaterpclib::SamuraiPhonebookEntryGetRequestFactory::createInstance(this)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SamuraiPhonebookEntryGetResponse)));

    QVariantMap variantMap;
    QVERIFY(request->createResponse(variantMap) == false);

    QCOMPARE(signalSpy.count(), 0);
}

}

QTEST_MAIN(tests::SamuraiPhonebookEntryGetRequestTest)
#include "moc_samuraiphonebookentrygetrequesttest.cxx"

