#include <QObject>
#include <QtTest/QtTest>

#include "request.h"

#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QMap>
#include <QVariantList>

#include "response.h"

namespace tests {

class RequestTest : public QObject
{
    Q_OBJECT

private slots:
    void testCreateInstance();
    void testCreateResponse();
    void testCreateResponseFailed();
};

void RequestTest::testCreateInstance()
{
    qsipgaterpclib::Request *request =
            qsipgaterpclib::RequestFactory::createInstance(this)
            .withFoo("foobar")
            .build();
    QCOMPARE(request->getMethod(), QString("foo.foo"));
    QVariantList list = request->getArguments();
    QMap<QString, QVariant> map = list.at(0).toMap();
    QCOMPARE(map.value("Foo"), QVariant("foobar"));
}

void RequestTest::testCreateResponse()
{
    qsipgaterpclib::Request *request =
            qsipgaterpclib::RequestFactory::createInstance(this)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::Response)));

    QVariant dummy(QString("dummy"));
    QVariantMap variantMap;
    variantMap.insert("Foo", dummy);
    QVERIFY(request->createResponse(variantMap) == true);

    QCOMPARE(signalSpy.count(), 1);
    QList<QVariant> arguments = signalSpy.takeFirst();
    QCOMPARE(arguments.count(), 1);
}

void RequestTest::testCreateResponseFailed()
{
    qsipgaterpclib::Request *request =
            qsipgaterpclib::RequestFactory::createInstance(this)
            .build();

    QSignalSpy signalSpy(request, SIGNAL(ready(qsipgaterpclib::Response)));

    QVariantMap variantMap;
    QVERIFY(request->createResponse(variantMap) == false);

    QCOMPARE(signalSpy.count(), 0);
}

}

QTEST_MAIN(tests::RequestTest)
#include "moc_requesttest.cxx"

