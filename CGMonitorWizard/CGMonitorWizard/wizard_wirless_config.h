#ifndef WIZARD_WIRLESS_CONFIG_H
#define WIZARD_WIRLESS_CONFIG_H

#include <QWidget>

namespace Ui {
class wizard_wirless_config;
}

class wizard_wirless_config : public QWidget
{
    Q_OBJECT

public:
    explicit wizard_wirless_config(QWidget *parent = 0);
    ~wizard_wirless_config();

private:
    Ui::wizard_wirless_config *ui;
};

#endif // WIZARD_WIRLESS_CONFIG_H
