#ifndef PROJECT_EXPORT_H
#define PROJECT_EXPORT_H

#include <QObject>
#include <QStringList>
#include <QWidget>
#include <QTextEdit>
#include <QDir>
#include <QFile>

#include "../Dialoge/dialog_progress.h"
#include "../Classes/struct.h"
#include "../Classes/database.h"
#include "../Classes/mfile.h"
#include "../Classes/spf_parser.h"
#include "../Logging/logging.h"
#include "../TouchProbe/tp_item.h"

class Project_Export : public QObject
{
    Q_OBJECT
private:
    Dialog_Progress* dialog_Progress;
    QStringList stringList_ContentMainProgramm;
    ProjectData* projectData;
    DataBase* dataBase;
    Logging* log;
    MFile* mfile;
    int counter;
    Programm programm;
    SPF_Parser* spf_Parser;
    QDir dir_Destination;
    QMap<QString, QString> map_Bruch;
    QStringList stringList_Touchprobe;

    bool loadBruch();

public:
    explicit Project_Export(QObject *parent = nullptr);
    void set_ContentMainProgramm(QTextEdit*);
    void set_DataBase(DataBase* db) {dataBase = db;}    //Übernehme die Datenbank, wird von tab_Project::set_DataBase übergeben
    void exportProject(ProjectData*, bool bool_IncToolCounter);
    void set_Logging(Logging* l);                       //Übernehme das Logging, wird von tab_Project::set_Logging übergeben
                                                        //erzeuge mfile(this, logging);
    bool replace_Wildcart(QString);
    bool finish_Load();

signals:
    void sig_Export_TouchProbe();

public slots:
    void slot_NextProgramm();
};

#endif // PROJECT_EXPORT_H
