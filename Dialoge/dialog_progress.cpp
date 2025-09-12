#include "dialog_progress.h"
#include "ui_dialog_progress.h"

Dialog_Progress::Dialog_Progress(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Progress)
{
     ui->setupUi(this);
}

Dialog_Progress::~Dialog_Progress()
{
    delete ui;
}

void Dialog_Progress::init_Dialog(QList<Programm> list_Programm)
{
    ui->progressBar->setMaximum(list_Programm.size());
}

void Dialog_Progress::set_Maximum(int i)
{
    ui->progressBar->setMaximum(i);
}

void Dialog_Progress::set_Value(QString string, int val)
{
    ui->label->setText(string);
    ui->progressBar->setValue(val);
    this->show();
}



