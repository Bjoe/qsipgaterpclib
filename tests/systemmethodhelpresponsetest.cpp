#include <QObject>
#include <QtTest/QtTest>

#include "systemmethodhelpresponse.h"

namespace tests {

class SystemMethodHelpResponseTest : public QObject
{
    Q_OBJECT

private slots:
    void testGetHelp();
};

void SystemMethodHelpResponseTest::testGetHelp()
{    
    qsipgaterpclib::SystemMethodHelpResponse response("foo");
    QCOMPARE(response.getHelp(), QString("foo"));
}

}

QTEST_MAIN(tests::SystemMethodHelpResponseTest)
#include "moc_systemmethodhelpresponsetest.cxx"

