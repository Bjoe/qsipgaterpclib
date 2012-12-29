#include <QObject>
#include <QtTest/QtTest>

#include "systemmethodsignatureresponse.h"

namespace tests {

class SystemMethodSignatureResponseTest : public QObject
{
    Q_OBJECT

private slots:
    void testGetHelp();
};

void SystemMethodSignatureResponseTest::testGetHelp()
{
    qsipgaterpclib::SystemMethodSignatureResponse response("foo");
    QCOMPARE(response.getSignature(), QString("foo"));
}

}

QTEST_MAIN(tests::SystemMethodSignatureResponseTest)
#include "moc_systemmethodsignatureresponsetest.cxx"
