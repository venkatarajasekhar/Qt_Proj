#include "cycthread.h"

CYCThread::CYCThread(QObject *parent) :
    QThread(parent)
{
}

CYCThread::~CYCThread()
{
    p->close();
    delete p;
}

void CYCThread::setFilename(const QString &filename)
{
    this->m_fileName=filename;
}

void CYCThread::run()
{
    /*
     * Why make p a global  variable?
     * Cause we need a new process won't close when main process exit
     */
    QString diskflag, filepath, filename;
    diskflag=m_fileName.left(2);
    diskflag.push_front("cmd /C ");

    filepath=m_fileName.left(m_fileName.lastIndexOf('\\'))+"\"";
    filepath.push_front(" && cd \"");

    filename=m_fileName.right(m_fileName.length()-m_fileName.lastIndexOf('\\')-1)+"\"";
    filename.push_front(" && \"");

    qDebug()<<diskflag+filepath+filename;
    p=new QProcess();
    //
    p->start(diskflag+filepath+filename);
    p->waitForFinished();
    //
}
