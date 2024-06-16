#include "dialog_project.h"
#include "ui_dialog_project.h"

Dialog_Project::Dialog_Project(QWidget *parent,
                               Logging* l,
                               Project* p,
                               DataBase* db) :
    QDialog(parent),
    ui(new Ui::Dialog_Project)
{
    ui->setupUi(this);

    // setze übergebene Parameter
    project = p;
    log     = l;
    database = db;

    // Erzeuge den Zeiger auf MFile
    mfile = new MFile(this, log);

    // Erzeuge den Zeiger auf Dialog_RohteilKontrolle
    // Verbinde das Signal für eine neu Auswahl mit dem Slot
    // slot_NewInspection(QString)
    dialog_RawPartInspection = new Dialog_RawPartInspection(this, project);
    connect(dialog_RawPartInspection, SIGNAL(sig_NewInspection(QString)),
                                this,   SLOT(slot_NewInspection(QString)));

    // Erstelle Paletten für gültige und ungültige Eingaben
    palette_InValid = new QPalette();
    palette_InValid->setColor(QPalette::Text,Qt::red);

    palette_Valid = new QPalette();
    *palette_Valid = palette();

    // Befülle Eingabefelder mit den Werten aus dem Project
    ui->lineEdit_ProjectName->setText(project->get_ProjectName());
    ui->lineEdit_ProjectStatus->setText(project->get_ProjectStatus());

    if(project->get_MaxOverSize())
    {
        ui->groupBox_AufmassMaxRT->setTitle("Aufmass Max vom Bauteil");
    }


    if(ui->checkBox_RT_EinzelAufmass->isChecked())
    {
        ui->widget_RT_AufmassEinzel->show();
    }
    else
    {
        ui->widget_RT_AufmassEinzel->hide();
    }

    if(ui->checkBox_FT_EinzelAufmass->isChecked())
    {
        ui->widget_FT_AufmassEinzel->show();
    }
    else
    {
        ui->widget_FT_AufmassEinzel->hide();
    }

    // Wenn OK geklickt wurde werden erstmal alle Eingaben überprüft
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(slot_CheckInput()));
    // Wird die Spannung geändert, wird auch der Nullpunkt gändert werden
    connect(ui->comboBox_Clamping, SIGNAL(currentIndexChanged(int)), this, SLOT(slot_ClampingChanged(int)));
    // Wird der Button Rohteilkontrolle geklickt erscheint eine Auswahl für die Rohteilkontrolle
    connect(ui->toolButton_RawPartInspection, SIGNAL(released()), this, SLOT(slot_ShowRawPartInspection()));
}

Dialog_Project::~Dialog_Project()
{
    delete ui;
}

bool Dialog_Project::load_Material()
{
    // Einlesen der Materialien
    // setze das File für die Materialien und lies es ein
    // gib alle Materialien in die ComboBox Material
    // tritt ein Fehler auf, gibt die Funktion FALSE zurück
    mfile->setFileName(QDir::homePath() + "/CamHelper/config/Material.txt");
    if(!mfile->read_Content())
        return false;
    ui->comboBox_Material->addItems(mfile->get_Content());

    return true;
}

void Dialog_Project::load_ProjectData()
{
    Item_Project item_Project;
    QString string_ProjectID;

    //Lade Projektdaten aus der Datenbank und fülle die Felder aus
    item_Project = database->get_Project(project->get_ProjectName(), project->get_ProjectClamping());
    ui->comboBox_Material->setCurrentText(item_Project.Material);
    ui->lineEdit_RTx->setText(item_Project.RawPart_X);
    ui->lineEdit_RTy->setText(item_Project.RawPart_Y);
    ui->lineEdit_RTz->setText(item_Project.RawPart_Z);
    ui->lineEdit_BTx->setText(item_Project.Component_X);
    ui->lineEdit_BTy->setText(item_Project.Component_Y);
    ui->lineEdit_BTz->setText(item_Project.Component_Z);
    ui->doubleSpinBox_ZRohTeil->setValue(item_Project.ZRawPart.toDouble());
    ui->label_RohteilKontrolle->setText(item_Project.RawPartInspection);

    //Wenn es keine ID gibt bricht hier ab
    string_ProjectID = item_Project.id;
    if(string_ProjectID.isEmpty())
        return;

    //OK es gibt eine ID, lade TouchProbe
    QList<Item_TouchProbe> list = database->get_TouchProbe(string_ProjectID);

    // Setze die Liste mit den TouchProbe im Projekt
    // Die Liste wird in CamHelper::slot_DialogProjectClosed() abgearbeitet
    project->set_ListTouchProbe(list);
}

bool Dialog_Project::load_ZeroPoint()
{
    //Einlesen der Nullpunkte
    QStringList stringList_Split;
    QString string_Clamping = project->get_ProjectClamping();

    // setze das File für die Mullpunkte und lies es ein
    mfile->setFileName(QDir::homePath() + "/CamHelper/config/Nullpunkt.txt");
    if(!mfile->read_Content())
        return false;

    // Übergebe den Inhalt des Files in stringList_ZeroPoint
    stringList_ZeroPoint = mfile->get_Content();

    // gehe durch die stringList_ZeroPoint
    foreach(string_Line,stringList_ZeroPoint)
    {
        // Wenn string_Line " || " enthaelt wird string_Line aufgesplittet
        // und beide Strings in QMap<QStrign, QString> map_NP eingetragen
        if(string_Line.contains(" || "))
        {
            stringList_Split = string_Line.split(" || ");
            if(stringList_Split.size()>1)
            {
                map_NP.insert(stringList_Split.at(0), stringList_Split.at(1));
            }
        }
    }

    // loesche stringList_ZeroPoint
    stringList_ZeroPoint.clear();

    // erzeuge einen Iterator auf map_NP und gehe durch map_NP
    // schreibe in stringList_ZeroPoint alle Keys von map_NP
    QMapIterator<QString, QString> i(map_NP);
    while (i.hasNext())
    {
        i.next();
        stringList_ZeroPoint.append(i.key());
    }

    // Schreibe alle Keys aus der stringList_ZeroPoint in die
    // ComboBox.
    ui->comboBox_Clamping->addItems(stringList_ZeroPoint);
    list_Keys = map_NP.keys();

    // setze den Nullpunkt anhand der Spannung
    if(string_Clamping == "SP0" || string_Clamping == "Sp0" || string_Clamping == "sp0")
    {
        ui->comboBox_Clamping->setCurrentText(list_Keys[0]);
        ui->lineEdit_NP->setText(map_NP[list_Keys[0]]);
    }

    if(string_Clamping == "SP1" || string_Clamping == "Sp1" || string_Clamping == "sp1")
    {
        ui->comboBox_Clamping->setCurrentText(list_Keys[1]);
        ui->lineEdit_NP->setText(map_NP[list_Keys[1]]);
    }

    if(string_Clamping == "SP2" || string_Clamping == "Sp2" || string_Clamping == "sp2")
    {
        ui->comboBox_Clamping->setCurrentText(list_Keys[2]);
        ui->lineEdit_NP->setText(map_NP[list_Keys[2]]);
    }

    if(string_Clamping == "SP3" || string_Clamping == "Sp3" || string_Clamping == "sp3")
    {
        ui->comboBox_Clamping->setCurrentText(list_Keys[3]);
        ui->lineEdit_NP->setText(map_NP[list_Keys[3]]);
    }

    return true;
}

void Dialog_Project::slot_CheckInput()
{
    //qDebug() << Q_FUNC_INFO;
    QString string_ProjectName;
    QString string_ProjectStatus;
    QString string_Komma;
    bool bool_OK;
    bool bool_valid = true;

    ui->lineEdit_ProjectName->setPalette(*palette_Valid);
    ui->lineEdit_ProjectStatus->setPalette(*palette_Valid);

    // Wenn das Eingabefeld leer ist oder "*" drin ist setze
    // setze die Palette für ein ungültiges Feld
    // und schreibe "*" in das Eingabenfeld
    // setze die Variabel bool_valid auf FALSE
    if(ui->lineEdit_ProjectName->text().isEmpty() ||
        ui->lineEdit_ProjectName->text() == "*")
    {
        ui->lineEdit_ProjectName->setPalette(*palette_InValid);
        ui->lineEdit_ProjectName->setText("*");
        bool_valid = false;
    }

    if(ui->lineEdit_ProjectStatus->text().isEmpty() ||
        ui->lineEdit_ProjectStatus->text() == "*")
    {
        ui->lineEdit_ProjectStatus->setPalette(*palette_InValid);
        ui->lineEdit_ProjectStatus->setText("*");
        bool_valid = false;
    }

    // Wenn Spannung1 gewaehlt wurde dann
    // überprüfe die Eingabenfelder für Rohteil und Bauteil
    if(ui->comboBox_Clamping->currentIndex() == 1)
    {
        // Wenn das Eingabefeld leer ist oder "*" drin ist setze
        // setze die Palette für ein ungültiges Feld
        // und schreibe "*" in das Eingabenfeld
        // setze die Variabel bool_valid auf FALSE
        if(ui->lineEdit_RTx->text().isEmpty() || ui->lineEdit_RTx->text() == "*" )
        {
            ui->lineEdit_RTx->setPalette(*palette_InValid);
            ui->lineEdit_RTx->setText("*");
            bool_valid = false;
        }

        if(ui->lineEdit_RTy->text().isEmpty() || ui->lineEdit_RTy->text() == "*" )
        {
            ui->lineEdit_RTy->setPalette(*palette_InValid);
            ui->lineEdit_RTy->setText("*");
            bool_valid = false;
        }

        if(ui->lineEdit_RTz->text().isEmpty() || ui->lineEdit_RTz->text() == "*" )
        {
            ui->lineEdit_RTz->setPalette(*palette_InValid);
            ui->lineEdit_RTz->setText("*");
            bool_valid = false;
        }

        if(ui->lineEdit_BTx->text().isEmpty() || ui->lineEdit_BTx->text() == "*" )
        {
            ui->lineEdit_BTx->setPalette(*palette_InValid);
            ui->lineEdit_BTx->setText("*");
            bool_valid = false;
        }

        if(ui->lineEdit_BTy->text().isEmpty() || ui->lineEdit_BTy->text() == "*" )
        {
            ui->lineEdit_BTy->setPalette(*palette_InValid);
            ui->lineEdit_BTy->setText("*");
            bool_valid = false;
        }

        if(ui->lineEdit_BTz->text().isEmpty() || ui->lineEdit_BTz->text() == "*" )
        {
            ui->lineEdit_BTz->setPalette(*palette_InValid);
            ui->lineEdit_BTz->setText("*");
            bool_valid = false;
        }
    }

    // Wenn Spannung1 gewaehlt wurde dann
    // Ersetze ein Komma durch einen Punkt
    // aus "," wird "."
    if(ui->comboBox_Clamping->currentIndex() == 1)
    {
        // Komma in Pnkut umwandeln
        string_Komma = ui->lineEdit_BTx->text();
        string_Komma = string_Komma.replace(",", ".");
        ui->lineEdit_BTx->setText(string_Komma);

        string_Komma = ui->lineEdit_BTy->text();
        string_Komma = string_Komma.replace(",", ".");
        ui->lineEdit_BTy->setText(string_Komma);

        string_Komma = ui->lineEdit_BTz->text();
        string_Komma = string_Komma.replace(",", ".");
        ui->lineEdit_BTz->setText(string_Komma);

        string_Komma = ui->lineEdit_RTx->text();
        string_Komma = string_Komma.replace(",", ".");
        ui->lineEdit_RTx->setText(string_Komma);

        string_Komma = ui->lineEdit_RTy->text();
        string_Komma = string_Komma.replace(",", ".");
        ui->lineEdit_RTy->setText(string_Komma);

        string_Komma = ui->lineEdit_RTz->text();
        string_Komma = string_Komma.replace(",", ".");
        ui->lineEdit_RTz->setText(string_Komma);

        // Prüfe ob sich die Inhalte der Eingabenfelder in ein
        // Double umwandeln lassen. Wenn das fehlschlaegt setze
        // bool_valde auf FALSE
        ui->lineEdit_BTx->text().toDouble(&bool_OK);
        if(!bool_OK)
        {
            ui->lineEdit_BTx->setPalette(*palette_InValid);
            bool_valid = false;
        }
        ui->lineEdit_BTy->text().toDouble(&bool_OK);
        if(!bool_OK)
        {
            ui->lineEdit_BTy->setPalette(*palette_InValid);
            bool_valid = false;
        }
        ui->lineEdit_BTz->text().toDouble(&bool_OK);
        if(!bool_OK)
        {
            ui->lineEdit_BTz->setPalette(*palette_InValid);
            bool_valid = false;
        }

        ui->lineEdit_RTx->text().toDouble(&bool_OK);
        if(!bool_OK)
        {
            ui->lineEdit_RTx->setPalette(*palette_InValid);
            bool_valid = false;
        }
        ui->lineEdit_RTy->text().toDouble(&bool_OK);
        if(!bool_OK)
        {
            ui->lineEdit_RTy->setPalette(*palette_InValid);
            bool_valid = false;
        }
        ui->lineEdit_RTz->text().toDouble(&bool_OK);
        if(!bool_OK)
        {
            ui->lineEdit_RTz->setPalette(*palette_InValid);
            bool_valid = false;
        }
    }

    // Wenn in der ComboBox_Material ein * angewaehlt ist
    // setze die ComboBox auf ungueltig und bool_valid auf FALSe
    if(ui->comboBox_Material->currentText() == "*")
    {
        ui->comboBox_Material->setPalette(*palette_InValid);
        ui->comboBox_Material->setCurrentText("*");
        bool_valid = false;
    }

    // Wenn bis hier ein Fehler aufgetreten ist zeige den Dialog erneut
    // bis es keine fehlerhaften Eingaben mehr gibt
    if(!bool_valid)
    {
        this->show();
        return;
    }

    // ab hier werden dem Project die Eingaben aus dem Dialog übergeben
    string_ProjectName = ui->lineEdit_ProjectName->text();
    string_ProjectName = string_ProjectName.replace(" ", "_");
    ui->lineEdit_ProjectName->setText(string_ProjectName);

    string_ProjectStatus = ui->lineEdit_ProjectStatus->text();
    string_ProjectStatus = string_ProjectStatus.replace(" ", "_");
    ui->lineEdit_ProjectStatus->setText(string_ProjectStatus);

    project->set_ProjectName(ui->lineEdit_ProjectName->text());
    project->set_ProjectStatus(ui->lineEdit_ProjectStatus->text());

    // Abmasse für das Bauteil
    project->set_ComponentPartX(ui->lineEdit_BTx->text());
    project->set_ComponentPartY(ui->lineEdit_BTy->text());
    project->set_ComponentPartZ(ui->lineEdit_BTz->text());

    // Abmasse für das Rohteil
    project->set_RawPartX(ui->lineEdit_RTx->text());
    project->set_RawPartY(ui->lineEdit_RTy->text());
    project->set_RawPartZ(ui->lineEdit_RTz->text());

    // Nullpunkt
    project->set_ProjectZeroPoint(ui->lineEdit_NP->text());

    // Z Rohteil
    project->set_ZRawPart(QString("%1").arg(ui->doubleSpinBox_ZRohTeil->value()));

    // Vorlage für das Hauptprogramm anhand der Spannung
    switch (ui->comboBox_Clamping->currentIndex())
    {
    case 0:
        project->set_ProjectClamping("Sp0");
        project->set_MainProgramm(QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP0.MPF");
        break;
    case 1:
        project->set_ProjectClamping("Sp1");
        project->set_MainProgramm(QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP1.MPF");
        break;
    case 2:
        project->set_ProjectClamping("Sp2");
        project->set_MainProgramm(QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP2.MPF");
        break;
    case 3:
        project->set_ProjectClamping("Sp3");
        project->set_MainProgramm(QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP3.MPF");
        break;
    case 4:
        project->set_ProjectClamping("Sp4");
        project->set_MainProgramm(QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP4.MPF");
        break;
    case 5:
        project->set_ProjectClamping("Sp5");
        project->set_MainProgramm(QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP5.MPF");
        break;
    default:
        break;
    }

    project->set_ProjectFullName();
    //project->set_RepetitiveManufacturing();

    /* Wenn das maximale Aufmass vom Rohteil definert wurde rechne das Aufmass auf das Bauteil um
       Ansonsten übernimm die Werte aus den SpinBoxen*/
    if(ui->groupBox_AufmassMaxRT->title().contains("Rohteil"))
    {
        double double_AufmassX = (ui->lineEdit_RTx->text().toDouble() -
                                  ui->lineEdit_BTx->text().toDouble()) /2;
        double double_AufmassY = (ui->lineEdit_RTy->text().toDouble() -
                                  ui->lineEdit_BTy->text().toDouble()) /2;

        project->set_XPlus_Max(QString("%1").arg(ui->doubleSpinBox_Xplus_Max->value() + double_AufmassX));
        project->set_XMinus_Max(QString("%1").arg(ui->doubleSpinBox_Xminus_Max->value() + double_AufmassX));
        project->set_YPlus_Max(QString("%1").arg(ui->doubleSpinBox_Yplus_Max->value() + double_AufmassY));
        project->set_YMinus_Max(QString("%1").arg(ui->doubleSpinBox_Yminus_Max->value() + double_AufmassY));
        project->set_ZPlus_Max(QString("%1").arg(ui->doubleSpinBox_Zplus_Max->value() +
                                                 ui->doubleSpinBox_ZRohTeil->value()));
    }
    else
    {
        project->set_XPlus_Max(QString("%1").arg(ui->doubleSpinBox_Xplus_Max->value()));
        project->set_XMinus_Max(QString("%1").arg(ui->doubleSpinBox_Xminus_Max->value()));
        project->set_YPlus_Max(QString("%1").arg(ui->doubleSpinBox_Yplus_Max->value()));
        project->set_YMinus_Max(QString("%1").arg(ui->doubleSpinBox_Yminus_Max->value()));
        project->set_ZPlus_Max(QString("%1").arg(ui->doubleSpinBox_Zplus_Max->value() +
                                                 ui->doubleSpinBox_ZRohTeil->value()));
    }

    project->set_XPlus_Min(QString("%1").arg(ui->doubleSpinBox_Xplus_Min->value()));
    project->set_XMinus_Min(QString("%1").arg(ui->doubleSpinBox_Xminus_Min->value()));
    project->set_YPlus_Min(QString("%1").arg(ui->doubleSpinBox_Yplus_Min->value()));
    project->set_YMinus_Min(QString("%1").arg(ui->doubleSpinBox_Yminus_Min->value()));
    project->set_ZPlus_Min(QString("%1").arg(ui->doubleSpinBox_Zplus_Min->value()));

    project->set_Material(ui->comboBox_Material->currentText());
    project->log_ProjectData();

    //Signal alles OK
    emit sig_AllValid();
}

void Dialog_Project::slot_ClampingChanged(int i)
{
    // Wenn i kleiner als list_Keys.size
    // setzte den Nullpunkt neu
    if(i < list_Keys.size())
        ui->lineEdit_NP->setText(map_NP[list_Keys[i]]);
}

void Dialog_Project::slot_NewInspection(QString str)
{
    ui->label_RohteilKontrolle->setText(str);
}

void Dialog_Project::slot_ShowRawPartInspection()
{
    dialog_RawPartInspection->show();
}
