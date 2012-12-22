#include "systemlistmethodsresponse.h"

#include <QVariant>

namespace qsipgaterpclib {

SystemListMethodsResponse::SystemListMethodsResponse(const QVariantList &aList) : variantList(aList)
{
}

const QString SystemListMethodsResponse::at(int aPosition) const
{
    return variantList.at(aPosition).toString();
}

int SystemListMethodsResponse::count() const
{
    return variantList.count();
}

int SystemListMethodsResponse::length() const
{
    return variantList.length();
}

QList<QString> SystemListMethodsResponse::getList() const
{
    QList<QString> list;
    foreach(QVariant variant, variantList) {
        list.append(variant.toString());
    }
    return list;
}

} // namespace qsipgaterpclib
