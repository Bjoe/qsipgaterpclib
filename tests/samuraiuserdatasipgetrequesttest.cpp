#include <QObject>
#include <QtTest/QtTest>

#include "samuraiuserdatasipgetrequest.h"

#include <QString>
#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QMap>
#include <QList>
#include <QVariantList>

#include "samuraiuserdatasipgetresponse.h"

namespace tests {

class SamuraiUserdataSipGetRequestTest : public QObject
{
    Q_OBJECT

private slots:
    void testCreateInstance();
    void testCreateResponse();
    void testCreateResponseFailed();
};

void SamuraiUserdataSipGetRequestTest::testCreateInstance()
{
    QList<QString> uriList;
    uriList.append("aUri");

    qsipgaterpclib::SamuraiUserdataSipGetRequest *request =
            qsipgaterpclib::SamuraiUserdataSipGetRequestFactory::createInstance(this)
            .withLocalUris(uriList)
            .build();
    QCOMPARE(request->getMethod(), QString("samurai.UserdataSipGet"));
    QVariantList list = request->getArguments();
    QMap<QString, QVariant> map = list.at(0).toMap();
    QVariantList variantList = map.value("LocalUriList").toList();
    QCOMPARE(variantList.at(0), QVariant("aUri"));
}

void SamuraiUserdataSipGetRequestTest::testCreateResponse()
{
    qsipgaterpclib::SamuraiUserdataSipGetRequest *request =
            qsipgaterpclib::SamuraiUserdataSipGetRequestFactory::createInstance(this)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SamuraiUserdataSipGetResponse)));

    QVariant dummy(QString("dummy"));
    QVariantMap variantMap;
    variantMap.insert("SipDataList", dummy);
    QVERIFY(request->createResponse(variantMap) == true);

    QCOMPARE(signalSpy.count(), 1);
    QList<QVariant> arguments = signalSpy.takeFirst();
    QCOMPARE(arguments.count(), 1);
}

void SamuraiUserdataSipGetRequestTest::testCreateResponseFailed()
{
    qsipgaterpclib::SamuraiUserdataSipGetRequest *request =
            qsipgaterpclib::SamuraiUserdataSipGetRequestFactory::createInstance(this)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SamuraiUserdataSipGetResponse)));

    QVariantMap variantMap;
    QVERIFY(request->createResponse(variantMap) == false);

    QCOMPARE(signalSpy.count(), 0);
}

}

QTEST_MAIN(tests::SamuraiUserdataSipGetRequestTest)
#include "moc_samuraiuserdatasipgetrequesttest.cxx"

