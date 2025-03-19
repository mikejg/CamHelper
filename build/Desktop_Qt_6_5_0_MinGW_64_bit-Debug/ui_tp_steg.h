/********************************************************************************
** Form generated from reading UI file 'tp_steg.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TP_STEG_H
#define UI_TP_STEG_H

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

class Ui_TP_Steg
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
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_Messachse;
    QLabel *label_Messrichtung;
    QSpacerItem *horizontalSpacer_3;
    MComboBox *comboBox_Messachse;
    QHBoxLayout *horizontalLayout_W;
    QLabel *label_W;
    QLineEdit *lineEdit_W;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_Alpha;
    QLabel *label_Alpha;
    QLineEdit *lineEdit_Alpha;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_DZ;
    QLabel *label_DZ;
    QLineEdit *lineEdit_DZ;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_Schutzzone;
    QLabel *label_Schutzzone;
    QSpacerItem *horizontalSpacer_7;
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

    void setupUi(QWidget *TP_Steg)
    {
        if (TP_Steg->objectName().isEmpty())
            TP_Steg->setObjectName("TP_Steg");
        TP_Steg->resize(202, 380);
        TP_Steg->setMinimumSize(QSize(0, 0));
        TP_Steg->setMaximumSize(QSize(270, 16777215));
        verticalLayout = new QVBoxLayout(TP_Steg);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        comboBox_Frame = new MComboBox(TP_Steg);
        comboBox_Frame->addItem(QString());
        comboBox_Frame->addItem(QString());
        comboBox_Frame->addItem(QString());
        comboBox_Frame->addItem(QString());
        comboBox_Frame->addItem(QString());
        comboBox_Frame->setObjectName("comboBox_Frame");

        verticalLayout->addWidget(comboBox_Frame);

        verticalSpacer_2 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        label_Korrekturziel = new QLabel(TP_Steg);
        label_Korrekturziel->setObjectName("label_Korrekturziel");
        label_Korrekturziel->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(label_Korrekturziel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_Nullpunktverschiebung = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_Nullpunktverschiebung);

        lineEdit_Nullpunkverschiebung = new QLineEdit(TP_Steg);
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

        lineEdit_Aktive_NPV = new QLineEdit(TP_Steg);
        lineEdit_Aktive_NPV->setObjectName("lineEdit_Aktive_NPV");
        lineEdit_Aktive_NPV->setEnabled(false);
        lineEdit_Aktive_NPV->setMinimumSize(QSize(120, 0));
        lineEdit_Aktive_NPV->setMaximumSize(QSize(120, 20));
        lineEdit_Aktive_NPV->setAlignment(Qt::AlignCenter);

        horizontalLayout_Aktive_NPV->addWidget(lineEdit_Aktive_NPV);

        horizontalSpacer_2 = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_Aktive_NPV->addItem(horizontalSpacer_2);

        lineEdit_Aktive_NPV_2 = new QLineEdit(TP_Steg);
        lineEdit_Aktive_NPV_2->setObjectName("lineEdit_Aktive_NPV_2");
        lineEdit_Aktive_NPV_2->setEnabled(false);
        lineEdit_Aktive_NPV_2->setMinimumSize(QSize(55, 0));
        lineEdit_Aktive_NPV_2->setMaximumSize(QSize(55, 20));
        lineEdit_Aktive_NPV_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_Aktive_NPV->addWidget(lineEdit_Aktive_NPV_2);


        verticalLayout->addLayout(horizontalLayout_Aktive_NPV);

        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_Messachse = new QHBoxLayout();
        horizontalLayout_Messachse->setSpacing(2);
        horizontalLayout_Messachse->setObjectName("horizontalLayout_Messachse");
        label_Messrichtung = new QLabel(TP_Steg);
        label_Messrichtung->setObjectName("label_Messrichtung");
        label_Messrichtung->setEnabled(true);
        label_Messrichtung->setMinimumSize(QSize(0, 20));
        label_Messrichtung->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_Messachse->addWidget(label_Messrichtung);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Messachse->addItem(horizontalSpacer_3);

        comboBox_Messachse = new MComboBox(TP_Steg);
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
        label_W = new QLabel(TP_Steg);
        label_W->setObjectName("label_W");
        label_W->setMinimumSize(QSize(40, 20));
        label_W->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_W->addWidget(label_W);

        lineEdit_W = new QLineEdit(TP_Steg);
        lineEdit_W->setObjectName("lineEdit_W");
        lineEdit_W->setMinimumSize(QSize(95, 20));
        lineEdit_W->setMaximumSize(QSize(95, 16777215));
        lineEdit_W->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_W->addWidget(lineEdit_W);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_W->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_W);

        horizontalLayout_Alpha = new QHBoxLayout();
        horizontalLayout_Alpha->setSpacing(0);
        horizontalLayout_Alpha->setObjectName("horizontalLayout_Alpha");
        label_Alpha = new QLabel(TP_Steg);
        label_Alpha->setObjectName("label_Alpha");
        label_Alpha->setEnabled(false);
        label_Alpha->setMinimumSize(QSize(40, 20));
        label_Alpha->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_Alpha->addWidget(label_Alpha);

        lineEdit_Alpha = new QLineEdit(TP_Steg);
        lineEdit_Alpha->setObjectName("lineEdit_Alpha");
        lineEdit_Alpha->setEnabled(false);
        lineEdit_Alpha->setMinimumSize(QSize(75, 20));
        lineEdit_Alpha->setMaximumSize(QSize(95, 16777215));
        lineEdit_Alpha->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_Alpha->addWidget(lineEdit_Alpha);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Alpha->addItem(horizontalSpacer_10);


        verticalLayout->addLayout(horizontalLayout_Alpha);

        horizontalLayout_DZ = new QHBoxLayout();
        horizontalLayout_DZ->setSpacing(0);
        horizontalLayout_DZ->setObjectName("horizontalLayout_DZ");
        label_DZ = new QLabel(TP_Steg);
        label_DZ->setObjectName("label_DZ");
        label_DZ->setMinimumSize(QSize(40, 20));
        label_DZ->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_DZ->addWidget(label_DZ);

        lineEdit_DZ = new QLineEdit(TP_Steg);
        lineEdit_DZ->setObjectName("lineEdit_DZ");
        lineEdit_DZ->setMinimumSize(QSize(95, 20));
        lineEdit_DZ->setMaximumSize(QSize(95, 16777215));
        lineEdit_DZ->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_DZ->addWidget(lineEdit_DZ);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_DZ->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_DZ);

        horizontalLayout_Schutzzone = new QHBoxLayout();
        horizontalLayout_Schutzzone->setSpacing(0);
        horizontalLayout_Schutzzone->setObjectName("horizontalLayout_Schutzzone");
        label_Schutzzone = new QLabel(TP_Steg);
        label_Schutzzone->setObjectName("label_Schutzzone");
        label_Schutzzone->setEnabled(true);
        label_Schutzzone->setMinimumSize(QSize(0, 20));
        label_Schutzzone->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_Schutzzone->addWidget(label_Schutzzone);

        horizontalSpacer_7 = new QSpacerItem(25, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Schutzzone->addItem(horizontalSpacer_7);

        lineEdit_Schutzzone = new QLineEdit(TP_Steg);
        lineEdit_Schutzzone->setObjectName("lineEdit_Schutzzone");
        lineEdit_Schutzzone->setEnabled(false);
        lineEdit_Schutzzone->setMinimumSize(QSize(70, 0));
        lineEdit_Schutzzone->setMaximumSize(QSize(70, 20));
        lineEdit_Schutzzone->setAlignment(Qt::AlignCenter);

        horizontalLayout_Schutzzone->addWidget(lineEdit_Schutzzone);


        verticalLayout->addLayout(horizontalLayout_Schutzzone);

        verticalSpacer_3 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_DFA = new QHBoxLayout();
        horizontalLayout_DFA->setObjectName("horizontalLayout_DFA");
        label_DFA = new QLabel(TP_Steg);
        label_DFA->setObjectName("label_DFA");
        label_DFA->setMinimumSize(QSize(45, 0));
        label_DFA->setMaximumSize(QSize(45, 20));

        horizontalLayout_DFA->addWidget(label_DFA);

        lineEdit_DFA = new QLineEdit(TP_Steg);
        lineEdit_DFA->setObjectName("lineEdit_DFA");
        lineEdit_DFA->setMaximumSize(QSize(75, 20));
        lineEdit_DFA->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_DFA->addWidget(lineEdit_DFA);

        horizontalSpacer_DFA = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_DFA->addItem(horizontalSpacer_DFA);


        verticalLayout->addLayout(horizontalLayout_DFA);

        horizontalLayout_TSA = new QHBoxLayout();
        horizontalLayout_TSA->setObjectName("horizontalLayout_TSA");
        label_TSA = new QLabel(TP_Steg);
        label_TSA->setObjectName("label_TSA");
        label_TSA->setMinimumSize(QSize(45, 0));
        label_TSA->setMaximumSize(QSize(45, 20));

        horizontalLayout_TSA->addWidget(label_TSA);

        lineEdit_TSA = new QLineEdit(TP_Steg);
        lineEdit_TSA->setObjectName("lineEdit_TSA");
        lineEdit_TSA->setMaximumSize(QSize(75, 20));
        lineEdit_TSA->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_TSA->addWidget(lineEdit_TSA);

        horizontalSpacer_TSA = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_TSA->addItem(horizontalSpacer_TSA);

        toolButton_Paste = new QToolButton(TP_Steg);
        toolButton_Paste->setObjectName("toolButton_Paste");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/paste.png"), QSize(), QIcon::Normal, QIcon::On);
        toolButton_Paste->setIcon(icon);

        horizontalLayout_TSA->addWidget(toolButton_Paste);


        verticalLayout->addLayout(horizontalLayout_TSA);

        textEdit_Anfahren = new QTextEdit(TP_Steg);
        textEdit_Anfahren->setObjectName("textEdit_Anfahren");
        textEdit_Anfahren->setMinimumSize(QSize(0, 100));
        textEdit_Anfahren->setMaximumSize(QSize(16777215, 100));
        QFont font;
        font.setFamilies({QString::fromUtf8("Lucida Console")});
        textEdit_Anfahren->setFont(font);

        verticalLayout->addWidget(textEdit_Anfahren);


        retranslateUi(TP_Steg);

        QMetaObject::connectSlotsByName(TP_Steg);
    } // setupUi

    void retranslateUi(QWidget *TP_Steg)
    {
        TP_Steg->setWindowTitle(QCoreApplication::translate("TP_Steg", "Form", nullptr));
        comboBox_Frame->setItemText(0, QCoreApplication::translate("TP_Steg", "Oben", nullptr));
        comboBox_Frame->setItemText(1, QCoreApplication::translate("TP_Steg", "Hinten", nullptr));
        comboBox_Frame->setItemText(2, QCoreApplication::translate("TP_Steg", "Links", nullptr));
        comboBox_Frame->setItemText(3, QCoreApplication::translate("TP_Steg", "Vorne", nullptr));
        comboBox_Frame->setItemText(4, QCoreApplication::translate("TP_Steg", "Rechts", nullptr));

        label_Korrekturziel->setText(QCoreApplication::translate("TP_Steg", "Korrekturziel", nullptr));
        lineEdit_Nullpunkverschiebung->setText(QCoreApplication::translate("TP_Steg", "Nullpunktverschiebung", nullptr));
        lineEdit_Aktive_NPV->setText(QCoreApplication::translate("TP_Steg", "aktive NPV", nullptr));
        lineEdit_Aktive_NPV_2->setText(QCoreApplication::translate("TP_Steg", "fein", nullptr));
        label_Messrichtung->setText(QCoreApplication::translate("TP_Steg", "Messachse", nullptr));
        comboBox_Messachse->setItemText(0, QCoreApplication::translate("TP_Steg", "X", nullptr));
        comboBox_Messachse->setItemText(1, QCoreApplication::translate("TP_Steg", "Y", nullptr));

        label_W->setText(QCoreApplication::translate("TP_Steg", "W", nullptr));
        lineEdit_W->setText(QString());
        label_Alpha->setText(QCoreApplication::translate("TP_Steg", "\316\261", nullptr));
        lineEdit_Alpha->setText(QCoreApplication::translate("TP_Steg", "0.000", nullptr));
        label_DZ->setText(QCoreApplication::translate("TP_Steg", "DZ", nullptr));
        lineEdit_DZ->setText(QCoreApplication::translate("TP_Steg", "17", nullptr));
        label_Schutzzone->setText(QCoreApplication::translate("TP_Steg", "Schutzzone", nullptr));
        lineEdit_Schutzzone->setText(QCoreApplication::translate("TP_Steg", "nein", nullptr));
        label_DFA->setText(QCoreApplication::translate("TP_Steg", "DFA", nullptr));
        lineEdit_DFA->setText(QCoreApplication::translate("TP_Steg", "10", nullptr));
        label_TSA->setText(QCoreApplication::translate("TP_Steg", "TSA", nullptr));
        lineEdit_TSA->setText(QCoreApplication::translate("TP_Steg", "0.500", nullptr));
        toolButton_Paste->setText(QCoreApplication::translate("TP_Steg", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TP_Steg: public Ui_TP_Steg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TP_STEG_H
