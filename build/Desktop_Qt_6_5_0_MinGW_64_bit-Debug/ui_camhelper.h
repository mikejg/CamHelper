/********************************************************************************
** Form generated from reading UI file 'camhelper.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMHELPER_H
#define UI_CAMHELPER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "Magazin/magazin.h"
#include "Project/tab_project.h"
#include "TouchProbe/touchprobe.h"
#include "logging.h"

QT_BEGIN_NAMESPACE

class Ui_CamHelper
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QTabWidget *tabWidget;
    Tab_Project *tab_Project;
    QVBoxLayout *verticalLayout_3;
    QWidget *tab_Main;
    QHBoxLayout *horizontalLayout_8;
    QTextEdit *textEdit;
    QWidget *tab_Rustplan;
    QVBoxLayout *verticalLayout_5;
    QTableView *tableView_Rustplan;
    Magazin *tab_Magazin;
    QWidget *tab_Log;
    QVBoxLayout *verticalLayout;
    Logging *textEdit_Log;
    TouchProbe *tab_TouchProbe;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *CamHelper)
    {
        if (CamHelper->objectName().isEmpty())
            CamHelper->setObjectName("CamHelper");
        CamHelper->resize(1200, 900);
        CamHelper->setMinimumSize(QSize(1200, 900));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/camhelper.png"), QSize(), QIcon::Normal, QIcon::Off);
        CamHelper->setWindowIcon(icon);
        centralwidget = new QWidget(CamHelper);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tab_Project = new Tab_Project();
        tab_Project->setObjectName("tab_Project");
        verticalLayout_3 = new QVBoxLayout(tab_Project);
        verticalLayout_3->setObjectName("verticalLayout_3");
        tabWidget->addTab(tab_Project, QString());
        tab_Main = new QWidget();
        tab_Main->setObjectName("tab_Main");
        horizontalLayout_8 = new QHBoxLayout(tab_Main);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        textEdit = new QTextEdit(tab_Main);
        textEdit->setObjectName("textEdit");
        QFont font;
        font.setFamilies({QString::fromUtf8("Lucida Console")});
        textEdit->setFont(font);

        horizontalLayout_8->addWidget(textEdit);

        tabWidget->addTab(tab_Main, QString());
        tab_Rustplan = new QWidget();
        tab_Rustplan->setObjectName("tab_Rustplan");
        verticalLayout_5 = new QVBoxLayout(tab_Rustplan);
        verticalLayout_5->setObjectName("verticalLayout_5");
        tableView_Rustplan = new QTableView(tab_Rustplan);
        tableView_Rustplan->setObjectName("tableView_Rustplan");
        tableView_Rustplan->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_5->addWidget(tableView_Rustplan);

        tabWidget->addTab(tab_Rustplan, QString());
        tab_Magazin = new Magazin();
        tab_Magazin->setObjectName("tab_Magazin");
        tabWidget->addTab(tab_Magazin, QString());
        tab_Log = new QWidget();
        tab_Log->setObjectName("tab_Log");
        verticalLayout = new QVBoxLayout(tab_Log);
        verticalLayout->setObjectName("verticalLayout");
        textEdit_Log = new Logging(tab_Log);
        textEdit_Log->setObjectName("textEdit_Log");
        textEdit_Log->setFont(font);

        verticalLayout->addWidget(textEdit_Log);

        tabWidget->addTab(tab_Log, QString());
        tab_TouchProbe = new TouchProbe();
        tab_TouchProbe->setObjectName("tab_TouchProbe");
        tabWidget->addTab(tab_TouchProbe, QString());

        verticalLayout_4->addWidget(tabWidget);

        CamHelper->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CamHelper);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1200, 21));
        CamHelper->setMenuBar(menubar);
        statusbar = new QStatusBar(CamHelper);
        statusbar->setObjectName("statusbar");
        CamHelper->setStatusBar(statusbar);
        toolBar = new QToolBar(CamHelper);
        toolBar->setObjectName("toolBar");
        CamHelper->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addSeparator();

        retranslateUi(CamHelper);

        tabWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(CamHelper);
    } // setupUi

    void retranslateUi(QMainWindow *CamHelper)
    {
        CamHelper->setWindowTitle(QCoreApplication::translate("CamHelper", "CamHelper", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Project), QCoreApplication::translate("CamHelper", "Projekt", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Main), QCoreApplication::translate("CamHelper", "Hauptprogramm", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Rustplan), QCoreApplication::translate("CamHelper", "R\303\274stplan", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Magazin), QCoreApplication::translate("CamHelper", "Magazin", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Log), QCoreApplication::translate("CamHelper", "Log", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_TouchProbe), QCoreApplication::translate("CamHelper", "Antasten", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("CamHelper", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CamHelper: public Ui_CamHelper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMHELPER_H
