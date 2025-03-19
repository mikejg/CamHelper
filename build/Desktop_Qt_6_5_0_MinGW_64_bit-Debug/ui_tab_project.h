/********************************************************************************
** Form generated from reading UI file 'tab_project.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB_PROJECT_H
#define UI_TAB_PROJECT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "Project/pix_scrollarea.h"

QT_BEGIN_NAMESPACE

class Ui_Tab_Project
{
public:
    QHBoxLayout *horizontalLayout_12;
    QFrame *frame;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_11;
    QToolButton *toolButton_RawPartInspection;
    QToolButton *toolButton_Tag;
    QToolButton *toolButton_Programme;
    QToolButton *toolButton_Tools;
    QSpacerItem *horizontalSpacer_7;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_ProjectName;
    QLineEdit *lineEdit_ProjectStatus;
    QHBoxLayout *horizontalLayout_File;
    QLineEdit *lineEdit_CamFile;
    QToolButton *toolButton_ExecFile;
    QToolButton *toolButton_OpenFile;
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
    QLabel *label;
    QLineEdit *lineEdit_NPx;
    QLabel *label_2;
    QLineEdit *lineEdit_NPy;
    QLabel *label_3;
    QLineEdit *lineEdit_NPz;
    QToolButton *toolButton_Paste;
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
    QTextEdit *textEdit_Comment;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_6;
    QToolButton *toolButton_Selector;
    QToolButton *toolButton_Open;
    Pix_ScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_Pictures;
    QSpacerItem *verticalSpacer_Pictures;

    void setupUi(QWidget *Tab_Project)
    {
        if (Tab_Project->objectName().isEmpty())
            Tab_Project->setObjectName("Tab_Project");
        Tab_Project->resize(1094, 945);
        horizontalLayout_12 = new QHBoxLayout(Tab_Project);
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        frame = new QFrame(Tab_Project);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_7 = new QVBoxLayout(frame);
        verticalLayout_7->setObjectName("verticalLayout_7");
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        toolButton_RawPartInspection = new QToolButton(frame);
        toolButton_RawPartInspection->setObjectName("toolButton_RawPartInspection");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/more.png"), QSize(), QIcon::Normal, QIcon::On);
        toolButton_RawPartInspection->setIcon(icon);

        horizontalLayout_11->addWidget(toolButton_RawPartInspection);

        toolButton_Tag = new QToolButton(frame);
        toolButton_Tag->setObjectName("toolButton_Tag");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icons/tag.png"), QSize(), QIcon::Normal, QIcon::On);
        toolButton_Tag->setIcon(icon1);

        horizontalLayout_11->addWidget(toolButton_Tag);

        toolButton_Programme = new QToolButton(frame);
        toolButton_Programme->setObjectName("toolButton_Programme");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icons/programm.png"), QSize(), QIcon::Normal, QIcon::On);
        toolButton_Programme->setIcon(icon2);

        horizontalLayout_11->addWidget(toolButton_Programme);

        toolButton_Tools = new QToolButton(frame);
        toolButton_Tools->setObjectName("toolButton_Tools");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Icons/tools.png"), QSize(), QIcon::Normal, QIcon::On);
        toolButton_Tools->setIcon(icon3);

        horizontalLayout_11->addWidget(toolButton_Tools);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_7);


        verticalLayout_7->addLayout(horizontalLayout_11);

        groupBox = new QGroupBox(frame);
        groupBox->setObjectName("groupBox");
        verticalLayout_6 = new QVBoxLayout(groupBox);
        verticalLayout_6->setObjectName("verticalLayout_6");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lineEdit_ProjectName = new QLineEdit(groupBox);
        lineEdit_ProjectName->setObjectName("lineEdit_ProjectName");
        lineEdit_ProjectName->setEnabled(false);
        lineEdit_ProjectName->setMinimumSize(QSize(0, 30));
        lineEdit_ProjectName->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_2->addWidget(lineEdit_ProjectName);

        lineEdit_ProjectStatus = new QLineEdit(groupBox);
        lineEdit_ProjectStatus->setObjectName("lineEdit_ProjectStatus");
        lineEdit_ProjectStatus->setMinimumSize(QSize(0, 30));
        lineEdit_ProjectStatus->setMaximumSize(QSize(45, 30));

        horizontalLayout_2->addWidget(lineEdit_ProjectStatus);


        verticalLayout_6->addLayout(horizontalLayout_2);

        horizontalLayout_File = new QHBoxLayout();
        horizontalLayout_File->setObjectName("horizontalLayout_File");
        lineEdit_CamFile = new QLineEdit(groupBox);
        lineEdit_CamFile->setObjectName("lineEdit_CamFile");

        horizontalLayout_File->addWidget(lineEdit_CamFile);

        toolButton_ExecFile = new QToolButton(groupBox);
        toolButton_ExecFile->setObjectName("toolButton_ExecFile");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Icons/camfile.png"), QSize(), QIcon::Normal, QIcon::On);
        toolButton_ExecFile->setIcon(icon4);
        toolButton_ExecFile->setIconSize(QSize(24, 24));

        horizontalLayout_File->addWidget(toolButton_ExecFile);

        toolButton_OpenFile = new QToolButton(groupBox);
        toolButton_OpenFile->setObjectName("toolButton_OpenFile");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Icons/File_Open.png"), QSize(), QIcon::Normal, QIcon::On);
        toolButton_OpenFile->setIcon(icon5);
        toolButton_OpenFile->setIconSize(QSize(24, 24));

        horizontalLayout_File->addWidget(toolButton_OpenFile);


        verticalLayout_6->addLayout(horizontalLayout_File);


        verticalLayout_7->addWidget(groupBox);

        groupBox_Rohteil = new QGroupBox(frame);
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


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_7->addWidget(groupBox_Rohteil);

        groupBox_Bauteil = new QGroupBox(frame);
        groupBox_Bauteil->setObjectName("groupBox_Bauteil");
        groupBox_Bauteil->setMinimumSize(QSize(435, 0));
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

        label = new QLabel(groupBox_Bauteil);
        label->setObjectName("label");

        horizontalLayout_6->addWidget(label);

        lineEdit_NPx = new QLineEdit(groupBox_Bauteil);
        lineEdit_NPx->setObjectName("lineEdit_NPx");
        lineEdit_NPx->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_6->addWidget(lineEdit_NPx);

        label_2 = new QLabel(groupBox_Bauteil);
        label_2->setObjectName("label_2");

        horizontalLayout_6->addWidget(label_2);

        lineEdit_NPy = new QLineEdit(groupBox_Bauteil);
        lineEdit_NPy->setObjectName("lineEdit_NPy");
        lineEdit_NPy->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_6->addWidget(lineEdit_NPy);

        label_3 = new QLabel(groupBox_Bauteil);
        label_3->setObjectName("label_3");

        horizontalLayout_6->addWidget(label_3);

        lineEdit_NPz = new QLineEdit(groupBox_Bauteil);
        lineEdit_NPz->setObjectName("lineEdit_NPz");
        lineEdit_NPz->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_6->addWidget(lineEdit_NPz);

        toolButton_Paste = new QToolButton(groupBox_Bauteil);
        toolButton_Paste->setObjectName("toolButton_Paste");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Icons/paste.png"), QSize(), QIcon::Normal, QIcon::On);
        toolButton_Paste->setIcon(icon6);
        toolButton_Paste->setIconSize(QSize(24, 24));

        horizontalLayout_6->addWidget(toolButton_Paste);


        verticalLayout_2->addLayout(horizontalLayout_6);


        verticalLayout_7->addWidget(groupBox_Bauteil);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_ZRohTeil = new QLabel(frame);
        label_ZRohTeil->setObjectName("label_ZRohTeil");

        horizontalLayout_4->addWidget(label_ZRohTeil);

        doubleSpinBox_ZRohTeil = new QDoubleSpinBox(frame);
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


        verticalLayout_7->addLayout(horizontalLayout_4);

        label_Spannung = new QLabel(frame);
        label_Spannung->setObjectName("label_Spannung");
        label_Spannung->setMaximumSize(QSize(16777215, 30));

        verticalLayout_7->addWidget(label_Spannung);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        comboBox_Clamping = new QComboBox(frame);
        comboBox_Clamping->setObjectName("comboBox_Clamping");
        comboBox_Clamping->setEnabled(false);

        horizontalLayout_5->addWidget(comboBox_Clamping);

        lineEdit_NP = new QLineEdit(frame);
        lineEdit_NP->setObjectName("lineEdit_NP");
        lineEdit_NP->setEnabled(false);
        lineEdit_NP->setMaximumSize(QSize(75, 16777215));

        horizontalLayout_5->addWidget(lineEdit_NP);


        verticalLayout_7->addLayout(horizontalLayout_5);

        label_Material = new QLabel(frame);
        label_Material->setObjectName("label_Material");
        label_Material->setMaximumSize(QSize(16777215, 30));

        verticalLayout_7->addWidget(label_Material);

        comboBox_Material = new QComboBox(frame);
        comboBox_Material->setObjectName("comboBox_Material");
        comboBox_Material->setMinimumSize(QSize(435, 0));

        verticalLayout_7->addWidget(comboBox_Material);

        groupBox_AufmassMaxRT = new QGroupBox(frame);
        groupBox_AufmassMaxRT->setObjectName("groupBox_AufmassMaxRT");
        groupBox_AufmassMaxRT->setMinimumSize(QSize(435, 0));
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


        verticalLayout_7->addWidget(groupBox_AufmassMaxRT);

        groupBox_AufmassMinFT = new QGroupBox(frame);
        groupBox_AufmassMinFT->setObjectName("groupBox_AufmassMinFT");
        groupBox_AufmassMinFT->setMinimumSize(QSize(435, 0));
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


        verticalLayout_7->addWidget(groupBox_AufmassMinFT);

        textEdit_Comment = new QTextEdit(frame);
        textEdit_Comment->setObjectName("textEdit_Comment");
        textEdit_Comment->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamilies({QString::fromUtf8("Lucida Console")});
        textEdit_Comment->setFont(font);

        verticalLayout_7->addWidget(textEdit_Comment);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);


        horizontalLayout_12->addWidget(frame);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);

        toolButton_Selector = new QToolButton(Tab_Project);
        toolButton_Selector->setObjectName("toolButton_Selector");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Icons/cut.png"), QSize(), QIcon::Normal, QIcon::On);
        toolButton_Selector->setIcon(icon7);
        toolButton_Selector->setIconSize(QSize(24, 24));

        horizontalLayout_8->addWidget(toolButton_Selector);

        toolButton_Open = new QToolButton(Tab_Project);
        toolButton_Open->setObjectName("toolButton_Open");
        toolButton_Open->setIcon(icon5);
        toolButton_Open->setIconSize(QSize(24, 24));

        horizontalLayout_8->addWidget(toolButton_Open);


        verticalLayout_5->addLayout(horizontalLayout_8);

        scrollArea = new Pix_ScrollArea(Tab_Project);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setMinimumSize(QSize(0, 0));
        scrollArea->setMaximumSize(QSize(16777215, 16777215));
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 531, 884));
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 0));
        verticalLayout_Pictures = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_Pictures->setObjectName("verticalLayout_Pictures");
        verticalSpacer_Pictures = new QSpacerItem(20, 576, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_Pictures->addItem(verticalSpacer_Pictures);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_5->addWidget(scrollArea);


        horizontalLayout_12->addLayout(verticalLayout_5);


        retranslateUi(Tab_Project);

        QMetaObject::connectSlotsByName(Tab_Project);
    } // setupUi

    void retranslateUi(QWidget *Tab_Project)
    {
        Tab_Project->setWindowTitle(QCoreApplication::translate("Tab_Project", "Form", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_RawPartInspection->setToolTip(QCoreApplication::translate("Tab_Project", "Rohteilkontrolle", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_RawPartInspection->setText(QCoreApplication::translate("Tab_Project", "...", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_Tag->setToolTip(QCoreApplication::translate("Tab_Project", "Tags", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_Tag->setText(QCoreApplication::translate("Tab_Project", "...", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_Programme->setToolTip(QCoreApplication::translate("Tab_Project", "Programme", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_Programme->setText(QCoreApplication::translate("Tab_Project", "...", nullptr));
        toolButton_Tools->setText(QCoreApplication::translate("Tab_Project", "...", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Tab_Project", "Projektname", nullptr));
        toolButton_ExecFile->setText(QCoreApplication::translate("Tab_Project", "...", nullptr));
        toolButton_OpenFile->setText(QCoreApplication::translate("Tab_Project", "...", nullptr));
        groupBox_Rohteil->setTitle(QCoreApplication::translate("Tab_Project", "Rohteil", nullptr));
        label_X->setText(QCoreApplication::translate("Tab_Project", "X", nullptr));
        lineEdit_RTx->setText(QString());
        label_Y->setText(QCoreApplication::translate("Tab_Project", "Y", nullptr));
        lineEdit_RTy->setText(QString());
        label_Z->setText(QCoreApplication::translate("Tab_Project", "Z", nullptr));
        lineEdit_RTz->setText(QString());
        label_RohteilKontrolle->setText(QCoreApplication::translate("Tab_Project", "Rohteilkontrolle", nullptr));
        groupBox_Bauteil->setTitle(QCoreApplication::translate("Tab_Project", "Bauteil", nullptr));
        label_X_2->setText(QCoreApplication::translate("Tab_Project", "X", nullptr));
        lineEdit_BTx->setText(QString());
        label_Y_2->setText(QCoreApplication::translate("Tab_Project", "Y", nullptr));
        lineEdit_BTy->setText(QString());
        label_Z_2->setText(QCoreApplication::translate("Tab_Project", "Z", nullptr));
        lineEdit_BTz->setText(QString());
        label->setText(QCoreApplication::translate("Tab_Project", "NP:  X", nullptr));
        label_2->setText(QCoreApplication::translate("Tab_Project", "Y", nullptr));
        label_3->setText(QCoreApplication::translate("Tab_Project", "Z", nullptr));
        toolButton_Paste->setText(QCoreApplication::translate("Tab_Project", "...", nullptr));
        label_ZRohTeil->setText(QCoreApplication::translate("Tab_Project", "Z Rohteil", nullptr));
        label_Spannung->setText(QCoreApplication::translate("Tab_Project", "Spannung", nullptr));
        label_Material->setText(QCoreApplication::translate("Tab_Project", "Material", nullptr));
        groupBox_AufmassMaxRT->setTitle(QCoreApplication::translate("Tab_Project", "Aufmass Max vom Rohteil", nullptr));
        checkBox_RT_EinzelAufmass->setText(QCoreApplication::translate("Tab_Project", "Einzelaufmasse", nullptr));
        label_RT_All->setText(QCoreApplication::translate("Tab_Project", "Alle Werte", nullptr));
        label_RT_Xplus->setText(QCoreApplication::translate("Tab_Project", "X+", nullptr));
        label_RT_Xminus->setText(QCoreApplication::translate("Tab_Project", "X-", nullptr));
        label_RT_Yplus->setText(QCoreApplication::translate("Tab_Project", "Y+", nullptr));
        label_RT_Yminus->setText(QCoreApplication::translate("Tab_Project", "Y-", nullptr));
        label_RT_Zplus->setText(QCoreApplication::translate("Tab_Project", "Z+", nullptr));
        groupBox_AufmassMinFT->setTitle(QCoreApplication::translate("Tab_Project", "Aufmass Min vom Bauteil", nullptr));
        checkBox_FT_EinzelAufmass->setText(QCoreApplication::translate("Tab_Project", "Einzelaufmasse", nullptr));
        label_FT_All->setText(QCoreApplication::translate("Tab_Project", "Alle Werte", nullptr));
        label_FT_Xplus->setText(QCoreApplication::translate("Tab_Project", "X+", nullptr));
        label_FT_Xminus->setText(QCoreApplication::translate("Tab_Project", "X-", nullptr));
        label_FT_Yplus->setText(QCoreApplication::translate("Tab_Project", "Y+", nullptr));
        label_FT_Yminus->setText(QCoreApplication::translate("Tab_Project", "Y-", nullptr));
        label_FT_Zplus->setText(QCoreApplication::translate("Tab_Project", "Z+", nullptr));
        toolButton_Selector->setText(QCoreApplication::translate("Tab_Project", "...", nullptr));
        toolButton_Open->setText(QCoreApplication::translate("Tab_Project", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tab_Project: public Ui_Tab_Project {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB_PROJECT_H
