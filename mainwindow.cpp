#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->frame->setStyleSheet("background-color: rgba(125, 125, 125, 255); ");
}

MainWindow::~MainWindow()
{
    delete ui;
}
