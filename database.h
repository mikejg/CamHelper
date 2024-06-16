#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDir>
#include <QBuffer>

#include "database_items.h"
#include "logging.h"
#include "Tools/toollist.h"
#include "TouchProbe/tp_struct.h"
#include "Project/mlabel.h"

class DataBase : public QObject
{
    Q_OBJECT
private:
    Logging* log;
    QSqlDatabase tool_DataBase;
    QSqlDatabase main_DataBase;

    QString string_ToolDB;
    QString string_MainDB;

    QStringList stringList_Error;

    void log_QueryError(QString, QSqlQuery*);

public:
    explicit DataBase(QObject *parent = nullptr, Logging* l = nullptr);

    //bool        deleteFrom_NCToolsProject(Item_NCToolProject);
    void        deleteFrom_NCToolsProject(QString);
    void        deleteFrom_ProgrammProject(QString);
    //bool        deleteFrom_ProgrammProject(Item_ProgrammProject);
    void        delete_TP_Items(QString);
    void        delete_Pictures(QString);
    void        delete_Tags(QString);

    QList<Item_NCToolProject>   get_ConnectionNCToolsProject(QString);

    int         get_Counter(QString toolID);
    QString     get_Description(QString toolID);
    Item_Project get_FullProject(QString, QString);
    QString     get_GageLength(QString);
    QString     get_NCToolProjectID(QString, QString);
    Item_Programm get_ItemProgramm(QString,QString);
    Item_Project get_Project(QString, QString);
    QString     get_ProjectID(QString, QString);
    QStringList get_Project();
    QStringList get_ProjectsFromTag(QString);
    QStringList get_Tags();
    QStringList get_Tags(QString);
    QStringList get_ToolData(QString);
    QString     get_ToolLength(QString toolID);
    QString     get_TipLength(QString toolID);
    void        get_Top100(ToolList*);

    QList<Item_TouchProbe> get_TouchProbe(QString);
    QList<QPixmap>         get_Pixmap(QString);

    bool        inc_ToolCounter(ToolList*);
    bool        insert_Programm(Item_Programm, QString, QString);
    void        insert_Picture(MLabel*, QString);
    QString     insert_Tool(Tool*);
    bool        insert_Tool(Tool*, QString, QString);
    void        insert_TPAusrichten(Struct_Ausrichten, QString);
    void        insert_TPBohrung(Struct_Bohrung, QString);
    void        insert_TPEbenheit(Struct_Ebenheit, QString);
    void        insert_TPKante(Struct_Kante, QString);
    void        insert_TPSteg(Struct_Steg, QString);
    void        insert_TPNut(Struct_Nut, QString);
    void        insert_Tags(QString, QString);
    bool open();

    bool save_Project(QMap<QString, QString>);
    void set_LastProduction(QString);

    void fill_ToolList(QString, QString, ToolList*);
signals:

};

#endif // DATABASE_H
