#include "output.h"

#include <iostream>

#include <QString>
#include <QList>
#include <QVariant>

namespace tests {

Output::Output(QObject *parent) :
    QObject(parent)
{
}

void Output::doDisplayListMethodsResponse(qsipgaterpclib::SystemListMethodsResponse aResponse)
{
    std::cout << "output: " << std::endl;
    QList<QString> list = aResponse.getList();
    foreach(QString value, list) {
        std::cout << value.toAscii().constData() << std::endl;
    }
}

void Output::doDisplayMethodHelpResponse(qsipgaterpclib::SystemMethodHelpResponse aResponse)
{
    std::cout << "output: " << std::endl;
    QString help = aResponse.getHelp();
    std::cout << help.toAscii().constData() << std::endl;
}

void Output::doDisplayMethodSignatureResponse(qsipgaterpclib::SystemMethodSignatureResponse aResponse)
{
    std::cout << "output: " << std::endl;
    QString help = aResponse.getSignature();
    std::cout << help.toAscii().constData() << std::endl;
}

void Output::doDisplayServerInfoResponse(qsipgaterpclib::SystemServerInfoResponse aResponse)
{
    std::cout << "output: " << std::endl;
    QString serverName = aResponse.getServerName();
    std::cout << serverName.toAscii().constData() << std::endl;
    QString serverVendor = aResponse.getServerVendor();
    std::cout << serverVendor.toAscii().constData() << std::endl;
    QString serverVersion = aResponse.getServerVersion();
    std::cout << serverVersion.toAscii().constData() << std::endl;
    QString specVersion = aResponse.getSpecVersion();
    std::cout << specVersion.toAscii().constData() << std::endl;
}

void Output::doDisplayAccountStatementResponse(qsipgaterpclib::SamuraiAccountStatementGetResponse aResponse)
{
    std::cout << "output: " << std::endl;
    QString startPeriod = aResponse.getStartDate();
    std::cout << "Start Period: " << startPeriod.toAscii().constData() << std::endl;
    QString endPeriod = aResponse.getEndDate();
    std::cout << "End Period: " << endPeriod.toAscii().constData() << std::endl;

    QString startCurrency = aResponse.getBalanceStartCurrency();
    double total = aResponse.getBalanceStartTotalIncludingVat();
    std::cout << "Total Start Balance: " << total << " " << startCurrency.toAscii().constData() << std::endl;

    QString endCurrency = aResponse.getBalanceEndCurrency();
    double totalEnd = aResponse.getBalanceEndTotalIncludingVat();
    std::cout << "Total End Balance: " << totalEnd << " " << endCurrency.toAscii().constData() << std::endl;

    QList<QList<QVariant> > accountStatements = aResponse.getAccountStatements();

    foreach(QList<QVariant> list, accountStatements) {
        foreach(QVariant variant, list) {
            std::cout << variant.toByteArray().constData() << " - ";
        }
        std::cout << std::endl;
    }
}

void Output::doDisplayBalanceGetResponse(qsipgaterpclib::SamuraiBalanceGetResponse aResponse)
{
    std::cout << "output: " << std::endl;
    QDateTime dateTime = aResponse.getBalanceTime();
    std::cout << "Timestamp: " << dateTime.toString().toAscii().constData() << std::endl;
    QVariant totalExcludingVat = aResponse.getTotalExcludingVat();
    std::cout << "Total excluding Vat: " << totalExcludingVat.toByteArray().constData() << std::endl;
    QVariant vatAmount = aResponse.getVatAmount();
    std::cout << "Vat amount: " << vatAmount.toByteArray().constData() << std::endl;
    QVariant totalIncludingVat = aResponse.getTotalIncludingVat();
    std::cout << "Total including Vat: " << totalIncludingVat.toByteArray().constData() << std::endl;
    QVariant vatPercent = aResponse.getVatPercent();
    std::cout << "Vat percent: " << vatPercent.toByteArray().constData() << std::endl;
}

void Output::doDisplayHistoryResponse(qsipgaterpclib::SamuraiHistoryGetByDateResponse aResponse)
{
    std::cout << "output: " << std::endl;
    QList<QList<QVariant> > list = aResponse.getHistoryEntrys();
    foreach(QList<QVariant> line, list) {
        foreach(QVariant variant, line) {
            std::cout << variant.toByteArray().constData() << " - ";
        }
        std::cout << std::endl;
    }
}

void Output::doDisplayTosListResponse(qsipgaterpclib::SamuraiTosListGetResponse aResponse)
{
    std::cout << "output: " << std::endl;
    QList<QString> list = aResponse.getTosList();
    foreach(QString line, list) {
        std::cout << line.toAscii().constData() << " - ";
    }
    std::cout << std::endl;
}

void Output::doDisplayOwnUriListResponse(qsipgaterpclib::SamuraiOwnUriListGetResponse aResponse)
{
    std::cout << "output: " << std::endl;
    QList<QList<QVariant> > list = aResponse.getOwnUriList();
    foreach(QList<QVariant> line, list) {
        std::cout << line.at(0).toByteArray().constData() << std::endl;
        std::cout << line.at(1).toByteArray().constData() << std::endl;
        std::cout << line.at(4).toByteArray().constData() << std::endl;
        std::cout << line.at(5).toByteArray().constData() << std::endl;

        std::cout << "E164 List: " << std::endl;
        QList<QVariant> e164List = line.at(2).toList();
        foreach(QVariant variant, e164List) {
            std::cout << variant.toByteArray().constData() << " - ";
        }
        std::cout << std::endl;

        std::cout << "Tos List: " << std::endl;
        QList<QVariant> tosList = line.at(3).toList();
        foreach(QVariant variant, tosList) {
            std::cout << variant.toByteArray().constData() << " - ";
        }
        std::cout << std::endl;
    }
}

void Output::doDisplayItemizedEntriesResponse(qsipgaterpclib::SamuraiItemizedEntriesGetResponse aResponse)
{
    std::cout << "output: " << std::endl;
    QDateTime startTime = aResponse.getPeriodStart();
    QDateTime endTime = aResponse.getPeriodEnd();
    std::cout << startTime.toString().toAscii().constData() << " - " << endTime.toString().toAscii().constData() << std::endl;

    QList<QList<QVariant> > list = aResponse.getItemizedEntries();
    foreach(QList<QVariant> line, list) {
        foreach(QVariant variant, line) {
            std::cout << variant.toByteArray().constData() << " - ";
        }
        std::cout << std::endl;
    }
}

void Output::doDisplayPhonebookEntryResponse(qsipgaterpclib::SamuraiPhonebookEntryGetResponse aResponse)
{
    std::cout << "output: " << std::endl;
    QList<QList<QVariant> > list = aResponse.getEntryList();
    foreach(QList<QVariant> line, list) {
        foreach(QVariant variant, line) {
            std::cout << variant.toByteArray().constData() << " - ";
        }
        std::cout << std::endl;
    }
}

void Output::doDisplayPhonebookListResponse(qsipgaterpclib::SamuraiPhonebookListGetResponse aResponse)
{
    std::cout << "output: " << std::endl;
    QList<QList<QVariant> > list = aResponse.getPhonebookList();
    foreach(QList<QVariant> line, list) {
        foreach(QVariant variant, line) {
            std::cout << variant.toByteArray().constData() << " - ";
        }
        std::cout << std::endl;
    }
}

void Output::doDisplayIntervalResponse(qsipgaterpclib::SamuraiRecommendedIntervalGetResponse aResponse)
{
    std::cout << "output: " << std::endl;
    QList<QList<QVariant> > list = aResponse.getIntervalList();
    foreach(QList<QVariant> line, list) {
        foreach(QVariant variant, line) {
            std::cout << variant.toByteArray().constData() << " - ";
        }
        std::cout << std::endl;
    }
}

void Output::doDisplayServerdataResponse(qsipgaterpclib::SamuraiServerdataGetResponse aResponse)
{
    std::cout << "output: " << std::endl;
    std::cout << "Sip registrar: " << aResponse.getSipRegistrarServer().toAscii().constData() << std::endl;
    std::cout << "Sip outbound proxy: " << aResponse.getSipOutboundProxy().toAscii().constData() << std::endl;
    std::cout << "STUN server: " << aResponse.getStunServer().toAscii().constData() << std::endl;
    std::cout << "NTP server: " << aResponse.getNtpServer().toAscii().constData() << std::endl;
    std::cout << "HTTP server: " << aResponse.getHttpServer().toAscii().constData() << std::endl;
    std::cout << "Samurai server: " << aResponse.getSamuraiServer().toAscii().constData() << std::endl;
    std::cout << "Simple server: " << aResponse.getSimpleServer().toAscii().constData() << std::endl;
    std::cout << "XMPP server: " << aResponse.getXmppServer().toAscii().constData() << std::endl;
}

void Output::doDisplayClientIdentifyResponse(qsipgaterpclib::SamuraiClientIdentifyResponse aResponse)
{
    std::cout << "output: " << std::endl;
    std::cout << "Receive response." << std::endl;
}

void Output::doDisplayHandlerError(QString anError)
{
    std::cout << "RPC Error: " << anError.toAscii().constData() << std::endl;
}

void Output::doDisplayError(QString anError)
{
    std::cout << "Error: " << anError.toAscii().constData() << std::endl;
}

} // namespace tests
