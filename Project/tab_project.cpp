#include "tab_project.h"
#include "ui_tab_project.h"
#include "../Classes/mlineedit.h"

Tab_Project::Tab_Project(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Tab_Project)
{
    ui->setupUi(this);

    fileDialog = new QFileDialog(this);
    fileDialog->setFilter(QDir::Files);

    settings = new QSettings("Gareiss", "CamHelper");
    clipboard = QApplication::clipboard();
    projectExport = new Project_Export(this);
    dialog_Repetition = new Dialog_Repetition();

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

    ui->doubleSpinBox_ZRawPart->set_Zero(false);

    connect(ui->checkBox_Offset_RawPart,SIGNAL(stateChanged(int)), this, SLOT(slot_checkBox_Offset_RawPart_stateChanged(int)));
    connect(ui->checkBox_Offset_FinishPart,SIGNAL(stateChanged(int)), this, SLOT(slot_checkBox_Offset_FinishPart_stateChanged(int)));

    connect(ui->toolButton_RawPartInspection, SIGNAL(released()), this, SLOT(slot_ShowRawPartInspection()));
    connect(ui->toolButton_Tag, SIGNAL(released()), this, SLOT(slot_ShowTags()));
    connect(ui->toolButton_Programme, SIGNAL(released()), this, SLOT(slot_ShowProgramm()));
    connect(ui->toolButton_Tools, SIGNAL(released()), this, SLOT(slot_ShowTools()));
    connect(ui->toolButton_Selector, SIGNAL(released()), this, SLOT(slot_NewSelector()));
    connect(ui->toolButton_Paste,SIGNAL(released()), this, SLOT(slot_NPPaste()));
    connect(ui->toolButton_Export, SIGNAL(released()), this, SLOT(slot_Export()));
    connect(ui->toolButton_OpenFile, SIGNAL(released()), this, SLOT(slot_NewHyperMILLFile()));
    connect(ui->toolButton_ExecFile, SIGNAL(released()), this, SLOT(slot_ExecFile()));
    connect(ui->toolButton_MainProgramm, SIGNAL(released()), this, SIGNAL(sig_ShowMainProgramm()));

    connect(dialog_Repetition, SIGNAL(accepted()), this, SLOT(slot_RepetitionAccepted()));
    connect(projectExport, SIGNAL(sig_Export_TouchProbe()), this, SIGNAL(sig_ExportTouchprobe()));
}

Tab_Project::~Tab_Project()
{
    delete ui;
    delete dialog_Repetition;
}

void Tab_Project::slot_Export()
{
    if(!update_ProjectData())                               //Schreibe den Inhalt der Eingabefelder in ProjectData
    {
        stackedWidget->setCurrentWidget(log);               //Wenn die Felder Unfollständig sind schalte auf Tab_Log
        return;                                             //brich den Export ab
    }

    mainProgramm->set_ProjectData(*projectData);            //Erzeuge das Hauptprogramm im Tab_MainProgramm
    projectExport->set_ContentMainProgramm(mainProgramm);   //Übergebe das Hauptprogramm an projectExport

    if(!dataBase->check_ProjectID(projectData->name,
                               projectData->tension))       //Überprüfe ob es das Project in der Datenbank gibt
        projectExport->exportProject(projectData, true);    //Starte den Export, die Werkzeuge werden um eins hochgezählt
    else
        dialog_Repetition->show();
}

bool Tab_Project::check_InputFields()
{
    bool bool_Return = true;

    if(!ui->lineEdit_ProjectName->check())                      //Überprüfe Projektname
    {
        log->vailed("Eingabefeld Projektname ist leer");
        bool_Return = false;
    }

    if(!ui->lineEdit_ProjectState->check())                     //Überprüfe Projektstand E0 E1 etc
    {
        log->vailed("Eingabefeld Projektstand ist leer");
        bool_Return = false;
    }

    if(!ui->lineEdit_Tension->check())                          //Überprüfe Spannung Sp1 Sp2 etc
    {
        log->vailed("Eingabefeld Spannung ist fehlerhaft");
        bool_Return = false;
    }

    if(ui->lineEdit_Tension->text() == "Sp1")                       //Wird nur bei Sp1 Überprüft
    {
        if(!ui->lineEdit_RawPartX->check())                         //Rohteil X
        {
            log->vailed("Eingabefeld Rohteil X ist fehlerhaft");
            bool_Return = false;
        }
        if(!ui->lineEdit_RawPartY->check())                         //Rohteil Y
        {
            log->vailed("Eingabefeld Rohteil Y ist fehlerhaft");
            bool_Return = false;
        }

        if(!ui->lineEdit_RawPartZ->check())                         //Rohteil Z
        {
            log->vailed("Eingabefeld Rohteil Z ist fehlerhaft");
            bool_Return = false;
        }

        if(!ui->lineEdit_FinishPartX->check())                      //Fertigteil X
        {
            log->vailed(("Eingabefeld Bauteil X ist fehlerhat"));
            bool_Return = false;
        }

        if(!ui->lineEdit_FinishPartY->check())                      //Fertigteil Y
        {
            log->vailed(("Eingabefeld Bauteil Y ist fehlerhat"));
            bool_Return = false;
        }

        if(!ui->lineEdit_FinishPartZ->check())                      //Ferigteil Z
        {
            log->vailed(("Eingabefeld Bauteil Z ist fehlerhat"));
            bool_Return = false;
        }

        if(!ui->doubleSpinBox_ZRawPart->check())                //Wert zum Antasten für Rohteil Z
        {
            log->vailed("Z Rohteil auf 0");
            ui->doubleSpinBox_ZRawPart->set_Null();
            bool_Return = false;
        }

        if(ui->label_RawPartInspection->text().isEmpty() ||         //Rohteilkontrolle
            ui->label_RawPartInspection->text() == "Rohteil")
        {
            log->vailed("Keine Rohteilkontrolle ausgewählt");
            ui->label_RawPartInspection->setText("Rohteil");
            ui->label_RawPartInspection->setStyleSheet("color:rgb(255,0,0);");
            bool_Return = false;
        }
        else
            ui->label_RawPartInspection->setStyleSheet("color:rgb(192,192,192);");

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
        ui->comboBox_Material->set_Empty();
        bool_Return = false;
    }

    return bool_Return;
}

bool Tab_Project::update_ProjectData()
{
    QString string;

    //Überprüfe die Eingabefelder
    if(!check_InputFields())
        return false;

    //Schreibe die Daten aus den Eingabefeldern in ProjectData
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
    projectData->offset_RawPart.string_Max_XPlus = string;

    string = QString("%1").arg(ui->doubleSpinBox_Offset_RawPart_XMinus->value());
    string = string.replace(",",".");
    projectData->offset_RawPart.string_Max_XMinus = string;

    string = QString("%1").arg(ui->doubleSpinBox_Offset_RawPart_YPlus->value());
    string = string.replace(",",".");
    projectData->offset_RawPart.string_Max_YPlus = string;

    string = QString("%1").arg(ui->doubleSpinBox_Offset_RawPart_YMinus->value());
    string = string.replace(",",".");
    projectData->offset_RawPart.string_Max_YMinus = string;

    string = QString("%1").arg(ui->doubleSpinBox_Offset_RawPart_ZPlus->value());
    string = string.replace(",",".");
    projectData->offset_RawPart.string_Max_ZPlus = string;

    //Aufmasse für die Rohteilkontrolle
    double double_AufmassX = (ui->lineEdit_RawPartX->text().toDouble() -
                              ui->lineEdit_FinishPartX->text().toDouble()) /2;
    double double_AufmassY = (ui->lineEdit_RawPartY->text().toDouble() -
                              ui->lineEdit_FinishPartY->text().toDouble()) /2;

    projectData->offset_RawPart.string_Max_XPlus_RawpartInspection = QString("%1").arg(ui->doubleSpinBox_Offset_RawPart_XPlus->value() + double_AufmassX);
    projectData->offset_RawPart.string_Max_XMinus_RawpartInspection = QString("%1").arg(ui->doubleSpinBox_Offset_RawPart_XMinus->value() + double_AufmassX);
    projectData->offset_RawPart.string_Max_YPlus_RawpartInspection = QString("%1").arg(ui->doubleSpinBox_Offset_RawPart_YPlus->value() + double_AufmassY);
    projectData->offset_RawPart.string_Max_YMinus_RawpartInspection = QString("%1").arg(ui->doubleSpinBox_Offset_RawPart_YMinus->value() + double_AufmassY);
    projectData->offset_RawPart.string_Max_ZPlus_RawpartInspection = QString("%1").arg(ui->doubleSpinBox_Offset_RawPart_ZPlus->value() +
                                                                                   ui->doubleSpinBox_ZRawPart->value());


    projectData->offset_RawPart.string_Min_XPlus = QString("%1").arg(ui->doubleSpinBox_Offset_FinishPart_XPlus->value());
    projectData->offset_RawPart.string_Min_XMinus = QString("%1").arg(ui->doubleSpinBox_Offset_FinishPart_XMinus->value());
    projectData->offset_RawPart.string_Min_YPlus = QString("%1").arg(ui->doubleSpinBox_Offset_FinishPart_YPlus->value());
    projectData->offset_RawPart.string_Min_YMinus = QString("%1").arg(ui->doubleSpinBox_Offset_FinishPart_YMinus->value());
    projectData->offset_RawPart.string_Min_ZPlus = QString("%1").arg(ui->doubleSpinBox_Offset_FinishPart_ZPlus->value());

    projectData->header = ui->textEdit_Header->toPlainText();

    //Lösche die Bilderliste und schreibe die Bilder in die Bilderliste
    projectData->listPictures.clear();
    foreach(MLabel* label, ui->scrollArea->get_PictureList())
    {
        projectData->listPictures.append(label->get_Pixmap());
    }

    projectData->list_TouchProbe.clear();
    int pos = 0;
    foreach(TP_Item* item, touchProbe->get_ItemList())
    {
        Item_TouchProbe item_TouchProbe;

        if(item->get_State() == TP_Item::Ausrichten)
        {
            item_TouchProbe.struct_Ausrichten = item->get_Ausrichten();             //Schreibe Ausrichten in item_Touchprobe
            item_TouchProbe.struct_Ausrichten.string_Pos = QString("%1").arg(pos);  //Schreibe die Position in Austrichten
            item_TouchProbe.state = Item_TouchProbe::Ausrichten;                    //setze den Status
            projectData->list_TouchProbe.append(item_TouchProbe);                   //speicher item_TouchProbe in projecData
            pos++;
            continue;
        }
        if(item->get_State() == TP_Item::Kante)
        {
            item_TouchProbe.struct_Kante = item->get_Kante();
            item_TouchProbe.struct_Kante.string_Pos = QString("%1").arg(pos);
            item_TouchProbe.state = Item_TouchProbe::Kante;
            projectData->list_TouchProbe.append(item_TouchProbe);
            pos++;
            continue;
        }

        if(item->get_State() == TP_Item::Ebenheit)
        {
            item_TouchProbe.struct_Ebenheit = item->get_Ebenheit();
            item_TouchProbe.struct_Ebenheit.string_Pos = QString("%1").arg(pos);
            item_TouchProbe.state = Item_TouchProbe::Ebenheit;
            projectData->list_TouchProbe.append(item_TouchProbe);
            pos++;
            continue;
        }

        if(item->get_State() == TP_Item::Steg)
        {
            item_TouchProbe.struct_Steg = item->get_Steg();
            item_TouchProbe.struct_Steg.string_Pos = QString("%1").arg(pos);
            item_TouchProbe.state = Item_TouchProbe::Steg;
            projectData->list_TouchProbe.append(item_TouchProbe);
            pos++;
            continue;
        }

        if(item->get_State() == TP_Item::Bohrung)
        {
            item_TouchProbe.struct_Bohrung = item->get_Bohrung();
            item_TouchProbe.struct_Bohrung.string_Pos = QString("%1").arg(pos);
            item_TouchProbe.state = Item_TouchProbe::Bohrung;
            projectData->list_TouchProbe.append(item_TouchProbe);
            pos++;
            continue;
        }

        if(item->get_State() == TP_Item::Nut)
        {
            item_TouchProbe.struct_Nut = item->get_Nut();
            item_TouchProbe.struct_Nut.string_Pos = QString("%1").arg(pos);
            item_TouchProbe.state = Item_TouchProbe::Nut;
            projectData->list_TouchProbe.append(item_TouchProbe);
            pos++;
            continue;
        }
    }
    return true;
}

float Tab_Project::filter_Value(QString string)
{
    float float_Value;
    bool bool_OK;
    QStringList stringList_Parts;
    //QString string_Return;

    stringList_Parts = string.split(" ");
    foreach(QString str, stringList_Parts)
    {
        str.toFloat(&bool_OK);
        if(bool_OK)
        {
            float_Value = str.toFloat(&bool_OK);
            break;
        }
    }

    // runde auf 3 stellen nach dem komma ab
    //if(bool_OK)
    //    string_Return = QString::number(float_Value, 'f', 3);
    return float_Value;
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

void Tab_Project::slot_NPPaste()
{
    //Settings* settings = project->get_Settings();

    float float_OffsetX = settings->value("OffsetX",999).toFloat();
    float float_OffsetY = settings->value("OffsetY",999).toFloat();
    float float_OffsetZ = settings->value("OffsetZ",999).toFloat();
    float float_NPx, float_NPy, float_NPz;

    QString string_Text = clipboard->text();
    QString string_X = "";
    QString string_Y = "";
    QString string_Z = "";

    // zerlege den String in Zeilen
    QStringList stringList = string_Text.split("\n");

    //geh durch alle Zeilen
    for(int i = 0; i<stringList.size(); i++)
    {
        // Wenn in der Zeile das Schlüsselwort Endpunkt vorkommt lies
        // die nächsten 3 Zeilen ein
        if(stringList.at(i).contains("Delta-Koordinaten") && i+3 < stringList.size())
        {
            string_X = stringList.at(i+1);
            string_Y = stringList.at(i+2);
            string_Z = stringList.at(i+3);
        }
    }

    if(!string_X.isEmpty())
        float_NPx = float_OffsetX + filter_Value(string_X);
    if(!string_Y.isEmpty())
        float_NPy = float_OffsetY + filter_Value(string_Y);
    if(!string_Z.isEmpty())
        float_NPz = float_OffsetZ + filter_Value(string_Z);

    ui->lineEdit_ZeroPointX->setText(QString::number(float_NPx, 'f', 2));
    ui->lineEdit_ZeroPointY->setText(QString::number(float_NPy, 'f', 2));
    ui->lineEdit_ZeroPointZ->setText(QString::number(float_NPz, 'f', 2));

    //qDebug() << Q_FUNC_INFO << float_NPx << float_NPy << float_NPz;
}

void Tab_Project::set_DataBase(DataBase *db)
{
    dataBase = db;                          //Übernehme die Datenbank in den Zeiger dataBase
    projectExport->set_DataBase(dataBase);  //Übergebe die Datenbank an projectExprot
}

void Tab_Project::set_Logging(Logging *l)
{
    log = l;
    mfile = new MFile(this, log);
    projectExport->set_Logging(log);        //Übergebe projectExport das logging
}

void Tab_Project::set_ProjectData(ProjectData* pd)
{
    projectData = pd;

    ui->scrollArea->clear();                                                        //Lösche die Bilder
    ui->textEdit_Header->clear();                                                   //Lösche den Header
    ui->label_RawPartInspection->setText("Rohteil");
    ui->label_RawPartInspection->setStyleSheet("color:rgb(255,0,0);");

    dialog_RawPartInspection = new Dialog_RawPartInspection(this);
    connect(dialog_RawPartInspection, SIGNAL(sig_NewInspection(QString)),
            this,   SLOT(slot_NewInspection(QString)));

    dialog_Tag = new Dialog_Tag(this, projectData, dataBase);

    dialog_Programm = new Dialog_Programm(this, projectData);                       //erzeuge den Dialog Progamm mit Zeiger auf die Daten

    dialog_Tools = new Dialog_Tools(this, projectData);
    connect(dialog_Tools, SIGNAL(sig_NewToolList()), this, SIGNAL(sig_NewToolList()));

    if(projectData->tension != "Sp1")
    {
        ui->lineEdit_RawPartX->set_TextNecessary(false);
        ui->lineEdit_RawPartY->set_TextNecessary(false);
        ui->lineEdit_RawPartZ->set_TextNecessary(false);

        ui->lineEdit_FinishPartX->set_TextNecessary(false);
        ui->lineEdit_FinishPartY->set_TextNecessary(false);
        ui->lineEdit_FinishPartZ->set_TextNecessary(false);

        ui->doubleSpinBox_ZRawPart->set_Zero(true);             //Die Spinbox darf den Wert 0 enthalten
    }
    else
    {
        ui->lineEdit_RawPartX->set_TextNecessary(true);
        ui->lineEdit_RawPartY->set_TextNecessary(true);
        ui->lineEdit_RawPartZ->set_TextNecessary(true);

        ui->lineEdit_FinishPartX->set_TextNecessary(true);
        ui->lineEdit_FinishPartY->set_TextNecessary(true);
        ui->lineEdit_FinishPartZ->set_TextNecessary(true);

        ui->doubleSpinBox_ZRawPart->set_Zero(false);
    }

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
    ui->doubleSpinBox_Offset_RawPart_XPlus->setValue(projectData->offset_RawPart.string_Max_XPlus.toDouble());
    ui->doubleSpinBox_Offset_RawPart_XMinus->setValue(projectData->offset_RawPart.string_Max_XMinus.toDouble());
    ui->doubleSpinBox_Offset_RawPart_YPlus->setValue(projectData->offset_RawPart.string_Max_YPlus.toDouble());
    ui->doubleSpinBox_Offset_RawPart_YMinus->setValue(projectData->offset_RawPart.string_Max_YMinus.toDouble());
    ui->doubleSpinBox_Offset_RawPart_ZPlus->setValue(projectData->offset_RawPart.string_Max_ZPlus.toDouble());

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

    check_InputFields();
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

void Tab_Project::slot_ShowTools()
{
    dialog_Tools->show();
}

void Tab_Project::slot_NewInspection(QString str)
{
    ui->label_RawPartInspection->setText(str);
    ui->label_RawPartInspection->setStyleSheet("");
    projectData->rawPart_Inspection = str;
}

void Tab_Project::slot_NewSelector()
{
    selectorWidget = new SelectorWidget();
    connect(selectorWidget, SIGNAL(sig_NewPixmap(QPixmap)), this, SLOT(slot_NewPixmap(QPixmap)));
    selectorWidget->show();
}

void Tab_Project::slot_NewPixmap(QPixmap pixmap)
{
    ui->scrollArea->insert_Pixmap(pixmap);
}

void Tab_Project::slot_RepetitionAccepted()
{
    if(dialog_Repetition->radioButton_Repetition->isChecked())
    {
        projectExport->exportProject(projectData, true);    //Starte den Export, die Werkzeuge werden um eins hochgezählt
    }
    else
    {
        projectExport->exportProject(projectData, false);    //Starte den Export
    }
}

void Tab_Project::slot_NewHyperMILLFile()
{
    fileDialog->setNameFilter(tr("HyperMILL (*.hmc)"));
    ui->lineEdit_hyperMILL_File->setText(fileDialog->getOpenFileName());
}

void Tab_Project::slot_ExecFile()
{
    QString url = ui->lineEdit_hyperMILL_File->text();
    if(url.isEmpty())
        return;

    QDesktopServices::openUrl(QUrl::fromLocalFile(url)); //(url, QUrl::TolerantMode));
}
