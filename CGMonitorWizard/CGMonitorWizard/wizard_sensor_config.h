#ifndef WIZARD_SENSOR_CONFIG_H
#define WIZARD_SENSOR_CONFIG_H

#include <QWidget>

namespace Ui {
class wizard_sensor_config;
}

class wizard_sensor_config : public QWidget
{
    Q_OBJECT

public:
    explicit wizard_sensor_config(QWidget *parent = 0);
    ~wizard_sensor_config();

private:
    Ui::wizard_sensor_config *ui;
};

#endif // WIZARD_SENSOR_CONFIG_H
