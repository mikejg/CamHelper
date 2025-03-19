/********************************************************************************
** Form generated from reading UI file 'tp_item.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TP_ITEM_H
#define UI_TP_ITEM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TouchProbe/tp_ausrichten.h"
#include "TouchProbe/tp_bohrung.h"
#include "TouchProbe/tp_ebenheit.h"
#include "TouchProbe/tp_kante.h"
#include "TouchProbe/tp_nut.h"
#include "TouchProbe/tp_steg.h"

QT_BEGIN_NAMESPACE

class Ui_TP_Item
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_PreView;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout1;
    QLabel *label_PreView_Icon;
    QLabel *label_PreView_Text;
    QHBoxLayout *horizontalLayout2;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton_Trash;
    QToolButton *toolButton_Add;
    QToolButton *toolButton_Fold;
    QWidget *widget_FullView;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea_Cyclus;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_Cyclus;
    QToolButton *toolButton_Ausrichten;
    QToolButton *toolButton_Kante;
    QToolButton *toolButton_Steg;
    QToolButton *toolButton_Ebenheit;
    QToolButton *toolButton_Bohrung;
    QToolButton *toolButton_Nut;
    TP_Ausrichten *widget_TP_Ausrichten;
    TP_Kante *widget_TP_Kante;
    TP_Ebenheit *widget_TP_Ebenheit;
    TP_Steg *widget_TP_Steg;
    TP_Bohrung *widget_TP_Bohrung;
    TP_Nut *widget_TP_Nut;

    void setupUi(QFrame *TP_Item)
    {
        if (TP_Item->objectName().isEmpty())
            TP_Item->setObjectName("TP_Item");
        TP_Item->resize(270, 343);
        TP_Item->setMaximumSize(QSize(270, 16777215));
        TP_Item->setAcceptDrops(false);
        TP_Item->setFrameShape(QFrame::Box);
        verticalLayout_3 = new QVBoxLayout(TP_Item);
        verticalLayout_3->setObjectName("verticalLayout_3");
        widget_PreView = new QWidget(TP_Item);
        widget_PreView->setObjectName("widget_PreView");
        verticalLayout = new QVBoxLayout(widget_PreView);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout1 = new QHBoxLayout();
        horizontalLayout1->setObjectName("horizontalLayout1");
        label_PreView_Icon = new QLabel(widget_PreView);
        label_PreView_Icon->setObjectName("label_PreView_Icon");
        label_PreView_Icon->setMaximumSize(QSize(32, 32));
        label_PreView_Icon->setPixmap(QPixmap(QString::fromUtf8(":/Icons/TouchProbe/empty-set.png")));
        label_PreView_Icon->setScaledContents(true);

        horizontalLayout1->addWidget(label_PreView_Icon);

        label_PreView_Text = new QLabel(widget_PreView);
        label_PreView_Text->setObjectName("label_PreView_Text");

        horizontalLayout1->addWidget(label_PreView_Text);


        verticalLayout->addLayout(horizontalLayout1);

        horizontalLayout2 = new QHBoxLayout();
        horizontalLayout2->setObjectName("horizontalLayout2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout2->addItem(horizontalSpacer);

        toolButton_Trash = new QToolButton(widget_PreView);
        toolButton_Trash->setObjectName("toolButton_Trash");
        toolButton_Trash->setMaximumSize(QSize(32, 32));
        QPalette palette;
        QBrush brush(QColor(12, 12, 12, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        toolButton_Trash->setPalette(palette);
        toolButton_Trash->setAutoFillBackground(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/TouchProbe/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_Trash->setIcon(icon);
        toolButton_Trash->setIconSize(QSize(32, 32));
        toolButton_Trash->setCheckable(false);

        horizontalLayout2->addWidget(toolButton_Trash);

        toolButton_Add = new QToolButton(widget_PreView);
        toolButton_Add->setObjectName("toolButton_Add");
        toolButton_Add->setMaximumSize(QSize(32, 32));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        toolButton_Add->setPalette(palette1);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icons/TouchProbe/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_Add->setIcon(icon1);
        toolButton_Add->setIconSize(QSize(32, 32));

        horizontalLayout2->addWidget(toolButton_Add);

        toolButton_Fold = new QToolButton(widget_PreView);
        toolButton_Fold->setObjectName("toolButton_Fold");
        toolButton_Fold->setMaximumSize(QSize(32, 32));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Button, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush);
        toolButton_Fold->setPalette(palette2);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icons/TouchProbe/down-arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_Fold->setIcon(icon2);
        toolButton_Fold->setIconSize(QSize(32, 32));

        horizontalLayout2->addWidget(toolButton_Fold);


        verticalLayout->addLayout(horizontalLayout2);


        verticalLayout_3->addWidget(widget_PreView);

        widget_FullView = new QWidget(TP_Item);
        widget_FullView->setObjectName("widget_FullView");
        verticalLayout_2 = new QVBoxLayout(widget_FullView);
        verticalLayout_2->setObjectName("verticalLayout_2");
        scrollArea_Cyclus = new QScrollArea(widget_FullView);
        scrollArea_Cyclus->setObjectName("scrollArea_Cyclus");
        scrollArea_Cyclus->setMinimumSize(QSize(0, 85));
        scrollArea_Cyclus->setMaximumSize(QSize(16777215, 85));
        scrollArea_Cyclus->setSizeIncrement(QSize(0, 0));
        scrollArea_Cyclus->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(-106, 0, 336, 69));
        scrollAreaWidgetContents->setMaximumSize(QSize(16777215, 85));
        horizontalLayout_Cyclus = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_Cyclus->setObjectName("horizontalLayout_Cyclus");
        toolButton_Ausrichten = new QToolButton(scrollAreaWidgetContents);
        toolButton_Ausrichten->setObjectName("toolButton_Ausrichten");
        toolButton_Ausrichten->setMinimumSize(QSize(48, 48));
        toolButton_Ausrichten->setMaximumSize(QSize(48, 48));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Icons/TouchProbe/Ausrichten.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon3.addFile(QString::fromUtf8(":/Icons/Ausrichten.png"), QSize(), QIcon::Normal, QIcon::On);
        toolButton_Ausrichten->setIcon(icon3);
        toolButton_Ausrichten->setIconSize(QSize(48, 48));

        horizontalLayout_Cyclus->addWidget(toolButton_Ausrichten);

        toolButton_Kante = new QToolButton(scrollAreaWidgetContents);
        toolButton_Kante->setObjectName("toolButton_Kante");
        toolButton_Kante->setMinimumSize(QSize(48, 48));
        toolButton_Kante->setMaximumSize(QSize(48, 48));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Icons/TouchProbe/Kante.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon4.addFile(QString::fromUtf8(":/Icons/Kante.png"), QSize(), QIcon::Normal, QIcon::On);
        toolButton_Kante->setIcon(icon4);
        toolButton_Kante->setIconSize(QSize(48, 48));

        horizontalLayout_Cyclus->addWidget(toolButton_Kante);

        toolButton_Steg = new QToolButton(scrollAreaWidgetContents);
        toolButton_Steg->setObjectName("toolButton_Steg");
        toolButton_Steg->setMinimumSize(QSize(48, 48));
        toolButton_Steg->setMaximumSize(QSize(48, 48));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Icons/TouchProbe/Steg.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon5.addFile(QString::fromUtf8(":/Icons/Steg.png"), QSize(), QIcon::Normal, QIcon::On);
        toolButton_Steg->setIcon(icon5);
        toolButton_Steg->setIconSize(QSize(48, 48));

        horizontalLayout_Cyclus->addWidget(toolButton_Steg);

        toolButton_Ebenheit = new QToolButton(scrollAreaWidgetContents);
        toolButton_Ebenheit->setObjectName("toolButton_Ebenheit");
        toolButton_Ebenheit->setMinimumSize(QSize(48, 48));
        toolButton_Ebenheit->setSizeIncrement(QSize(48, 48));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Icons/TouchProbe/Ebene.png"), QSize(), QIcon::Normal, QIcon::On);
        toolButton_Ebenheit->setIcon(icon6);
        toolButton_Ebenheit->setIconSize(QSize(48, 48));

        horizontalLayout_Cyclus->addWidget(toolButton_Ebenheit);

        toolButton_Bohrung = new QToolButton(scrollAreaWidgetContents);
        toolButton_Bohrung->setObjectName("toolButton_Bohrung");
        toolButton_Bohrung->setMinimumSize(QSize(48, 48));
        toolButton_Bohrung->setMaximumSize(QSize(48, 48));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Icons/TouchProbe/Bohrung.png"), QSize(), QIcon::Normal, QIcon::On);
        toolButton_Bohrung->setIcon(icon7);
        toolButton_Bohrung->setIconSize(QSize(48, 48));

        horizontalLayout_Cyclus->addWidget(toolButton_Bohrung);

        toolButton_Nut = new QToolButton(scrollAreaWidgetContents);
        toolButton_Nut->setObjectName("toolButton_Nut");
        toolButton_Nut->setMinimumSize(QSize(48, 48));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Icons/TouchProbe/Nut.png"), QSize(), QIcon::Normal, QIcon::On);
        toolButton_Nut->setIcon(icon8);
        toolButton_Nut->setIconSize(QSize(48, 48));

        horizontalLayout_Cyclus->addWidget(toolButton_Nut);

        scrollArea_Cyclus->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea_Cyclus);

        widget_TP_Ausrichten = new TP_Ausrichten(widget_FullView);
        widget_TP_Ausrichten->setObjectName("widget_TP_Ausrichten");

        verticalLayout_2->addWidget(widget_TP_Ausrichten);

        widget_TP_Kante = new TP_Kante(widget_FullView);
        widget_TP_Kante->setObjectName("widget_TP_Kante");

        verticalLayout_2->addWidget(widget_TP_Kante);

        widget_TP_Ebenheit = new TP_Ebenheit(widget_FullView);
        widget_TP_Ebenheit->setObjectName("widget_TP_Ebenheit");

        verticalLayout_2->addWidget(widget_TP_Ebenheit);

        widget_TP_Steg = new TP_Steg(widget_FullView);
        widget_TP_Steg->setObjectName("widget_TP_Steg");

        verticalLayout_2->addWidget(widget_TP_Steg);

        widget_TP_Bohrung = new TP_Bohrung(widget_FullView);
        widget_TP_Bohrung->setObjectName("widget_TP_Bohrung");

        verticalLayout_2->addWidget(widget_TP_Bohrung);

        widget_TP_Nut = new TP_Nut(widget_FullView);
        widget_TP_Nut->setObjectName("widget_TP_Nut");

        verticalLayout_2->addWidget(widget_TP_Nut);


        verticalLayout_3->addWidget(widget_FullView);


        retranslateUi(TP_Item);

        QMetaObject::connectSlotsByName(TP_Item);
    } // setupUi

    void retranslateUi(QFrame *TP_Item)
    {
        TP_Item->setWindowTitle(QCoreApplication::translate("TP_Item", "Frame", nullptr));
        label_PreView_Icon->setText(QString());
        label_PreView_Text->setText(QCoreApplication::translate("TP_Item", "Kein Antast-Cyclus ausgew\303\244hlt", nullptr));
        toolButton_Trash->setText(QCoreApplication::translate("TP_Item", "...", nullptr));
        toolButton_Add->setText(QCoreApplication::translate("TP_Item", "...", nullptr));
        toolButton_Fold->setText(QCoreApplication::translate("TP_Item", "...", nullptr));
        toolButton_Ausrichten->setText(QCoreApplication::translate("TP_Item", "...", nullptr));
        toolButton_Kante->setText(QCoreApplication::translate("TP_Item", "...", nullptr));
        toolButton_Steg->setText(QCoreApplication::translate("TP_Item", "...", nullptr));
        toolButton_Ebenheit->setText(QCoreApplication::translate("TP_Item", "...", nullptr));
        toolButton_Bohrung->setText(QCoreApplication::translate("TP_Item", "...", nullptr));
        toolButton_Nut->setText(QCoreApplication::translate("TP_Item", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TP_Item: public Ui_TP_Item {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TP_ITEM_H
