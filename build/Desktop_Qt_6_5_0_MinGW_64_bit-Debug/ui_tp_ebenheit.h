/********************************************************************************
** Form generated from reading UI file 'tp_ebenheit.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TP_EBENHEIT_H
#define UI_TP_EBENHEIT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mcombobox.h"

QT_BEGIN_NAMESPACE

class Ui_TP_Ebenheit
{
public:
    QVBoxLayout *verticalLayout;
    MComboBox *comboBox_Frame;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_ZEbene;
    QLabel *label_ZEbene;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit_ZEbene;
    QToolButton *toolButton_Paste;
    QHBoxLayout *horizontalLayout_V_Bereich;
    QLabel *label_Vertrauensbereich;
    QSpacerItem *horizontalSpacer_V_Bereich;
    QLineEdit *lineEdit_Vertrauensbereich;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_Punkt1X;
    QLabel *label_Punkt1X;
    QSpacerItem *horizontalSpacer_Punkt1X;
    QLineEdit *lineEdit_Punkt1X;
    QToolButton *toolButton_PasteP1;
    QHBoxLayout *horizontalLayout_Punkt1Y;
    QLabel *label_Punkt1Y;
    QSpacerItem *horizontalSpacer_Punkt1Y;
    QLineEdit *lineEdit_Punkt1Y;
    QCheckBox *checkBox_Jump1;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_Punkt2X;
    QLabel *label_Punkt2X;
    QSpacerItem *horizontalSpacer_Punkt2X;
    QLineEdit *lineEdit_Punkt2X;
    QToolButton *toolButton_PasteP2;
    QHBoxLayout *horizontalLayout_Punkt2Y;
    QLabel *label_Punkt2Y;
    QSpacerItem *horizontalSpacer_Punkt2Y;
    QLineEdit *lineEdit_Punkt2Y;
    QCheckBox *checkBox_Jump2;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_Punkt3X;
    QLabel *label_Punkt3X;
    QSpacerItem *horizontalSpacer_Punkt3X;
    QLineEdit *lineEdit_Punkt3X;
    QToolButton *toolButton_PasteP3;
    QHBoxLayout *horizontalLayout_Punkt3Y;
    QLabel *label_Punkt3Y;
    QSpacerItem *horizontalSpacer_Punkt3Y;
    QLineEdit *lineEdit_Punkt3Y;
    QCheckBox *checkBox_Jump3;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_Punkt4X;
    QLabel *label_Punkt4X;
    QSpacerItem *horizontalSpacer_Punkt4X;
    QLineEdit *lineEdit_Punkt4X;
    QToolButton *toolButton_PasteP4;
    QHBoxLayout *horizontalLayout_Punkt4Y;
    QLabel *label_Punkt4Y;
    QSpacerItem *horizontalSpacer_Punkt4Y;
    QLineEdit *lineEdit_Punkt4Y;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QWidget *TP_Ebenheit)
    {
        if (TP_Ebenheit->objectName().isEmpty())
            TP_Ebenheit->setObjectName("TP_Ebenheit");
        TP_Ebenheit->resize(270, 324);
        TP_Ebenheit->setMaximumSize(QSize(270, 16777215));
        verticalLayout = new QVBoxLayout(TP_Ebenheit);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        comboBox_Frame = new MComboBox(TP_Ebenheit);
        comboBox_Frame->addItem(QString());
        comboBox_Frame->addItem(QString());
        comboBox_Frame->addItem(QString());
        comboBox_Frame->addItem(QString());
        comboBox_Frame->addItem(QString());
        comboBox_Frame->setObjectName("comboBox_Frame");

        verticalLayout->addWidget(comboBox_Frame);

        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_ZEbene = new QHBoxLayout();
        horizontalLayout_ZEbene->setSpacing(0);
        horizontalLayout_ZEbene->setObjectName("horizontalLayout_ZEbene");
        label_ZEbene = new QLabel(TP_Ebenheit);
        label_ZEbene->setObjectName("label_ZEbene");
        label_ZEbene->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_ZEbene->addWidget(label_ZEbene);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_ZEbene->addItem(horizontalSpacer);

        lineEdit_ZEbene = new QLineEdit(TP_Ebenheit);
        lineEdit_ZEbene->setObjectName("lineEdit_ZEbene");
        lineEdit_ZEbene->setEnabled(true);
        lineEdit_ZEbene->setMinimumSize(QSize(75, 0));
        lineEdit_ZEbene->setMaximumSize(QSize(75, 20));
        lineEdit_ZEbene->setAlignment(Qt::AlignCenter);

        horizontalLayout_ZEbene->addWidget(lineEdit_ZEbene);

        toolButton_Paste = new QToolButton(TP_Ebenheit);
        toolButton_Paste->setObjectName("toolButton_Paste");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/paste.png"), QSize(), QIcon::Normal, QIcon::On);
        toolButton_Paste->setIcon(icon);

        horizontalLayout_ZEbene->addWidget(toolButton_Paste);


        verticalLayout->addLayout(horizontalLayout_ZEbene);

        horizontalLayout_V_Bereich = new QHBoxLayout();
        horizontalLayout_V_Bereich->setSpacing(0);
        horizontalLayout_V_Bereich->setObjectName("horizontalLayout_V_Bereich");
        label_Vertrauensbereich = new QLabel(TP_Ebenheit);
        label_Vertrauensbereich->setObjectName("label_Vertrauensbereich");
        label_Vertrauensbereich->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_V_Bereich->addWidget(label_Vertrauensbereich);

        horizontalSpacer_V_Bereich = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_V_Bereich->addItem(horizontalSpacer_V_Bereich);

        lineEdit_Vertrauensbereich = new QLineEdit(TP_Ebenheit);
        lineEdit_Vertrauensbereich->setObjectName("lineEdit_Vertrauensbereich");
        lineEdit_Vertrauensbereich->setEnabled(true);
        lineEdit_Vertrauensbereich->setMinimumSize(QSize(75, 0));
        lineEdit_Vertrauensbereich->setMaximumSize(QSize(75, 20));
        lineEdit_Vertrauensbereich->setAlignment(Qt::AlignCenter);

        horizontalLayout_V_Bereich->addWidget(lineEdit_Vertrauensbereich);

        horizontalSpacer_2 = new QSpacerItem(24, 16, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_V_Bereich->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_V_Bereich);

        verticalSpacer_2 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_Punkt1X = new QHBoxLayout();
        horizontalLayout_Punkt1X->setSpacing(0);
        horizontalLayout_Punkt1X->setObjectName("horizontalLayout_Punkt1X");
        label_Punkt1X = new QLabel(TP_Ebenheit);
        label_Punkt1X->setObjectName("label_Punkt1X");
        label_Punkt1X->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_Punkt1X->addWidget(label_Punkt1X);

        horizontalSpacer_Punkt1X = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Punkt1X->addItem(horizontalSpacer_Punkt1X);

        lineEdit_Punkt1X = new QLineEdit(TP_Ebenheit);
        lineEdit_Punkt1X->setObjectName("lineEdit_Punkt1X");
        lineEdit_Punkt1X->setEnabled(true);
        lineEdit_Punkt1X->setMinimumSize(QSize(75, 0));
        lineEdit_Punkt1X->setMaximumSize(QSize(75, 20));
        lineEdit_Punkt1X->setAlignment(Qt::AlignCenter);

        horizontalLayout_Punkt1X->addWidget(lineEdit_Punkt1X);

        toolButton_PasteP1 = new QToolButton(TP_Ebenheit);
        toolButton_PasteP1->setObjectName("toolButton_PasteP1");
        toolButton_PasteP1->setIcon(icon);

        horizontalLayout_Punkt1X->addWidget(toolButton_PasteP1);


        verticalLayout->addLayout(horizontalLayout_Punkt1X);

        horizontalLayout_Punkt1Y = new QHBoxLayout();
        horizontalLayout_Punkt1Y->setSpacing(0);
        horizontalLayout_Punkt1Y->setObjectName("horizontalLayout_Punkt1Y");
        label_Punkt1Y = new QLabel(TP_Ebenheit);
        label_Punkt1Y->setObjectName("label_Punkt1Y");
        label_Punkt1Y->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_Punkt1Y->addWidget(label_Punkt1Y);

        horizontalSpacer_Punkt1Y = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Punkt1Y->addItem(horizontalSpacer_Punkt1Y);

        lineEdit_Punkt1Y = new QLineEdit(TP_Ebenheit);
        lineEdit_Punkt1Y->setObjectName("lineEdit_Punkt1Y");
        lineEdit_Punkt1Y->setEnabled(true);
        lineEdit_Punkt1Y->setMinimumSize(QSize(75, 0));
        lineEdit_Punkt1Y->setMaximumSize(QSize(75, 20));
        lineEdit_Punkt1Y->setAlignment(Qt::AlignCenter);

        horizontalLayout_Punkt1Y->addWidget(lineEdit_Punkt1Y);

        checkBox_Jump1 = new QCheckBox(TP_Ebenheit);
        checkBox_Jump1->setObjectName("checkBox_Jump1");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(checkBox_Jump1->sizePolicy().hasHeightForWidth());
        checkBox_Jump1->setSizePolicy(sizePolicy);
        checkBox_Jump1->setMinimumSize(QSize(24, 1));
        checkBox_Jump1->setSizeIncrement(QSize(0, 0));
        checkBox_Jump1->setBaseSize(QSize(0, 0));
        checkBox_Jump1->setIconSize(QSize(16, 16));

        horizontalLayout_Punkt1Y->addWidget(checkBox_Jump1);


        verticalLayout->addLayout(horizontalLayout_Punkt1Y);

        verticalSpacer_3 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_Punkt2X = new QHBoxLayout();
        horizontalLayout_Punkt2X->setSpacing(0);
        horizontalLayout_Punkt2X->setObjectName("horizontalLayout_Punkt2X");
        label_Punkt2X = new QLabel(TP_Ebenheit);
        label_Punkt2X->setObjectName("label_Punkt2X");
        label_Punkt2X->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_Punkt2X->addWidget(label_Punkt2X);

        horizontalSpacer_Punkt2X = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Punkt2X->addItem(horizontalSpacer_Punkt2X);

        lineEdit_Punkt2X = new QLineEdit(TP_Ebenheit);
        lineEdit_Punkt2X->setObjectName("lineEdit_Punkt2X");
        lineEdit_Punkt2X->setEnabled(true);
        lineEdit_Punkt2X->setMinimumSize(QSize(75, 0));
        lineEdit_Punkt2X->setMaximumSize(QSize(75, 20));
        lineEdit_Punkt2X->setAlignment(Qt::AlignCenter);

        horizontalLayout_Punkt2X->addWidget(lineEdit_Punkt2X);

        toolButton_PasteP2 = new QToolButton(TP_Ebenheit);
        toolButton_PasteP2->setObjectName("toolButton_PasteP2");
        toolButton_PasteP2->setIcon(icon);

        horizontalLayout_Punkt2X->addWidget(toolButton_PasteP2);


        verticalLayout->addLayout(horizontalLayout_Punkt2X);

        horizontalLayout_Punkt2Y = new QHBoxLayout();
        horizontalLayout_Punkt2Y->setSpacing(0);
        horizontalLayout_Punkt2Y->setObjectName("horizontalLayout_Punkt2Y");
        label_Punkt2Y = new QLabel(TP_Ebenheit);
        label_Punkt2Y->setObjectName("label_Punkt2Y");
        label_Punkt2Y->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_Punkt2Y->addWidget(label_Punkt2Y);

        horizontalSpacer_Punkt2Y = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Punkt2Y->addItem(horizontalSpacer_Punkt2Y);

        lineEdit_Punkt2Y = new QLineEdit(TP_Ebenheit);
        lineEdit_Punkt2Y->setObjectName("lineEdit_Punkt2Y");
        lineEdit_Punkt2Y->setEnabled(true);
        lineEdit_Punkt2Y->setMinimumSize(QSize(75, 0));
        lineEdit_Punkt2Y->setMaximumSize(QSize(75, 20));
        lineEdit_Punkt2Y->setAlignment(Qt::AlignCenter);

        horizontalLayout_Punkt2Y->addWidget(lineEdit_Punkt2Y);

        checkBox_Jump2 = new QCheckBox(TP_Ebenheit);
        checkBox_Jump2->setObjectName("checkBox_Jump2");
        checkBox_Jump2->setMinimumSize(QSize(24, 0));

        horizontalLayout_Punkt2Y->addWidget(checkBox_Jump2);


        verticalLayout->addLayout(horizontalLayout_Punkt2Y);

        verticalSpacer_4 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout_Punkt3X = new QHBoxLayout();
        horizontalLayout_Punkt3X->setSpacing(0);
        horizontalLayout_Punkt3X->setObjectName("horizontalLayout_Punkt3X");
        label_Punkt3X = new QLabel(TP_Ebenheit);
        label_Punkt3X->setObjectName("label_Punkt3X");
        label_Punkt3X->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_Punkt3X->addWidget(label_Punkt3X);

        horizontalSpacer_Punkt3X = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Punkt3X->addItem(horizontalSpacer_Punkt3X);

        lineEdit_Punkt3X = new QLineEdit(TP_Ebenheit);
        lineEdit_Punkt3X->setObjectName("lineEdit_Punkt3X");
        lineEdit_Punkt3X->setEnabled(true);
        lineEdit_Punkt3X->setMinimumSize(QSize(75, 0));
        lineEdit_Punkt3X->setMaximumSize(QSize(75, 20));
        lineEdit_Punkt3X->setAlignment(Qt::AlignCenter);

        horizontalLayout_Punkt3X->addWidget(lineEdit_Punkt3X);

        toolButton_PasteP3 = new QToolButton(TP_Ebenheit);
        toolButton_PasteP3->setObjectName("toolButton_PasteP3");
        toolButton_PasteP3->setIcon(icon);

        horizontalLayout_Punkt3X->addWidget(toolButton_PasteP3);


        verticalLayout->addLayout(horizontalLayout_Punkt3X);

        horizontalLayout_Punkt3Y = new QHBoxLayout();
        horizontalLayout_Punkt3Y->setSpacing(0);
        horizontalLayout_Punkt3Y->setObjectName("horizontalLayout_Punkt3Y");
        label_Punkt3Y = new QLabel(TP_Ebenheit);
        label_Punkt3Y->setObjectName("label_Punkt3Y");
        label_Punkt3Y->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_Punkt3Y->addWidget(label_Punkt3Y);

        horizontalSpacer_Punkt3Y = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Punkt3Y->addItem(horizontalSpacer_Punkt3Y);

        lineEdit_Punkt3Y = new QLineEdit(TP_Ebenheit);
        lineEdit_Punkt3Y->setObjectName("lineEdit_Punkt3Y");
        lineEdit_Punkt3Y->setEnabled(true);
        lineEdit_Punkt3Y->setMinimumSize(QSize(75, 0));
        lineEdit_Punkt3Y->setMaximumSize(QSize(75, 20));
        lineEdit_Punkt3Y->setAlignment(Qt::AlignCenter);

        horizontalLayout_Punkt3Y->addWidget(lineEdit_Punkt3Y);

        checkBox_Jump3 = new QCheckBox(TP_Ebenheit);
        checkBox_Jump3->setObjectName("checkBox_Jump3");
        checkBox_Jump3->setMinimumSize(QSize(24, 0));

        horizontalLayout_Punkt3Y->addWidget(checkBox_Jump3);


        verticalLayout->addLayout(horizontalLayout_Punkt3Y);

        verticalSpacer_5 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_5);

        horizontalLayout_Punkt4X = new QHBoxLayout();
        horizontalLayout_Punkt4X->setSpacing(0);
        horizontalLayout_Punkt4X->setObjectName("horizontalLayout_Punkt4X");
        label_Punkt4X = new QLabel(TP_Ebenheit);
        label_Punkt4X->setObjectName("label_Punkt4X");
        label_Punkt4X->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_Punkt4X->addWidget(label_Punkt4X);

        horizontalSpacer_Punkt4X = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Punkt4X->addItem(horizontalSpacer_Punkt4X);

        lineEdit_Punkt4X = new QLineEdit(TP_Ebenheit);
        lineEdit_Punkt4X->setObjectName("lineEdit_Punkt4X");
        lineEdit_Punkt4X->setEnabled(true);
        lineEdit_Punkt4X->setMinimumSize(QSize(75, 0));
        lineEdit_Punkt4X->setMaximumSize(QSize(75, 20));
        lineEdit_Punkt4X->setAlignment(Qt::AlignCenter);

        horizontalLayout_Punkt4X->addWidget(lineEdit_Punkt4X);

        toolButton_PasteP4 = new QToolButton(TP_Ebenheit);
        toolButton_PasteP4->setObjectName("toolButton_PasteP4");
        toolButton_PasteP4->setIcon(icon);

        horizontalLayout_Punkt4X->addWidget(toolButton_PasteP4);


        verticalLayout->addLayout(horizontalLayout_Punkt4X);

        horizontalLayout_Punkt4Y = new QHBoxLayout();
        horizontalLayout_Punkt4Y->setSpacing(0);
        horizontalLayout_Punkt4Y->setObjectName("horizontalLayout_Punkt4Y");
        label_Punkt4Y = new QLabel(TP_Ebenheit);
        label_Punkt4Y->setObjectName("label_Punkt4Y");
        label_Punkt4Y->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_Punkt4Y->addWidget(label_Punkt4Y);

        horizontalSpacer_Punkt4Y = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Punkt4Y->addItem(horizontalSpacer_Punkt4Y);

        lineEdit_Punkt4Y = new QLineEdit(TP_Ebenheit);
        lineEdit_Punkt4Y->setObjectName("lineEdit_Punkt4Y");
        lineEdit_Punkt4Y->setEnabled(true);
        lineEdit_Punkt4Y->setMinimumSize(QSize(75, 0));
        lineEdit_Punkt4Y->setMaximumSize(QSize(75, 20));
        lineEdit_Punkt4Y->setAlignment(Qt::AlignCenter);

        horizontalLayout_Punkt4Y->addWidget(lineEdit_Punkt4Y);

        horizontalSpacer_6 = new QSpacerItem(24, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_Punkt4Y->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_Punkt4Y);


        retranslateUi(TP_Ebenheit);

        QMetaObject::connectSlotsByName(TP_Ebenheit);
    } // setupUi

    void retranslateUi(QWidget *TP_Ebenheit)
    {
        TP_Ebenheit->setWindowTitle(QCoreApplication::translate("TP_Ebenheit", "Form", nullptr));
        comboBox_Frame->setItemText(0, QCoreApplication::translate("TP_Ebenheit", "Oben", nullptr));
        comboBox_Frame->setItemText(1, QCoreApplication::translate("TP_Ebenheit", "Hinten", nullptr));
        comboBox_Frame->setItemText(2, QCoreApplication::translate("TP_Ebenheit", "Links", nullptr));
        comboBox_Frame->setItemText(3, QCoreApplication::translate("TP_Ebenheit", "Vorne", nullptr));
        comboBox_Frame->setItemText(4, QCoreApplication::translate("TP_Ebenheit", "Rechts", nullptr));

        label_ZEbene->setText(QCoreApplication::translate("TP_Ebenheit", "Z_Ebene", nullptr));
        lineEdit_ZEbene->setText(QString());
        toolButton_Paste->setText(QCoreApplication::translate("TP_Ebenheit", "...", nullptr));
        label_Vertrauensbereich->setText(QCoreApplication::translate("TP_Ebenheit", "Vertrauensbereich", nullptr));
        lineEdit_Vertrauensbereich->setText(QString());
        label_Punkt1X->setText(QCoreApplication::translate("TP_Ebenheit", "Punkt1 X", nullptr));
        lineEdit_Punkt1X->setText(QString());
        toolButton_PasteP1->setText(QCoreApplication::translate("TP_Ebenheit", "...", nullptr));
        label_Punkt1Y->setText(QCoreApplication::translate("TP_Ebenheit", "Punkt1 Y", nullptr));
        lineEdit_Punkt1Y->setText(QString());
        checkBox_Jump1->setText(QString());
        label_Punkt2X->setText(QCoreApplication::translate("TP_Ebenheit", "Punkt2 X", nullptr));
        lineEdit_Punkt2X->setText(QString());
        toolButton_PasteP2->setText(QCoreApplication::translate("TP_Ebenheit", "...", nullptr));
        label_Punkt2Y->setText(QCoreApplication::translate("TP_Ebenheit", "Punkt2 Y", nullptr));
        lineEdit_Punkt2Y->setText(QString());
        checkBox_Jump2->setText(QString());
        label_Punkt3X->setText(QCoreApplication::translate("TP_Ebenheit", "Punkt3 X", nullptr));
        lineEdit_Punkt3X->setText(QString());
        toolButton_PasteP3->setText(QCoreApplication::translate("TP_Ebenheit", "...", nullptr));
        label_Punkt3Y->setText(QCoreApplication::translate("TP_Ebenheit", "Punkt3 Y", nullptr));
        lineEdit_Punkt3Y->setText(QString());
        checkBox_Jump3->setText(QString());
        label_Punkt4X->setText(QCoreApplication::translate("TP_Ebenheit", "Punkt4 X", nullptr));
        lineEdit_Punkt4X->setText(QString());
        toolButton_PasteP4->setText(QCoreApplication::translate("TP_Ebenheit", "...", nullptr));
        label_Punkt4Y->setText(QCoreApplication::translate("TP_Ebenheit", "Punkt4 Y", nullptr));
        lineEdit_Punkt4Y->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TP_Ebenheit: public Ui_TP_Ebenheit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TP_EBENHEIT_H
