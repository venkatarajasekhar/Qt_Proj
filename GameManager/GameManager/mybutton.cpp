#include "mybutton.h"

MyButton::MyButton():
    QPushButton()
{
}

MyButton::~MyButton()
{
}

void MyButton::executeExternalFile()
{
//    qDebug()<<"MyButton::executeExeternalFile: "<<m_fileName;
    m_thread=new CYCThread();
    connect(m_thread, SIGNAL(finished()), this, SLOT(markRunning()));
    m_thread->setFilename(m_fileName);
    m_thread->start();
    m_clientNum++;
    this->setStyleSheet("border-image: url(:/pic/btnBGRun.png);");
}

void MyButton::markRunning()
{
    if(m_clientNum==0)
    {
        this->setStyleSheet("QPushButton{border-radius:5px;border-image: url(:/pic/btnBG.png);\
                            background-color: rgbd(255, 255, 255,64);}\
                            QPushButton:hover{\
                            border-image: url(:/pic/btnBGRun.png);}");
    }else
        --m_clientNum;
}

void MyButton::setExeFileName(QString filename)
{
    this->m_fileName=filename;
    this->setToolTip(m_fileName.right(m_fileName.length()-m_fileName.lastIndexOf('\\')-1));
    connect(this, SIGNAL(clicked()), this, SLOT(executeExternalFile()));
}

QString MyButton::getExeFileName()
{
    return m_fileName;
}

