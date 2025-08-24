#ifndef DATABASE_H
#define DATABASE_H

#include <QDir>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include "struct.h"
#include "../Tool/tool_Struct.h"
#include "../Tool/toollist.h"
#include "../Logging/logging.h"

class DataBase : public QObject
{
    Q_OBJECT

private:
    Logging* log;

    QSqlDatabase tool_DataBase;
    QSqlDatabase main_DataBase;

    QString string_ToolDB;
    QString string_MainDB;


public:
    explicit DataBase(QObject *parent = nullptr, Logging* l = nullptr);

    bool open();

    int                 get_Counter(QString);           //Hole mir den Zähler für das Werkzeug aus der Datenbank
    QString             get_Description(QString);       //Hole mir die Beschreibung
    QList<ProjectData>  get_LastOpen();                 //Hole mir die letzten 10 Projekt aus der Datenbank
    QStringList         get_LastOpenList();             //Hole mir eine Liste mit den letzten 10 ProjectNamen
    ProjectData         get_Project(QString);           //Hole mir ein Project mit der ProjctId aus der Datenbank
    ProjectData         get_Project(QString, QString);
    QStringList         get_ProjectFromTag(QString);    //Hole mir eine Liste aller Projecte mit dem gleichen Tag
    QStringList         get_ProjectList();              //Hole mir eine Liste aller ProjectNamen
    QStringList         get_Tags();                     //Hole mir eine Liste mit den Tags
    QStringList         get_Tags(QString);              //Hole mir die Tags eines Projects
    QStringList         get_ToolData(QString);          //Hole mir die Werkzeugdaten aus der hyperMILL Datenbank
    void                get_Top100(ToolList*);          //Hole mir die 100 meist benutzten Werkzeuge
    QString             get_ToolLength(QString);        //Hole mir die Werkzeuglänge
    QString             get_TipLength(QString);         //Hole die Freistellänge

    void insert_FinishPart(ProjectData &);              //Schreibt die FertigteilDaten in ein Projekt
    void insert_Picutres(ProjectData &);                //Schreibt die Bilder in ein Projekt
    void insert_RawPart(ProjectData &);                 //Schreibt die RohteilDaten in ein Projekt
    void insert_ToolList(ProjectData &);                //Schreibt die Werkzeuge in ein Projekt
    void insert_ZeroPoint(ProjectData &);               //Schreibt den Nullpunkt in ein Projekt
    void insert_OffsetRawPart(ProjectData &);           //Schreibt die Rohteil Aufmasse ins Projekt
    void insert_Programm(ProjectData &);
    void insert_TouchProbe(ProjectData &);
};

#endif // DATABASE_H
