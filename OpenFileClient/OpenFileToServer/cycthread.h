#ifndef CYCTHREAD_H
#define CYCTHREAD_H

#include <QThread>
#include <QProcess>
#include <QStringList>
#include <QtNetwork/QTcpSocket>
#include <QDebug>
#include <QFile>
#include <QUrl>

class CYCThread : public QThread
{
    Q_OBJECT
public:
    explicit CYCThread(QObject *parent = 0);
    virtual ~CYCThread();
    //void setFilename(const QStringList &filename);
    explicit CYCThread(QObject *parent, QString serverip, QStringList filenames);
signals:
    void processExit();
public slots:

    void printError(QAbstractSocket::SocketError e);
protected:
    void run();
private:
    QStringList m_fileName;
    QTcpSocket *m_tcpClient;
    QString m_serverIp;
};

#endif // CYCTHREAD_H
