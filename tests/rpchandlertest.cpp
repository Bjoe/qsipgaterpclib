#include "rpchandlertest.h"

#include "rpchandler.h"

#include <QString>
#include <QVariantList>
#include <QFile>
#include <QSignalSpy>
#include <QSslError>
#include <QNetworkReply>
#include <QxtXmlRpcCall>
#include <QxtXmlRpcClient>

#include "mockabstractrequest.h"
#include "mockabstracthandler.h"
#include "testconfig.h"

Q_DECLARE_METATYPE(QList<QSslError>)
Q_DECLARE_METATYPE(QNetworkReply::NetworkError)

using ::testing::Return;
using ::testing::_;

namespace tests {

void RpcHandlerTest::testSendRequest()
{
    QxtXmlRpcClient *rpcClient = new QxtXmlRpcClient();
    qsipgaterpclib::RpcHandler *handler = new qsipgaterpclib::RpcHandler(rpcClient);

    MockAbstractRequest mock("mock");
    MockAbstractHandler mockHandler;
    EXPECT_CALL(mock, getHandler()).Times(1)
            .WillOnce(Return(&mockHandler));
    EXPECT_CALL(mockHandler, handleResponse(_)).Times(0);

    handler->sendRpcRequest(&mock);

    EXPECT_CALL(mockHandler, handleResponse(_)).Times(1);

    handler->rpcFinished();
}

void RpcHandlerTest::testRpcError_data()
{
    QTest::addColumn<QNetworkReply::NetworkError>("code");
    QTest::addColumn<QString>("expected");

    QTest::newRow("Authentication required") << QNetworkReply::AuthenticationRequiredError << QString(tr("Authentifizierung wird benoetigt."));
    QTest::newRow("Connection refused") << QNetworkReply::ConnectionRefusedError << QString(tr("Verbindung wurde abgewiesen."));
    QTest::newRow("Remote host closed") << QNetworkReply::RemoteHostClosedError << QString(tr("Server hat die Verbindung geschlossen."));
    QTest::newRow("Host not found") << QNetworkReply::HostNotFoundError << QString(tr("Servername konnte nicht gefunden werden."));
    QTest::newRow("Timeout") << QNetworkReply::TimeoutError << QString(tr("Server hat nicht geantwortet."));
    QTest::newRow("Operation Canceled") << QNetworkReply::OperationCanceledError << QString(tr("Die Operation wurde abgebrochen."));
    QTest::newRow("SSL Handshake failed") << QNetworkReply::SslHandshakeFailedError << QString(tr("SSL Verbindung konnte nicht aufgebaut werden."));
    QTest::newRow("Temporary network failure") << QNetworkReply::TemporaryNetworkFailureError << QString(tr("Temporaerer Netwerk Fehler."));
    QTest::newRow("Proxy connection refused") << QNetworkReply::ProxyConnectionRefusedError << QString(tr("Proxy Verbindung wurde abgewiesen."));
    QTest::newRow("Proxy connection closed") << QNetworkReply::ProxyConnectionClosedError << QString(tr("Proxy Verbindung wurde geschlossen."));
    QTest::newRow("Proxy Not found") << QNetworkReply::ProxyNotFoundError << QString(tr("Proxy wurde nicht gefunden."));
    QTest::newRow("Proxy timeout") << QNetworkReply::ProxyTimeoutError << QString(tr("Proxy hat nicht geantwortet."));
    QTest::newRow("Proxy authentication required") << QNetworkReply::ProxyAuthenticationRequiredError << QString(tr("Proxy erwartet eine Authentifizierung."));
    QTest::newRow("Content access denied") << QNetworkReply::ContentAccessDenied << QString(tr("Zugriff wurde verweigert."));
    QTest::newRow("Content operation not permitted") << QNetworkReply::ContentOperationNotPermittedError << QString(tr("Zugriff ist nicht erlaubt."));
    QTest::newRow("Content not found") << QNetworkReply::ContentNotFoundError << QString(tr("Ressource konnte nicht gefunden werden."));
    QTest::newRow("Content resend") << QNetworkReply::ContentReSendError << QString(tr("Content resend error."));
    QTest::newRow("Protocol unknown") << QNetworkReply::ProtocolUnknownError << QString(tr("Netzwerk Protokoll ist nicht bekannt."));
    QTest::newRow("Protocol invalid operation") << QNetworkReply::ProtocolInvalidOperationError << QString(tr("Falsche Netzwerk Protokoll Ausfuehrung."));
    QTest::newRow("Unknown network") << QNetworkReply::UnknownNetworkError << QString(tr("Ein unbekannter Netzwerk Fehler ist aufgetreten."));
    QTest::newRow("Unknown proxy") << QNetworkReply::UnknownProxyError << QString(tr("Ein unbekannter Proxy Fehler ist aufgetreten."));
    QTest::newRow("Unknown content") << QNetworkReply::UnknownContentError << QString(tr("Unbekannter Content Fehler."));
    QTest::newRow("Protocol failure") << QNetworkReply::ProtocolFailure << QString(tr("Ein Netwerk Fehler ist aufgetreten."));
}

void RpcHandlerTest::testRpcError()
{
    QFETCH(QNetworkReply::NetworkError, code);
    QFETCH(QString, expected);

    qsipgaterpclib::RpcHandler *handler = new qsipgaterpclib::RpcHandler(0);

    QSignalSpy signalSpy(handler, SIGNAL(error(QString)));

    handler->rpcError(code);

    QVERIFY(signalSpy.count() == 1);
    QList<QVariant> arguments = signalSpy.takeFirst();
    QVERIFY(arguments.size() == 1);
    QCOMPARE(arguments.at(0).toString(), expected);
}

void RpcHandlerTest::testRpcSslError_data()
{
    QTest::addColumn<QList<QSslError> >("codeList");
    QTest::addColumn<QString>("expected");

    QList<QSslError> list1;
    list1.append(QSslError::UnableToGetIssuerCertificate);
    QTest::newRow("Unable to get issuer certificate") << list1 << QString(tr("The issuer certificate could not be found. "));

    QList<QSslError> list2;
    list2.append(QSslError::UnableToDecryptCertificateSignature);
    QTest::newRow("Unable to decrypt certificaton signature") << list2 << QString(tr("The certificate signature could not be decrypted. "));

    QList<QSslError> list3;
    list3.append(QSslError::UnableToDecodeIssuerPublicKey);
    QTest::newRow("Unable to decode issuer public key") << list3 << QString(tr("The public key in the certificate could not be read. "));

    QList<QSslError> list4;
    list4.append(QSslError::CertificateSignatureFailed);
    QTest::newRow("Certificate signature failed") << list4 << QString(tr("The signature of the certificate is invalid. "));

    QList<QSslError> list5;
    list5.append(QSslError::CertificateNotYetValid);
    QTest::newRow("Certificate not yet valid") << list5 << QString(tr("The certificate is not yet valid. "));

    QList<QSslError> list6;
    list6.append(QSslError::CertificateExpired);
    QTest::newRow("Certificate expired") << list6 << QString(tr("The certificate has expired. "));

    QList<QSslError> list7;
    list7.append(QSslError::InvalidNotBeforeField);
    QTest::newRow("Invalid not before field") << list7 << QString(tr("The certificate's notBefore field contains an invalid time. "));

    QList<QSslError> list8;
    list8.append(QSslError::InvalidNotAfterField);
    QTest::newRow("Invalid not after field") << list8 << QString(tr("The certificate's notAfter field contains an invalid time. "));

    QList<QSslError> list9;
    list9.append(QSslError::SelfSignedCertificate);
    QTest::newRow("Self signed certificate") << list9 << QString(tr("The certificate is self-signed, and untrusted. "));

    QList<QSslError> list10;
    list10.append(QSslError::SelfSignedCertificateInChain);
    QTest::newRow("Self signed certificate in chain") << list10 << QString(tr("The root certificate of the certificate chain is self-signed, and untrusted. "));

    QList<QSslError> list11;
    list11.append(QSslError::UnableToGetLocalIssuerCertificate);
    QTest::newRow("Unable to get local issuer certificate") << list11 << QString(tr("The issuer certificate of a locally looked up certificate could not be found. "));

    QList<QSslError> list12;
    list12.append(QSslError::UnableToVerifyFirstCertificate);
    QTest::newRow("Unable to verify first certificate") << list12 << QString(tr("No certificates could be verified. "));

    QFile file(CERTIFICATE);
    file.open(QIODevice::ReadOnly);
    QSslCertificate certificate(&file);
    QList<QSslError> list13;
    list13.append(QSslError(QSslError::CertificateRevoked, certificate));
    QTest::newRow("Certificate revoked") << list13 << QString(tr("Common Name: secure.sipgate.de\nOrganization: \nIssuer common name: COMODO SSL CA\nIssuer organization: : COMODO CA Limited\nZertifikat wurde widerrufen (Unknown error). "));

    QList<QSslError> list14;
    list14.append(QSslError::InvalidCaCertificate);
    QTest::newRow("Invalid ca certificate") << list14 << QString(tr("One of the CA certificates is invalid. "));

    QList<QSslError> list15;
    list15.append(QSslError::PathLengthExceeded);
    QTest::newRow("Path length exceeded") << list15 << QString(tr("The basicConstraints path length parameter has been exceeded. "));

    QList<QSslError> list16;
    list16.append(QSslError::InvalidPurpose);
    QTest::newRow("Invalid purpose") << list16 << QString(tr("The supplied certificate is unsuitable for this purpose. "));

    QList<QSslError> list17;
    list17.append(QSslError::CertificateUntrusted);
    QTest::newRow("Certificate untrusted") << list17 << QString(tr("The root CA certificate is not trusted for this purpose. "));

    QList<QSslError> list18;
    list18.append(QSslError::CertificateRejected);
    QTest::newRow("Certificate rejected") << list18 << QString(tr("The root CA certificate is marked to reject the specified purpose. "));

    QList<QSslError> list19;
    list19.append(QSslError::SubjectIssuerMismatch);
    QTest::newRow("Subject issuer mismatch") << list19 << QString(tr("The current candidate issuer certificate was rejected because its subject name did not match the issuer name of the current certificate. "));

    QList<QSslError> list20;
    list20.append(QSslError::AuthorityIssuerSerialNumberMismatch);
    QTest::newRow("Authority issuer serial number mismatch") << list20 << QString(tr("The current candidate issuer certificate was rejected because its issuer name and serial number was present and did not match the authority key identifier of the current certificate. "));

    QList<QSslError> list21;
    list21.append(QSslError::NoPeerCertificate);
    QTest::newRow("No peer certificate") << list21 << QString(tr("The peer did not present any certificate. "));

    QList<QSslError> list22;
    list22.append(QSslError::HostNameMismatch);
    QTest::newRow("Host name mismatch") << list22 << QString(tr("The host name did not match any of the valid hosts for this certificate. "));

    QList<QSslError> list23;
    list23.append(QSslError::NoSslSupport);
    QTest::newRow("No ssl support") << list23 << QString(tr("Es wird kein SSL unterstuezt (). "));

    QList<QSslError> list24;
    list24.append(QSslError::CertificateBlacklisted);
    QTest::newRow("Certificate blacklisted") << list15 << QString(tr("The basicConstraints path length parameter has been exceeded. "));

    QList<QSslError> list25;
    list25.append(QSslError::UnspecifiedError);
    QTest::newRow("Unspecified error") << list25 << QString(tr("Unknown error. "));

    QList<QSslError> list26;
    list26.append(QSslError::CertificateRejected);
    list26.append(QSslError::CertificateSignatureFailed);
    QTest::newRow("Certificate rejected, certificate signature failed") << list26 << QString(tr("The root CA certificate is marked to reject the specified purpose. The signature of the certificate is invalid. "));
}

void RpcHandlerTest::testRpcSslError()
{
    QFETCH(QList<QSslError>, codeList);
    QFETCH(QString, expected);

    qsipgaterpclib::RpcHandler *handler = new qsipgaterpclib::RpcHandler(0);

    QSignalSpy signalSpy(handler, SIGNAL(error(QString)));

    handler->rpcSslErrors(codeList);

    QVERIFY(signalSpy.count() == 1);
    QList<QVariant> arguments = signalSpy.takeFirst();
    QVERIFY(arguments.size() == 1);
    QCOMPARE(arguments.at(0).toString(), expected);
}

} // namespace tests

QTEST_GMOCK_MAIN(tests::RpcHandlerTest)
#include "rpchandlertest.moc"
