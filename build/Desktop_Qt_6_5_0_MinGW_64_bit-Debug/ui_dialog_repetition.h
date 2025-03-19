/********************************************************************************
** Form generated from reading UI file 'dialog_repetition.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_REPETITION_H
#define UI_DIALOG_REPETITION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Repetition
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_LastProduction;
    QRadioButton *radioButton_Import;
    QRadioButton *radioButton_Paket;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog_Repetition)
    {
        if (Dialog_Repetition->objectName().isEmpty())
            Dialog_Repetition->setObjectName("Dialog_Repetition");
        Dialog_Repetition->resize(416, 120);
        verticalLayout = new QVBoxLayout(Dialog_Repetition);
        verticalLayout->setObjectName("verticalLayout");
        label_LastProduction = new QLabel(Dialog_Repetition);
        label_LastProduction->setObjectName("label_LastProduction");

        verticalLayout->addWidget(label_LastProduction);

        radioButton_Import = new QRadioButton(Dialog_Repetition);
        radioButton_Import->setObjectName("radioButton_Import");

        verticalLayout->addWidget(radioButton_Import);

        radioButton_Paket = new QRadioButton(Dialog_Repetition);
        radioButton_Paket->setObjectName("radioButton_Paket");

        verticalLayout->addWidget(radioButton_Paket);

        buttonBox = new QDialogButtonBox(Dialog_Repetition);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Dialog_Repetition);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Dialog_Repetition, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Dialog_Repetition, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Dialog_Repetition);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Repetition)
    {
        Dialog_Repetition->setWindowTitle(QCoreApplication::translate("Dialog_Repetition", "Wiederholfertigung", nullptr));
        label_LastProduction->setText(QCoreApplication::translate("Dialog_Repetition", "TextLabel", nullptr));
        radioButton_Import->setText(QCoreApplication::translate("Dialog_Repetition", "Import  Wiederholfertigung in Datenbank", nullptr));
        radioButton_Paket->setText(QCoreApplication::translate("Dialog_Repetition", "Erstelle Paket", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Repetition: public Ui_Dialog_Repetition {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_REPETITION_H
