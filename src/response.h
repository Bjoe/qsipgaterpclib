#ifndef QSIPGATERPCLIB_RESPONSE_H
#define QSIPGATERPCLIB_RESPONSE_H

#include <QVariant>

namespace qsipgaterpclib {

class Response
{
public:
    Response(const QVariant &aVariant);

    QVariant getFoo() const
    {
        return variant;
    }

private:
    QVariant variant;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_RESPONSE_H
