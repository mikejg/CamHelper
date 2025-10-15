#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

    //Verbinde die ToolButtons an der Seite mit Slots
    connect(ui->toolButton_Log, SIGNAL(clicked()), this, SLOT(slot_ToolButtonClicked()));
    connect(ui->toolButton_Project, SIGNAL(clicked()), this, SLOT(slot_ToolButtonClicked()));
    connect(ui->toolButton_Open, SIGNAL(clicked()), this, SLOT(slot_ToolButtonClicked()));
    connect(ui->toolButton_ToolList, SIGNAL(clicked()), this, SLOT(slot_ToolButtonClicked()));
    connect(ui->toolButton_ToolMagazin, SIGNAL(clicked()), this, SLOT(slot_ToolButtonClicked()));
    connect(ui->toolButton_TouchProbe, SIGNAL(clicked()), this, SLOT(slot_ToolButtonClicked()));
    connect(ui->toolButton_New, SIGNAL(clicked()), this, SLOT(slot_NewProject()));
    connect(ui->toolButton_Check, SIGNAL(clicked()), this, SLOT(slot_CheckFiles()));

    //Wenn im tab_Init auf ein Bild gecklict wird, soll das Projekt geöffnet werden
    connect(ui->tab_Init, SIGNAL(sig_Clicked(QString)), this, SLOT(slot_OpenProject(QString)));
    connect(ui->tab_Project, SIGNAL(sig_ExportTouchprobe()),
            ui->tab_Touchprobe, SLOT(slot_ExportTouchprobe()));
    connect(ui->tab_Project, SIGNAL(sig_ShowMainProgramm()), this, SLOT(slot_ShowMainProgramm()));

    QTimer::singleShot(500, this, SLOT(slot_InitApp()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *ev)
{
    if(obj == ui->tab_Project && ev->type() == QEvent::Leave)
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

    if(dialog_Settings->checkSettings())
        logging->successful("Settings OK");
    else
    {
        logging->vailed("Settings fehlerhat");
        ui->stackedWidget->setCurrentWidget(ui->tab_Logging);
        dialog_Settings->show();
        return;
    }

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

    //connect(magazin, SIGNAL(sig_NewMagazin()), this, SLOT(slot_NewMagazin()));
    if(!magazin->create_ToolList())
        return;

    ui->tab_Touchprobe->set_Logging(logging);
    ui->tab_Touchprobe->insert_Item();
}

void MainWindow::slot_NewProject()
{
    ProjectData* database_ProjectData;

    projectData = new ProjectData;
    projectData->string_ProgrammDir = dialog_Settings->get_ProgrammDir();

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

    if(!spf_Parser->scann_ForNoXY())
        return;

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
    projectData = dataBase->get_Project(string_ProjectId);                  //Lade die Projekdaten aus der DatenBank
    projectData->string_ProgrammDir = dialog_Settings->get_ProgrammDir();
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
        ui->stackedWidget->setCurrentWidget(ui->tab_Init);
        dialog_Open->slot_ShowDialog();
    }

    if(sender() == ui->toolButton_ToolMagazin)
        ui->stackedWidget->setCurrentWidget(ui->tab_Magazin);

    if(sender() == ui->toolButton_TouchProbe)
        ui->stackedWidget->setCurrentWidget(ui->tab_Touchprobe);
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

    //Schalte auf den Tab Log um
    //ui->tabWidget->setCurrentWidget(ui->tab_Logging);


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
            qDebug() << Q_FUNC_INFO;
            qDebug() << "Vorher:" << int_Before;

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
        qDebug() << Q_FUNC_INFO;

        //Wenn es das gleiche Projekt ist wie das aktuelle Projekt werde die die Listen aktualisiert
        /*if(string_ProjectFullName == projectData->name + "_" + projectData->state + "_" + projectData->tension)
        {
            project->set_NCTools();
            showTable_Rustplan(false);
            ui->tab_Project->slot_RefreshTools();
        }*/
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
