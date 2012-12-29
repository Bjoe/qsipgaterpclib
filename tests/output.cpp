#include "output.h"

#include <iostream>

#include <QString>
#include <QList>

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

void Output::doDisplayError(QString anError)
{
    std::cout << "Error: " << anError.toAscii().constData() << std::endl;
}


} // namespace tests
