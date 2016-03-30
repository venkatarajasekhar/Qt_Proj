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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
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
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *edit2;
    QLabel *label_4;
    QLineEdit *edit1;
    QCheckBox *checkBox_1;
    QLabel *label_6;
    QCheckBox *checkBox_2;
    QLineEdit *edit3;
    QCheckBox *checkBox_3;
    QLabel *label_5;
    QLabel *label_3;
    QLineEdit *edit4;
    QCheckBox *checkBox_4;
    QLabel *label_7;
    QLineEdit *edit5;
    QCheckBox *checkBox_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_8;
    QLineEdit *editFre;
    QLabel *label_9;
    QLineEdit *editId;
    QLineEdit *editPwd;
    QLineEdit *editUrl;
    QPushButton *btnLogin;
    QVBoxLayout *verticalLayout;
    QPushButton *btnStart;
    QPushButton *btnStop;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_10;
    QPushButton *btnTX;
    QPushButton *btnPE;
    QPushButton *btnYX;
    QTextEdit *textInfo;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(680, 320);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        edit2 = new QLineEdit(centralWidget);
        edit2->setObjectName(QStringLiteral("edit2"));
        edit2->setMinimumSize(QSize(100, 0));

        gridLayout_2->addWidget(edit2, 4, 1, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 4, 0, 1, 1);

        edit1 = new QLineEdit(centralWidget);
        edit1->setObjectName(QStringLiteral("edit1"));
        edit1->setMinimumSize(QSize(150, 0));

        gridLayout_2->addWidget(edit1, 3, 1, 1, 1);

        checkBox_1 = new QCheckBox(centralWidget);
        checkBox_1->setObjectName(QStringLiteral("checkBox_1"));

        gridLayout_2->addWidget(checkBox_1, 3, 2, 1, 1);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 5, 0, 1, 1);

        checkBox_2 = new QCheckBox(centralWidget);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        gridLayout_2->addWidget(checkBox_2, 4, 2, 1, 1);

        edit3 = new QLineEdit(centralWidget);
        edit3->setObjectName(QStringLiteral("edit3"));

        gridLayout_2->addWidget(edit3, 5, 1, 1, 1);

        checkBox_3 = new QCheckBox(centralWidget);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        gridLayout_2->addWidget(checkBox_3, 5, 2, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 6, 0, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 3, 0, 1, 1);

        edit4 = new QLineEdit(centralWidget);
        edit4->setObjectName(QStringLiteral("edit4"));

        gridLayout_2->addWidget(edit4, 6, 1, 1, 1);

        checkBox_4 = new QCheckBox(centralWidget);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));

        gridLayout_2->addWidget(checkBox_4, 6, 2, 1, 1);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 7, 0, 1, 1);

        edit5 = new QLineEdit(centralWidget);
        edit5->setObjectName(QStringLiteral("edit5"));
        edit5->setMinimumSize(QSize(0, 0));

        gridLayout_2->addWidget(edit5, 7, 1, 1, 1);

        checkBox_5 = new QCheckBox(centralWidget);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));

        gridLayout_2->addWidget(checkBox_5, 7, 2, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMaximumSize(QSize(50, 20));

        horizontalLayout_2->addWidget(label_8);

        editFre = new QLineEdit(centralWidget);
        editFre->setObjectName(QStringLiteral("editFre"));
        editFre->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_2->addWidget(editFre);


        gridLayout_2->addLayout(horizontalLayout_2, 5, 3, 1, 1);

        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_2->addWidget(label_9, 0, 0, 1, 1);

        editId = new QLineEdit(centralWidget);
        editId->setObjectName(QStringLiteral("editId"));

        gridLayout_2->addWidget(editId, 1, 1, 1, 2);

        editPwd = new QLineEdit(centralWidget);
        editPwd->setObjectName(QStringLiteral("editPwd"));

        gridLayout_2->addWidget(editPwd, 2, 1, 1, 2);

        editUrl = new QLineEdit(centralWidget);
        editUrl->setObjectName(QStringLiteral("editUrl"));

        gridLayout_2->addWidget(editUrl, 0, 1, 1, 3);

        btnLogin = new QPushButton(centralWidget);
        btnLogin->setObjectName(QStringLiteral("btnLogin"));
        btnLogin->setMinimumSize(QSize(80, 20));
        btnLogin->setMaximumSize(QSize(80, 16777215));

        gridLayout_2->addWidget(btnLogin, 1, 3, 2, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        btnStart = new QPushButton(centralWidget);
        btnStart->setObjectName(QStringLiteral("btnStart"));
        btnStart->setMinimumSize(QSize(80, 20));
        btnStart->setMaximumSize(QSize(80, 16777215));

        verticalLayout->addWidget(btnStart);

        btnStop = new QPushButton(centralWidget);
        btnStop->setObjectName(QStringLiteral("btnStop"));
        btnStop->setMinimumSize(QSize(80, 0));
        btnStop->setMaximumSize(QSize(80, 16777215));

        verticalLayout->addWidget(btnStop);


        gridLayout_2->addLayout(verticalLayout, 6, 3, 2, 1);


        horizontalLayout_3->addLayout(gridLayout_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout->addWidget(label_10);

        btnTX = new QPushButton(centralWidget);
        btnTX->setObjectName(QStringLiteral("btnTX"));

        horizontalLayout->addWidget(btnTX);

        btnPE = new QPushButton(centralWidget);
        btnPE->setObjectName(QStringLiteral("btnPE"));

        horizontalLayout->addWidget(btnPE);

        btnYX = new QPushButton(centralWidget);
        btnYX->setObjectName(QStringLiteral("btnYX"));

        horizontalLayout->addWidget(btnYX);


        verticalLayout_2->addLayout(horizontalLayout);

        textInfo = new QTextEdit(centralWidget);
        textInfo->setObjectName(QStringLiteral("textInfo"));

        verticalLayout_2->addWidget(textInfo);


        horizontalLayout_3->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_2->setText(QApplication::translate("MainWindow", "\345\257\206\347\240\201\357\274\232", 0));
        label->setText(QApplication::translate("MainWindow", "\345\255\246\345\217\267\357\274\232", 0));
        label_4->setText(QApplication::translate("MainWindow", "\350\257\276\347\250\2132\357\274\232", 0));
        checkBox_1->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251", 0));
        label_6->setText(QApplication::translate("MainWindow", "\350\257\276\347\250\2133\357\274\232", 0));
        checkBox_2->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251", 0));
        checkBox_3->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251", 0));
        label_5->setText(QApplication::translate("MainWindow", "\350\257\276\347\250\2134\357\274\232", 0));
        label_3->setText(QApplication::translate("MainWindow", "\350\257\276\347\250\2131\357\274\232", 0));
        checkBox_4->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251", 0));
        label_7->setText(QApplication::translate("MainWindow", "\350\257\276\347\250\2135\357\274\232", 0));
        checkBox_5->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251", 0));
        label_8->setText(QApplication::translate("MainWindow", "\351\242\221\347\216\207", 0));
        label_9->setText(QApplication::translate("MainWindow", "\347\275\221\345\235\200\357\274\232", 0));
        btnLogin->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225", 0));
        btnStart->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213", 0));
        btnStop->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242", 0));
        label_10->setText(QApplication::translate("MainWindow", "\350\257\276\347\250\213\344\273\243\347\240\201\357\274\232", 0));
        btnTX->setText(QApplication::translate("MainWindow", "\351\200\232\351\200\211\350\257\276", 0));
        btnPE->setText(QApplication::translate("MainWindow", "\344\275\223\350\202\262\350\257\276", 0));
        btnYX->setText(QApplication::translate("MainWindow", "\351\231\242\347\263\273\351\200\211\344\277\256", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
