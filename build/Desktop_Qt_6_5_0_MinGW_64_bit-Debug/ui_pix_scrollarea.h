/********************************************************************************
** Form generated from reading UI file 'pix_scrollarea.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PIX_SCROLLAREA_H
#define UI_PIX_SCROLLAREA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QScrollArea>

QT_BEGIN_NAMESPACE

class Ui_Pix_ScrollArea
{
public:

    void setupUi(QScrollArea *Pix_ScrollArea)
    {
        if (Pix_ScrollArea->objectName().isEmpty())
            Pix_ScrollArea->setObjectName("Pix_ScrollArea");
        Pix_ScrollArea->resize(400, 300);

        retranslateUi(Pix_ScrollArea);

        QMetaObject::connectSlotsByName(Pix_ScrollArea);
    } // setupUi

    void retranslateUi(QScrollArea *Pix_ScrollArea)
    {
        Pix_ScrollArea->setWindowTitle(QCoreApplication::translate("Pix_ScrollArea", "ScrollArea", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Pix_ScrollArea: public Ui_Pix_ScrollArea {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PIX_SCROLLAREA_H
