#ifndef WIZARD_MAINPAGE_H
#define WIZARD_MAINPAGE_H

#include <QWidget>

namespace Ui {
class wizard_mainpage;
}

class wizard_mainpage : public QWidget
{
    Q_OBJECT

public:
    explicit wizard_mainpage(QWidget *parent = 0);
    ~wizard_mainpage();

private:
    Ui::wizard_mainpage *ui;
};

#endif // WIZARD_MAINPAGE_H
