#ifndef QMYTEXTEDIT_H
#define QMYTEXTEDIT_H

#include <QTextEdit>
#include <QMouseEvent>
#include <QPoint>

class QMyTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    explicit QMyTextEdit(QWidget *parent = 0);

signals:
    void mouseLButoonClick(QPoint);
private:
    QPoint point;
public slots:

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseDoubleClickEvent(QMouseEvent *);
    void insertFromMimeData(const QMimeData *source);
};

#endif // QMYTEXTEDIT_H
