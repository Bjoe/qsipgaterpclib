#ifndef QSIPGATERPCLIB_SAMURAIHISTORYGETBYDATERESPONSE_H
#define QSIPGATERPCLIB_SAMURAIHISTORYGETBYDATERESPONSE_H

#include <QList>
#include <QVariant>

namespace qsipgaterpclib {

class SamuraiHistoryGetByDateResponse
{
public:
    SamuraiHistoryGetByDateResponse(const QVariant &aHistory);

    QList<QList<QVariant> > getHistoryEntrys() const;

private:
    QVariantList historyList;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SAMURAIHISTORYGETBYDATERESPONSE_H
