#include "imgdialog.h"
#include "ui_imgdialog.h"

ImgDialog::ImgDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImgDialog)
{
    ui->setupUi(this);
}

ImgDialog::~ImgDialog()
{
    delete ui;
}

void ImgDialog::setImage(QPixmap pixmap)
{
    ui->label->setPixmap(pixmap);
}

void ImgDialog::closeEvent(QCloseEvent *e)
{
    this->hide();
    return;
}
