#ifndef TAB_PROJECT_H
#define TAB_PROJECT_H

#include <QWidget>
#include <QFileDialog>
#include <QDesktopServices>

#include "project.h"
#include "mlabel.h"
#include "selectorwidget.h"
#include "../logging.h"
#include "../database.h"
#include "../Dialoge/dialog_rawpartinspection.h"
#include "../Dialoge/dialog_tag.h"
#include "../Dialoge/dialog_programm.h"

namespace Ui {
class Tab_Project;
}

class Tab_Project : public QWidget
{
    Q_OBJECT

private:
    Ui::Tab_Project *ui;
    QColor                 backroundColor;
    DataBase*              database;
    Dialog_RawPartInspection* dialog_RawPartInspection;
    Dialog_Tag*            dialog_Tag;
    Dialog_Programm*       dialog_Programm;
    QFileDialog*           fileDialog;
    Logging*               log;
    QList<QString>         list_Keys;
    QMap<QString, QString> map_NP;
    MFile*                 mfile;
    //QPalette*              palette_InValid;
    //QPalette*              palette_Valid;
    QPalette               palette;
    Project*               project;
    QString                string_Line;
    QStringList            stringList_ZeroPoint;
    SelectorWidget*        selectorWidget;

    void check_LineEdit(QLineEdit*, bool bool_Unsigned = false);

protected:
    bool eventFilter(QObject *obj, QEvent *ev) override;

public:
    explicit Tab_Project(QWidget *parent = nullptr);
    ~Tab_Project();

    void clear();
    bool check_Project();
    bool load_Material();
    void load_ProjectData();
    bool load_ZeroPoint();

    void set_DataBase(DataBase* db) {database = db;}
    void set_Logging(Logging* l) {log = l; mfile->set_Logging(l);}
    void set_Project(Project* p) {project = p;}
    void set_ProjectData();

    QList<MLabel*> get_PictureList();

public slots:
    void slot_ClampingChanged(int);
    void slot_NewInspection(QString);
    void slot_ShowProgramme();
    void slot_ShowRawPartInspection();
    void slot_ShowTags();
    void slot_OpenPicture();
    void slot_NewSelector();
    void slot_NewPixmap(QPixmap);
    void slot_NewHyperMILLFile();
    void slot_ExecFile();
    void slot_checkBox_RT_AufmassEinzel_stateChanged(int);
    void slot_checkBox_FT_AufmassEinzel_stateChanged(int);
};

#endif // TAB_PROJECT_H
