#include <QObject>
#include <QtTest/QtTest>

#include <QVariant>

#include "response.h"

namespace tests {

class ResponseTest : public QObject
{
    Q_OBJECT

private slots:
    void testGet();
};

void ResponseTest::testGet()
{
    QVariant foo("foo");
    qsipgaterpclib::Response
            response(foo);
    QCOMPARE(response.getFoo(), QVariant("foo"));
}

}

QTEST_MAIN(tests::ResponseTest)
#include "moc_responsetest.cxx"
