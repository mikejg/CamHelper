/********************************************************************************
** Form generated from reading UI file 'selectorwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTORWIDGET_H
#define UI_SELECTORWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_SelectorWidget
{
public:

    void setupUi(QDialog *SelectorWidget)
    {
        if (SelectorWidget->objectName().isEmpty())
            SelectorWidget->setObjectName("SelectorWidget");
        SelectorWidget->resize(400, 300);

        retranslateUi(SelectorWidget);

        QMetaObject::connectSlotsByName(SelectorWidget);
    } // setupUi

    void retranslateUi(QDialog *SelectorWidget)
    {
        SelectorWidget->setWindowTitle(QCoreApplication::translate("SelectorWidget", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SelectorWidget: public Ui_SelectorWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTORWIDGET_H
