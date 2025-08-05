#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTableWidgetItem>

#include "Classes/database.h"
#include "Classes/struct.h"
#include "Dialoge/dialog_settings.h"
#include "Dialoge/dialog_init.h"
#include "Dialoge/dialog_open.h"
#include "Logging/logging.h"
#include "Magazin/magazin.h"
#include "Project/project.h"

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
    DataBase* dataBase;
    Dialog_Open* dialog_Open;
    Dialog_Settings* dialog_Settings;
    Dialog_Init* dialog_Init;
    Logging* logging;
    Magazin* magazin;
    Project* currentProject;
    bool bool_IgnoreToggle;

protected:
    bool eventFilter(QObject *obj, QEvent *ev) override;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void sig_OpenProject(QString);

public slots:
    void slot_InitApp();
    void slot_ToolButtonClicked();
    void slot_OpenProject(QString);
    void slot_OpenProject(QString, QString);
    void slot_ToolListToggled(bool);
    void slot_DialogPrintFinished(int);
};
#endif // MAINWINDOW_H
