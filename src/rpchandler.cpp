#include "rpchandler.h"

namespace qsipgaterpclib {

RpcHandler::RpcHandler(QxtXmlRpcClient *aXmlRpcClient, QObject *aParent) :
    QObject(aParent), xmlRpcClient(aXmlRpcClient), rpcCall(0), request(0)
{
}

RpcHandler::~RpcHandler()
{
    if(rpcCall != 0) {
        delete rpcCall;
    }
}

bool RpcHandler::sendRpcRequest(AbstractRequest *aRequest)
{
    request = aRequest;
    rpcCall = xmlRpcClient->call(request->getMethod(), request->getArguments());

    connect(rpcCall, SIGNAL(error(QNetworkReply::NetworkError)), SLOT(rpcError(QNetworkReply::NetworkError)));
    connect(rpcCall, SIGNAL(sslErrors(const QList<QSslError> &)), SLOT(rpcSslErrors(const QList<QSslError> &)));
    connect(rpcCall, SIGNAL(finished()), SLOT(rpcFinished()));
}

void RpcHandler::rpcFinished()
{
    if(request != 0 && rpcCall != 0) {
        request->handleResponse(rpcCall->result());
    }
}

void RpcHandler::rpcError(QNetworkReply::NetworkError aCode)
{
    QString message("");
    switch(aCode) {

    case QNetworkReply::AuthenticationRequiredError:
        message.append(tr("Authentifizierung wird benoetigt."));
        break;
    case QNetworkReply::ConnectionRefusedError:
        message.append(tr("Verbindung wurde abgewiesen."));
        break;
    case QNetworkReply::RemoteHostClosedError:
        message.append(tr("Server hat die Verbindung geschlossen."));
        break;
    case QNetworkReply::HostNotFoundError:
        message.append(tr("Servername konnte nicht gefunden werden."));
        break;
    case QNetworkReply::TimeoutError:
        message.append(tr("Server hat nicht geantwortet."));
        break;
    case QNetworkReply::OperationCanceledError:
        message.append(tr("Die Operation wurde abgebrochen."));
        break;
    case QNetworkReply::SslHandshakeFailedError:
        message.append(tr("SSL Verbindung konnte nicht aufgebaut werden."));
        break;
    case QNetworkReply::TemporaryNetworkFailureError:
        message.append(tr("Temporaerer Netwerk Fehler."));
        break;
    case QNetworkReply::ProxyConnectionRefusedError:
        message.append(tr("Proxy Verbindung wurde abgewiesen."));
        break;
    case QNetworkReply::ProxyConnectionClosedError:
        message.append(tr("Proxy Verbindung wurde geschlossen."));
        break;
    case QNetworkReply::ProxyNotFoundError:
        message.append(tr("Proxy wurde nicht gefunden."));
        break;
    case QNetworkReply::ProxyTimeoutError:
        message.append(tr("Proxy hat nicht geantwortet."));
        break;
    case QNetworkReply::ProxyAuthenticationRequiredError:
        message.append(tr("Proxy erwartet eine Authentifizierung."));
        break;
    case QNetworkReply::ContentAccessDenied:
        message.append(tr("Zugriff wurde verweigert."));
        break;
    case QNetworkReply::ContentOperationNotPermittedError:
        message.append(tr("Zugriff ist nicht erlaubt."));
        break;
    case QNetworkReply::ContentNotFoundError:
        message.append(tr("Ressource konnte nicht gefunden werden."));
        break;
    case QNetworkReply::ContentReSendError:
        message.append(tr("Content resend error."));
        break;
    case QNetworkReply::ProtocolUnknownError:
        message.append(tr("Netzwerk Protokoll ist nicht bekannt."));
        break;
    case QNetworkReply::ProtocolInvalidOperationError:
        message.append(tr("Falsche Netzwerk Protokoll Ausfuehrung."));
        break;
    case QNetworkReply::UnknownNetworkError:
        message.append(tr("Ein unbekannter Netzwerk Fehler ist aufgetreten."));
        break;
    case QNetworkReply::UnknownProxyError:
        message.append(tr("Ein unbekannter Proxy Fehler ist aufgetreten."));
        break;
    case QNetworkReply::UnknownContentError:
        message.append(tr("Unbekannter Content Fehler."));
        break;
    case QNetworkReply::ProtocolFailure:
        message.append(tr("Ein Netwerk Fehler ist aufgetreten."));
        break;
    default:
        message.append(tr("Unknown Error Code: ") + aCode);
    }

    emit error(message);
}

void RpcHandler::rpcSslErrors(const QList<QSslError> &anErrors)
{
    QString message("");
    foreach(const QSslError error, anErrors) {
        const QSslCertificate certificate = error.certificate();

        if(!certificate.isNull()) {
            message.append(QString("%1: %2\n").arg(tr("Common Name")).arg(certificate.subjectInfo(QSslCertificate::CommonName)));
            message.append(QString("%1: %2\n").arg(tr("Organization")).arg(certificate.subjectInfo(QSslCertificate::Organization)));
            message.append(QString("%1: %2\n").arg(tr("Issuer common name")).arg(certificate.issuerInfo(QSslCertificate::CommonName)));
            message.append(QString("%1: %2\n").arg(tr("Issuer organization: ")).arg(certificate.issuerInfo(QSslCertificate::Organization)));
            /// todo Add more information about certificate. For an example sha1 fingerprint
        }

        switch(error.error())
        {
        case QSslError::NoSslSupport:
            message.append(
                        QString("%2 (%1). ")
                        .arg(error.errorString())
                        .arg(tr("Es wird kein SSL unterstuezt")));
            break;
        case QSslError::CertificateRevoked:
            message.append(
                        QString("%2 (%1). ")
                        .arg(error.errorString())
                        .arg(tr("Zertifikat wurde widerrufen")));
            break;
        default:
            message.append(error.errorString() + ". ");
        }
    }

    emit error(message);
}

} // namespace qsipgaterpclib
