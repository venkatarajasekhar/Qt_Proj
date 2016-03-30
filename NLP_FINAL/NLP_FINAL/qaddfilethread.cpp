#include "qaddfilethread.h"

QAddFileThread::QAddFileThread(QObject *parent):
    QThread(parent)
{

}
/*
 * A new thread to add new word to the dictionary,
 * and all new words will store in userdic.txt
 */
void QAddFileThread::run()
{
    QRegExp keyrx("(.*)\\[E\\]");
    QRegExp serx("(\\[L\\].*)");
    QRegExp exrx("(\\[E\\].*)");
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream fs(&file);
        QString key="", ex="",se="", line="";
        while(!fs.atEnd())
        {
            line=fs.readLine();
            all++;
            //keyword
            int pos = keyrx.indexIn(line);
            if(pos>-1)
            {
                key=keyrx.cap(1);
            }else
            {
                //if the line does not contains any keywords skip
                continue;
            }
            //If dic contains the key already, skip
            QHash<QString, QString>::iterator it=dic->find(key);
            if(it!=dic->end())
            {
                continue;
            }
            //sentence
            pos = serx.indexIn(line);
            if(pos>-1)
            {
                se=serx.cap(1);
                line.resize(pos);
            }
            //explain
            pos = exrx.indexIn(line);
            if(pos>-1)
            {
                ex=exrx.cap(1);
            }else
            {
                //if the word dose not have a explanation, skip
                continue;
            }
            added++;
            (*dic)[key]=ex+"\n"+se;
            *ts<<key<<ex<<se<<"\n";
            ts->flush();
            key=""; ex="";se=""; line="";
        }
    }
    file.close();
    //emit a message to tell the main thread(the ui thread), how many words added successfully.
    emit addNewFileEnd(all,added);
}
/*
 * Get the current filename from mainwindow.cpp
 */
void QAddFileThread::setFileName(QString fname)
{
    //qDebug()<<fname;
    file.setFileName(fname);
}
/*
 * Get the dictionary pointer from QMyHashThread, passed by mainwindow.
 */
void QAddFileThread::setDicPointer(QHash<QString, QString>* dic)
{
    this->dic=dic;
}
/*
 * Get the textstream pointer from QMyHashThread, cause when add a new word,
 * you must store it in a file, so that you can reused it next time.
 */
void QAddFileThread::setTextStreamPointer(QTextStream *ts)
{
    this->ts=ts;
}
