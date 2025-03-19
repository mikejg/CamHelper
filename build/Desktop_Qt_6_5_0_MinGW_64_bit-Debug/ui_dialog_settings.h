/********************************************************************************
** Form generated from reading UI file 'dialog_settings.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_SETTINGS_H
#define UI_DIALOG_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Settings
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label_Programme;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit_Programme;
    QToolButton *toolButton_Programme;
    QLabel *label_Magazin;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineEdit_Magazin;
    QToolButton *toolButton_Magazin;
    QLabel *label_WerkzeugDB;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *lineEdit_WerkzeugDB;
    QToolButton *toolButton_WerkzeugDB;
    QGroupBox *groupBox_NPOffset;
    QHBoxLayout *horizontalLayout;
    QLabel *label_X;
    QLineEdit *lineEdit_X;
    QLabel *label_2;
    QLineEdit *lineEdit_Y;
    QLabel *label;
    QLineEdit *lineEdit_Z;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *checkBox_Numbering;
    QSpacerItem *horizontalSpacer;
    QLabel *label_WerkzeugPlatze;
    QSpinBox *spinBox_WerkzeugPlatze;
    QCheckBox *checkBox_AufmassMax;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog_Settings)
    {
        if (Dialog_Settings->objectName().isEmpty())
            Dialog_Settings->setObjectName("Dialog_Settings");
        Dialog_Settings->resize(340, 400);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog_Settings->sizePolicy().hasHeightForWidth());
        Dialog_Settings->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(Dialog_Settings);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_Programme = new QLabel(Dialog_Settings);
        label_Programme->setObjectName("label_Programme");
        label_Programme->setMinimumSize(QSize(0, 30));
        label_Programme->setMaximumSize(QSize(16777215, 30));

        verticalLayout_2->addWidget(label_Programme);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        lineEdit_Programme = new QLineEdit(Dialog_Settings);
        lineEdit_Programme->setObjectName("lineEdit_Programme");
        lineEdit_Programme->setMinimumSize(QSize(0, 30));
        lineEdit_Programme->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_4->addWidget(lineEdit_Programme);

        toolButton_Programme = new QToolButton(Dialog_Settings);
        toolButton_Programme->setObjectName("toolButton_Programme");
        toolButton_Programme->setMinimumSize(QSize(30, 30));
        toolButton_Programme->setMaximumSize(QSize(30, 30));

        horizontalLayout_4->addWidget(toolButton_Programme);


        verticalLayout_2->addLayout(horizontalLayout_4);

        label_Magazin = new QLabel(Dialog_Settings);
        label_Magazin->setObjectName("label_Magazin");
        label_Magazin->setMinimumSize(QSize(0, 30));
        label_Magazin->setMaximumSize(QSize(16777215, 30));

        verticalLayout_2->addWidget(label_Magazin);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        lineEdit_Magazin = new QLineEdit(Dialog_Settings);
        lineEdit_Magazin->setObjectName("lineEdit_Magazin");
        lineEdit_Magazin->setMinimumSize(QSize(0, 30));
        lineEdit_Magazin->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_5->addWidget(lineEdit_Magazin);

        toolButton_Magazin = new QToolButton(Dialog_Settings);
        toolButton_Magazin->setObjectName("toolButton_Magazin");
        toolButton_Magazin->setMinimumSize(QSize(30, 30));
        toolButton_Magazin->setMaximumSize(QSize(30, 30));

        horizontalLayout_5->addWidget(toolButton_Magazin);


        verticalLayout_2->addLayout(horizontalLayout_5);

        label_WerkzeugDB = new QLabel(Dialog_Settings);
        label_WerkzeugDB->setObjectName("label_WerkzeugDB");
        label_WerkzeugDB->setMinimumSize(QSize(0, 30));
        label_WerkzeugDB->setMaximumSize(QSize(16777215, 30));

        verticalLayout_2->addWidget(label_WerkzeugDB);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        lineEdit_WerkzeugDB = new QLineEdit(Dialog_Settings);
        lineEdit_WerkzeugDB->setObjectName("lineEdit_WerkzeugDB");
        lineEdit_WerkzeugDB->setMinimumSize(QSize(0, 30));
        lineEdit_WerkzeugDB->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_6->addWidget(lineEdit_WerkzeugDB);

        toolButton_WerkzeugDB = new QToolButton(Dialog_Settings);
        toolButton_WerkzeugDB->setObjectName("toolButton_WerkzeugDB");
        toolButton_WerkzeugDB->setMinimumSize(QSize(30, 30));
        toolButton_WerkzeugDB->setMaximumSize(QSize(30, 30));

        horizontalLayout_6->addWidget(toolButton_WerkzeugDB);


        verticalLayout_2->addLayout(horizontalLayout_6);

        groupBox_NPOffset = new QGroupBox(Dialog_Settings);
        groupBox_NPOffset->setObjectName("groupBox_NPOffset");
        horizontalLayout = new QHBoxLayout(groupBox_NPOffset);
        horizontalLayout->setObjectName("horizontalLayout");
        label_X = new QLabel(groupBox_NPOffset);
        label_X->setObjectName("label_X");

        horizontalLayout->addWidget(label_X);

        lineEdit_X = new QLineEdit(groupBox_NPOffset);
        lineEdit_X->setObjectName("lineEdit_X");

        horizontalLayout->addWidget(lineEdit_X);

        label_2 = new QLabel(groupBox_NPOffset);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        lineEdit_Y = new QLineEdit(groupBox_NPOffset);
        lineEdit_Y->setObjectName("lineEdit_Y");

        horizontalLayout->addWidget(lineEdit_Y);

        label = new QLabel(groupBox_NPOffset);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        lineEdit_Z = new QLineEdit(groupBox_NPOffset);
        lineEdit_Z->setObjectName("lineEdit_Z");

        horizontalLayout->addWidget(lineEdit_Z);


        verticalLayout_2->addWidget(groupBox_NPOffset);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        checkBox_Numbering = new QCheckBox(Dialog_Settings);
        checkBox_Numbering->setObjectName("checkBox_Numbering");

        horizontalLayout_7->addWidget(checkBox_Numbering);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        label_WerkzeugPlatze = new QLabel(Dialog_Settings);
        label_WerkzeugPlatze->setObjectName("label_WerkzeugPlatze");

        horizontalLayout_7->addWidget(label_WerkzeugPlatze);

        spinBox_WerkzeugPlatze = new QSpinBox(Dialog_Settings);
        spinBox_WerkzeugPlatze->setObjectName("spinBox_WerkzeugPlatze");
        spinBox_WerkzeugPlatze->setMaximumSize(QSize(50, 16777215));
        spinBox_WerkzeugPlatze->setMaximum(200);
        spinBox_WerkzeugPlatze->setValue(100);

        horizontalLayout_7->addWidget(spinBox_WerkzeugPlatze);


        verticalLayout->addLayout(horizontalLayout_7);

        checkBox_AufmassMax = new QCheckBox(Dialog_Settings);
        checkBox_AufmassMax->setObjectName("checkBox_AufmassMax");

        verticalLayout->addWidget(checkBox_AufmassMax);


        verticalLayout_2->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(Dialog_Settings);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(Dialog_Settings);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Dialog_Settings, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Dialog_Settings, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Dialog_Settings);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Settings)
    {
        Dialog_Settings->setWindowTitle(QCoreApplication::translate("Dialog_Settings", "Einstellungen", nullptr));
        label_Programme->setText(QCoreApplication::translate("Dialog_Settings", "Verzeichnis Programme", nullptr));
        toolButton_Programme->setText(QCoreApplication::translate("Dialog_Settings", "...", nullptr));
        label_Magazin->setText(QCoreApplication::translate("Dialog_Settings", "Verzeichnis Werkzeug Magazin", nullptr));
        toolButton_Magazin->setText(QCoreApplication::translate("Dialog_Settings", "...", nullptr));
        label_WerkzeugDB->setText(QCoreApplication::translate("Dialog_Settings", "Werkzeug Datenbank", nullptr));
        toolButton_WerkzeugDB->setText(QCoreApplication::translate("Dialog_Settings", "...", nullptr));
        groupBox_NPOffset->setTitle(QCoreApplication::translate("Dialog_Settings", "NP Offset", nullptr));
        label_X->setText(QCoreApplication::translate("Dialog_Settings", "X", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog_Settings", "Y", nullptr));
        label->setText(QCoreApplication::translate("Dialog_Settings", "Z", nullptr));
        checkBox_Numbering->setText(QCoreApplication::translate("Dialog_Settings", "Nummerierung", nullptr));
        label_WerkzeugPlatze->setText(QCoreApplication::translate("Dialog_Settings", "Pl\303\244tze im Werkzeugmagazin", nullptr));
        checkBox_AufmassMax->setText(QCoreApplication::translate("Dialog_Settings", "Aufmass Max vom Bauteil", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Settings: public Ui_Dialog_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_SETTINGS_H
