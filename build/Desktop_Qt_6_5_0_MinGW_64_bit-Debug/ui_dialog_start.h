/********************************************************************************
** Form generated from reading UI file 'dialog_start.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_START_H
#define UI_DIALOG_START_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Start
{
public:
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton_New;
    QToolButton *toolButton_Check;
    QToolButton *toolButton_Open;

    void setupUi(QDialog *Dialog_Start)
    {
        if (Dialog_Start->objectName().isEmpty())
            Dialog_Start->setObjectName("Dialog_Start");
        Dialog_Start->resize(234, 82);
        QPalette palette;
        QBrush brush(QColor(8, 8, 8, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        Dialog_Start->setPalette(palette);
        horizontalLayout = new QHBoxLayout(Dialog_Start);
        horizontalLayout->setSpacing(12);
        horizontalLayout->setObjectName("horizontalLayout");
        toolButton_New = new QToolButton(Dialog_Start);
        toolButton_New->setObjectName("toolButton_New");
        toolButton_New->setMinimumSize(QSize(64, 64));
        QPalette palette1;
        QBrush brush1(QColor(11, 11, 11, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        QBrush brush3(QColor(240, 240, 240, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        toolButton_New->setPalette(palette1);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_New->setIcon(icon);
        toolButton_New->setIconSize(QSize(48, 48));

        horizontalLayout->addWidget(toolButton_New);

        toolButton_Check = new QToolButton(Dialog_Start);
        toolButton_Check->setObjectName("toolButton_Check");
        toolButton_Check->setMinimumSize(QSize(64, 64));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        toolButton_Check->setPalette(palette2);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icons/checklist.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_Check->setIcon(icon1);
        toolButton_Check->setIconSize(QSize(48, 48));

        horizontalLayout->addWidget(toolButton_Check);

        toolButton_Open = new QToolButton(Dialog_Start);
        toolButton_Open->setObjectName("toolButton_Open");
        toolButton_Open->setMinimumSize(QSize(64, 64));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        toolButton_Open->setPalette(palette3);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icons/File_Open.png"), QSize(), QIcon::Normal, QIcon::On);
        toolButton_Open->setIcon(icon2);
        toolButton_Open->setIconSize(QSize(48, 48));

        horizontalLayout->addWidget(toolButton_Open);


        retranslateUi(Dialog_Start);

        QMetaObject::connectSlotsByName(Dialog_Start);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Start)
    {
        Dialog_Start->setWindowTitle(QCoreApplication::translate("Dialog_Start", "CamHelper Start", nullptr));
        toolButton_New->setText(QCoreApplication::translate("Dialog_Start", "...", nullptr));
        toolButton_Check->setText(QCoreApplication::translate("Dialog_Start", "...", nullptr));
        toolButton_Open->setText(QCoreApplication::translate("Dialog_Start", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Start: public Ui_Dialog_Start {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_START_H
