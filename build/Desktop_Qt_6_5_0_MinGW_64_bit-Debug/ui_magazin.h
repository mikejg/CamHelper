/********************************************************************************
** Form generated from reading UI file 'magazin.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAGAZIN_H
#define UI_MAGAZIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Magazin
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QTableView *tableView;

    void setupUi(QWidget *Magazin)
    {
        if (Magazin->objectName().isEmpty())
            Magazin->setObjectName("Magazin");
        Magazin->resize(668, 359);
        verticalLayout = new QVBoxLayout(Magazin);
        verticalLayout->setObjectName("verticalLayout");
        lineEdit = new QLineEdit(Magazin);
        lineEdit->setObjectName("lineEdit");

        verticalLayout->addWidget(lineEdit);

        tableView = new QTableView(Magazin);
        tableView->setObjectName("tableView");
        tableView->horizontalHeader()->setDefaultSectionSize(100);
        tableView->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(tableView);


        retranslateUi(Magazin);

        QMetaObject::connectSlotsByName(Magazin);
    } // setupUi

    void retranslateUi(QWidget *Magazin)
    {
        Magazin->setWindowTitle(QCoreApplication::translate("Magazin", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Magazin: public Ui_Magazin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAGAZIN_H
