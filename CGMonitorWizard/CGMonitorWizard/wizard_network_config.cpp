#include "wizard_network_config.h"
#include "ui_wizard_network_config.h"
#include "wizard_wired_config.h"
#include "wizard_wirless_config.h"
#include "wizard.h"

wizard_network_config::wizard_network_config(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wizard_network_config)
{
    ui->setupUi(this);
}

wizard_network_config::~wizard_network_config()
{
    delete ui;
}

void wizard_network_config::on_btnWired_clicked()
{
    wizard_wired_config *wwc=new wizard_wired_config();
    wwc->show();
}

void wizard_network_config::on_btnWirless_clicked()
{
    wizard_wirless_config *wwc=new wizard_wirless_config();
    wwc->show();
}

void wizard_network_config::on_btnPre_clicked()
{

}

void wizard_network_config::on_btnNext_clicked()
{

}
