#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
#include <QUrl>
#include <QString>
#include <QProcess>
#include <QDesktopServices>
#include <QDebug>
#include <QMouseEvent>
#include <QMenu>
#include <QAction>
#include "cycthread.h"

class MyButton : public QPushButton
{
    Q_OBJECT
public:
    MyButton();
    virtual ~MyButton();
    void setExeFileName(QString filename);
    QString getExeFileName();
public slots:
    void executeExternalFile();
    void markRunning();
signals:
    void NoMoreClient();
private:
    int m_clientNum;
    QString m_fileName;
    CYCThread *m_thread;
};

#endif // MYBUTTON_H
