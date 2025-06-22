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
    query.exec("SELECT id, Name, State, Tension, Last_Open FROM Project "
               "ORDER BY Last_Open DESC, Name "
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
        insert_Picutres(projectData);
        list.append(projectData);
    }
    return list;
}

ProjectData DataBase::get_Project(QString string_ProjectId)
{
    ProjectData projectData;
    QSqlQuery query(main_DataBase);
    query.exec("SELECT id, Name, State, Material, Tension, RawPartInspection, "
               "hyperMILL_File, Header, Last_Production, Last_Open "
               "FROM Project "
               "WHERE id = '" + string_ProjectId + "';");

    if(!query.lastError().text().isEmpty())
    {
        log->vailed(Q_FUNC_INFO);
        log->vailed(query.lastError().text());
        return projectData;
    }

    while (query.next())
    {
        projectData.name                = query.value("Name").toString();
        projectData.id                  = query.value("id").toString();
        projectData.state               = query.value("State").toString();
        projectData.material            = query.value("Material").toString();
        projectData.tension             = query.value("Tension").toString();
        projectData.rawPart_Inspection  = query.value("RawPartInspection").toString();
        projectData.hyperMILL_File      = query.value("hyperMILL_File").toString();
        projectData.header              = query.value("Header").toString();
        projectData.lastProduction      = query.value("Last_Production").toString();
        projectData.lastOpen            = query.value("Last_Open").toString();

        insert_FinishPart(projectData); //Schreib die Fertigteilmasse ins Projekt
        insert_Picutres(projectData);   //Schreib die Bilder ins Projekt
        insert_RawPart(projectData);    //Schreib die Rohteilmasse ins Projekt
    }

    return projectData;
}

void DataBase::insert_FinishPart(ProjectData &projectData)
{
    //suche die Fertigeildaten und schreib sie ins Projekt
    QSqlQuery query (main_DataBase);
    FinishPart finishPart;
    query.exec("SELECT * FROM FinishPart "
               "WHERE Project_ID = '" + projectData.id + "';");

    if(!query.lastError().text().isEmpty())
    {
        log->vailed(Q_FUNC_INFO);
        log->vailed(query.lastError().text());
        return;
    }

    while (query.next())
    {
        finishPart.id          = query.value("id").toString();
        finishPart.x_Length    = query.value("X_Length").toString();
        finishPart.y_Width     = query.value("Y_Width").toString();
        finishPart.z_Height    = query.value("Z_Height").toString();
        projectData.finishPart = finishPart;
    }

    return;
}

void DataBase::insert_Picutres(ProjectData &projectData)
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

void DataBase::insert_RawPart(ProjectData &projectData)
{
    //suche die Rohteildaten und schreib sie ins Projekt
    QSqlQuery query (main_DataBase);
    RawPart rawPart;
    query.exec("SELECT * FROM RawPart "
               "WHERE Project_ID = '" + projectData.id + "';");

    if(!query.lastError().text().isEmpty())
    {
        log->vailed(Q_FUNC_INFO);
        log->vailed(query.lastError().text());
        return;
    }

    while (query.next())
    {
        rawPart.id          = query.value("id").toString();
        rawPart.x_Length    = query.value("X_Length").toString();
        rawPart.y_Width     = query.value("Y_Width").toString();
        rawPart.z_Height    = query.value("Z_Height").toString();
        rawPart.z_RawPart   = query.value("Z_RawPart").toString();
        projectData.rawPart = rawPart;
    }
    return;
}
