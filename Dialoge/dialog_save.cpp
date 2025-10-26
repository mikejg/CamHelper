#include "dialog_save.h"
#include "ui_dialog_save.h"

Dialog_Save::Dialog_Save(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_Save)
{
    ui->setupUi(this);

    connect(ui->buttonBox, SIGNAL(clicked(QAbstractButton*)), this, SLOT(slot_Clicked(QAbstractButton*)));
}

Dialog_Save::~Dialog_Save()
{
    delete ui;
}

void Dialog_Save::slot_Clicked(QAbstractButton* button)
{
    if(ui->buttonBox->buttonRole(button) == QDialogButtonBox::DestructiveRole)
    {
        emit discard();
        hide();
    }
}
