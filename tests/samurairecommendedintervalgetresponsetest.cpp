#include <QObject>
#include <QtTest/QtTest>

#include <QList>
#include <QVariant>
#include <QVariantList>
#include <QVariantMap>

#include "samurairecommendedintervalgetresponse.h"

namespace tests {

class SamuraiRecommendedIntervalGetResponseTest : public QObject
{
    Q_OBJECT

private slots:
    void testGet();
};

void SamuraiRecommendedIntervalGetResponseTest::testGet()
{
    QVariantMap map;
    map.insert("MethodName", QVariant("aMethodName"));
    map.insert("RecommendedInterval", QVariant(23));

    QVariantList list;
    list.append(QVariant(map));
    QVariant variant(list);
    qsipgaterpclib::SamuraiRecommendedIntervalGetResponse
            response(variant);
    QList<QList<QVariant> > intervalList = response.getIntervalList();
    QCOMPARE(intervalList.count(), 1);
    QList<QVariant> line = intervalList.at(0);
    QCOMPARE(line.at(0), QVariant("aMethodName"));
    QCOMPARE(line.at(1), QVariant(23));
}

}

QTEST_MAIN(tests::SamuraiRecommendedIntervalGetResponseTest)
#include "moc_samurairecommendedintervalgetresponsetest.cxx"
