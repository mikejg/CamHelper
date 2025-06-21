#include "dialog_init.h"
#include "ui_dialog_init.h"

Dialog_Init::Dialog_Init(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Dialog_Init)
{
    ui->setupUi(this);

    connect(ui->widget_1, SIGNAL(sig_Clicked(QString)), this, SIGNAL(sig_Clicked(QString)));
    connect(ui->widget_2, SIGNAL(sig_Clicked(QString)), this, SIGNAL(sig_Clicked(QString)));
    connect(ui->widget_3, SIGNAL(sig_Clicked(QString)), this, SIGNAL(sig_Clicked(QString)));
    connect(ui->widget_4, SIGNAL(sig_Clicked(QString)), this, SIGNAL(sig_Clicked(QString)));
}

Dialog_Init::~Dialog_Init()
{
    delete ui;
}

void Dialog_Init::set_Pictures(QList<ProjectData> list_ProjectData)
{
    //Übergebe an jedes Widget eine zum Anzeigen ein ProjectData
    if(list_ProjectData.size() > 0)
        ui->widget_1->set_ProjectData(list_ProjectData.at(0));

    if(list_ProjectData.size() > 1)
        ui->widget_2->set_ProjectData(list_ProjectData.at(1));

    if(list_ProjectData.size() > 2)
        ui->widget_3->set_ProjectData(list_ProjectData.at(2));

    if(list_ProjectData.size() > 3)
        ui->widget_4->set_ProjectData(list_ProjectData.at(3));

}
