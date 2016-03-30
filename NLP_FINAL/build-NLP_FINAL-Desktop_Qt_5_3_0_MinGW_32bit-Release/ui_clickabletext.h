/********************************************************************************
** Form generated from reading UI file 'clickabletext.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLICKABLETEXT_H
#define UI_CLICKABLETEXT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_ClickableText
{
public:
    QHBoxLayout *horizontalLayout;
    QCommandLinkButton *linkButton;

    void setupUi(QDialog *ClickableText)
    {
        if (ClickableText->objectName().isEmpty())
            ClickableText->setObjectName(QStringLiteral("ClickableText"));
        ClickableText->resize(256, 53);
        ClickableText->setStyleSheet(QStringLiteral("#ClickableText{background-color: rgba(255, 255, 255, 0);}"));
        horizontalLayout = new QHBoxLayout(ClickableText);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        linkButton = new QCommandLinkButton(ClickableText);
        linkButton->setObjectName(QStringLiteral("linkButton"));

        horizontalLayout->addWidget(linkButton);


        retranslateUi(ClickableText);

        QMetaObject::connectSlotsByName(ClickableText);
    } // setupUi

    void retranslateUi(QDialog *ClickableText)
    {
        ClickableText->setWindowTitle(QApplication::translate("ClickableText", "Dialog", 0));
        linkButton->setText(QApplication::translate("ClickableText", "\351\200\232\350\277\207\347\275\221\347\273\234\346\237\245\350\257\242\346\233\264\345\244\232\347\273\223\346\236\234...", 0));
    } // retranslateUi

};

namespace Ui {
    class ClickableText: public Ui_ClickableText {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLICKABLETEXT_H
