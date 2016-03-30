#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QTcpSocket>
#include <QByteArray>
#include <QHostAddress>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void printError(QAbstractSocket::SocketError err);
protected:
    void timerEvent(QTimerEvent *e);
private:
    Ui::MainWindow *ui;
    QTcpSocket *client;
    int timerId;
};

#endif // MAINWINDOW_H
