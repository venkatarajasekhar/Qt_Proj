#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include <QStringList>
#include <QPoint>
#include <QMouseEvent>
namespace Ui {
class InputDialog;
}

class InputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputDialog(QWidget *parent = 0);
    ~InputDialog();

    void setWord(QString word);
private slots:
    void on_buttonBox_accepted();
signals:
    void newWordAdded(QStringList list);
protected:
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
private:
    Ui::InputDialog *ui;
    QPoint m_dragPosition;
    bool m_drag;
};

#endif // INPUTDIALOG_H
