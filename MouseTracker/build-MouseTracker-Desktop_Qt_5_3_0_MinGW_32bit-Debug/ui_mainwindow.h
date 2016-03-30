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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_x;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *label_y;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_x2;
    QLabel *label_pos_x;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_y2;
    QLabel *label_pos_y;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_x3;
    QLabel *label_geo_x;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_y3;
    QLabel *label_geo_y;
    QLabel *label_info;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 400);
        MainWindow->setMinimumSize(QSize(400, 400));
        MainWindow->setMaximumSize(QSize(400, 400));
        MainWindow->setStyleSheet(QString::fromUtf8("QLabel{font: 24pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(64, 24));
        label->setMaximumSize(QSize(256, 16777215));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        label_x = new QLabel(centralWidget);
        label_x->setObjectName(QStringLiteral("label_x"));
        label_x->setMinimumSize(QSize(128, 24));
        label_x->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_x);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(64, 24));
        label_2->setMaximumSize(QSize(256, 16777215));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);

        label_y = new QLabel(centralWidget);
        label_y->setObjectName(QStringLiteral("label_y"));
        label_y->setMinimumSize(QSize(128, 24));
        label_y->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_y);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_x2 = new QLabel(centralWidget);
        label_x2->setObjectName(QStringLiteral("label_x2"));
        label_x2->setMinimumSize(QSize(64, 24));
        label_x2->setMaximumSize(QSize(256, 16777215));
        label_x2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_x2);

        label_pos_x = new QLabel(centralWidget);
        label_pos_x->setObjectName(QStringLiteral("label_pos_x"));
        label_pos_x->setMinimumSize(QSize(128, 24));
        label_pos_x->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_pos_x);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_y2 = new QLabel(centralWidget);
        label_y2->setObjectName(QStringLiteral("label_y2"));
        label_y2->setMinimumSize(QSize(64, 24));
        label_y2->setMaximumSize(QSize(256, 16777215));
        label_y2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_y2);

        label_pos_y = new QLabel(centralWidget);
        label_pos_y->setObjectName(QStringLiteral("label_pos_y"));
        label_pos_y->setMinimumSize(QSize(128, 24));
        label_pos_y->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_pos_y);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_x3 = new QLabel(centralWidget);
        label_x3->setObjectName(QStringLiteral("label_x3"));
        label_x3->setMinimumSize(QSize(64, 24));
        label_x3->setMaximumSize(QSize(256, 16777215));
        label_x3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_x3);

        label_geo_x = new QLabel(centralWidget);
        label_geo_x->setObjectName(QStringLiteral("label_geo_x"));
        label_geo_x->setMinimumSize(QSize(128, 24));
        label_geo_x->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_geo_x);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_y3 = new QLabel(centralWidget);
        label_y3->setObjectName(QStringLiteral("label_y3"));
        label_y3->setMinimumSize(QSize(64, 24));
        label_y3->setMaximumSize(QSize(256, 16777215));
        label_y3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_y3);

        label_geo_y = new QLabel(centralWidget);
        label_geo_y->setObjectName(QStringLiteral("label_geo_y"));
        label_geo_y->setMinimumSize(QSize(128, 24));
        label_geo_y->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_geo_y);


        verticalLayout->addLayout(horizontalLayout_6);

        label_info = new QLabel(centralWidget);
        label_info->setObjectName(QStringLiteral("label_info"));
        label_info->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_info);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "Mouse.X:", 0));
        label_x->setText(QApplication::translate("MainWindow", "0", 0));
        label_2->setText(QApplication::translate("MainWindow", "Mouse.Y:", 0));
        label_y->setText(QApplication::translate("MainWindow", "0", 0));
        label_x2->setText(QApplication::translate("MainWindow", "Cli.Geo.X:", 0));
        label_pos_x->setText(QApplication::translate("MainWindow", "0", 0));
        label_y2->setText(QApplication::translate("MainWindow", "Cli.Geo.y:", 0));
        label_pos_y->setText(QApplication::translate("MainWindow", "0", 0));
        label_x3->setText(QApplication::translate("MainWindow", "Win.Geo.X:", 0));
        label_geo_x->setText(QApplication::translate("MainWindow", "0", 0));
        label_y3->setText(QApplication::translate("MainWindow", "Win.Geo.y:", 0));
        label_geo_y->setText(QApplication::translate("MainWindow", "0", 0));
        label_info->setText(QApplication::translate("MainWindow", "Mouse Inside Window", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
