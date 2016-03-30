#include "wizard_wired_config.h"
#include "ui_wizard_wired_config.h"

wizard_wired_config::wizard_wired_config(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wizard_wired_config)
{
    ui->setupUi(this);
}

wizard_wired_config::~wizard_wired_config()
{
    delete ui;
}
