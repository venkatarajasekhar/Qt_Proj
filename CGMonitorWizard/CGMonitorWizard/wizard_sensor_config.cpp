#include "wizard_sensor_config.h"
#include "ui_wizard_sensor_config.h"

wizard_sensor_config::wizard_sensor_config(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wizard_sensor_config)
{
    ui->setupUi(this);
}

wizard_sensor_config::~wizard_sensor_config()
{
    delete ui;
}
