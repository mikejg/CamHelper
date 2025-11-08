#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTableWidgetItem>

#include "Classes/database.h"
#include "Classes/spf_parser.h"
#include "Classes/struct.h"
#include "Classes/mfile.h"

#include "Dialoge/dialog_settings.h"
#include "Dialoge/dialog_init.h"
#include "Dialoge/dialog_open.h"
#include "Dialoge/dialog_save.h"
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
    Dialog_Save* dialog_Save;
    Logging* logging;
    Magazin* magazin;
    //Project* currentProject;
    ProjectData* projectData;
    bool bool_IgnoreToggle;
    QIcon *ico;
    SPF_Parser* spf_Parser;
    MFile* mfile;
    bool forceClose;
    bool load_Programme(QStringList&);
    bool copyWerkzeugDB();
    bool isPopupOpen = false;

protected:
    bool eventFilter(QObject *obj, QEvent *ev) override;
    void closeEvent(QCloseEvent *event);

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
    void slot_NewToolList();
    void slot_NewProject();
    void slot_CheckFiles();
    void slot_ShowMainProgramm();
    void slot_SaveOpenProject();
    void slot_SaveNewProject();
    void slot_OpenProject();
    void slot_SaveClose();
    void slot_Close();
    void slot_PopupOpen(bool);
};
#endif // MAINWINDOW_H
