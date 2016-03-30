#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QTextStream>
#include <QMouseEvent>
//#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QString byteToKMG(long long cur, long long old);
protected:
    void timerEvent(QTimerEvent *e);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *);
public slots:
    void calNetRate();
private:
    Ui::MainWindow *ui;
    QProcess *process;
    int timerId;
    long long oldUpBytes;
    long long oldDownBytes;
    long long curUpBytes;
    long long curDownByte;

    bool m_drag;
    QPoint m_dragPosition;
    QPoint m_dlgPos;
};

#endif // MAINWINDOW_H
