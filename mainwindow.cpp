#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->tab_Init);

    //übergebe den Zeiger für das Logging
    logging = ui->tab_Logging;

    //Erstelle die Datenbank
    database = new DataBase(this, logging);

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

    //Wenn im tab_Init auf ein Bild gecklict wird, soll das Projekt geöffnet werden
    connect(ui->tab_Init, SIGNAL(sig_Clicked(QString)), this, SIGNAL(sig_OpenProject(QString)));


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

    if(!database->open())
        return;

    QList<ProjectData> list = database->get_LastOpen();
    dialog_Init->set_Pictures(list);


    //ui->toolButton_Project->setEnabled(true);
    //ui->toolButton_MainProgramm->setEnabled(true);
    //ui->toolButton_ToolList->setEnabled(true);
    //ui->toolButton_ToolMagazin->setEnabled(true);
}

void MainWindow::slot_ToolButtonClicked()
{
    if(sender() == ui->toolButton_Log)
        ui->stackedWidget->setCurrentWidget(ui->tab_Logging);

    if(sender() == ui->toolButton_Project)
        ui->stackedWidget->setCurrentWidget(ui->tab_Project);

    if(sender() == ui->toolButton_Open)
        ui->stackedWidget->setCurrentWidget(ui->tab_Init);
}
