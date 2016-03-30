#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->textEdit->setReadOnly(true);
    m_dlg=new ImgDialog();
    m_dlg->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * Connect to database
 */
void MainWindow::databaseConnect()
{
    ui->textEdit->append("Connecting to database...");
    m_db = QSqlDatabase::addDatabase("QMYSQL");
    m_db.setHostName("192.168.1.103");
    m_db.setDatabaseName("cycmonitor");
    m_db.setUserName("congge");
    m_db.setPassword("congpp");
    if(!m_db.open())
        ui->textEdit->append("Connection: Failed!");
    else
        ui->textEdit->append("Connection: OK!");
}

void MainWindow::on_btn_conn_clicked()
{
    this->databaseConnect();
}

void MainWindow::on_btn_choose_clicked()
{
    m_strImage = QFileDialog::getOpenFileName(this,"Please Select image file",
                ".","Image(*.png *.jpg *.bmp *.gif)");
    if (m_strImage.isNull())
        return;
    ui->lineEdit_Jpg->setText(m_strImage);
    ui->textEdit->append(m_strImage);
}

void MainWindow::on_btn_tem_clicked()
{
    QString data=ui->lineEdit_tem->text();
    if(data.length()==0)
        return;
    QString warningId;
    if(data.length()>=2)
        warningId=insertIntoSensor(4);
    qDebug()<<"warning id"<<warningId;
    insertIntoTem(data, warningId);
}

void MainWindow::on_btn_sensor_clicked()
{
    ;
}

/*
 * value: degree
 * warningId: if value is out of range, warningId is set to not null
 *              it's a foreign key to get image from sensor table.
 */
void MainWindow::insertIntoTem(QString value, QString warningId="")
{
    QString sql;
    if(warningId.length()==0)
        sql=QString("insert into temperature(temperature) values(")+value+")";
    else
        sql=QString("insert into temperature(temperature, warning_flag, warning_id) values("+value+", 1,"+warningId+");");
    ui->textEdit->append(sql);
    QSqlQuery query;
    query.prepare(sql);
    if(!query.exec())
        ui->textEdit->append(query.lastError().text());
    else
        ui->textEdit->append(query.value(0).toString());
}

/*
 * Insert a new row into sensor table
 * @warningFlag: necessary, point out the sensor
 */
QString MainWindow::insertIntoSensor(int warningFlag)
{
    m_strImage=ui->lineEdit_Jpg->text();
    //read image from file
    QByteArray data;
    QString path = m_strImage;
    if(m_strImage.length()==0)
        return 0;
    QFile* file=new QFile(path);
    file->open(QIODevice::ReadOnly);
    data = file->readAll();
    file->close();

    //store image data to variant
    QVariant var(data);
    QString sql = QString("insert into sensor(warning_flag, jpg) values(")+(warningFlag+'0')+", ?)";
    QSqlQuery query;
    query.prepare(sql);

    //bind image value, it will automatically replace the '?' in the sql statement
    query.addBindValue(var);
    if(!query.exec())
        ui->textEdit->append(query.lastError().text());
    else
        ui->textEdit->append("Insert: OK!");

    //return the last id from sensor table, give it to the temperature table
    sql="select max(id) from sensor;";
    query.clear();
    query.prepare(sql);
    if(!query.exec())
        ui->textEdit->append(query.lastError().text());
    else
    {
        while(query.next())
        {
            if(query.isNull(0)==false)
                return query.value(0).toString();
        }
    }
    return "";
}

/*
 * Get the image in sensor table
 * @id: the primary key of sensor table
 */
QPixmap MainWindow::getPixmapFromTable(QString id)
{
    QString sql="select jpg from sensor where id=";
    sql+=id;
    ui->textEdit->append(sql);

    QSqlQuery query;
    query.prepare(sql);
    if(!query.exec())
        ui->textEdit->append(query.lastError().text());
    else
    {
        while (query.next())
        {
            if (query.isNull(0) == false)
            {
                QPixmap photo;
                photo.loadFromData(query.value(0).toByteArray(), "PNG");
                ui->textEdit->append("Get Image: OK!");
                return photo;
            }
        }
    }
    return QPixmap();
}

void MainWindow::on_btn_getImg_clicked()
{
    QString id=ui->lineEdit_id->text();
    if(id.length()==0)
        return;
    m_dlg->setImage(getPixmapFromTable(id));
    m_dlg->show();
}
