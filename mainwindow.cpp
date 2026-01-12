#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    forceClose = false;
    QPixmap bkgnd(":/Icons/Main/Wallpaper5.png"); //Add commentMore actions
    bkgnd = bkgnd.scaled(this->size());
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    ico = new QIcon();
    ico->addPixmap(QPixmap(":/Icons/Main/ToolList2.png"),QIcon::Normal,QIcon::On);
    ico->addPixmap(QPixmap(":/Icons/Main/print.png"),QIcon::Normal,QIcon::Off);
    ui->toolButton_ToolList->setIcon(*ico);
    ui->toolButton_ToolList->setCheckable(true);
    ui->toolButton_ToolList->setChecked(true);

    ui->stackedWidget->setCurrentWidget(ui->tab_Init);

    projectData = nullptr;

    logging = ui->tab_Logging;                              //übergebe den Zeiger für das Logging
    mfile = new MFile(this, logging);                       //Erstelle ein MFile
    dataBase = new DataBase(this, logging);                 //Erstelle die Datenbank

    ui->tab_Project->set_DataBase(dataBase);                //Übergebe die DatenBank an Tab_Project
    ui->tab_Project->set_Logging(logging);                  //Übergebe Logging an Tab_Project
    ui->tab_Project->set_StackedWidget(ui->stackedWidget);  //Übergebe StackedWidget an Tab_Project
    ui->tab_Project->set_TouchProbe(ui->tab_Touchprobe);    //Übergebe Touchprobe an Tab_Prject;
    ui->tab_Project->set_MainProgramm(ui->tab_MainProgramm);//Übergebe MainProgramm an Tab_Project

    ui->tab_Project->installEventFilter(this);
    connect(ui->tab_Project, SIGNAL(sig_NewToolList()), this, SLOT(slot_NewToolList()));

    ui->tab_MainProgramm->set_Logging(logging);         //Übergebe Lobbing an Tab_MainProgramm
    dialog_Init = ui->tab_Init;                         //übergebe den Zeiger für Dialog_Init

    //Erstelle den Dialog Settings. Wenn alle Einstellungen OK sind und gespeichert wurden
    //wird der InitApp neu gestartet
    dialog_Settings = new Dialog_Settings(this, logging);
    connect(dialog_Settings, SIGNAL(settingsOK()), this, SLOT(slot_InitApp()));

    //Erstelle einen Parser für die Unterprogramme und übergib ihm das Verzeichnis für die Unterprogramme
    spf_Parser = new SPF_Parser(this, dialog_Settings->get_ProgrammDir(),logging, dataBase);

    dialog_Save = new Dialog_Save(this);

    license = new License(this);
    connect(license, SIGNAL(sig_ValidLicense(bool)), this, SLOT(slot_ValidLicense(bool)));

    dialog_LicenseKey = new Dialog_LicenseKey(this);
    connect(dialog_LicenseKey, SIGNAL(accepted()), this, SLOT(slot_InitApp()));

    //Verbinde die ToolButtons an der Seite mit Slots
    connect(ui->toolButton_Log, SIGNAL(clicked()), this, SLOT(slot_ToolButtonClicked()));
    connect(ui->toolButton_Project, SIGNAL(clicked()), this, SLOT(slot_ToolButtonClicked()));
    connect(ui->toolButton_Open, SIGNAL(clicked()), this, SLOT(slot_ToolButtonClicked()));
    connect(ui->toolButton_ToolList, SIGNAL(clicked()), this, SLOT(slot_ToolButtonClicked()));
    connect(ui->toolButton_ToolMagazin, SIGNAL(clicked()), this, SLOT(slot_ToolButtonClicked()));
    connect(ui->toolButton_TouchProbe, SIGNAL(clicked()), this, SLOT(slot_ToolButtonClicked()));
    connect(ui->toolButton_New, SIGNAL(clicked()), this, SLOT(slot_ToolButtonClicked()));
    connect(ui->toolButton_Check, SIGNAL(clicked()), this, SLOT(slot_CheckFiles()));
    connect(ui->toolButton_Settings, SIGNAL(clicked()), this, SLOT(slot_ToolButtonClicked()));

    //Wenn im tab_Init auf ein Bild gecklict wird, soll das Projekt geöffnet werden
    connect(ui->tab_Init, SIGNAL(sig_Clicked(QString)), this, SLOT(slot_OpenProject(QString)));
    connect(ui->tab_Project, SIGNAL(sig_ExportTouchprobe()),
            ui->tab_Touchprobe, SLOT(slot_ExportTouchprobe()));
    connect(ui->tab_Project, SIGNAL(sig_ShowMainProgramm()), this, SLOT(slot_ShowMainProgramm()));

    connect(ui->tab_Project, SIGNAL(sig_PopupShown(bool)), this, SLOT(slot_PopupOpen(bool)));

    license->checkRemoteFile();
    //QTimer::singleShot(500, this, SLOT(slot_InitApp()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *ev)
{
    if(!isPopupOpen && obj == ui->tab_Project && ev->type() == QEvent::Leave )
    {
        if(ui->tab_Project->update_ProjectData())
        {
            ui->tab_MainProgramm->set_ProjectData(*projectData);
        }
    }
    return true;
}

void MainWindow::slot_DialogPrintFinished(int result)
{
    Q_UNUSED(result);
    ui->toolButton_ToolList->setCheckable(true);                    //Schalte den Toolbutten wieder ein
    //bool_IgnoreToggle = false;
}

void MainWindow::slot_InitApp()
{
    ui->toolButton_Project->setEnabled(false);
    ui->toolButton_ToolList->setEnabled(false);
    ui->toolButton_TouchProbe->setEnabled(false);
    ui->toolButton_Check->setEnabled(false);
    ui->toolButton_Open->setEnabled(false);
    ui->toolButton_New->setEnabled(false);
    ui->toolButton_ToolMagazin->setEnabled(false);

    if(dialog_Settings->checkSettings())
        logging->successful("Settings OK");
    else
    {
        logging->vailed("Settings fehlerhat");
        ui->stackedWidget->setCurrentWidget(ui->tab_Logging);
        dialog_Settings->show();
        return;
    }

    if(!copyWerkzeugDB())
        return;

    //Öffne die Datenbanken
    if(!dataBase->open())
        return;

    //Lade die Materialliste
    if(!ui->tab_Project->load_Material())
        return;

    //Übergebe die Anzahl der Magazinplätze an den Rüstplan
    ui->tab_ToolSheet->set_MagazinCapacity(dialog_Settings->get_MagazinCapacity());
    ui->tab_ToolSheet->set_Magazin(ui->tab_Magazin);                    //Übergebe das Magazin an den Rüstplan
    ui->tab_ToolSheet->set_DataBase(dataBase);                          //Übergebe die Datenbank an den Rüstplan
    connect(ui->tab_ToolSheet, SIGNAL(sig_DialogPrintFinished(int)),    //Verbinde das beenden des Druckens mit
            this, SLOT(slot_DialogPrintFinished(int)));                 //dem SLOT

    QList<ProjectData> list = dataBase->get_LastOpen();                 //Lade die Letzten Projekte
    dialog_Init->set_Pictures(list);                                    //Übergebe die letzten Projekte an Dialog_Init

    //Dialog Open
    dialog_Open = new Dialog_Open(this, dataBase);
    dialog_Open->hide();
    connect(dialog_Open, SIGNAL(sig_OpenProject(QString,QString)), this, SLOT(slot_OpenProject(QString,QString)));

    magazin = ui->tab_Magazin;
    magazin->set_FilePath(dialog_Settings->get_MagazinDir());
    magazin->set_DataBase(dataBase);
    magazin->set_Logging(logging);

    if(!magazin->create_ToolList())
        return;

    ui->tab_Touchprobe->set_Logging(logging);
    ui->tab_Touchprobe->insert_Item();

    ui->toolButton_Check->setEnabled(true);
    ui->toolButton_Open->setEnabled(true);
    ui->toolButton_New->setEnabled(true);
    ui->toolButton_ToolMagazin->setEnabled(true);
    ui->toolButton_Settings->setEnabled(true);
    ui->toolButton_Log->setEnabled(true);
}


void MainWindow::slot_NewProject()
{
    ProjectData* database_ProjectData;

    projectData = new ProjectData;
    projectData->string_ProgrammDir = dialog_Settings->get_ProgrammDir();
    projectData->string_LocalDir    = dialog_Settings->get_LocalDir();
    projectData->string_RemoteDir   = dialog_Settings->get_RemoteDir();

    spf_Parser->set_ProjectData(projectData);           //übergib den Parser projectData
    if(!spf_Parser->scann_ForData())                    //Suche in den SPF Files nach Project Name_Stand_Spannung
        return;

    if(projectData->tension == "Sp0")
        projectData->zeroPoint.string_G = "G54";

    if(projectData->tension == "Sp1")
            projectData->zeroPoint.string_G = "G55";

    if(projectData->tension == "Sp2")
        projectData->zeroPoint.string_G = "G506";

    if(projectData->tension == "Sp3")
        projectData->zeroPoint.string_G = "G507";

    if(projectData->tension == "Sp4")
        projectData->zeroPoint.string_G = "G508";

    if(!spf_Parser->scann_ForTools())                   // Scanne SPF Files nach Werkzeugen
        return;                                         // wenn das fehlschlägt brich die Funktion ab

    if(projectData->tension == "Sp1")                   // Scanne nur bei Sp1 nach NoXY
    {
        if(!spf_Parser->scann_ForNoXY())
            return;
    }

    //lade den Standart Comment für Spannung 0 und Spannung1
    if(projectData->tension == "Sp0" || projectData->tension == "Sp1")
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
    //setze den Standart Header für das Project
    foreach (QString str, mfile->get_Content())
    {
        projectData->header = projectData->header + str + "\n";
    }

    //Wenn es NICHT Sp1 ist, suche in der Datenbank nach Sp1
    //und übernehme das Material von Sp1
    if(projectData->tension != "Sp1")
    {
        database_ProjectData = dataBase->get_Project(projectData->name, "Sp1");
        projectData->material = database_ProjectData->material;
    }

    dataBase->get_Project(projectData);

    ui->tab_Project->set_ProjectData(projectData);
    ui->tab_ToolSheet->showTable(projectData);
    ui->tab_Touchprobe->set_ProjectData(projectData);
    ui->tab_Touchprobe->clear();
    ui->tab_Touchprobe->insert_Item(projectData->list_TouchProbe);
    ui->stackedWidget->setCurrentWidget(ui->tab_Project);
    ui->toolButton_Project->setEnabled(true);
    ui->toolButton_ToolList->setEnabled(true);
    ui->toolButton_TouchProbe->setEnabled(true);
}

void MainWindow::slot_NewToolList()
{
    ui->tab_ToolSheet->showTable(projectData);
}

void MainWindow::slot_OpenProject(QString string_ProjectId)
{
    qDebug() << Q_FUNC_INFO;
    projectData = dataBase->get_Project(string_ProjectId);                  //Lade die Projekdaten aus der DatenBank
    projectData->string_ProgrammDir = dialog_Settings->get_ProgrammDir();
    projectData->string_LocalDir    = dialog_Settings->get_LocalDir();
    projectData->string_RemoteDir   = dialog_Settings->get_RemoteDir();
    ui->tab_Project->set_ProjectData(projectData);                          //Zeige die Projektaten im Tab Projekt an
    ui->tab_ToolSheet->showTable(projectData);
    ui->tab_Touchprobe->clear();
    ui->tab_Touchprobe->set_ProjectData(projectData);
    ui->tab_Touchprobe->insert_Item(projectData->list_TouchProbe);
    ui->stackedWidget->setCurrentWidget(ui->tab_Project);                   //Zeige Tab_Projekt an
    ui->toolButton_Project->setEnabled(true);
    ui->toolButton_ToolList->setEnabled(true);
    ui->toolButton_TouchProbe->setEnabled(true);
}

void MainWindow::slot_OpenProject(QString string_Name, QString string_Tension)
{
    projectData = dataBase->get_Project(string_Name, string_Tension);       //Lade die Projekdaten aus der DatenBank
    projectData->string_ProgrammDir = dialog_Settings->get_ProgrammDir();
    projectData->string_LocalDir    = dialog_Settings->get_LocalDir();
    projectData->string_RemoteDir   = dialog_Settings->get_RemoteDir();
    ui->tab_Project->set_ProjectData(projectData);                          //Zeige die Projektaten im Tab Projekt an
    ui->tab_ToolSheet->showTable(projectData);
    ui->tab_Touchprobe->clear();
    ui->tab_Touchprobe->set_ProjectData(projectData);                       //Übergebe die Antastzyklen
    ui->tab_Touchprobe->insert_Item(projectData->list_TouchProbe);
    ui->stackedWidget->setCurrentWidget(ui->tab_Project);                   //Zeige Tab_Projekt an
    ui->toolButton_Project->setEnabled(true);
    ui->toolButton_ToolList->setEnabled(true);
    ui->toolButton_TouchProbe->setEnabled(true);
}

void MainWindow::slot_ToolButtonClicked()
{
    if(sender() == ui->toolButton_ToolList)
    {
        if(ui->stackedWidget->currentWidget() != ui->tab_ToolSheet)
        {
            ui->stackedWidget->setCurrentWidget(ui->tab_ToolSheet);
            ui->toolButton_ToolList->setChecked(false);
            //Damit es kein kurzes aufblitzen des ToolList Icons gibt wird das
            //Durcker Icon auf auf On gesetzt
            ico->addPixmap(QPixmap(":/Icons/Main/print.png"),QIcon::Normal,QIcon::On);
            ui->toolButton_ToolList->setIcon(*ico);
            return;
        }

        if(ui->stackedWidget->currentWidget() == ui->tab_ToolSheet)
        {
            ui->toolButton_ToolList->setChecked(false);
            ui->tab_ToolSheet->printTable();
            return;
        }
    }

    if(sender() != ui->toolButton_ToolList)
    {
        ico->addPixmap(QPixmap(":/Icons/Main/ToolList2.png"),QIcon::Normal,QIcon::On);
        ui->toolButton_ToolList->setIcon(*ico);
        ui->toolButton_ToolList->setChecked(true);
    }

    if(sender() == ui->toolButton_Log)
        ui->stackedWidget->setCurrentWidget(ui->tab_Logging);

    if(sender() == ui->toolButton_Project)
        ui->stackedWidget->setCurrentWidget(ui->tab_Project);

    if(sender() == ui->toolButton_Open)
    {
        if(projectData == nullptr)                                                  //Wenn projectData ein Nullzeiger ist
        {
            ui->stackedWidget->setCurrentWidget(ui->tab_Init);                      //zeige Dialog zum öffnen eines neue Projekts
            dialog_Open->slot_ShowDialog();
            return;
        }

        if(!ui->tab_Project->update_ProjectData())                                  //Wenn es fehlerhafte eingaben im Projekt gibt
            return;                                                                 //beende die Funktion

        ProjectData* compareData;
        disconnect(dialog_Save, SIGNAL(accepted()));                                    //löse alle Verbindungen vom Signal accepted
        disconnect(dialog_Save, SIGNAL(discard()));                                     //löse alle Verbindungen vom Signal discard

        connect(dialog_Save, SIGNAL(accepted()), this, SLOT(slot_SaveOpenProject()));   //Verbbinde das Signal accepted neu
        connect(dialog_Save, SIGNAL(discard()), this, SLOT(slot_OpenProject()));        //Verbinde das Signal discard neu
        compareData = dataBase->get_Project(projectData->name, projectData->tension);   //Lade das Ursprüngliche Project aus der Datenbank

        if(*projectData == *compareData)                                            //sind beide Projekt gleich
        {
            ui->stackedWidget->setCurrentWidget(ui->tab_Init);                      //zeige Dialog zum öffnen eines neue Projekts
            dialog_Open->slot_ShowDialog();
        }
        else
            dialog_Save->show();                                                    //Zeige Dialog zum Speichern des aktuellen Projekts
    }

    if(sender() == ui->toolButton_New)
    {
        if(projectData == nullptr)                                                  //Wenn projectData ein Nullzeiger ist
        {
            slot_NewProject();
            return;
        }

        if(!ui->tab_Project->update_ProjectData())                                  //Wenn es fehlerhafte eingaben im Projekt gibt
            return;                                                                 //beende die Funktion

        ProjectData* compareData;
        compareData = dataBase->get_Project(projectData->name, projectData->tension);   //Lade das Ursprüngliche Project aus der Datenbank
        disconnect(dialog_Save, SIGNAL(accepted()));                                    //löse alle Verbindungen vom Signal accepted
        disconnect(dialog_Save, SIGNAL(discard()));                                     //löse alle Verbindungen vom Signal discard

        connect(dialog_Save, SIGNAL(accepted()), this, SLOT(slot_SaveNewProject()));   //Verbbinde das Signal accepted neu
        connect(dialog_Save, SIGNAL(discard()), this, SLOT(slot_NewProject()));        //Verbinde das Signal discard neu

        if(*projectData == *compareData)                                            //sind beide Projekt gleich
        {
            slot_NewProject();
        }
        else
            dialog_Save->show();
    }

    if(sender() == ui->toolButton_ToolMagazin)
        ui->stackedWidget->setCurrentWidget(ui->tab_Magazin);

    if(sender() == ui->toolButton_TouchProbe)
        ui->stackedWidget->setCurrentWidget(ui->tab_Touchprobe);

    if(sender() == ui->toolButton_Settings)
        dialog_Settings->show();
}

void MainWindow::slot_ShowMainProgramm()
{
    ui->stackedWidget->setCurrentWidget(ui->tab_MainProgramm);
}

void MainWindow::slot_ToolListToggled(bool bool_Toggle)
{
    //if(bool_IgnoreToggle) return;   //Ignoriere das Umschalten

    if(!bool_Toggle)
        ui->stackedWidget->setCurrentWidget(ui->tab_ToolSheet);

    if(bool_Toggle)
    {
        //bool_IgnoreToggle = true;                                   //Ignoriere das Umschalten
        ui->toolButton_ToolList->setChecked(false);                 //Schalte auf das Icon Drucken
        ui->toolButton_ToolList->setCheckable(false);               //Schalte den Toolbutton aus
        ui->tab_ToolSheet->printTable();                            //Öffne den Druckdialog
    }
}

void MainWindow::slot_CheckFiles()
{
    QStringList stringList_Programme;
    Programm programm;
    QStringList stringList_Project;
    QString string_Project;
    QString string_ProjectFullName;
    QString string_Tension;
    QString string_ProjectID;
    ToolList* toolList;
    ToolList* toolList_Project;
    int int_Before;
    int int_After;

    toolList = new ToolList(this);

    //Lese die Programme aus dem Verzeichnis ein
    if(!load_Programme(stringList_Programme))
        return;

    foreach (QString string_Programm, stringList_Programme)
    {
        programm.ProgrammName = string_Programm;

        //zieh aus dem Programm den ProjectNamen und entferne am Ende ||
        //es bleibt der string E28994006_E0_Sp1 übrig
        string_ProjectFullName = spf_Parser->get_ProjectName(dialog_Settings->get_ProgrammDir() + "/" + string_Programm);
        string_ProjectFullName = string_ProjectFullName.remove(" ||");

        //splitte E28994006_E0_Sp1 nach '_'
        stringList_Project = string_ProjectFullName.split("_");

        if(stringList_Project.size() > 2)
        {
            //string_Project wird E28994006
            string_Project = stringList_Project.at(0);

            //string_Clamping wird Sp1
            string_Tension = stringList_Project.at(2);

            //hol mir die ProjectID aus der Datenbank
            string_ProjectID = dataBase->get_ProjectID(string_Project, string_Tension);

            //hole mir die Daten für Item_Programm aus der Datenbank
            programm = dataBase->get_Programm(string_ProjectID, string_Programm);

            //Hole alle Werkzeuge für das Projekt aus der Datenbank
            toolList_Project = new ToolList(this);
            dataBase->fill_ToolList(string_ProjectFullName, toolList_Project);

            int_Before = toolList_Project->get_Size();

            //Suche alle Werkzeuge aus dem Programm
            spf_Parser->parse_Tool(dialog_Settings->get_ProgrammDir()+ "/" + string_Programm, toolList);

            //Schreibe alle Werkzeuge aus toolList in toolList_Project, vorhandene werden
            //ignoriert, neue werden hinzugefugt
            foreach (Tool* tool, toolList->get_List())
            {
                toolList_Project->insert_Tool(tool);
            }

            int_After = toolList_Project->get_Size();

            //Wenn es Anderung an der Werkzeugliste gab wird sie neu abgespeichert
            if(int_Before != int_After)
            {
                qDebug() << Q_FUNC_INFO;
                qDebug() << "Vorher:" << int_Before;
                qDebug() << "Nacher:" << int_After;

                dataBase->delete_FromTable("NCTools_Project", string_ProjectID);
                foreach (Tool* tool, toolList_Project->get_List())
                {
                    dataBase->insert_Tool(tool, string_ProjectID, string_ProjectFullName);
                }
            }
        }

        spf_Parser->finish(dialog_Settings->get_ProgrammDir()+ "/" + string_Programm, programm);

        //Wenn es das gleiche Projekt ist wie das aktuelle Projekt werde die die Listen aktualisiert
        if(projectData != nullptr && string_ProjectFullName == projectData->name + "_" + projectData->state + "_" + projectData->tension)
        {
            projectData->toolList = toolList_Project;
            ui->tab_ToolSheet->showTable(projectData);
            ui->tab_Project->refresh_DialogTools();
        }
    }
}

bool MainWindow::load_Programme(QStringList &stringList_Programme)
{
    /* Erzeuge dir und setze den Pfad auf string_ProgrammDir
     * setz den Filter auf SPF-Dateien */
    QDir dir;
    QStringList filters;
    dir.setPath(dialog_Settings->get_ProgrammDir());
    filters << "*.spf";
    dir.setNameFilters(filters);

    /* Variable die ich später noch brauche */
    //QString string_shortName;
    //bool bool_OK;
    //int int_I;  Q_UNUSED(int_I);

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

        if(str.length() > 28)
        {
            qDebug() << str << ": " << str.length();
            if(str.startsWith("0"))
            {
                str = str.right(str.length()-1);
                dir.rename("0"+ str, str);
            }
            logging->vailed("Dateiname zu lang");
            logging->vailed(str);
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
        /* trage str in d stringList_Programme ein */
        stringList_Programme.append(str);
    }
    return true;
}

void MainWindow::slot_SaveOpenProject()
{
    if(!ui->tab_Project->update_ProjectData())                  //Schreibe den Inhalt der Eingabefelder in ProjectData
    {
        ui->stackedWidget->setCurrentWidget(ui->tab_Logging);   //Wenn die Felder Unfollständig sind schalte auf Tab_Log
        return;                                                 //brich hier ab
    }

    if(dataBase->save(projectData))
        logging->successful("Project: " +
                        projectData->name + "_" +
                        projectData->state + "_" +
                        projectData->tension + " erfolgreich gespeichert");
    else
    {
        logging->vailed("Project: " +
                    projectData->name + "_" +
                    projectData->state + "_" +
                    projectData->tension + "konnte nicht gespeichert werden");

        ui->stackedWidget->setCurrentWidget(ui->tab_Logging);               //Wenn die Felder Unfollständig sind schalte auf Tab_Log
        return;                                                             //brich hier ab
    }

    ui->stackedWidget->setCurrentWidget(ui->tab_Init);      //zeige Dialog zum öffnen eines neue Projekts
    dialog_Open->slot_ShowDialog();
}

void MainWindow::slot_SaveNewProject()
{
    if(!ui->tab_Project->update_ProjectData())                  //Schreibe den Inhalt der Eingabefelder in ProjectData
    {
        ui->stackedWidget->setCurrentWidget(ui->tab_Logging);   //Wenn die Felder Unfollständig sind schalte auf Tab_Log
        return;                                                 //brich hier ab
    }

    if(dataBase->save(projectData))
        logging->successful("Project: " +
                            projectData->name + "_" +
                            projectData->state + "_" +
                            projectData->tension + " erfolgreich gespeichert");
    else
    {
        logging->vailed("Project: " +
                        projectData->name + "_" +
                        projectData->state + "_" +
                        projectData->tension + "konnte nicht gespeichert werden");

        ui->stackedWidget->setCurrentWidget(ui->tab_Logging);               //Wenn die Felder Unfollständig sind schalte auf Tab_Log
        return;                                                             //brich hier ab
    }

    slot_NewProject();
}

void MainWindow::slot_OpenProject()
{
    ui->stackedWidget->setCurrentWidget(ui->tab_Init);      //zeige Dialog zum öffnen eines neue Projekts
    dialog_Open->slot_ShowDialog();
}

bool MainWindow::copyWerkzeugDB()
{
    QFileInfo fileInfo_WerkzeugDB;
    QString string_WerkzeugDB = dialog_Settings->get_ToolDB();

    /* Wenn das File WerkzeugDB.db schon existiert wird es erstmal gelöscht
     * Wenn das fehlschlägt gib eine Fehlermeldung aus und verlasse die
     * Funktion mit false*/
    fileInfo_WerkzeugDB = QFileInfo(QDir::homePath() + "/CamHelper/WerkzeugDB/WerkzeugDB.db");
    if(fileInfo_WerkzeugDB.exists())
    {
        if(!QFile::remove(fileInfo_WerkzeugDB.absoluteFilePath()))
        {
            logging->vailed(Q_FUNC_INFO + QString(" - konnte alte Sicherheitskopie von WerkzeugDB nicht loeschen"));
            logging->vailed(fileInfo_WerkzeugDB.absoluteFilePath());
            return false;
        }
    }

    /* Kopiert die orginal Werkzeugdatenbank nach /MainGen/WerkzeugDB/WerkzeugDB.db
     * Wenn das fehlschlägt gib eine Fehlermeldung aus und verlasse die
     * Funktion mit false*/
    if(!QFile::copy(string_WerkzeugDB, QDir::homePath() + "/CamHelper/WerkzeugDB/WerkzeugDB.db"))
    {
        logging->vailed(Q_FUNC_INFO + QString(" - konnte keine Sicherheitskopie von WerkzeugDB erstellen"));
        return false;
    }

    logging->successful("Werkzeugdatenbank kopiert");
    return true;
}

void MainWindow::closeEvent(QCloseEvent *event)
{

    ProjectData* compareData;
    if(projectData == nullptr || forceClose)                                                  //Wenn projectData ein Nullzeiger ist
    {
        event->accept();
    }
    else
    {
        if(!ui->tab_Project->update_ProjectData())                                  //Wenn es fehlerhafte eingaben im Projekt gibt
        {
            event->ignore();
            return;
        }

        compareData = dataBase->get_Project(projectData->name, projectData->tension);   //Lade das Ursprüngliche Project aus der Datenbank
        disconnect(dialog_Save, SIGNAL(accepted()));                                    //löse alle Verbindungen vom Signal accepted
        disconnect(dialog_Save, SIGNAL(discard()));

        connect(dialog_Save, SIGNAL(accepted()), this, SLOT(slot_SaveClose()));   //Verbbinde das Signal accepted neu
        connect(dialog_Save, SIGNAL(discard()), this, SLOT(slot_Close()));        //Verbinde das Signal discard neu

        if(*projectData == *compareData)                                            //sind beide Projekt gleich
        {
            event->accept();
        }
        else
        {
            qDebug() << Q_FUNC_INFO;
            event->ignore();
            dialog_Save->show();
        }
    }
}

void MainWindow::slot_SaveClose()
{
    if(!ui->tab_Project->update_ProjectData())                  //Schreibe den Inhalt der Eingabefelder in ProjectData
    {
        ui->stackedWidget->setCurrentWidget(ui->tab_Logging);   //Wenn die Felder Unfollständig sind schalte auf Tab_Log
        return;                                                 //brich hier ab
    }

    if(dataBase->save(projectData))
        logging->successful("Project: " +
                            projectData->name + "_" +
                            projectData->state + "_" +
                            projectData->tension + " erfolgreich gespeichert");
    else
    {
        logging->vailed("Project: " +
                        projectData->name + "_" +
                        projectData->state + "_" +
                        projectData->tension + "konnte nicht gespeichert werden");

        ui->stackedWidget->setCurrentWidget(ui->tab_Logging);               //Wenn die Felder Unfollständig sind schalte auf Tab_Log
        return;                                                             //brich hier ab
    }

    this->close();
}

void MainWindow::slot_Close()
{
    forceClose = true;
    this->close();
}

void MainWindow::slot_PopupOpen(bool b)
{
    isPopupOpen = b;
}


void MainWindow::slot_ValidLicense(bool bool_Valid)
{
    if(bool_Valid)
    {
        QTimer::singleShot(500, this, SLOT(slot_InitApp()));
        logging->successful("Gültige Lizenz gefunden");
    }
    else
    {
        ui->toolButton_Project->setEnabled(false);
        ui->toolButton_ToolList->setEnabled(false);
        ui->toolButton_TouchProbe->setEnabled(false);
        ui->toolButton_Check->setEnabled(false);
        ui->toolButton_Open->setEnabled(false);
        ui->toolButton_New->setEnabled(false);
        ui->toolButton_ToolMagazin->setEnabled(false);
        ui->toolButton_Settings->setEnabled(false);
        ui->toolButton_Log->setEnabled(false);

        logging->vailed(" ");
        logging->vailed("   +-------------------------------+");
        logging->vailed("   | KEINE Gültige Lizenz gefunden |");
        logging->vailed("   +-------------------------------+");
        ui->stackedWidget->setCurrentWidget(ui->tab_Logging);
        dialog_LicenseKey->show();
    }
}
