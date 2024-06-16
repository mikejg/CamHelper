#ifndef DIALOG_PROJECT_H
#define DIALOG_PROJECT_H

#include <QDialog>
#include "dialog_rawpartinspection.h"
#include "../database.h"
#include "../logging.h"
#include "../mfile.h"
#include "../Project/project.h"

namespace Ui {
class Dialog_Project;
}

class Dialog_Project : public QDialog
{
    Q_OBJECT
private:
    Ui::Dialog_Project *ui;

    DataBase* database;
    Dialog_RawPartInspection* dialog_RawPartInspection;

    QString string_Line;
    Logging*       log;

    QMap<QString, QString> map_NP;
    MFile*                 mfile;

    QList<QString> list_Keys;

    QPalette*  palette_InValid;
    QPalette*  palette_Valid;
    Project*   project;

    QStringList stringList_ZeroPoint;

public:
    explicit Dialog_Project(QWidget *parent = nullptr,
                            Logging* l = nullptr,
                            Project* p = nullptr,
                            DataBase* db = nullptr);
    ~Dialog_Project();

    bool load_Material();
    void load_ProjectData();
    bool load_ZeroPoint();

signals:
    sig_AllValid();

public slots:
    void slot_CheckInput();
    void slot_ClampingChanged(int);
    void slot_NewInspection(QString);
    void slot_ShowRawPartInspection();
};

#endif // DIALOG_PROJECT_H
