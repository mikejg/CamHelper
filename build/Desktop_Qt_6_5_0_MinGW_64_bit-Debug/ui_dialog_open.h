/********************************************************************************
** Form generated from reading UI file 'dialog_open.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_OPEN_H
#define UI_DIALOG_OPEN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include "Project/mlabel.h"

QT_BEGIN_NAMESPACE

class Ui_Dialog_Open
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_Project;
    QToolButton *toolButton_Tags;
    QHBoxLayout *horizontalLayout;
    QListView *listView_Project;
    MLabel *label;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog_Open)
    {
        if (Dialog_Open->objectName().isEmpty())
            Dialog_Open->setObjectName("Dialog_Open");
        Dialog_Open->resize(600, 400);
        Dialog_Open->setMinimumSize(QSize(600, 400));
        Dialog_Open->setMaximumSize(QSize(16777215, 16777215));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/File_Open.png"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog_Open->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(Dialog_Open);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lineEdit_Project = new QLineEdit(Dialog_Open);
        lineEdit_Project->setObjectName("lineEdit_Project");

        horizontalLayout_2->addWidget(lineEdit_Project);

        toolButton_Tags = new QToolButton(Dialog_Open);
        toolButton_Tags->setObjectName("toolButton_Tags");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icons/tag.png"), QSize(), QIcon::Normal, QIcon::On);
        toolButton_Tags->setIcon(icon1);

        horizontalLayout_2->addWidget(toolButton_Tags);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        listView_Project = new QListView(Dialog_Open);
        listView_Project->setObjectName("listView_Project");
        listView_Project->setMaximumSize(QSize(290, 16777215));

        horizontalLayout->addWidget(listView_Project);

        label = new MLabel(Dialog_Open);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(Dialog_Open);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Dialog_Open);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Dialog_Open, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Dialog_Open, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Dialog_Open);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Open)
    {
        Dialog_Open->setWindowTitle(QCoreApplication::translate("Dialog_Open", "Datei \303\226ffnen", nullptr));
        toolButton_Tags->setText(QCoreApplication::translate("Dialog_Open", "...", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog_Open: public Ui_Dialog_Open {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_OPEN_H
