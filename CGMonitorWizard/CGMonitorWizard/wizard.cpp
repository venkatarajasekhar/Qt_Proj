#include "wizard.h"
#include "ui_wizard.h"
#include "wizard_network_config.h"

Wizard::Wizard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Wizard)
{
    ui->setupUi(this);
}

Wizard::~Wizard()
{
    delete ui;
}

void Wizard::on_btnNext_clicked()
{
    wizard_network_config *wnc=new wizard_network_config();
    wnc->show();

}
