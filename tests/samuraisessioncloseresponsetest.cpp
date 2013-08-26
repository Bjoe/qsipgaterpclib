#include <QObject>
#include <QtTest/QtTest>

#include <QVariant>

#include "samuraisessioncloseresponse.h"

namespace tests {

class SamuraiSessionCloseResponseTest : public QObject
{
    Q_OBJECT

private slots:
    void testGet();
};

void SamuraiSessionCloseResponseTest::testGet()
{
    qsipgaterpclib::SamuraiSessionCloseResponse
            response;
}

}

QTEST_MAIN(tests::SamuraiSessionCloseResponseTest)
#include "moc_samuraisessioncloseresponsetest.cxx"
