#ifndef TESTS_OUTPUT_H
#define TESTS_OUTPUT_H

#include <QObject>
#include "systemlistmethodsresponse.h"

namespace tests {

class Output : public QObject
{
    Q_OBJECT
public:
    explicit Output(QObject *parent = 0);
    
public slots:
    void doDisplayResponse(qsipgaterpclib::SystemListMethodsResponse aResponse);
    void doDisplayError(QString anError);
};

} // namespace tests

#endif // TESTS_OUTPUT_H
