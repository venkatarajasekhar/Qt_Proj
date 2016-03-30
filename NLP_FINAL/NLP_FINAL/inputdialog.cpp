#include "inputdialog.h"
#include "ui_inputdialog.h"

InputDialog::InputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputDialog)
{
    ui->setupUi(this);
    //setAttribute(Qt::WA_TranslucentBackground, true);
    setWindowFlags(Qt::FramelessWindowHint|Qt::Tool|Qt::WindowStaysOnTopHint);
    ui->editWord->setReadOnly(true);
    ui->editExplain->setFocus();
    m_drag=false;
}

InputDialog::~InputDialog()
{
    delete ui;
}
/*
 * Input:   A English word
 * Function:Set the new word from the cursor position to editWord
 */
void InputDialog::setWord(QString word)
{
    ui->editWord->setText(word);
    ui->editExplain->setText("");
    ui->editSentence->setText("");
}
/*
 * When user click confirm button.
 */
void InputDialog::on_buttonBox_accepted()
{
    QStringList list;
    list.append(ui->editWord->text());
    //If users did not enter the explanation and the sentence but click ok
    QString str=ui->editExplain->text();
    if(str=="")
        return;
    list.append("[E]"+ui->editExplain->text());
    list.append("[L]"+ui->editSentence->text());
    emit newWordAdded(list);
}

/*
 * These 3 functions below is used to take respond to the user's drag on the window
 */
void InputDialog::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        //qDebug()<<"oh no";
        m_drag = true;
        m_dragPosition = event->globalPos() - this->pos();
        event->accept();
    }
}
void InputDialog::mouseMoveEvent(QMouseEvent *event)
{
    if (m_drag && (event->buttons() == Qt::LeftButton))
    {
        move(event->globalPos() - m_dragPosition);
        event->accept();
    }
}
void InputDialog::mouseReleaseEvent(QMouseEvent *)
{
    m_drag = false;
}
