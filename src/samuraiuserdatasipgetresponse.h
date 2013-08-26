#ifndef QSIPGATERPCLIB_SAMURAIUSERDATASIPGETRESPONSE_H
#define QSIPGATERPCLIB_SAMURAIUSERDATASIPGETRESPONSE_H

#include <QList>
#include <QVariant>
#include <QVariantList>

namespace qsipgaterpclib {

class SamuraiUserdataSipGetResponse
{
public:
    SamuraiUserdataSipGetResponse(const QVariant &aList);

    QList<QList<QVariant> > getSipDataList() const;

private:
    QVariantList sipDataList;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SAMURAIUSERDATASIPGETRESPONSE_H
