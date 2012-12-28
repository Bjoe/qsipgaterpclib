#ifndef QSIPGATERPCLIB_ABSTRACTREQUEST_H
#define QSIPGATERPCLIB_ABSTRACTREQUEST_H

#include <QObject>
#include <QString>
#include <QVariant>
#include <QVariantMap>
#include <QVariantList>

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

    virtual void handleResponse(const QVariant &aVariant);

signals:
    void error(QString aMessage);

protected:
    virtual bool createResponse(const QVariantMap &aVariant) =0;

private:
    QVariantList arguments;
    QString method;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_ABSTRACTREQUEST_H
