#include "dialog_programm.h"
#include "ui_dialog_programm.h"

Dialog_Programm::Dialog_Programm(QWidget *parent, Project* p) :
    QDialog(parent),
    ui(new Ui::Dialog_Programm)
{
    project = p;

    ui->setupUi(this);
    ui->tableView_Programme->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    //erzeuge ein neues ProgrammModel
    programmModel = new ProgrammModel();
    //Überge dem ProgrammModel die Item_Programm Liste
    programmModel->populateData(project->get_ListProgramm());
    //setze das ProgrammModel in tableView_Programme
    ui->tableView_Programme->setModel(programmModel);
    //Verbinde sig / slot NewProgrammList(QList<Item_ProgrammProject>)
    connect(programmModel, SIGNAL(sig_NewProgrammList(QList<Item_Programm>)),
            project, SLOT(slot_NewProgrammList(QList<Item_Programm>)));
}

Dialog_Programm::~Dialog_Programm()
{
    delete ui;
}
