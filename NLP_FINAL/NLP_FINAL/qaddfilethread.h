#ifndef QADDFILETHREAD_H
#define QADDFILETHREAD_H

#include <QThread>
#include "qmyhashthread.h"
class QAddFileThread : public QThread
{
    Q_OBJECT
public:
    explicit QAddFileThread(QObject *parent = 0);
    void setFileName(QString fname);
    void setDicPointer(QHash<QString, QString> *dic);
    void setTextStreamPointer(QTextStream *ts);
private:
    QHash<QString,QString> *dic; //this pointer is from QMyHashThread
    QTextStream *ts; //this pointer is from QMyHashThread
    QFile file;
    int all;
    int added;
signals:
    void addNewFileEnd(int,int);

public slots:

protected:
    void run();
};

#endif // QADDFILETHREAD_H
