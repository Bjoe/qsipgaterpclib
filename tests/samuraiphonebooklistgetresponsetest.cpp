#include <QObject>
#include <QtTest/QtTest>

#include <QString>
#include <QList>
#include <QVariant>
#include <QVariantList>
#include <QVariantMap>

#include "samuraiphonebooklistgetresponse.h"

namespace tests {

class SamuraiPhonebookListGetResponseTest : public QObject
{
    Q_OBJECT

private slots:
    void testGet();
};

void SamuraiPhonebookListGetResponseTest::testGet()
{
    QVariantMap phonebookMap;
    phonebookMap.insert("EntryID", QVariant("anEntryID"));
    phonebookMap.insert("EntryHash", QVariant("anEntryHash"));

    QVariantList phonebookListVariant;
    phonebookListVariant.append(QVariant(phonebookMap));

    QVariant phonebookVariant(phonebookListVariant);
    qsipgaterpclib::SamuraiPhonebookListGetResponse
            response(phonebookVariant);
    QList<QList<QVariant> > phonebookList = response.getPhonebookList();
    QCOMPARE(phonebookList.count(), 1);
    QList<QVariant> line = phonebookList.at(0);
    QCOMPARE(line.at(0), QVariant("anEntryID"));
    QCOMPARE(line.at(1), QVariant("anEntryHash"));
}

}

QTEST_MAIN(tests::SamuraiPhonebookListGetResponseTest)
#include "moc_samuraiphonebooklistgetresponsetest.cxx"
