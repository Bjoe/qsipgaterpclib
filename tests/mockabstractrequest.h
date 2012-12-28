#ifndef MOCKABSTRACTREQUEST_H
#define MOCKABSTRACTREQUEST_H

#include <QObject>
#include <QString>
#include <QVariant>
#include <QVariantMap>

#include <gmock/gmock.h>

#include "abstractrequest.h"

namespace tests
{

class MockAbstractRequest : public qsipgaterpclib::AbstractRequest
{
public:
    MockAbstractRequest(const QString &aMethod, QObject *aParent = 0) : AbstractRequest(aMethod, aParent)
    {}

    void invokeHandleResponse(const QVariant &aVariant)
    {
        AbstractRequest::handleResponse(aVariant);
    }

    MOCK_METHOD1(handleResponse, void(const QVariant &aVariant));
    MOCK_METHOD1(createResponse, bool(const QVariantMap &aVariant));
};

}

#endif // MOCKABSTRACTREQUEST_H
