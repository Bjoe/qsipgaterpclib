#include <QObject>
#include <QtTest/QtTest>

#include <QVariant>
#include <QVariantMap>
#include <QVariantList>
#include <QDate>
#include <QTime>
#include <QDateTime>

#include "samuraiaccountstatementgetresponse.h"

namespace tests {

class SamuraiAccountStatementGetResponseTest : public QObject
{
    Q_OBJECT

private slots:
    void testGet();
};

void SamuraiAccountStatementGetResponseTest::testGet()
{
    QDate startDate(2012,7,1);
    QTime startTime(5,6,7);
    QDate endDate(2013,1,4);
    QTime endTime(7,6,5);

    double totalStart = 1.264;
    double totalExcludeStart = 0.456;
    double totalVatAmountStart = 7.56;
    double totalVatPercentStart = 0.16;

    double totalEnd = 2.456;
    double totalExcludeEnd = 4.56;
    double totalVatAmountEnd = 635.5;
    double totalVatPercentEnd = 0.61;

    QVariantMap balanceStart;
    balanceStart.insert("Currency", QVariant("EUR"));
    balanceStart.insert("TotalIncludingVat", QVariant(totalStart));
    balanceStart.insert("TotalExcludingVat", QVariant(totalExcludeStart));
    balanceStart.insert("VatAmount", QVariant(totalVatAmountStart));
    balanceStart.insert("VatPercent", QVariant(totalVatPercentStart));

    QVariantMap balanceEnd;
    balanceEnd.insert("Currency", QVariant("AUD"));
    balanceEnd.insert("TotalIncludingVat", QVariant(totalEnd));
    balanceEnd.insert("TotalExcludingVat", QVariant(totalExcludeEnd));
    balanceEnd.insert("VatAmount", QVariant(totalVatAmountEnd));
    balanceEnd.insert("VatPercent", QVariant(totalVatPercentEnd));

    double price1 = 1.52;
    double price2 = 2.54;
    double price3 = 3.45;

    double vat1 = 0.19;
    double vat2 = 0.18;
    double vat3 = 0.17;

    double priceExcludingVat = 0.52;
    double vatAmount = 12.22;

    QVariantMap priceType1;
    priceType1.insert("Currency", QVariant("GBP"));
    priceType1.insert("TotalIncludingVat", QVariant(price1));
    priceType1.insert("VatPercent", QVariant(vat1));
    priceType1.insert("TotalExcludingVat", QVariant(priceExcludingVat));
    priceType1.insert("VatAmount", QVariant(vatAmount));

    QVariantMap priceType2;
    priceType2.insert("Currency", QVariant("USD"));
    priceType2.insert("TotalIncludingVat", QVariant(price2));
    priceType2.insert("VatPercent", QVariant(vat2));

    QVariantMap priceType3;
    priceType3.insert("Currency", QVariant("JPY"));
    priceType3.insert("TotalIncludingVat", QVariant(price3));
    priceType3.insert("VatPercent", QVariant(vat3));

    QDateTime timestamp(QDate::currentDate());

    QVariantMap accountStatement1;
    accountStatement1.insert("Price", QVariant(priceType1));
    accountStatement1.insert("Quantity", QVariant(2));
    accountStatement1.insert("ServiceName", QVariant("Deutschland 01805"));
    accountStatement1.insert("TotalDuration", QVariant(123));
    accountStatement1.insert("Timestamp", QVariant(timestamp));

    QVariantMap accountStatement2;
    accountStatement2.insert("Price", QVariant(priceType2));
    accountStatement2.insert("Quantity", QVariant(11));
    accountStatement2.insert("ServiceName", QVariant("Festnetz Deutschland"));

    QVariantMap accountStatement3;
    accountStatement3.insert("Price", QVariant(priceType3));
    accountStatement3.insert("Quantity", QVariant(23));
    accountStatement3.insert("ServiceName", QVariant("Mobilfunk Deutschland"));


    QVariantList variantList;
    variantList.append(QVariant(accountStatement1));
    variantList.append(QVariant(accountStatement2));
    variantList.append(QVariant(accountStatement3));


    qsipgaterpclib::SamuraiAccountStatementGetResponse
            response(QVariant(QDateTime(startDate, startTime)),
                     QVariant(QDateTime(endDate, endTime)),
                     QVariant(variantList),
                     QVariant(balanceStart),
                     QVariant(balanceEnd));
    QCOMPARE(response.getStartPeriod(), QDateTime(startDate, startTime));
    QCOMPARE(response.getEndPeriod(), QDateTime(endDate, endTime));
    QCOMPARE(response.getStartDate(), QDate(startDate).toString());
    QCOMPARE(response.getEndDate(), QDate(endDate).toString());
    QCOMPARE(response.getBalanceStartTotalIncludingVat(), totalStart);
    QCOMPARE(response.getBalanceStartCurrency(), QString("EUR"));
    QCOMPARE(response.getBalanceStartTotalExcludingVat(), totalExcludeStart);
    QCOMPARE(response.getBalanceStartVatAmount(), totalVatAmountStart);
    QCOMPARE(response.getBalanceStartVatPercent(), totalVatPercentStart);
    QCOMPARE(response.getBalanceEndTotalIncludingVat(), totalEnd);
    QCOMPARE(response.getBalanceEndCurrency(), QString("AUD"));
    QCOMPARE(response.getBalanceEndTotalExcludingVat(), totalExcludeEnd);
    QCOMPARE(response.getBalanceEndVatAmount(), totalVatAmountEnd);
    QCOMPARE(response.getBalanceEndVatPercent(), totalVatPercentEnd);

    QList<QList<QVariant> > accountStatements = response.getAccountStatements();
    QCOMPARE(accountStatements.count(), 3);
    QList<QVariant> statement1 = accountStatements.at(0);
    QCOMPARE(statement1.at(0), QVariant(timestamp));
    QCOMPARE(statement1.at(1), QVariant(2));
    QCOMPARE(statement1.at(2).toString(), QString("Deutschland 01805"));
    QCOMPARE(statement1.at(3), QVariant(123));
    QCOMPARE(statement1.at(4), QVariant(priceExcludingVat));
    QCOMPARE(statement1.at(5), QVariant(vatAmount));
    QCOMPARE(statement1.at(6), QVariant(vat1));
    QCOMPARE(statement1.at(7), QVariant(price1));
    QCOMPARE(statement1.at(8).toString(), QString("GBP"));

    QList<QVariant> statement2 = accountStatements.at(1);
    QCOMPARE(statement2.at(0), QVariant());
    QCOMPARE(statement2.at(1), QVariant(11));
    QCOMPARE(statement2.at(2).toString(), QString("Festnetz Deutschland"));
    QCOMPARE(statement2.at(3), QVariant());
    QCOMPARE(statement2.at(4), QVariant());
    QCOMPARE(statement2.at(5), QVariant());
    QCOMPARE(statement2.at(6), QVariant(vat2));
    QCOMPARE(statement2.at(7), QVariant(price2));
    QCOMPARE(statement2.at(8).toString(), QString("USD"));

    QList<QVariant> statement3 = accountStatements.at(2);
    QCOMPARE(statement3.at(0), QVariant());
    QCOMPARE(statement3.at(1), QVariant(23));
    QCOMPARE(statement3.at(2).toString(), QString("Mobilfunk Deutschland"));
    QCOMPARE(statement3.at(3), QVariant());
    QCOMPARE(statement3.at(4), QVariant());
    QCOMPARE(statement3.at(5), QVariant());
    QCOMPARE(statement3.at(6), QVariant(vat3));
    QCOMPARE(statement3.at(7), QVariant(price3));
    QCOMPARE(statement3.at(8).toString(), QString("JPY"));
}

}

QTEST_MAIN(tests::SamuraiAccountStatementGetResponseTest)
#include "moc_samuraiaccountstatementgetresponsetest.cxx"
