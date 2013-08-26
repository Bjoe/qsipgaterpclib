#ifndef QSIPGATERPCLIB_SAMURAITOSLISTGETRESPONSE_H
#define QSIPGATERPCLIB_SAMURAITOSLISTGETRESPONSE_H

#include <QString>
#include <QList>
#include <QVariant>
#include <QVariantList>

namespace qsipgaterpclib {

class SamuraiTosListGetResponse
{
public:
    SamuraiTosListGetResponse(const QVariant &aList);

    QList<QString> getTosList() const;

private:
    QVariantList list;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SAMURAITOSLISTGETRESPONSE_H
