/********************************************************************************
** Form generated from reading UI file 'pix_scrollcontent.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PIX_SCROLLCONTENT_H
#define UI_PIX_SCROLLCONTENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Pix_ScrollContent
{
public:

    void setupUi(QWidget *Pix_ScrollContent)
    {
        if (Pix_ScrollContent->objectName().isEmpty())
            Pix_ScrollContent->setObjectName("Pix_ScrollContent");
        Pix_ScrollContent->resize(400, 300);

        retranslateUi(Pix_ScrollContent);

        QMetaObject::connectSlotsByName(Pix_ScrollContent);
    } // setupUi

    void retranslateUi(QWidget *Pix_ScrollContent)
    {
        Pix_ScrollContent->setWindowTitle(QCoreApplication::translate("Pix_ScrollContent", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Pix_ScrollContent: public Ui_Pix_ScrollContent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PIX_SCROLLCONTENT_H
