#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cookie=new QNetworkCookieJar();
    manager=new QNetworkAccessManager(this);
    manager->setCookieJar(cookie);
    connect(manager,SIGNAL(finished(QNetworkReply*)),
                this,SLOT(replyFinished(QNetworkReply*)));
    html="";
    curStatus=FirstAccess;
    accessCode="";
    ui->editUrl->setText("http://202.116.193.51/default_ldap.aspx");
    ui->editId->setText("20111003809");
    ui->editPwd->setText("719142");
    this->getThreeKind();
}

MainWindow::~MainWindow()
{
    delete manager;
    delete ui;
}

/*
 * 1. access homepage and get the access code, something like that
 * <input type="hidden" name="__VIEWSTATE" value="
 * dDw4MTI3MTI0O3Q8O2w8aTwxPjs+O2w8dDw7bDxpPDc+Oz
 * 47bDx0PHA8O3A8bDxvbmNsaWNrOz47bDx3aW5kb3cuY2xvc2
 * UoKVw7Oz4+Pjs7Pjs+Pjs+Pjs+PvyEpJjZxJWcyW8kRJ7IEDWInDI=">
 *
 * 2. Login
 */
void MainWindow::getAccessCode()
{
    QRegExp rx("(<input type=\"hidden\" name=\"__VIEWSTATE\" value=\")(.*)(\")");
    rx.setMinimal(true);
    int pos=rx.indexIn(html);
    if(pos>-1)
    {
        accessCode=rx.cap(2);
        ui->textInfo->setText("AccessCode: "+accessCode.toHtmlEscaped());
    }else
    {
        ui->textInfo->setText("Cannot connect to server!");
    }
    id = ui->editId->text();
    pwd = ui->editPwd->text();
    QString reqData="__VIEWSTATE=dDw4MTI3MTI0O3Q8O2w8aTwxPjs%2BO2w8dDw7bDxpPDc%2BOz47bDx0PHA8O3A8bD"+
            QString("xvbmNsaWNrOz47bDx3aW5kb3cuY2xvc2UoKVw7Oz4%2BPjs7Pjs%2BPjs%2BPjs%2BPvyEpJjZxJWcyW8kRJ7IEDWInDI%3D")
            +"&tbYHM="+id+"&tbPSW="+pwd+"&Button1=+%B5%C7+%C2%BC+";
    //QString reqData="__VIEWSTATE="+accessCode.toHtmlEscaped()+"&tbYHM="+id+"&tbPSW="+pwd+"&Button1=+%B5%C7+%C2%BC+";
    //qDebug()<<reqData;
    QNetworkRequest request;
    request.setUrl(url);
    request.setAttribute(QNetworkRequest::RedirectionTargetAttribute,QUrl("http://202.116.193.51/xs_main_zzjk.aspx?xh=20111003809"));
    request.setRawHeader("Host","202.116.193.51");
    request.setRawHeader("Connection","keep-alive");
    request.setRawHeader("Content-Length","229");
    request.setRawHeader("Cache-Control","max-age=0");
    request.setRawHeader("Accept","text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8");
    request.setRawHeader("Origin","http://202.116.193.51");
    request.setRawHeader("User-Agent","Mozilla/5.0 (Windows NT 6.3) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/35.0.1916.114 Safari/537.36");
    request.setRawHeader("Content-Type","application/x-www-form-urlencoded");
    request.setRawHeader("Referer","http://202.116.193.51/default_ldap.aspx");
    request.setRawHeader("Accept-Encoding","gzip,deflate,sdch");
    request.setRawHeader("Accept-Language","zh-CN,zh;q=0.8,en;q=0.6,zh-TW;q=0.4");
    request.setRawHeader("Cookie","ASP.NET_SessionId=s0na0dujrhownj55oq14s455");
    //qDebug()<<request.rawHeaderList();
    ui->textInfo->append("登录中...");
    curStatus=Login;
    QByteArray postdata;
    postdata=reqData.toLatin1();
    //qDebug()<<postdata;
    manager->post(request,postdata);
}
/*
 * Login button
 */
void MainWindow::on_btnLogin_clicked()
{
    curStatus=FirstAccess;
    QString urlstr = ui->editUrl->text();
    url.setUrl(urlstr);
    //qDebug()<<word;
    manager->get(QNetworkRequest(url));
}

void MainWindow::replyFinished(QNetworkReply* reply)
{
    QTextCodec *codec = QTextCodec::codecForName("GB2312");
    html = codec->toUnicode(reply->readAll());
    switch(curStatus)
    {
    case FirstAccess:
        ui->textInfo->append(QString("5秒防刷等待..."));
        fangshuaId=startTimer(8000);
        break;
    case Login:
        //qDebug()<<html;
        //ui->textInfo->append(html);
        //getThreeKind();
        curStatus=NomalLink;
        manager->get(QNetworkRequest(QUrl("http://202.116.193.51/xs_main_zzjk.aspx?xh="+id)));
        break;
    case NomalLink:
        this->getThreeKind();
        break;
    default:
        break;
    }
}

void MainWindow::timerEvent(QTimerEvent *e)
{
    if(e->timerId()==fangshuaId)
    {
        getAccessCode();
        killTimer(fangshuaId);
    }
}
/*
 * get three kind of lesson, like that
 * <a href="xf_xsyxxxk.aspx?xh=20111003809&amp;xm=陈诒聪&amp;gnmkdm=N121106"
 * target="zhuti" onclick="GetMc('院系选修课');">院系选修课</a>
 * <LI><A onclick="GetMc('学生选课');" href="http://202.116.195.103/xsxk.aspx?xh=20111003809&amp;xm=陈诒聪&amp;gnmkdm=N121101" target=zhuti>学生选课</A>
 * <LI><A onclick="GetMc('选体育课');" href="http://202.116.195.103/xstyk.aspx?xh=20111003809&amp;xm=陈诒聪&amp;gnmkdm=N121102" target=zhuti>选体育课</A>
 * <LI><A onclick="GetMc('院系选修课');" href="http://202.116.195.103/xf_xsyxxxk.aspx?xh=20111003809&amp;xm=陈诒聪&amp;gnmkdm=N121106" target=zhuti>院系选修课</A>
 * <LI><A onclick="GetMc('通选课');" href="http://202.116.195.103/xf_xsqxxxk.aspx?xh=20111003809&amp;xm=陈诒聪&amp;gnmkdm=N121109" target=zhuti>通选课</A></LI>
 */
void MainWindow::getThreeKind()
{
    QFile file("q.html");
    file.open(QIODevice::ReadOnly);
    html=QString(file.readAll());
    QRegExp rx("href=.*aspx\\?xh=.*N[0-9]{6}");
    //QRegExp rx("<span class='down'>.*</span>");
    rx.setMinimal(true);
    //rx.setCaseSensitivity(Qt::CaseInsensitive);
    int pos = 0, i=0;
    while ((pos = rx.indexIn(html, pos)) != -1)
    {
        QString str=rx.cap(1);
        ui->textInfo->append(str);
        //SubUrl[i++]=QUrl(str);
        pos += rx.matchedLength();
    }
    if(i==0)
    {
        ui->textInfo->append("<font color='#ff0000'>不是选课时间！</font>");
    }
    //ui->textInfo->append(html);
//    QFile file("q.html");
//    file.open(QIODevice::WriteOnly);
//    file.write(html.toUtf8());
    file.close();
}

void MainWindow::on_btnTX_clicked()
{
    //SubUrl[TX]
    qDebug()<<SubUrl[TX];
}

void MainWindow::on_btnPE_clicked()
{
    //SubUrl[PE]
    qDebug()<<SubUrl[PE];
}

void MainWindow::on_btnYX_clicked()
{
    //SubUrl[YX]
    qDebug()<<SubUrl[YX];
}
