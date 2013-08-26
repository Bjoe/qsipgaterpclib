#include <QObject>
#include <QtTest/QtTest>

#include "samuraiumsummarygetrequest.h"

#include <QString>
#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QList>
#include <QMap>
#include <QVariantList>

#include "samuraiumsummarygetresponse.h"

namespace tests {

class SamuraiUmSummaryGetRequestTest : public QObject
{
    Q_OBJECT

private slots:
    void testCreateInstance();
    void testCreateResponse();
    void testCreateResponseFailed();
};

void SamuraiUmSummaryGetRequestTest::testCreateInstance()
{
    QList<QString> labelNamesList;
    labelNamesList.append("aLableName");

    QList<QString> tosList;
    tosList.append("aTos");

    QList<QString> localUriList;
    localUriList.append("aLocalUri");

    qsipgaterpclib::SamuraiUmSummaryGetRequest *request =
            qsipgaterpclib::SamuraiUmSummaryGetRequestFactory::createInstance(this)
            .withLabelNames(labelNamesList)
            .withLocalUris(localUriList)
            .withTos(tosList)
            .build();
    QCOMPARE(request->getMethod(), QString("samurai.UmSummaryGet"));
    QVariantList list = request->getArguments();
    QMap<QString, QVariant> map = list.at(0).toMap();
    QVariantList list1 = map.value("LabelName").toList();
    QCOMPARE(list1.at(0), QVariant("aLableName"));
    QVariantList list2 = map.value("TOS").toList();
    QCOMPARE(list2.at(0), QVariant("aTos"));
    QVariantList list3 = map.value("LocalUriList").toList();
    QCOMPARE(list3.at(0), QVariant("aLocalUri"));
}

void SamuraiUmSummaryGetRequestTest::testCreateResponse()
{
    qsipgaterpclib::SamuraiUmSummaryGetRequest *request =
            qsipgaterpclib::SamuraiUmSummaryGetRequestFactory::createInstance(this)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SamuraiUmSummaryGetResponse)));

    QVariant dummy(QString("dummy"));
    QVariantMap variantMap;
    variantMap.insert("UmSummary", dummy);
    QVERIFY(request->createResponse(variantMap) == true);

    QCOMPARE(signalSpy.count(), 1);
    QList<QVariant> arguments = signalSpy.takeFirst();
    QCOMPARE(arguments.count(), 1);
}

void SamuraiUmSummaryGetRequestTest::testCreateResponseFailed()
{
    qsipgaterpclib::SamuraiUmSummaryGetRequest *request =
            qsipgaterpclib::SamuraiUmSummaryGetRequestFactory::createInstance(this)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SamuraiUmSummaryGetResponse)));

    QVariantMap variantMap;
    QVERIFY(request->createResponse(variantMap) == false);

    QCOMPARE(signalSpy.count(), 0);
}

}

QTEST_MAIN(tests::SamuraiUmSummaryGetRequestTest)
#include "moc_samuraiumsummarygetrequesttest.cxx"

