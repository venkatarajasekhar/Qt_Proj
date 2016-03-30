#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    process(new QProcess),
    timerId(0),
    oldDownBytes(0),
    oldUpBytes(0),
    curDownByte(0),
    curUpBytes(0)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground, true);
    setAttribute(Qt::WA_DeleteOnClose, true);
    setAttribute(Qt::WA_QuitOnClose, true);
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowFlags(Qt::FramelessWindowHint|Qt::Tool|Qt::WindowStaysOnTopHint);
    timerId=startTimer(1000);
    connect(process,SIGNAL(readyReadStandardOutput()),this, SLOT(calNetRate()));
}

MainWindow::~MainWindow()
{
    delete process;
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *e)
{
    if(e->timerId()==timerId)
    {
        process->start("cmd",QStringList()<<"/c"<<"netstat -e");
        //process->start("netstat",QStringList()<<"/c"<<"-e");
    }
}

void MainWindow::calNetRate()
{
    QString strTemp=QString::fromLocal8Bit(process->readAllStandardOutput());
    //qDebug()<<strTemp;
    QString up,down;
    QRegExp rx("(\\s)([0-9]+)(\\s)");
    int pos = 0;
    if((pos = rx.indexIn(strTemp, pos)) != -1)
    {
       up=rx.cap(2);
        pos += rx.matchedLength();
    }
    if((pos = rx.indexIn(strTemp, pos)) != -1)
    {
       down=rx.cap(2);
    }
    //qDebug()<<"Up:"<<up<<" Down:"<<down;
    if(up=="" || down=="")
        return;
    curUpBytes=up.toLongLong();
    curDownByte=down.toLongLong();
    if(oldDownBytes!=0 && oldUpBytes!=0)
    {
        ui->up->setText(byteToKMG(curUpBytes, oldUpBytes));
        ui->down->setText(byteToKMG(curDownByte, oldDownBytes));
    }
    oldDownBytes=curDownByte;
    oldUpBytes=curUpBytes;
}

QString MainWindow::byteToKMG(long long cur, long long old)
{
    QString res;
    int tmp=cur-old;
    //qDebug()<<"cur"<<cur<<"old"<<old<<"tmp"<<tmp;
    if(tmp/(1024*1024)>0)
    {
        int mb=tmp/(1024*1024);
        if(mb>15)
            mb=0;
        QTextStream(&res)<<mb<<"MB/s";

    }
    else if(tmp/(1024)>0)
        QTextStream(&res)<<tmp/1024<<"KB/s";
    else
        QTextStream(&res)<<tmp<<"B/s";
    return res;
}

/*
 * These 3 function below is used to respond to the users' drag on the window
 */
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        //qDebug()<<"oh no";
        m_drag = true;
        m_dragPosition = event->globalPos() - this->pos();
        event->accept();
    }else if(event->button() == Qt::MiddleButton)
    {
        emit close();
    }
}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    //qDebug()<<"oh no";
    if (m_drag && (event->buttons() == Qt::LeftButton))
    {
        move(event->globalPos() - m_dragPosition);
        event->accept();
    }
}
void MainWindow::mouseReleaseEvent(QMouseEvent *)
{
    m_drag = false;
}

