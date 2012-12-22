#ifndef QSIPGATERPCLIB_SYSTEMLISTMETHODSHANDLER_H
#define QSIPGATERPCLIB_SYSTEMLISTMETHODSHANDLER_H

#include <QObject>
#include <QVariantMap>

#include "abstracthandler.h"
#include "systemlistmethodsresponse.h"

namespace qsipgaterpclib {

class SystemListMethodsHandler : public AbstractHandler
{
    Q_OBJECT

public:
    SystemListMethodsHandler(QObject *aParent = 0);

signals:
    void ready(qsipgaterpclib::SystemListMethodsResponse aResponse);

protected:
    virtual bool createResponse(const QVariantMap &aVariant);
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SYSTEMLISTMETHODSHANDLER_H
