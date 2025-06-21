#include "database.h"

DataBase::DataBase(QObject *parent, Logging* l)
    : QObject{parent}
{
    log = l;

    string_ToolDB = QDir::homePath() + "/CamHelper/WerkzeugDB/WerkzeugDB.db";
    string_MainDB = QDir::homePath() + "/CamHelper/DataBase.db";

    main_DataBase = QSqlDatabase::addDatabase("QSQLITE", "MainDataBase");
    main_DataBase.setDatabaseName(string_MainDB);

    tool_DataBase = QSqlDatabase::addDatabase("QSQLITE", "ToolDataBase");
    tool_DataBase.setDatabaseName(string_ToolDB);
}

bool DataBase::open()
{
    QFile file_ToolDataBase(string_ToolDB);
    QFile file_MainDataBase(string_MainDB);

    if(!file_MainDataBase.exists())
    {
        log->vailed(Q_FUNC_INFO);
        log->vailed(string_MainDB);
        log->vailed("konnte nicht gefunden werden");
        return false;
    }

    if(!file_ToolDataBase.exists())
    {
        log->vailed(Q_FUNC_INFO);
        log->vailed(string_ToolDB);
        log->vailed("konnte nicht gefunden werden");
        return false;
    }

    if(!main_DataBase.open())
    {
        qDebug() << Q_FUNC_INFO << "!main_DataBase.open";
        log->vailed(Q_FUNC_INFO);
        log->vailed("main_DataBase konnte nicht geöffnet werden");
        return false;
    }
    else
    {
        log->successful("main_DataBase geöffnet");
    }

    if(!tool_DataBase.open())
    {
        log->vailed(Q_FUNC_INFO);
        log->vailed("tool_DataBase konnte nicht geöffnet werden");
        return false;
    }
    else
    {
       log->successful("tool_DataBase geöffnet");
    }

    return true;
}

QList<ProjectData> DataBase::get_LastOpen()
{
    QList<ProjectData> list;
    QSqlQuery query(main_DataBase);
    ProjectData projectData;

    //Suche nach dem Project in der Datenbank,
    query.exec("SELECT id, Name, Status, Clamping, LastOpen FROM Project "
               "ORDER BY LastOpen DESC, Name "
               "LIMIT 10; ");

    if(!query.lastError().text().isEmpty())
    {
        log->vailed(Q_FUNC_INFO);
        log->vailed(query.lastError().text());
        return list;
    }

    while (query.next())
    {
        projectData = ProjectData();
        projectData.name = query.value("Name").toString();
        projectData.id =   query.value("id").toString();
        insertPicutres(projectData);
        list.append(projectData);
    }
    return list;
}

ProjectData DataBase::get_Project(QString string_ProjectId)
{
    ProjectData projectData;
    QSqlQuery query(main_DataBase);
    query.exec("SELECT id, Name, Status, Material, Clamping, RawPartInspection, "
               "CamFile, Comment, Last_Production, LastOpen "
               "FROM Project "
               "WHERE id = '" + string_ProjectId + "';");


    while (query.next())
    {
        projectData.name                = query.value("Name").toString();
        projectData.id                  =   query.value("id").toString();
        projectData.state               = query.value("Status").toString();
        projectData.material            = query.value("Material").toString();
        projectData.tension             = query.value("Clamping").toString();
        projectData.rawPart_Inspection  = query.value("RawPartInspection").toString();
        projectData.hyperMILL_File      = query.value("CamFile").toString();
        projectData.header              = query.value("Comment").toString();
        projectData.lastProduction      = query.value("Last_Production").toString();
        projectData.lastOpen            = query.value("LastOpen").toString();
        insertPicutres(projectData);
    }

    return projectData;
}

void DataBase::insertPicutres(ProjectData &projectData)
{
    // sucht die Bilder aus der Datenbank und schreibt sie in das Projekt
    QSqlQuery query (main_DataBase);
    QList<QPixmap> list;
    QPixmap outPixmap;
    QByteArray byteArray;

    query.exec("SELECT * FROM Pictures "
               "WHERE project_id = '" + projectData.id + "';");

    if(!query.lastError().text().isEmpty())
    {
        log->vailed(Q_FUNC_INFO);
        log->vailed(query.lastError().text());
        return;
    }

    while (query.next())
    {
        outPixmap = QPixmap();
        byteArray = query.value("data").toByteArray();
        outPixmap.loadFromData( byteArray );
        list.append(outPixmap);
    }

    projectData.listPictures = list;
}
