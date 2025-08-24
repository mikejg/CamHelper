#ifndef TAB_PROJECT_H
#define TAB_PROJECT_H

#include <QWidget>

#include "../Classes/database.h"
#include "../Classes/mfile.h"

#include "../Dialoge/dialog_tag.h"
#include "../Dialoge/dialog_rawpartinspection.h"
#include "../Dialoge/dialog_programm.h"
#include "../Dialoge/dialog_tools.h"

#include "../Logging/logging.h"

#include "project.h"

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
    Logging* log;
    MFile* mfile; // wird in set_Logging erstellt
    ProjectData* projectData;

    void insert_Pixmap(QPixmap p);

public:
    explicit Tab_Project(QWidget *parent = nullptr);
    ~Tab_Project();

    bool load_Material();
    void set_DataBase(DataBase* db) {dataBase = db;}
    void set_Logging(Logging* l); //Logging wird gesetzt und MFile mit Logging erstellt
    void set_ProjectData(ProjectData* );
    bool check_InputFields();

signals:
    void sig_NewToolList();

public slots:
    void slot_NewInspection(QString);
    void slot_ShowRawPartInspection();
    void slot_ShowTags();
    void slot_ShowProgramm();
    void slot_ShowTools();
    void slot_checkBox_Offset_RawPart_stateChanged(int);
    void slot_checkBox_Offset_FinishPart_stateChanged(int);
    //void slot_NewProgrammList(QList<Item_Programm>);
};

#endif // TAB_PROJECT_H
