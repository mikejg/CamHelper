#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTableWidgetItem>

#include "Classes/database.h"
#include "Dialoge/dialog_settings.h"
#include "Dialoge/dialog_init.h"
#include "Logging/logging.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    DataBase* database;
    Dialog_Settings* dialog_Settings;
    Dialog_Init* dialog_Init;
    Logging* logging;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void sig_OpenProject(QString);

public slots:
    void slot_InitApp();
    void slot_ToolButtonClicked();

};
#endif // MAINWINDOW_H
