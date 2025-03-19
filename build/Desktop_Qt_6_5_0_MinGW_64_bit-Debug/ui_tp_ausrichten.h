/********************************************************************************
** Form generated from reading UI file 'tp_ausrichten.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TP_AUSRICHTEN_H
#define UI_TP_AUSRICHTEN_H

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

class Ui_TP_Ausrichten
{
public:
    QVBoxLayout *verticalLayout;
    MComboBox *comboBox_Frame;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_Nullpunktverschiebung;
    QLineEdit *lineEdit_Nullpunkverschiebung;
    QHBoxLayout *horizontalLayout_Aktive_NPV;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit_Aktive_NPV;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit_Aktive_NPV_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_Winkelkorrektur;
    QLabel *label_Winkelkorrektur;
    QSpacerItem *horizontalSpacer_8;
    QLineEdit *lineEdit_Winkelkorrektur;
    QHBoxLayout *horizontalLayout_Positionieren;
    QLabel *label_Positionieren;
    QSpacerItem *horizontalSpacer_9;
    QLineEdit *lineEdit_Positionieren;
    QHBoxLayout *horizontalLayout_Messrichtung;
    QLabel *label_Messrichtung;
    QSpacerItem *horizontalSpacer_3;
    MComboBox *comboBox_Messrichtung1;
    MComboBox *comboBox_Messrichtung2;
    QHBoxLayout *horizontalLayout_Positionierachse;
    QLabel *label_Positionierachse;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *lineEdit_Positionierachse;
    QHBoxLayout *horizontalLayout_Alpha;
    QLabel *label_Alpha;
    QLineEdit *lineEdit_Alpha;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_CAlgin_L2;
    QLabel *label_L2;
    QLineEdit *lineEdit_L2;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_Schutzzone;
    QLabel *label_Schutzzone;
    QSpacerItem *horizontalSpacer_11;
    QLineEdit *lineEdit_Schutzzone;
    QHBoxLayout *horizontalLayout_DFA;
    QLabel *label_DFA;
    QLineEdit *lineEdit_DFA;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *horizontalLayout_TSA;
    QLabel *label_TSA;
    QLineEdit *lineEdit_TSA;
    QSpacerItem *horizontalSpacer_13;
    QToolButton *toolButton;
    QTextEdit *textEdit_Anfahren;

    void setupUi(QWidget *TP_Ausrichten)
    {
        if (TP_Ausrichten->objectName().isEmpty())
            TP_Ausrichten->setObjectName("TP_Ausrichten");
        TP_Ausrichten->resize(270, 398);
        TP_Ausrichten->setMaximumSize(QSize(270, 16777215));
        verticalLayout = new QVBoxLayout(TP_Ausrichten);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        comboBox_Frame = new MComboBox(TP_Ausrichten);
        comboBox_Frame->addItem(QString());
        comboBox_Frame->addItem(QString());
        comboBox_Frame->addItem(QString());
        comboBox_Frame->addItem(QString());
        comboBox_Frame->addItem(QString());
        comboBox_Frame->setObjectName("comboBox_Frame");

        verticalLayout->addWidget(comboBox_Frame);

        verticalSpacer_2 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_Nullpunktverschiebung = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_Nullpunktverschiebung);

        lineEdit_Nullpunkverschiebung = new QLineEdit(TP_Ausrichten);
        lineEdit_Nullpunkverschiebung->setObjectName("lineEdit_Nullpunkverschiebung");
        lineEdit_Nullpunkverschiebung->setEnabled(false);
        lineEdit_Nullpunkverschiebung->setMinimumSize(QSize(200, 0));
        lineEdit_Nullpunkverschiebung->setMaximumSize(QSize(200, 20));
        lineEdit_Nullpunkverschiebung->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lineEdit_Nullpunkverschiebung);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_Aktive_NPV = new QHBoxLayout();
        horizontalLayout_Aktive_NPV->setSpacing(0);
        horizontalLayout_Aktive_NPV->setObjectName("horizontalLayout_Aktive_NPV");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Aktive_NPV->addItem(horizontalSpacer);

        lineEdit_Aktive_NPV = new QLineEdit(TP_Ausrichten);
        lineEdit_Aktive_NPV->setObjectName("lineEdit_Aktive_NPV");
        lineEdit_Aktive_NPV->setEnabled(false);
        lineEdit_Aktive_NPV->setMinimumSize(QSize(120, 0));
        lineEdit_Aktive_NPV->setMaximumSize(QSize(120, 20));
        lineEdit_Aktive_NPV->setAlignment(Qt::AlignCenter);

        horizontalLayout_Aktive_NPV->addWidget(lineEdit_Aktive_NPV);

        horizontalSpacer_2 = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_Aktive_NPV->addItem(horizontalSpacer_2);

        lineEdit_Aktive_NPV_2 = new QLineEdit(TP_Ausrichten);
        lineEdit_Aktive_NPV_2->setObjectName("lineEdit_Aktive_NPV_2");
        lineEdit_Aktive_NPV_2->setEnabled(false);
        lineEdit_Aktive_NPV_2->setMinimumSize(QSize(55, 0));
        lineEdit_Aktive_NPV_2->setMaximumSize(QSize(55, 20));
        lineEdit_Aktive_NPV_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_Aktive_NPV->addWidget(lineEdit_Aktive_NPV_2);


        verticalLayout->addLayout(horizontalLayout_Aktive_NPV);

        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_Winkelkorrektur = new QHBoxLayout();
        horizontalLayout_Winkelkorrektur->setSpacing(0);
        horizontalLayout_Winkelkorrektur->setObjectName("horizontalLayout_Winkelkorrektur");
        label_Winkelkorrektur = new QLabel(TP_Ausrichten);
        label_Winkelkorrektur->setObjectName("label_Winkelkorrektur");
        label_Winkelkorrektur->setEnabled(false);
        label_Winkelkorrektur->setMinimumSize(QSize(0, 20));
        label_Winkelkorrektur->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_Winkelkorrektur->addWidget(label_Winkelkorrektur);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Winkelkorrektur->addItem(horizontalSpacer_8);

        lineEdit_Winkelkorrektur = new QLineEdit(TP_Ausrichten);
        lineEdit_Winkelkorrektur->setObjectName("lineEdit_Winkelkorrektur");
        lineEdit_Winkelkorrektur->setEnabled(false);
        lineEdit_Winkelkorrektur->setMinimumSize(QSize(109, 20));
        lineEdit_Winkelkorrektur->setMaximumSize(QSize(109, 20));
        lineEdit_Winkelkorrektur->setAlignment(Qt::AlignCenter);

        horizontalLayout_Winkelkorrektur->addWidget(lineEdit_Winkelkorrektur);


        verticalLayout->addLayout(horizontalLayout_Winkelkorrektur);

        horizontalLayout_Positionieren = new QHBoxLayout();
        horizontalLayout_Positionieren->setObjectName("horizontalLayout_Positionieren");
        label_Positionieren = new QLabel(TP_Ausrichten);
        label_Positionieren->setObjectName("label_Positionieren");
        label_Positionieren->setEnabled(false);
        label_Positionieren->setMinimumSize(QSize(0, 20));
        label_Positionieren->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_Positionieren->addWidget(label_Positionieren);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Positionieren->addItem(horizontalSpacer_9);

        lineEdit_Positionieren = new QLineEdit(TP_Ausrichten);
        lineEdit_Positionieren->setObjectName("lineEdit_Positionieren");
        lineEdit_Positionieren->setEnabled(false);
        lineEdit_Positionieren->setMinimumSize(QSize(109, 20));
        lineEdit_Positionieren->setMaximumSize(QSize(109, 20));
        lineEdit_Positionieren->setAlignment(Qt::AlignCenter);

        horizontalLayout_Positionieren->addWidget(lineEdit_Positionieren);


        verticalLayout->addLayout(horizontalLayout_Positionieren);

        horizontalLayout_Messrichtung = new QHBoxLayout();
        horizontalLayout_Messrichtung->setSpacing(2);
        horizontalLayout_Messrichtung->setObjectName("horizontalLayout_Messrichtung");
        label_Messrichtung = new QLabel(TP_Ausrichten);
        label_Messrichtung->setObjectName("label_Messrichtung");
        label_Messrichtung->setEnabled(false);
        label_Messrichtung->setMinimumSize(QSize(0, 20));
        label_Messrichtung->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_Messrichtung->addWidget(label_Messrichtung);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Messrichtung->addItem(horizontalSpacer_3);

        comboBox_Messrichtung1 = new MComboBox(TP_Ausrichten);
        comboBox_Messrichtung1->addItem(QString());
        comboBox_Messrichtung1->addItem(QString());
        comboBox_Messrichtung1->setObjectName("comboBox_Messrichtung1");
        comboBox_Messrichtung1->setMinimumSize(QSize(0, 20));
        comboBox_Messrichtung1->setMaximumSize(QSize(40, 20));
        comboBox_Messrichtung1->setCursor(QCursor(Qt::ArrowCursor));
        comboBox_Messrichtung1->setIconSize(QSize(16, 16));

        horizontalLayout_Messrichtung->addWidget(comboBox_Messrichtung1);

        comboBox_Messrichtung2 = new MComboBox(TP_Ausrichten);
        comboBox_Messrichtung2->addItem(QString());
        comboBox_Messrichtung2->addItem(QString());
        comboBox_Messrichtung2->addItem(QString());
        comboBox_Messrichtung2->setObjectName("comboBox_Messrichtung2");
        comboBox_Messrichtung2->setMinimumSize(QSize(70, 20));
        comboBox_Messrichtung2->setMaximumSize(QSize(70, 20));

        horizontalLayout_Messrichtung->addWidget(comboBox_Messrichtung2);


        verticalLayout->addLayout(horizontalLayout_Messrichtung);

        horizontalLayout_Positionierachse = new QHBoxLayout();
        horizontalLayout_Positionierachse->setSpacing(2);
        horizontalLayout_Positionierachse->setObjectName("horizontalLayout_Positionierachse");
        label_Positionierachse = new QLabel(TP_Ausrichten);
        label_Positionierachse->setObjectName("label_Positionierachse");
        label_Positionierachse->setEnabled(false);
        label_Positionierachse->setMinimumSize(QSize(0, 20));
        label_Positionierachse->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_Positionierachse->addWidget(label_Positionierachse);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Positionierachse->addItem(horizontalSpacer_4);

        lineEdit_Positionierachse = new QLineEdit(TP_Ausrichten);
        lineEdit_Positionierachse->setObjectName("lineEdit_Positionierachse");
        lineEdit_Positionierachse->setEnabled(false);
        lineEdit_Positionierachse->setMinimumSize(QSize(70, 20));
        lineEdit_Positionierachse->setMaximumSize(QSize(70, 20));

        horizontalLayout_Positionierachse->addWidget(lineEdit_Positionierachse);


        verticalLayout->addLayout(horizontalLayout_Positionierachse);

        horizontalLayout_Alpha = new QHBoxLayout();
        horizontalLayout_Alpha->setSpacing(0);
        horizontalLayout_Alpha->setObjectName("horizontalLayout_Alpha");
        label_Alpha = new QLabel(TP_Ausrichten);
        label_Alpha->setObjectName("label_Alpha");
        label_Alpha->setEnabled(false);
        label_Alpha->setMinimumSize(QSize(40, 20));
        label_Alpha->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_Alpha->addWidget(label_Alpha);

        lineEdit_Alpha = new QLineEdit(TP_Ausrichten);
        lineEdit_Alpha->setObjectName("lineEdit_Alpha");
        lineEdit_Alpha->setEnabled(false);
        lineEdit_Alpha->setMinimumSize(QSize(75, 20));
        lineEdit_Alpha->setMaximumSize(QSize(95, 16777215));
        lineEdit_Alpha->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_Alpha->addWidget(lineEdit_Alpha);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Alpha->addItem(horizontalSpacer_10);


        verticalLayout->addLayout(horizontalLayout_Alpha);

        horizontalLayout_CAlgin_L2 = new QHBoxLayout();
        horizontalLayout_CAlgin_L2->setSpacing(0);
        horizontalLayout_CAlgin_L2->setObjectName("horizontalLayout_CAlgin_L2");
        label_L2 = new QLabel(TP_Ausrichten);
        label_L2->setObjectName("label_L2");
        label_L2->setMinimumSize(QSize(40, 20));
        label_L2->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_CAlgin_L2->addWidget(label_L2);

        lineEdit_L2 = new QLineEdit(TP_Ausrichten);
        lineEdit_L2->setObjectName("lineEdit_L2");
        lineEdit_L2->setMinimumSize(QSize(95, 20));
        lineEdit_L2->setMaximumSize(QSize(95, 16777215));
        lineEdit_L2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_CAlgin_L2->addWidget(lineEdit_L2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_CAlgin_L2->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_CAlgin_L2);

        horizontalLayout_Schutzzone = new QHBoxLayout();
        horizontalLayout_Schutzzone->setSpacing(2);
        horizontalLayout_Schutzzone->setObjectName("horizontalLayout_Schutzzone");
        label_Schutzzone = new QLabel(TP_Ausrichten);
        label_Schutzzone->setObjectName("label_Schutzzone");
        label_Schutzzone->setEnabled(false);
        label_Schutzzone->setMinimumSize(QSize(0, 20));
        label_Schutzzone->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_Schutzzone->addWidget(label_Schutzzone);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Schutzzone->addItem(horizontalSpacer_11);

        lineEdit_Schutzzone = new QLineEdit(TP_Ausrichten);
        lineEdit_Schutzzone->setObjectName("lineEdit_Schutzzone");
        lineEdit_Schutzzone->setEnabled(false);
        lineEdit_Schutzzone->setMinimumSize(QSize(70, 20));
        lineEdit_Schutzzone->setMaximumSize(QSize(70, 20));
        lineEdit_Schutzzone->setAlignment(Qt::AlignCenter);

        horizontalLayout_Schutzzone->addWidget(lineEdit_Schutzzone);


        verticalLayout->addLayout(horizontalLayout_Schutzzone);

        horizontalLayout_DFA = new QHBoxLayout();
        horizontalLayout_DFA->setSpacing(0);
        horizontalLayout_DFA->setObjectName("horizontalLayout_DFA");
        label_DFA = new QLabel(TP_Ausrichten);
        label_DFA->setObjectName("label_DFA");
        label_DFA->setEnabled(false);
        label_DFA->setMinimumSize(QSize(40, 20));
        label_DFA->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_DFA->addWidget(label_DFA);

        lineEdit_DFA = new QLineEdit(TP_Ausrichten);
        lineEdit_DFA->setObjectName("lineEdit_DFA");
        lineEdit_DFA->setEnabled(false);
        lineEdit_DFA->setMinimumSize(QSize(75, 20));
        lineEdit_DFA->setMaximumSize(QSize(95, 16777215));
        lineEdit_DFA->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_DFA->addWidget(lineEdit_DFA);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_DFA->addItem(horizontalSpacer_12);


        verticalLayout->addLayout(horizontalLayout_DFA);

        horizontalLayout_TSA = new QHBoxLayout();
        horizontalLayout_TSA->setSpacing(0);
        horizontalLayout_TSA->setObjectName("horizontalLayout_TSA");
        label_TSA = new QLabel(TP_Ausrichten);
        label_TSA->setObjectName("label_TSA");
        label_TSA->setEnabled(false);
        label_TSA->setMinimumSize(QSize(40, 20));
        label_TSA->setMaximumSize(QSize(16777215, 20));
        label_TSA->setAcceptDrops(true);

        horizontalLayout_TSA->addWidget(label_TSA);

        lineEdit_TSA = new QLineEdit(TP_Ausrichten);
        lineEdit_TSA->setObjectName("lineEdit_TSA");
        lineEdit_TSA->setEnabled(true);
        lineEdit_TSA->setMinimumSize(QSize(75, 20));
        lineEdit_TSA->setMaximumSize(QSize(95, 16777215));
        lineEdit_TSA->setAcceptDrops(true);
        lineEdit_TSA->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_TSA->addWidget(lineEdit_TSA);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_TSA->addItem(horizontalSpacer_13);

        toolButton = new QToolButton(TP_Ausrichten);
        toolButton->setObjectName("toolButton");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/paste.png"), QSize(), QIcon::Normal, QIcon::On);
        toolButton->setIcon(icon);

        horizontalLayout_TSA->addWidget(toolButton);


        verticalLayout->addLayout(horizontalLayout_TSA);

        textEdit_Anfahren = new QTextEdit(TP_Ausrichten);
        textEdit_Anfahren->setObjectName("textEdit_Anfahren");
        textEdit_Anfahren->setMinimumSize(QSize(0, 100));
        textEdit_Anfahren->setMaximumSize(QSize(16777215, 100));
        QFont font;
        font.setFamilies({QString::fromUtf8("Lucida Console")});
        textEdit_Anfahren->setFont(font);

        verticalLayout->addWidget(textEdit_Anfahren);


        retranslateUi(TP_Ausrichten);

        QMetaObject::connectSlotsByName(TP_Ausrichten);
    } // setupUi

    void retranslateUi(QWidget *TP_Ausrichten)
    {
        TP_Ausrichten->setWindowTitle(QCoreApplication::translate("TP_Ausrichten", "Form", nullptr));
        comboBox_Frame->setItemText(0, QCoreApplication::translate("TP_Ausrichten", "Oben", nullptr));
        comboBox_Frame->setItemText(1, QCoreApplication::translate("TP_Ausrichten", "Hinten", nullptr));
        comboBox_Frame->setItemText(2, QCoreApplication::translate("TP_Ausrichten", "Links", nullptr));
        comboBox_Frame->setItemText(3, QCoreApplication::translate("TP_Ausrichten", "Vorne", nullptr));
        comboBox_Frame->setItemText(4, QCoreApplication::translate("TP_Ausrichten", "Rechts", nullptr));

        lineEdit_Nullpunkverschiebung->setText(QCoreApplication::translate("TP_Ausrichten", "Nullpunktverschiebung", nullptr));
        lineEdit_Aktive_NPV->setText(QCoreApplication::translate("TP_Ausrichten", "aktive NPV", nullptr));
        lineEdit_Aktive_NPV_2->setText(QCoreApplication::translate("TP_Ausrichten", "fein", nullptr));
        label_Winkelkorrektur->setText(QCoreApplication::translate("TP_Ausrichten", "Winkelkorrektur", nullptr));
        lineEdit_Winkelkorrektur->setText(QCoreApplication::translate("TP_Ausrichten", "Rundachse C", nullptr));
        label_Positionieren->setText(QCoreApplication::translate("TP_Ausrichten", "Positionieren", nullptr));
        lineEdit_Positionieren->setText(QCoreApplication::translate("TP_Ausrichten", "achsparallel", nullptr));
        label_Messrichtung->setText(QCoreApplication::translate("TP_Ausrichten", "Messrichtung", nullptr));
        comboBox_Messrichtung1->setItemText(0, QCoreApplication::translate("TP_Ausrichten", "+", nullptr));
        comboBox_Messrichtung1->setItemText(1, QCoreApplication::translate("TP_Ausrichten", "-", nullptr));

        comboBox_Messrichtung2->setItemText(0, QCoreApplication::translate("TP_Ausrichten", "X", nullptr));
        comboBox_Messrichtung2->setItemText(1, QCoreApplication::translate("TP_Ausrichten", "Y", nullptr));
        comboBox_Messrichtung2->setItemText(2, QCoreApplication::translate("TP_Ausrichten", "Z", nullptr));

        label_Positionierachse->setText(QCoreApplication::translate("TP_Ausrichten", "Positionierachse", nullptr));
        label_Alpha->setText(QCoreApplication::translate("TP_Ausrichten", "\316\261", nullptr));
        lineEdit_Alpha->setText(QCoreApplication::translate("TP_Ausrichten", "0.000", nullptr));
        label_L2->setText(QCoreApplication::translate("TP_Ausrichten", "L2", nullptr));
        lineEdit_L2->setText(QString());
        label_Schutzzone->setText(QCoreApplication::translate("TP_Ausrichten", "Schutzzone", nullptr));
        lineEdit_Schutzzone->setText(QCoreApplication::translate("TP_Ausrichten", "nein", nullptr));
        label_DFA->setText(QCoreApplication::translate("TP_Ausrichten", "DFA", nullptr));
        lineEdit_DFA->setText(QCoreApplication::translate("TP_Ausrichten", "10.000", nullptr));
        label_TSA->setText(QCoreApplication::translate("TP_Ausrichten", "TSA", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_TSA->setToolTip(QCoreApplication::translate("TP_Ausrichten", "Vertrauensbereich", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEdit_TSA->setText(QCoreApplication::translate("TP_Ausrichten", "0.200", nullptr));
        toolButton->setText(QCoreApplication::translate("TP_Ausrichten", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TP_Ausrichten: public Ui_TP_Ausrichten {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TP_AUSRICHTEN_H
