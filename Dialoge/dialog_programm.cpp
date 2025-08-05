#include "dialog_programm.h"
#include "ui_dialog_programm.h"

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
    programmModel->populateData(projectData->list_Programm);                   //Überge dem ProgrammModel die Item_Programm Liste
    ui->tableView_Programme->setModel(programmModel);                           //setze das ProgrammModel in tableView_Programme
    //Verbinde sig / slot NewProgrammList(QList<Item_ProgrammProject>)
    //connect(programmModel, SIGNAL(sig_NewProgrammList(QList<Item_Programm>)),
    //        this, SIGNAL(sig_NewProgrammList(QList<Item_Programm>)));
}

Dialog_Programm::~Dialog_Programm()
{
    delete ui;
}
