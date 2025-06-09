#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->frame->setStyleSheet("background-color: rgba(125, 125, 125, 255); ");

    dialog_Settings = new Dialog_Settings(this);

    QTimer::singleShot(500, this, SLOT(slot_InitApp()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_InitApp()
{
    //Überprüfe die Settings, wenn es einen Fehler gibt
    //zeige den Dialog
    if(!dialog_Settings->checkSettings())
        dialog_Settings->show();
}
