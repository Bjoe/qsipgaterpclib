#include "samuraitoslistgetresponse.h"

namespace qsipgaterpclib {

SamuraiTosListGetResponse::SamuraiTosListGetResponse(const QVariant &aList) : list(aList.toList())
{
}

QList<QString> SamuraiTosListGetResponse::getTosList() const
{
    QList<QString> tosList;
    foreach(QVariant variant, list) {
        tosList.append(variant.toString());
    }

    return tosList;
}

} // namespace qsipgaterpclib
