#include "dialog_rawpartinspection.h"
#include "ui_dialog_rawpartinspection.h"

Dialog_RawPartInspection::Dialog_RawPartInspection(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::Dialog_RawPartInspection)
{
    ui->setupUi(this);

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
        emit sig_NewInspection("Rohteilkontrolle00");

    if(sender() == ui->toolButton_RawPartInspection_01)
        emit sig_NewInspection("Rohteilkontrolle01");

    if(sender() == ui->toolButton_RawPartInspection_02)
        emit sig_NewInspection("Rohteilkontrolle02");

    if(sender() == ui->toolButton_RawPartInspection_03)
        emit sig_NewInspection("Rohteilkontrolle03");

    this->close();
}
