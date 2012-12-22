#include "systemlistmethodsresponsetest.h"

#include "systemlistmethodsresponse.h"

#include <QString>
#include <QVariant>
#include <QList>
#include <QVariantList>


namespace tests {

void SystemListMethodsResponseTest::testAt()
{
    QVariantList variantList;
    variantList.append(QVariant(QString("foo")));
    variantList.append(QVariant(QString("bar")));
    qsipgaterpclib::SystemListMethodsResponse response(variantList);

    QCOMPARE(response.at(1), QString("bar"));
}

void SystemListMethodsResponseTest::testCount()
{
    QVariantList variantList;
    variantList.append(QVariant(QString("foo")));
    variantList.append(QVariant(QString("bar")));
    qsipgaterpclib::SystemListMethodsResponse response(variantList);

    QCOMPARE(response.count(), 2);
    QCOMPARE(response.length(), 2);
}

void SystemListMethodsResponseTest::testGetList()
{
    QVariantList variantList;
    variantList.append(QVariant(QString("foo")));
    variantList.append(QVariant(QString("bar")));
    qsipgaterpclib::SystemListMethodsResponse response(variantList);

    QList<QString> list = response.getList();

    QCOMPARE(list.at(0), QString("foo"));
    QCOMPARE(list.at(1), QString("bar"));
}

} // namespace tests

QTEST_MAIN(tests::SystemListMethodsResponseTest)
#include "systemlistmethodsresponsetest.moc"
