#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/Icons/Main/Wallpaper3.png"); //Add commentMore actions
    bkgnd = bkgnd.scaled(this->size());
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    ui->stackedWidget->setCurrentWidget(ui->tab_Init);

    //übergebe den Zeiger für das Logging
    logging = ui->tab_Logging;

    //Erstelle die Datenbank
    dataBase = new DataBase(this, logging);

    //Übergebe die DatenBank, Logging
    ui->tab_Project->set_DataBase(dataBase);
    ui->tab_Project->set_Logging(logging);

    //übergebe den Zeiger für Dialog_Init
    dialog_Init = ui->tab_Init;


    //Erstelle den Dialog Settings. Wenn alle Einstellungen OK sind und gespeichert wurden
    //wird der InitApp neu gestartet
    dialog_Settings = new Dialog_Settings(this, logging);
    connect(dialog_Settings, SIGNAL(settingsOK()), this, SLOT(slot_InitApp()));

    //Verbinde die ToolButtons an der Seite mit Slots
    connect(ui->toolButton_Log, SIGNAL(clicked()), this, SLOT(slot_ToolButtonClicked()));
    connect(ui->toolButton_Project, SIGNAL(clicked()), this, SLOT(slot_ToolButtonClicked()));
    connect(ui->toolButton_Open, SIGNAL(clicked()), this, SLOT(slot_ToolButtonClicked()));
    connect(ui->toolButton_ToolList, SIGNAL(clicked()), this, SLOT(slot_ToolButtonClicked()));
    connect(ui->toolButton_ToolMagazin, SIGNAL(clicked()), this, SLOT(slot_ToolButtonClicked()));

    //Wenn im tab_Init auf ein Bild gecklict wird, soll das Projekt geöffnet werden
    connect(ui->tab_Init, SIGNAL(sig_Clicked(QString)), this, SLOT(slot_OpenProject(QString)));


    QTimer::singleShot(500, this, SLOT(slot_InitApp()));
}

MainWindow::~MainWindow()
{
    delete ui;
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
    //ui->toolButton_MainProgramm->setEnabled(true);
    ui->toolButton_ToolList->setEnabled(true);
    ui->toolButton_ToolMagazin->setEnabled(true);
}

void MainWindow::slot_ToolButtonClicked()
{
    if(sender() == ui->toolButton_Log)
        ui->stackedWidget->setCurrentWidget(ui->tab_Logging);

    if(sender() == ui->toolButton_Project)
        ui->stackedWidget->setCurrentWidget(ui->tab_Project);

    if(sender() == ui->toolButton_Open)
    {
        ui->stackedWidget->setCurrentWidget(ui->tab_Init);
        dialog_Open->slot_ShowDialog();
    }

    if(sender() == ui->toolButton_ToolList)
        ui->stackedWidget->setCurrentWidget(ui->tab_ToolList);

    if(sender() == ui->toolButton_ToolMagazin)
        ui->stackedWidget->setCurrentWidget(ui->tab_Magazin);
}

void MainWindow::slot_OpenProject(QString string_ProjectId)
{
    ProjectData projectData;

    currentProject = new Project(this);                     //Erstelle einen Zeiger für das aktuelle Projekt
    projectData = dataBase->get_Project(string_ProjectId);  //Lade die Projekdaten aus der DatenBank
    currentProject->set_ProjectData(projectData);           //Übergebe die Projektdaten an das aktuelle Projekt
    ui->tab_Project->set_ProjectData(projectData);          //Zeige die Projektaten im Tab Projekt an
    ui->stackedWidget->setCurrentWidget(ui->tab_Project);   //Zeige Tab_Projekt an
}

void MainWindow::slot_OpenProject(QString string_Name, QString string_Tension)
{
    ProjectData projectData;

    currentProject = new Project(this);                                 //Erstelle einen Zeiger für das aktuelle Projekt
    projectData = dataBase->get_Project(string_Name, string_Tension);   //Lade die Projekdaten aus der DatenBank
    currentProject->set_ProjectData(projectData);                       //Übergebe die Projektdaten an das aktuelle Projekt
    ui->tab_Project->set_ProjectData(projectData);                      //Zeige die Projektaten im Tab Projekt an
    ui->stackedWidget->setCurrentWidget(ui->tab_Project);               //Zeige Tab_Projekt an
}
