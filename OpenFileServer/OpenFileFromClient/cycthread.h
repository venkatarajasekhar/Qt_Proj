#ifndef CYCTHREAD_H
#define CYCTHREAD_H

#include <QThread>
#include <QProcess>
#include <QStringList>
#include <QtNetwork>
#include <QDebug>
#include <QFile>
#include <QUrl>
#include <QMap>

class CYCThread : public QThread
{
    Q_OBJECT
public:
    explicit CYCThread(QObject *parent=NULL);
    virtual ~CYCThread();
    void setFilename(const QString &filename);
    void setAppMap(QMap<QString, QString> &map);
signals:
    void processExit();
public slots:
protected:
    void run();
private:
    QString m_fileName;
    QMap<QString, QString> *appMap;
};

#endif // CYCTHREAD_H
