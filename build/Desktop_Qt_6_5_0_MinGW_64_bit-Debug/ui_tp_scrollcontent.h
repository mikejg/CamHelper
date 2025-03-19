/********************************************************************************
** Form generated from reading UI file 'tp_scrollcontent.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TP_SCROLLCONTENT_H
#define UI_TP_SCROLLCONTENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TP_ScrollContent
{
public:

    void setupUi(QWidget *TP_ScrollContent)
    {
        if (TP_ScrollContent->objectName().isEmpty())
            TP_ScrollContent->setObjectName("TP_ScrollContent");
        TP_ScrollContent->resize(400, 300);
        TP_ScrollContent->setAcceptDrops(true);

        retranslateUi(TP_ScrollContent);

        QMetaObject::connectSlotsByName(TP_ScrollContent);
    } // setupUi

    void retranslateUi(QWidget *TP_ScrollContent)
    {
        TP_ScrollContent->setWindowTitle(QCoreApplication::translate("TP_ScrollContent", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TP_ScrollContent: public Ui_TP_ScrollContent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TP_SCROLLCONTENT_H
