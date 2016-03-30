#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegExp>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkCookieJar>
#include <QTextCodec>
#include <QFile>
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

    void getAccessCode();
    void getThreeKind();
protected:
    void timerEvent(QTimerEvent *e);
private slots:
    void on_btnLogin_clicked();

    void replyFinished(QNetworkReply *reply);
    void on_btnTX_clicked();

    void on_btnPE_clicked();

    void on_btnYX_clicked();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *manager;
    QString html;
    enum status{FirstAccess, Login, NomalLink, Others};
    enum courseKind{PE, TX, YX};
    int curStatus;
    int fangshuaId;
    QString accessCode;
    QUrl url;
    QUrl SubUrl[3];
    QString tiyuke;
    QString yuanxi;
    QString tongxuan;
    QString id;
    QString pwd;
    QNetworkCookieJar *cookie;
};

#endif // MAINWINDOW_H
