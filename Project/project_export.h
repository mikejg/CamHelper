#ifndef PROJECT_EXPORT_H
#define PROJECT_EXPORT_H

#include <QObject>

#include "project.h"
#include "../database.h"
#include "../logging.h"
#include "../Dialoge/dialog_progress.h"
#include "../Parser/parser_placeholder.h"
#include "../Parser/parser_programm.h"

class Project_Export : public QObject
{
    Q_OBJECT

private:
    DataBase*           database;
    Dialog_Progress*    dialog_Progress;
    Logging*            log;
    Parser_PlaceHolder* parser_PlaceHolder;
    Parser_Programm*    parser_Programm;
    Project*            project;
    enum Marker {KopfStart, KopfEnd, keinMarker};

    QStringList stringList;

    QStringList stringList_ContentMainProgramm;
    int                    counter;
    QString         string_Destination;
    bool              bool_IncToolCounter;
    QStringList stringList_Log;
    Marker                 marker;
    MFile*                 mfile;
    QString         string_Programm;
    QString         string_ProgrammDir;
    //QStringList stringList_Programme;
    QString         string_ProjectClamping;
    QString         string_ProjectFullName;
    QString         string_ProjectName;
    QString         string_Source;
    QTimer*                timer;
    QList<Item_Programm> list_ItemProgramm;
    Item_Programm item_Programm;
     QMap<QString, QString> map_Bruch;

    bool finish_Cleaning();
    bool finish_Load();
    bool finish_RawPartInspection();
    bool finish_TouchSp0();
    bool finish_TouchSp1();
    QString formatString(QString);
    void init_ExportFiles();
    bool loadBruch();

public:
    explicit Project_Export(QObject *parent = nullptr,
                            Logging* l = nullptr,
                            Project* p = nullptr,
                            Dialog_Progress* dp = nullptr,
                            DataBase* db = nullptr);

    void set_Project(Project* p) {project = p;
                                  parser_PlaceHolder->set_Project(p);}

public slots:
    void slot_ExportProject(bool);
    void slot_NextProgramm();

signals:
    void sig_ExportTouchProbe();
};

#endif // PROJECT_EXPORT_H
