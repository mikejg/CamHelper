/********************************************************************************
** Form generated from reading UI file 'dialog_progress.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_PROGRESS_H
#define UI_DIALOG_PROGRESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Progress
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QProgressBar *progressBar;

    void setupUi(QDialog *Dialog_Progress)
    {
        if (Dialog_Progress->objectName().isEmpty())
            Dialog_Progress->setObjectName("Dialog_Progress");
        Dialog_Progress->resize(400, 82);
        verticalLayout = new QVBoxLayout(Dialog_Progress);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(Dialog_Progress);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        progressBar = new QProgressBar(Dialog_Progress);
        progressBar->setObjectName("progressBar");
        progressBar->setValue(24);

        verticalLayout->addWidget(progressBar);


        retranslateUi(Dialog_Progress);

        QMetaObject::connectSlotsByName(Dialog_Progress);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Progress)
    {
        Dialog_Progress->setWindowTitle(QCoreApplication::translate("Dialog_Progress", "Speichern", nullptr));
        label->setText(QCoreApplication::translate("Dialog_Progress", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Progress: public Ui_Dialog_Progress {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_PROGRESS_H
