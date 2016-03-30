#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QtSql/QSqlDatabase>
#include <QSqlResult>
#include <QSqlQuery>
#include <QSqlError>
#include <QFileDialog>
#include <QDir>
#include <QVariant>
#include "imgdialog.h"
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

    void databaseConnect();
    void insertIntoTem(QString value, QString warningId);
    QString insertIntoSensor(int warningFlag);
    QPixmap getPixmapFromTable(QString id);
private slots:
    void on_btn_conn_clicked();
    void on_btn_choose_clicked();
    void on_btn_tem_clicked();
    void on_btn_sensor_clicked();

    void on_btn_getImg_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase m_db;
    QString m_strImage;
    ImgDialog *m_dlg;
};

#endif // MAINWINDOW_H
