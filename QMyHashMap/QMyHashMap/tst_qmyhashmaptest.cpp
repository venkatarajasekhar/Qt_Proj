#include <QString>
#include <QtTest>
#include <QHash>

class QMyHashMapTest : public QThread
{
    Q_OBJECT

public:
    QMyHashMapTest();

protected:
    QHash<QString, QString> dic;
    void run();
private Q_SLOTS:
    void testCase1();

};

QMyHashMapTest::QMyHashMapTest()
{
}

void QMyHashMapTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

void QMyHashMapTest::run()
{
    QFile file("diclarge.txt");
    if(file.open(QFile::ReadOnly))
    {
        QTextStream fs(&file);
        QString key="", value="", line="";
        while(!fs.atEnd())
        {
            fs>>line;
            //line.
            qDebug()<<line;
        }
    }
}

QTEST_APPLESS_MAIN(QMyHashMapTest)

#include "tst_qmyhashmaptest.moc"

