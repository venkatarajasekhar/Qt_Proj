#include "wizard_mainpage.h"
#include "ui_wizard_mainpage.h"

wizard_mainpage::wizard_mainpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wizard_mainpage)
{
    ui->setupUi(this);
}

wizard_mainpage::~wizard_mainpage()
{
    delete ui;
}
