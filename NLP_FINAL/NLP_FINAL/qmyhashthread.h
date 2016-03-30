#ifndef QMYHASHTHREAD_H
#define QMYHASHTHREAD_H

#include <QThread>
#include <QHash>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <QRegExp>
#include <QTime>
#include <QStringList>
#include <QVector>

class QMyHashThread : public QThread
{
    Q_OBJECT
public:
    explicit QMyHashThread(QObject *parent = 0);
    ~QMyHashThread();
    QString findWord(QString word);
    QStringList correctWord(QString wordtofind);
    int LevenshteinDistance(QString a, QString b);
    inline int minimum(int a, int b, int c);
    QVector<int> correctSentence(QString s, int startpos);
    void addNewWords(QStringList list);
    QTextStream *getUserTs();
    QHash<QString,QString>* getDicPointer();
    QTextStream *getTextStreamPointer();

signals:
    void loadThreadExited(int timeused);

protected:
    void run();
private:
    QHash<QString, QString> dic;
    int matrix[100][100];
    QFile *userFile;
    QTextStream *userTs;

};

#endif // QMYHASHTHREAD_H
