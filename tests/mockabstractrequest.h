#ifndef MOCKABSTRACTREQUEST_H
#define MOCKABSTRACTREQUEST_H

#include <QObject>
#include <QString>
#include <QVariant>
#include <QVariantMap>

#include <gmock/gmock.h>

#include "abstractrequest.h"

#include "abstracthandler.h"

namespace tests
{

class MockAbstractRequest : public qsipgaterpclib::AbstractRequest
{
public:
    MockAbstractRequest(const QString &aMethod, QObject *aParent = 0) : AbstractRequest(aMethod, aParent)
    {}

    MOCK_METHOD0(getHandler, qsipgaterpclib::AbstractHandler*());
};

}

#endif // MOCKABSTRACTREQUEST_H
