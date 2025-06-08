#include "tab_project.h"
#include "ui_tab_project.h"

Tab_Project::Tab_Project(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Tab_Project)
{
    ui->setupUi(this);
}

Tab_Project::~Tab_Project()
{
    delete ui;
}
