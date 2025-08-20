#include "tab_project.h"
#include "ui_tab_project.h"
#include "../Classes/mlineedit.h"

Tab_Project::Tab_Project(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Tab_Project)
{
    ui->setupUi(this);
    ui->scrollArea->set_Layout(ui->verticalLayout_Pictures);
    ui->scrollArea->set_Spacer(ui->verticalSpacer_Pictures);

    ui->lineEdit_ProjectName->set_TextNecessary(true);
    ui->lineEdit_ProjectState->set_TextNecessary(true);
    ui->lineEdit_Tension->set_TextNecessary(true);
    ui->lineEdit_Tension->state = MLineEdit::Tension;

    ui->lineEdit_RawPartX->set_TextNecessary(true);
    ui->lineEdit_RawPartX->state = MLineEdit::Digi;
    ui->lineEdit_RawPartY->set_TextNecessary(true);
    ui->lineEdit_RawPartY->state = MLineEdit::Digi;
    ui->lineEdit_RawPartZ->set_TextNecessary(true);
    ui->lineEdit_RawPartZ->state = MLineEdit::Digi;

    ui->lineEdit_FinishPartX->set_TextNecessary(true);
    ui->lineEdit_FinishPartX->state = MLineEdit::Digi;
    ui->lineEdit_FinishPartY->set_TextNecessary(true);
    ui->lineEdit_FinishPartY->state = MLineEdit::Digi;
    ui->lineEdit_FinishPartZ->set_TextNecessary(true);
    ui->lineEdit_FinishPartZ->state = MLineEdit::Digi;

    ui->lineEdit_ZeroPointG->set_TextNecessary(true);
    ui->lineEdit_ZeroPointG->state = MLineEdit::ZeroPointG;
    ui->lineEdit_ZeroPointX->set_TextNecessary(true);
    ui->lineEdit_ZeroPointX->state = MLineEdit::Digi;
    ui->lineEdit_ZeroPointY->set_TextNecessary(true);
    ui->lineEdit_ZeroPointY->state = MLineEdit::Digi;
    ui->lineEdit_ZeroPointZ->set_TextNecessary(true);
    ui->lineEdit_ZeroPointZ->state = MLineEdit::Digi;

    connect(ui->checkBox_Offset_RawPart,SIGNAL(stateChanged(int)), this, SLOT(slot_checkBox_Offset_RawPart_stateChanged(int)));
    connect(ui->checkBox_Offset_FinishPart,SIGNAL(stateChanged(int)), this, SLOT(slot_checkBox_Offset_FinishPart_stateChanged(int)));

    connect(ui->toolButton_RawPartInspection, SIGNAL(released()), this, SLOT(slot_ShowRawPartInspection()));
    connect(ui->toolButton_Tag, SIGNAL(released()), this, SLOT(slot_ShowTags()));
    connect(ui->toolButton_Programme, SIGNAL(released()), this, SLOT(slot_ShowProgramm()));
}

Tab_Project::~Tab_Project()
{
    delete ui;
}

void Tab_Project::insert_Pixmap(QPixmap p)
{
    ui->scrollArea->insert_Pixmap(p);
}

bool Tab_Project::load_Material()
{
    // Einlesen der Materialien
    // setze das File für die Materialien und lies es ein
    // gib alle Materialien in die ComboBox Material
    // tritt ein Fehler auf, gibt die Funktion FALSE zurück
    mfile->setFileName(QDir::homePath() + "/CamHelper/config/Material.txt");
    if(!mfile->read_Content())
        return false;

    log->successful("Materialliste geladen");
    ui->comboBox_Material->addItem("");
    ui->comboBox_Material->addItems(mfile->get_Content());

    return true;
}

void Tab_Project::set_Logging(Logging *l)
{
    log = l;
    mfile = new MFile(this, log);
}

void Tab_Project::set_ProjectData(ProjectData* pd)
{
    projectData = pd;

    ui->scrollArea->clear();                                                        //Lösche die Bilder
    ui->textEdit_Header->clear();                                                   //Lösche den Header

    dialog_RawPartInspection = new Dialog_RawPartInspection(this);
    connect(dialog_RawPartInspection, SIGNAL(sig_NewInspection(QString)),
            this,   SLOT(slot_NewInspection(QString)));

    dialog_Tag = new Dialog_Tag(this, projectData, dataBase);

    dialog_Programm = new Dialog_Programm(this, projectData);

    //Befülle die Felder mit Daten
    ui->lineEdit_ProjectName->setText(projectData->name);                            //Name des Projects
    ui->lineEdit_ProjectState->setText(projectData->state);                          //Der Modellstand des Projekts
    ui->lineEdit_Tension->setText(projectData->tension);                             //Die Spannung des Projekts
    ui->lineEdit_hyperMILL_File->setText(projectData->hyperMILL_File);               //Das hyperMIll File für das Projekt
    ui->textEdit_Header->append(projectData->header);                                //Infotext am Anfanger des Hauptprogramms

    ui->lineEdit_RawPartX->setText(projectData->rawPart.x_Length);                   //Rohteil Länge in X
    ui->lineEdit_RawPartY->setText(projectData->rawPart.y_Width);                    //Rohteil Breite in Y
    ui->lineEdit_RawPartZ->setText(projectData->rawPart.z_Height);                   //Rohteil Höhe in Z
    ui->doubleSpinBox_ZRawPart->setValue(projectData->rawPart.z_RawPart.toFloat());  //Z-Rohteil

    ui->lineEdit_FinishPartX->setText(projectData->finishPart.x_Length);             //Fertigteil Länge in X
    ui->lineEdit_FinishPartY->setText(projectData->finishPart.y_Width);              //Fertigteil Breite in Y
    ui->lineEdit_FinishPartZ->setText(projectData->finishPart.z_Height);             //Fertigteil Höhe in Z

    ui->comboBox_Material->setCurrentText(projectData->material);                    //Material
    ui->label_RawPartInspection->setText(projectData->rawPart_Inspection);

    ui->lineEdit_ZeroPointG->setText(projectData->zeroPoint.string_G);               //Nullpunkt G (G55 G506 etc)
    ui->lineEdit_ZeroPointX->setText(projectData->zeroPoint.string_X);               //Nullpunkt X
    ui->lineEdit_ZeroPointY->setText(projectData->zeroPoint.string_Y);               //Nullpunkt Y
    ui->lineEdit_ZeroPointZ->setText(projectData->zeroPoint.string_Z);               //Nullpunkt Z

    foreach(QPixmap pixmap, projectData->listPictures)                               //Bilder werden eingefügt
        insert_Pixmap(pixmap);

    //Rohteil Aufmass
    ui->doubleSpinBox_Offset_RawPart_XPlus->setValue(projectData->offset_RawPart.string_XPlus.toDouble());
    ui->doubleSpinBox_Offset_RawPart_XMinus->setValue(projectData->offset_RawPart.string_XMinus.toDouble());
    ui->doubleSpinBox_Offset_RawPart_YPlus->setValue(projectData->offset_RawPart.string_YPlus.toDouble());
    ui->doubleSpinBox_Offset_RawPart_YMinus->setValue(projectData->offset_RawPart.string_YMinus.toDouble());
    ui->doubleSpinBox_Offset_RawPart_ZPlus->setValue(projectData->offset_RawPart.string_ZPlus.toDouble());

    ui->widget_Offset_RawPart->hide();
    ui->checkBox_Offset_RawPart->setChecked(false);
    if(ui->doubleSpinBox_Offset_RawPart_XMinus->value() != ui->doubleSpinBox_Offset_RawPart->value() ||
       ui->doubleSpinBox_Offset_RawPart_XPlus->value()  != ui->doubleSpinBox_Offset_RawPart->value() ||
       ui->doubleSpinBox_Offset_RawPart_YMinus->value() != ui->doubleSpinBox_Offset_RawPart->value() ||
       ui->doubleSpinBox_Offset_RawPart_YPlus->value()  != ui->doubleSpinBox_Offset_RawPart->value() ||
       ui->doubleSpinBox_Offset_RawPart_ZPlus->value()  != ui->doubleSpinBox_Offset_RawPart->value() )
    {
        ui->checkBox_Offset_RawPart->setChecked(true);
    }

    //Bauteil Aufmass
    ui->widget_Offset_FinishPart->hide();
    ui->checkBox_Offset_FinishPart->setChecked(false);
    if(ui->doubleSpinBox_Offset_FinishPart_XMinus->value() != ui->doubleSpinBox_Offset_FinishPart->value() ||
        ui->doubleSpinBox_Offset_FinishPart_XPlus->value()  != ui->doubleSpinBox_Offset_FinishPart->value() ||
        ui->doubleSpinBox_Offset_FinishPart_YMinus->value() != ui->doubleSpinBox_Offset_FinishPart->value() ||
        ui->doubleSpinBox_Offset_FinishPart_YPlus->value()  != ui->doubleSpinBox_Offset_FinishPart->value() )
    {
        ui->checkBox_Offset_FinishPart->setChecked(true);
    }


}

void Tab_Project::slot_checkBox_Offset_RawPart_stateChanged(int state)
{
    Q_UNUSED(state);
    if(ui->checkBox_Offset_RawPart->isChecked())
    {
        ui->widget_Offset_RawPart->show();
    }
    else
    {
        ui->widget_Offset_RawPart->hide();
    }
}

void Tab_Project::slot_checkBox_Offset_FinishPart_stateChanged(int state)
{
    Q_UNUSED(state);
    if(ui->checkBox_Offset_FinishPart->isChecked())
    {
        ui->widget_Offset_FinishPart->show();
    }
    else
    {
        ui->widget_Offset_FinishPart->hide();
    }
}

void Tab_Project::slot_ShowRawPartInspection()
{
    dialog_RawPartInspection->show();
}

void Tab_Project::slot_ShowTags()
{
    dialog_Tag->show();
}

void Tab_Project::slot_ShowProgramm()
{
    dialog_Programm->show();
}

void Tab_Project::slot_NewInspection(QString str)
{
    ui->label_RawPartInspection->setText(str);
    projectData->rawPart_Inspection = str;

    /*if(ui->label_RohteilKontrolle->text() != QString("Rohteilkontrolle"))
    {
        palette_Label.setColor(ui->label_RohteilKontrolle->foregroundRole(), forgroundColor);
        ui->label_RohteilKontrolle->setPalette(palette_Label);
    }*/
}

bool Tab_Project::check_InputFields()
{
    bool bool_Return = true;
    QString string;

    if(!ui->lineEdit_ProjectName->check())
    {
        log->vailed("Eingabefeld Projektname ist leer");
        bool_Return = false;
    }

    if(!ui->lineEdit_ProjectState->check())
    {
        log->vailed("Eingabefeld Projektstand ist leer");
        bool_Return = false;
    }

    if(!ui->lineEdit_Tension->check())
    {
        log->vailed("Eingabefeld Spannung ist fehlerhaft");
        bool_Return = false;
    }

    if(!ui->lineEdit_RawPartX->check())
    {
        log->vailed("Eingabefeld Rohteil X ist fehlerhaft");
        bool_Return = false;
    }

    if(!ui->lineEdit_RawPartY->check())
    {
        log->vailed("Eingabefeld Rohteil Y ist fehlerhaft");
        bool_Return = false;
    }

    if(!ui->lineEdit_RawPartZ->check())
    {
        log->vailed("Eingabefeld Rohteil Z ist fehlerhaft");
        bool_Return = false;
    }

    if(!ui->lineEdit_FinishPartX->check())
    {
        log->vailed(("Eingabefeld Bauteil X ist fehlerhat"));
        bool_Return = false;
    }

    if(!ui->lineEdit_FinishPartY->check())
    {
        log->vailed(("Eingabefeld Bauteil Y ist fehlerhat"));
        bool_Return = false;
    }

    if(!ui->lineEdit_FinishPartZ->check())
    {
        log->vailed(("Eingabefeld Bauteil Z ist fehlerhat"));
        bool_Return = false;
    }

    if(!ui->lineEdit_ZeroPointG->check())
    {
        log->vailed(("Eingabefeld Nullpunkt G ist fehlerhat"));
        bool_Return = false;
    }

    if(!ui->lineEdit_ZeroPointX->check())
    {
        log->vailed(("Eingabefeld Nullpunkt X ist fehlerhat"));
        bool_Return = false;
    }

    if(!ui->lineEdit_ZeroPointY->check())
    {
        log->vailed(("Eingabefeld Nullpunkt Y ist fehlerhat"));
        bool_Return = false;
    }

    if(!ui->lineEdit_ZeroPointZ->check())
    {
        log->vailed(("Eingabefeld Nullpunkt Z ist fehlerhat"));
        bool_Return = false;
    }

    if(ui->comboBox_Material->currentText().isEmpty())
    {
        log->vailed("Material fehlt");
        bool_Return = false;
    }

    if(!bool_Return)                //Wenn ein Fehler aufgetreten ist brech hier ab
        return bool_Return;


    projectData->name = ui->lineEdit_ProjectName->text();
    projectData->state = ui->lineEdit_ProjectState->text();
    projectData->tension = ui->lineEdit_Tension->text();
    projectData->hyperMILL_File = ui->lineEdit_hyperMILL_File->text();
    projectData->material = ui->comboBox_Material->currentText();

    projectData->rawPart.x_Length = ui->lineEdit_RawPartX->text();
    projectData->rawPart.y_Width = ui->lineEdit_RawPartY->text();
    projectData->rawPart.z_Height = ui->lineEdit_RawPartZ->text();
    projectData->rawPart.z_RawPart = QString("%1").arg(ui->doubleSpinBox_ZRawPart->value());
    projectData->rawPart_Inspection = ui->label_RawPartInspection->text();

    projectData->finishPart.x_Length = ui->lineEdit_FinishPartX->text();
    projectData->finishPart.y_Width = ui->lineEdit_FinishPartY->text();
    projectData->finishPart.z_Height = ui->lineEdit_FinishPartZ->text();

    projectData->zeroPoint.string_G = ui->lineEdit_ZeroPointG->text();
    projectData->zeroPoint.string_X = ui->lineEdit_ZeroPointX->text();
    projectData->zeroPoint.string_Y = ui->lineEdit_ZeroPointY->text();
    projectData->zeroPoint.string_Z = ui->lineEdit_ZeroPointZ->text();

    string = QString("%1").arg(ui->doubleSpinBox_Offset_RawPart_XPlus->value());
    string = string.replace(",",".");
    projectData->offset_RawPart.string_XPlus = string;

    string = QString("%1").arg(ui->doubleSpinBox_Offset_RawPart_XMinus->value());
    string = string.replace(",",".");
    projectData->offset_RawPart.string_XMinus = string;

    string = QString("%1").arg(ui->doubleSpinBox_Offset_RawPart_YPlus->value());
    string = string.replace(",",".");
    projectData->offset_RawPart.string_YPlus = string;

    string = QString("%1").arg(ui->doubleSpinBox_Offset_RawPart_YMinus->value());
    string = string.replace(",",".");
    projectData->offset_RawPart.string_YMinus = string;

    string = QString("%1").arg(ui->doubleSpinBox_Offset_RawPart_ZPlus->value());
    string = string.replace(",",".");
    projectData->offset_RawPart.string_ZPlus = string;


    return bool_Return;
}
