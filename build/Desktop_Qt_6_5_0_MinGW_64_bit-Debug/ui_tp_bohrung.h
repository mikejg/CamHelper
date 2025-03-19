/********************************************************************************
** Form generated from reading UI file 'tp_bohrung.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TP_BOHRUNG_H
#define UI_TP_BOHRUNG_H

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

class Ui_TP_Bohrung
{
public:
    QVBoxLayout *verticalLayout;
    MComboBox *comboBox_Frame;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_Korrekturziel;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_Nullpunktverschiebung;
    QLineEdit *lineEdit_Nullpunkverschiebung;
    QHBoxLayout *horizontalLayout_Aktive_NPV;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit_Aktive_NPV;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit_Aktive_NPV_2;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_Durchmesser;
    QLabel *label_Durchmesser;
    QLineEdit *lineEdit_Durchmesser;
    QSpacerItem *horizontalSpacer_11;
    QHBoxLayout *horizontalLayout_Alpha;
    QLabel *label_Alpha;
    QLineEdit *lineEdit_Alpha;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_Schutzzone;
    QLabel *label_Schutzzone;
    QSpacerItem *horizontalSpacer_12;
    QLineEdit *lineEdit_Schutzzone;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_DFA;
    QLabel *label_DFA;
    QLineEdit *lineEdit_DFA;
    QSpacerItem *horizontalSpacer_13;
    QHBoxLayout *horizontalLayout_TSA;
    QLabel *label_TSA;
    QLineEdit *lineEdit_TSA;
    QSpacerItem *horizontalSpacer_14;
    QToolButton *toolButton_Paste;
    QTextEdit *textEdit_Anfahren;

    void setupUi(QWidget *TP_Bohrung)
    {
        if (TP_Bohrung->objectName().isEmpty())
            TP_Bohrung->setObjectName("TP_Bohrung");
        TP_Bohrung->resize(270, 333);
        TP_Bohrung->setMinimumSize(QSize(0, 0));
        TP_Bohrung->setMaximumSize(QSize(270, 16777215));
        verticalLayout = new QVBoxLayout(TP_Bohrung);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        comboBox_Frame = new MComboBox(TP_Bohrung);
        comboBox_Frame->addItem(QString());
        comboBox_Frame->addItem(QString());
        comboBox_Frame->addItem(QString());
        comboBox_Frame->addItem(QString());
        comboBox_Frame->addItem(QString());
        comboBox_Frame->setObjectName("comboBox_Frame");

        verticalLayout->addWidget(comboBox_Frame);

        verticalSpacer_2 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        label_Korrekturziel = new QLabel(TP_Bohrung);
        label_Korrekturziel->setObjectName("label_Korrekturziel");
        label_Korrekturziel->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(label_Korrekturziel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_Nullpunktverschiebung = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_Nullpunktverschiebung);

        lineEdit_Nullpunkverschiebung = new QLineEdit(TP_Bohrung);
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

        lineEdit_Aktive_NPV = new QLineEdit(TP_Bohrung);
        lineEdit_Aktive_NPV->setObjectName("lineEdit_Aktive_NPV");
        lineEdit_Aktive_NPV->setEnabled(false);
        lineEdit_Aktive_NPV->setMinimumSize(QSize(120, 0));
        lineEdit_Aktive_NPV->setMaximumSize(QSize(120, 20));
        lineEdit_Aktive_NPV->setAlignment(Qt::AlignCenter);

        horizontalLayout_Aktive_NPV->addWidget(lineEdit_Aktive_NPV);

        horizontalSpacer_2 = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_Aktive_NPV->addItem(horizontalSpacer_2);

        lineEdit_Aktive_NPV_2 = new QLineEdit(TP_Bohrung);
        lineEdit_Aktive_NPV_2->setObjectName("lineEdit_Aktive_NPV_2");
        lineEdit_Aktive_NPV_2->setEnabled(false);
        lineEdit_Aktive_NPV_2->setMinimumSize(QSize(55, 0));
        lineEdit_Aktive_NPV_2->setMaximumSize(QSize(55, 20));
        lineEdit_Aktive_NPV_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_Aktive_NPV->addWidget(lineEdit_Aktive_NPV_2);


        verticalLayout->addLayout(horizontalLayout_Aktive_NPV);

        verticalSpacer_3 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_Durchmesser = new QHBoxLayout();
        horizontalLayout_Durchmesser->setSpacing(0);
        horizontalLayout_Durchmesser->setObjectName("horizontalLayout_Durchmesser");
        label_Durchmesser = new QLabel(TP_Bohrung);
        label_Durchmesser->setObjectName("label_Durchmesser");
        label_Durchmesser->setEnabled(true);
        label_Durchmesser->setMinimumSize(QSize(40, 20));
        label_Durchmesser->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_Durchmesser->addWidget(label_Durchmesser);

        lineEdit_Durchmesser = new QLineEdit(TP_Bohrung);
        lineEdit_Durchmesser->setObjectName("lineEdit_Durchmesser");
        lineEdit_Durchmesser->setEnabled(true);
        lineEdit_Durchmesser->setMinimumSize(QSize(75, 20));
        lineEdit_Durchmesser->setMaximumSize(QSize(95, 16777215));
        lineEdit_Durchmesser->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_Durchmesser->addWidget(lineEdit_Durchmesser);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Durchmesser->addItem(horizontalSpacer_11);


        verticalLayout->addLayout(horizontalLayout_Durchmesser);

        horizontalLayout_Alpha = new QHBoxLayout();
        horizontalLayout_Alpha->setSpacing(0);
        horizontalLayout_Alpha->setObjectName("horizontalLayout_Alpha");
        label_Alpha = new QLabel(TP_Bohrung);
        label_Alpha->setObjectName("label_Alpha");
        label_Alpha->setEnabled(false);
        label_Alpha->setMinimumSize(QSize(40, 20));
        label_Alpha->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_Alpha->addWidget(label_Alpha);

        lineEdit_Alpha = new QLineEdit(TP_Bohrung);
        lineEdit_Alpha->setObjectName("lineEdit_Alpha");
        lineEdit_Alpha->setEnabled(false);
        lineEdit_Alpha->setMinimumSize(QSize(75, 20));
        lineEdit_Alpha->setMaximumSize(QSize(95, 16777215));
        lineEdit_Alpha->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_Alpha->addWidget(lineEdit_Alpha);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Alpha->addItem(horizontalSpacer_10);


        verticalLayout->addLayout(horizontalLayout_Alpha);

        horizontalLayout_Schutzzone = new QHBoxLayout();
        horizontalLayout_Schutzzone->setSpacing(2);
        horizontalLayout_Schutzzone->setObjectName("horizontalLayout_Schutzzone");
        label_Schutzzone = new QLabel(TP_Bohrung);
        label_Schutzzone->setObjectName("label_Schutzzone");
        label_Schutzzone->setEnabled(false);
        label_Schutzzone->setMinimumSize(QSize(0, 20));
        label_Schutzzone->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_Schutzzone->addWidget(label_Schutzzone);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Schutzzone->addItem(horizontalSpacer_12);

        lineEdit_Schutzzone = new QLineEdit(TP_Bohrung);
        lineEdit_Schutzzone->setObjectName("lineEdit_Schutzzone");
        lineEdit_Schutzzone->setEnabled(false);
        lineEdit_Schutzzone->setMinimumSize(QSize(70, 20));
        lineEdit_Schutzzone->setMaximumSize(QSize(70, 20));
        lineEdit_Schutzzone->setAlignment(Qt::AlignCenter);

        horizontalLayout_Schutzzone->addWidget(lineEdit_Schutzzone);


        verticalLayout->addLayout(horizontalLayout_Schutzzone);

        verticalSpacer_4 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout_DFA = new QHBoxLayout();
        horizontalLayout_DFA->setSpacing(0);
        horizontalLayout_DFA->setObjectName("horizontalLayout_DFA");
        label_DFA = new QLabel(TP_Bohrung);
        label_DFA->setObjectName("label_DFA");
        label_DFA->setEnabled(false);
        label_DFA->setMinimumSize(QSize(40, 20));
        label_DFA->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_DFA->addWidget(label_DFA);

        lineEdit_DFA = new QLineEdit(TP_Bohrung);
        lineEdit_DFA->setObjectName("lineEdit_DFA");
        lineEdit_DFA->setEnabled(false);
        lineEdit_DFA->setMinimumSize(QSize(75, 20));
        lineEdit_DFA->setMaximumSize(QSize(95, 16777215));
        lineEdit_DFA->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_DFA->addWidget(lineEdit_DFA);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_DFA->addItem(horizontalSpacer_13);


        verticalLayout->addLayout(horizontalLayout_DFA);

        horizontalLayout_TSA = new QHBoxLayout();
        horizontalLayout_TSA->setSpacing(0);
        horizontalLayout_TSA->setObjectName("horizontalLayout_TSA");
        label_TSA = new QLabel(TP_Bohrung);
        label_TSA->setObjectName("label_TSA");
        label_TSA->setEnabled(false);
        label_TSA->setMinimumSize(QSize(40, 20));
        label_TSA->setMaximumSize(QSize(16777215, 20));
        label_TSA->setAcceptDrops(true);

        horizontalLayout_TSA->addWidget(label_TSA);

        lineEdit_TSA = new QLineEdit(TP_Bohrung);
        lineEdit_TSA->setObjectName("lineEdit_TSA");
        lineEdit_TSA->setEnabled(true);
        lineEdit_TSA->setMinimumSize(QSize(75, 20));
        lineEdit_TSA->setMaximumSize(QSize(95, 16777215));
        lineEdit_TSA->setAcceptDrops(true);
        lineEdit_TSA->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_TSA->addWidget(lineEdit_TSA);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_TSA->addItem(horizontalSpacer_14);

        toolButton_Paste = new QToolButton(TP_Bohrung);
        toolButton_Paste->setObjectName("toolButton_Paste");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/paste.png"), QSize(), QIcon::Normal, QIcon::On);
        toolButton_Paste->setIcon(icon);

        horizontalLayout_TSA->addWidget(toolButton_Paste);


        verticalLayout->addLayout(horizontalLayout_TSA);

        textEdit_Anfahren = new QTextEdit(TP_Bohrung);
        textEdit_Anfahren->setObjectName("textEdit_Anfahren");
        textEdit_Anfahren->setMinimumSize(QSize(0, 100));
        textEdit_Anfahren->setMaximumSize(QSize(16777215, 100));
        QFont font;
        font.setFamilies({QString::fromUtf8("Lucida Console")});
        textEdit_Anfahren->setFont(font);

        verticalLayout->addWidget(textEdit_Anfahren);


        retranslateUi(TP_Bohrung);

        QMetaObject::connectSlotsByName(TP_Bohrung);
    } // setupUi

    void retranslateUi(QWidget *TP_Bohrung)
    {
        TP_Bohrung->setWindowTitle(QCoreApplication::translate("TP_Bohrung", "Form", nullptr));
        comboBox_Frame->setItemText(0, QCoreApplication::translate("TP_Bohrung", "Oben", nullptr));
        comboBox_Frame->setItemText(1, QCoreApplication::translate("TP_Bohrung", "Hinten", nullptr));
        comboBox_Frame->setItemText(2, QCoreApplication::translate("TP_Bohrung", "Links", nullptr));
        comboBox_Frame->setItemText(3, QCoreApplication::translate("TP_Bohrung", "Vorne", nullptr));
        comboBox_Frame->setItemText(4, QCoreApplication::translate("TP_Bohrung", "Rechts", nullptr));

        label_Korrekturziel->setText(QCoreApplication::translate("TP_Bohrung", "Korrekturziel", nullptr));
        lineEdit_Nullpunkverschiebung->setText(QCoreApplication::translate("TP_Bohrung", "Nullpunktverschiebung", nullptr));
        lineEdit_Aktive_NPV->setText(QCoreApplication::translate("TP_Bohrung", "aktive NPV", nullptr));
        lineEdit_Aktive_NPV_2->setText(QCoreApplication::translate("TP_Bohrung", "fein", nullptr));
        label_Durchmesser->setText(QCoreApplication::translate("TP_Bohrung", " \303\230", nullptr));
        lineEdit_Durchmesser->setText(QString());
        label_Alpha->setText(QCoreApplication::translate("TP_Bohrung", "\316\261 0", nullptr));
        lineEdit_Alpha->setText(QCoreApplication::translate("TP_Bohrung", "0.000", nullptr));
        label_Schutzzone->setText(QCoreApplication::translate("TP_Bohrung", "Schutzzone", nullptr));
        lineEdit_Schutzzone->setText(QCoreApplication::translate("TP_Bohrung", "nein", nullptr));
        label_DFA->setText(QCoreApplication::translate("TP_Bohrung", "DFA", nullptr));
        lineEdit_DFA->setText(QCoreApplication::translate("TP_Bohrung", "10.000", nullptr));
        label_TSA->setText(QCoreApplication::translate("TP_Bohrung", "TSA", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_TSA->setToolTip(QCoreApplication::translate("TP_Bohrung", "Vertrauensbereich", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEdit_TSA->setText(QCoreApplication::translate("TP_Bohrung", "0.200", nullptr));
        toolButton_Paste->setText(QCoreApplication::translate("TP_Bohrung", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TP_Bohrung: public Ui_TP_Bohrung {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TP_BOHRUNG_H
