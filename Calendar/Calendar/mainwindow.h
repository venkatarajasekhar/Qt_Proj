#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextCharFormat>
#include <QDate>
#include <QSettings>
#include <QStringList>
#include <QDebug>
#include <QTextStream>
#include <QResizeEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void SetDateTextFormat(const QDate &date, Qt::GlobalColor color);
    QString DateToStrig();
    void resizeEvent ( QResizeEvent * event );
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
public slots:
    void SetDateChecked(QDate date);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    void InitCalendar(const QSettings& settings);

private:
    Ui::MainWindow *ui;
    QSettings m_Settings;
    QDate m_curDate;
};

#endif // MAINWINDOW_H
