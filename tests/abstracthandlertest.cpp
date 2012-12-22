#include "abstracthandlertest.h"

#include "abstracthandler.h"

#include <QString>
#include <QVariant>
#include <QVariantMap>
#include <QList>
#include <QVariantList>
#include <QSignalSpy>
#include <QxtXmlRpcCall>
#include <QxtXmlRpcClient>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "testconfig.h"

#include "mockabstracthandler.h"

using ::testing::StrictMock;
using ::testing::_;
using ::testing::Return;

namespace tests {

void AbstractHandlerTest::testHandleResponse()
{
    StrictMock<MockAbstractHandler> handler;

    QVariantMap map;
    map.insert("StatusCode", QVariant(200));
    QVariant response(map);

    QSignalSpy signalSpy(&handler, SIGNAL(error(QString)));
    EXPECT_CALL(handler, createResponse(_))
            .WillOnce(Return(true));

    handler.invokeHandleResponse(response);

    QCOMPARE(signalSpy.count(), 0);
}

void AbstractHandlerTest::testHandleResponseCreateFailed()
{
    StrictMock<MockAbstractHandler> handler;

    QVariantMap map;
    map.insert("StatusCode", QVariant(200));
    QVariant response(map);

    QSignalSpy signalSpy(&handler, SIGNAL(error(QString)));
    EXPECT_CALL(handler, createResponse(_))
            .WillOnce(Return(false));

    handler.invokeHandleResponse(response);

    QCOMPARE(signalSpy.count(), 1);
    QList<QVariant> arguments = signalSpy.takeFirst();
    QCOMPARE(arguments.at(0).toString(), QString(tr("Es ist ein Fehler aufgetreten")));
}

void AbstractHandlerTest::testHandleResponseFailed()
{
    StrictMock<MockAbstractHandler> handler;

    QVariantMap map;
    map.insert("StatusCode", QVariant(404));
    map.insert("StatusString", QVariant("foobar"));
    QVariant response(map);

    QSignalSpy signalSpy(&handler, SIGNAL(error(QString)));

    handler.invokeHandleResponse(response);

    QCOMPARE(signalSpy.count(), 1);
    QList<QVariant> arguments = signalSpy.takeFirst();
    QCOMPARE(arguments.at(0).toString(), QString(tr("Es ist ein Fehler aufgetreten (404) (foobar)")));
}

void AbstractHandlerTest::testHandleResponseFailedWithoutMessage()
{
    StrictMock<MockAbstractHandler> handler;

    QVariantMap map;
    map.insert("StatusCode", QVariant(404));
    QVariant response(map);

    QSignalSpy signalSpy(&handler, SIGNAL(error(QString)));

    handler.invokeHandleResponse(response);

    QCOMPARE(signalSpy.count(), 1);
    QList<QVariant> arguments = signalSpy.takeFirst();
    QCOMPARE(arguments.at(0).toString(), QString(tr("Es ist ein Fehler aufgetreten")));
}

} // namespace tests

QTEST_GMOCK_MAIN(tests::AbstractHandlerTest)
#include "abstracthandlertest.moc"
