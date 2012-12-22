#ifndef TESTS_ABSTRACTHANDLERTEST_H
#define TESTS_ABSTRACTHANDLERTEST_H

#include <QObject>
#include <QtTest/QtTest>

namespace tests {

class AbstractHandlerTest : public QObject
{
    Q_OBJECT

private slots:
    void testHandleResponse();
    void testHandleResponseCreateFailed();
    void testHandleResponseFailed();
    void testHandleResponseFailedWithoutMessage();
};

} // namespace tests

#endif // TESTS_ABSTRACTHANDLERTEST_H
