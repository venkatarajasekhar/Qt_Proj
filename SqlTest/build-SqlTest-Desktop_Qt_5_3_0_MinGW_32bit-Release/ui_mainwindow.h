/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextEdit *textEdit;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit_tem;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_smoke;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_id;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QPushButton *btn_choose;
    QLineEdit *lineEdit_Jpg;
    QPushButton *btn_conn;
    QPushButton *btn_getImg;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_tem;
    QPushButton *btn_sensor;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(600, 480);
        MainWindow->setMinimumSize(QSize(480, 480));
        MainWindow->setMaximumSize(QSize(600, 480));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral(""));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(169, 9, 421, 470));
        textEdit->setMinimumSize(QSize(0, 0));
        textEdit->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"font: 9pt \"Courier New\";\n"
"color: rgb(255, 255, 255);"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 9, 154, 366));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setSpacing(20);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(72, 16777215));

        verticalLayout->addWidget(label);

        lineEdit_tem = new QLineEdit(layoutWidget);
        lineEdit_tem->setObjectName(QStringLiteral("lineEdit_tem"));
        lineEdit_tem->setMaximumSize(QSize(150, 16777215));

        verticalLayout->addWidget(lineEdit_tem);


        verticalLayout_5->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(72, 16777215));

        verticalLayout_3->addWidget(label_3);

        lineEdit_smoke = new QLineEdit(layoutWidget);
        lineEdit_smoke->setObjectName(QStringLiteral("lineEdit_smoke"));
        lineEdit_smoke->setMaximumSize(QSize(150, 16777215));

        verticalLayout_3->addWidget(lineEdit_smoke);


        verticalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(72, 16777215));

        verticalLayout_4->addWidget(label_4);

        lineEdit_id = new QLineEdit(layoutWidget);
        lineEdit_id->setObjectName(QStringLiteral("lineEdit_id"));
        lineEdit_id->setMaximumSize(QSize(150, 16777215));

        verticalLayout_4->addWidget(lineEdit_id);


        verticalLayout_5->addLayout(verticalLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(72, 16777215));

        horizontalLayout_2->addWidget(label_2);

        btn_choose = new QPushButton(layoutWidget);
        btn_choose->setObjectName(QStringLiteral("btn_choose"));
        btn_choose->setMaximumSize(QSize(64, 16777215));

        horizontalLayout_2->addWidget(btn_choose);


        verticalLayout_2->addLayout(horizontalLayout_2);

        lineEdit_Jpg = new QLineEdit(layoutWidget);
        lineEdit_Jpg->setObjectName(QStringLiteral("lineEdit_Jpg"));
        lineEdit_Jpg->setMaximumSize(QSize(150, 16777215));

        verticalLayout_2->addWidget(lineEdit_Jpg);


        verticalLayout_5->addLayout(verticalLayout_2);

        btn_conn = new QPushButton(layoutWidget);
        btn_conn->setObjectName(QStringLiteral("btn_conn"));

        verticalLayout_5->addWidget(btn_conn);

        btn_getImg = new QPushButton(layoutWidget);
        btn_getImg->setObjectName(QStringLiteral("btn_getImg"));

        verticalLayout_5->addWidget(btn_getImg);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn_tem = new QPushButton(layoutWidget);
        btn_tem->setObjectName(QStringLiteral("btn_tem"));
        btn_tem->setMaximumSize(QSize(72, 16777215));

        horizontalLayout->addWidget(btn_tem);

        btn_sensor = new QPushButton(layoutWidget);
        btn_sensor->setObjectName(QStringLiteral("btn_sensor"));
        btn_sensor->setMaximumSize(QSize(72, 16777215));

        horizontalLayout->addWidget(btn_sensor);


        verticalLayout_5->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        textEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Courier New'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">*********************************************************</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">* Qt sql terminal                                *</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">* By cyc, 2015-1-4 19:40:35                      *</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0"
                        "px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">**************************************************</span></p></body></html>", 0));
        label->setText(QApplication::translate("MainWindow", "Temperture:", 0));
        lineEdit_tem->setText(QApplication::translate("MainWindow", "20", 0));
        label_3->setText(QApplication::translate("MainWindow", "Smoke:", 0));
        label_4->setText(QApplication::translate("MainWindow", "Id:", 0));
        lineEdit_id->setText(QApplication::translate("MainWindow", "4", 0));
        label_2->setText(QApplication::translate("MainWindow", "Jpg path:", 0));
        btn_choose->setText(QApplication::translate("MainWindow", "choose...", 0));
        btn_conn->setText(QApplication::translate("MainWindow", "Connect", 0));
        btn_getImg->setText(QApplication::translate("MainWindow", "GetImage", 0));
        btn_tem->setText(QApplication::translate("MainWindow", "Insert(Tem)", 0));
        btn_sensor->setText(QApplication::translate("MainWindow", "Insert(Sensor)", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
