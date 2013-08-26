#ifndef QSIPGATERPCLIB_SAMURAIEVENTLISTGETRESPONSE_H
#define QSIPGATERPCLIB_SAMURAIEVENTLISTGETRESPONSE_H

#include <QVariant>
#include <QList>
#include <QVariantList>

namespace qsipgaterpclib {

class SamuraiEventListGetResponse
{
public:
    SamuraiEventListGetResponse();
    SamuraiEventListGetResponse(int aCount, const QVariant anEventList);

    int getOverallCount();
    QList<QVariantList> getEventList();

private:
    int count;
    QVariantList eventList;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SAMURAIEVENTLISTGETRESPONSE_H
