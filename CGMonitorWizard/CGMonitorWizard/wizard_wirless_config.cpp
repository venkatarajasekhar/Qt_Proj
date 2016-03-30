#include "wizard_wirless_config.h"
#include "ui_wizard_wirless_config.h"

wizard_wirless_config::wizard_wirless_config(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wizard_wirless_config)
{
    ui->setupUi(this);
}

wizard_wirless_config::~wizard_wirless_config()
{
    delete ui;
}
