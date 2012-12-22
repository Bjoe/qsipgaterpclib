#ifndef QSIPGATERPCLIB_SYSTEMLISTMETHODSRESPONSE_H
#define QSIPGATERPCLIB_SYSTEMLISTMETHODSRESPONSE_H

#include <QString>
#include <QList>
#include <QVariantList>

namespace qsipgaterpclib {

class SystemListMethodsResponse
{
public:
    SystemListMethodsResponse(const QVariantList &aList);

    const QString at(int aPosition) const;
    int count() const;
    int length() const;
    QList<QString> getList() const;

private:
    QVariantList variantList;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SYSTEMLISTMETHODSRESPONSE_H
