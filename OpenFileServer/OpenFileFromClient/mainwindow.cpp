#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    setAttribute(Qt::WA_TranslucentBackground, true);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);

    TotalBytes = 0;
    bytesReceived = 0;
    fileNameSize = 0;
    m_thread=new CYCThread();
    localFile=new QFile();

    appList["txt"]="D:\\Program Files\\Sublime Text 3\\sublime_text.exe";
    m_thread->setAppMap(appList);
    m_tcpServer=new QTcpServer();
    connect(m_tcpServer, SIGNAL(newConnection()), this, SLOT(acceptConnection()));

    ui->setupUi(this);
    start();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_tcpServer;
    delete m_thread;
}


void MainWindow::start()
{
    bytesReceived = 0;
    while(!m_tcpServer->isListening()&&!m_tcpServer->listen(QHostAddress::Any,8086))
    {
        QMessageBox::StandardButton ret = QMessageBox::critical(this,
                                                                tr("circle"),
                                                                tr("can not test: %1")
                                                                .arg(m_tcpServer->errorString()),
                                                                QMessageBox::Retry|
                                                                QMessageBox::Cancel);
        if(ret == QMessageBox::Cancel)
            return;
    }
}



void MainWindow::acceptConnection()
{
    qDebug()<<"accept connection";
    bytesReceived=0;
    TotalBytes = 0;
    fileNameSize=0;
    fileName.clear();
    clientConnection = m_tcpServer->nextPendingConnection();
    connect(clientConnection,SIGNAL(readyRead()),
            this,SLOT(updateServerProgress()));
    connect(clientConnection,SIGNAL(error(QAbstractSocket::SocketError)),
            this,SLOT(displayError(QAbstractSocket::SocketError)));
    //m_tcpServer->close();
}



void MainWindow::displayError(QAbstractSocket::SocketError socketError)
{
    if(socketError == QTcpSocket::RemoteHostClosedError)
        return;
    QMessageBox::information(this,tr("NetWork"),
                             tr("generate the following error:%1.")
                             .arg(m_tcpServer->errorString()));
}



void MainWindow::updateServerProgress()
{
    QDataStream in(clientConnection);
    in.setVersion(QDataStream::Qt_4_7);
    qDebug()<<"update server progress";

    // recv start, get total bytes, file name size and file name first
    if(bytesReceived <= sizeof(qint64)*2)
    {
        if((clientConnection->bytesAvailable() >= sizeof(qint64)*2)&&(fileNameSize==0))
        {
            in>>TotalBytes>>fileNameSize;
            qDebug()<<"total size"<<TotalBytes<<"file name size"<<fileNameSize;
            bytesReceived += sizeof(qint64)*2;
        }

        if((clientConnection->bytesAvailable()>=fileNameSize)&&(fileName.isEmpty()))
        {
            in>>fileName;
            qDebug()<<"filename "<<fileName;
            bytesReceived += fileNameSize;
            localFile->setFileName(fileName);
            int i=0;
            QString name=fileName.left(fileName.indexOf('.'));
            QString prefix=fileName.right(fileName.length()-fileName.lastIndexOf('.')-1);
            while(localFile->exists())
            {
                fileName="";
                QTextStream(&fileName)<<name<<"["<<(i++)<<"]."<<prefix;
                qDebug()<<"filename "<<fileName;
                localFile->setFileName(fileName);
            }
            if(!localFile->open(QFile::WriteOnly))
            {
                QMessageBox::warning(this,tr("Application"),
                                     tr("can not read file %1:\n%2.")
                                     .arg(fileName)
                                     .arg(localFile->errorString()));
                return;
            }
        }else
        {
           return;
        }
    }

    // receiving
    if(bytesReceived<TotalBytes)
    {
        bytesReceived += clientConnection->bytesAvailable();
        qDebug()<<"write block "<<bytesReceived;
        inBlock = clientConnection->readAll();
        localFile->write(inBlock);
        inBlock.resize(0);
    }

    // recv ok
    if(bytesReceived == TotalBytes)
    {
        qDebug()<<"byte recv"<<bytesReceived;
        clientConnection->flush();
        clientConnection->close();
        localFile->flush();
        localFile->close();
        m_thread->setFilename(fileName);
        m_thread->start();
        QApplication::restoreOverrideCursor();
    }
}


/*
 * These 3 functions below are used to respond to the users' drag on the window
 */
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_drag = true;
        m_dragPosition = event->globalPos() - this->pos();
        event->accept();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (m_drag && (event->buttons() == Qt::LeftButton))
    {
        move(event->globalPos() - m_dragPosition);
        event->accept();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    m_drag=false;
}

