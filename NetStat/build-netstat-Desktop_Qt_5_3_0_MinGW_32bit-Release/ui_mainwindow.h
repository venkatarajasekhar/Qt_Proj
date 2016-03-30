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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *down;
    QLabel *label_3;
    QLabel *up;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(148, 23);
        MainWindow->setMaximumSize(QSize(165, 35));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMaximumSize(QSize(200, 35));
        centralWidget->setStyleSheet(QString::fromUtf8("#centralWidget{\n"
"	background-color: rgba(255, 255, 255, 50);\n"
"	border-width:1px;\n"
"	border-radius:10px;\n"
"}\n"
"#up,#down{\n"
"	color: rgb(85, 170, 255);\n"
"	font: 25 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";\n"
"}"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 147, 22));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(15, 20));
        label->setPixmap(QPixmap(QString::fromUtf8(":/pic/down.png")));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(false);

        horizontalLayout->addWidget(label);

        down = new QLabel(widget);
        down->setObjectName(QStringLiteral("down"));
        down->setMaximumSize(QSize(50, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(3);
        down->setFont(font);

        horizontalLayout->addWidget(down);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(15, 20));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/pic/up.png")));
        label_3->setScaledContents(true);
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_3);

        up = new QLabel(widget);
        up->setObjectName(QStringLiteral("up"));
        up->setMaximumSize(QSize(16777215, 20));

        horizontalLayout->addWidget(up);

        MainWindow->setCentralWidget(centralWidget);
        label->raise();
        down->raise();
        label_3->raise();
        up->raise();
        label->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QString());
        down->setText(QApplication::translate("MainWindow", "0 KB/s", 0));
        label_3->setText(QString());
        up->setText(QApplication::translate("MainWindow", "0 KB/s", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
