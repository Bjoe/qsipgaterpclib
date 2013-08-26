#include "request.h"

namespace qsipgaterpclib {

Request::Request(QObject *aParent) : AbstractRequest("foo.foo", aParent)
{
}

bool Request::createResponse(const QVariantMap &aVariant)
{
    bool result = false;

    QVariant foo = aVariant.value("Foo");

    if(foo.isValid()) {
        Response response(foo);
        emit ready(response);
        result = true;
    }
    return result;
}

} // namespace qsipgaterpclib
