#ifndef WIZARD_H
#define WIZARD_H

#include <QMainWindow>

namespace Ui {
class Wizard;
}

class Wizard : public QMainWindow
{
    Q_OBJECT

public:
    explicit Wizard(QWidget *parent = 0);
    ~Wizard();

private slots:
    void on_btnNext_clicked();

private:
    Ui::Wizard *ui;
};

#endif // WIZARD_H
