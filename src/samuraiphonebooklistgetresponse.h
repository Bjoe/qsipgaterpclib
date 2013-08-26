#ifndef QSIPGATERPCLIB_SAMURAIPHONEBOOKLISTGETRESPONSE_H
#define QSIPGATERPCLIB_SAMURAIPHONEBOOKLISTGETRESPONSE_H

#include <QList>
#include <QVariant>
#include <QVariantList>
#include <QVariantMap>

namespace qsipgaterpclib {

class SamuraiPhonebookListGetResponse
{
public:
    SamuraiPhonebookListGetResponse(const QVariant &aPhonebook);

    QList<QList<QVariant> > getPhonebookList() const;

private:
    QVariantList phonebookList;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SAMURAIPHONEBOOKLISTGETRESPONSE_H
