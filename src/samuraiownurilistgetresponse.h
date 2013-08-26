#ifndef QSIPGATERPCLIB_SAMURAIOWNURILISTGETRESPONSE_H
#define QSIPGATERPCLIB_SAMURAIOWNURILISTGETRESPONSE_H

#include <QList>
#include <QVariant>
#include <QVariantList>

namespace qsipgaterpclib {

class SamuraiOwnUriListGetResponse
{
public:
    SamuraiOwnUriListGetResponse(const QVariant &aOwnUriList);

    QList<QList<QVariant> > getOwnUriList() const;

private:
    QVariantList uriList;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_RESPONSE_H
