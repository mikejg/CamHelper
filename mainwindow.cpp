#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/Icons/Main/Wallpaper.jpg");
    bkgnd = bkgnd.scaled(this->size());
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    //dialog_Settings = new Dialog_Settings(this);
    ui->stackedWidget->setCurrentIndex(0);

    QTimer::singleShot(500, this, SLOT(slot_InitApp()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_InitApp()
{
}
