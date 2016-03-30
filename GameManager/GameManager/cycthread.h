#ifndef CYCTHREAD_H
#define CYCTHREAD_H

#include <QThread>
#include <QProcess>
#include <QString>
#include <QDebug>

class CYCThread : public QThread
{
    Q_OBJECT
public:
    explicit CYCThread(QObject *parent = 0);
    virtual ~CYCThread();
    void setFilename(const QString &filename);
signals:
    void processExit();
public slots:

protected:
    void run();
private:
    QProcess *p;
    QString m_fileName;

};

#endif // CYCTHREAD_H
