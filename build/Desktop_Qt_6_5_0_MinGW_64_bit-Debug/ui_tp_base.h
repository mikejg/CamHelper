/********************************************************************************
** Form generated from reading UI file 'tp_base.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TP_BASE_H
#define UI_TP_BASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TP_Base
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;

    void setupUi(QWidget *TP_Base)
    {
        if (TP_Base->objectName().isEmpty())
            TP_Base->setObjectName("TP_Base");
        TP_Base->resize(147, 44);
        verticalLayout = new QVBoxLayout(TP_Base);
        verticalLayout->setObjectName("verticalLayout");
        pushButton = new QPushButton(TP_Base);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);


        retranslateUi(TP_Base);

        QMetaObject::connectSlotsByName(TP_Base);
    } // setupUi

    void retranslateUi(QWidget *TP_Base)
    {
        TP_Base->setWindowTitle(QCoreApplication::translate("TP_Base", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("TP_Base", "TP_Base", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TP_Base: public Ui_TP_Base {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TP_BASE_H
