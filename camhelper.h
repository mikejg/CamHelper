#ifndef CAMHELPER_H
#define CAMHELPER_H

#include <QMainWindow>
//#include <QTextBlock>
#include <QTimer>
#include <QPrinter>
#include <QPainter>
#include <QPrintPreviewDialog>

#include "mfile.h"

#include "Dialoge/dialog_progress.h"
#include "Dialoge/dialog_project.h"
#include "Dialoge/dialog_repetition.h"
#include "Dialoge/dialog_start.h"
#include "Dialoge/dialog_settings.h"
#include "Dialoge/dialog_open.h"

#include "Magazin/magazin.h"
#include "Magazin/magazinmodel.h"

#include "Parser/parser_placeholder.h"
#include "Parser/parser_programm.h"

#include "Project/project.h"
#include "Project/tab_project.h"
#include "Project/project_export.h"

#include "Model/tablemodel.h"
#include "Model/programmmodel.h"

#include "TouchProbe/touchprobe.h"

#include "database.h"
#include "highlighter.h"
#include "license.h"
#include "logging.h"
#include "settings.h"
#include "tableprinter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CamHelper; }
QT_END_NAMESPACE

class CamHelper : public QMainWindow
{
    Q_OBJECT
private:
    Ui::CamHelper*      ui;

    QAction*            action_Check;
    QAction*            action_Export;
    QAction*            action_Save;
    QAction*            action_Print;
    QAction*            action_Settings;
    QAction*            action_Open;
    QAction*            action_New;
    DataBase*           dataBase;
    Dialog_Progress*    dialog_Progress;
    Dialog_Project*     dialog_Project;
    Dialog_Repetition*  dialog_Repetition;
    Dialog_Settings*    dialog_Settings;
    Dialog_Start*       dialog_Start;
    Dialog_Open*        dialog_Open;
    HighLighter*        highLighter; 
    QList<QString>      list_Counter;
    QList<QString>      list_ToolID;
    QList<QString>      list_ToolDescription;
    QList<QString>      list_GageLength;
    QList<QString>      list_Keys;
    QList<QString>      list_ToolLength;
    QList<QString>      list_TipLength;
    QStringList         stringList_Log;
    License*            license;
    Logging*            logging;
    Magazin*            magazin;
    QMap<QString, QString> map_NP;
    MFile*              mfile;
    Parser_Programm*    parser_Programm;
    Parser_PlaceHolder* parser_PlaceHolder;
    bool                bool_PrintIn;
    bool                bool_PrintOut;
    bool                bool_PrintProject;
    ProgrammModel*      programmModel;
    Project*            project;
    Project*            old_Project;
    Project_Export*     project_Export;
    Settings*           settings;
    Tab_Project*        tab_Project;
    TableModel*         tableModel;
    ToolList*           toolList_IN;
    ToolList*           toolList_OUT;
    ToolList*           toolList_Table;
    ToolList*           toolList_Top100;
    TouchProbe*         touchProbe;

    bool load_Programme(QStringList&);
    void showTable_Rustplan(bool bool_Print=false);
    //void set_TabProject();
    bool copyWerkzeugDB();
    void new_Project();

protected:
    bool eventFilter(QObject *obj, QEvent *ev) override;

public:
    CamHelper(QWidget *parent = nullptr);
    ~CamHelper();

public slots:
    void slot_CheckFiles();
    void slot_CheckFiles(bool);
    void slot_DialogPrintFinished(int);
    void slot_DialogProjectClosed();
    void slot_Export(bool);
    void slot_LicenseFaild();
    void slot_LoadProject(QString,QString);
    void slot_NewMagazin();
    void slot_NewProject();
    void slot_NewToolList();
    void slot_Print(bool);
    void slot_PrintPage(QPrinter*);
    void slot_RepetitionAccepted();
    void slot_Save(bool);
    void slot_Settings(bool b);
    void slot_ShowLog();
    void slot_startApplication();
    void slot_TableClicked(const QModelIndex &modelIndex);
};
#endif // CAMHELPER_H
