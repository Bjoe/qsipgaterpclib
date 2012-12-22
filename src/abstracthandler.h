#ifndef QSIPGATERPCLIB_ABSTRACTHANDLER_H
#define QSIPGATERPCLIB_ABSTRACTHANDLER_H

#include <QObject>
#include <QString>
#include <QVariant>
#include <QVariantMap>

namespace qsipgaterpclib {

class AbstractHandler : public QObject
{
    Q_OBJECT

public:
    explicit AbstractHandler(QObject *parent = 0);
    virtual ~AbstractHandler() {}

    virtual void handleResponse(const QVariant &aVariant);

signals:
    void error(QString aMessage);

protected:
    virtual bool createResponse(const QVariantMap &aVariant) =0;

};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_ABSTRACTHANDLER_H
