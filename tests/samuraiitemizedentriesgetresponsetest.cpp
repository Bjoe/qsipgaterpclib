#include <QObject>
#include <QtTest/QtTest>

#include <QDateTime>
#include <QVariant>
#include <QVariantMap>
#include <QVariantList>

#include "samuraiitemizedentriesgetresponse.h"

namespace tests {

class SamuraiItemizedEntriesGetResponseTest : public QObject
{
    Q_OBJECT

private slots:
    void testGet();
};

void SamuraiItemizedEntriesGetResponseTest::testGet()
{
    double totalExcludingVat1 = 0.26;
    double totalIncludingVat1 = 3.545;
    double vatAmount1 = 0.5665;
    double vatPercent1 = 1.546;

    double totalExcludingVat2 = 0.465;
    double totalIncludingVat2 = 3.5;
    double vatAmount2 = 0.999;
    double vatPercent2 = 5.546;

    double totalExcludingVat3 = 60.26;
    double totalIncludingVat3 = 43.545;
    double vatAmount3 = 40.5665;
    double vatPercent3 = 41.546;

    QVariantMap price;
    price.insert("TotalExcludingVat", QVariant(totalExcludingVat1));
    price.insert("TotalIncludingVat", QVariant(totalIncludingVat1));
    price.insert("VatAmount", QVariant(vatAmount1));
    price.insert("VatPercent", QVariant(vatPercent1));
    price.insert("Currency", QString("EUR"));

    QVariantMap setupFee;
    setupFee.insert("TotalExcludingVat", QVariant(totalExcludingVat2));
    setupFee.insert("TotalIncludingVat", QVariant(totalIncludingVat2));
    setupFee.insert("VatAmount", QVariant(vatAmount2));
    setupFee.insert("VatPercent", QVariant(vatPercent2));
    setupFee.insert("Currency", QString("AUD"));

    QVariantMap pricePerUnit;
    pricePerUnit.insert("TotalExcludingVat", QVariant(totalExcludingVat3));
    pricePerUnit.insert("TotalIncludingVat", QVariant(totalIncludingVat3));
    pricePerUnit.insert("VatAmount", QVariant(vatAmount3));
    pricePerUnit.insert("VatPercent", QVariant(vatPercent3));
    pricePerUnit.insert("Currency", QString("USD"));

    QDateTime timestamp(QDate::currentDate());

    QVariantMap map;
    map.insert("Timestamp", QVariant(timestamp));
    map.insert("SourceUri", QVariant("uriFoo"));
    map.insert("TargetUri", QVariant("targetFoo"));
    map.insert("Price", QVariant(price));
    map.insert("SetupFee", QVariant(setupFee));
    map.insert("PricePerUnit", QVariant(pricePerUnit));
    map.insert("TicksA", QVariant(23));
    map.insert("TicksB", QVariant(42));
    map.insert("UnitsCharged", QVariant(65));
    map.insert("TariffName", QVariant("Tariff"));
    map.insert("Duration", QVariant(222));
    map.insert("TOS", QVariant("aTOS"));

    QVariantList list;
    list.append(QVariant(map));

    QDateTime periodStart(QDate(2013,1,1));
    QDateTime periodEnd(QDate(2013,1,5));

    QVariant entries(list);
    QVariant start(periodStart);
    QVariant end(periodEnd);

    qsipgaterpclib::SamuraiItemizedEntriesGetResponse
            response(start, end, entries);
    QCOMPARE(response.getPeriodStart(), periodStart);
    QCOMPARE(response.getPeriodEnd(), periodEnd);

    QList<QList<QVariant> > entrieList = response.getItemizedEntries();
    QCOMPARE(entrieList.count(), 1);
    QList<QVariant> line = entrieList.at(0);
    QCOMPARE(line.at(0), QVariant(timestamp));
    QCOMPARE(line.at(1), QVariant("uriFoo"));
    QCOMPARE(line.at(2), QVariant("targetFoo"));
    QCOMPARE(line.at(3), QVariant(totalExcludingVat1));
    QCOMPARE(line.at(4), QVariant(totalIncludingVat1));
    QCOMPARE(line.at(5), QVariant(vatAmount1));
    QCOMPARE(line.at(6), QVariant(vatPercent1));
    QCOMPARE(line.at(7), QVariant("EUR"));
    QCOMPARE(line.at(8), QVariant(totalExcludingVat2));
    QCOMPARE(line.at(9), QVariant(totalIncludingVat2));
    QCOMPARE(line.at(10), QVariant(vatAmount2));
    QCOMPARE(line.at(11), QVariant(vatPercent2));
    QCOMPARE(line.at(12), QVariant("AUD"));
    QCOMPARE(line.at(13), QVariant(totalExcludingVat3));
    QCOMPARE(line.at(14), QVariant(totalIncludingVat3));
    QCOMPARE(line.at(15), QVariant(vatAmount3));
    QCOMPARE(line.at(16), QVariant(vatPercent3));
    QCOMPARE(line.at(17), QVariant("USD"));
    QCOMPARE(line.at(18), QVariant(23));
    QCOMPARE(line.at(19), QVariant(42));
    QCOMPARE(line.at(20), QVariant(65));
    QCOMPARE(line.at(21), QVariant("Tariff"));
    QCOMPARE(line.at(22), QVariant(222));
    QCOMPARE(line.at(23), QVariant("aTOS"));
}

}

QTEST_MAIN(tests::SamuraiItemizedEntriesGetResponseTest)
#include "moc_samuraiitemizedentriesgetresponsetest.cxx"
