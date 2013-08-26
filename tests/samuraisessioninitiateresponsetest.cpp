#include <QObject>
#include <QtTest/QtTest>

#include <QString>
#include <QVariant>

#include "samuraisessioninitiateresponse.h"

namespace tests {

class SamuraiSessionInitiateResponseTest : public QObject
{
    Q_OBJECT

private slots:
    void testGet();
};

void SamuraiSessionInitiateResponseTest::testGet()
{
    QVariant id("sessionId");
    qsipgaterpclib::SamuraiSessionInitiateResponse
            response(id);
    QCOMPARE(response.getSessionId(), QString("sessionId"));
}

}

QTEST_MAIN(tests::SamuraiSessionInitiateResponseTest)
#include "moc_samuraisessioninitiateresponsetest.cxx"
