#ifndef TESTS_RPCCLIENTFACTORYTEST_H
#define TESTS_RPCCLIENTFACTORYTEST_H

#include <QObject>
#include <QtTest/QtTest>

namespace tests {

class RpcClientFactoryTest : public QObject
{
    Q_OBJECT

private slots:
    void testCreateInstance();
};

} // namespace tests

#endif // TESTS_RPCCLIENTFACTORYTEST_H
