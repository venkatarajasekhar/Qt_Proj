#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->btnCheck->setEnabled(false);
    ui->btnTran->setEnabled(false);
    myThread = new QMyHashThread();
    connect(myThread,SIGNAL(loadThreadExited(int)),this,SLOT(enableAction(int)));
    myThread->start();
    color[red]="#FF0000";color[yellow]="#FFAE00";color[green]="#80FF20";color[wathet]="#00AEFF";color[blue]="#0000FF";
    m_drag=false;
    //setFocusPolicy(Qt::ClickFocus);
    setAttribute(Qt::WA_TranslucentBackground, true);
    setWindowFlags(Qt::FramelessWindowHint);
    ui->radioFile->setChecked(true);

    ui->btnLink->setVisible(false);
    ui->editArtical->setAutoFormatting(QTextEdit::AutoNone);
    ui->editArtical->installEventFilter(this);
    ui->textEditWordTran->setTextColor(QColor(0,0,255));
    psgOld="";
    fileName="";

    ui->lineEditNewWord->setEnabled(false);
    ui->lineEdiNewTran->setEnabled(false);
    ui->lineEditNewSen->setEnabled(false);
    add=new QAddFileThread();
    allWrongWord.clear();
    inputDlg=new InputDialog();
    dlg=new Dialog();
    manager = new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),
                this,SLOT(replyFinished(QNetworkReply*)));
    connect(ui->editArtical,SIGNAL(cursorPositionChanged()), this, SLOT(showCandidateDlg()));
    connect(inputDlg, SIGNAL(newWordAdded(QStringList)), this, SLOT(addNewWords(QStringList)));
    connect(ui->lineEditWordInput, SIGNAL(returnPressed()), this, SLOT(on_btnTran_clicked()));
    //connect(dlg, SIGNAL(listDoubleClick(QString)),this,SLOT(autoReplaceWord(QString)));
    connect(ui->editArtical, SIGNAL(mouseLButoonClick(QPoint)), this, SLOT(getTextEditClickPos(QPoint)));

    mylen.psgLen=0;
    mylen.newpsgLen=0;
    mylen.insertPos=0;
    curPos=0;

    getArticalTimerId=startTimer(1500);
    ui->editArtical->insertHtml("I am first lined so many dog barked bark barking");
}

MainWindow::~MainWindow()
{
    delete inputDlg;
    delete dlg;
    delete myThread;
    delete ui;
}


/*
 * On check button click
 */
void MainWindow::on_btnCheck_clicked()
{
    disconnect(ui->editArtical,SIGNAL(cursorPositionChanged()), this, SLOT(showCandidateDlg()));
    allWrongWord.clear();
    QString psg;
    psg=ui->editArtical->toPlainText();
    ui->editArtical->setText("");
    ui->editArtical->insertHtml("<font color='#000000'>"+psg+" </font>");
    psgOld=psg;
    if(psg=="")
        return;
    //qDebug()<<"psg"<<psg;
    QRegExp rx("[^A-Za-z0-9_\\s]"),rxs("\\s*$");
    psg.remove(rx);     //remove none letter
    psg.remove(rxs);    //remove the last space
    //qDebug()<<"psg"<<psg;
    QTextStream ts(&psg);
    QString tmp="";
    while(!ts.atEnd())
    {
        ts>>tmp;
        //tmp.remove(rxs);
        tmp=tmp.toLower();
        if(tmp!=""&&myThread->findWord(tmp)=="")
        {
            allWrongWord[tmp]++;
        }
    }
    //qDebug()<<"allWrongWord"<<allWrongWord;
    markAllWrongWord();
    connect(ui->editArtical,SIGNAL(cursorPositionChanged()), this, SLOT(showCandidateDlg()));
}

/*
 * A slot to store the position of the mouse cursor
 */
void MainWindow::getTextEditClickPos(QPoint point)
{
    if(dlg!=NULL)
        if(!m_dlgPos.isNull())
            if(abs(point.rx()-m_dlgPos.rx())>50||abs(point.ry()-m_dlgPos.ry())>50)
                dlg->hide();
    m_dlgPos=point;
}

/*
 * A slot to replace the wrong word with the correct one in the candidate box
 */
void MainWindow::autoReplaceWord(QString str)
{
    if(str.compare("添加到词典...")==0)
    {
        //show input dialog
        ui->editArtical->clearFocus();
        dlg->hide();
        inputDlg->setWord(wordUnderCursor);
        inputDlg->show();
        return;
    }
    int pos=ui->editArtical->textCursor().position();
    psgOld=ui->editArtical->toPlainText();
    int l=pos==0?0:pos-1,r=pos;
    //go left and find the first one which is not a letter
    for(;l>0;l--)
    {
        if(!psgOld[l].isLetter())
            break;
    }
    l=l==0?0:l+1;
    //go right and fine the first one which is not a letter
    for(;r<psgOld.length(); r++)
    {
        if(!psgOld[r].isLetter())
            break;
    }
    //qDebug()<<r<<"r l"<<l;
    ReplaceWords(l, r-l, str, green);
}

/*
 * Input:   pos specify the pos in the text edit area;
 *          wordslen specify how many words you want to delete
 * Note:    The delete action deletes the back one not the front one
 */
void MainWindow::ReplaceWords(int pos, int wordslen, QString newwords, int newcolor)
{
    int oldpos=ui->editArtical->textCursor().position();
    QTextCursor cursor=ui->editArtical->textCursor();
    cursor.setPosition(pos);
    ui->editArtical->setTextCursor(cursor);
    for(int i=0; i<wordslen; i++)
    {
        ui->editArtical->textCursor().deleteChar();
    }
    if(newwords!="")
        ui->editArtical->insertHtml("<font color='"+color[newcolor]+"'>"+newwords+"</font>");
    cursor.setPosition(oldpos);
    ui->editArtical->setTextCursor(cursor);
}


/*
 * A slot takes respond to the load-file thread
 */
void MainWindow::enableAction(int timeused)
{
    ui->btnTran->setEnabled(true);
    ui->btnSave->setEnabled(true);
    ui->btnCheck->setEnabled(true);
    //qDebug()<<timeused;
}

/*
 * A slot to show candidate dialog
 */
void MainWindow::showCandidateDlg()
{
    //if text cursor pos is valid, then show dlg with candidate
    int pos=ui->editArtical->textCursor().position();
    if(ui->editArtical->textCursor().atEnd())
        return;
    if(isPosValid(pos))
    {
        connect(dlg, SIGNAL(listDoubleClick(QString)),this,SLOT(autoReplaceWord(QString)));
        dlg->setCandidateText(candidate);
        dlg->move(m_dlgPos.rx(),m_dlgPos.ry()+10);
        //qDebug()<<"going to show dialog"<<m_dlgPos;
        if(dlg->isHidden())
        {
            dlg->show();
        }
    }else if(ui->checkBoxAutoTran->isChecked() && wordUnderCursor!="")
    {
        disconnect(dlg, SIGNAL(listDoubleClick(QString)),this,SLOT(autoReplaceWord(QString)));
        QStringList list;
        list.append(wordUnderCursor);
        list.append(myThread->findWord(wordUnderCursor));
        dlg->setTranText(list);
        dlg->move(m_dlgPos.rx(),m_dlgPos.ry()+10);
        //qDebug()<<"going to show dialog"<<m_dlgPos;
        if(dlg->isHidden())
        {
            dlg->show();
        }
    }
    else
    {
        dlg->hide();
    }
}

/*
 * Input:   the position of the cursor in editArtical
 * Return:  true if the word under the cursor is a wrong word
 *          false if the word under the cursor is not a wrong word
 */
bool MainWindow::isPosValid(int pos)
{
    int l=pos==0?0:pos-1,r=pos;
    //go left and find the first one which is not a letter
    for(;l>0;l--)
    {
        if(!psgOld[l].isLetter())
            break;
    }
    l=l==0?0:l+1;
    //go right and find the first one which is not a letter
    for(;r<psgOld.length(); r++)
    {
        if(!psgOld[r].isLetter())
            break;
    }
    wordUnderCursor=psgOld.mid(l,r-l);
    //qDebug()<<"wordAtPos"<<wordAtPos;
    QHash<QString, int>::iterator it=allWrongWord.find(wordUnderCursor);
    if(it==allWrongWord.end())
        return false;
    else
    {
        candidate=myThread->correctWord(wordUnderCursor);
        return true;
    }
}

/*
 * Qt object event filter
 */
bool MainWindow::eventFilter(QObject *obj, QEvent *e)
{
        return QMainWindow::eventFilter(obj,e);
}

/*
 * These 3 function below is used to respond to the users' drag on the window
 */
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        //qDebug()<<"oh no";
        m_drag = true;
        m_dragPosition = event->globalPos() - this->pos();
        event->accept();
    }
    if(dlg!=NULL&&!dlg->isHidden())
    {
        dlg->hide();
    }
}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    //qDebug()<<"oh no";
    if (m_drag && (event->buttons() == Qt::LeftButton))
    {
        move(event->globalPos() - m_dragPosition);
        event->accept();
    }
    if(dlg!=NULL)
        if(!m_dlgPos.isNull())
            if(abs(event->globalX()-m_dlgPos.rx())>100||abs(event->globalY()-m_dlgPos.ry())>100)
                dlg->hide();
}
void MainWindow::mouseReleaseEvent(QMouseEvent *)
{
    m_drag = false;
}

/*
 * Timer
 */
void MainWindow::timerEvent(QTimerEvent *e)
{
    if(e->timerId()==getArticalTimerId)
    {
        psgOld=ui->editArtical->toPlainText();
    }
}

/*
 * A slot to open txt file.
 */
void MainWindow::on_btnOpenFile_clicked()
{
    fname = QFileDialog::getOpenFileName(this, tr("选择文件"), " ",  tr("文本文件(*.txt*);;所有文件(*.*)"));
    if(fname=="")
        return;
    QFile file(fname);
    if(!file.open(QIODevice::ReadWrite| QIODevice::Text))
    {
        QMessageBox msgBox;
        msgBox.setText("无法打开："+fname);
        msgBox.exec();
    }
    QTextStream ts(&file);
    psgOld = ts.readAll();
    allWrongWord.clear();
    ui->editArtical->setTextColor(QColor(0,0,0));
    ui->editArtical->setText(psgOld);
    file.close();
}

/*
 * A slot to add a single word to the dictionary
 */
void MainWindow::addNewWords(QStringList list)
{
    myThread->addNewWords(list);
}

/*
 * A slot to show a message box to show how many word have been successfully add to the dic
 */
void MainWindow::addNewFile(int all, int added)
{
    //qDebug()<<"msgBox"<<all<<added;
    QMessageBox msgBox;
    QString msg="检测到新单词：";
    QString tmp1, tmp2, tmp3;
    QTextStream(&tmp1)<<all;
    QTextStream(&tmp2)<<added;
    QTextStream(&tmp3)<<(all-added);
    msg=msg+tmp1+"个\n成功添加："+tmp2+" 个\n";
    if((all-added)!=0)
        msg+="其中："+ tmp3+" 个单词重复或格式错误";
    msgBox.setText(msg);
    msgBox.exec();
    ui->labelInfo->setText("添加成功 "+tmp2+" 个新单词");
}

/*
 * Scan the whole passage, if it has wrong words
 * then replace them with the same word but the different color.
 */
void MainWindow::markAllWrongWord()
{
    QHash<QString,int>::iterator it=allWrongWord.begin();
    for(; it!=allWrongWord.end(); it++)
    {
        QString key=it.key();
        if(key=="")
            continue;
        if(key.at(0).isDigit())
            continue;
        QRegExp rx(key);
        int pos = 0;
        while ((pos = rx.indexIn(psgOld, pos)) != -1)
        {
            QString str=rx.cap(0);
            //qDebug()<<str;
            ReplaceWords(pos,str.length(),str, red);
            pos += rx.matchedLength();
        }
    }
}


/*
 * A slot for user to choose a file which is going to be added to the dictionary
 */
void MainWindow::on_btnChooseFile_clicked()
{
    fileName = QFileDialog::getOpenFileName(this, tr("选择文件"), "",  tr("文本文件(*.txt*);;所有文件(*.*)"));
    if(fileName=="")
        return;
    ui->lineEditInputFile->setText(fileName);
    ui->labelInfo->setText("");

}
/*
 * A slot when the tab bar is clicked, to hide the candidate dialog
 */
void MainWindow::on_tabArtical_tabBarClicked(int)
{
    if(dlg!=NULL&&!dlg->isHidden())
        dlg->hide();
}

/*
 * These 2 function below are slots to make sure you just can choose
 * a single way to add you words to the dictionary
 */
void MainWindow::on_radioFile_clicked()
{
    ui->lineEditNewWord->setEnabled(false);
    ui->lineEdiNewTran->setEnabled(false);
    ui->lineEditNewSen->setEnabled(false);
    ui->lineEditInputFile->setEnabled(true);
}

void MainWindow::on_radioSingle_clicked()
{
    ui->lineEditNewWord->setEnabled(true);
    ui->lineEdiNewTran->setEnabled(true);
    ui->lineEditNewSen->setEnabled(true);
    ui->lineEditInputFile->setEnabled(false);
}
/*
 * Add new word button clicked
 */
void MainWindow::on_btnAddNew_clicked()
{
    if(ui->radioFile->isChecked())
    {
        //if add new words through file is checked the start a new thread
        //cause it may take a long time to finish
        if(fileName=="")
        {
            QMessageBox msgbox;
            msgbox.setText("没有选择任何文件！");
            msgbox.exec();
            return;
        }
        add->setDicPointer(myThread->getDicPointer());
        add->setFileName(fileName);
        add->setTextStreamPointer(myThread->getTextStreamPointer());
        connect(add,SIGNAL(addNewFileEnd(int,int)),this,SLOT(addNewFile(int,int)));
        add->start();
    }else
    {
        //if add new word manually then add directly
        QStringList list;
        if(ui->lineEditNewWord->text()=="")
        {
            ui->labelInfo->setText("没有输入！");
            return;
        }
        list.append(ui->lineEditNewWord->text());
        list.append("[E]"+ui->lineEdiNewTran->text());
        list.append("[L]"+ui->lineEditNewSen->text());
        if(myThread->findWord(list.at(0))!="")
        {
            ui->labelInfo->setText(list.at(0)+" 已存在");
        }
        else
        {
            addNewWords(list);
            ui->labelInfo->setText("成功添加 1 个单词");
        }
    }
}

/*
 * Reset the label text
 */
void MainWindow::on_lineEditNewWord_textChanged(const QString &)
{
    ui->labelInfo->setText("");
}

/*
 * Save file button clicked, save the current text to a file.
 */
void MainWindow::on_btnSave_clicked()
{
    QString fn = QFileDialog::getSaveFileName(this, tr("保存文件"), "", tr("txt(*.txt)"));
    if (!fn.isNull())
    {
        QFile file(fn);
        //qDebug()<<fn;
        QMessageBox msgbox;
        if(file.open(QIODevice::ReadWrite))
        {
            file.write(psgOld.toStdString().c_str());
            file.write("\n");
            file.close();
            msgbox.setText("保存成功");
        }else
        {
            msgbox.setText("保存失败");
        }
        msgbox.exec();
    }else
    {
    }
}

/*
 * On translate button clicked
 */
void MainWindow::on_btnTran_clicked()
{
    QString word=ui->lineEditWordInput->text();
    if(word=="")
    {
        ui->textEditWordTran->setText("No pain no gain, no input no output!");
        return;
    }
    ui->btnLink->setVisible(true);
    QString ret=myThread->findWord(word);
    if(ret=="")
    {
        ret=myThread->findWord(word.toLower());
        if(ret=="")
        {
            QStringList list=myThread->correctWord(word);
            ui->textEditWordTran->setText("");
            QString str="<font color='#0000FF'>没有找到单词：</font><font color='#00FFA0'>"+word+"</font>";
            ui->textEditWordTran->insertHtml(str);
            ui->textEditWordTran->setTextColor(QColor(0,0,255));
            ui->textEditWordTran->append("你是不是想要找：");
            ui->textEditWordTran->textCursor().setPosition(str.length()-1, QTextCursor::MoveAnchor);
            for(int i=0; i<list.size(); i++)
            {
                ui->textEditWordTran->insertHtml("<font color='"+color[i]+"'>"+list.at(i)+" </font>");
            }
            return;
        }
    }else
    {
        ret.replace(QRegExp("\\[E\\]"),"【解释】\n");
        ret.replace(QRegExp("\\[L\\]"),"\n【例句】\n");
        ret.replace(QRegExp("\\[J\\]"),"\n\n【构词】\n");
        QRegExp rx("((n|v|adj|adv|prep|pron)\\.)");
        rx.indexIn(ret);
        //qDebug()<<rx;
        int pos=0;
        while ((pos = rx.indexIn(ret, pos)) != -1) {
            ret.insert(pos,"\n");
            pos += rx.matchedLength();
        }
        ui->textEditWordTran->setText(ret);
        ui->textEditWordTran->setTextColor(QColor(0,0,255));
    }
}
/*
 * A slot, when down load html file finished
 */
void MainWindow::replyFinished(QNetworkReply *reply)
{
    QString all = reply->readAll();
    QRegExp keyrx("<ul><li><span class=(\"pos\"|\"pos\\sweb\")>.*</li></ul>");
    QRegExp cnrx("<div class=(\"bil_ex\"|\"sen_cn\")>.*</div>");
    QRegExp enrx("<div class=(\"val_ex\"|\"sen_en\")>.*</div>");
    QRegExp noarx("(<a.*>|</a>)");
    noarx.setMinimal(true);
    keyrx.setMinimal(true);
    cnrx.setMinimal(true);
    enrx.setMinimal(true);
    all.remove(noarx);
    QString explain;
    int pos = keyrx.indexIn(all);
    int pos2=cnrx.indexIn(all);
    int pos3=enrx.indexIn(all);
    if(pos>-1)
    {
        explain=keyrx.cap(0);
        explain=explain.left(explain.length()-10);
        explain=explain.right(explain.length()-8);
        //qDebug()<<explain;
        explain.insert(explain.lastIndexOf(QRegExp("网络"))+2,": ");
        ui->textEditWordTran->append("\n以下内容来自互联网：\n【解释】\n");
        ui->textEditWordTran->append(explain);
    }else
    {
        ui->textEditWordTran->append("\n还是没有找到...╮(╯▽╰)╭\n");
        return;
    }
    if(pos2>-1)
    {
        explain=enrx.cap(0);
        //qDebug()<<explain;
        ui->textEditWordTran->append("\n【例句】\n");
        ui->textEditWordTran->append(explain);
    }
    if(pos3>-1)
    {
        explain=cnrx.cap(0);
        //qDebug()<<explain;
        ui->textEditWordTran->append(explain);
    }
    reply->deleteLater();
}
/*
 * A slot, to get translation from network
 */
void MainWindow::on_btnLink_clicked()
{
    QString word=ui->lineEditWordInput->text();
    if(word=="")
        return;
    word=word.toHtmlEscaped();
    //qDebug()<<word;
    manager->get(QNetworkRequest(QUrl("http://cn.bing.com/dict/search?q="+word+"&go=&qs=n&form=CM&pq="+word+"&sc=7-5&sp=-1&sk=")));
    ui->btnLink->setVisible(false);
}
