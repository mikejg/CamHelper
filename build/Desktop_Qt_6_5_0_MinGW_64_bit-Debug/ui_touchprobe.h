/********************************************************************************
** Form generated from reading UI file 'touchprobe.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOUCHPROBE_H
#define UI_TOUCHPROBE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TouchProbe/tp_scrollcontent.h"

QT_BEGIN_NAMESPACE

class Ui_TouchProbe
{
public:
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEdit;
    QLabel *label_Pix;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_ToolBar;
    QToolButton *toolButton_Edit;
    QToolButton *toolButton_Pix;
    QToolButton *toolButton_Export;
    QSpacerItem *horizontalSpacer_4;
    QScrollArea *scrollArea;
    TP_ScrollContent *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_scrollArea;
    QSpacerItem *verticalSpacer_ScrollContent;

    void setupUi(QWidget *TouchProbe)
    {
        if (TouchProbe->objectName().isEmpty())
            TouchProbe->setObjectName("TouchProbe");
        TouchProbe->resize(1166, 649);
        horizontalLayout = new QHBoxLayout(TouchProbe);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, -1, 9, -1);
        textEdit = new QTextEdit(TouchProbe);
        textEdit->setObjectName("textEdit");
        QFont font;
        font.setFamilies({QString::fromUtf8("Lucida Console")});
        textEdit->setFont(font);

        horizontalLayout->addWidget(textEdit);

        label_Pix = new QLabel(TouchProbe);
        label_Pix->setObjectName("label_Pix");
        label_Pix->setMinimumSize(QSize(400, 400));
        label_Pix->setScaledContents(false);
        label_Pix->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_Pix);

        widget = new QWidget(TouchProbe);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(320, 0));
        widget->setMaximumSize(QSize(300, 16777215));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_ToolBar = new QHBoxLayout();
        horizontalLayout_ToolBar->setObjectName("horizontalLayout_ToolBar");
        toolButton_Edit = new QToolButton(widget);
        toolButton_Edit->setObjectName("toolButton_Edit");
        toolButton_Edit->setMinimumSize(QSize(32, 32));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/TouchProbe/create.png"), QSize(), QIcon::Normal, QIcon::On);
        toolButton_Edit->setIcon(icon);
        toolButton_Edit->setIconSize(QSize(24, 24));

        horizontalLayout_ToolBar->addWidget(toolButton_Edit);

        toolButton_Pix = new QToolButton(widget);
        toolButton_Pix->setObjectName("toolButton_Pix");
        toolButton_Pix->setMinimumSize(QSize(32, 32));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icons/TouchProbe/picture.png"), QSize(), QIcon::Normal, QIcon::On);
        toolButton_Pix->setIcon(icon1);
        toolButton_Pix->setIconSize(QSize(24, 24));

        horizontalLayout_ToolBar->addWidget(toolButton_Pix);

        toolButton_Export = new QToolButton(widget);
        toolButton_Export->setObjectName("toolButton_Export");
        toolButton_Export->setMinimumSize(QSize(32, 32));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icons/export.png"), QSize(), QIcon::Normal, QIcon::On);
        toolButton_Export->setIcon(icon2);
        toolButton_Export->setIconSize(QSize(24, 24));

        horizontalLayout_ToolBar->addWidget(toolButton_Export);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_ToolBar->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_ToolBar);

        scrollArea = new QScrollArea(widget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setMinimumSize(QSize(300, 0));
        scrollArea->setMaximumSize(QSize(300, 16777215));
        scrollArea->setAcceptDrops(true);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new TP_ScrollContent();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 298, 571));
        verticalLayout_scrollArea = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_scrollArea->setObjectName("verticalLayout_scrollArea");
        verticalLayout_scrollArea->setContentsMargins(9, -1, 3, -1);
        verticalSpacer_ScrollContent = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_scrollArea->addItem(verticalSpacer_ScrollContent);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        horizontalLayout->addWidget(widget);


        retranslateUi(TouchProbe);

        QMetaObject::connectSlotsByName(TouchProbe);
    } // setupUi

    void retranslateUi(QWidget *TouchProbe)
    {
        TouchProbe->setWindowTitle(QCoreApplication::translate("TouchProbe", "Form", nullptr));
        label_Pix->setText(QString());
        toolButton_Edit->setText(QString());
        toolButton_Pix->setText(QString());
        toolButton_Export->setText(QCoreApplication::translate("TouchProbe", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TouchProbe: public Ui_TouchProbe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOUCHPROBE_H
