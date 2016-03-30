#include "cycthread.h"

CYCThread::CYCThread(QObject *parent) :
    QThread(parent)
{
}

CYCThread::~CYCThread()
{
}

/*
 * filename: just the name(like: test.txt), should not include the path
 */
void CYCThread::setFilename(const QString &filename)
{
    this->m_fileName=filename;
}

/*
 *
 *
 */
void CYCThread::setAppMap(QMap<QString, QString> &map)
{
    if(!map.isEmpty())
        this->appMap=&map;
}

void CYCThread::run()
{
    QString application, prefix;
    prefix=m_fileName.right(m_fileName.length()-m_fileName.lastIndexOf('.')-1);
    prefix=prefix.toLower();
    application.push_back("cmd /C \"");
    if(appMap->contains(prefix))
    {
        application.push_back(appMap->value(prefix));
        qDebug()<<application+"\" \""+m_fileName+"\"";
        QProcess *p=new QProcess();
        p->start(application+"\" \""+m_fileName+"\"");
        p->waitForFinished();
        delete p;
    }
}
