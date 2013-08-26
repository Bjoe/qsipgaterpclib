#include <QObject>
#include <QtTest/QtTest>

#include <QString>
#include <QVariant>

#include "samuraisessionstatusgetresponse.h"

namespace tests {

class SamuraiSessionStatusGetResponseTest : public QObject
{
    Q_OBJECT

private slots:
    void testGet();
};

void SamuraiSessionStatusGetResponseTest::testGet()
{
    QVariant variant("aStatus");
    qsipgaterpclib::SamuraiSessionStatusGetResponse
            response(variant);
    QCOMPARE(response.getStatus(), QString("aStatus"));
}

}

QTEST_MAIN(tests::SamuraiSessionStatusGetResponseTest)
#include "moc_samuraisessionstatusgetresponsetest.cxx"
