/********************************************************************************
** Form generated from reading UI file 'tp_kante.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TP_KANTE_H
#define UI_TP_KANTE_H

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

class Ui_TP_Kante
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
    QHBoxLayout *horizontalLayout_Messrichtung;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    MComboBox *comboBox_Messrichtung;
    MComboBox *comboBox_Messachse;
    QHBoxLayout *horizontalLayout_Wert;
    QLabel *label_Wert;
    QLineEdit *lineEdit_Wert;
    QSpacerItem *horizontalSpacer_Wert;
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

    void setupUi(QWidget *TP_Kante)
    {
        if (TP_Kante->objectName().isEmpty())
            TP_Kante->setObjectName("TP_Kante");
        TP_Kante->resize(270, 301);
        TP_Kante->setMaximumSize(QSize(270, 16777215));
        verticalLayout = new QVBoxLayout(TP_Kante);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        comboBox_Frame = new MComboBox(TP_Kante);
        comboBox_Frame->addItem(QString());
        comboBox_Frame->addItem(QString());
        comboBox_Frame->addItem(QString());
        comboBox_Frame->addItem(QString());
        comboBox_Frame->addItem(QString());
        comboBox_Frame->setObjectName("comboBox_Frame");

        verticalLayout->addWidget(comboBox_Frame);

        verticalSpacer_2 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        label_Korrekturziel = new QLabel(TP_Kante);
        label_Korrekturziel->setObjectName("label_Korrekturziel");
        label_Korrekturziel->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(label_Korrekturziel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_Nullpunktverschiebung = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_Nullpunktverschiebung);

        lineEdit_Nullpunkverschiebung = new QLineEdit(TP_Kante);
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

        lineEdit_Aktive_NPV = new QLineEdit(TP_Kante);
        lineEdit_Aktive_NPV->setObjectName("lineEdit_Aktive_NPV");
        lineEdit_Aktive_NPV->setEnabled(false);
        lineEdit_Aktive_NPV->setMinimumSize(QSize(120, 0));
        lineEdit_Aktive_NPV->setMaximumSize(QSize(120, 20));
        lineEdit_Aktive_NPV->setAlignment(Qt::AlignCenter);

        horizontalLayout_Aktive_NPV->addWidget(lineEdit_Aktive_NPV);

        horizontalSpacer_2 = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_Aktive_NPV->addItem(horizontalSpacer_2);

        lineEdit_Aktive_NPV_2 = new QLineEdit(TP_Kante);
        lineEdit_Aktive_NPV_2->setObjectName("lineEdit_Aktive_NPV_2");
        lineEdit_Aktive_NPV_2->setEnabled(false);
        lineEdit_Aktive_NPV_2->setMinimumSize(QSize(55, 0));
        lineEdit_Aktive_NPV_2->setMaximumSize(QSize(55, 20));
        lineEdit_Aktive_NPV_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_Aktive_NPV->addWidget(lineEdit_Aktive_NPV_2);


        verticalLayout->addLayout(horizontalLayout_Aktive_NPV);

        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_Messrichtung = new QHBoxLayout();
        horizontalLayout_Messrichtung->setObjectName("horizontalLayout_Messrichtung");
        label_2 = new QLabel(TP_Kante);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_Messrichtung->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Messrichtung->addItem(horizontalSpacer_3);

        comboBox_Messrichtung = new MComboBox(TP_Kante);
        comboBox_Messrichtung->addItem(QString());
        comboBox_Messrichtung->addItem(QString());
        comboBox_Messrichtung->setObjectName("comboBox_Messrichtung");
        comboBox_Messrichtung->setMaximumSize(QSize(40, 20));

        horizontalLayout_Messrichtung->addWidget(comboBox_Messrichtung);

        comboBox_Messachse = new MComboBox(TP_Kante);
        comboBox_Messachse->addItem(QString());
        comboBox_Messachse->addItem(QString());
        comboBox_Messachse->addItem(QString());
        comboBox_Messachse->setObjectName("comboBox_Messachse");
        comboBox_Messachse->setMaximumSize(QSize(70, 20));

        horizontalLayout_Messrichtung->addWidget(comboBox_Messachse);


        verticalLayout->addLayout(horizontalLayout_Messrichtung);

        horizontalLayout_Wert = new QHBoxLayout();
        horizontalLayout_Wert->setObjectName("horizontalLayout_Wert");
        label_Wert = new QLabel(TP_Kante);
        label_Wert->setObjectName("label_Wert");
        label_Wert->setMinimumSize(QSize(45, 20));
        label_Wert->setMaximumSize(QSize(45, 20));
        label_Wert->setSizeIncrement(QSize(0, 20));

        horizontalLayout_Wert->addWidget(label_Wert);

        lineEdit_Wert = new QLineEdit(TP_Kante);
        lineEdit_Wert->setObjectName("lineEdit_Wert");
        lineEdit_Wert->setMaximumSize(QSize(75, 20));
        lineEdit_Wert->setSizeIncrement(QSize(0, 20));
        lineEdit_Wert->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_Wert->addWidget(lineEdit_Wert);

        horizontalSpacer_Wert = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Wert->addItem(horizontalSpacer_Wert);


        verticalLayout->addLayout(horizontalLayout_Wert);

        horizontalLayout_DFA = new QHBoxLayout();
        horizontalLayout_DFA->setObjectName("horizontalLayout_DFA");
        label_DFA = new QLabel(TP_Kante);
        label_DFA->setObjectName("label_DFA");
        label_DFA->setMinimumSize(QSize(45, 0));
        label_DFA->setMaximumSize(QSize(45, 20));

        horizontalLayout_DFA->addWidget(label_DFA);

        lineEdit_DFA = new QLineEdit(TP_Kante);
        lineEdit_DFA->setObjectName("lineEdit_DFA");
        lineEdit_DFA->setMaximumSize(QSize(75, 20));
        lineEdit_DFA->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_DFA->addWidget(lineEdit_DFA);

        horizontalSpacer_DFA = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_DFA->addItem(horizontalSpacer_DFA);


        verticalLayout->addLayout(horizontalLayout_DFA);

        horizontalLayout_TSA = new QHBoxLayout();
        horizontalLayout_TSA->setObjectName("horizontalLayout_TSA");
        label_TSA = new QLabel(TP_Kante);
        label_TSA->setObjectName("label_TSA");
        label_TSA->setMinimumSize(QSize(45, 0));
        label_TSA->setMaximumSize(QSize(45, 20));

        horizontalLayout_TSA->addWidget(label_TSA);

        lineEdit_TSA = new QLineEdit(TP_Kante);
        lineEdit_TSA->setObjectName("lineEdit_TSA");
        lineEdit_TSA->setMaximumSize(QSize(75, 20));
        lineEdit_TSA->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_TSA->addWidget(lineEdit_TSA);

        horizontalSpacer_TSA = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_TSA->addItem(horizontalSpacer_TSA);

        toolButton_Paste = new QToolButton(TP_Kante);
        toolButton_Paste->setObjectName("toolButton_Paste");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/paste.png"), QSize(), QIcon::Normal, QIcon::On);
        toolButton_Paste->setIcon(icon);

        horizontalLayout_TSA->addWidget(toolButton_Paste);


        verticalLayout->addLayout(horizontalLayout_TSA);

        textEdit_Anfahren = new QTextEdit(TP_Kante);
        textEdit_Anfahren->setObjectName("textEdit_Anfahren");
        textEdit_Anfahren->setMinimumSize(QSize(0, 100));
        textEdit_Anfahren->setMaximumSize(QSize(16777215, 100));
        QFont font;
        font.setFamilies({QString::fromUtf8("Lucida Console")});
        textEdit_Anfahren->setFont(font);

        verticalLayout->addWidget(textEdit_Anfahren);


        retranslateUi(TP_Kante);

        QMetaObject::connectSlotsByName(TP_Kante);
    } // setupUi

    void retranslateUi(QWidget *TP_Kante)
    {
        TP_Kante->setWindowTitle(QCoreApplication::translate("TP_Kante", "Form", nullptr));
        comboBox_Frame->setItemText(0, QCoreApplication::translate("TP_Kante", "Oben", nullptr));
        comboBox_Frame->setItemText(1, QCoreApplication::translate("TP_Kante", "Hinten", nullptr));
        comboBox_Frame->setItemText(2, QCoreApplication::translate("TP_Kante", "Links", nullptr));
        comboBox_Frame->setItemText(3, QCoreApplication::translate("TP_Kante", "Vorne", nullptr));
        comboBox_Frame->setItemText(4, QCoreApplication::translate("TP_Kante", "Rechts", nullptr));

        label_Korrekturziel->setText(QCoreApplication::translate("TP_Kante", "Korrekturziel", nullptr));
        lineEdit_Nullpunkverschiebung->setText(QCoreApplication::translate("TP_Kante", "Nullpunktverschiebung", nullptr));
        lineEdit_Aktive_NPV->setText(QCoreApplication::translate("TP_Kante", "aktive NPV", nullptr));
        lineEdit_Aktive_NPV_2->setText(QCoreApplication::translate("TP_Kante", "fein", nullptr));
        label_2->setText(QCoreApplication::translate("TP_Kante", "Messrichtung", nullptr));
        comboBox_Messrichtung->setItemText(0, QCoreApplication::translate("TP_Kante", "+", nullptr));
        comboBox_Messrichtung->setItemText(1, QCoreApplication::translate("TP_Kante", "-", nullptr));

        comboBox_Messachse->setItemText(0, QCoreApplication::translate("TP_Kante", "X", nullptr));
        comboBox_Messachse->setItemText(1, QCoreApplication::translate("TP_Kante", "Y", nullptr));
        comboBox_Messachse->setItemText(2, QCoreApplication::translate("TP_Kante", "Z", nullptr));

        label_Wert->setText(QCoreApplication::translate("TP_Kante", "X0", nullptr));
        lineEdit_Wert->setText(QString());
        label_DFA->setText(QCoreApplication::translate("TP_Kante", "DFA", nullptr));
        lineEdit_DFA->setText(QCoreApplication::translate("TP_Kante", "10", nullptr));
        label_TSA->setText(QCoreApplication::translate("TP_Kante", "TSA", nullptr));
        lineEdit_TSA->setText(QCoreApplication::translate("TP_Kante", "0.500", nullptr));
        toolButton_Paste->setText(QCoreApplication::translate("TP_Kante", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TP_Kante: public Ui_TP_Kante {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TP_KANTE_H
