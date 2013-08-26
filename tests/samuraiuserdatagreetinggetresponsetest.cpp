#include <QObject>
#include <QtTest/QtTest>

#include <QString>
#include <QVariant>

#include "samuraiuserdatagreetinggetresponse.h"

namespace tests {

class SamuraiUserdataGreetingGetResponseTest : public QObject
{
    Q_OBJECT

private slots:
    void testGet();
};

void SamuraiUserdataGreetingGetResponseTest::testGet()
{
    QVariant gender("aGender");
    QVariant firstName("aFirstName");
    QVariant lastName("aLastName");

    qsipgaterpclib::SamuraiUserdataGreetingGetResponse
            response(gender, firstName, lastName);
    QCOMPARE(response.getGender(), QString("aGender"));
    QCOMPARE(response.getFirstName(), QString("aFirstName"));
    QCOMPARE(response.getLastName(), QString("aLastName"));
}

}

QTEST_MAIN(tests::SamuraiUserdataGreetingGetResponseTest)
#include "moc_samuraiuserdatagreetinggetresponsetest.cxx"
