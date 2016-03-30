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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qmytextedit.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnExit;
    QTabWidget *tabArtical;
    QWidget *tab_1;
    QHBoxLayout *horizontalLayout_2;
    QMyTextEdit *editArtical;
    QGridLayout *gridLayout;
    QPushButton *btnSave;
    QPushButton *btnCheck;
    QSpacerItem *verticalSpacer;
    QPushButton *btnOpenFile;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditWordInput;
    QPushButton *btnTran;
    QTextEdit *textEditWordTran;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QRadioButton *radioButton;
    QGridLayout *gridLayout_3;
    QPushButton *btnChooseFile;
    QLineEdit *lineEditInputFile;
    QRadioButton *radioButton_2;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLineEdit *lineEditNewWord;
    QLabel *label_3;
    QLineEdit *lineEdiNewTran;
    QLabel *label_4;
    QLineEdit *lineEditNewSen;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btnAddNew;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QWidget *tab_4;
    QLabel *label_5;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(765, 522);
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/res/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setWindowOpacity(1);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QLatin1String("#centralWidget{background-image: url(:/image/res/bg.png);\n"
"border-radius:5px;}\n"
"#editArtical{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-radius:10px;\n"
"}\n"
"#tabArtical::pane{\n"
"border-bottom-left-radius: 10px;\n"
"border-bottom-right-radius: 10px;\n"
"background-color: rgbd(255, 255, 255, 5%);\n"
"}\n"
"#tabArtical::tab-bar{\n"
"}\n"
"#tab_1{\n"
"background-color: rgbd(255, 255, 255, 0%);\n"
"}\n"
"#tab_2{\n"
"background-color: rgbd(255, 255, 255, 0%);\n"
"}\n"
"#tab_3{\n"
"background-color: rgbd(255, 255, 255, 0%);\n"
"}\n"
"#tab_4{\n"
"background-color: rgbd(255, 255, 255, 0%);\n"
"}\n"
"\n"
"QTabBar::tab{background-color: rgbd(255, 255, 255, 100%);margin-left:5px;border-radius:5px;}\n"
"\n"
"QTabBar::tab:selected, QTabBar::tab:hover {\n"
"	\n"
"	color: rgb(0, 170, 255);\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    border-color: #9B9B9B;\n"
"	\n"
"	background-color: qlineargradient(spread:pad, x1:0.511, y1:1, x2:0.494318, y2:0, stop:0 rgba(234, 234, 234, 255), stop:1 rgba(255, 255, "
                        "255, 255));\n"
"}\n"
"\n"
"QTabBar::tab:!selected {\n"
"	color: rgb(0, 120, 255);\n"
"    margin-top: 2px; /* make non-selected tabs look smaller */\n"
"}\n"
"\n"
"#btnExit{\n"
"	background-color: rgbd(255, 255, 255,0);\n"
"	border-image: url(:/image/res/exit.png);\n"
"}\n"
"#btnExit::hover{\n"
"border-image:url(:/image/res/exit_hover.png);\n"
"}\n"
"#textEditWordTran{\n"
"	background-color:rgbd(255,255,255,50%);\n"
"	border-radius:10px;}\n"
"#plainTextEditArtical{background-color:rgbd(255,255,255,80%);}"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(35, 25, 35, 30);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, 10, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        btnExit = new QPushButton(centralWidget);
        btnExit->setObjectName(QStringLiteral("btnExit"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnExit->sizePolicy().hasHeightForWidth());
        btnExit->setSizePolicy(sizePolicy);
        btnExit->setMinimumSize(QSize(20, 20));
        btnExit->setMaximumSize(QSize(20, 20));
        btnExit->setStyleSheet(QStringLiteral(""));
        btnExit->setIconSize(QSize(24, 24));

        horizontalLayout_3->addWidget(btnExit);


        verticalLayout_2->addLayout(horizontalLayout_3);

        tabArtical = new QTabWidget(centralWidget);
        tabArtical->setObjectName(QStringLiteral("tabArtical"));
        tabArtical->setMinimumSize(QSize(0, 0));
        tabArtical->setTabPosition(QTabWidget::North);
        tabArtical->setTabShape(QTabWidget::Rounded);
        tabArtical->setIconSize(QSize(20, 20));
        tab_1 = new QWidget();
        tab_1->setObjectName(QStringLiteral("tab_1"));
        horizontalLayout_2 = new QHBoxLayout(tab_1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        editArtical = new QMyTextEdit(tab_1);
        editArtical->setObjectName(QStringLiteral("editArtical"));
        QFont font;
        font.setPointSize(10);
        editArtical->setFont(font);
        editArtical->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextEditable|Qt::TextEditorInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout_2->addWidget(editArtical);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        btnSave = new QPushButton(tab_1);
        btnSave->setObjectName(QStringLiteral("btnSave"));
        btnSave->setMinimumSize(QSize(0, 0));
        btnSave->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(btnSave, 2, 0, 1, 1);

        btnCheck = new QPushButton(tab_1);
        btnCheck->setObjectName(QStringLiteral("btnCheck"));

        gridLayout->addWidget(btnCheck, 3, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 0, 1, 1);

        btnOpenFile = new QPushButton(tab_1);
        btnOpenFile->setObjectName(QStringLiteral("btnOpenFile"));

        gridLayout->addWidget(btnOpenFile, 1, 0, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);

        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/res/find.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabArtical->addTab(tab_1, icon1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout = new QVBoxLayout(tab_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        lineEditWordInput = new QLineEdit(tab_2);
        lineEditWordInput->setObjectName(QStringLiteral("lineEditWordInput"));

        horizontalLayout->addWidget(lineEditWordInput);

        btnTran = new QPushButton(tab_2);
        btnTran->setObjectName(QStringLiteral("btnTran"));

        horizontalLayout->addWidget(btnTran);


        verticalLayout->addLayout(horizontalLayout);

        textEditWordTran = new QTextEdit(tab_2);
        textEditWordTran->setObjectName(QStringLiteral("textEditWordTran"));
        QFont font1;
        font1.setPointSize(11);
        textEditWordTran->setFont(font1);

        verticalLayout->addWidget(textEditWordTran);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/res/tran.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabArtical->addTab(tab_2, icon2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_3 = new QVBoxLayout(tab_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 20));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        label_2->setFont(font2);
        label_2->setScaledContents(false);
        label_2->setWordWrap(false);

        verticalLayout_3->addWidget(label_2);

        radioButton = new QRadioButton(tab_3);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        verticalLayout_3->addWidget(radioButton);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        btnChooseFile = new QPushButton(tab_3);
        btnChooseFile->setObjectName(QStringLiteral("btnChooseFile"));

        gridLayout_3->addWidget(btnChooseFile, 0, 0, 1, 1);

        lineEditInputFile = new QLineEdit(tab_3);
        lineEditInputFile->setObjectName(QStringLiteral("lineEditInputFile"));

        gridLayout_3->addWidget(lineEditInputFile, 0, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout_3);

        radioButton_2 = new QRadioButton(tab_3);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout_3->addWidget(radioButton_2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(tab_3);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        lineEditNewWord = new QLineEdit(tab_3);
        lineEditNewWord->setObjectName(QStringLiteral("lineEditNewWord"));

        gridLayout_2->addWidget(lineEditNewWord, 0, 1, 1, 1);

        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        lineEdiNewTran = new QLineEdit(tab_3);
        lineEdiNewTran->setObjectName(QStringLiteral("lineEdiNewTran"));

        gridLayout_2->addWidget(lineEdiNewTran, 1, 1, 1, 1);

        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 2, 0, 1, 1);

        lineEditNewSen = new QLineEdit(tab_3);
        lineEditNewSen->setObjectName(QStringLiteral("lineEditNewSen"));

        gridLayout_2->addWidget(lineEditNewSen, 2, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        btnAddNew = new QPushButton(tab_3);
        btnAddNew->setObjectName(QStringLiteral("btnAddNew"));

        horizontalLayout_4->addWidget(btnAddNew);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_4);

        verticalSpacer_3 = new QSpacerItem(20, 95, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/res/configure.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabArtical->addTab(tab_3, icon3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        label_5 = new QLabel(tab_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(110, 100, 121, 121));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/image/res/logo.png")));
        label_5->setScaledContents(true);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/res/info.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabArtical->addTab(tab_4, icon4, QString());

        verticalLayout_2->addWidget(tabArtical);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(btnExit, SIGNAL(clicked()), MainWindow, SLOT(close()));

        tabArtical->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\345\260\217\347\201\257\346\263\241\342\200\224\342\200\224\342\200\224\350\213\261\346\226\207\345\215\225\350\257\215\351\235\236\350\257\215\346\213\274\345\206\231\351\224\231\350\257\257\347\232\204\350\207\252\345\212\250\350\257\206\345\210\253\347\263\273\347\273\237 ", 0));
#ifndef QT_NO_TOOLTIP
        btnExit->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        btnExit->setText(QString());
        editArtical->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><br /></p></body></html>", 0));
        btnSave->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", 0));
        btnCheck->setText(QApplication::translate("MainWindow", "\346\243\200\346\237\245", 0));
        btnOpenFile->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200", 0));
        tabArtical->setTabText(tabArtical->indexOf(tab_1), QApplication::translate("MainWindow", "\346\226\207\347\253\240\347\272\240\351\224\231", 0));
        btnTran->setText(QApplication::translate("MainWindow", "\347\277\273\350\257\221", 0));
        textEditWordTran->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#0055ff;\">Ever tried. Ever failed. No matter. Try Again. Fail again. Fail better. </span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; color:#0055ff;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent"
                        ":0px;\"><span style=\" color:#0055ff;\">\345\212\252\345\212\233\350\277\207\357\274\214\345\244\261\350\264\245\350\277\207\357\274\214\346\262\241\345\205\263\347\263\273\357\274\214\345\261\241\346\210\230\345\261\241\350\264\245\357\274\214\345\261\241\350\264\245\345\261\241\346\210\230\357\274\214\346\257\217\344\270\200\346\254\241\345\244\261\350\264\245\351\203\275\346\257\224\344\270\212\344\270\200\346\254\241\346\233\264\345\245\275\343\200\202</span></p></body></html>", 0));
        tabArtical->setTabText(tabArtical->indexOf(tab_2), QApplication::translate("MainWindow", "\345\215\225\350\257\215\346\237\245\350\257\242", 0));
        label_2->setText(QApplication::translate("MainWindow", "\344\270\272\347\263\273\347\273\237\345\242\236\345\212\240\346\226\260\345\215\225\350\257\215\357\274\232", 0));
        radioButton->setText(QApplication::translate("MainWindow", "\351\200\232\350\277\207\346\226\207\344\273\266\346\211\271\351\207\217\346\267\273\345\212\240\357\274\232", 0));
        btnChooseFile->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\346\226\207\344\273\266", 0));
        radioButton_2->setText(QApplication::translate("MainWindow", "\346\211\213\345\212\250\345\242\236\345\212\240", 0));
        label->setText(QApplication::translate("MainWindow", "\350\213\261\346\226\207\345\215\225\350\257\215\357\274\232", 0));
        label_3->setText(QApplication::translate("MainWindow", "\344\270\255\346\226\207\347\277\273\350\257\221\357\274\232", 0));
        label_4->setText(QApplication::translate("MainWindow", "\350\213\261\346\226\207\344\276\213\345\217\245\357\274\232", 0));
        btnAddNew->setText(QApplication::translate("MainWindow", "\346\233\264\346\226\260", 0));
        tabArtical->setTabText(tabArtical->indexOf(tab_3), QApplication::translate("MainWindow", "\347\263\273\347\273\237\350\256\276\347\275\256", 0));
        label_5->setText(QString());
        tabArtical->setTabText(tabArtical->indexOf(tab_4), QApplication::translate("MainWindow", "\345\205\263\344\272\216\346\210\221\344\273\254", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
