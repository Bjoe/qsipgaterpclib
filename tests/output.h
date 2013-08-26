#ifndef TESTS_OUTPUT_H
#define TESTS_OUTPUT_H

#include <QObject>
#include "systemlistmethodsresponse.h"
#include "systemmethodhelpresponse.h"
#include "systemmethodsignatureresponse.h"
#include "systemserverinforesponse.h"
#include "samuraiaccountstatementgetresponse.h"
#include "samuraibalancegetresponse.h"
#include "samuraiclientidentifyresponse.h"
#include "samuraihistorygetbydateresponse.h"
#include "samuraiitemizedentriesgetresponse.h"
#include "samuraiownurilistgetresponse.h"
#include "samuraiphonebookentrygetresponse.h"
#include "samuraiphonebooklistgetresponse.h"
#include "samurairecommendedintervalgetresponse.h"
#include "samuraiserverdatagetresponse.h"
#include "samuraitoslistgetresponse.h"

namespace tests {

class Output : public QObject
{
    Q_OBJECT
public:
    explicit Output(QObject *parent = 0);
    
public slots:
    void doDisplayListMethodsResponse(qsipgaterpclib::SystemListMethodsResponse aResponse);
    void doDisplayMethodHelpResponse(qsipgaterpclib::SystemMethodHelpResponse aResponse);
    void doDisplayMethodSignatureResponse(qsipgaterpclib::SystemMethodSignatureResponse aResponse);
    void doDisplayServerInfoResponse(qsipgaterpclib::SystemServerInfoResponse aResponse);
    void doDisplayAccountStatementResponse(qsipgaterpclib::SamuraiAccountStatementGetResponse aResponse);
    void doDisplayBalanceGetResponse(qsipgaterpclib::SamuraiBalanceGetResponse aResponse);
    void doDisplayClientIdentifyResponse(qsipgaterpclib::SamuraiClientIdentifyResponse aResponse);
    void doDisplayHistoryResponse(qsipgaterpclib::SamuraiHistoryGetByDateResponse aResponse);
    void doDisplayItemizedEntriesResponse(qsipgaterpclib::SamuraiItemizedEntriesGetResponse aResponse);
    void doDisplayOwnUriListResponse(qsipgaterpclib::SamuraiOwnUriListGetResponse aResponse);
    void doDisplayPhonebookEntryResponse(qsipgaterpclib::SamuraiPhonebookEntryGetResponse aResponse);
    void doDisplayPhonebookListResponse(qsipgaterpclib::SamuraiPhonebookListGetResponse aResponse);
    void doDisplayIntervalResponse(qsipgaterpclib::SamuraiRecommendedIntervalGetResponse aResponse);
    void doDisplayServerdataResponse(qsipgaterpclib::SamuraiServerdataGetResponse aResponse);
    void doDisplayTosListResponse(qsipgaterpclib::SamuraiTosListGetResponse aResponse);

    void doDisplayHandlerError(QString anError);
    void doDisplayError(QString anError);
};

} // namespace tests

#endif // TESTS_OUTPUT_H
