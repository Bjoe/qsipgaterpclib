#include <QObject>
#include <QtTest/QtTest>

#include "abstractrequest.h"

#include <QString>
#include <QVariant>
#include <QVariantList>
#include <QxtXmlRpcCall>
#include <QxtXmlRpcClient>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "testconfig.h"

#include "mockabstractrequest.h"

namespace tests {

class AbstractRequestTest : public QObject
{
    Q_OBJECT

private slots:
    void testCreateInstance();
};

void AbstractRequestTest::testCreateInstance()
{
    MockAbstractRequest request("foo");

    QVariantList list;
    list.append(QVariant("bar"));
    request.setArguments(list);

    QCOMPARE(request.getMethod(), QString("foo"));
    QVariantList arguments = request.getArguments();
    QCOMPARE(arguments.size(), 1);
    QVariant arg = arguments.takeFirst();
    QCOMPARE(arg.toString(), QString("bar"));
}

} // namespace tests

QTEST_GMOCK_MAIN(tests::AbstractRequestTest)
#include "moc_abstractrequesttest.cxx"
