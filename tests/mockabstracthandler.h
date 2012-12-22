#ifndef TESTS_MOCKABSTRACTHANDLER_H
#define TESTS_MOCKABSTRACTHANDLER_H

#include <QObject>
#include <QString>
#include <QVariant>
#include <QVariantMap>

#include <gmock/gmock.h>

#include "abstracthandler.h"

namespace tests
{

class MockAbstractHandler : public qsipgaterpclib::AbstractHandler
{
public:
    MockAbstractHandler(QObject *aParent = 0) : AbstractHandler(aParent)
    {}

    void invokeHandleResponse(const QVariant &aVariant)
    {
        AbstractHandler::handleResponse(aVariant);
    }

    MOCK_METHOD1(handleResponse, void(const QVariant &aVariant));
    MOCK_METHOD1(createResponse, bool(const QVariantMap &aVariant));
};

}

#endif // TESTS_MOCKABSTRACTHANDLER_H
