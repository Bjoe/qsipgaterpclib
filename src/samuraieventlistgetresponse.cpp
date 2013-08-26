#include "samuraieventlistgetresponse.h"

#include <QVariantMap>

namespace qsipgaterpclib {

SamuraiEventListGetResponse::SamuraiEventListGetResponse()
    : count(0), eventList()
{
}

SamuraiEventListGetResponse::SamuraiEventListGetResponse(int aCount, const QVariant anEventList)
    : count(aCount), eventList(anEventList.toList())
{
}

int SamuraiEventListGetResponse::getOverallCount()
{
    return count;
}

QList<QVariantList> SamuraiEventListGetResponse::getEventList()
{
    QList<QVariantList> list;

    foreach(QVariant variant, eventList) {
        QVariantMap event = variant.toMap();

        QVariantList line;
        line.append(event.value("EventID"));
        line.append(event.value("SourceUri"));
        line.append(event.value("TargetUri"));
        line.append(event.value("Timestamp"));
        line.append(event.value("SizeDepend"));
        line.append(event.value("TOS"));
        line.append(event.value("UnRead"));

        QVariantList contentList;
        QVariant contentVariant = event.value("ContentList");
        foreach(QVariant content, contentVariant.toList()) {
            QVariantMap contentMap = content.toMap();

            QVariantList contentLine;
            contentLine.append(contentMap.value("SizeBytes"));
            contentLine.append(contentMap.value("SizeDepend"));
            contentLine.append(contentMap.value("DownloadUriHttp"));
            contentLine.append(contentMap.value("ContentType"));

            contentList.append(QVariant(contentLine));
        }

        line.append(QVariant(contentList));
        line.append(event.value("Labels"));

        list.append(line);
    }

    return list;
}

} // namespace qsipgaterpclib
