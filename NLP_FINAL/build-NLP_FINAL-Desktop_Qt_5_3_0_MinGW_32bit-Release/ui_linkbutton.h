/********************************************************************************
** Form generated from reading UI file 'linkbutton.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINKBUTTON_H
#define UI_LINKBUTTON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LinkButton
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;

    void setupUi(QWidget *LinkButton)
    {
        if (LinkButton->objectName().isEmpty())
            LinkButton->setObjectName(QStringLiteral("LinkButton"));
        LinkButton->resize(244, 41);
        horizontalLayout = new QHBoxLayout(LinkButton);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(LinkButton);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/res/find.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);

        horizontalLayout->addWidget(pushButton);


        retranslateUi(LinkButton);

        QMetaObject::connectSlotsByName(LinkButton);
    } // setupUi

    void retranslateUi(QWidget *LinkButton)
    {
        LinkButton->setWindowTitle(QApplication::translate("LinkButton", "Form", 0));
        pushButton->setText(QApplication::translate("LinkButton", "\351\200\232\350\277\207\347\275\221\347\273\234\350\216\267\345\217\226\346\233\264\345\244\232\347\273\223\346\236\234...", 0));
    } // retranslateUi

};

namespace Ui {
    class LinkButton: public Ui_LinkButton {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINKBUTTON_H
