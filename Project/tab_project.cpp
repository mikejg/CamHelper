#include "tab_project.h"
#include "ui_tab_project.h"

Tab_Project::Tab_Project(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab_Project)
{
    ui->setupUi(this);

    clipboard = QApplication::clipboard();

    ui->scrollArea->set_Layout(ui->verticalLayout_Pictures);
    ui->scrollArea->set_Spacer(ui->verticalSpacer_Pictures);

    ui->lineEdit_RTx->installEventFilter(this);
    ui->lineEdit_RTy->installEventFilter(this);
    ui->lineEdit_RTz->installEventFilter(this);
    ui->lineEdit_BTx->installEventFilter(this);
    ui->lineEdit_BTy->installEventFilter(this);
    ui->lineEdit_BTz->installEventFilter(this);
    ui->lineEdit_NPx->installEventFilter(this);
    ui->lineEdit_NPy->installEventFilter(this);
    ui->lineEdit_NPz->installEventFilter(this);

    // Erzeuge den Zeiger auf MFile
    mfile = new MFile(this);

    fileDialog = new QFileDialog(this);
    fileDialog->setFilter(QDir::Files);

    palette = ui->lineEdit_BTx->palette();
    backroundColor = palette.color(QPalette::Base);
    palette.setColor(QPalette::Base, Qt::darkRed);

    palette_Label = ui->label_RohteilKontrolle->palette();
    forgroundColor = palette_Label.color(ui->label_RohteilKontrolle->foregroundRole());

    ui->lineEdit_BTx->setPalette(palette);
    ui->lineEdit_BTy->setPalette(palette);
    ui->lineEdit_BTz->setPalette(palette);
    ui->lineEdit_RTx->setPalette(palette);
    ui->lineEdit_RTy->setPalette(palette);
    ui->lineEdit_RTz->setPalette(palette);
    ui->lineEdit_NPx->setPalette(palette);
    ui->lineEdit_NPy->setPalette(palette);
    ui->lineEdit_NPz->setPalette(palette);

    // Wird die Spannung geändert, wird auch der Nullpunkt gändert werden
    connect(ui->comboBox_Clamping, SIGNAL(currentIndexChanged(int)), this, SLOT(slot_ClampingChanged(int)));
    connect(ui->toolButton_Programme, SIGNAL(released()), this, SLOT(slot_ShowProgramme()));
    connect(ui->toolButton_Tools, SIGNAL(released()), this, SLOT(slot_ShowTools()));
    // Wird der Button Rohteilkontrolle geklickt erscheint eine Auswahl für die Rohteilkontrolle
    connect(ui->toolButton_RawPartInspection, SIGNAL(released()), this, SLOT(slot_ShowRawPartInspection()));
    connect(ui->toolButton_Tag, SIGNAL(released()), this, SLOT(slot_ShowTags()));
    connect(ui->toolButton_Open, SIGNAL(released()), this, SLOT(slot_OpenPicture()));
    connect(ui->toolButton_Selector, SIGNAL(released()), this, SLOT(slot_NewSelector()));
    connect(ui->toolButton_OpenFile, SIGNAL(released()), this, SLOT(slot_NewHyperMILLFile()));
    connect(ui->toolButton_ExecFile, SIGNAL(released()), this, SLOT(slot_ExecFile()));
    connect(ui->checkBox_RT_EinzelAufmass,SIGNAL(stateChanged(int)), this, SLOT(slot_checkBox_RT_AufmassEinzel_stateChanged(int)));
    connect(ui->checkBox_FT_EinzelAufmass,SIGNAL(stateChanged(int)), this, SLOT(slot_checkBox_FT_AufmassEinzel_stateChanged(int)));
    connect(ui->toolButton_Paste,SIGNAL(released()), this, SLOT(slot_NPPaste()));
}

Tab_Project::~Tab_Project()
{
    delete ui;
}

void Tab_Project::clear()
{
    ui->lineEdit_ProjectName->setText("");
    ui->lineEdit_ProjectStatus->setText("");
    ui->lineEdit_CamFile->setText("");
    ui->textEdit_Comment->clear();

    ui->lineEdit_BTx->setText("");
    ui->lineEdit_BTy->setText("");
    ui->lineEdit_BTz->setText("");

    ui->lineEdit_RTx->setText("");
    ui->lineEdit_RTy->setText("");
    ui->lineEdit_RTz->setText("");

    ui->doubleSpinBox_ZRohTeil->setValue(1);
    ui->scrollArea->clear();
}

bool Tab_Project::check_Project()
{
    bool bool_valid = true;
    QString string_ProjectName;
    QString string_ProjectStatus;

    // Wenn Spannung0 gewaehlt wurde dann
    // überprüfe die Eingabenfelder für Rohteil und Bauteil
    if(ui->comboBox_Clamping->currentIndex() == 0)
    {
        check_LineEdit(ui->lineEdit_RTx, true);
        if(ui->lineEdit_RTx->palette().color(QPalette::Base) == Qt::darkRed)
            bool_valid = false;

        check_LineEdit(ui->lineEdit_RTy, true);
        if(ui->lineEdit_RTx->palette().color(QPalette::Base) == Qt::darkRed)
            bool_valid = false;

        check_LineEdit(ui->lineEdit_RTz, true);
        if(ui->lineEdit_RTz->palette().color(QPalette::Base) == Qt::darkRed)
            bool_valid = false;
    }

    // Wenn Spannung1 gewaehlt wurde dann
    // überprüfe die Eingabenfelder für Rohteil und Bauteil
    if(ui->comboBox_Clamping->currentIndex() == 1)
    {
        check_LineEdit(ui->lineEdit_RTx, true);
        if(ui->lineEdit_RTx->palette().color(QPalette::Base) == Qt::darkRed)
            bool_valid = false;

        check_LineEdit(ui->lineEdit_RTy, true);
        if(ui->lineEdit_RTx->palette().color(QPalette::Base) == Qt::darkRed)
            bool_valid = false;

        check_LineEdit(ui->lineEdit_RTz, true);
        if(ui->lineEdit_RTz->palette().color(QPalette::Base) == Qt::darkRed)
            bool_valid = false;

        check_LineEdit(ui->lineEdit_BTx, true);
        if(ui->lineEdit_BTx->palette().color(QPalette::Base) == Qt::darkRed)
            bool_valid = false;

        check_LineEdit(ui->lineEdit_BTy, true);
        if(ui->lineEdit_BTy->palette().color(QPalette::Base) == Qt::darkRed)
            bool_valid = false;

        check_LineEdit(ui->lineEdit_BTz, true);
        if(ui->lineEdit_BTz->palette().color(QPalette::Base) == Qt::darkRed)
            bool_valid = false;

        if(ui->label_RohteilKontrolle->text() == QString("Rohteilkontrolle"))
        {
            qDebug() << Q_FUNC_INFO << ui->label_RohteilKontrolle->text();
            palette_Label.setColor(ui->label_RohteilKontrolle->foregroundRole(), Qt::darkRed);
            ui->label_RohteilKontrolle->setPalette(palette_Label);
            bool_valid = false;
        }
    }

    check_LineEdit(ui->lineEdit_NPx, true);
    if(ui->lineEdit_NPx->palette().color(QPalette::Base) == Qt::darkRed)
        bool_valid = false;
    check_LineEdit(ui->lineEdit_NPy, true);
    if(ui->lineEdit_NPy->palette().color(QPalette::Base) == Qt::darkRed)
        bool_valid = false;
    check_LineEdit(ui->lineEdit_NPz, true);
    if(ui->lineEdit_NPz->palette().color(QPalette::Base) == Qt::darkRed)
        bool_valid = false;

    // Wenn bis hier ein Fehler aufgetreten brich die Funktion mit
    // false ab
    if(!bool_valid)
    {
        log->error("Project unvollständig");
        return false;
    }
    // Leerzeichen und Unterstrichen im ProjectNamen entfernen
    string_ProjectName = ui->lineEdit_ProjectName->text();
    string_ProjectName = string_ProjectName.replace(" ", "_");
    ui->lineEdit_ProjectName->setText(string_ProjectName);

    // Leerzeichen und Unterstriche im ProjectStatus entfernen
    string_ProjectStatus = ui->lineEdit_ProjectStatus->text();
    string_ProjectStatus = string_ProjectStatus.replace(" ", "_");
    ui->lineEdit_ProjectStatus->setText(string_ProjectStatus);

    //Uebernehme alle Werte in das Project
    project->set_ProjectName(ui->lineEdit_ProjectName->text());
    project->set_ProjectStatus(ui->lineEdit_ProjectStatus->text());
    project->set_CamFile(ui->lineEdit_CamFile->text());

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
    project->set_NPx(ui->lineEdit_NPx->text());
    project->set_NPy(ui->lineEdit_NPy->text());
    project->set_NPz(ui->lineEdit_NPz->text());

    // Z Rohteil
    project->set_ZRawPart(QString("%1").arg(ui->doubleSpinBox_ZRohTeil->value()));

    // Maximal Aufmass aus den Spinboxen
    project->set_XPlus_Max_DB(QString("%1").arg(ui->doubleSpinBox_Xplus_Max->value()));
    project->set_XMinus_Max_DB(QString("%1").arg(ui->doubleSpinBox_Xminus_Max->value()));
    project->set_YPlus_Max_DB(QString("%1").arg(ui->doubleSpinBox_Yplus_Max->value()));
    project->set_YMinus_Max_DB(QString("%1").arg(ui->doubleSpinBox_Yminus_Max->value()));
    project->set_ZPlus_Max_DB(QString("%1").arg(ui->doubleSpinBox_Zplus_Max->value()));

    // Vorlage für das Hauptprogramm anhand der Spannung
    switch (ui->comboBox_Clamping->currentIndex())
    {
    case 0:
        project->set_ProjectClamping("Sp0");
        break;
    case 1:
        project->set_ProjectClamping("Sp1");
        break;
    case 2:
        project->set_ProjectClamping("Sp2");
        break;
    case 3:
        project->set_ProjectClamping("Sp3");
        break;
    case 4:
        project->set_ProjectClamping("Sp4");
        break;
    case 5:
        project->set_ProjectClamping("Sp5");
        break;
    default:
        break;
    }

    project->set_ProjectZeroPoint(ui->lineEdit_NP->text());
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

    project->set_Comment(ui->textEdit_Comment->toPlainText());
    //Schreibe die neuen Projectdaten in Tab Log
    //project->log_ProjectData();

    return true;
}

bool Tab_Project::eventFilter(QObject *object, QEvent *event)
{
    double double_NPz;
    if(ui->comboBox_Clamping->currentIndex() == 0)
    {
        if(object == ui->lineEdit_RTx)
            check_LineEdit(ui->lineEdit_RTx, true);

        if(object == ui->lineEdit_RTy)
            check_LineEdit(ui->lineEdit_RTy, true);

        if(object == ui->lineEdit_RTz)
            check_LineEdit(ui->lineEdit_RTz, true);
    }

    if(ui->comboBox_Clamping->currentIndex() == 1)
    {
        if(object == ui->lineEdit_BTx)
            check_LineEdit(ui->lineEdit_BTx, true);

        if(object == ui->lineEdit_BTy)
            check_LineEdit(ui->lineEdit_BTy, true);

        if(object == ui->lineEdit_BTz)
            check_LineEdit(ui->lineEdit_BTz, true);

        if(object == ui->lineEdit_RTx)
            check_LineEdit(ui->lineEdit_RTx, true);

        if(object == ui->lineEdit_RTy)
            check_LineEdit(ui->lineEdit_RTy, true);

        if(object == ui->lineEdit_RTz)
        {
            check_LineEdit(ui->lineEdit_RTz, true);
        }
    }

    if(ui->comboBox_Clamping->currentIndex() > 0 )
    {
        if(object == ui->lineEdit_NPx)
            check_LineEdit(ui->lineEdit_NPx, true);

        if(object == ui->lineEdit_NPy)
            check_LineEdit(ui->lineEdit_NPy, true);

        if(object == ui->lineEdit_NPz)
            check_LineEdit(ui->lineEdit_NPz, true);
    }
    return false;
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

bool Tab_Project::load_Material()
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

void Tab_Project::load_ProjectData()
{
    Item_Project item_Project;
    QString string_ProjectID;

    //Lade Projektdaten aus der Datenbank und fülle die Felder aus
    item_Project = database->get_Project(project->get_ProjectName(), project->get_ProjectClamping());

    project->set_Material(item_Project.Material);
    project->set_RawPartX(item_Project.RawPart_X);
    project->set_RawPartY(item_Project.RawPart_Y);
    project->set_RawPartZ(item_Project.RawPart_Z);
    project->set_ComponentPartX(item_Project.Component_X);
    project->set_ComponentPartY(item_Project.Component_Y);
    project->set_ComponentPartZ(item_Project.Component_Z);
    project->set_ZRawPart(item_Project.ZRawPart);
    project->set_RawPartInspection(item_Project.RawPartInspection);
    project->set_CamFile(item_Project.CamFile);
    project->set_LastProduction(item_Project.Last_Production);
    project->set_XPlus_Max_DB(item_Project.XPlus_Max);
    project->set_XMinus_Max_DB(item_Project.XMinus_Max);
    project->set_YPlus_Max_DB(item_Project.YPlus_Max);
    project->set_YMinus_Max_DB(item_Project.YMinus_Max);
    project->set_ZPlus_Max_DB(item_Project.ZPlus_Max);
    project->set_NPx(item_Project.NPx);
    project->set_NPy(item_Project.NPy);
    project->set_NPz(item_Project.NPz);

    //Wenn in der Datenbank ein Comment war dann übernehme den Comment
    //ansonsten wird der Voreingestellte Comment beibehalten
    if(!item_Project.Comment.isEmpty())
       project->set_Comment(item_Project.Comment);

    //Wenn es keine ID gibt bricht hier ab
    string_ProjectID = item_Project.id;
    if(string_ProjectID.isEmpty())
        return;

    //OK es gibt eine ID, lade TouchProbe
    QList<Item_TouchProbe> list = database->get_TouchProbe(string_ProjectID);

    //lade Bilder aus der Datenbank
    QList<QPixmap> pixmapList = database->get_Pixmap(string_ProjectID);
    foreach (QPixmap pix, pixmapList)
    {
        slot_NewPixmap(pix);
    }

    // Setze die Liste mit den TouchProbe im Projekt
    // Die Liste wird in CamHelper::slot_NewProject() abgearbeitet
    project->set_ListTouchProbe(list);
}

bool Tab_Project::load_ZeroPoint()
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

void Tab_Project::set_ProjectData()
{
    // Erzeuge den Zeiger auf Dialog_RohteilKontrolle
    // Verbinde das Signal für eine neu Auswahl mit dem Slot
    // slot_NewInspection(QString)
    dialog_RawPartInspection = new Dialog_RawPartInspection(this, project);
    connect(dialog_RawPartInspection, SIGNAL(sig_NewInspection(QString)),
            this,   SLOT(slot_NewInspection(QString)));

    // Erzeuge den Zeiger auf Dialog_Tags und befülle den Dialog mit den
    // gesetzten Tags
    dialog_Tag = new Dialog_Tag(this, project, database);

    dialog_Programm = new Dialog_Programm(this, project);

    dialog_Tools = new Dialog_Tools(this, project);

    // Befülle Eingabefelder mit den Werten aus dem Project
    ui->lineEdit_ProjectName->setText(project->get_ProjectName());
    ui->lineEdit_ProjectStatus->setText(project->get_ProjectStatus());
    ui->lineEdit_CamFile->setText(project->get_CamFile());
    ui->textEdit_Comment->append(project->get_Comment());

    ui->lineEdit_RTx->setText(project->get_RawPartX());
    ui->lineEdit_RTy->setText(project->get_RawPartY());
    ui->lineEdit_RTz->setText(project->get_RawPartZ());

    ui->lineEdit_BTx->setText(project->get_ComponentPartX());
    ui->lineEdit_BTy->setText(project->get_ComponentPartY());
    ui->lineEdit_BTz->setText(project->get_ComponentPartZ());

    if(project->get_NPx() != "-999")
        ui->lineEdit_NPx->setText(project->get_NPx());
    else
        ui->lineEdit_NPx->setText("");
    if(project->get_NPy() != "-999")
        ui->lineEdit_NPy->setText(project->get_NPy());
    else
        ui->lineEdit_NPy->setText("");
    if(project->get_NPz() != "-999")
        ui->lineEdit_NPz->setText(project->get_NPz());
    else
        ui->lineEdit_NPz->setText("");

    ui->label_RohteilKontrolle->setText(project->get_RawPartInspection());
    ui->doubleSpinBox_ZRohTeil->setValue(project->get_ZRawPart().toDouble());
    ui->comboBox_Material->setCurrentText(project->get_Material());

    QString string_Clamping = project->get_ProjectClamping();
    if(string_Clamping == "SP0" || string_Clamping == "Sp0" || string_Clamping == "sp0")
    {
        ui->comboBox_Clamping->setCurrentText(list_Keys[0]);
        ui->lineEdit_NP->setText(map_NP[list_Keys[0]]);
        palette.setColor(QPalette::Base, backroundColor);
        ui->lineEdit_BTx->setPalette(palette);
        ui->lineEdit_BTy->setPalette(palette);
        ui->lineEdit_BTz->setPalette(palette);
    }

    if(string_Clamping == "SP1" || string_Clamping == "Sp1" || string_Clamping == "sp1")
    {
        ui->comboBox_Clamping->setCurrentText(list_Keys[1]);
        ui->lineEdit_NP->setText(map_NP[list_Keys[1]]);
        if(ui->label_RohteilKontrolle->text() == QString("Rohteilkontrolle"))
        {
            palette_Label.setColor(ui->label_RohteilKontrolle->foregroundRole(), Qt::darkRed);
            ui->label_RohteilKontrolle->setPalette(palette_Label);
        }
    }

    if(string_Clamping == "SP2" || string_Clamping == "Sp2" || string_Clamping == "sp2")
    {
        ui->comboBox_Clamping->setCurrentText(list_Keys[2]);
        ui->lineEdit_NP->setText(map_NP[list_Keys[2]]);
        palette.setColor(QPalette::Base, backroundColor);
        ui->lineEdit_BTx->setPalette(palette);
        ui->lineEdit_BTy->setPalette(palette);
        ui->lineEdit_BTz->setPalette(palette);

        ui->lineEdit_RTx->setPalette(palette);
        ui->lineEdit_RTy->setPalette(palette);
        ui->lineEdit_RTz->setPalette(palette);
    }

    if(string_Clamping == "SP3" || string_Clamping == "Sp3" || string_Clamping == "sp3")
    {
        ui->comboBox_Clamping->setCurrentText(list_Keys[3]);
        ui->lineEdit_NP->setText(map_NP[list_Keys[3]]);

        palette.setColor(QPalette::Base, backroundColor);
        ui->lineEdit_BTx->setPalette(palette);
        ui->lineEdit_BTy->setPalette(palette);
        ui->lineEdit_BTz->setPalette(palette);

        ui->lineEdit_RTx->setPalette(palette);
        ui->lineEdit_RTy->setPalette(palette);
        ui->lineEdit_RTz->setPalette(palette);
    }

    // Nullpunkt setzen
    project->set_ProjectZeroPoint(ui->lineEdit_NP->text());

    if(project->get_MaxOverSize())
    {
        ui->groupBox_AufmassMaxRT->setTitle("Aufmass Max vom Bauteil");
    }

    ui->doubleSpinBox_Xplus_Max->setValue(project->get_XPlus_Max_DB().toDouble());
    ui->doubleSpinBox_Xminus_Max->setValue(project->get_XMinus_Max_DB().toDouble());
    ui->doubleSpinBox_Yplus_Max->setValue(project->get_YPlus_Max_DB().toDouble());
    ui->doubleSpinBox_Yminus_Max->setValue(project->get_YMinus_Max_DB().toDouble());
    ui->doubleSpinBox_Zplus_Max->setValue(project->get_ZPlus_Max_DB().toDouble());

    if(ui->doubleSpinBox_Xplus_Max->value() != ui->doubleSpinBox_RT_All->value() ||
       ui->doubleSpinBox_Xminus_Max->value() != ui->doubleSpinBox_RT_All->value() ||
       ui->doubleSpinBox_Yplus_Max->value() != ui->doubleSpinBox_RT_All->value() ||
       ui->doubleSpinBox_Yminus_Max->value() != ui->doubleSpinBox_RT_All->value() ||
       ui->doubleSpinBox_Zplus_Max->value() != ui->doubleSpinBox_RT_All->value())
    {
        ui->checkBox_RT_EinzelAufmass->setChecked(true);
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
}

void Tab_Project::slot_ClampingChanged(int i)
{
    // Wenn i kleiner als list_Keys.size
    // setzte den Nullpunkt neu
    if(i < list_Keys.size())
        ui->lineEdit_NP->setText(map_NP[list_Keys[i]]);
}

void Tab_Project::slot_ShowProgramme()
{
    dialog_Programm->show();
}

void Tab_Project::slot_ShowRawPartInspection()
{
    dialog_RawPartInspection->show();
}

void Tab_Project::slot_ShowTags()
{
    dialog_Tag->show();
}

void Tab_Project::slot_ShowTools()
{
    dialog_Tools->show();
}

void Tab_Project::slot_NewInspection(QString str)
{
    ui->label_RohteilKontrolle->setText(str);
    if(ui->label_RohteilKontrolle->text() != QString("Rohteilkontrolle"))
    {
        palette_Label.setColor(ui->label_RohteilKontrolle->foregroundRole(), forgroundColor);
        ui->label_RohteilKontrolle->setPalette(palette_Label);
    }
}

void Tab_Project::slot_OpenPicture()
{
    QString string_File;
    fileDialog->setNameFilter(tr("Images (*.png)"));
    string_File = fileDialog->getOpenFileName();
    if(string_File.isEmpty())
        return;

    ui->scrollArea->insert_Pixmap(string_File);
}

void Tab_Project::slot_NewHyperMILLFile()
{
   fileDialog->setNameFilter(tr("HyperMILL (*.hmc)"));
    ui->lineEdit_CamFile->setText(fileDialog->getOpenFileName());
}

void Tab_Project::slot_NPPaste()
{
    Settings* settings = project->get_Settings();

    float float_OffsetX = settings->get_OffsetX();
    float float_OffsetY = settings->get_OffsetY();
    float float_OffsetZ = settings->get_OffsetZ();
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

    ui->lineEdit_NPx->setText(QString::number(float_NPx, 'f', 2));
    ui->lineEdit_NPy->setText(QString::number(float_NPy, 'f', 2));
    ui->lineEdit_NPz->setText(QString::number(float_NPz, 'f', 2));

    //qDebug() << Q_FUNC_INFO << float_NPx << float_NPy << float_NPz;
}

void Tab_Project::slot_ExecFile()
{
    QString url = ui->lineEdit_CamFile->text();
    if(url.isEmpty())
        return;

    QDesktopServices::openUrl(QUrl::fromLocalFile(url)); //(url, QUrl::TolerantMode));
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

void Tab_Project::slot_RefreshTools()
{
    qDebug() << Q_FUNC_INFO;

    if(dialog_Tools != nullptr)
    {
        dialog_Tools->refresh();
    }
}
QList<MLabel*> Tab_Project::get_PictureList()
{
    return ui->scrollArea->get_PictureList();
}

void Tab_Project::slot_checkBox_RT_AufmassEinzel_stateChanged(int state)
{
    Q_UNUSED(state);
    if(ui->checkBox_RT_EinzelAufmass->isChecked())
    {
        ui->widget_RT_AufmassEinzel->show();
    }
    else
    {
        ui->widget_RT_AufmassEinzel->hide();
    }
}

void Tab_Project::slot_checkBox_FT_AufmassEinzel_stateChanged(int state)
{
    Q_UNUSED(state);
    if(ui->checkBox_FT_EinzelAufmass->isChecked())
    {
        ui->widget_FT_AufmassEinzel->show();
    }
    else
    {
        ui->widget_FT_AufmassEinzel->hide();
    }
}

void Tab_Project::check_LineEdit(QLineEdit* lineEdit, bool bool_Unsigned)
{
    double double_Value;
    QString string_Text = lineEdit->text();
    if(string_Text.contains(","))
    {
        string_Text = string_Text.replace("," , ".");
        lineEdit->setText(string_Text);
    }
    bool bool_ok;
    double_Value = lineEdit->text().toDouble(&bool_ok);

    //Wenn die Konvertierung des Strings zu Double erfolgreich war setze die normale
    //Hintergrundfarbe. Wenn sie fehlschlägt setze Rot
    if(bool_ok)
        palette.setColor(QPalette::Base, backroundColor);
    else
        palette.setColor(QPalette::Base, Qt::darkRed);

    // Wenn die Konvertierung geklappt hat, aber der Wert
    // kein Vorzeichen haben soll, der Wert aber ein Vorzeichen hat
    // weil der Wert kleiner 0 ist
    // dann setze Rot.
    if(bool_ok && bool_Unsigned && double_Value < 0)
    {
        palette.setColor(QPalette::Base, Qt::darkRed);
    }
    lineEdit->setPalette(palette);
}
