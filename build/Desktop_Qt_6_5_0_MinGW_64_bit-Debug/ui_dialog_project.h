/********************************************************************************
** Form generated from reading UI file 'dialog_project.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_PROJECT_H
#define UI_DIALOG_PROJECT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Project
{
public:
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_ProjectName;
    QLineEdit *lineEdit_ProjectStatus;
    QGroupBox *groupBox_Rohteil;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_X;
    QLineEdit *lineEdit_RTx;
    QLabel *label_Y;
    QLineEdit *lineEdit_RTy;
    QLabel *label_Z;
    QLineEdit *lineEdit_RTz;
    QSpacerItem *horizontalSpacer;
    QLabel *label_RohteilKontrolle;
    QToolButton *toolButton_RawPartInspection;
    QGroupBox *groupBox_Bauteil;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_X_2;
    QLineEdit *lineEdit_BTx;
    QLabel *label_Y_2;
    QLineEdit *lineEdit_BTy;
    QLabel *label_Z_2;
    QLineEdit *lineEdit_BTz;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_ZRohTeil;
    QDoubleSpinBox *doubleSpinBox_ZRohTeil;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_Spannung;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *comboBox_Clamping;
    QLineEdit *lineEdit_NP;
    QLabel *label_Material;
    QComboBox *comboBox_Material;
    QGroupBox *groupBox_AufmassMaxRT;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox_RT_EinzelAufmass;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_RT_All;
    QDoubleSpinBox *doubleSpinBox_RT_All;
    QWidget *widget_RT_AufmassEinzel;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_RT_Xplus;
    QDoubleSpinBox *doubleSpinBox_Xplus_Max;
    QLabel *label_RT_Xminus;
    QDoubleSpinBox *doubleSpinBox_Xminus_Max;
    QLabel *label_RT_Yplus;
    QDoubleSpinBox *doubleSpinBox_Yplus_Max;
    QLabel *label_RT_Yminus;
    QDoubleSpinBox *doubleSpinBox_Yminus_Max;
    QLabel *label_RT_Zplus;
    QDoubleSpinBox *doubleSpinBox_Zplus_Max;
    QGroupBox *groupBox_AufmassMinFT;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_9;
    QCheckBox *checkBox_FT_EinzelAufmass;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_FT_All;
    QDoubleSpinBox *doubleSpinBox_FT_All;
    QWidget *widget_FT_AufmassEinzel;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_FT_Xplus;
    QDoubleSpinBox *doubleSpinBox_Xplus_Min;
    QLabel *label_FT_Xminus;
    QDoubleSpinBox *doubleSpinBox_Xminus_Min;
    QLabel *label_FT_Yplus;
    QDoubleSpinBox *doubleSpinBox_Yplus_Min;
    QLabel *label_FT_Yminus;
    QDoubleSpinBox *doubleSpinBox_Yminus_Min;
    QLabel *label_FT_Zplus;
    QDoubleSpinBox *doubleSpinBox_Zplus_Min;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog_Project)
    {
        if (Dialog_Project->objectName().isEmpty())
            Dialog_Project->setObjectName("Dialog_Project");
        Dialog_Project->resize(453, 654);
        verticalLayout_5 = new QVBoxLayout(Dialog_Project);
        verticalLayout_5->setObjectName("verticalLayout_5");
        groupBox = new QGroupBox(Dialog_Project);
        groupBox->setObjectName("groupBox");
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lineEdit_ProjectName = new QLineEdit(groupBox);
        lineEdit_ProjectName->setObjectName("lineEdit_ProjectName");
        lineEdit_ProjectName->setMinimumSize(QSize(0, 30));
        lineEdit_ProjectName->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_2->addWidget(lineEdit_ProjectName);

        lineEdit_ProjectStatus = new QLineEdit(groupBox);
        lineEdit_ProjectStatus->setObjectName("lineEdit_ProjectStatus");
        lineEdit_ProjectStatus->setMinimumSize(QSize(0, 30));
        lineEdit_ProjectStatus->setMaximumSize(QSize(45, 30));

        horizontalLayout_2->addWidget(lineEdit_ProjectStatus);


        verticalLayout_5->addWidget(groupBox);

        groupBox_Rohteil = new QGroupBox(Dialog_Project);
        groupBox_Rohteil->setObjectName("groupBox_Rohteil");
        verticalLayout = new QVBoxLayout(groupBox_Rohteil);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_X = new QLabel(groupBox_Rohteil);
        label_X->setObjectName("label_X");

        horizontalLayout_3->addWidget(label_X);

        lineEdit_RTx = new QLineEdit(groupBox_Rohteil);
        lineEdit_RTx->setObjectName("lineEdit_RTx");
        lineEdit_RTx->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_3->addWidget(lineEdit_RTx);

        label_Y = new QLabel(groupBox_Rohteil);
        label_Y->setObjectName("label_Y");

        horizontalLayout_3->addWidget(label_Y);

        lineEdit_RTy = new QLineEdit(groupBox_Rohteil);
        lineEdit_RTy->setObjectName("lineEdit_RTy");
        lineEdit_RTy->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_3->addWidget(lineEdit_RTy);

        label_Z = new QLabel(groupBox_Rohteil);
        label_Z->setObjectName("label_Z");

        horizontalLayout_3->addWidget(label_Z);

        lineEdit_RTz = new QLineEdit(groupBox_Rohteil);
        lineEdit_RTz->setObjectName("lineEdit_RTz");
        lineEdit_RTz->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_3->addWidget(lineEdit_RTz);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label_RohteilKontrolle = new QLabel(groupBox_Rohteil);
        label_RohteilKontrolle->setObjectName("label_RohteilKontrolle");

        horizontalLayout_3->addWidget(label_RohteilKontrolle);

        toolButton_RawPartInspection = new QToolButton(groupBox_Rohteil);
        toolButton_RawPartInspection->setObjectName("toolButton_RawPartInspection");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/more.png"), QSize(), QIcon::Normal, QIcon::On);
        toolButton_RawPartInspection->setIcon(icon);

        horizontalLayout_3->addWidget(toolButton_RawPartInspection);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_5->addWidget(groupBox_Rohteil);

        groupBox_Bauteil = new QGroupBox(Dialog_Project);
        groupBox_Bauteil->setObjectName("groupBox_Bauteil");
        verticalLayout_2 = new QVBoxLayout(groupBox_Bauteil);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_X_2 = new QLabel(groupBox_Bauteil);
        label_X_2->setObjectName("label_X_2");

        horizontalLayout_6->addWidget(label_X_2);

        lineEdit_BTx = new QLineEdit(groupBox_Bauteil);
        lineEdit_BTx->setObjectName("lineEdit_BTx");
        lineEdit_BTx->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_6->addWidget(lineEdit_BTx);

        label_Y_2 = new QLabel(groupBox_Bauteil);
        label_Y_2->setObjectName("label_Y_2");

        horizontalLayout_6->addWidget(label_Y_2);

        lineEdit_BTy = new QLineEdit(groupBox_Bauteil);
        lineEdit_BTy->setObjectName("lineEdit_BTy");
        lineEdit_BTy->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_6->addWidget(lineEdit_BTy);

        label_Z_2 = new QLabel(groupBox_Bauteil);
        label_Z_2->setObjectName("label_Z_2");

        horizontalLayout_6->addWidget(label_Z_2);

        lineEdit_BTz = new QLineEdit(groupBox_Bauteil);
        lineEdit_BTz->setObjectName("lineEdit_BTz");
        lineEdit_BTz->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_6->addWidget(lineEdit_BTz);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_6);


        verticalLayout_5->addWidget(groupBox_Bauteil);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_ZRohTeil = new QLabel(Dialog_Project);
        label_ZRohTeil->setObjectName("label_ZRohTeil");

        horizontalLayout_4->addWidget(label_ZRohTeil);

        doubleSpinBox_ZRohTeil = new QDoubleSpinBox(Dialog_Project);
        doubleSpinBox_ZRohTeil->setObjectName("doubleSpinBox_ZRohTeil");
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(doubleSpinBox_ZRohTeil->sizePolicy().hasHeightForWidth());
        doubleSpinBox_ZRohTeil->setSizePolicy(sizePolicy);
        doubleSpinBox_ZRohTeil->setSingleStep(0.500000000000000);
        doubleSpinBox_ZRohTeil->setValue(1.000000000000000);

        horizontalLayout_4->addWidget(doubleSpinBox_ZRohTeil);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_5->addLayout(horizontalLayout_4);

        label_Spannung = new QLabel(Dialog_Project);
        label_Spannung->setObjectName("label_Spannung");
        label_Spannung->setMaximumSize(QSize(16777215, 30));

        verticalLayout_5->addWidget(label_Spannung);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        comboBox_Clamping = new QComboBox(Dialog_Project);
        comboBox_Clamping->setObjectName("comboBox_Clamping");

        horizontalLayout_5->addWidget(comboBox_Clamping);

        lineEdit_NP = new QLineEdit(Dialog_Project);
        lineEdit_NP->setObjectName("lineEdit_NP");
        lineEdit_NP->setEnabled(false);
        lineEdit_NP->setMaximumSize(QSize(75, 16777215));

        horizontalLayout_5->addWidget(lineEdit_NP);


        verticalLayout_5->addLayout(horizontalLayout_5);

        label_Material = new QLabel(Dialog_Project);
        label_Material->setObjectName("label_Material");
        label_Material->setMaximumSize(QSize(16777215, 30));

        verticalLayout_5->addWidget(label_Material);

        comboBox_Material = new QComboBox(Dialog_Project);
        comboBox_Material->setObjectName("comboBox_Material");

        verticalLayout_5->addWidget(comboBox_Material);

        groupBox_AufmassMaxRT = new QGroupBox(Dialog_Project);
        groupBox_AufmassMaxRT->setObjectName("groupBox_AufmassMaxRT");
        groupBox_AufmassMaxRT->setFlat(true);
        verticalLayout_3 = new QVBoxLayout(groupBox_AufmassMaxRT);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        checkBox_RT_EinzelAufmass = new QCheckBox(groupBox_AufmassMaxRT);
        checkBox_RT_EinzelAufmass->setObjectName("checkBox_RT_EinzelAufmass");

        horizontalLayout->addWidget(checkBox_RT_EinzelAufmass);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        label_RT_All = new QLabel(groupBox_AufmassMaxRT);
        label_RT_All->setObjectName("label_RT_All");

        horizontalLayout->addWidget(label_RT_All);

        doubleSpinBox_RT_All = new QDoubleSpinBox(groupBox_AufmassMaxRT);
        doubleSpinBox_RT_All->setObjectName("doubleSpinBox_RT_All");
        doubleSpinBox_RT_All->setDecimals(1);
        doubleSpinBox_RT_All->setSingleStep(0.500000000000000);
        doubleSpinBox_RT_All->setValue(2.000000000000000);

        horizontalLayout->addWidget(doubleSpinBox_RT_All);


        verticalLayout_3->addLayout(horizontalLayout);

        widget_RT_AufmassEinzel = new QWidget(groupBox_AufmassMaxRT);
        widget_RT_AufmassEinzel->setObjectName("widget_RT_AufmassEinzel");
        widget_RT_AufmassEinzel->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_7 = new QHBoxLayout(widget_RT_AufmassEinzel);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_RT_Xplus = new QLabel(widget_RT_AufmassEinzel);
        label_RT_Xplus->setObjectName("label_RT_Xplus");

        horizontalLayout_7->addWidget(label_RT_Xplus);

        doubleSpinBox_Xplus_Max = new QDoubleSpinBox(widget_RT_AufmassEinzel);
        doubleSpinBox_Xplus_Max->setObjectName("doubleSpinBox_Xplus_Max");
        doubleSpinBox_Xplus_Max->setDecimals(1);
        doubleSpinBox_Xplus_Max->setSingleStep(0.500000000000000);
        doubleSpinBox_Xplus_Max->setValue(2.000000000000000);

        horizontalLayout_7->addWidget(doubleSpinBox_Xplus_Max);

        label_RT_Xminus = new QLabel(widget_RT_AufmassEinzel);
        label_RT_Xminus->setObjectName("label_RT_Xminus");

        horizontalLayout_7->addWidget(label_RT_Xminus);

        doubleSpinBox_Xminus_Max = new QDoubleSpinBox(widget_RT_AufmassEinzel);
        doubleSpinBox_Xminus_Max->setObjectName("doubleSpinBox_Xminus_Max");
        doubleSpinBox_Xminus_Max->setDecimals(1);
        doubleSpinBox_Xminus_Max->setSingleStep(0.500000000000000);
        doubleSpinBox_Xminus_Max->setValue(2.000000000000000);

        horizontalLayout_7->addWidget(doubleSpinBox_Xminus_Max);

        label_RT_Yplus = new QLabel(widget_RT_AufmassEinzel);
        label_RT_Yplus->setObjectName("label_RT_Yplus");

        horizontalLayout_7->addWidget(label_RT_Yplus);

        doubleSpinBox_Yplus_Max = new QDoubleSpinBox(widget_RT_AufmassEinzel);
        doubleSpinBox_Yplus_Max->setObjectName("doubleSpinBox_Yplus_Max");
        doubleSpinBox_Yplus_Max->setDecimals(1);
        doubleSpinBox_Yplus_Max->setSingleStep(0.500000000000000);
        doubleSpinBox_Yplus_Max->setValue(2.000000000000000);

        horizontalLayout_7->addWidget(doubleSpinBox_Yplus_Max);

        label_RT_Yminus = new QLabel(widget_RT_AufmassEinzel);
        label_RT_Yminus->setObjectName("label_RT_Yminus");

        horizontalLayout_7->addWidget(label_RT_Yminus);

        doubleSpinBox_Yminus_Max = new QDoubleSpinBox(widget_RT_AufmassEinzel);
        doubleSpinBox_Yminus_Max->setObjectName("doubleSpinBox_Yminus_Max");
        doubleSpinBox_Yminus_Max->setDecimals(1);
        doubleSpinBox_Yminus_Max->setSingleStep(0.500000000000000);
        doubleSpinBox_Yminus_Max->setValue(2.000000000000000);

        horizontalLayout_7->addWidget(doubleSpinBox_Yminus_Max);

        label_RT_Zplus = new QLabel(widget_RT_AufmassEinzel);
        label_RT_Zplus->setObjectName("label_RT_Zplus");

        horizontalLayout_7->addWidget(label_RT_Zplus);

        doubleSpinBox_Zplus_Max = new QDoubleSpinBox(widget_RT_AufmassEinzel);
        doubleSpinBox_Zplus_Max->setObjectName("doubleSpinBox_Zplus_Max");
        doubleSpinBox_Zplus_Max->setDecimals(1);
        doubleSpinBox_Zplus_Max->setSingleStep(0.500000000000000);
        doubleSpinBox_Zplus_Max->setValue(2.000000000000000);

        horizontalLayout_7->addWidget(doubleSpinBox_Zplus_Max);


        verticalLayout_3->addWidget(widget_RT_AufmassEinzel);


        verticalLayout_5->addWidget(groupBox_AufmassMaxRT);

        groupBox_AufmassMinFT = new QGroupBox(Dialog_Project);
        groupBox_AufmassMinFT->setObjectName("groupBox_AufmassMinFT");
        verticalLayout_4 = new QVBoxLayout(groupBox_AufmassMinFT);
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        checkBox_FT_EinzelAufmass = new QCheckBox(groupBox_AufmassMinFT);
        checkBox_FT_EinzelAufmass->setObjectName("checkBox_FT_EinzelAufmass");

        horizontalLayout_9->addWidget(checkBox_FT_EinzelAufmass);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);

        label_FT_All = new QLabel(groupBox_AufmassMinFT);
        label_FT_All->setObjectName("label_FT_All");

        horizontalLayout_9->addWidget(label_FT_All);

        doubleSpinBox_FT_All = new QDoubleSpinBox(groupBox_AufmassMinFT);
        doubleSpinBox_FT_All->setObjectName("doubleSpinBox_FT_All");
        doubleSpinBox_FT_All->setDecimals(1);
        doubleSpinBox_FT_All->setSingleStep(0.500000000000000);
        doubleSpinBox_FT_All->setValue(1.500000000000000);

        horizontalLayout_9->addWidget(doubleSpinBox_FT_All);


        verticalLayout_4->addLayout(horizontalLayout_9);

        widget_FT_AufmassEinzel = new QWidget(groupBox_AufmassMinFT);
        widget_FT_AufmassEinzel->setObjectName("widget_FT_AufmassEinzel");
        widget_FT_AufmassEinzel->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_10 = new QHBoxLayout(widget_FT_AufmassEinzel);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        label_FT_Xplus = new QLabel(widget_FT_AufmassEinzel);
        label_FT_Xplus->setObjectName("label_FT_Xplus");

        horizontalLayout_10->addWidget(label_FT_Xplus);

        doubleSpinBox_Xplus_Min = new QDoubleSpinBox(widget_FT_AufmassEinzel);
        doubleSpinBox_Xplus_Min->setObjectName("doubleSpinBox_Xplus_Min");
        doubleSpinBox_Xplus_Min->setDecimals(1);
        doubleSpinBox_Xplus_Min->setSingleStep(0.500000000000000);
        doubleSpinBox_Xplus_Min->setValue(1.500000000000000);

        horizontalLayout_10->addWidget(doubleSpinBox_Xplus_Min);

        label_FT_Xminus = new QLabel(widget_FT_AufmassEinzel);
        label_FT_Xminus->setObjectName("label_FT_Xminus");

        horizontalLayout_10->addWidget(label_FT_Xminus);

        doubleSpinBox_Xminus_Min = new QDoubleSpinBox(widget_FT_AufmassEinzel);
        doubleSpinBox_Xminus_Min->setObjectName("doubleSpinBox_Xminus_Min");
        doubleSpinBox_Xminus_Min->setDecimals(1);
        doubleSpinBox_Xminus_Min->setSingleStep(0.500000000000000);
        doubleSpinBox_Xminus_Min->setValue(1.500000000000000);

        horizontalLayout_10->addWidget(doubleSpinBox_Xminus_Min);

        label_FT_Yplus = new QLabel(widget_FT_AufmassEinzel);
        label_FT_Yplus->setObjectName("label_FT_Yplus");

        horizontalLayout_10->addWidget(label_FT_Yplus);

        doubleSpinBox_Yplus_Min = new QDoubleSpinBox(widget_FT_AufmassEinzel);
        doubleSpinBox_Yplus_Min->setObjectName("doubleSpinBox_Yplus_Min");
        doubleSpinBox_Yplus_Min->setDecimals(1);
        doubleSpinBox_Yplus_Min->setSingleStep(0.500000000000000);
        doubleSpinBox_Yplus_Min->setValue(1.500000000000000);

        horizontalLayout_10->addWidget(doubleSpinBox_Yplus_Min);

        label_FT_Yminus = new QLabel(widget_FT_AufmassEinzel);
        label_FT_Yminus->setObjectName("label_FT_Yminus");

        horizontalLayout_10->addWidget(label_FT_Yminus);

        doubleSpinBox_Yminus_Min = new QDoubleSpinBox(widget_FT_AufmassEinzel);
        doubleSpinBox_Yminus_Min->setObjectName("doubleSpinBox_Yminus_Min");
        doubleSpinBox_Yminus_Min->setDecimals(1);
        doubleSpinBox_Yminus_Min->setSingleStep(0.500000000000000);
        doubleSpinBox_Yminus_Min->setValue(1.500000000000000);

        horizontalLayout_10->addWidget(doubleSpinBox_Yminus_Min);

        label_FT_Zplus = new QLabel(widget_FT_AufmassEinzel);
        label_FT_Zplus->setObjectName("label_FT_Zplus");

        horizontalLayout_10->addWidget(label_FT_Zplus);

        doubleSpinBox_Zplus_Min = new QDoubleSpinBox(widget_FT_AufmassEinzel);
        doubleSpinBox_Zplus_Min->setObjectName("doubleSpinBox_Zplus_Min");
        doubleSpinBox_Zplus_Min->setDecimals(1);
        doubleSpinBox_Zplus_Min->setSingleStep(0.500000000000000);
        doubleSpinBox_Zplus_Min->setValue(0.500000000000000);

        horizontalLayout_10->addWidget(doubleSpinBox_Zplus_Min);


        verticalLayout_4->addWidget(widget_FT_AufmassEinzel);


        verticalLayout_5->addWidget(groupBox_AufmassMinFT);

        buttonBox = new QDialogButtonBox(Dialog_Project);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_5->addWidget(buttonBox);

        QWidget::setTabOrder(lineEdit_ProjectName, lineEdit_ProjectStatus);
        QWidget::setTabOrder(lineEdit_ProjectStatus, lineEdit_RTx);
        QWidget::setTabOrder(lineEdit_RTx, lineEdit_RTy);
        QWidget::setTabOrder(lineEdit_RTy, lineEdit_RTz);
        QWidget::setTabOrder(lineEdit_RTz, lineEdit_BTx);
        QWidget::setTabOrder(lineEdit_BTx, lineEdit_BTy);
        QWidget::setTabOrder(lineEdit_BTy, lineEdit_BTz);
        QWidget::setTabOrder(lineEdit_BTz, doubleSpinBox_ZRohTeil);
        QWidget::setTabOrder(doubleSpinBox_ZRohTeil, comboBox_Clamping);
        QWidget::setTabOrder(comboBox_Clamping, lineEdit_NP);
        QWidget::setTabOrder(lineEdit_NP, comboBox_Material);
        QWidget::setTabOrder(comboBox_Material, checkBox_RT_EinzelAufmass);
        QWidget::setTabOrder(checkBox_RT_EinzelAufmass, doubleSpinBox_RT_All);
        QWidget::setTabOrder(doubleSpinBox_RT_All, doubleSpinBox_Xplus_Max);
        QWidget::setTabOrder(doubleSpinBox_Xplus_Max, doubleSpinBox_Xminus_Max);
        QWidget::setTabOrder(doubleSpinBox_Xminus_Max, doubleSpinBox_Yplus_Max);
        QWidget::setTabOrder(doubleSpinBox_Yplus_Max, doubleSpinBox_Yminus_Max);
        QWidget::setTabOrder(doubleSpinBox_Yminus_Max, doubleSpinBox_Zplus_Max);
        QWidget::setTabOrder(doubleSpinBox_Zplus_Max, checkBox_FT_EinzelAufmass);
        QWidget::setTabOrder(checkBox_FT_EinzelAufmass, doubleSpinBox_FT_All);
        QWidget::setTabOrder(doubleSpinBox_FT_All, doubleSpinBox_Xplus_Min);
        QWidget::setTabOrder(doubleSpinBox_Xplus_Min, doubleSpinBox_Xminus_Min);
        QWidget::setTabOrder(doubleSpinBox_Xminus_Min, doubleSpinBox_Yplus_Min);
        QWidget::setTabOrder(doubleSpinBox_Yplus_Min, doubleSpinBox_Yminus_Min);
        QWidget::setTabOrder(doubleSpinBox_Yminus_Min, doubleSpinBox_Zplus_Min);

        retranslateUi(Dialog_Project);
        QObject::connect(doubleSpinBox_RT_All, &QDoubleSpinBox::valueChanged, doubleSpinBox_Xplus_Max, &QDoubleSpinBox::setValue);
        QObject::connect(doubleSpinBox_RT_All, &QDoubleSpinBox::valueChanged, doubleSpinBox_Xminus_Max, &QDoubleSpinBox::setValue);
        QObject::connect(doubleSpinBox_RT_All, &QDoubleSpinBox::valueChanged, doubleSpinBox_Yplus_Max, &QDoubleSpinBox::setValue);
        QObject::connect(doubleSpinBox_RT_All, &QDoubleSpinBox::valueChanged, doubleSpinBox_Yminus_Max, &QDoubleSpinBox::setValue);
        QObject::connect(doubleSpinBox_RT_All, &QDoubleSpinBox::valueChanged, doubleSpinBox_Zplus_Max, &QDoubleSpinBox::setValue);
        QObject::connect(doubleSpinBox_FT_All, &QDoubleSpinBox::valueChanged, doubleSpinBox_Xplus_Min, &QDoubleSpinBox::setValue);
        QObject::connect(doubleSpinBox_FT_All, &QDoubleSpinBox::valueChanged, doubleSpinBox_Xminus_Min, &QDoubleSpinBox::setValue);
        QObject::connect(doubleSpinBox_FT_All, &QDoubleSpinBox::valueChanged, doubleSpinBox_Yplus_Min, &QDoubleSpinBox::setValue);
        QObject::connect(doubleSpinBox_FT_All, &QDoubleSpinBox::valueChanged, doubleSpinBox_Yminus_Min, &QDoubleSpinBox::setValue);

        QMetaObject::connectSlotsByName(Dialog_Project);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Project)
    {
        Dialog_Project->setWindowTitle(QCoreApplication::translate("Dialog_Project", "Start", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Dialog_Project", "Projektname", nullptr));
        groupBox_Rohteil->setTitle(QCoreApplication::translate("Dialog_Project", "Rohteil", nullptr));
        label_X->setText(QCoreApplication::translate("Dialog_Project", "X", nullptr));
        lineEdit_RTx->setText(QString());
        label_Y->setText(QCoreApplication::translate("Dialog_Project", "Y", nullptr));
        lineEdit_RTy->setText(QString());
        label_Z->setText(QCoreApplication::translate("Dialog_Project", "Z", nullptr));
        lineEdit_RTz->setText(QString());
        label_RohteilKontrolle->setText(QCoreApplication::translate("Dialog_Project", "Rohteilkontrolle00", nullptr));
        toolButton_RawPartInspection->setText(QCoreApplication::translate("Dialog_Project", "...", nullptr));
        groupBox_Bauteil->setTitle(QCoreApplication::translate("Dialog_Project", "Bauteil", nullptr));
        label_X_2->setText(QCoreApplication::translate("Dialog_Project", "X", nullptr));
        lineEdit_BTx->setText(QString());
        label_Y_2->setText(QCoreApplication::translate("Dialog_Project", "Y", nullptr));
        lineEdit_BTy->setText(QString());
        label_Z_2->setText(QCoreApplication::translate("Dialog_Project", "Z", nullptr));
        lineEdit_BTz->setText(QString());
        label_ZRohTeil->setText(QCoreApplication::translate("Dialog_Project", "Z Rohteil", nullptr));
        label_Spannung->setText(QCoreApplication::translate("Dialog_Project", "Spannung", nullptr));
        label_Material->setText(QCoreApplication::translate("Dialog_Project", "Material", nullptr));
        groupBox_AufmassMaxRT->setTitle(QCoreApplication::translate("Dialog_Project", "Aufmass Max vom Rohteil", nullptr));
        checkBox_RT_EinzelAufmass->setText(QCoreApplication::translate("Dialog_Project", "Einzelaufmasse", nullptr));
        label_RT_All->setText(QCoreApplication::translate("Dialog_Project", "Alle Werte", nullptr));
        label_RT_Xplus->setText(QCoreApplication::translate("Dialog_Project", "X+", nullptr));
        label_RT_Xminus->setText(QCoreApplication::translate("Dialog_Project", "X-", nullptr));
        label_RT_Yplus->setText(QCoreApplication::translate("Dialog_Project", "Y+", nullptr));
        label_RT_Yminus->setText(QCoreApplication::translate("Dialog_Project", "Y-", nullptr));
        label_RT_Zplus->setText(QCoreApplication::translate("Dialog_Project", "Z+", nullptr));
        groupBox_AufmassMinFT->setTitle(QCoreApplication::translate("Dialog_Project", "Aufmass Min vom Bauteil", nullptr));
        checkBox_FT_EinzelAufmass->setText(QCoreApplication::translate("Dialog_Project", "Einzelaufmasse", nullptr));
        label_FT_All->setText(QCoreApplication::translate("Dialog_Project", "Alle Werte", nullptr));
        label_FT_Xplus->setText(QCoreApplication::translate("Dialog_Project", "X+", nullptr));
        label_FT_Xminus->setText(QCoreApplication::translate("Dialog_Project", "X-", nullptr));
        label_FT_Yplus->setText(QCoreApplication::translate("Dialog_Project", "Y+", nullptr));
        label_FT_Yminus->setText(QCoreApplication::translate("Dialog_Project", "Y-", nullptr));
        label_FT_Zplus->setText(QCoreApplication::translate("Dialog_Project", "Z+", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Project: public Ui_Dialog_Project {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_PROJECT_H
