#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QMessageBox>
#include <QtNetwork>
#include <QFile>
#include <QApplication>
#include <QDebug>
#include <QObject>
#include <QDataStream>
#include <QMap>
#include <QMouseEvent>
#include "cycthread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void openFile();
public slots:

    void start();
    void displayError(QAbstractSocket::SocketError socketError);
    void updateServerProgress();
    void acceptConnection();
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
private:
    Ui::MainWindow *ui;
    bool m_drag;
    QPoint m_dragPosition;

    QTcpServer *m_tcpServer;
    CYCThread *m_thread;
    QTcpSocket *clientConnection;

    qint64 TotalBytes;
    qint64 bytesReceived;
    qint64 fileNameSize;
    QString fileName;
    QFile *localFile;
    QByteArray inBlock;

    QMap<QString, QString> appList;
};

#endif // MAINWINDOW_H
