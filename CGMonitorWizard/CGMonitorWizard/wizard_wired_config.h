#ifndef WIZARD_WIRED_CONFIG_H
#define WIZARD_WIRED_CONFIG_H

#include <QWidget>

namespace Ui {
class wizard_wired_config;
}

class wizard_wired_config : public QWidget
{
    Q_OBJECT

public:
    explicit wizard_wired_config(QWidget *parent = 0);
    ~wizard_wired_config();

private:
    Ui::wizard_wired_config *ui;
};

#endif // WIZARD_WIRED_CONFIG_H
