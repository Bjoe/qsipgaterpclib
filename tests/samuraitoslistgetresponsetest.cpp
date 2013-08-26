#include <QObject>
#include <QtTest/QtTest>

#include <QVariant>

#include "samuraitoslistgetresponse.h"

namespace tests {

class SamuraiTosListGetResponseTest : public QObject
{
    Q_OBJECT

private slots:
    void testGet();
};

void SamuraiTosListGetResponseTest::testGet()
{
    QVariantList variantList;
    variantList.append("aTos");

    QVariant variant(variantList);
    qsipgaterpclib::SamuraiTosListGetResponse
            response(variant);
    QList<QString> list = response.getTosList();

    QCOMPARE(list.at(0), QString("aTos"));
}

}

QTEST_MAIN(tests::SamuraiTosListGetResponseTest)
#include "moc_samuraitoslistgetresponsetest.cxx"
