#include <QObject>
#include <QtTest/QtTest>

#include "systemmethodhelprequest.h"

#include "systemmethodhelphandler.h"

#include <QString>
#include <QVariantList>

namespace tests {

class SystemMethodHelpRequestTest : public QObject
{
    Q_OBJECT

private slots:
    void testCreateInstance();
    void testGetHandler();
};

void SystemMethodHelpRequestTest::testCreateInstance()
{
    qsipgaterpclib::SystemMethodHelpRequest *request =
            qsipgaterpclib::SystemMethodHelpRequestFactory::createInstance()
            .withMethodName("foo.bar")
            .build();
    QCOMPARE(request->getMethod(), QString("system.methodHelp"));
    QVariantList list = request->getArguments();
    QHash<QString, QVariant> map = list.at(0).toHash();
    QCOMPARE(map.value("MethodName"), QVariant(QString("foo.bar")));
}

void SystemMethodHelpRequestTest::testGetHandler()
{
    qsipgaterpclib::SystemMethodHelpRequest *request = qsipgaterpclib::SystemMethodHelpRequestFactory::createInstance().build();
    qsipgaterpclib::SystemMethodHelpHandler *handler = request->getHandler();

}

}

QTEST_MAIN(tests::SystemMethodHelpRequestTest)
#include "moc_systemmethodhelprequesttest.cxx"
