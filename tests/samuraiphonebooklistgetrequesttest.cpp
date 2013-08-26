#include <QObject>
#include <QtTest/QtTest>

#include "samuraiphonebooklistgetrequest.h"

#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QMap>
#include <QVariantList>

#include "samuraiphonebooklistgetresponse.h"

namespace tests {

class SamuraiPhonebookListGetRequestTest : public QObject
{
    Q_OBJECT

private slots:
    void testCreateInstance();
    void testCreateResponse();
    void testCreateResponseFailed();
};

void SamuraiPhonebookListGetRequestTest::testCreateInstance()
{
    qsipgaterpclib::SamuraiPhonebookListGetRequest *request =
            qsipgaterpclib::SamuraiPhonebookListGetRequestFactory::createInstance(this)
            .build();
    QCOMPARE(request->getMethod(), QString("samurai.PhonebookListGet"));
    QCOMPARE(request->getArguments(), QVariantList());
}

void SamuraiPhonebookListGetRequestTest::testCreateResponse()
{
    qsipgaterpclib::SamuraiPhonebookListGetRequest *request =
            qsipgaterpclib::SamuraiPhonebookListGetRequestFactory::createInstance(this)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SamuraiPhonebookListGetResponse)));

    QVariant dummy(QString("dummy"));
    QVariantMap variantMap;
    variantMap.insert("PhonebookList", dummy);
    QVERIFY(request->createResponse(variantMap) == true);

    QCOMPARE(signalSpy.count(), 1);
    QList<QVariant> arguments = signalSpy.takeFirst();
    QCOMPARE(arguments.count(), 1);
}

void SamuraiPhonebookListGetRequestTest::testCreateResponseFailed()
{
    qsipgaterpclib::SamuraiPhonebookListGetRequest *request =
            qsipgaterpclib::SamuraiPhonebookListGetRequestFactory::createInstance(this)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SamuraiPhonebookListGetResponse)));

    QVariantMap variantMap;
    QVERIFY(request->createResponse(variantMap) == false);

    QCOMPARE(signalSpy.count(), 0);
}

}

QTEST_MAIN(tests::SamuraiPhonebookListGetRequestTest)
#include "moc_samuraiphonebooklistgetrequesttest.cxx"

