#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //setAttribute(Qt::WA_TranslucentBackground, true);
    setWindowFlags(Qt::FramelessWindowHint|Qt::Tool|Qt::WindowStaysOnTopHint);
    connect(ui->listView,SIGNAL(doubleClicked(QModelIndex)), this, SLOT(getListText(QModelIndex)));
    //setWindowFlags(Qt::WindowStaysOnTopHint | Qt::X11BypassWindowManagerHint);
    model = new QStringListModel();
}

Dialog::~Dialog()
{
    delete model;
    delete ui;
}

void Dialog::setCandidateText(QStringList listofwords)
{
    listofwords.append("添加到词典...");
    model->setStringList(listofwords);
    ui->listView->setModel(model);
    dlgList=listofwords;
}

void Dialog::setTranText(QStringList list)
{
    model->setStringList(list);
    ui->listView->setModel(model);
    dlgList=list;
}

void Dialog::getListText(QModelIndex index)
{
    if(index.isValid())
    {
        int row=index.row();
        qDebug()<<dlgList.at(row);
        emit listDoubleClick(dlgList.at(row));
    }
}

