#ifndef QSIPGATERPCLIB_SAMURAIPHONEBOOKENTRYGETRESPONSE_H
#define QSIPGATERPCLIB_SAMURAIPHONEBOOKENTRYGETRESPONSE_H

#include <QList>
#include <QVariant>
#include <QVariantList>

namespace qsipgaterpclib {

class SamuraiPhonebookEntryGetResponse
{
public:
    SamuraiPhonebookEntryGetResponse(const QVariant &aVariant);

    QList<QList<QVariant> >  getEntryList() const;

private:
    QVariantList entryIdList;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SAMURAIPHONEBOOKENTRYGETRESPONSE_H
