#ifndef QSIPGATERPCLIB_SYSTEMMETHODHELPHANDLER_H
#define QSIPGATERPCLIB_SYSTEMMETHODHELPHANDLER_H

#include <QObject>
#include <QVariantMap>

#include "abstracthandler.h"
#include "systemmethodhelpresponse.h"

namespace qsipgaterpclib {

class SystemMethodHelpHandler : public AbstractHandler
{
    Q_OBJECT

public:
    explicit SystemMethodHelpHandler(QObject *parent = 0);
    
signals:
    void ready(qsipgaterpclib::SystemMethodHelpResponse aResponse);
    
protected:
    virtual bool createResponse(const QVariantMap &aVariant);
    
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SYSTEMMETHODHELPHANDLER_H
