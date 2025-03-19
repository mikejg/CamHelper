/********************************************************************************
** Form generated from reading UI file 'dialog_programm.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_PROGRAMM_H
#define UI_DIALOG_PROGRAMM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Programm
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tableView_Programme;

    void setupUi(QDialog *Dialog_Programm)
    {
        if (Dialog_Programm->objectName().isEmpty())
            Dialog_Programm->setObjectName("Dialog_Programm");
        Dialog_Programm->resize(300, 450);
        Dialog_Programm->setMinimumSize(QSize(300, 450));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/programm.png"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog_Programm->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(Dialog_Programm);
        verticalLayout->setObjectName("verticalLayout");
        tableView_Programme = new QTableView(Dialog_Programm);
        tableView_Programme->setObjectName("tableView_Programme");

        verticalLayout->addWidget(tableView_Programme);


        retranslateUi(Dialog_Programm);

        QMetaObject::connectSlotsByName(Dialog_Programm);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Programm)
    {
        Dialog_Programm->setWindowTitle(QCoreApplication::translate("Dialog_Programm", "Programme", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Programm: public Ui_Dialog_Programm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_PROGRAMM_H
