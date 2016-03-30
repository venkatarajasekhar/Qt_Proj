#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QCursor>
#include <QString>
#include <QTextStream>
#include <QDesktopWidget>
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

    QString toQString(int num);
    void hideWindow();
    bool isMouseInsideWindow(QPoint p);
    enum{CYC_HIDE_TO_TOP=1, CYC_HIDE_TO_LEFT, CYC_HIDE_TO_BOTTOM, CYC_HIDE_TO_RIGHT};
protected:
    void timerEvent(QTimerEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
private:
    Ui::MainWindow *ui;
    int m_timerId;
    bool m_needToHide;
    int m_theWayToHide;
    int m_movedLength;
    QRect m_screenRect;
};

#endif // MAINWINDOW_H
