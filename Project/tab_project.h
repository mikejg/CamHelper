#ifndef TAB_PROJECT_H
#define TAB_PROJECT_H

#include <QWidget>
#include <QSettings>
#include <QClipboard>
#include <QStackedWidget>
#include <QFileDialog>
#include <QDesktopServices>
#include <QMessageBox>
#include <QPushButton>
#include <QProgressDialog>

#include "../Classes/database.h"
#include "../Classes/mfile.h"
#include "../Classes/copier.h"

#include "../Dialoge/dialog_tag.h"
#include "../Dialoge/dialog_rawpartinspection.h"
#include "../Dialoge/dialog_programm.h"
#include "../Dialoge/dialog_tools.h"
#include "../Dialoge/dialog_repetition.h"

#include "../Logging/logging.h"
#include "../MainProgramm/mainprogramm.h"
#include "../TouchProbe/touchprobe.h"
#include "../TouchProbe/tp_item.h"

#include "project.h"
#include "selectorwidget.h"
#include "project_export.h"

namespace Ui {
class Tab_Project;
}

class Tab_Project : public QWidget
{
    Q_OBJECT
private:
    Ui::Tab_Project *ui;
    DataBase* dataBase;
    Dialog_Tag* dialog_Tag;
    Dialog_RawPartInspection* dialog_RawPartInspection;
    Dialog_Programm* dialog_Programm;
    Dialog_Tools* dialog_Tools;
    Dialog_Repetition* dialog_Repetition;
    Logging* log;
    MFile* mfile; // wird in set_Logging erstellt
    ProjectData* projectData;
    SelectorWidget* selectorWidget;
    QSettings* settings;
    QClipboard*            clipboard;
    QStackedWidget* stackedWidget;
    Project_Export* projectExport;
    TouchProbe* touchProbe;
    MainProgramm* mainProgramm;
    QFileDialog*           fileDialog;
    QMessageBox* msgBox;
    float filter_Value(QString);
    void insert_Pixmap(QPixmap p);
    QString string_LocalDir;
    QString string_RemoteDir;

public:
    explicit Tab_Project(QWidget *parent = nullptr);
    ~Tab_Project();

    bool load_Material();
    void set_DataBase(DataBase* db);
    void set_Logging(Logging* l); //Logging wird gesetzt und MFile mit Logging erstellt
    void set_ProjectData(ProjectData* );
    bool check_InputFields(bool bool_Warning = true);
    void set_MainProgramm(MainProgramm* mp) {mainProgramm = mp;}
    void set_StackedWidget(QStackedWidget* sw) {stackedWidget = sw;}
    void set_TouchProbe(TouchProbe* tp) {touchProbe = tp;}
    bool update_ProjectData();
    void refresh_DialogTools();

signals:
    void sig_NewToolList();
    void sig_ExportTouchprobe();
    void sig_ShowMainProgramm();
    void sig_PopupShown(bool);

public slots:
    void slot_Export();
    void slot_NewInspection(QString);
    void slot_NPPaste();
    void slot_ShowRawPartInspection();
    void slot_ShowTags();
    void slot_PopupClosed();
    void slot_ShowProgramm();
    void slot_ShowTools();
    void slot_checkBox_Offset_RawPart_stateChanged(int);
    void slot_checkBox_Offset_FinishPart_stateChanged(int);
    void slot_NewSelector();
    void slot_NewPixmap(QPixmap);
    void slot_RepetitionAccepted();
    void slot_NewHyperMILLFile();
    void slot_ExecFile();
    void slot_Save();
    void slot_CheckInOut();
    void slot_CheckInOut_Finished();

};

#endif // TAB_PROJECT_H
