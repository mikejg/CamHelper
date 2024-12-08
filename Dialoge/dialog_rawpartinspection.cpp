#include "dialog_rawpartinspection.h"
#include "ui_dialog_rawpartinspection.h"

Dialog_RawPartInspection::Dialog_RawPartInspection(QWidget* parent,
                                                   Project* p) :
    QDialog(parent),
    ui(new Ui::Dialog_RawPartInspection)
{
    ui->setupUi(this);
    project = p;

    connect(ui->toolButton_RawPartInspection_00, SIGNAL(released()), this, SLOT(slot_Selected()));
    connect(ui->toolButton_RawPartInspection_01, SIGNAL(released()), this, SLOT(slot_Selected()));
    connect(ui->toolButton_RawPartInspection_02, SIGNAL(released()), this, SLOT(slot_Selected()));
    connect(ui->toolButton_RawPartInspection_03, SIGNAL(released()), this, SLOT(slot_Selected()));
}

Dialog_RawPartInspection::~Dialog_RawPartInspection()
{
    delete ui;
}

void Dialog_RawPartInspection::slot_Selected()
{
    // Wenn der Sender tool_Butten_RawPartInspection_00 ist
    // setze im Project die Rohteilkontrolle00
    if(sender() == ui->toolButton_RawPartInspection_00)
        project->set_RawPartInspection("Rohteilkontrolle00");

    if(sender() == ui->toolButton_RawPartInspection_01)
        project->set_RawPartInspection("Rohteilkontrolle01");

    if(sender() == ui->toolButton_RawPartInspection_02)
        project->set_RawPartInspection("Rohteilkontrolle02");

    if(sender() == ui->toolButton_RawPartInspection_03)
        project->set_RawPartInspection("Rohteilkontrolle03");

    // Sende das Signal sig_NewInspection
    emit sig_NewInspection(project->get_RawPartInspection());

    this->close();
}
