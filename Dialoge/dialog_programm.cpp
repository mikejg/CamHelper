#include "dialog_programm.h"
#include "ui_dialog_programm.h"
#include <QScrollBar>

Dialog_Programm::Dialog_Programm(QWidget *parent, ProjectData* pd) :
    QDialog(parent),
    ui(new Ui::Dialog_Programm)
{
    projectData = pd;

    ui->setupUi(this);
    ui->tableView_Programme->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableView_Programme->verticalHeader()->hide();

    //Hintergrund Bild
    QPixmap bkgnd(":/Icons/Main/Wallpaper5_klein.png"); //Add commentMore actions
    bkgnd = bkgnd.scaled(this->size());
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    programmModel = new ProgrammModel();                                        //erzeuge ein neues ProgrammModel
    programmModel->populateData(projectData->list_Programm);                    //Überge dem ProgrammModel die Programmliste
    ui->tableView_Programme->setModel(programmModel);                           //setze das ProgrammModel in tableView_Programme

    connect(programmModel, SIGNAL(sig_NewProgrammList(QList<Programm>)), this, SLOT(slot_NewProgrammList(QList<Programm>)));
}

Dialog_Programm::~Dialog_Programm()
{
    delete ui;
}

void Dialog_Programm::slot_NewProgrammList(QList<Programm> programmList)
{
    projectData->list_Programm = programmList;
}
