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

int DataBase::get_Counter(QString toolID)
{
    QSqlQuery query (main_DataBase);
    int counter = 0;

    query.exec("select counter from NCTool "
               "where T_Number = '" + toolID + "';");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
    {
        log->vailed(Q_FUNC_INFO);
        log->vailed(query.lastError().text());
    }

    while (query.next())
    {
        counter = query.value("counter").toInt();
        //qDebug() << QString("%1").arg(counter);
    }

    //qDebug() << QString("%1").arg(counter);
    return counter;
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

QStringList DataBase::get_LastOpenList()
{
    QStringList stringList;
    QString string;
    QSqlQuery query (main_DataBase);

    //Suche nach dem Project in der Datenbank,
    query.exec("SELECT id, Name, Tension, Last_Open FROM Project "
               "ORDER BY Last_Open DESC, Name; ");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
    {
        log->vailed(Q_FUNC_INFO);
        log->vailed(query.lastError().text());
        return stringList;
    }

    while (query.next())
    {
        string = query.value("Name").toString();
        string = string + "_";
        string = string + query.value("Tension").toString();

        stringList.append(string);
    }

    return stringList;
}

QStringList DataBase::get_Tags()
{
    QStringList returnList;
    QString string_Tag;

    QSqlQuery query (main_DataBase);
    query.exec("SELECT tag FROM Tags ORDER BY tag;");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
    {
        log->vailed(Q_FUNC_INFO);
        log->vailed(query.lastError().text());
        return returnList;
    }

    while(query.next())
    {
        string_Tag = query.value("tag").toString();
        if(!returnList.contains(string_Tag))
        {
            returnList.append(string_Tag);
        }
    }
    return returnList;
}

QStringList DataBase::get_Tags(QString string_ProjectID)
{
    QStringList returnList;
    QString string_Tag;
    QSqlQuery query (main_DataBase);
    query.exec("SELECT * FROM Tags "
               "WHERE project_id = '" + string_ProjectID +"' "
               "ORDER BY tag;");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
    {
        log->vailed(Q_FUNC_INFO);
        log->vailed(query.lastError().text());
        return returnList;
    }

    while(query.next())
    {
        string_Tag = query.value("tag").toString();
        if(!returnList.contains(string_Tag))
        {
            returnList.append(string_Tag);
        }
    }
    return returnList;
}

QStringList DataBase::get_ToolData(QString toolID)
{
    QStringList returnList;
    bool bool_Hals = true;
    QString string_TipLength = "0";
    QSqlQuery query (tool_DataBase);

    query.exec("select nc_number_str, "
               "gage_length, "
               "tool_length,"
               "nc_name, "
               "Tools.dbl_param5, Tools.bool_param2, Tools.dbl_param1 "
               "FROM NCTools "
               "INNER JOIN Tools on "
               "Tools.id = NCTools.tool_id "
               "where NCTools.nc_number_str = '" + toolID + "';");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
    {
        log->vailed(Q_FUNC_INFO);
        log->vailed(query.lastError().text());
        return returnList;
    }

    while (query.next())
    {
        returnList.append(query.value("gage_length").toString());
        returnList.append(query.value("tool_length").toString());

        string_TipLength = query.value("dbl_param5").toString();
        bool_Hals = query.value("bool_param2").toBool();
        if(!bool_Hals) string_TipLength = " - ";
        returnList.append(string_TipLength);
        bool_Hals = true;

        returnList.append(query.value("nc_name").toString());
        returnList.append(query.value("dbl_param1").toString());
    }

    return returnList;
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

        insert_FinishPart(projectData);     //Schreib die Fertigteilmasse ins Projekt
        insert_Picutres(projectData);       //Schreib die Bilder ins Projekt
        insert_RawPart(projectData);        //Schreib die Rohteilmasse ins Projekt
        insert_ToolList(projectData);       //Schreib die Werkzeuge ins Projekt
        insert_ZeroPoint(projectData);      //Schreib den Nullpunkt ins Projekt
        insert_OffsetRawPart(projectData);  //Schreib die Rohteil Aufmasse ins Projekt
    }

    return projectData;
}

ProjectData DataBase::get_Project(QString string_Name, QString string_Tension)
{
    //QString string_Project_Id;
    QSqlQuery query(main_DataBase);
    ProjectData projectData;

    query.exec("SELECT id, Name, Tension "
               "FROM Project "
               "WHERE Name = '" + string_Name + "' "
               "AND Tension = '" + string_Tension + "';");

    if(!query.lastError().text().isEmpty())
    {
        log->vailed(Q_FUNC_INFO);
        log->vailed(query.lastError().text());
        return projectData;
    }

    if(query.first())
      projectData = get_Project(query.value("id").toString());

    return projectData;
}

QStringList DataBase::get_ProjectFromTag(QString string_Tag)
{
    QSqlQuery query (main_DataBase);
    QStringList returnList;
    QString string;

    query.exec("SELECT Project.Name, Project.Tension FROM Tags "
               "INNER JOIN Project on "
               "Project.id = Tags.project_id "
               "WHERE tag = '" + string_Tag + "';");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
    {
        log->vailed(Q_FUNC_INFO);
        log->vailed(query.lastError().text());
        return returnList;
    }

    while(query.next())
    {
        string = query.value("Project.Name").toString();
        string = string + "_";
        string = string + query.value("Project.Tension").toString();

        returnList.append(string);
    }

    return returnList;
}

QStringList DataBase::get_ProjectList()
{
    QStringList stringList;
    QString string;
    QSqlQuery query (main_DataBase);

    //Suche nach dem Project in der Datenbank,
    query.exec("SELECT id, Name, Tension "
               "FROM Project "
               "ORDER BY Name;");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
    {
        log->vailed(Q_FUNC_INFO);
        log->vailed(query.lastError().text());
        return stringList;
    }

    while (query.next())
    {
        string = query.value("Name").toString();
        string = string + "_";
        string = string + query.value("Tension").toString();

        stringList.append(string);
    }

    return stringList;
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

void DataBase::insert_ZeroPoint(ProjectData &projectData)
{
    //suche den Nullpunkt und schreib sie ins Projekt
    QSqlQuery query (main_DataBase);
    ZeroPoint zeroPoint;

    query.exec("SELECT * FROM ZeroPoint "
               "WHERE Project_ID = '" + projectData.id + "';");

    if(!query.lastError().text().isEmpty())
    {
        log->vailed(Q_FUNC_INFO);
        log->vailed(query.lastError().text());
        return;
    }

    while (query.next())
    {
        zeroPoint.id          = query.value("id").toString();
        zeroPoint.string_X    = query.value("X").toString();
        zeroPoint.string_Y    = query.value("Y").toString();
        zeroPoint.string_Z    = query.value("Z").toString();
        zeroPoint.string_G    = query.value("G").toString();
        projectData.zeroPoint = zeroPoint;
    }
    return;
}

void DataBase::insert_ToolList(ProjectData &projectData)
{
    //such nach den Werkzeugen und schreib sie ins Projekt
    QSqlQuery query (main_DataBase);
    Tool* tool;

    query.exec("SELECT NCTool.T_Number, NCTool.Gage_Length, "
               "NCTool.Tool_Length, NCTool.Tip_Length, "
               "NCTool.Counter, NCTool.Description, "
               "nctool_id, project_id "
               "FROM NCTools_Project "
               "INNER JOIN NCTool on NCTool.id = NCTools_Project.nctool_id "
               "WHERE project_id = " + projectData.id + " ;");

    if(!query.lastError().text().isEmpty())
    {
        log->vailed(Q_FUNC_INFO);
        log->vailed(query.lastError().text());
        return;
    }

    while (query.next())
    {
        tool = new Tool();
        tool->set_Number(query.value("NCTool.T_Number").toString());
        tool->set_Description(query.value("NCTool.Description").toString());
        tool->set_GageLength(query.value("NCTool.Gage_Length").toString());
        tool->set_ToolLength(query.value("NCTool.Tool_Length").toString());
        tool->set_TipLength(query.value("NCTool.Tip_Length").toString());
        tool->set_Counter(query.value("NCTool.Counter").toInt());

        projectData.toolList->insert_Tool(tool);
    }
    return;
}

void DataBase::insert_OffsetRawPart(ProjectData &projectData)
{
    //such nach den Rohteil Aufmasse und schreib sie ins Projekt
    QSqlQuery query (main_DataBase);
    Offset_RawPart offset_RawPart;

    query.exec("SELECT * FROM Offset_RawPart "
               "WHERE Project_ID = '" + projectData.id + "';");

    if(!query.lastError().text().isEmpty())
    {
        log->vailed(Q_FUNC_INFO);
        log->vailed(query.lastError().text());
        return;
    }

    while (query.next())
    {
        offset_RawPart.id = query.value("id").toString();
        offset_RawPart.string_XPlus = query.value("X_Plus").toString();
        offset_RawPart.string_XMinus = query.value("X_Minus").toString();
        offset_RawPart.string_YPlus = query.value("Y_Plus").toString();
        offset_RawPart.string_YMinus = query.value("Y_Minus").toString();
        offset_RawPart.string_ZPlus = query.value("Z_Plus").toString();

        projectData.offset_RawPart = offset_RawPart;
    }

    return;
}
