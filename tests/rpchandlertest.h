#ifndef TESTS_RPCHANDLERTEST_H
#define TESTS_RPCHANDLERTEST_H

#include <QObject>
#include <QtTest/QtTest>

namespace tests {

class RpcHandlerTest : public QObject
{
    Q_OBJECT

private slots:
    void testSendRequest();
    void testRpcError_data();
    void testRpcError();
    void testRpcSslError_data();
    void testRpcSslError();
};

} // namespace tests

#endif // TESTS_RPCHANDLERTEST_H
