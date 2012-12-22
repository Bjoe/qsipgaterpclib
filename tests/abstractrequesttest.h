#ifndef TESTS_ABSTRACTREQUESTTEST_H
#define TESTS_ABSTRACTREQUESTTEST_H

#include <QObject>
#include <QtTest/QtTest>

namespace tests
{

class AbstractRequestTest : public QObject
{
    Q_OBJECT

private slots:
    void testCreateInstance();
};

} // namespace tests

#endif // TESTS_ABSTRACTREQUESTTEST_H
