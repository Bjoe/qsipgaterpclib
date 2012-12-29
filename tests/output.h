#ifndef TESTS_OUTPUT_H
#define TESTS_OUTPUT_H

#include <QObject>
#include "systemlistmethodsresponse.h"
#include "systemmethodhelpresponse.h"
#include "systemmethodsignatureresponse.h"
#include "systemserverinforesponse.h"

namespace tests {

class Output : public QObject
{
    Q_OBJECT
public:
    explicit Output(QObject *parent = 0);
    
public slots:
    void doDisplayListMethodsResponse(qsipgaterpclib::SystemListMethodsResponse aResponse);
    void doDisplayMethodHelpResponse(qsipgaterpclib::SystemMethodHelpResponse aResponse);
    void doDisplayMethodSignatureResponse(qsipgaterpclib::SystemMethodSignatureResponse aResponse);
    void doDisplayServerInfoResponse(qsipgaterpclib::SystemServerInfoResponse aResponse);
    void doDisplayError(QString anError);
};

} // namespace tests

#endif // TESTS_OUTPUT_H
