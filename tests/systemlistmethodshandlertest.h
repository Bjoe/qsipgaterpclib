#ifndef TESTS_SYSTEMLISTMETHODSHANDLERTEST_H
#define TESTS_SYSTEMLISTMETHODSHANDLERTEST_H

#include <QObject>
#include <QtTest/QtTest>

namespace tests {

class SystemListMethodsHandlerTest : public QObject
{
    Q_OBJECT

private slots:
    void testCreateResponse();
    void testCreateResponseFailed();
};

} // namespace tests

#endif // TESTS_SYSTEMLISTMETHODSHANDLERTEST_H
