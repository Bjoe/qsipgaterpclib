#include <QObject>
#include <QtTest/QtTest>

#include <QString>
#include <QDateTime>
#include <QVariant>
#include <QVariantMap>

#include "samuraibalancegetresponse.h"

#include <QDebug>

namespace tests {

class SamuraiBalanceGetResponseTest : public QObject
{
    Q_OBJECT

private slots:
    void testGet();
};

void SamuraiBalanceGetResponseTest::testGet()
{
    QDateTime balanceTime(QDate::currentDate());

    double price1 = 0.123;
    double vat1 = 0.16;
    double vatAmount = 23.23;
    double priceExcludingVat = 45.66;

    QVariantMap priceType1;
    priceType1.insert("Currency", QVariant("EUR"));
    priceType1.insert("TotalIncludingVat", QVariant(price1));
    priceType1.insert("VatPercent", QVariant(vat1));
    priceType1.insert("TotalExcludingVat", QVariant(priceExcludingVat));
    priceType1.insert("VatAmount", QVariant(vatAmount));

    QVariant variantTime(balanceTime);
    QVariant variantPriceType(priceType1);
    qsipgaterpclib::SamuraiBalanceGetResponse response(variantTime, variantPriceType);

    QCOMPARE(response.getBalanceTime(), balanceTime);
    QCOMPARE(response.getCurrency(), QString("EUR"));
    QCOMPARE(response.getTotalExcludingVat(), QVariant(priceExcludingVat));
    QCOMPARE(response.getTotalIncludingVat(), QVariant(price1));
    QCOMPARE(response.getVatAmount(), QVariant(vatAmount));
    QCOMPARE(response.getVatPercent(), QVariant(vat1));
}

}

QTEST_MAIN(tests::SamuraiBalanceGetResponseTest)
#include "moc_samuraibalancegetresponsetest.cxx"
