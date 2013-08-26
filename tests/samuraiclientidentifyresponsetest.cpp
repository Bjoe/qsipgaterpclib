#include <QObject>
#include <QtTest/QtTest>

#include <QVariant>

#include "samuraiclientidentifyresponse.h"

namespace tests {

class SamuraiClientIdentifyResponseTest : public QObject
{
    Q_OBJECT

private slots:
    void testGet();
};

void SamuraiClientIdentifyResponseTest::testGet()
{
    qsipgaterpclib::SamuraiClientIdentifyResponse
            response;
}

}

QTEST_MAIN(tests::SamuraiClientIdentifyResponseTest)
#include "moc_samuraiclientidentifyresponsetest.cxx"
