#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QtNetwork>
#include <QFile>
#include <QString>
#include <QByteArray>
#include <QFileDialog>
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include <QUrl>
#include <QList>
#include <QRegExp>
#include <QStringList>
#include <QMouseEvent>
#include <QMimeData>

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
    void start();
    void openFile();
    void startTransfer();
    void displayError(QAbstractSocket::SocketError socketError);
    void updateClientProgress(qint64 numBytes);
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
private:
    Ui::MainWindow *ui;
    bool m_drag;            //whether is drag by mouse right button
    bool m_click;           //whether is click by mouse right button
    QPoint m_dragPosition;  //current cursor position
    QStringList m_fNameList;
    QTcpSocket tcpClient;

    qint64 TotalBytes;
    qint64 bytesWritten;
    qint64 bytesToWrite;
    qint64 loadSize;
    QString m_fileName;
    QFile *localFile;
    QByteArray outBlock;

    int sentFileCount;
};

#endif // MAINWINDOW_H
