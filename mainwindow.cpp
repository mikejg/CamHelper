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

    QIcon *ico = new QIcon();
    ico->addPixmap(QPixmap(":/Icons/Main/ToolList2.png"),QIcon::Normal,QIcon::On);
    ico->addPixmap(QPixmap(":/Icons/Main/print.png"),QIcon::Normal,QIcon::Off);
    ui->toolButton_ToolList->setIcon(*ico);
    ui->toolButton_ToolList->setCheckable(true);
    ui->toolButton_ToolList->setChecked(true);

    ui->stackedWidget->setCurrentWidget(ui->tab_Init);

    logging = ui->tab_Logging;                          //übergebe den Zeiger für das Logging

    dataBase = new DataBase(this, logging);             //Erstelle die Datenbank

    ui->tab_Project->set_DataBase(dataBase);            //Übergebe die DatenBank an Tab_Project
    ui->tab_Project->set_Logging(logging);              //Übergebe Logging an Tab_Project
    ui->tab_Project->installEventFilter(this);

    ui->tab_MainProgramm->set_Logging(logging);         //Übergebe Lobbing an Tab_MainProgramm
    dialog_Init = ui->tab_Init;                         //übergebe den Zeiger für Dialog_Init

    //bool_IgnoreToggle = false;

    //Erstelle den Dialog Settings. Wenn alle Einstellungen OK sind und gespeichert wurden
    //wird der InitApp neu gestartet
    dialog_Settings = new Dialog_Settings(this, logging);
    connect(dialog_Settings, SIGNAL(settingsOK()), this, SLOT(slot_InitApp()));

    //Verbinde die ToolButtons an der Seite mit Slots
    connect(ui->toolButton_Log, SIGNAL(clicked()), this, SLOT(slot_ToolButtonClicked()));
    connect(ui->toolButton_Project, SIGNAL(clicked()), this, SLOT(slot_ToolButtonClicked()));
    connect(ui->toolButton_Open, SIGNAL(clicked()), this, SLOT(slot_ToolButtonClicked()));
    connect(ui->toolButton_ToolList, SIGNAL(toggled(bool)), this, SLOT(slot_ToolListToggled(bool)));
    connect(ui->toolButton_ToolMagazin, SIGNAL(clicked()), this, SLOT(slot_ToolButtonClicked()));
    connect(ui->toolButton_MainProgramm, SIGNAL(clicked()), this, SLOT(slot_ToolButtonClicked()));

    //Wenn im tab_Init auf ein Bild gecklict wird, soll das Projekt geöffnet werden
    connect(ui->tab_Init, SIGNAL(sig_Clicked(QString)), this, SLOT(slot_OpenProject(QString)));

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
        if(ui->tab_Project->check_InputFields())
        {
            //foreach(Programm pgr, projectData->list_Programm)
            //    qDebug() << Q_FUNC_INFO << pgr.ProgrammName << pgr.NoXY;
            ui->tab_MainProgramm->set_ProjectData(*projectData);
        }
    }
    return true;
}

void MainWindow::slot_InitApp()
{
    ui->toolButton_Project->setEnabled(false);
    ui->toolButton_MainProgramm->setEnabled(false);
    ui->toolButton_ToolList->setEnabled(false);
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

    QList<ProjectData> list = dataBase->get_LastOpen();
    dialog_Init->set_Pictures(list);

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



    ui->toolButton_Project->setEnabled(true);
    ui->toolButton_MainProgramm->setEnabled(true);
    ui->toolButton_ToolList->setEnabled(true);
    ui->toolButton_ToolMagazin->setEnabled(true);
}

void MainWindow::slot_ToolButtonClicked()
{
    bool_IgnoreToggle = true;                                   //Ignoriere das Umschalten
    ui->toolButton_ToolList->setCheckable(true);                //Schalte den ToolButton wieder ein
    ui->toolButton_ToolList->setChecked(true);                  //Schalte auf das Icon ToolList um

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

    if(sender() == ui->toolButton_MainProgramm)
        ui->stackedWidget->setCurrentWidget(ui->tab_MainProgramm);
    bool_IgnoreToggle = false;
}

void MainWindow::slot_OpenProject(QString string_ProjectId)
{
    projectData =  new ProjectData();

    currentProject = new Project(this);                     //Erstelle einen Zeiger für das aktuelle Projekt
    *projectData = dataBase->get_Project(string_ProjectId);  //Lade die Projekdaten aus der DatenBank
    currentProject->set_ProjectData(projectData);           //Übergebe die Projektdaten an das aktuelle Projekt
    ui->tab_Project->set_ProjectData(projectData);         //Zeige die Projektaten im Tab Projekt an
    ui->tab_ToolSheet->showTable(*projectData);
    ui->stackedWidget->setCurrentWidget(ui->tab_Project);   //Zeige Tab_Projekt an
}

void MainWindow::slot_OpenProject(QString string_Name, QString string_Tension)
{
    projectData =  new ProjectData();

    currentProject = new Project(this);                                 //Erstelle einen Zeiger für das aktuelle Projekt
    *projectData = dataBase->get_Project(string_Name, string_Tension);   //Lade die Projekdaten aus der DatenBank
    currentProject->set_ProjectData(projectData);                       //Übergebe die Projektdaten an das aktuelle Projekt
    ui->tab_Project->set_ProjectData(projectData);                      //Zeige die Projektaten im Tab Projekt an
    ui->tab_ToolSheet->showTable(*projectData);
    ui->stackedWidget->setCurrentWidget(ui->tab_Project);               //Zeige Tab_Projekt an
}

void MainWindow::slot_ToolListToggled(bool bool_Toggle)
{
    if(bool_IgnoreToggle) return;   //Ignoriere das Umschalten

    if(!bool_Toggle)
        ui->stackedWidget->setCurrentWidget(ui->tab_ToolSheet);

    if(bool_Toggle)
    {
        bool_IgnoreToggle = true;                                   //Ignoriere das Umschalten
        ui->toolButton_ToolList->setChecked(false);                 //Schalte auf das Icon Drucken
        ui->toolButton_ToolList->setCheckable(false);               //Schalte den Toolbutton aus
        ui->tab_ToolSheet->printTable();                            //Öffne den Druckdialog
    }
}

void MainWindow::slot_DialogPrintFinished(int result)
{
    Q_UNUSED(result);
    ui->toolButton_ToolList->setCheckable(true);                    //Schalte den Toolbutten wieder ein
    bool_IgnoreToggle = false;
}
