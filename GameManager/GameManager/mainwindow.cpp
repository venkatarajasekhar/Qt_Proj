#include "mainwindow.h"
#include "ui_mainwindow.h"

#define BTN_WIDTH           64
#define BTN_HEIGHT          64
#define VERTICAL_SPACING    2

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),ui(new Ui::MainWindow),
    m_row(1),m_drag(false),m_click(true),m_theWayToHide(0),m_timerId(0),
    m_windowIsHidden(false),m_pixToMove(0)
{
    setAttribute(Qt::WA_TranslucentBackground, true);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
    setAcceptDrops(true);
    setMouseTracking(true);
    m_screenRect=QApplication::desktop()->availableGeometry();
    ui->setupUi(this);

    /*
     * Init ui by config.ini
     */
    m_file.setFileName("config.ini");
    if(m_file.open(QIODevice::ReadWrite))
    {
//        QString tmp=m_file.readAll();
        QTextStream fs(&m_file);
        //init window postion
        if(!fs.atEnd())
        {
            QStringList list=fs.readLine().split(' ');
            if(list.size()==4)
            {
                m_dragPosition.setX(list.at(0).toInt());
                m_dragPosition.setY(list.at(1).toInt());
                if(list.at(2)!="0")
                {
                    m_timerId=startTimer(500);
                    m_theWayToHide=list.at(3).toInt();
                }
            }
        }
        //init button(s)
        while(!fs.atEnd())
        {
            QString tmp=fs.readLine();
            if(tmp==NULL)
                continue;
            //qDebug()<<"config.ini: "<<tmp;
            tmp.remove('\r');
            tmp.remove('\n');
            if(tmp!=NULL)
            {
                m_strList.append(tmp);
                addButton(tmp);
            }
        }
        if(!m_dragPosition.isNull())
            this->move(m_dragPosition);
        m_file.close();
    }else
    {
        QMessageBox msg;
        msg.setText("Cannot create file: config.ini");
        msg.exec();
        system("exit");
    }
    ui->gridLayout->setRowMinimumHeight(0, 64);
    ui->gridLayout->setVerticalSpacing(VERTICAL_SPACING);

    /*
     * init action
     */
    m_actionExit=new QAction("&Exit", this);
    connect(m_actionExit, SIGNAL(triggered()), this, SLOT(close()));
    m_actionDelete=new QAction("&Delete", this);
    connect(m_actionDelete, SIGNAL(triggered()), this, SLOT(deleteButtonByMousePos()));
    m_actionAdd=new QAction("&Add", this);
    connect(m_actionAdd, SIGNAL(triggered()), this, SLOT(on_btn0_clicked()));

    /*
     * init menu
     */
    m_menu=new QMenu(this);
    m_menu->addAction(m_actionAdd);
    m_menu->addAction(m_actionExit);

}

MainWindow::~MainWindow()
{
    delete m_actionAdd;
    delete m_actionDelete;
    delete m_actionExit;
    delete ui;
}

/*
 * A slot associate with btn add
 */
void MainWindow::on_btn0_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Choose file..."), "",  tr("(*.exe*)"));
    if(fileName=="")
        return;
    //qDebug()<<"Choose file: "<<fileName;
    fileName.replace("/", "\\");
    m_strList.append(fileName);
    addButton(fileName);
}

/*
 * Convert integer to QString
 */
QString MainWindow::toQString(int num)
{
    QString tmp;
    QTextStream(&tmp)<<num;
    return tmp;
}

/*
 * These 3 function below is used to respond to the users' drag on the window
 */
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
    {
        m_drag = true;
        m_dragPosition = event->globalPos() - this->pos();
        event->accept();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (m_drag && (event->buttons() == Qt::RightButton))
    {
        //qDebug()<<event->screenPos();
        if(event->screenPos().x()==m_screenRect.width()-1)  //touch the right side
        {
            if(!btnList.empty())
                this->move(event->screenPos().x()-btnList.at(0)->geometry().width()-10, this->geometry().y());
            else
                this->move(event->screenPos().x()-ui->btn0->geometry().width()-10, this->geometry().y());
            m_theWayToHide=CYC_HIDE_TO_RIGHT;
            if(m_timerId==0)
                m_timerId=startTimer(500);
        }else if(event->screenPos().y()==0) // touch the top
        {
            if(!btnList.empty())
                this->move(this->geometry().x(), 1-btnList.at(0)->geometry().y());
            else
                this->move(this->geometry().x(), 1-ui->btn0->geometry().y());
            m_theWayToHide=CYC_HIDE_TO_TOP;
            if(m_timerId==0)
                m_timerId=startTimer(500);
        }else
        {
            if(m_timerId!=0)
            {
                killTimer(m_timerId); m_timerId=0;
            }
            m_theWayToHide=CYC_NOT_HIDE;

            //nomal move window
            m_click=false;
            move(event->globalPos() - m_dragPosition);
        }
        event->accept();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(m_click && event->button()==Qt::RightButton)
    {
        QPoint point((int)(event->screenPos().x()), (int)(event->screenPos().y()));
        if(m_row>0) //user clicked the .exe file button
        {
            m_mouseClickedPoint=event->pos();
            m_menu->removeAction(m_actionExit);
            m_menu->addAction(m_actionDelete);
            m_menu->addAction(m_actionExit);
        }else   //the original add button
        {
            m_menu->removeAction(m_actionDelete);
        }
        m_menu->popup(point);
    }
    m_click=true;
    m_drag=false;
}


/*
 * whether the mouse is on the window
 */
bool MainWindow::isMouseInsideWindow(QPoint p)
{
    int left=ui->btn0->geometry().left()+this->geometry().left()+12;    //12 is the border width
    int right=left+ui->btn0->width();
    int top=btnList.empty()?ui->btn0->geometry().top():btnList.first()->geometry().top();
    top+=this->geometry().top();
    int bottom=btnList.empty()?ui->btn0->geometry().bottom():btnList.back()->geometry().bottom();
    bottom+=this->geometry().top();
    //qDebug()<<p<<left<<right<<top<<bottom;
    if(p.rx()>=left && p.rx()<=right+1)
        if(p.ry()>=top-1 && p.ry()<=bottom)
            return true;
    return false;
}

void MainWindow::timerEvent(QTimerEvent *e)
{
    if(e->timerId()==m_timerId)
    {
        //timer started(want to hide), mouse cursor is outside the window
        //and window currently is not hidden, so hide the window
        if(!m_windowIsHidden && !isMouseInsideWindow(QCursor::pos()) && m_menu->isHidden())
        {
            if(m_theWayToHide==CYC_HIDE_TO_RIGHT)
            {
                if(!btnList.empty())
                    m_pixToMove=btnList.at(0)->width()-1;
                else
                    m_pixToMove=ui->btn0->width()-1;
                int originX=this->geometry().x(), originY=this->geometry().y();
                for(int i=0; i<m_pixToMove; ++i)
                {
                    this->move(originX+i, originY);
                }
            }else if(m_theWayToHide==CYC_HIDE_TO_TOP)
            {
                if(!btnList.empty())
                    m_pixToMove=btnList.back()->geometry().bottom()-btnList.first()->geometry().top()-1;
                else
                    m_pixToMove=ui->btn0->geometry().height()-1;
                int originY=this->geometry().y(),originX=this->geometry().x();
                for(int i=0; i<m_pixToMove; ++i)
                {
                    this->move(originX, originY-i);
                }
                //qDebug()<<this->geometry();
            }
            m_windowIsHidden=true;
        }else if(m_windowIsHidden && isMouseInsideWindow(QCursor::pos()))
        {
            //timer started(want to hide), window currently is hidden
            //and mouse cursor is on the window edge, inside the window, so show it
            if(m_theWayToHide==CYC_HIDE_TO_RIGHT)
            {
                int originX=this->geometry().x(), originY=this->geometry().y();
                for(int i=0; i<m_pixToMove; ++i)
                {
                    this->move(originX-i, originY);
                }
            }else if(m_theWayToHide==CYC_HIDE_TO_TOP)
            {
                int originY=this->geometry().y(), originX=this->geometry().x();
                for(int i=0; i<m_pixToMove; ++i)
                {
                    this->move(originX, originY+i);
                }
            }

            m_windowIsHidden=false;
        }
    }
}

/*
 * Drag enter, only accept exe file
 */
void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    //qDebug()<<"Drag enter";
    if(event->mimeData()->hasUrls())
    {
        QString localFile;
        QRegExp rx("\\.exe$",Qt::CaseInsensitive);
        foreach(QUrl url, event->mimeData()->urls())
        {
            localFile = url.toLocalFile();
            //Only accept .exe file
            if(rx.indexIn(localFile)>=0)
            {
                event->accept();
                return;
            }
            else
            {
                event->ignore();
            }
        }
    }else
    {
        event->ignore();
    }
}

/*
 * after accept a file, add new button to the ui
 */
void MainWindow::dropEvent(QDropEvent *event)
{
    QList<QUrl> urls = event->mimeData()->urls();
    if(urls.isEmpty())
        return;

    foreach(QUrl url, urls)
    {
        QString filename = url.toLocalFile();
        filename=filename.replace("/", "\\");
        //Whether already exist
        foreach(QString str, m_strList)
        {
            if(str==filename)
                return;
        }
        m_strList.append(filename);
        addButton(filename);
    }
}

void MainWindow::addButton(QString filename)
{
    MyButton* newBtn = new MyButton();
    newBtn->setMinimumSize(BTN_WIDTH, BTN_HEIGHT);
    newBtn->setMaximumSize(BTN_WIDTH, BTN_HEIGHT);
    newBtn->setExeFileName(filename);
    newBtn->setStyleSheet("QPushButton{border-radius:5px;border-image: url(:/pic/btnBG.png);\
                          background-color: rgbd(255, 255, 255,64);}\
                          QPushButton:hover{\
                          border-image: url(:/pic/btnBGRun.png);}");
/*
    //Extract icon from exe file
    const UINT iconCount = ExtractIconEx((wchar_t *)filename.utf16(), -1, 0, 0, 0);
    //qDebug()<<iconCount;
    if (iconCount>0)
    {
        QScopedArrayPointer<HICON> icons(new HICON[iconCount]);
        const UINT extractedIconCount =
            ExtractIconEx((wchar_t *)filename.utf16(), 0, icons.data(), 0, iconCount);
        //qDebug()<<extractedIconCount;
        if (extractedIconCount>0)
        {
            QPixmap pixmap = QtWin::fromHICON(icons[0]);
            if (!pixmap.isNull())
            {
                //pixmap = pixmap.scaled(64, 64, Qt::KeepAspectRatio, Qt::SmoothTransformation);
                //pixmap.save(toQString(m_row)+".png", "png", 100);
                QIcon qIcon(pixmap);
                newBtn->setIconSize(QSize(64,64));
                newBtn->setIcon(qIcon);
                //newBtn->setStyleSheet("background-image: url(\""+toQString(m_row)+"\");");
                //qDebug()<<"Save image";
            }
        }
    }
*/

    QPixmap pixmap = getIcon(filename);
    pixmap.save(toQString(m_row)+".png", "png");
    QIcon qIcon(pixmap);
    newBtn->setIconSize(QSize(48,48));
    newBtn->setIcon(qIcon);
    btnList.append(newBtn);
    //qDebug()<<m_row<<filename;
    ui->gridLayout->addWidget(newBtn, m_row++, 0, 1, 1);
    if(!ui->btn0->isHidden())
        ui->btn0->hide();
}
typedef HICON (*CYCGetIcon)(CONST TCHAR *, CONST INT);
QPixmap MainWindow::getIcon(QString filename)
{
    QLibrary mylib("getIcon.dll");
    HICON hIcon;
    QPixmap pixmap;
    if (mylib.load())
    {
        CYCGetIcon icon;
        icon=(CYCGetIcon)mylib.resolve("CYCGetIcon");
        if (icon!=NULL)
        {
            //#define SHIL_EXTRALARGE     2
            //#define SHIL_JUMBO     4
            hIcon=icon((CONST TCHAR *)filename.utf16(), 4);
            pixmap=QtWin::fromHICON(hIcon);
            if(!pixmapIsOnly48Bit(pixmap))
                return pixmap;
            else
            {
                //qDebug()<<"48 bits only";
                hIcon=icon((CONST TCHAR *)filename.utf16(), 2);
                return QtWin::fromHICON(hIcon);
            }
        }
    }
    QMessageBox::information(NULL,"NO","Cannot load 'getIcon.dll' correctly!");
    return QPixmap(":/pic/chilun.png");
}

bool MainWindow::pixmapIsOnly48Bit(QPixmap pixmap)
{
    QImage img=pixmap.toImage();
    int row=img.height(), col=img.width();
    for(int i=49; i<row; ++i)
    {
        for(int j=49; j<col; ++j)
        {
            if((img.pixel(i,j)&0xff000000)!=0)
                return false;
        }
    }
    return true;
}

/*
 * delete button by name
 */
void MainWindow::deleteButtonByName(QString filename)
{
    //qDebug()<<"deleteButtonByName";
    //delete all button on gridLayout
    foreach(MyButton* p, btnList)
    {
        ui->gridLayout->removeWidget(p);
    }
    //delete one
    foreach(MyButton* p, btnList)
    {
        if(p->getExeFileName()==filename)
        {
            btnList.removeOne(p);
            delete p;
            m_strList.removeOne(filename);
            m_row--;
            //put the rest back to gridLayout
            foreach(MyButton* p, btnList)
            {
                ui->gridLayout->addWidget(p);
            }
            break;
        }
    }
    //if no more button then show add button
    if(m_row==1)
    {
        //qDebug()<<"ui->btn0->show()";
        ui->btn0->show();
    }
}

/*
 * delete Button By Mouse clicked Pos
 */
void MainWindow::deleteButtonByMousePos()
{
    //delete all button on gridLayout
    foreach(MyButton* p, btnList)
    {
        ui->gridLayout->removeWidget(p);
    }
    //find the clicked button
    foreach(MyButton *p, btnList)
    {
        //qDebug()<<p->pos()<<"  "<<m_mouseClickedPoint;
        if(p->pos().ry()<m_mouseClickedPoint.ry() && p->pos().ry()+p->width()>m_mouseClickedPoint.ry())
        {
            m_strList.removeOne(p->getExeFileName());
            btnList.removeOne(p);
            delete p;
            m_row--;
            //put the rest back to gridLayout
            foreach(MyButton* p, btnList)
            {
                ui->gridLayout->addWidget(p);
            }
            break;
        }
    }
    //no more button there
    if(m_row==1)
    {
        //qDebug()<<"ui->btn0->show()";
        ui->btn0->show();
    }
}

/*
 * refresh config.ini before close
 */
void MainWindow::closeEvent(QCloseEvent *e)
{
    if(m_file.open(QIODevice::WriteOnly))
    {
        //write current postion
        QString str;
        QTextStream(&str)<<this->geometry().x()<<' '<<this->geometry().y()<<' '<<m_timerId<<' '<<m_theWayToHide;
        m_file.write(str.toLatin1()+"\r\n");
        //write all button name
        foreach(str, m_strList)
        {
            if(str!=NULL)
                m_file.write(str.toLatin1()+"\r\n");
        }
    }
    m_file.close();
    e->accept();
    exit(0);
}

