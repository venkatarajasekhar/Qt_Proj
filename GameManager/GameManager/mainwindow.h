#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QStringList>
#include <QPushButton>
#include <QTextStream>
#include <QMouseEvent>
#include <QRegExp>
#include <QDragEnterEvent>
#include <QUrl>
#include <QMimeData>
#include <QMessageBox>
#include <QProcess>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QIconEngine>
#include <QCoreApplication>
#include <QFileDialog>
#include <QLibrary>
#include <QDesktopWidget>
#include "mybutton.h"

#include <QtWinExtras/QtWin>
#include <shellapi.h>
#include <commctrl.h>
#include <windows.h>
#include <commoncontrols.h>

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
    void addButton(QString filename);
    QPixmap getIcon(QString filename);
    bool pixmapIsOnly48Bit(QPixmap pixmap);
    bool isMouseInsideWindow(QPoint p);
    enum{CYC_NOT_HIDE, CYC_HIDE_TO_TOP, CYC_HIDE_TO_LEFT, CYC_HIDE_TO_RIGHT};
protected:
    void mouseReleaseEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    void closeEvent(QCloseEvent *e);
    //    void contextMenuEvent(QContextMenuEvent *event);
    void timerEvent(QTimerEvent *e);
private slots:
    void deleteButtonByName(QString filename);
    void on_btn0_clicked();
    void deleteButtonByMousePos();

private:
    Ui::MainWindow *ui;
    QList<MyButton*> btnList;   //all pointer associate with the button
    int m_row;              //current row of the gridLayout
    bool m_drag;            //whether is drag by mouse right button
    bool m_click;           //whether is click by mouse right button
    QPoint m_dragPosition;  //current cursor position
    QPoint m_mouseClickedPoint; //current right mouse clicked position
    QFile m_file;           //handle of config.ini
    QStringList m_strList;  //all file name
    QAction *m_actionDelete;
    QAction *m_actionExit;
    QAction *m_actionAdd;
    QMenu *m_menu;


    int m_timerId;          //timer to get cursor pos
    int m_theWayToHide;     //hide to top? left? right? bottom?
    int m_pixToMove;        //
    bool m_windowIsHidden;
    QRect m_screenRect;     //screen rect
};

#endif // MAINWINDOW_H
