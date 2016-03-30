/********************************************************************************
** Form generated from reading UI file 'inputdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTDIALOG_H
#define UI_INPUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_InputDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *editWord;
    QLabel *label_2;
    QLineEdit *editExplain;
    QLabel *label_3;
    QLineEdit *editSentence;
    QSpacerItem *verticalSpacer_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *InputDialog)
    {
        if (InputDialog->objectName().isEmpty())
            InputDialog->setObjectName(QStringLiteral("InputDialog"));
        InputDialog->setWindowModality(Qt::ApplicationModal);
        InputDialog->resize(365, 214);
        InputDialog->setWindowOpacity(0.8);
        InputDialog->setStyleSheet(QLatin1String("#InputDialog{\n"
"	background-image: url(:/image/res/inputdlgbg.png);\n"
"border-radius:10px;\n"
"}"));
        InputDialog->setSizeGripEnabled(false);
        InputDialog->setModal(true);
        verticalLayout = new QVBoxLayout(InputDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(20, 20, 20, 20);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_5 = new QLabel(InputDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(20, 20));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/image/res/logo.png")));
        label_5->setScaledContents(true);

        horizontalLayout->addWidget(label_5);

        label_4 = new QLabel(InputDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(6);
        gridLayout->setVerticalSpacing(20);
        label = new QLabel(InputDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        editWord = new QLineEdit(InputDialog);
        editWord->setObjectName(QStringLiteral("editWord"));

        gridLayout->addWidget(editWord, 0, 1, 1, 1);

        label_2 = new QLabel(InputDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        editExplain = new QLineEdit(InputDialog);
        editExplain->setObjectName(QStringLiteral("editExplain"));

        gridLayout->addWidget(editExplain, 1, 1, 1, 1);

        label_3 = new QLabel(InputDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        editSentence = new QLineEdit(InputDialog);
        editSentence->setObjectName(QStringLiteral("editSentence"));

        gridLayout->addWidget(editSentence, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        buttonBox = new QDialogButtonBox(InputDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(InputDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), InputDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), InputDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(InputDialog);
    } // setupUi

    void retranslateUi(QDialog *InputDialog)
    {
        InputDialog->setWindowTitle(QApplication::translate("InputDialog", "Dialog", 0));
        label_5->setText(QString());
        label_4->setText(QApplication::translate("InputDialog", "\346\267\273\345\212\240\345\210\260\350\257\215\345\205\270...", 0));
        label->setText(QApplication::translate("InputDialog", "\345\215\225\350\257\215\357\274\232", 0));
        label_2->setText(QApplication::translate("InputDialog", "\350\247\243\351\207\212\357\274\232", 0));
        label_3->setText(QApplication::translate("InputDialog", "\344\276\213\345\217\245\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class InputDialog: public Ui_InputDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTDIALOG_H
