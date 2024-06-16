#include "dialog_start.h"
#include "ui_dialog_start.h"

Dialog_Start::Dialog_Start(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Start)
{
    ui->setupUi(this);
    connect(ui->toolButton_New, SIGNAL(pressed()), this, SIGNAL(sig_NewClicked()));
    connect(ui->toolButton_New, SIGNAL(pressed()), this, SLOT(hide()));

    connect(ui->toolButton_Check, SIGNAL(pressed()), this, SIGNAL(sig_CheckFiles()));
    connect(ui->toolButton_Check, SIGNAL(pressed()), this, SLOT(hide()));

    connect(ui->toolButton_Open, SIGNAL(pressed()), this, SIGNAL(sig_OpenProject()));
    connect(ui->toolButton_Open, SIGNAL(pressed()), this, SLOT(hide()));
}

Dialog_Start::~Dialog_Start()
{
    delete ui;
}
