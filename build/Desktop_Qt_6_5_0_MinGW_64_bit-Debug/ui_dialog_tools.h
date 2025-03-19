/********************************************************************************
** Form generated from reading UI file 'dialog_tools.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_TOOLS_H
#define UI_DIALOG_TOOLS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Tools
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tableView_Tools;

    void setupUi(QDialog *Dialog_Tools)
    {
        if (Dialog_Tools->objectName().isEmpty())
            Dialog_Tools->setObjectName("Dialog_Tools");
        Dialog_Tools->resize(300, 450);
        Dialog_Tools->setMinimumSize(QSize(300, 450));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/tools.png"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog_Tools->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(Dialog_Tools);
        verticalLayout->setObjectName("verticalLayout");
        tableView_Tools = new QTableView(Dialog_Tools);
        tableView_Tools->setObjectName("tableView_Tools");

        verticalLayout->addWidget(tableView_Tools);


        retranslateUi(Dialog_Tools);

        QMetaObject::connectSlotsByName(Dialog_Tools);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Tools)
    {
        Dialog_Tools->setWindowTitle(QCoreApplication::translate("Dialog_Tools", "Werkzeuge", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Tools: public Ui_Dialog_Tools {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_TOOLS_H
