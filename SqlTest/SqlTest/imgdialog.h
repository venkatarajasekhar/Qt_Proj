#ifndef IMGDIALOG_H
#define IMGDIALOG_H

#include <QDialog>
#include <QPixmap>

namespace Ui {
class ImgDialog;
}

class ImgDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ImgDialog(QWidget *parent = 0);
    ~ImgDialog();

    void setImage(QPixmap pixmap);
protected:
    void closeEvent(QCloseEvent *e);
private:
    Ui::ImgDialog *ui;
};

#endif // IMGDIALOG_H
