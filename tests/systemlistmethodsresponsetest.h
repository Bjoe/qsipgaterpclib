#ifndef TESTS_SYSTEMLISTMETHODSRESPONSETEST_H
#define TESTS_SYSTEMLISTMETHODSRESPONSETEST_H

#include <QObject>
#include <QtTest/QtTest>

namespace tests {

class SystemListMethodsResponseTest : public QObject
{
    Q_OBJECT
private slots:
    void testAt();
    void testCount();
    void testGetList();
};

} // namespace tests

#endif // TESTS_SYSTEMLISTMETHODSRESPONSETEST_H
