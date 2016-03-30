#ifndef WIZARD_NETWORK_CONFIG_H
#define WIZARD_NETWORK_CONFIG_H

#include <QWidget>

namespace Ui {
class wizard_network_config;
}

class wizard_network_config : public QWidget
{
    Q_OBJECT

public:
    explicit wizard_network_config(QWidget *parent = 0);
    ~wizard_network_config();

private slots:
    void on_btnWired_clicked();

    void on_btnPre_clicked();

    void on_btnWirless_clicked();

    void on_btnNext_clicked();

private:
    Ui::wizard_network_config *ui;
};

#endif // WIZARD_NETWORK_CONFIG_H
