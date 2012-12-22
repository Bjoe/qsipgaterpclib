#ifndef QSIPGATERPCLIB_ABSTRACTREQUEST_H
#define QSIPGATERPCLIB_ABSTRACTREQUEST_H

#include <QObject>
#include <QString>
#include <QVariantList>

#include "abstracthandler.h"

namespace qsipgaterpclib {

class AbstractRequest : public QObject
{
    Q_OBJECT
public:
    explicit AbstractRequest(const QString &aMethod, QObject *parent = 0);
    virtual ~AbstractRequest() {}

    void setArguments(const QVariantList &anArguments)
    {
        arguments = anArguments;
    }

    QString getMethod() const
    {
        return method;
    }

    QVariantList getArguments() const
    {
        return arguments;
    }

    virtual AbstractHandler *getHandler() =0;

private:
    QVariantList arguments;
    QString method;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_ABSTRACTREQUEST_H
