#include "dialog_repetition.h"
#include "ui_dialog_repetition.h"

Dialog_Repetition::Dialog_Repetition(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Repetition)
{
    ui->setupUi(this);
    ui->radioButton_Paket->setChecked(true);

    radioButton_Paket = ui->radioButton_Paket;
    radioButton_Repetition = ui->radioButton_Import;
}

Dialog_Repetition::~Dialog_Repetition()
{
    delete ui;
}

void Dialog_Repetition::set_LastProduction(QString str)
{
    ui->label_LastProduction->setText("Letzte Fertigung: " + str);
}
