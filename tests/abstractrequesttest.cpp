#include <QObject>
#include <QtTest/QtTest>

#include "abstractrequest.h"

#include <QString>
#include <QVariant>
#include <QVariantMap>
#include <QList>
#include <QVariantList>
#include <QxtXmlRpcCall>
#include <QxtXmlRpcClient>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "testconfig.h"

#include "mockabstractrequest.h"

using ::testing::StrictMock;
using ::testing::_;
using ::testing::Return;

namespace tests {

class AbstractRequestTest : public QObject
{
    Q_OBJECT

private slots:
    void testCreateInstance();
    void testHandleResponse();
    void testHandleResponseCreateFailed();
    void testHandleResponseFailed();
    void testHandleResponseFailed2();
    void testHandleResponseFailedWithoutMessage();
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

void AbstractRequestTest::testHandleResponse()
{
    StrictMock<MockAbstractRequest> request("foo");

    QVariantMap map;
    map.insert("StatusCode", QVariant(200));
    QVariant response(map);

    QSignalSpy signalSpy(&request, SIGNAL(error(QString)));
    EXPECT_CALL(request, createResponse(_))
            .WillOnce(Return(true));

    request.invokeHandleResponse(response);

    QCOMPARE(signalSpy.count(), 0);
}

void AbstractRequestTest::testHandleResponseCreateFailed()
{
    StrictMock<MockAbstractRequest> request("foo");

    QVariantMap map;
    map.insert("StatusCode", QVariant(200));
    QVariant response(map);

    QSignalSpy signalSpy(&request, SIGNAL(error(QString)));
    EXPECT_CALL(request, createResponse(_))
            .WillOnce(Return(false));

    request.invokeHandleResponse(response);

    QCOMPARE(signalSpy.count(), 1);
    QList<QVariant> arguments = signalSpy.takeFirst();
    QCOMPARE(arguments.at(0).toString(), QString(tr("Es ist ein Fehler beim erzeugen der Antwort aufgetreten")));
}

void AbstractRequestTest::testHandleResponseFailed()
{
    StrictMock<MockAbstractRequest> request("foo");

    QVariantMap map;
    map.insert("StatusCode", QVariant(404));
    map.insert("StatusString", QVariant("foobar"));
    QVariant response(map);

    QSignalSpy signalSpy(&request, SIGNAL(error(QString)));

    request.invokeHandleResponse(response);

    QCOMPARE(signalSpy.count(), 1);
    QList<QVariant> arguments = signalSpy.takeFirst();
    QCOMPARE(arguments.at(0).toString(), QString(tr("Es ist ein Fehler aufgetreten (404) (foobar)")));
}

void AbstractRequestTest::testHandleResponseFailed2()
{
    StrictMock<MockAbstractRequest> request("foo");

    QVariantMap map;
    map.insert("faultCode", QVariant(404));
    map.insert("faultString", QVariant("foobar"));
    QVariant response(map);

    QSignalSpy signalSpy(&request, SIGNAL(error(QString)));

    request.invokeHandleResponse(response);

    QCOMPARE(signalSpy.count(), 1);
    QList<QVariant> arguments = signalSpy.takeFirst();
    QCOMPARE(arguments.at(0).toString(), QString(tr("Es ist ein Fehler aufgetreten (404) (foobar)")));
}

void AbstractRequestTest::testHandleResponseFailedWithoutMessage()
{
    StrictMock<MockAbstractRequest> request("foo");

    QVariantMap map;
    map.insert("StatusCode", QVariant(404));
    QVariant response(map);

    QSignalSpy signalSpy(&request, SIGNAL(error(QString)));

    request.invokeHandleResponse(response);

    QCOMPARE(signalSpy.count(), 1);
    QList<QVariant> arguments = signalSpy.takeFirst();
    QCOMPARE(arguments.at(0).toString(), QString(tr("Es ist ein allgemeiner RPC Fehler aufgetreten")));
}


} // namespace tests

QTEST_GMOCK_MAIN(tests::AbstractRequestTest)
#include "moc_abstractrequesttest.cxx"
