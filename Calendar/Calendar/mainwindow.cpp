#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_Settings("config.ini", QSettings::IniFormat),
    m_curDate()
{
    ui->setupUi(this);
    connect(ui->calendarWidget, SIGNAL(clicked(QDate)), this, SLOT(SetDateChecked(QDate)));
//    connect(this, SIGNAL())
    m_Settings.setIniCodec("UTF-8");
    InitCalendar(m_Settings);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetDateChecked(QDate date)
{
    m_curDate = date;
    ui->label->setText(DateToStrig().replace('H', '-'));
}

void MainWindow::SetDateTextFormat(const QDate &date, Qt::GlobalColor color)
{
    QTextCharFormat t;
    t.setBackground(color);
    ui->calendarWidget->setDateTextFormat(date, t);
    ui->calendarWidget->update();
}

void MainWindow::InitCalendar(const QSettings &settings)
{
    QStringList list = settings.allKeys();
    QSize size;
    for(size_t i=0; i<list.size(); ++i)
    {
        QString dateStr = list[i];
        if(dateStr == "width")
            size.setWidth(settings.value(dateStr).toInt());
        else if(dateStr == "height")
            size.setHeight(settings.value(dateStr).toInt());
        else
        {
            QStringList ymd = dateStr.split('H');
            QDate date;
            date.setDate(ymd[2].toInt(), ymd[0].toInt(), ymd[1].toInt());
            qDebug()<<date<<settings.value(list[i]).toInt();
            if(settings.value(list[i]).toInt() == 1)
                SetDateTextFormat(date, Qt::green);
            else
                SetDateTextFormat(date, Qt::gray);
        }
    }
    this->resize(size);
}

QString MainWindow::DateToStrig()
{
    QString year, month, day;
    QTextStream(&year)<<m_curDate.year();
    QTextStream(&month)<<m_curDate.month();
    QTextStream(&day)<<m_curDate.day();
    QString strDate=month+"H"+day+"H"+year;
    qDebug()<<strDate;
    return strDate;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    qDebug()<<event->size();
    m_Settings.setValue("width", event->size().width());
    m_Settings.setValue("height", event->size().height());
    event->accept();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_C && (event->modifiers() & Qt::ControlModifier))
    {
        on_pushButton_3_clicked();
        event->accept();
    }else if(event->key() == Qt::Key_S && (event->modifiers() & Qt::ControlModifier))
    {
        on_pushButton_clicked();
        event->accept();
    }else if(event->key() == Qt::Key_Z && (event->modifiers() & Qt::ControlModifier))
    {
        on_pushButton_2_clicked();
        event->accept();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->type() == QEvent::MouseButtonDblClick)
    {
        on_pushButton_clicked();
        event->accept();
    }
}

void MainWindow::on_pushButton_clicked()
{
    QDate date;
    if(m_curDate != date)
    {
        SetDateTextFormat(m_curDate, Qt::green);
        m_Settings.setValue(DateToStrig(), 1);
    }
    ui->calendarWidget->setFocus();
}

void MainWindow::on_pushButton_2_clicked()
{
    QDate date;
    if(m_curDate != date)
    {
        SetDateTextFormat(m_curDate, Qt::white);
    }
    m_Settings.remove(DateToStrig());
    ui->calendarWidget->setFocus();
}

void MainWindow::on_pushButton_3_clicked()
{
    QDate date;
    if(m_curDate != date)
    {
        SetDateTextFormat(m_curDate, Qt::gray);
        m_Settings.setValue(DateToStrig(), 2);
    }
    ui->calendarWidget->setFocus();
}
