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

void Output::doDisplayHandlerError(QString anError)
{
    std::cout << "RPC Error: " << anError.toAscii().constData() << std::endl;
}

void Output::doDisplayError(QString anError)
{
    std::cout << "Error: " << anError.toAscii().constData() << std::endl;
}

} // namespace tests
