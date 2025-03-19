/********************************************************************************
** Form generated from reading UI file 'dialog_tag.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_TAG_H
#define UI_DIALOG_TAG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Tag
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget_Tags;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QToolButton *toolButton_Add;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog_Tag)
    {
        if (Dialog_Tag->objectName().isEmpty())
            Dialog_Tag->setObjectName("Dialog_Tag");
        Dialog_Tag->resize(312, 342);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/tag.png"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog_Tag->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(Dialog_Tag);
        verticalLayout->setObjectName("verticalLayout");
        listWidget_Tags = new QListWidget(Dialog_Tag);
        listWidget_Tags->setObjectName("listWidget_Tags");

        verticalLayout->addWidget(listWidget_Tags);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lineEdit = new QLineEdit(Dialog_Tag);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);

        toolButton_Add = new QToolButton(Dialog_Tag);
        toolButton_Add->setObjectName("toolButton_Add");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icons/TouchProbe/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_Add->setIcon(icon1);

        horizontalLayout->addWidget(toolButton_Add);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(Dialog_Tag);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Dialog_Tag);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Dialog_Tag, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Dialog_Tag, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Dialog_Tag);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Tag)
    {
        Dialog_Tag->setWindowTitle(QCoreApplication::translate("Dialog_Tag", "Tags", nullptr));
        toolButton_Add->setText(QCoreApplication::translate("Dialog_Tag", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Tag: public Ui_Dialog_Tag {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_TAG_H
