#include "camhelper.h"
#include "ui_camhelper.h"

CamHelper::CamHelper(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CamHelper)
{
    ui->setupUi(this);

    // Tab_Project
    tab_Project = ui->tab_Project;
    tab_Project->installEventFilter(this);

    // Dialog_Progress
    dialog_Progress = new Dialog_Progress(this);

    // Highlighter
    highLighter = new HighLighter(ui->textEdit->document());

    // ui->tableView_Programme->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    //Rüstplan
    ui->tableView_Rustplan->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    connect(ui->tableView_Rustplan, SIGNAL(clicked(const QModelIndex &)), this, SLOT(slot_TableClicked(const QModelIndex &)));

    //Dialog_Repetition
    dialog_Repetition = new Dialog_Repetition(this);
    connect(dialog_Repetition, SIGNAL(accepted()), this, SLOT(slot_RepetitionAccepted()));

    QToolBar *toolbar = this->addToolBar("main toolbar");
    action_Open = toolbar->addAction(QIcon(":/Icons/File_Open.png"),"Project öffnen");
    action_New = toolbar->addAction(QIcon(":Icons/new.png"),"Neues Project");
    action_Save = toolbar->addAction(QIcon(":/Icons/save.png"),"Projekt speichern");
    action_Export = toolbar->addAction(QIcon(":/Icons/export.png"),"Packet Exportieren");
    action_Print = toolbar->addAction(QIcon(":/Icons/print.png"),"Rüstplan Drucken");
    action_Check = toolbar->addAction(QIcon(":/Icons/checklist.png"),"Einzelne Files Checken");
    action_Settings = toolbar->addAction(QIcon(":/Icons/settings.png"),"Einstellungen");

    connect(action_Export, SIGNAL(triggered(bool)), this, SLOT(slot_Export(bool)));
    connect(action_Save,   SIGNAL(triggered(bool)), this, SLOT(slot_Save(bool)));
    connect(action_Print,  SIGNAL(triggered(bool)), this, SLOT(slot_Print(bool)));
    connect(action_Check,  SIGNAL(triggered(bool)), this, SLOT(slot_CheckFiles(bool)));
    connect(action_Settings,  SIGNAL(triggered(bool)), this, SLOT(slot_Settings(bool)));
    connect(action_New, SIGNAL(triggered(bool)), this, SLOT(slot_NewProject()));

    action_Save->setEnabled(false);
    action_Export->setEnabled(false);
    action_Print->setEnabled(false);
    action_Open->setEnabled(false);
    action_New->setEnabled(false);

    bool_PrintIn         = true;
    bool_PrintOut        = true;
    bool_PrintProject    = true;

    toolList_IN          = new ToolList(this);
    toolList_OUT         = new ToolList(this);
    toolList_Table       = new ToolList(this);


    QTimer::singleShot(500,this,SLOT(slot_startApplication()));
}

CamHelper::~CamHelper()
{
    delete ui;
}

bool CamHelper::eventFilter(QObject *obj, QEvent *ev)
{
    if(obj == ui->tab_Project && ev->type() == QEvent::Leave)
    {
        tab_Project->check_Project();
        ui->textEdit->clear();
        mfile->setFileName(project->get_MainProgramm());
        if(!mfile->read_Content()) return false;

        /* ersetze im Hauptprogramm die Platzhalter */
        QStringList stringList_Content = parser_PlaceHolder->set_PlaceHolder_MainProgramm(mfile->get_Content());
        // schreibe alles in textEdit
        foreach(QString str, stringList_Content)
        {
            ui->textEdit->append(str);
        }
        ui->textEdit->moveCursor (QTextCursor::Start) ;
    }
    return true;
}

bool CamHelper::load_Programme(QStringList &stringList_Programme)
{
    /* Erzeuge dir und setze den Pfad auf string_ProgrammDir
     * setz den Filter auf SPF-Dateien */
    QDir dir;
    QStringList filters;
    dir.setPath(settings->get_ProgrammDir());
    filters << "*.spf";
    dir.setNameFilters(filters);

    /* Variable die ich später noch brauche */
    QString string_shortName;
    bool bool_OK;
    int int_I;  Q_UNUSED(int_I);

    /* Lösche alle Programme aus stringList_Programme */
    stringList_Programme.clear();

    stringList_Programme = dir.entryList(QDir::Files);

    /*Erzeuge eine temporäre StringList tmp
     * geh durch stringList_Programme
     * wenn der Eintrag mit 1_ - 9_ stratet setze eine 0 davor
     * Überprüfe die länge des Progammnamens abhängig ob
     *  eine Nummerierung vorgesehen ist oder nicht
     * schreibe den Eintrag in tmp*/
    QStringList tmp;
    foreach(QString str, stringList_Programme)
    {
        if (str.startsWith("1_") || str.startsWith("2_") || str.startsWith("3_") ||
            str.startsWith("4_") || str.startsWith("5_") || str.startsWith("6_") ||
            str.startsWith("7_") || str.startsWith("8_") || str.startsWith("9_") )
        {
            dir.rename(str, "0"+str);
            str = "0" + str;
        }

        if(!settings->get_Numbering() && str.length() > 31)
        {
            if(str.startsWith("0"))
            {
                str = str.right(str.length()-1);
                dir.rename("0"+ str, str);
            }
            stringList_Log.clear();
            stringList_Log.append("Datei: " + str + " zu lang");
            stringList_Log.append(" - Loeschen Sie die Datei");
            stringList_Log.append(" - Kürzen Sie den Komponentenjob");
            stringList_Log.append(" - Spielen sie die Datei neu aus");
            stringList_Log.append(" - Starten Sie die Applikation neu");
            logging->frame_Error(stringList_Log);
            return false;
        }

        if(settings->get_Numbering() && str.length() > 28)
        {
            qDebug() << str << ": " << str.length();
            if(str.startsWith("0"))
            {
                str = str.right(str.length()-1);
                dir.rename("0"+ str, str);
            }
            stringList_Log.clear();
            stringList_Log.append("Datei: " + str + " zu lang");
            stringList_Log.append(" - Loeschen Sie die Datei");
            stringList_Log.append(" - Kürzen Sie den Komponentenjob");
            stringList_Log.append(" - Spielen sie die Datei neu aus");
            stringList_Log.append(" - Starten Sie die Applikation neu");
            logging->frame_Error(stringList_Log);
            return false;
        }

        tmp.append(str);
    }

    /* Sortiere tmp
     * Lösche alle Einträge in stringList_Programme
     * geht durch tmp
     * Schreibe alle Einträge von tmp in stringListProgramme*/
    tmp.sort();
    stringList_Programme.clear();

    foreach(QString str, tmp)
    {
        /* Wenn keine Nummerierung der Programme vorgesehen ist */
    if(!settings->get_Numbering())
    {
        /* Kopiere str nach string_shortName */
        string_shortName = str;

        /* Überprüfe ob das erste Zeichen von string_shortName eine
             * Zahl ist. Das Ergebniss wird in bool_OK gespeichert */
        int_I = string_shortName.left(1).toInt(&bool_OK, 10);

        while(bool_OK)
        {
            /* Lösche das erste Zeichen von string_shortName */
                string_shortName = string_shortName.right(string_shortName.length()-1);

                /* Überprüfe ob das erste Zeichen von string_shortName eine Zahl ist */
            int_I = string_shortName.left(1).toInt(&bool_OK, 10);

            /* Wenn das erste Zeichen ein '_' ist wird bool_OK auf true gesetzt */
            if(string_shortName.startsWith("_"))
                bool_OK = true;
        }

        /* Benenne das SPF-File um */
        dir.rename(str, string_shortName);

        /* trage string_shortName in stringList_Progamme ein */
        stringList_Programme.append(string_shortName);
    }
    else
    {
        /* trage str in d stringList_Programme ein */
        stringList_Programme.append(str);
    }
}
return true;
}

void CamHelper::showTable_Rustplan(bool bool_Print)
{
    /* Vorbereitung für den Rüstplan */
    toolList_IN->clear();
    toolList_OUT->clear();
    toolList_Table->clear();

    list_ToolID.clear();
    list_ToolDescription.clear();
    list_GageLength.clear();
    list_ToolLength.clear();
    list_TipLength.clear();
    list_Counter.clear();

    int int_Projects_Size;
    int int_In_Size;
    int int_Out_Size;
    int int_Free_Size;
    int int_Counter = 0;

    //Kopiere die ToolList aus dem Projekt in toolList_Table
    //sortiere toolList_Table nach der Tool_ID
    foreach(Tool* tool, project->get_ToolList()->get_List())
        toolList_Table->insert_Tool(tool);
    toolList_Table->sort_ID();

    int_Projects_Size = project->get_ToolList()->get_Size();

    foreach(Tool* tool, toolList_Table->get_List())
    {
        if(!magazin->contains(tool))
            toolList_IN->insert_Tool(tool);
    }
    int_In_Size = toolList_IN->get_Size();

    //Vergleiche Werkzeugmagazin mit Top100 und Projekt
    foreach(Tool* tool, magazin->get_ToolList()->get_List())
    {
        if(!toolList_Top100->contains(tool) &&
            !toolList_Table->contains(tool) &&
            tool->get_State() == Tool::In)
            toolList_OUT->insert_Tool(tool);
    }
    toolList_OUT->sort_Counter();
    int_Out_Size = toolList_OUT->get_Size();

    /* Wenn bool_Print = false ODER bool_PrintProject = true
     * dann wird die Kopfzeile für das Projekt angezeig.
     * Das bedeutet, wenn ein Druckauftrag ansteht und das Projekt
     * ausgebledet werden soll wird die Kopfzeile ignoriert */
    if(!bool_Print || bool_PrintProject)
    {
        //erzeuge erste Zeile mit ProjektNamen und Anzahl der verwendeten Werkzeuge
        list_ToolDescription.append(QString(project->get_ProjectFullName() + "  %1 Werkzeuge").arg(int_Projects_Size));
        list_ToolID.append(" ");
        list_GageLength.append(" ");
        list_ToolLength.append(" ");
        list_TipLength.append(" ");
        list_Counter.append(" ");
    }

    /* Zeige die Werkzeuge für das Projekt nur an wenn bool_PrintProject = true
     * bool_PrintProject wird im slot_TableClicked(const QModelIndex &)
     * gesteuert. Wenn man auf die Kopfzeile klickt wird bool_PrintProject
     * umgeschalten */
    if(bool_PrintProject)
    {
        //Füge die Werkzeuge ein
        foreach(Tool* tool, toolList_Table->get_List())
        {
            int_Counter++;
            list_Counter.append(QString("%1").arg(int_Counter));
            list_ToolDescription.append(tool->get_Description());
            list_ToolID.append(tool->get_Number());
            list_GageLength.append(tool->get_GageLength());
            list_ToolLength.append(tool->get_ToolLength());
            list_TipLength.append(tool->get_TipLength());
        }

        //erzeuge eine Leerzeile
        list_ToolDescription.append(" ");
        list_ToolID.append(" ");
        list_GageLength.append(" ");
        list_ToolLength.append(" ");
        list_TipLength.append(" ");
        list_Counter.append(" ");
    }

    /* Dokumentation Siehe oben
     * if(!bool_Print || bool_PrintProject) */
    if(!bool_Print || bool_PrintIn)
    {
        //erzeuge eine Zeile: 10 Werkzeuge EINLAGERN - 15 Freie Plätze im Magazin"
        int_Free_Size = settings->get_WerkzeugPlatze() - magazin->get_Size();
        list_ToolDescription.append(QString("  %1 Werkzeuge EINLAGERN  -  %2 Frei Plätze im Magazin").arg(int_In_Size).arg(int_Free_Size));
            list_ToolID.append(" ");
        list_GageLength.append(" ");
        list_ToolLength.append(" ");
        list_TipLength.append(" ");
        list_Counter.append(" ");
    }

    /* Dokumentation Siehe oben
     * if(bool_PrintProject) */
    if(bool_PrintIn)
    {
        //Füge alle Werkzeuge aus der toolList_IN ein
        foreach(Tool* tool, toolList_IN->get_List())
        {
            int_Counter++;
            list_Counter.append(QString("%1").arg(int_Counter));
            list_ToolDescription.append(tool->get_Description());
            list_GageLength.append(tool->get_GageLength());
            list_ToolLength.append(tool->get_ToolLength());
            list_TipLength.append(tool->get_TipLength());

            //qDebug() << tool->get_Number() << ": " << tool->get_State();
            if(tool->get_State() == Tool::Disassembled)
            {
                list_ToolID.append(tool->get_Number() + "_X");
            }
            else
                list_ToolID.append(tool->get_Number());
        }

        //erzeuge eine Leerzeile
        list_ToolDescription.append(" ");
        list_ToolID.append(" ");
        list_GageLength.append(" ");
        list_ToolLength.append(" ");
        list_TipLength.append(" ");
        list_Counter.append(" ");
    }

    /* Dokumentation Siehe oben
     * if(!bool_Print || bool_PrintProject) */
    if(!bool_Print || bool_PrintOut)
    {
        //erzeuge eine Zeile: 15 Werkzeuge Auslagen
        list_ToolDescription.append(QString("  %1 Werkzeuge AUSLAGERN ").arg(int_Out_Size));
        list_ToolID.append(" ");
        list_GageLength.append(" ");
        list_ToolLength.append(" ");
        list_TipLength.append(" ");
        list_Counter.append(" ");
    }

    /* Dokumentation Siehe oben
     * if(bool_PrintProject) */
    if(bool_PrintOut)
    {
        //Füge alle Werkzeuge aus der toolList_Out ein
        foreach(Tool* tool, toolList_OUT->get_List())
        {
            int_Counter++;
            list_Counter.append(QString("%1").arg(int_Counter));
            list_ToolDescription.append(tool->get_Description());
            list_ToolID.append(tool->get_Number());
            list_GageLength.append(tool->get_GageLength());
            list_ToolLength.append(tool->get_ToolLength());
            list_TipLength.append(QString("%1").arg(tool->get_Counter()));
        }
    }

    tableModel = new TableModel(this);

    // Populate model with data:
    tableModel->populateData(list_ToolID,
                             list_ToolDescription,
                             list_GageLength,
                             list_ToolLength,
                             list_TipLength,
                             list_Counter);

    //Wenn kein Druckauftrag besteht zeige das Model im TableView an
    if(!bool_Print)
    {
        ui->tableView_Rustplan->setModel(tableModel);
        ui->tableView_Rustplan->show();
    }
}

void CamHelper::slot_CheckFiles()
{
    QStringList stringList_Programme;
    Item_Programm item_Programm;
    QStringList stringList_Project;
    QString string_Project;
    QString string_Clamping;
    QString string_ProjectID;

    if(!parser_Programm->loadBruch())
        return;

    if(!load_Programme(stringList_Programme))
        return;

    ui->tabWidget->setCurrentWidget(ui->tab_Log);
    foreach (QString string_Programm, stringList_Programme)
    {
        item_Programm.Programm = string_Programm;
        string_Project = parser_Programm->parse_ProjectName(settings->get_ProgrammDir()+ "/" + string_Programm);
        string_Project = string_Project.remove(" ||");
        qDebug() << string_Project;
        stringList_Project = string_Project.split("_");
        if(stringList_Project.size() > 2)
        {
            string_Project = stringList_Project.at(0);
            string_Clamping = stringList_Project.at(2);
            string_ProjectID = dataBase->get_ProjectID(string_Project, string_Clamping);
            item_Programm = dataBase->get_ItemProgramm(string_ProjectID, string_Programm);
        }
        parser_Programm->finish(settings->get_ProgrammDir()+ "/" + string_Programm, item_Programm);
    }

}

void CamHelper::slot_CheckFiles(bool b)
{
    Q_UNUSED(b);
    slot_CheckFiles();
}

void CamHelper::slot_DialogPrintFinished(int result)
{
    //qDebug() << Q_FUNC_INFO;
    Q_UNUSED(result);
    showTable_Rustplan();
}

void CamHelper::slot_DialogProjectClosed()
{
    dialog_Project->hide();

    /* setze mfile den Pfad für das Hauptprogramm
     * lese das Hauptprogramm ein
     * wenn es einen Fehler beim einlesen gibt verlasse die Funktion */
    mfile->setFileName(project->get_MainProgramm());
    if(!mfile->read_Content()) return;

    /* ersetze im Hauptprogramm die Platzhalter */
    QStringList stringList_Content = parser_PlaceHolder->set_PlaceHolder_MainProgramm(mfile->get_Content());

    foreach(QString str, stringList_Content)
    {
        ui->textEdit->append(str);
    }
    //erstelle den Ruestplan
    showTable_Rustplan();

    touchProbe->insert_Item(project->get_ListTouchProbe());

    action_Save->setEnabled(true);
    action_Export->setEnabled(true);
    action_Print->setEnabled(true);
}

void CamHelper::slot_Export(bool b)
{
    Q_UNUSED(b);
    QString string_ProjectID;

    if(!tab_Project->check_Project())
    {
        logging->error("Fehlerhafter Project");
        ui->tabWidget->setCurrentIndex(0);
        return;
    }

    project->set_ContentMainProgramm(ui->textEdit);
    project->set_TPItemList(touchProbe->get_ItemList());

    // Versuche die ProjectID des Projects aus der Datenbank zu holen
    string_ProjectID = dataBase->get_ProjectID(project->get_ProjectName(),
                                               project->get_ProjectClamping());

    //qDebug() << string_ProjectID;
    // wenn es keine ProjectID gibt, gibt es das Project noch nicht
    // speicher das Project und exportiere das Project
    if(string_ProjectID.isEmpty())
    {
        project->set_TPItemList(touchProbe->get_ItemList());
        project->set_LastProduction(QDateTime::currentDateTime().toString(Qt::ISODate));
        project->save();
        project_Export->slot_ExportProject(true);
    }

    else
    {
        dialog_Repetition->set_LastProduction(project->get_LastProduction());
        dialog_Repetition->show();
    }
}

void CamHelper::slot_LicenseFaild()
{
    ui->tabWidget->setCurrentWidget(ui->tab_Log);

    QTimer::singleShot(5000, this, SLOT(close()));
}

void CamHelper::slot_LoadProject(QString string_Project, QString string_Clamping)
{
    //erzeuge einen neuen Zeiger für das Project und übergib ihn den nötigen Klassen
    new_Project();

    Item_Project item_Project = dataBase->get_FullProject(string_Project, string_Clamping);

    project->set_ProjectName(item_Project.Name);
    project->set_ProjectStatus(item_Project.Status);
    project->set_ProjectClamping(item_Project.Clamping);
    project->set_ProjectZeroPoint(item_Project.ZeroPoint);
    project->set_CamFile(item_Project.CamFile);
    project->set_Comment(item_Project.Comment);

    project->set_ProjectFullName();

    project->set_RawPartInspection(item_Project.RawPartInspection);

    project->set_RawPartX(item_Project.RawPart_X);
    project->set_RawPartY(item_Project.RawPart_Y);
    project->set_RawPartZ(item_Project.RawPart_Z);

    project->set_ComponentPartX(item_Project.Component_X);
    project->set_ComponentPartY(item_Project.Component_Y);
    project->set_ComponentPartZ(item_Project.Component_Z);

    project->set_ZRawPart(item_Project.ZRawPart);
    project->set_Material(item_Project.Material);

    project->set_LastProduction(item_Project.Last_Production);
    project->set_XPlus_Max_DB(item_Project.XPlus_Max);
    project->set_XMinus_Max_DB(item_Project.XMinus_Max);
    project->set_YPlus_Max_DB(item_Project.YPlus_Max);
    project->set_YMinus_Max_DB(item_Project.YMinus_Max);
    project->set_ZPlus_Max_DB(item_Project.ZPlus_Max);

    //setze QList<Item_ProgrammProject>
    project->set_Programms(item_Project.list_Programme);

    project->set_NCTools();

    //erstelle den Ruestplan
    showTable_Rustplan();

    if(project->get_ProjectClamping() == "Sp0")
        project->set_MainProgramm(QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP0.MPF");
    if(project->get_ProjectClamping() == "Sp1")
        project->set_MainProgramm(QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP1.MPF");
    if(project->get_ProjectClamping() == "Sp2")
        project->set_MainProgramm(QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP2.MPF");
    if(project->get_ProjectClamping() == "Sp3")
        project->set_MainProgramm(QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP3.MPF");
    if(project->get_ProjectClamping() == "Sp4")
        project->set_MainProgramm(QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP4.MPF");
    if(project->get_ProjectClamping() == "Sp5")
        project->set_MainProgramm(QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP5.MPF");

    /* setze mfile den Pfad für das Hauptprogramm
     * lese das Hauptprogramm ein
     * wenn es einen Fehler beim einlesen gibt verlasse die Funktion */
    //qDebug() << "MainProgramm" << project->get_MainProgramm();
    mfile->setFileName(project->get_MainProgramm());
    if(!mfile->read_Content()) return;

    /* ersetze im Hauptprogramm die Platzhalter */
    QStringList stringList_Content = parser_PlaceHolder->set_PlaceHolder_MainProgramm(mfile->get_Content());

    // schreibe alles in textEdit
    foreach(QString str, stringList_Content)
    {
        ui->textEdit->append(str);
    }
    //scrolle ganz nach oben
    ui->textEdit->moveCursor (QTextCursor::Start) ;

    QList<Item_TouchProbe> list = dataBase->get_TouchProbe(item_Project.id);
    project->set_ListTouchProbe(list);
    touchProbe->insert_Item(project->get_ListTouchProbe());

    QList<QPixmap> pixmap_List = dataBase->get_Pixmap(item_Project.id);
    foreach(QPixmap pix, pixmap_List)
    {
        ui->tab_Project->slot_NewPixmap(pix);
    }

    project->log_ProjectData();
    tab_Project->set_ProjectData();


    action_Save->setEnabled(true);
    action_Export->setEnabled(true);
    action_Print->setEnabled(true);
    action_Open->setEnabled(true);
    action_New->setEnabled(true);
}

void CamHelper::slot_NewMagazin()
{
    showTable_Rustplan(false);
}

void CamHelper::slot_NewProject()
{
    QString string_Comment;
    //erzeuge einen neuen Zeiger für das Project und übergib ihn den nötigen Klassen
    new_Project();

    // Scanne SPF Files nach Projektdaten
    // wenn das fehlschlägt brich die Funktion ab */
    if(!project->scann_ForData())
        return;

    // Scanne SPF Files nach Werkzeugen
    // wenn das fehlschlägt brich die Funktion ab
    if(!project->scann_ForTools())
        return;

    if(project->get_ProjectClamping() == "Sp0")
        project->set_MainProgramm(QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP0.MPF");
    if(project->get_ProjectClamping() == "Sp1")
        project->set_MainProgramm(QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP1.MPF");
    if(project->get_ProjectClamping() == "Sp2")
        project->set_MainProgramm(QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP2.MPF");
    if(project->get_ProjectClamping() == "Sp3")
        project->set_MainProgramm(QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP3.MPF");
    if(project->get_ProjectClamping() == "Sp4")
        project->set_MainProgramm(QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP4.MPF");
    if(project->get_ProjectClamping() == "Sp5")
        project->set_MainProgramm(QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP5.MPF");

    //lade den Standart Comment für Spannung 0 und Spannung1
    if(project->get_ProjectClamping() == "Sp0" || project->get_ProjectClamping() == "Sp1")
    {
        mfile->setFileName(QDir::homePath() + "/CamHelper/config/Comment01.txt");
        if(!mfile->read_Content())
            return;
    }
    //lade den Standart Comment für Spannung 2 - 5
    else
    {
        mfile->setFileName(QDir::homePath() + "/CamHelper/config/Comment25.txt");
        if(!mfile->read_Content())
            return;   
    }
    //setze den Standart Comment für das Project
    foreach (QString str, mfile->get_Content())
    {
        string_Comment = string_Comment + str + "\n";
    }
    project->set_Comment(string_Comment);

    //lade vorhandene daten aus der Datenbank
    tab_Project->load_ProjectData();


    /*
    //erzeuge ein neues ProgrammModel
    programmModel = new ProgrammModel();
    //Überge dem ProgrammModel die Item_Programm Liste
    programmModel->populateData(project->get_ListProgramm());
    //setze das ProgrammModel in tableView_Programme
    ui->tableView_Programme->setModel(programmModel);
    //Verbinde sig / slot NewProgrammList(QList<Item_ProgrammProject>)
    connect(programmModel, SIGNAL(sig_NewProgrammList(QList<Item_Programm>)),
            project, SLOT(slot_NewProgrammList(QList<Item_Programm>)));

    */

    /* setze mfile den Pfad für das Hauptprogramm
     * lese das Hauptprogramm ein
     * wenn es einen Fehler beim einlesen gibt verlasse die Funktion */
    mfile->setFileName(project->get_MainProgramm());
    if(!mfile->read_Content()) return;

    /* ersetze im Hauptprogramm die Platzhalter */
    QStringList stringList_Content = parser_PlaceHolder->set_PlaceHolder_MainProgramm(mfile->get_Content());
    // schreibe alles in textEdit
    foreach(QString str, stringList_Content)
    {
        ui->textEdit->append(str);
    }
    //scrolle ganz nach oben
    ui->textEdit->moveCursor (QTextCursor::Start) ;
    //erstelle den Ruestplan
    showTable_Rustplan();

    //befülle lineEdit etc im tab_Project mit den ProjektDaten
    tab_Project->set_ProjectData();

    project->log_ProjectData();
    touchProbe->insert_Item(project->get_ListTouchProbe());

    action_Save->setEnabled(true);
    action_Export->setEnabled(true);
    action_Print->setEnabled(true);
    action_Open->setEnabled(true);
    action_New->setEnabled(true);
}

void CamHelper::slot_Print(bool b)
{
    Q_UNUSED(b);

    QPrintPreviewDialog dialogPrint;
    connect(&dialogPrint, SIGNAL(paintRequested(QPrinter*)), this, SLOT(slot_PrintPage(QPrinter*)));
    connect(&dialogPrint, SIGNAL(finished(int)), this, SLOT(slot_DialogPrintFinished(int)));
    dialogPrint.exec();
}

void CamHelper::slot_PrintPage(QPrinter *printer)
{
    showTable_Rustplan(true);
    QPainter painter;
    if(!painter.begin(printer)) {
        logging->warning( "can't start printer");
        return;
    }
    // print table
    TablePrinter tablePrinter(&painter, printer);
    QVector<int> columnStretch = QVector<int>() << 2 << 5 << 3 << 2 << 2 << 20;
    QVector<QString> columnHeaders = QVector<QString>() << "Nr" << "Tool ID" << "GL" << "AL" << "FL" << "Beschreibung";
    //if(!tablePrinter.printTable(ui->tableView_Rustplan->model(), columnStretch, columnHeaders))
    if(!tablePrinter.printTable(tableModel, columnStretch, columnHeaders))
    {
        logging->error(Q_FUNC_INFO + QString(" - ") + tablePrinter.lastError());
    }
    painter.end();
    //qDebug() << "Start: " << Q_FUNC_INFO;
}

void CamHelper::slot_RepetitionAccepted()
{
    QString string_ProjectID;

    //speicher das Project;
    if(dialog_Repetition->radioButton_Repetition->isChecked())
    {
        project->set_LastProduction(QDateTime::currentDateTime().toString(Qt::ISODate));
    }

    project->save();

    // Versuche die ProjectID des Projects aus der Datenbank zu holen
    string_ProjectID = dataBase->get_ProjectID(project->get_ProjectName(),
                                               project->get_ProjectClamping());

    /* Abhängig vom radioButton_Repetition wird die Funktion
     * 'project_Export->slot_ExportProject' mit true oder false aufgerufen */
    if(dialog_Repetition->radioButton_Repetition->isChecked())
    {
        project_Export->slot_ExportProject(true);
    }
    else
    {
        project_Export->slot_ExportProject(false);
    }
}

void CamHelper::slot_Save(bool b)
{
    Q_UNUSED(b);

    //Überprüfe ob im Tab_Project alle Werte eingetragen sind
    if(!tab_Project->check_Project())
    {
        logging->error("Fehlerhafter Project");
        ui->tabWidget->setCurrentIndex(0);
        return;
    }

    //Schreibe in das Project die aktuellen Antast Cyclen und Bilder
    project->set_TPItemList(touchProbe->get_ItemList());
    project->set_PictureList(tab_Project->get_PictureList());

    project->save();
}

void CamHelper::slot_Settings(bool b)
{
    Q_UNUSED(b);
    dialog_Settings->show();
}

void CamHelper::slot_ShowLog()
{
    //bringt den Tab Log in den Vordergrund
    //wird von Logging nach einem Error getriggert
    ui->tabWidget->setCurrentWidget(ui->tab_Log);
}

void CamHelper::slot_startApplication()
{

    logging = ui->textEdit_Log;
    connect(logging, SIGNAL(sig_ShowLog()), this, SLOT(slot_ShowLog()));

    mfile   = new MFile(this, logging);

    // Dialg Start
    dialog_Start = new Dialog_Start(this);
    connect(dialog_Start, SIGNAL(sig_NewClicked()), this, SLOT(slot_NewProject()));
    connect(dialog_Start, SIGNAL(sig_CheckFiles()), this, SLOT(slot_CheckFiles()));

    //Alles was man für die Einstellungen braucht
    settings = new Settings(this);
    dialog_Settings = new Dialog_Settings(this, logging);
    dialog_Settings->set_Settings(settings);
    connect(dialog_Settings, SIGNAL(settingsOK()),     this, SLOT(slot_startApplication()));

    //HyperMILL Datenbank kopieren
    if(!copyWerkzeugDB())
        return;

    //DataBase initialisieren und oeffnen,
    //wenn das fehlschlaegt wird die Funktion beendet
    dataBase = new DataBase(this, logging);
    if(!dataBase->open())
        return;

    //Dialog Open
    dialog_Open = new Dialog_Open(this, logging, dataBase);
    dialog_Open->hide();
    connect(dialog_Start, SIGNAL(sig_OpenProject()), dialog_Open, SLOT(slot_ShowDialog()));
    connect(action_Open, SIGNAL(triggered(bool)), dialog_Open, SLOT(slot_ShowDialog()));
    connect(dialog_Open, SIGNAL(sig_LoadProject(QString,QString)), this, SLOT(slot_LoadProject(QString,QString)));

    //Project initialisieren
    project = new Project(this,
                          logging,
                          settings,
                          dataBase,
                          toolList_IN);

    //parser_PlaceHolder initialisieren
    parser_PlaceHolder = new Parser_PlaceHolder(this,
                                                logging,
                                                project); //<-- Project erledigt

    //parser_Programm initialisieren
    parser_Programm = new Parser_Programm(this,
                                          logging,
                                          dataBase);

    // erstelle eine neue ToolList für Top100
    // hol aus der DatenBank die Top 100
    toolList_Top100 = new ToolList(this);
    dataBase->get_Top100(toolList_Top100);

   /* Überprüfe die Settings
   * Wenn das fehlschlägt verlasse die Funktion */
   if(!dialog_Settings->checkSettings())
   {
     dialog_Settings->show();
     return;
   }

   touchProbe = ui->tab_TouchProbe;
   touchProbe->set_Project(project);
   touchProbe->set_Logging(logging);
   touchProbe->insert_Item();

   magazin = ui->tab_Magazin;
   magazin->set_FilePath(settings->get_MagazinDir() + "/Magazin.INI");
   magazin->set_DataBase(dataBase);
   magazin->set_Logging(logging);
   connect(magazin, SIGNAL(sig_NewMagazin()), this, SLOT(slot_NewMagazin()));
   if(!magazin->create_ToolList())
     return;

   // neuen Project_Export erstellen
   project_Export = new Project_Export(this,
                                       logging,
                                       project,        //<-- Project erledigt
                                       dialog_Progress,
                                       dataBase);

   if(!dialog_Settings->checkSettings())
   {
     dialog_Settings->show();
     return;
   }

   //Zeiger in Tab_Project setzten
   tab_Project->set_DataBase(dataBase);
   tab_Project->set_Logging(logging);
   tab_Project->set_Project(project);  //<-- Project erledigt

   //Lade die Nullpunkte in den Dialog_Project
   //Wenn das fehlschlägt brich die Funktion ab
   if(!tab_Project->load_ZeroPoint())
     return;

   //Lade die Materialien in den Dialog_Project
   //Wenn das fehlschlägt brich die Funktion ab
   if(!tab_Project->load_Material())
     return;

   dialog_Start->show();

   license = new License(this, settings, logging);
   connect(license, SIGNAL(sig_LicenseFailed()), this, SLOT(slot_LicenseFaild()));
   license->checkLicense();
}

void CamHelper::slot_TableClicked(const QModelIndex &modelIndex)
{

   if(modelIndex.row() == 0 && bool_PrintProject)
   {
     bool_PrintProject = false;
     showTable_Rustplan();
     return;
   }

   if(modelIndex.row() == 0 && !bool_PrintProject)
   {
     bool_PrintProject = true;
     showTable_Rustplan();
     return;
   }

   if(list_ToolDescription[modelIndex.row()].contains("EINLAGERN") && bool_PrintIn)
   {
     bool_PrintIn = false;
     showTable_Rustplan();
     return;
   }

   if(list_ToolDescription[modelIndex.row()].contains("EINLAGERN") && !bool_PrintIn)
   {
     bool_PrintIn = true;
     showTable_Rustplan();
     return;
   }

   if(list_ToolDescription[modelIndex.row()].contains("AUSLAGERN") && bool_PrintOut)
   {
     bool_PrintOut = false;
     showTable_Rustplan();
     return;
   }

   if(list_ToolDescription[modelIndex.row()].contains("AUSLAGERN") && !bool_PrintOut)
   {
     bool_PrintOut = true;
     showTable_Rustplan();
     return;
   }
}

bool CamHelper::copyWerkzeugDB()
{
   QFileInfo fileInfo_WerkzeugDB;
   QString string_WerkzeugDB = settings->get_WerkzeugDB();

   /* Wenn das File WerkzeugDB.db schon existiert wird es erstmal gelöscht
     * Wenn das fehlschlägt gib eine Fehlermeldung aus und verlasse die
     * Funktion mit false*/
   fileInfo_WerkzeugDB = QFileInfo(QDir::homePath() + "/CamHelper/WerkzeugDB/WerkzeugDB.db");
   if(fileInfo_WerkzeugDB.exists())
   {
     if(!QFile::remove(fileInfo_WerkzeugDB.absoluteFilePath()))
     {
            logging->error(Q_FUNC_INFO + QString(" - konnte alte Sicherheitskopie von WerkzeugDB nicht loeschen"));
            return false;
     }
   }

   /* Kopiert die orginal Werkzeugdatenbank nach /MainGen/WerkzeugDB/WerkzeugDB.db
     * Wenn das fehlschlägt gib eine Fehlermeldung aus und verlasse die
     * Funktion mit false*/
   if(!QFile::copy(string_WerkzeugDB, QDir::homePath() + "/CamHelper/WerkzeugDB/WerkzeugDB.db"))
   {
     logging->error(Q_FUNC_INFO + QString(" - konnte keine Sicherheitskopie von WerkzeugDB erstellen"));
     return false;
   }

   stringList_Log.clear();
   stringList_Log.append("Copy");
   stringList_Log.append(string_WerkzeugDB);
   stringList_Log.append("to");
   stringList_Log.append(QDir::homePath() + "/CamHelper/WerkzeugDB/WerkzeugDB.db");

   logging->frame_Successful(stringList_Log);
   return true;
}

void CamHelper::new_Project()
{
   project = new Project(this,
                         logging,
                         settings,
                         dataBase,
                         toolList_IN);

   //Neuen Zeiger an die Klassen übergeben
   tab_Project->set_Project(project);
   project_Export->set_Project(project);
   touchProbe->set_Project(project);
   parser_PlaceHolder->set_Project(project);

   //Antastcyclen in Touchprobe löschen
   touchProbe->clear();
   tab_Project->clear();

   ui->textEdit->clear();
}
