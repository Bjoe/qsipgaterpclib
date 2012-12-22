#ifndef TESTS_SYSTEMLISTMETHODSREQUESTTEST_H
#define TESTS_SYSTEMLISTMETHODSREQUESTTEST_H

#include <QObject>
#include <QtTest/QtTest>

namespace tests {

class SystemListMethodsRequestTest : public QObject
{
    Q_OBJECT

private slots:
    void testCreateInstance();
    void testGetHandler();
};

} // namespace tests

#endif // TESTS_SYSTEMLISTMETHODSREQUESTTEST_H
