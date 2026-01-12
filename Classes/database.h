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
    bool                delete_ProjectData(ProjectData* );
    bool                delete_FromTable(QString, QString);
    int                 get_Counter(QString);           //Hole mir den Zähler für das Werkzeug aus der Datenbank
    QString             get_GageLength(QString);        //Hole mir die Gesamtlänge des Werkzeugs
    QString             get_Description(QString);       //Hole mir die Beschreibung
    QList<ProjectData>  get_LastOpen();                 //Hole mir die letzten 10 Projekt aus der Datenbank
    QStringList         get_LastOpenList();             //Hole mir eine Liste mit den letzten 10 ProjectNamen
    ProjectData*        get_Project(QString);           //Hole mir ein Project mit der ProjctId aus der Datenbank
    ProjectData*        get_Project(QString, QString);
    bool                get_Project(ProjectData*);
    bool                get_ProjectID(ProjectData*);
    bool                check_ProjectID(QString, QString);
    QString             get_ProjectID(QString, QString);
    QStringList         get_ProjectFromTag(QString);    //Hole mir eine Liste aller Projecte mit dem gleichen Tag
    QStringList         get_ProjectList();              //Hole mir eine Liste aller ProjectNamen
    QStringList         get_ProjectList(QString);       //Hole alle ProjectNamen mit dem Werkzeug
    Programm            get_Programm(QString, QString);
    QStringList         get_Tags();                     //Hole mir eine Liste mit den Tags
    QStringList         get_Tags(QString);              //Hole mir die Tags eines Projects
    QStringList         get_ToolData(QString);          //Hole mir die Werkzeugdaten aus der hyperMILL Datenbank
    QStringList         get_Tools();
    void                get_Top100(ToolList*);          //Hole mir die 100 meist benutzten Werkzeuge
    QString             get_ToolLength(QString);        //Hole mir die Werkzeuglänge
    QString             get_TipLength(QString);         //Hole die Freistellänge
    QString             get_NCToolProjectID(QString, QString);

    bool save(ProjectData*);                            //Speicher das Project ab;
    bool save_RawPart(ProjectData*);                    //Speicher Rohteil Daten;
    bool save_FinishPart(ProjectData*);                 //Speicher Fertigteil Daten;
    bool save_ZeroPoint(ProjectData*);                  //Speicher den Nullpunkt;
    bool save_Programm(ProjectData*);                   //Speicher die Programme;
    bool save_Picture(ProjectData*);                    //Speicher die Bilder;
    bool save_NCTools(ProjectData*);                    //Speicher die NCTools;
    bool save_TouchProbe(ProjectData*);                 //Speicher die Antastzyklen;
    bool save_Tags(ProjectData*);                       //Speicher die Tags
    bool save_Offset_RawPart(ProjectData*);             //Speicher Offset Rohteil

    void insert_FinishPart(ProjectData*);              //Schreibt die FertigteilDaten in ein Projekt
    void insert_Picutres(ProjectData*);                //Schreibt die Bilder in ein Projekt
    void insert_RawPart(ProjectData*);                 //Schreibt die RohteilDaten in ein Projekt
    void insert_ToolList(ProjectData*);                //Schreibt die Werkzeuge in ein Projekt
    void insert_ZeroPoint(ProjectData*);               //Schreibt den Nullpunkt in ein Projekt
    void insert_OffsetRawPart(ProjectData*);           //Schreibt die Rohteil Aufmasse ins Projekt
    void insert_Programm(ProjectData*);
    void insert_Tags(ProjectData*);
    void insert_TouchProbe(ProjectData*);
    bool insert_Tool(Tool*, QString, QString);

    bool create_NCToolProject(Tool*, ProjectData*);         //Erstelle einen neuen Datensatz in NCTools_Project
    QString create_Tool(Tool*);                             //Erstelle einen neuen Werkzeug Datensatz
    bool create_TPAusrichten(Struct_Ausrichten,QString);    //Erstelle einen neuen Datensatz in TP_Ausrichten
    bool create_TPKante(Struct_Kante,QString);              //Erstelle einen neuen Datensatz in TP_Kante
    bool create_TPEbenheit(Struct_Ebenheit, QString);       //Erstelle einen neuen Datensatz in TP_Ebenheit
    bool create_TPSteg(Struct_Steg, QString);               //Erstelle einen neuen Datensatz in TP_Steg
    bool create_TPBohrung(Struct_Bohrung, QString);         //Erstelle einen neuen Datensatz in TP_Bohrung
    bool create_TPNut(Struct_Nut, QString);                 //Erstelle einen neuen Datensatz in TP_Nut
    bool inc_ToolCounter(ToolList* );                       //Zähle die Werkzeuge eins hoch

    void fill_ToolList(QString, ToolList*);
};

#endif // DATABASE_H
