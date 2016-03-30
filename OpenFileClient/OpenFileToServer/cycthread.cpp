#include "cycthread.h"

CYCThread::CYCThread(QObject *parent, QString serverip, QStringList filenames) :
    QThread(parent)
{
    this->m_fileName=filenames;
    m_tcpClient=new QTcpSocket();
    m_tcpClient->connectToHost(serverip, 8086);
    connect(m_tcpClient, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(printError(QAbstractSocket::SocketError)));
    connect(m_tcpClient, SIGNAL(connected()), this, SLOT(start()));
}

CYCThread::~CYCThread()
{
    delete m_tcpClient;
}


void CYCThread::run()
{
    qDebug()<<"RUN";
    foreach(QString fName, m_fileName)
    {
        QString name=fName.right(fName.length()-fName.lastIndexOf('/')-1);
        qDebug()<<name;
        m_tcpClient->write(name.toLatin1());
        m_tcpClient->flush();
        QFile file;
        file.setFileName(fName);
        if(file.open(QIODevice::ReadOnly))
        {
            QByteArray bytes=file.readAll();
            qDebug()<<bytes.length();
            m_tcpClient->write(bytes);
            m_tcpClient->flush();
        }
        file.close();
    }

}

void CYCThread::printError(QAbstractSocket::SocketError e)
{
    qDebug()<<"ERROR" << e;
}
