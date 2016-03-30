#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    client = new QTcpSocket(this);
    client->connectToHost(QHostAddress("192.168.1.100"), 8888);
    connect(client, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(printError(QAbstractSocket::SocketError)));
    timerId=startTimer(1000);
}

void MainWindow::timerEvent(QTimerEvent *e)
{
    if(e->timerId()==timerId)
    {
        QByteArray bytes = client->readAll();
        qDebug()<<bytes.length();
        ui->img->setPixmap(QPixmap::fromImage(QImage::fromData(bytes, "jpg")));
    }
}

void MainWindow::printError(QAbstractSocket::SocketError err)
{
    qDebug()<<"socket error"<<err;
}

MainWindow::~MainWindow()
{
    delete ui;
}
