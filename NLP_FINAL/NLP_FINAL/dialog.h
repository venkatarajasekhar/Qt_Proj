#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QStringList>
#include <QStringListModel>
#include <QModelIndex>
#include <QDebug>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    bool isShowing;
    void setCandidateText(QStringList listofwords);
    void setTranText(QStringList list);
private:
    Ui::Dialog *ui;
    QStringList dlgList;
     QStringListModel *model;
public slots:
    void getListText(QModelIndex index);
signals:
    void listDoubleClick(QString);

};

#endif // DIALOG_H
