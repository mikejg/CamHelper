/********************************************************************************
** Form generated from reading UI file 'tp_nut.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TP_NUT_H
#define UI_TP_NUT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mcombobox.h"

QT_BEGIN_NAMESPACE

class Ui_TP_Nut
{
public:
    QVBoxLayout *verticalLayout;
    MComboBox *comboBox_Frame;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_Nullpunktverschiebung_2;
    QLineEdit *lineEdit_Nullpunkverschiebung_2;
    QHBoxLayout *horizontalLayout_Aktive_NPV_2;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *lineEdit_Aktive_NPV_3;
    QSpacerItem *horizontalSpacer_8;
    QLineEdit *lineEdit_Aktive_NPV_4;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_Messachse;
    QLabel *label_Messrichtung_2;
    QSpacerItem *horizontalSpacer_9;
    MComboBox *comboBox_Messachse;
    QHBoxLayout *horizontalLayout_W;
    QLabel *label_W;
    QLineEdit *lineEdit_W;
    QSpacerItem *horizontalSpacer_11;
    QHBoxLayout *horizontalLayout_Alpha_2;
    QLabel *label_Alpha_2;
    QLineEdit *lineEdit_Alpha_2;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *horizontalLayout_Schutzzone_2;
    QLabel *label_Schutzzone;
    QSpacerItem *horizontalSpacer_13;
    QLineEdit *lineEdit_Schutzzone;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_DFA;
    QLabel *label_DFA;
    QLineEdit *lineEdit_DFA;
    QSpacerItem *horizontalSpacer_DFA;
    QHBoxLayout *horizontalLayout_TSA;
    QLabel *label_TSA;
    QLineEdit *lineEdit_TSA;
    QSpacerItem *horizontalSpacer_TSA;
    QToolButton *toolButton_Paste;
    QTextEdit *textEdit_Anfahren;

    void setupUi(QWidget *TP_Nut)
    {
        if (TP_Nut->objectName().isEmpty())
            TP_Nut->setObjectName("TP_Nut");
        TP_Nut->resize(202, 348);
        TP_Nut->setMaximumSize(QSize(270, 16777215));
        verticalLayout = new QVBoxLayout(TP_Nut);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        comboBox_Frame = new MComboBox(TP_Nut);
        comboBox_Frame->addItem(QString());
        comboBox_Frame->addItem(QString());
        comboBox_Frame->addItem(QString());
        comboBox_Frame->addItem(QString());
        comboBox_Frame->addItem(QString());
        comboBox_Frame->setObjectName("comboBox_Frame");

        verticalLayout->addWidget(comboBox_Frame);

        verticalSpacer_2 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_Nullpunktverschiebung_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_Nullpunktverschiebung_2);

        lineEdit_Nullpunkverschiebung_2 = new QLineEdit(TP_Nut);
        lineEdit_Nullpunkverschiebung_2->setObjectName("lineEdit_Nullpunkverschiebung_2");
        lineEdit_Nullpunkverschiebung_2->setEnabled(false);
        lineEdit_Nullpunkverschiebung_2->setMinimumSize(QSize(200, 0));
        lineEdit_Nullpunkverschiebung_2->setMaximumSize(QSize(200, 20));
        lineEdit_Nullpunkverschiebung_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lineEdit_Nullpunkverschiebung_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_Aktive_NPV_2 = new QHBoxLayout();
        horizontalLayout_Aktive_NPV_2->setSpacing(0);
        horizontalLayout_Aktive_NPV_2->setObjectName("horizontalLayout_Aktive_NPV_2");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Aktive_NPV_2->addItem(horizontalSpacer_4);

        lineEdit_Aktive_NPV_3 = new QLineEdit(TP_Nut);
        lineEdit_Aktive_NPV_3->setObjectName("lineEdit_Aktive_NPV_3");
        lineEdit_Aktive_NPV_3->setEnabled(false);
        lineEdit_Aktive_NPV_3->setMinimumSize(QSize(120, 0));
        lineEdit_Aktive_NPV_3->setMaximumSize(QSize(120, 20));
        lineEdit_Aktive_NPV_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_Aktive_NPV_2->addWidget(lineEdit_Aktive_NPV_3);

        horizontalSpacer_8 = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_Aktive_NPV_2->addItem(horizontalSpacer_8);

        lineEdit_Aktive_NPV_4 = new QLineEdit(TP_Nut);
        lineEdit_Aktive_NPV_4->setObjectName("lineEdit_Aktive_NPV_4");
        lineEdit_Aktive_NPV_4->setEnabled(false);
        lineEdit_Aktive_NPV_4->setMinimumSize(QSize(55, 0));
        lineEdit_Aktive_NPV_4->setMaximumSize(QSize(55, 20));
        lineEdit_Aktive_NPV_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_Aktive_NPV_2->addWidget(lineEdit_Aktive_NPV_4);


        verticalLayout->addLayout(horizontalLayout_Aktive_NPV_2);

        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_Messachse = new QHBoxLayout();
        horizontalLayout_Messachse->setSpacing(2);
        horizontalLayout_Messachse->setObjectName("horizontalLayout_Messachse");
        label_Messrichtung_2 = new QLabel(TP_Nut);
        label_Messrichtung_2->setObjectName("label_Messrichtung_2");
        label_Messrichtung_2->setEnabled(true);
        label_Messrichtung_2->setMinimumSize(QSize(0, 20));
        label_Messrichtung_2->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_Messachse->addWidget(label_Messrichtung_2);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Messachse->addItem(horizontalSpacer_9);

        comboBox_Messachse = new MComboBox(TP_Nut);
        comboBox_Messachse->addItem(QString());
        comboBox_Messachse->addItem(QString());
        comboBox_Messachse->setObjectName("comboBox_Messachse");
        comboBox_Messachse->setMinimumSize(QSize(70, 20));
        comboBox_Messachse->setMaximumSize(QSize(70, 20));

        horizontalLayout_Messachse->addWidget(comboBox_Messachse);


        verticalLayout->addLayout(horizontalLayout_Messachse);

        horizontalLayout_W = new QHBoxLayout();
        horizontalLayout_W->setSpacing(0);
        horizontalLayout_W->setObjectName("horizontalLayout_W");
        label_W = new QLabel(TP_Nut);
        label_W->setObjectName("label_W");
        label_W->setMinimumSize(QSize(40, 20));
        label_W->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_W->addWidget(label_W);

        lineEdit_W = new QLineEdit(TP_Nut);
        lineEdit_W->setObjectName("lineEdit_W");
        lineEdit_W->setMinimumSize(QSize(95, 20));
        lineEdit_W->setMaximumSize(QSize(95, 16777215));
        lineEdit_W->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_W->addWidget(lineEdit_W);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_W->addItem(horizontalSpacer_11);


        verticalLayout->addLayout(horizontalLayout_W);

        horizontalLayout_Alpha_2 = new QHBoxLayout();
        horizontalLayout_Alpha_2->setSpacing(0);
        horizontalLayout_Alpha_2->setObjectName("horizontalLayout_Alpha_2");
        label_Alpha_2 = new QLabel(TP_Nut);
        label_Alpha_2->setObjectName("label_Alpha_2");
        label_Alpha_2->setEnabled(false);
        label_Alpha_2->setMinimumSize(QSize(40, 20));
        label_Alpha_2->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_Alpha_2->addWidget(label_Alpha_2);

        lineEdit_Alpha_2 = new QLineEdit(TP_Nut);
        lineEdit_Alpha_2->setObjectName("lineEdit_Alpha_2");
        lineEdit_Alpha_2->setEnabled(false);
        lineEdit_Alpha_2->setMinimumSize(QSize(75, 20));
        lineEdit_Alpha_2->setMaximumSize(QSize(95, 16777215));
        lineEdit_Alpha_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_Alpha_2->addWidget(lineEdit_Alpha_2);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Alpha_2->addItem(horizontalSpacer_12);


        verticalLayout->addLayout(horizontalLayout_Alpha_2);

        horizontalLayout_Schutzzone_2 = new QHBoxLayout();
        horizontalLayout_Schutzzone_2->setSpacing(0);
        horizontalLayout_Schutzzone_2->setObjectName("horizontalLayout_Schutzzone_2");
        label_Schutzzone = new QLabel(TP_Nut);
        label_Schutzzone->setObjectName("label_Schutzzone");
        label_Schutzzone->setEnabled(true);
        label_Schutzzone->setMinimumSize(QSize(0, 20));
        label_Schutzzone->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_Schutzzone_2->addWidget(label_Schutzzone);

        horizontalSpacer_13 = new QSpacerItem(25, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Schutzzone_2->addItem(horizontalSpacer_13);

        lineEdit_Schutzzone = new QLineEdit(TP_Nut);
        lineEdit_Schutzzone->setObjectName("lineEdit_Schutzzone");
        lineEdit_Schutzzone->setEnabled(false);
        lineEdit_Schutzzone->setMinimumSize(QSize(70, 0));
        lineEdit_Schutzzone->setMaximumSize(QSize(70, 20));
        lineEdit_Schutzzone->setAlignment(Qt::AlignCenter);

        horizontalLayout_Schutzzone_2->addWidget(lineEdit_Schutzzone);


        verticalLayout->addLayout(horizontalLayout_Schutzzone_2);

        verticalSpacer_3 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_DFA = new QHBoxLayout();
        horizontalLayout_DFA->setObjectName("horizontalLayout_DFA");
        label_DFA = new QLabel(TP_Nut);
        label_DFA->setObjectName("label_DFA");
        label_DFA->setMinimumSize(QSize(45, 0));
        label_DFA->setMaximumSize(QSize(45, 20));

        horizontalLayout_DFA->addWidget(label_DFA);

        lineEdit_DFA = new QLineEdit(TP_Nut);
        lineEdit_DFA->setObjectName("lineEdit_DFA");
        lineEdit_DFA->setMaximumSize(QSize(75, 20));
        lineEdit_DFA->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_DFA->addWidget(lineEdit_DFA);

        horizontalSpacer_DFA = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_DFA->addItem(horizontalSpacer_DFA);


        verticalLayout->addLayout(horizontalLayout_DFA);

        horizontalLayout_TSA = new QHBoxLayout();
        horizontalLayout_TSA->setObjectName("horizontalLayout_TSA");
        label_TSA = new QLabel(TP_Nut);
        label_TSA->setObjectName("label_TSA");
        label_TSA->setMinimumSize(QSize(45, 0));
        label_TSA->setMaximumSize(QSize(45, 20));

        horizontalLayout_TSA->addWidget(label_TSA);

        lineEdit_TSA = new QLineEdit(TP_Nut);
        lineEdit_TSA->setObjectName("lineEdit_TSA");
        lineEdit_TSA->setMaximumSize(QSize(75, 20));
        lineEdit_TSA->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_TSA->addWidget(lineEdit_TSA);

        horizontalSpacer_TSA = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_TSA->addItem(horizontalSpacer_TSA);

        toolButton_Paste = new QToolButton(TP_Nut);
        toolButton_Paste->setObjectName("toolButton_Paste");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/paste.png"), QSize(), QIcon::Normal, QIcon::On);
        toolButton_Paste->setIcon(icon);

        horizontalLayout_TSA->addWidget(toolButton_Paste);


        verticalLayout->addLayout(horizontalLayout_TSA);

        textEdit_Anfahren = new QTextEdit(TP_Nut);
        textEdit_Anfahren->setObjectName("textEdit_Anfahren");
        textEdit_Anfahren->setMinimumSize(QSize(0, 100));
        textEdit_Anfahren->setMaximumSize(QSize(16777215, 100));
        QFont font;
        font.setFamilies({QString::fromUtf8("Lucida Console")});
        textEdit_Anfahren->setFont(font);

        verticalLayout->addWidget(textEdit_Anfahren);


        retranslateUi(TP_Nut);

        QMetaObject::connectSlotsByName(TP_Nut);
    } // setupUi

    void retranslateUi(QWidget *TP_Nut)
    {
        TP_Nut->setWindowTitle(QCoreApplication::translate("TP_Nut", "Form", nullptr));
        comboBox_Frame->setItemText(0, QCoreApplication::translate("TP_Nut", "Oben", nullptr));
        comboBox_Frame->setItemText(1, QCoreApplication::translate("TP_Nut", "Hinten", nullptr));
        comboBox_Frame->setItemText(2, QCoreApplication::translate("TP_Nut", "Links", nullptr));
        comboBox_Frame->setItemText(3, QCoreApplication::translate("TP_Nut", "Vorne", nullptr));
        comboBox_Frame->setItemText(4, QCoreApplication::translate("TP_Nut", "Rechts", nullptr));

        lineEdit_Nullpunkverschiebung_2->setText(QCoreApplication::translate("TP_Nut", "Nullpunktverschiebung", nullptr));
        lineEdit_Aktive_NPV_3->setText(QCoreApplication::translate("TP_Nut", "aktive NPV", nullptr));
        lineEdit_Aktive_NPV_4->setText(QCoreApplication::translate("TP_Nut", "fein", nullptr));
        label_Messrichtung_2->setText(QCoreApplication::translate("TP_Nut", "Messachse", nullptr));
        comboBox_Messachse->setItemText(0, QCoreApplication::translate("TP_Nut", "X", nullptr));
        comboBox_Messachse->setItemText(1, QCoreApplication::translate("TP_Nut", "Y", nullptr));

        label_W->setText(QCoreApplication::translate("TP_Nut", "W", nullptr));
        lineEdit_W->setText(QString());
        label_Alpha_2->setText(QCoreApplication::translate("TP_Nut", "\316\261", nullptr));
        lineEdit_Alpha_2->setText(QCoreApplication::translate("TP_Nut", "0.000", nullptr));
        label_Schutzzone->setText(QCoreApplication::translate("TP_Nut", "Schutzzone", nullptr));
        lineEdit_Schutzzone->setText(QCoreApplication::translate("TP_Nut", "nein", nullptr));
        label_DFA->setText(QCoreApplication::translate("TP_Nut", "DFA", nullptr));
        lineEdit_DFA->setText(QCoreApplication::translate("TP_Nut", "10", nullptr));
        label_TSA->setText(QCoreApplication::translate("TP_Nut", "TSA", nullptr));
        lineEdit_TSA->setText(QCoreApplication::translate("TP_Nut", "0.500", nullptr));
        toolButton_Paste->setText(QCoreApplication::translate("TP_Nut", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TP_Nut: public Ui_TP_Nut {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TP_NUT_H
