/********************************************************************************
** Form generated from reading UI file 'imgdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMGDIALOG_H
#define UI_IMGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ImgDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QDialog *ImgDialog)
    {
        if (ImgDialog->objectName().isEmpty())
            ImgDialog->setObjectName(QStringLiteral("ImgDialog"));
        ImgDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(ImgDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(ImgDialog);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);


        retranslateUi(ImgDialog);

        QMetaObject::connectSlotsByName(ImgDialog);
    } // setupUi

    void retranslateUi(QDialog *ImgDialog)
    {
        ImgDialog->setWindowTitle(QApplication::translate("ImgDialog", "Dialog", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ImgDialog: public Ui_ImgDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMGDIALOG_H
