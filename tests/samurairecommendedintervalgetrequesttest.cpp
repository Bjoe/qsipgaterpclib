#include <QObject>
#include <QtTest/QtTest>

#include "samurairecommendedintervalgetrequest.h"

#include <QString>
#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QList>
#include <QMap>
#include <QVariantList>

#include "samurairecommendedintervalgetresponse.h"

namespace tests {

class SamuraiRecommendedIntervalGetRequestTest : public QObject
{
    Q_OBJECT

private slots:
    void testCreateInstance();
    void testCreateResponse();
    void testCreateResponseFailed();
};

void SamuraiRecommendedIntervalGetRequestTest::testCreateInstance()
{
    QList<QString> methodList;
    methodList.append("foo");

    qsipgaterpclib::SamuraiRecommendedIntervalGetRequest *request =
            qsipgaterpclib::SamuraiRecommendedIntervalGetRequestFactory::createInstance(this)
            .withMethodList(methodList)
            .build();
    QCOMPARE(request->getMethod(), QString("samurai.RecommendedIntervalGet"));
    QVariantList list = request->getArguments();
    QMap<QString, QVariant> map = list.at(0).toMap();
    QVariantList mList = map.value("MethodList").toList();
    QCOMPARE(mList.at(0), QVariant("foo"));
}

void SamuraiRecommendedIntervalGetRequestTest::testCreateResponse()
{
    qsipgaterpclib::SamuraiRecommendedIntervalGetRequest *request =
            qsipgaterpclib::SamuraiRecommendedIntervalGetRequestFactory::createInstance(this)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SamuraiRecommendedIntervalGetResponse)));

    QVariant dummy(QString("dummy"));
    QVariantMap variantMap;
    variantMap.insert("IntervalList", dummy);
    QVERIFY(request->createResponse(variantMap) == true);

    QCOMPARE(signalSpy.count(), 1);
    QList<QVariant> arguments = signalSpy.takeFirst();
    QCOMPARE(arguments.count(), 1);
}

void SamuraiRecommendedIntervalGetRequestTest::testCreateResponseFailed()
{
    qsipgaterpclib::SamuraiRecommendedIntervalGetRequest *request =
            qsipgaterpclib::SamuraiRecommendedIntervalGetRequestFactory::createInstance(this)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::SamuraiRecommendedIntervalGetResponse)));

    QVariantMap variantMap;
    QVERIFY(request->createResponse(variantMap) == false);

    QCOMPARE(signalSpy.count(), 0);
}

}

QTEST_MAIN(tests::SamuraiRecommendedIntervalGetRequestTest)
#include "moc_samurairecommendedintervalgetrequesttest.cxx"

