#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setMouseTracking(true);
    ui->setupUi(this);
    m_screenRect=QApplication::desktop()->availableGeometry();
    ui->label_geo_x->setText(toQString(m_screenRect.width()));
    ui->label_geo_y->setText(toQString(m_screenRect.height()));
    m_timerId=startTimer(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *e)
{
    if(e->timerId()==m_timerId)
    {
        ui->label_x->setText(toQString(QCursor::pos().rx()));
        ui->label_y->setText(toQString(QCursor::pos().ry()));
        ui->label_pos_x->setText(toQString(this->geometry().x()));
        ui->label_pos_y->setText(toQString(this->geometry().y()));
        if(isMouseInsideWindow(QCursor::pos()))
            ui->label_info->setText("Inside");
        else
            ui->label_info->setText("Outside");
    }
}

/*
 * Convert integer to QString
 */
QString MainWindow::toQString(int num)
{
    QString tmp;
    QTextStream(&tmp)<<num;
    return tmp;
}

/*
 * whether the mouse is on the window
 */
bool MainWindow::isMouseInsideWindow(QPoint p)
{
    int left=this->geometry().x();
    int right=left+this->width();
    int top=this->geometry().y();
    int bottom=top+this->height();
    if(p.rx()>=left && p.rx()<=right)
        if(p.ry()>=top && p.ry()<=bottom)
            return true;
    return false;
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    this->move(e->screenPos().x()-200, e->screenPos().y()-200);
    if(e->screenPos().x()>=m_screenRect.width()-1)  //touch the right side
    {
        this->move(e->screenPos().x()-this->geometry().width(), e->screenPos().y()-200);
        ui->label_info1->setText("Touch right side");
    }else
    {
        ui->label_info1->setText("Moving...");
    }
}

void MainWindow::hideWindow()
{
    if(m_needToHide)
    {
        ;
    }
}
