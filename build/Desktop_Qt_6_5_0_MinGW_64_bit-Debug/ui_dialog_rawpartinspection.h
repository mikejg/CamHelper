/********************************************************************************
** Form generated from reading UI file 'dialog_rawpartinspection.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_RAWPARTINSPECTION_H
#define UI_DIALOG_RAWPARTINSPECTION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_RawPartInspection
{
public:
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButton_RawPartInspection_00;
    QToolButton *toolButton_RawPartInspection_01;
    QToolButton *toolButton_RawPartInspection_02;
    QToolButton *toolButton_RawPartInspection_03;

    void setupUi(QDialog *Dialog_RawPartInspection)
    {
        if (Dialog_RawPartInspection->objectName().isEmpty())
            Dialog_RawPartInspection->setObjectName("Dialog_RawPartInspection");
        Dialog_RawPartInspection->resize(796, 200);
        Dialog_RawPartInspection->setMinimumSize(QSize(600, 200));
        horizontalLayout = new QHBoxLayout(Dialog_RawPartInspection);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(Dialog_RawPartInspection);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 794, 198));
        horizontalLayout_2 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        toolButton_RawPartInspection_00 = new QToolButton(scrollAreaWidgetContents);
        toolButton_RawPartInspection_00->setObjectName("toolButton_RawPartInspection_00");
        toolButton_RawPartInspection_00->setMinimumSize(QSize(192, 192));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/RawPartInspection/RawPartInspection00_192.png"), QSize(), QIcon::Normal, QIcon::On);
        toolButton_RawPartInspection_00->setIcon(icon);
        toolButton_RawPartInspection_00->setIconSize(QSize(192, 192));

        horizontalLayout_2->addWidget(toolButton_RawPartInspection_00);

        toolButton_RawPartInspection_01 = new QToolButton(scrollAreaWidgetContents);
        toolButton_RawPartInspection_01->setObjectName("toolButton_RawPartInspection_01");
        toolButton_RawPartInspection_01->setMinimumSize(QSize(192, 192));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icons/RawPartInspection/RawPartInspection01_192.png"), QSize(), QIcon::Normal, QIcon::On);
        toolButton_RawPartInspection_01->setIcon(icon1);
        toolButton_RawPartInspection_01->setIconSize(QSize(192, 192));

        horizontalLayout_2->addWidget(toolButton_RawPartInspection_01);

        toolButton_RawPartInspection_02 = new QToolButton(scrollAreaWidgetContents);
        toolButton_RawPartInspection_02->setObjectName("toolButton_RawPartInspection_02");
        toolButton_RawPartInspection_02->setMinimumSize(QSize(192, 192));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icons/RawPartInspection/RawPartInspection02_192.png"), QSize(), QIcon::Normal, QIcon::On);
        toolButton_RawPartInspection_02->setIcon(icon2);
        toolButton_RawPartInspection_02->setIconSize(QSize(192, 192));

        horizontalLayout_2->addWidget(toolButton_RawPartInspection_02);

        toolButton_RawPartInspection_03 = new QToolButton(scrollAreaWidgetContents);
        toolButton_RawPartInspection_03->setObjectName("toolButton_RawPartInspection_03");
        toolButton_RawPartInspection_03->setMinimumSize(QSize(192, 192));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Icons/RawPartInspection/RawPartInspection03_192.PNG"), QSize(), QIcon::Normal, QIcon::On);
        toolButton_RawPartInspection_03->setIcon(icon3);
        toolButton_RawPartInspection_03->setIconSize(QSize(192, 192));

        horizontalLayout_2->addWidget(toolButton_RawPartInspection_03);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(scrollArea);


        retranslateUi(Dialog_RawPartInspection);

        QMetaObject::connectSlotsByName(Dialog_RawPartInspection);
    } // setupUi

    void retranslateUi(QDialog *Dialog_RawPartInspection)
    {
        Dialog_RawPartInspection->setWindowTitle(QCoreApplication::translate("Dialog_RawPartInspection", "Rohteilkontrolle", nullptr));
        toolButton_RawPartInspection_00->setText(QCoreApplication::translate("Dialog_RawPartInspection", "...", nullptr));
        toolButton_RawPartInspection_01->setText(QCoreApplication::translate("Dialog_RawPartInspection", "...", nullptr));
        toolButton_RawPartInspection_02->setText(QCoreApplication::translate("Dialog_RawPartInspection", "...", nullptr));
        toolButton_RawPartInspection_03->setText(QCoreApplication::translate("Dialog_RawPartInspection", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_RawPartInspection: public Ui_Dialog_RawPartInspection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_RAWPARTINSPECTION_H
