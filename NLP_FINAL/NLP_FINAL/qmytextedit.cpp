#include "qmytextedit.h"
#include <QDebug>
#include <QMimeData>
QMyTextEdit::QMyTextEdit(QWidget *parent) :
    QTextEdit(parent)
{
}

/*
 * Rewrite the mousePressEvent, cause we need to get the position of
 * the mouse cursor when uset click the textedit area.
 */
void QMyTextEdit::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::LeftButton)
    {
        qDebug()<<"Left button";
        point=e->globalPos();
        emit mouseLButoonClick(point);
    }
    QTextEdit::mousePressEvent(e);
}

void QMyTextEdit::mouseDoubleClickEvent(QMouseEvent *)
{
    return;
}

void QMyTextEdit::insertFromMimeData(const QMimeData *source)
{
    QMimeData data;
    data.setText(source->text());
    QTextEdit::insertFromMimeData(&data);
}
