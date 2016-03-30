#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    setAttribute(Qt::WA_TranslucentBackground, true);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
    ui->setupUi(this);
    setAcceptDrops(true);

    loadSize = 4*1024;
    TotalBytes = 0;
    bytesWritten = 0;
    bytesToWrite = 0;
    sentFileCount=0;

    localFile = new QFile();

    connect(&tcpClient,SIGNAL(connected()),this,SLOT(startTransfer()));
    connect(&tcpClient,SIGNAL(bytesWritten(qint64)),this,SLOT(updateClientProgress(qint64)));
    connect(&tcpClient,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
    //connect(&tcpClient, SIGNAL(disconnected()), this, SLOT(start()));
}

MainWindow::~MainWindow()
{
    delete localFile;
    delete ui;
}

/*
 * Drag enter
 */
void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    qDebug()<<"Drag enter";
    if(event->mimeData()->hasUrls())
    {
        event->accept();
    }else
    {
        event->ignore();
    }
}


/*
 * after accept a file, add new button to the ui
 */
void MainWindow::dropEvent(QDropEvent *event)
{
    QList<QUrl> urls = event->mimeData()->urls();
    if(urls.isEmpty())
        return;
    m_fNameList.clear();
    this->m_fileName=urls.at(0).toLocalFile();
     m_fNameList.append(m_fileName);
    foreach(QUrl url, urls)
    {
        QString filename = url.toLocalFile();
        //filename=filename.replace("/", "\\");
        qDebug()<<filename;
        //Whether already exist
        if(!m_fNameList.contains(filename))
            m_fNameList.append(filename);
    }
    this->start();
}


/*
 *
 */
void MainWindow::startTransfer()
{
    qDebug()<<"start transfer";
    ++sentFileCount;
    localFile->setFileName(m_fileName);
    if(!localFile->open(QFile::ReadOnly))
    {
        QMessageBox::warning(this,tr("Application"),
                             tr("can not open %1:\n%2.")
                             .arg(m_fileName)
                             .arg(localFile->errorString()));
        return;
    }
    TotalBytes = localFile->size();
    QDataStream sendOut(&outBlock,QIODevice::WriteOnly);
    sendOut.setVersion(QDataStream::Qt_4_7);
    QString currentFile = m_fileName.right(m_fileName.size()-
                                         m_fileName.lastIndexOf('/')-1);
    sendOut<<qint64(0)<<qint64(0)<<currentFile;
    TotalBytes += outBlock.size();
    sendOut.device()->seek(0);
    sendOut<<TotalBytes<<qint64(outBlock.size()- sizeof(qint64)*2);
    bytesToWrite = TotalBytes - tcpClient.write(outBlock);
    qDebug()<<"file: "<<currentFile<<"size: "<<TotalBytes-outBlock.size();
    outBlock.resize(0);
}

void MainWindow::displayError(QAbstractSocket::SocketError socketError)
{
    if(socketError == QTcpSocket::RemoteHostClosedError)
        return;
    QMessageBox::warning(this,tr("NetWork"),
                             tr("generate the following error:%1.")
                             .arg(tcpClient.errorString()));
    tcpClient.close();
    QApplication::restoreOverrideCursor();
}

void MainWindow::openFile()
{
    m_fileName = QFileDialog::getOpenFileName(this);
    if (!m_fileName.isEmpty())
        ;
}


void MainWindow::start()
{
    bytesWritten = 0;
    tcpClient.connectToHost(QHostAddress("127.0.0.1"),8086);
}


void MainWindow::updateClientProgress(qint64 numBytes)
{
    bytesWritten += (int)numBytes;
    if(bytesToWrite > 0)
    {
        if(bytesToWrite > 0)
        {
            outBlock = localFile->read(qMin(bytesToWrite,loadSize));
            bytesToWrite -= (int)tcpClient.write(outBlock);
            outBlock.resize(0);
        }else
        {
            localFile->close();
            if(sentFileCount<m_fNameList.size())
            {
                m_fileName=m_fNameList.at(sentFileCount);
                start();
            }else
            {
                m_fNameList.clear();
                sentFileCount=0;
            }
        }
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
