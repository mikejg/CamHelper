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
    stringList_Error.clear();
}

/*
bool DataBase::deleteFrome_NCToolsProject(QString string_ProjectID)
{
    QSqlQuery query (main_DataBase);

    query.exec("DELETE FROM NCTools_Project "
               "WHERE project_id = '" + string_ProjectID + "';");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
    {
        log_QueryError(Q_FUNC_INFO, &query);
        return false;
    }

    return true;
}
*/
void DataBase::delete_TP_Items(QString string_ProjectID)
{
    QSqlQuery query (main_DataBase);
    query.exec("DELETE FROM TP_Ausrichten "
               "WHERE project_id = '" + string_ProjectID + "';");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
    {
        log_QueryError(Q_FUNC_INFO, &query);
    }

    query.exec("DELETE FROM TP_Kante "
               "WHERE project_id = '" + string_ProjectID + "';");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
    {
        log_QueryError(Q_FUNC_INFO, &query);
    }

    query.exec("DELETE FROM TP_Ebenheit "
               "WHERE project_id = '" + string_ProjectID + "';");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
    {
        log_QueryError(Q_FUNC_INFO, &query);
    }

    query.exec("DELETE FROM TP_Steg "
               "WHERE project_id = '" + string_ProjectID + "';");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
    {
        log_QueryError(Q_FUNC_INFO, &query);
    }

    query.exec("DELETE FROM TP_Nut "
               "WHERE project_id = '" + string_ProjectID + "';");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
    {
        log_QueryError(Q_FUNC_INFO, &query);
    }

    query.exec("DELETE FROM TP_Bohrung "
               "WHERE project_id = '" + string_ProjectID + "';");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
    {
        log_QueryError(Q_FUNC_INFO, &query);
    }
}

void DataBase::delete_Pictures(QString string_ProjectID)
{
    QSqlQuery query (main_DataBase);
    query.exec("DELETE FROM Pictures "
               "WHERE project_id = '" + string_ProjectID + "';");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
    {
        log_QueryError(Q_FUNC_INFO, &query);
    }
}

void DataBase::deleteFrom_NCToolsProject(QString string_ProjectID)
{
    QSqlQuery query (main_DataBase);
    query.exec("DELETE FROM NCTools_Project "
               "WHERE project_id = '" + string_ProjectID + "';");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
    {
        log_QueryError(Q_FUNC_INFO, &query);
    }
}

/*bool DataBase::deleteFrom_NCToolsProject(Item_NCToolProject item)
{
    QSqlQuery query (main_DataBase);

    query.exec("DELETE FROM NCTools_Project "
               "WHERE id = '" + item.id + "';");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
    {
        log_QueryError(Q_FUNC_INFO, &query);
        return false;
    }

    return true;
}*/

void DataBase::deleteFrom_ProgrammProject(QString string_ProjectID)
{
    QSqlQuery query (main_DataBase);
    query.exec("DELETE FROM Programm_Project "
               "WHERE project_id = '" + string_ProjectID + "';");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
    {
        log_QueryError(Q_FUNC_INFO, &query);
    }
}

void DataBase::delete_Tags(QString string_ProjectID)
{
    QSqlQuery query (main_DataBase);
    query.exec("DELETE FROM tags "
               "WHERE project_id = '" + string_ProjectID + "';");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
    {
        log_QueryError(Q_FUNC_INFO, &query);
    }
}

/*
bool DataBase::deleteFrom_ProgrammProject(Item_ProgrammProject item)
{
    QSqlQuery query (main_DataBase);

    query.exec("DELETE FROM Programm_Project "
               "WHERE id = '" + item.id + "';");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
    {
        log_QueryError(Q_FUNC_INFO, &query);
        return false;
    }

    return true;
}
*/

void DataBase::fill_ToolList(QString string_Project, QString string_Clamping, ToolList* toolList)
{
    qDebug() << Q_FUNC_INFO;
    QSqlQuery query (main_DataBase);
    QString string_FullName = string_Project + "_" + string_Clamping;
    Tool* tool;

    query.exec("SELECT * "
               "FROM NCTools_Project "
               "INNER JOIN NCTools on "
               "NCTools.id = nctool_id "
               "WHERE Project = '" + string_FullName + "';");

    if(!query.lastError().text().isEmpty())
    {
        log_QueryError(Q_FUNC_INFO, &query);
        return;
    }

    while(query.next())
    {
        tool = new Tool(this);
        tool->set_Number(query.value("T_Number").toString());
        tool->set_GageLength(query.value("GageLength").toString());
        tool->set_ToolLength(query.value("ToolLength").toString());
        tool->set_TipLength(query.value("TipLength").toString());
        tool->set_Counter(query.value("counter").toInt());
        tool->set_Description(query.value("Description").toString());
        tool->set_ToolLife(query.value("ToolLife").toBool());
        tool->set_Parts(query.value("Parts").toInt());
        toolList->insert_Tool(tool);
    }
}

QList<Item_NCToolProject> DataBase::get_ConnectionNCToolsProject(QString string_ProjectID)
{
    QList<Item_NCToolProject> list;
    QSqlQuery query (main_DataBase);
    Item_NCToolProject item;

    query.exec("SELECT * FROM NCTools_Project "
               "WHERE project_id = '" + string_ProjectID + "';");

    if(!query.lastError().text().isEmpty())
    {
        log_QueryError(Q_FUNC_INFO, &query);
        return list;
    }

    while (query.next())
    {
        item = Item_NCToolProject(query.value("T_Number").toString(),
                                  query.value("project_id").toString());
        item.id = query.value("id").toString();

        list.append(item);
    }
    return list;
}


/*
QList<Item_ProgrammProject> DataBase::get_ConnectionProgrammProject(QString string_ProjectID)
{
    QList<Item_ProgrammProject> list;
    QSqlQuery query (main_DataBase);
    Item_ProgrammProject item;

    query.exec("SELECT * FROM Programm_Project "
               "WHERE project_id = '" + string_ProjectID + "';");

    if(!query.lastError().text().isEmpty())
    {
        log_QueryError(Q_FUNC_INFO, &query);
        return list;
    }

    while (query.next())
    {
        item = Item_ProgrammProject(query.value("Programm").toString(),
                                  query.value("project_id").toString());
        item.id = query.value("id").toString();

        item.Offset_X = query.value("Offset_X").toBool();
        item.Offset_Y = query.value("Offset_Y").toBool();
        item.Offset_Z = query.value("Offset_Z").toBool();
        item.TOFFL = query.value("TOFFL").toBool();
        list.append(item);
    }

    return list;
}
*/

int DataBase::get_Counter(QString toolID)
{
    QSqlQuery query (main_DataBase);
    int counter = 0;

    query.exec("select counter from NCTools "
          "where T_Number = '" + toolID + "';");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
        log_QueryError(Q_FUNC_INFO, &query);

    while (query.next())
    {
        counter = query.value("counter").toInt();
        //qDebug() << QString("%1").arg(counter);
    }

    //qDebug() << QString("%1").arg(counter);
    return counter;
}

QString DataBase::get_Description(QString toolID)
{
    //Holt die Beschreibung des Werkzeugs aus der Datenbank
    QString string_Description;
    QSqlQuery query (tool_DataBase);

    query.exec("select nc_name from NCTools "
               "where nc_number_str = '" + toolID + "';");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
        log_QueryError(Q_FUNC_INFO, &query);

    while (query.next())
    {
        string_Description = query.value("nc_name").toString();
    }
    return string_Description;
}

/*
QString DataBase::get_HolderName(QString toolID)
{
    // Holt den Halternamen aus der Datenbank
    QSqlQuery query (tool_DataBase);
    QString string_HolderName;

    query.exec("SELECT Holders.name from NCTools "
               "INNER JOIN Holders on "
               "Holders.id = NCTools.holder_id "
               "where NCTools.nc_number_str = '" + toolID + "';");

    while (query.next())
    {
        string_HolderName = query.value("name").toString();
    }
    return string_HolderName;
}
*/

Item_Project DataBase::get_FullProject(QString string_Name, QString string_Clamping)
{
    Item_Project item_Project = get_Project(string_Name, string_Clamping);

    return item_Project;
}

QString DataBase::get_GageLength(QString toolID)
{
    // Holt die Ausspannlaenge des Werkzeugs aus der Datenbank
    QSqlQuery query (tool_DataBase);
    QString string_GageLength;
    string_GageLength = "0";

    query.exec("select nc_number_str, gage_length from NCTools "
               "where nc_number_str = '" + toolID + "';");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
        log_QueryError(Q_FUNC_INFO, &query);

    while (query.next())
    {
        string_GageLength = query.value("gage_length").toString();
    }
    return string_GageLength;
}

QString DataBase::get_NCToolProjectID(QString string_NCToolID, QString string_ProjectID)
{
    QString string_NCToolProjectID = "-1";
    QSqlQuery query (main_DataBase);

    //Suche nach dem Project in der Datenbank,
    query.exec("SELECT id, nctool_id, project_id FROM NCTools_Project "
               "WHERE nctool_id = '" + string_NCToolID + "' "
               "AND project_id = '" + string_ProjectID + "';");

    //qDebug() << query.lastQuery();

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
        log_QueryError(Q_FUNC_INFO, &query);

    while (query.next())
    {
        string_NCToolProjectID = query.value("id").toString();
    }

    return string_NCToolProjectID;
}

Item_Programm DataBase::get_ItemProgramm(QString string_ProjectID, QString string_Programm)
{
    QSqlQuery query (main_DataBase);
    Item_Programm item;
    item.Programm = string_Programm;

    query.exec("SELECT * from Programm_Project "
               "WHERE project_id = '" + string_ProjectID + "' "
               "AND Programm = '" + string_Programm + "';");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
        log_QueryError(Q_FUNC_INFO, &query);

    while(query.next())
    {
        item.id = query.value("id").toString();
        item.Programm = query.value("Programm").toString();
        item.Project_ID = query.value("project_id").toString();
        item.Offset_X = query.value("Offset_X").toBool();
        item.Offset_Y = query.value("Offset_Y").toBool();
        item.Offset_Z = query.value("Offset_Z").toBool();
        item.TOFFL = query.value("TOFFL").toBool();
        item.NoXY = query.value("NoXY").toBool();
    }
    return item;
}

Item_Project DataBase::get_Project(QString string_Name, QString string_Clamping)
{
    Item_Project item_Project(string_Name, string_Clamping);
    Item_Programm item_Programm;

    QString string_FullName = string_Name + "_" + string_Clamping;
    QSqlQuery query (main_DataBase);

    /*Suche nach dem Project in der Datenbank*/
    query.exec("SELECT * from Project "
          "WHERE Name = '" + string_Name + "' "
          "AND Clamping = '" + string_Clamping + "';");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
        log_QueryError(Q_FUNC_INFO, &query);

    while(query.next())
    {
        item_Project.id = query.value("id").toString();
        item_Project.Material = query.value("Material").toString();
        item_Project.RawPart_X = query.value("RawPart_X").toString();
        item_Project.RawPart_Y = query.value("RawPart_Y").toString();
        item_Project.RawPart_Z = query.value("RawPart_Z").toString();
        item_Project.Component_X = query.value("Component_X").toString();
        item_Project.Component_Y = query.value("Component_Y").toString();
        item_Project.Component_Z = query.value("Component_Z").toString();
        item_Project.ZRawPart = query.value("ZRawPart").toString();
        item_Project.ZeroPoint = query.value("ZeroPoint").toString();
        item_Project.RawPartInspection = query.value("RawPartInspection").toString();
        item_Project.Status = query.value("Status").toString();
        item_Project.CamFile = query.value("CamFile").toString();
        item_Project.Comment = query.value("Comment").toString();
        item_Project.Last_Production = query.value("Last_Production").toString();
        item_Project.XPlus_Max = query.value("XPlus_Max").toString();
        item_Project.XMinus_Max = query.value("XMinus_Max").toString();
        item_Project.YPlus_Max = query.value("YPlus_Max").toString();
        item_Project.YMinus_Max = query.value("YMinus_Max").toString();
        item_Project.ZPlus_Max = query.value("ZPlus_Max").toString();
        item_Project.NPx = query.value("NPx").toString();
        item_Project.NPy = query.value("NPy").toString();
        item_Project.NPz = query.value("NPz").toString();
    }

    query.exec("SELECT * from Programm_Project "
               "WHERE Project = '" + string_FullName + "' "
               "ORDER BY Programm;");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
        log_QueryError(Q_FUNC_INFO, &query);

    while(query.next())
    {
        //item_Project.Programme.append(query.value("Programm").toString());

        item_Programm.id = query.value("id").toString();
        item_Programm.Programm = query.value("Programm").toString();
        item_Programm.Project_ID = query.value("project_id").toString();
        item_Programm.Offset_X = query.value("Offset_X").toBool();
        item_Programm.Offset_Y = query.value("Offset_Y").toBool();
        item_Programm.Offset_Z = query.value("Offset_Z").toBool();
        item_Programm.TOFFL = query.value("TOFFL").toBool();
        item_Programm.NoXY = query.value("NoXY").toBool();

        item_Project.list_Programme.append(item_Programm);
    }

    return item_Project;
}

QString DataBase::get_ProjectID(QString string_ProjectName, QString string_ProjectClamping)
{
    QString string_ProjectID;
    QSqlQuery query (main_DataBase);

    //Suche nach dem Project in der Datenbank,
    query.exec("SELECT id, Name, Status, Clamping from Project "
               "where Name = '" + string_ProjectName + "' "
               "and Clamping = '" + string_ProjectClamping + "';");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
        log_QueryError(Q_FUNC_INFO, &query);

    while (query.next())
    {
        string_ProjectID = query.value("id").toString();
    }

    return string_ProjectID;
}

QStringList DataBase::get_Project()
{
    QStringList stringList;
    QString string;
    QSqlQuery query (main_DataBase);

    //Suche nach dem Project in der Datenbank,
    query.exec("SELECT id, Name, Status, Clamping FROM Project ORDER BY Name;");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
        log_QueryError(Q_FUNC_INFO, &query);

    while (query.next())
    {
        string = query.value("Name").toString();
        string = string + "_";
        string = string + query.value("Clamping").toString();

        stringList.append(string);
    }

    return stringList;
}

QStringList DataBase::get_ProjectsFromTag(QString string_Tag)
{
    QSqlQuery query (main_DataBase);
    QStringList stringList;
    QString string;

    query.exec("SELECT Project.Name, Project.Clamping FROM Tags "
              "INNER JOIN Project on "
              "Project.id = Tags.project_id "
              "WHERE tag = '" + string_Tag + "';");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
        log_QueryError(Q_FUNC_INFO, &query);

    while(query.next())
    {
        string = query.value("Project.Name").toString();
        string = string + "_";
        string = string + query.value("Project.Clamping").toString();

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
        log_QueryError(Q_FUNC_INFO, &query);

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
    query.exec("SELECT * FROM Tags WHERE project_id = '" + string_ProjectID +"' ORDER BY tag;");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
        log_QueryError(Q_FUNC_INFO, &query);

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

QString DataBase::get_TipLength(QString toolID)
{
    // Holt die Freistellange des Werkzeugs aus der Datenbank
    QSqlQuery query (tool_DataBase);
    QString string_TipLength;

    bool bool_Hals = true;

    string_TipLength = "0";

    query.exec("SELECT Tools.dbl_param5, Tools.bool_param2 from NCTools "
               "INNER JOIN Tools on "
               "Tools.id = NCTools.tool_id "
               "where NCTools.nc_number_str = '" + toolID + "';");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
        log_QueryError(Q_FUNC_INFO, &query);

    while (query.next())
    {
        string_TipLength = query.value("dbl_param5").toString();
        bool_Hals        = query.value("bool_param2").toBool();
    }

    if(!bool_Hals)
        string_TipLength = " - ";

    return string_TipLength;
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
        log_QueryError(Q_FUNC_INFO, &query);

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

QString DataBase::get_ToolLength(QString toolID)
{
    // Holt die Ausspannlaenge des Werkzeugs aus der Datenbank
    QSqlQuery query (tool_DataBase);
    QString string_ToolLength;
    string_ToolLength = "0";

    query.exec("select nc_number_str, tool_length from NCTools "
               "where nc_number_str = '" + toolID + "';");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
        log_QueryError(Q_FUNC_INFO, &query);

    while (query.next())
    {
        string_ToolLength = query.value("tool_length").toString();
    }
    return string_ToolLength;
}

void DataBase::get_Top100(ToolList* toolList)
{
    toolList->clear();
    Tool* tool;

    QSqlQuery query (main_DataBase);

    query.exec("select T_Number, counter, Description from NCTools order by counter desc, T_Number asc limit 100;");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
        log_QueryError(Q_FUNC_INFO, &query);

    int i = 0;
    while (query.next() && i < 100)
    {
        tool = new Tool(toolList);
        tool->set_Number(query.value("T_Number").toString());
        tool->set_Description(query.value("Description").toString());
        tool->set_Counter(query.value("counter").toInt());

        toolList->insert_Tool(tool);
        i++;
    }
}

QList<Item_TouchProbe> DataBase::get_TouchProbe(QString string_ProjectID)
{
    //qDebug() << Q_FUNC_INFO << string_ProjectID;

    QList<Item_TouchProbe> list;
    QSqlQuery query (main_DataBase);
    Struct_Ausrichten struct_Ausrichten;
    Struct_Ebenheit   struct_Ebenheit;
    Struct_Kante      struct_Kante;
    Struct_Steg       struct_Steg;
    Struct_Bohrung    struct_Bohrung;
    Struct_Nut        struct_Nut;

    Item_TouchProbe item;

    //--------- Lade TP_Ausrichten -----------------------------------------------------------
    query.exec("SELECT * FROM TP_Ausrichten "
               "WHERE project_id = '" + string_ProjectID + "';");

    if(!query.lastError().text().isEmpty())
    {
        log_QueryError(Q_FUNC_INFO, &query);
        return list;
    }

    while (query.next())
    {
        item = Item_TouchProbe();

        struct_Ausrichten = Struct_Ausrichten();
        struct_Ausrichten.string_Pos = query.value("Pos").toString();
        struct_Ausrichten.string_Frame = query.value("Frame").toString();
        struct_Ausrichten.string_Messrichtung = query.value("Messrichtung").toString();
        struct_Ausrichten.string_Messachse = query.value("Messachse").toString();
        struct_Ausrichten.string_Positionierachse = query.value("Positionierachse").toString();
        struct_Ausrichten.string_L2 = query.value("L2").toString();
        struct_Ausrichten.string_TSA = query.value("TSA").toString();
        struct_Ausrichten.string_Anfahren = query.value("Anfahren").toString();

        item.state = Item_TouchProbe::Ausrichten;
        item.Pos = struct_Ausrichten.string_Pos.toInt();
        item.struct_Ausrichten = struct_Ausrichten;

        list.append(item);
    }


    //--------------------Lade TP_Kante -----------------------------------------------------
    query.exec("SELECT * FROM TP_Kante "
               "WHERE project_id = '" + string_ProjectID + "';");

    if(!query.lastError().text().isEmpty())
    {
        log_QueryError(Q_FUNC_INFO, &query);
        return list;
    }

    while (query.next())
    {
        item = Item_TouchProbe();

        struct_Kante = Struct_Kante();
        struct_Kante.string_Pos = query.value("Pos").toString();
        struct_Kante.string_Frame = query.value("Frame").toString();
        struct_Kante.string_Messrichtung = query.value("Messrichtung").toString();
        struct_Kante.string_Messachse = query.value("Messachse").toString();
        struct_Kante.string_Wert = query.value("Wert").toString();
        struct_Kante.string_DFA = query.value("DFA").toString();
        struct_Kante.string_TSA = query.value("TSA").toString();
        struct_Kante.string_Anfahren = query.value("Anfahren").toString();

        item.state = Item_TouchProbe::Kante;
        item.Pos = struct_Kante.string_Pos.toInt();
        item.struct_Kante = struct_Kante;

        list.append(item);
    }

    //--------------------Lade TP_Ebenheit -----------------------------------------------------
    query.exec("SELECT * FROM TP_Ebenheit "
               "WHERE project_id = '" + string_ProjectID + "';");

    if(!query.lastError().text().isEmpty())
    {
        log_QueryError(Q_FUNC_INFO, &query);
        return list;
    }

    while (query.next())
    {
        item = Item_TouchProbe();

        struct_Ebenheit = Struct_Ebenheit();
        struct_Ebenheit.string_Pos = query.value("Pos").toString();
        struct_Ebenheit.string_Frame = query.value("Frame").toString();
        struct_Ebenheit.string_Vertrauensbereich = query.value("Vertrauensbereich").toString();
        struct_Ebenheit.string_ZEbene = query.value("ZEbene").toString();
        struct_Ebenheit.string_Punkt1X = query.value("Punkt1X").toString();
        struct_Ebenheit.string_Punkt1Y = query.value("Punkt1Y").toString();
        struct_Ebenheit.string_Punkt2X = query.value("Punkt2X").toString();
        struct_Ebenheit.string_Punkt2Y = query.value("Punkt2Y").toString();
        struct_Ebenheit.string_Punkt3X = query.value("Punkt3X").toString();
        struct_Ebenheit.string_Punkt3Y = query.value("Punkt3Y").toString();
        struct_Ebenheit.string_Punkt4X = query.value("Punkt4X").toString();
        struct_Ebenheit.string_Punkt4Y = query.value("Punkt4Y").toString();
        struct_Ebenheit.bool_Jump1 = query.value("Jump1").toBool();
        struct_Ebenheit.bool_Jump2 = query.value("Jump2").toBool();
        struct_Ebenheit.bool_Jump3 = query.value("Jump3").toBool();

        item.state = Item_TouchProbe::Ebenheit;
        item.Pos = struct_Ebenheit.string_Pos.toInt();
        item.struct_Ebenheit = struct_Ebenheit;

        list.append(item);
    }

    //--------------------Lade TP_Steg -----------------------------------------------------
    query.exec("SELECT * FROM TP_Steg "
               "WHERE project_id = '" + string_ProjectID + "';");

    if(!query.lastError().text().isEmpty())
    {
        log_QueryError(Q_FUNC_INFO, &query);
        return list;
    }

    while (query.next())
    {
        item = Item_TouchProbe();

        struct_Steg = Struct_Steg();
        struct_Steg.string_Pos = query.value("Pos").toString();
        struct_Steg.string_Frame = query.value("Frame").toString();
        struct_Steg.string_Messachse = query.value("Messachse").toString();
        struct_Steg.string_W = query.value("W").toString();
        struct_Steg.string_DZ = query.value("DZ").toString();
        struct_Steg.string_DFA = query.value("DFA").toString();
        struct_Steg.string_TSA = query.value("TSA").toString();
        struct_Steg.string_Anfahren = query.value("Anfahren").toString();

        item.state = Item_TouchProbe::Steg;
        item.Pos = struct_Steg.string_Pos.toInt();
        item.struct_Steg = struct_Steg;

        list.append(item);
    }

    //--------------------Lade TP_Nut -----------------------------------------------------
    query.exec("SELECT * FROM TP_Nut "
               "WHERE project_id = '" + string_ProjectID + "';");

    if(!query.lastError().text().isEmpty())
    {
        log_QueryError(Q_FUNC_INFO, &query);
        return list;
    }

    while (query.next())
    {
        item = Item_TouchProbe();

        struct_Nut = Struct_Nut();
        struct_Nut.string_Pos = query.value("Pos").toString();
        struct_Nut.string_Frame = query.value("Frame").toString();
        struct_Nut.string_Messachse = query.value("Messachse").toString();
        struct_Nut.string_W = query.value("W").toString();
        struct_Nut.string_DFA = query.value("DFA").toString();
        struct_Nut.string_TSA = query.value("TSA").toString();
        struct_Nut.string_Anfahren = query.value("Anfahren").toString();

        item.state = Item_TouchProbe::Nut;
        item.Pos = struct_Nut.string_Pos.toInt();
        item.struct_Nut = struct_Nut;

        list.append(item);
    }

    //--------------------Lade TP_Bohrung -----------------------------------------------------
    query.exec("SELECT * FROM TP_Bohrung "
               "WHERE project_id = '" + string_ProjectID + "';");

    if(!query.lastError().text().isEmpty())
    {
        log_QueryError(Q_FUNC_INFO, &query);
        return list;
    }

    while (query.next())
    {
        item = Item_TouchProbe();

        struct_Bohrung = Struct_Bohrung();
        struct_Bohrung.string_Pos = query.value("Pos").toString();
        struct_Bohrung.string_Frame = query.value("Frame").toString();
        struct_Bohrung.string_Durchmesser = query.value("Durchmesser").toString();
        struct_Bohrung.string_TSA = query.value("TSA").toString();
        struct_Bohrung.string_Anfahren = query.value("Anfahren").toString();

        item.state = Item_TouchProbe::Bohrung;
        item.Pos = struct_Bohrung.string_Pos.toInt();
        item.struct_Bohrung = struct_Bohrung;

        list.append(item);
    }

    //sortiere die Liste nach Position
    for (int i = 0; i<list.size(); i++)
    {

        for(int j = 0; j<i; j++)
        {
            if(list.at(i).Pos < list.at(j).Pos)
            {
                list.move(i,j);
                break;
            }
        }
    }

    //qDebug() << Q_FUNC_INFO << list.size();
    return list;
}

QList<QPixmap> DataBase::get_Pixmap(QString string_ProjectID)
{
    QSqlQuery query (main_DataBase);
    QList<QPixmap> list;
    QPixmap outPixmap;

    QByteArray byteArray;

    query.exec("SELECT * FROM Pictures "
               "WHERE project_id = '" + string_ProjectID + "';");

    if(!query.lastError().text().isEmpty())
    {
        log_QueryError(Q_FUNC_INFO, &query);
        list.clear();
        return list;
    }

    while (query.next())
    {
        outPixmap = QPixmap();
        byteArray = query.value("data").toByteArray();
        outPixmap.loadFromData( byteArray );
        list.append(outPixmap);
    }
}

bool DataBase::inc_ToolCounter(ToolList* toolList)
{
    QSqlQuery query (main_DataBase);
    int int_ToolCounter;

    foreach(Tool* tool, toolList->get_List())
    {
        int_ToolCounter = -1;

        // hol dir den Counter
        query.exec("SELECT counter FROM NCTools WHERE T_Number = '" + tool->get_Number() + "';");
        if(!query.lastError().text().isEmpty())
        {
            log_QueryError(Q_FUNC_INFO, &query);
            return false;
        }

        while (query.next())
        {
            int_ToolCounter = query.value("counter").toString().toInt();
        }

        // Wenn der Counter immer noch -1 ist brich ab
        if(int_ToolCounter == -1)
        {
            log->error(tool->get_Number() + " Counter = -1");
            return false;
        }

        // setzt den Counter um eins hoch
        int_ToolCounter++;

        // Update das Werkzeug
        query.exec("UPDATE NCTools SET counter=" + QString("%1").arg(int_ToolCounter) +
                   " WHERE T_Number = '" + tool->get_Number() + "';");

        if(!query.lastError().text().isEmpty())
        {
            log_QueryError(Q_FUNC_INFO, &query);
            return false;
        }
    }
    return true;
}

QString DataBase::insert_Tool(Tool* tool)
{
    QSqlQuery query (main_DataBase);
    QSqlQuery queryAdd (main_DataBase);
    QString string_ToolID;
    QString string_HolderID;

    // Suche nach dem Tool in der Datenbank,
    // wenn das Tool schon in der Datenbank existiert,
    // wird die ID zurückgeben
    query.exec("SELECT id, T_Number FROM NCTools "
               "WHERE T_Number = '" +
               tool->get_Number()+ "';");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
        log_QueryError(Q_FUNC_INFO, &query);

    while (query.next())
    {
        string_ToolID = query.value("id").toString();
    }

    // Wenn es das Tool in der Datenbank gibt wird
    // die ID zurückgeben
    if(!string_ToolID.isEmpty())
        return string_ToolID;


    //Trägt den Halter in die DatenBank ein und gibt die ID zurück
    //string_HolderID = insertHolder(tool->get_HalterName());

    // Ab hier gibt es das Tool noch nicht, es wird in die Datenbank
    // eingetragen.
    queryAdd.prepare("INSERT INTO NCTools (T_Number, Description, GageLength, ToolLength, TipLength, "
                     "counter) "
                     "VALUES (:T_Number, "
                     ":Description, "
                     ":GageLength, "
                     ":ToolLength, "
                     ":TipLength, "
                     ":counter)");
    queryAdd.bindValue(":T_Number", tool->get_Number());
    queryAdd.bindValue(":Description", tool->get_Description());
    queryAdd.bindValue(":GageLength", tool->get_GageLength());
    queryAdd.bindValue(":ToolLength", tool->get_ToolLength());
    queryAdd.bindValue(":TipLength", tool->get_TipLength());
    queryAdd.bindValue(":counter", 0);

    if(!queryAdd.exec())
    {
        // Wenn es einen Fehler gibt wird die Fehlermeldung an den Kommas
        // gesplittet und ausgegeben
        QStringList stringList_Split;
        stringList_Error.clear();
        stringList_Error.append(Q_FUNC_INFO);
        stringList_Error.append(" Project einfuegen fehlgeschlagen: ");
        stringList_Split = queryAdd.lastQuery().split(",");
        stringList_Error.append(stringList_Split);
        stringList_Split = queryAdd.lastError().text().split(",");
        stringList_Error.append(stringList_Split);
        log->frame_Error(stringList_Error);
    }

    // Nach dem Eintragen des Tools wird die ID neu gesucht und bei erfolg
    // zurückgegeben
    query.exec();
    while (query.next())
    {
        string_ToolID = query.value("id").toString();
    }

    return string_ToolID;
}

bool DataBase::insert_Programm(Item_Programm item, QString string_ProjectID, QString string_ProjectFullName)
{
    //QSqlQuery query (main_DataBase);
    QSqlQuery queryAdd (main_DataBase);

    int int_OffsetX = int(item.Offset_X);
    int int_OffsetY = int(item.Offset_Y);
    int int_OffsetZ = int(item.Offset_Z);
    int int_TOFFL = int(item.TOFFL);
    int int_NoXY  = int(item.NoXY);

    queryAdd.prepare("INSERT INTO Programm_Project (Programm, project_id, Project,"
                     "Offset_X, Offset_Y, Offset_Z, TOFFL, NoXY) "
                     "VALUES (:Programm, "
                     ":project_id, "
                     ":Project,"
                     ":Offset_X,"
                     ":Offset_Y,"
                     ":Offset_Z,"
                     ":TOFFL,"
                     ":NoXY)");
    queryAdd.bindValue(":Programm", item.Programm);
    queryAdd.bindValue(":project_id", string_ProjectID);
    queryAdd.bindValue(":Project", string_ProjectFullName);
    queryAdd.bindValue(":Offset_X", int_OffsetX);
    queryAdd.bindValue(":Offset_Y", int_OffsetY);
    queryAdd.bindValue(":Offset_Z", int_OffsetZ);
    queryAdd.bindValue(":TOFFL", int_TOFFL);
    queryAdd.bindValue(":NoXY", int_NoXY);

    if(!queryAdd.exec())
    {
        // Wenn es einen Fehler gibt wird die Fehlermeldung an den Kommas
        // gesplittet und ausgegeben
        QStringList stringList_Split;
        stringList_Error.clear();
        stringList_Error.append(Q_FUNC_INFO);
        stringList_Error.append(" Programm einfuegen fehlgeschlagen: ");
        stringList_Split = queryAdd.lastQuery().split(",");
        stringList_Error.append(stringList_Split);
        stringList_Split = queryAdd.lastError().text().split(",");
        stringList_Error.append(stringList_Split);
        log->frame_Error(stringList_Error);
        return false;
    }
    /*
    // Suche nach dem Programm in der Datenbank,
    // wenn es das Prgramm schon in der Datenbank existiert,
    // beende die Funktion mit TRUE
    query.exec("SELECT id, Programm, project_id FROM Programm_Project "
               "WHERE Programm  = '" + string_Prg + "' "
               "AND project_id = '" + string_ProjectID + "'; ");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
    {
        log_QueryError(Q_FUNC_INFO, &query);
        return false;
    }

    while (query.next())
    {
        string_ID = query.value("id").toString();
    }

    if(string_ID != "-1")
        return true;

    // ab hier wird eine neuer Eintrag erstellt
    queryAdd.prepare("INSERT INTO Programm_Project (Programm, project_id, Project) "
                    "VALUES (:Programm, "
                    ":project_id, "
                    ":Project)");
    queryAdd.bindValue(":Programm", string_Prg);
    queryAdd.bindValue(":project_id", string_ProjectID);
    queryAdd.bindValue(":Project", string_ProjectFullName);

    if(!queryAdd.exec())
    {
        // Wenn es einen Fehler gibt wird die Fehlermeldung an den Kommas
        // gesplittet und ausgegeben
        QStringList stringList_Split;
        stringList_Error.clear();
        stringList_Error.append(Q_FUNC_INFO);
        stringList_Error.append(" Programm einfuegen fehlgeschlagen: ");
        stringList_Split = queryAdd.lastQuery().split(",");
        stringList_Error.append(stringList_Split);
        stringList_Split = queryAdd.lastError().text().split(",");
        stringList_Error.append(stringList_Split);
        log->frame_Error(stringList_Error);
        return false;
    }
    */
    return true;
}

bool DataBase::insert_Tool(Tool* tool, QString string_ProjectID, QString string_ProjectFullName)
{
    QString string_ToolID;
    QString string_NCToolsProjectID;
    int int_ToolLife  = int(tool->get_ToolLife());

    QSqlQuery queryAdd (main_DataBase);

    // Trage das Tool in die Datenbank ein
    // Wenn das Fehlschlägt gib FALSE zurück
    string_ToolID = insert_Tool(tool);
    if(string_ToolID.isEmpty())
        return false;

    // Hol dir die ID aus NCTools-Project
    // Wenn es eine ID gibt, brech mit TRUE ab
    // Ansonsten trage eine neue Verbindung zwischen Werkzeug und Projekt ein
    string_NCToolsProjectID = get_NCToolProjectID(string_ToolID, string_ProjectID);

    if(string_NCToolsProjectID != "-1")
    {
        return true;
    }

    queryAdd.prepare("INSERT INTO NCTools_Project (nctool_id, T_Number, project_id, "
                                                  "Project, ToolLife, Parts) "
                     "VALUES (:nctool_id, "
                     ":T_Number, "
                     ":project_id, "
                     ":Project, "
                     ":ToolLife,"
                     ":Parts)");
    queryAdd.bindValue(":nctool_id", string_ToolID);
    queryAdd.bindValue(":T_Number", tool->get_Number());
    queryAdd.bindValue(":project_id", string_ProjectID);
    queryAdd.bindValue(":Project", string_ProjectFullName);
    queryAdd.bindValue(":ToolLife", int_ToolLife);
    queryAdd.bindValue(":Parts", tool->get_Parts());
    if(!queryAdd.exec())
    {
        // Wenn es einen Fehler gibt wird die Fehlermeldung an den Kommas
        // gesplittet und ausgegeben
        QStringList stringList_Split;
        stringList_Error.clear();
        stringList_Error.append(Q_FUNC_INFO);
        stringList_Error.append(" Eintrag in die Zuordnungstabelle");
        stringList_Error.append(" NCTools_Project fehlgeschlagen");
        stringList_Split = queryAdd.lastQuery().split(",");
        stringList_Error.append(stringList_Split);
        stringList_Split = queryAdd.lastError().text().split(",");
        stringList_Error.append(stringList_Split);
        log->frame_Error(stringList_Error);
        return false;
    }
    return true;
}

void DataBase::insert_TPAusrichten(Struct_Ausrichten ausrichten, QString string_ProjectID)
{
    QSqlQuery query (main_DataBase);

    query.prepare("INSERT INTO TP_Ausrichten (project_id, Project, Pos, Frame, Messrichtung, "
                                             "Messachse, Positionierachse, L2, TSA, Anfahren) "
                     "VALUES (:project_id, "
                     ":Project, "
                     ":Pos, "
                     ":Frame, "
                     ":Messrichtung, "
                     ":Messachse, "
                     ":Positionierachse, "
                     ":L2, "
                     ":TSA, "
                     ":Anfahren)");
    query.bindValue(":project_id", string_ProjectID);
    query.bindValue(":Project", " ");
    query.bindValue(":Pos", ausrichten.string_Pos);
    query.bindValue(":Frame", ausrichten.string_Frame);
    query.bindValue(":Messrichtung", ausrichten.string_Messrichtung);
    query.bindValue(":Messachse", ausrichten.string_Messachse);
    query.bindValue(":Positionierachse", ausrichten.string_Positionierachse);
    query.bindValue(":L2", ausrichten.string_L2);
    query.bindValue(":TSA", ausrichten.string_TSA);
    query.bindValue(":Anfahren", ausrichten.string_Anfahren);



    if(!query.exec())
    {
        // Wenn es einen Fehler gibt wird die Fehlermeldung an den Kommas
        // gesplittet und ausgegeben
        QStringList stringList_Split;
        stringList_Error.clear();
        stringList_Error.append(Q_FUNC_INFO);
        stringList_Error.append(" Ausrichten einfuegen fehlgeschlagen: ");
        stringList_Split = query.lastQuery().split(",");
        stringList_Error.append(stringList_Split);
        stringList_Split = query.lastError().text().split(",");
        stringList_Error.append(stringList_Split);
        log->frame_Error(stringList_Error);
    }
}

void DataBase::insert_TPBohrung(Struct_Bohrung bohrung, QString string_ProjectID)
{
    QSqlQuery query (main_DataBase);

    query.prepare("INSERT INTO TP_Bohrung (project_id, Project, Pos, Frame, Durchmesser, "
                  "TSA, Anfahren) "
                  "VALUES (:project_id, "
                  ":Project, "
                  ":Pos, "
                  ":Frame, "
                  ":Durchmesser, "
                  ":TSA, "
                  ":Anfahren)");
    query.bindValue(":project_id", string_ProjectID);
    query.bindValue(":Project", " ");
    query.bindValue(":Pos", bohrung.string_Pos);
    query.bindValue(":Frame", bohrung.string_Frame);
    query.bindValue(":Durchmesser", bohrung.string_Durchmesser);
    query.bindValue(":TSA", bohrung.string_TSA);
    query.bindValue(":Anfahren", bohrung.string_Anfahren);

    if(!query.exec())
    {
        // Wenn es einen Fehler gibt wird die Fehlermeldung an den Kommas
        // gesplittet und ausgegeben
        QStringList stringList_Split;
        stringList_Error.clear();
        stringList_Error.append(Q_FUNC_INFO);
        stringList_Error.append(" Bohrung einfuegen fehlgeschlagen: ");
        stringList_Split = query.lastQuery().split(",");
        stringList_Error.append(stringList_Split);
        stringList_Split = query.lastError().text().split(",");
        stringList_Error.append(stringList_Split);
        log->frame_Error(stringList_Error);
    }
}

void DataBase::insert_TPEbenheit(Struct_Ebenheit ebenheit, QString string_ProjectID)
{
    int int_Jump1 = int(ebenheit.bool_Jump1);
    int int_Jump2 = int(ebenheit.bool_Jump2);
    int int_Jump3 = int(ebenheit.bool_Jump3);

    QSqlQuery query (main_DataBase);

    query.prepare("INSERT INTO TP_Ebenheit (project_id, Project, Pos, Frame, ZEbene, Vertrauensbereich, "
                  "Punkt1X, Punkt1Y, Punkt2X, Punkt2Y, Punkt3X, Punkt3Y, Punkt4X, Punkt4Y, "
                  "Jump1, Jump2, Jump3) "
                  "VALUES (:project_id, "
                  ":Project, "
                  ":Pos, "
                  ":Frame, "
                  ":ZEbene, "
                  ":Vertrauensbereich, "
                  ":Punkt1X, "
                  ":Punkt1Y, "
                  ":Punkt2X, "
                  ":Punkt2Y, "
                  ":Punkt3X, "
                  ":Punkt3Y, "
                  ":Punkt4X, "
                  ":Punkt4Y, "
                  ":Jump1, "
                  ":Jump2, "
                  ":Jump3)");
    query.bindValue(":project_id", string_ProjectID);
    query.bindValue(":Project", " ");
    query.bindValue(":Pos", ebenheit.string_Pos);
    query.bindValue(":Frame", ebenheit.string_Frame);
    query.bindValue(":ZEbene", ebenheit.string_ZEbene);
    query.bindValue(":Vertrauensbereich", ebenheit.string_Vertrauensbereich);
    query.bindValue(":Punkt1X", ebenheit.string_Punkt1X);
    query.bindValue(":Punkt1Y", ebenheit.string_Punkt1Y);
    query.bindValue(":Punkt2X", ebenheit.string_Punkt2X);
    query.bindValue(":Punkt2Y", ebenheit.string_Punkt2Y);
    query.bindValue(":Punkt3X", ebenheit.string_Punkt3X);
    query.bindValue(":Punkt3Y", ebenheit.string_Punkt3Y);
    query.bindValue(":Punkt4X", ebenheit.string_Punkt4X);
    query.bindValue(":Punkt4Y", ebenheit.string_Punkt4Y);
    query.bindValue(":Jump1", int_Jump1);
    query.bindValue(":Jump2", int_Jump2);
    query.bindValue(":Jump3", int_Jump3);

    if(!query.exec())
    {
        // Wenn es einen Fehler gibt wird die Fehlermeldung an den Kommas
        // gesplittet und ausgegeben
        QStringList stringList_Split;
        stringList_Error.clear();
        stringList_Error.append(Q_FUNC_INFO);
        stringList_Error.append(" Ausrichten einfuegen fehlgeschlagen: ");
        stringList_Split = query.lastQuery().split(",");
        stringList_Error.append(stringList_Split);
        stringList_Split = query.lastError().text().split(",");
        stringList_Error.append(stringList_Split);
        log->frame_Error(stringList_Error);
    }
}

void DataBase::insert_TPKante(Struct_Kante kante, QString string_ProjectID)
{
    QSqlQuery query (main_DataBase);

    query.prepare("INSERT INTO TP_Kante (project_id, Project, Pos, Frame, Messrichtung, "
                  "Messachse, Wert, DFA, TSA, Anfahren) "
                  "VALUES (:project_id, "
                  ":Project, "
                  ":Pos, "
                  ":Frame, "
                  ":Messrichtung, "
                  ":Messachse, "
                  ":Wert, "
                  ":DFA, "
                  ":TSA, "
                  ":Anfahren)");
    query.bindValue(":project_id", string_ProjectID);
    query.bindValue(":Project", " ");
    query.bindValue(":Pos", kante.string_Pos);
    query.bindValue(":Frame", kante.string_Frame);
    query.bindValue(":Messrichtung", kante.string_Messrichtung);
    query.bindValue(":Messachse", kante.string_Messachse);
    query.bindValue(":Wert", kante.string_Wert);
    query.bindValue(":DFA", kante.string_DFA);
    query.bindValue(":TSA", kante.string_TSA);
    query.bindValue(":Anfahren", kante.string_Anfahren);



    if(!query.exec())
    {
        // Wenn es einen Fehler gibt wird die Fehlermeldung an den Kommas
        // gesplittet und ausgegeben
        QStringList stringList_Split;
        stringList_Error.clear();
        stringList_Error.append(Q_FUNC_INFO);
        stringList_Error.append(" Kante einfuegen fehlgeschlagen: ");
        stringList_Split = query.lastQuery().split(",");
        stringList_Error.append(stringList_Split);
        stringList_Split = query.lastError().text().split(",");
        stringList_Error.append(stringList_Split);
        log->frame_Error(stringList_Error);
    }
}

void DataBase::insert_TPSteg(Struct_Steg steg, QString string_ProjectID)
{
    QSqlQuery query (main_DataBase);

    query.prepare("INSERT INTO TP_Steg (project_id, Project, Pos, Frame, Messachse, "
                  "W, DZ, DFA, TSA, Anfahren) "
                  "VALUES (:project_id, "
                  ":Project, "
                  ":Pos, "
                  ":Frame, "
                  ":Messachse, "
                  ":W, "
                  ":DZ, "
                  ":DFA, "
                  ":TSA, "
                  ":Anfahren)");
    query.bindValue(":project_id", string_ProjectID);
    query.bindValue(":Project", " ");
    query.bindValue(":Pos", steg.string_Pos);
    query.bindValue(":Frame", steg.string_Frame);
    query.bindValue(":Messachse", steg.string_Messachse);
    query.bindValue(":W", steg.string_W);
    query.bindValue(":DZ", steg.string_DZ);
    query.bindValue(":DFA", steg.string_DFA);
    query.bindValue(":TSA", steg.string_TSA);
    query.bindValue(":Anfahren", steg.string_Anfahren);

    if(!query.exec())
    {
        // Wenn es einen Fehler gibt wird die Fehlermeldung an den Kommas
        // gesplittet und ausgegeben
        QStringList stringList_Split;
        stringList_Error.clear();
        stringList_Error.append(Q_FUNC_INFO);
        stringList_Error.append(" Steg einfuegen fehlgeschlagen: ");
        stringList_Split = query.lastQuery().split(",");
        stringList_Error.append(stringList_Split);
        stringList_Split = query.lastError().text().split(",");
        stringList_Error.append(stringList_Split);
        log->frame_Error(stringList_Error);
    }
}

void DataBase::insert_TPNut(Struct_Nut nut, QString string_ProjectID)
{
    QSqlQuery query (main_DataBase);

    query.prepare("INSERT INTO TP_Nut (project_id, Project, Pos, Frame, Messachse, "
                  "W, DFA, TSA, Anfahren) "
                  "VALUES (:project_id, "
                  ":Project, "
                  ":Pos, "
                  ":Frame, "
                  ":Messachse, "
                  ":W, "
                  ":DFA, "
                  ":TSA, "
                  ":Anfahren)");
    query.bindValue(":project_id", string_ProjectID);
    query.bindValue(":Project", " ");
    query.bindValue(":Pos", nut.string_Pos);
    query.bindValue(":Frame", nut.string_Frame);
    query.bindValue(":Messachse", nut.string_Messachse);
    query.bindValue(":W", nut.string_W);
    query.bindValue(":DFA", nut.string_DFA);
    query.bindValue(":TSA", nut.string_TSA);
    query.bindValue(":Anfahren", nut.string_Anfahren);

    if(!query.exec())
    {
        // Wenn es einen Fehler gibt wird die Fehlermeldung an den Kommas
        // gesplittet und ausgegeben
        QStringList stringList_Split;
        stringList_Error.clear();
        stringList_Error.append(Q_FUNC_INFO);
        stringList_Error.append(" Nut einfuegen fehlgeschlagen: ");
        stringList_Split = query.lastQuery().split(",");
        stringList_Error.append(stringList_Split);
        stringList_Split = query.lastError().text().split(",");
        stringList_Error.append(stringList_Split);
        log->frame_Error(stringList_Error);
    }
}

void DataBase::insert_Picture(MLabel* label, QString string_ProjectID)
{
    QSqlQuery query (main_DataBase);
    QPixmap pixmap = label->get_Pixmap();

    // schreibe das Pixmap in ein QByteArray
    QByteArray inByteArray;
    QBuffer buffer(&inByteArray);
    buffer.open(QIODevice::WriteOnly);
    pixmap.save(&buffer, "PNG");

    //qDebug() << inByteArray;

    // Bild-Bytes in Datenbank schreiben
    // Hinweis: Achte darauf, dass die :platzhalter in Klammern stehen
    query.prepare( "INSERT INTO Pictures (project_id, data) VALUES (:project_id, :data)" );
    query.bindValue(":project_id", string_ProjectID);
    query.bindValue( ":data", inByteArray );

    if(!query.exec())
    {
        // Wenn es einen Fehler gibt wird die Fehlermeldung an den Kommas
        // gesplittet und ausgegeben
        stringList_Error.clear();
        stringList_Error.append(Q_FUNC_INFO);
        stringList_Error.append(" Bild einfuegen fehlgeschlagen: ");
        log->frame_Error(stringList_Error);
    }

}

void DataBase::insert_Tags(QString string_Tag, QString string_ProjectID)
{
    QSqlQuery query (main_DataBase);

    // Tag in Datenbank schreiben
    // Hinweis: Achte darauf, dass die :platzhalter in Klammern stehen
    query.prepare( "INSERT INTO Tags (project_id, tag) VALUES (:project_id, :tag)" );
    query.bindValue(":project_id", string_ProjectID);
    query.bindValue( ":tag", string_Tag );

    if(!query.exec())
    {
        // Wenn es einen Fehler gibt wird die Fehlermeldung an den Kommas
        // gesplittet und ausgegeben
        stringList_Error.clear();
        stringList_Error.append(Q_FUNC_INFO);
        stringList_Error.append(" Bild einfuegen fehlgeschlagen: ");
        log->frame_Error(stringList_Error);
    }

}

void DataBase::log_QueryError(QString string_FuncInfo, QSqlQuery* query)
{
    stringList_Error.clear();
    stringList_Error.append("ERROR");
    stringList_Error.append(string_FuncInfo);
    stringList_Error.append(query->lastError().text());
    log->frame_Error(stringList_Error);
}

bool DataBase::open()
{
    stringList_Error.clear();
    QFile file_ToolDataBase(string_ToolDB);
    QFile file_MainDataBase(string_MainDB);

    if(!file_ToolDataBase.exists())
    {
        stringList_Error.append(Q_FUNC_INFO);
        stringList_Error.append(string_ToolDB);
        stringList_Error.append("konnte nicht gefunden werden");
        log->frame_Error(stringList_Error);
        return false;
    }

    if(!file_MainDataBase.exists())
    {
        stringList_Error.append(Q_FUNC_INFO);
        stringList_Error.append(string_MainDB);
        stringList_Error.append("konnte nicht gefunden werden");
        log->frame_Error(stringList_Error);
        return false;
    }

    if(!main_DataBase.open())
    {
        stringList_Error.append("ERROR");
        stringList_Error.append(" open main_DataBase FAILED");
        log->frame_Error(stringList_Error);
        return false;
    }

    if(!tool_DataBase.open())
    {
        stringList_Error.append("ERROR");
        stringList_Error.append(" open Tool_DataBase FAILED");
        log->frame_Error(stringList_Error);
        return false;
    }

    return true;
}

void DataBase::set_LastProduction(QString string_ProjectID)
{
    QSqlQuery query (main_DataBase);

    // Update Project Last_Production
    query.exec("UPDATE Project SET Last_Production= '" + QDateTime::currentDateTime().toString(Qt::ISODate) + "'"
               " WHERE id = " + string_ProjectID + ";");

    qDebug() << query.lastQuery();

    if(!query.lastError().text().isEmpty())
    {
        log_QueryError(Q_FUNC_INFO, &query);
    }
}

bool DataBase::save_Project(QMap<QString, QString> map_Data)
{
    QSqlQuery query (main_DataBase);
    QSqlQuery queryAdd (main_DataBase);
    QString string_ProjectID;
    bool bool_Return = true;

    //Suche nach dem Project in der Datenbank,
    query.exec("SELECT id, Name, Status, Clamping from Project "
               "where Name = '" + map_Data.value("Name") + "' "
               "and Clamping = '" + map_Data.value("Clamping") + "';");

    while (query.next())
    {
        string_ProjectID = query.value("id").toString();
    }

    // Wenn es das Project noch nicht gibt wird es angelegt
    if(string_ProjectID.isEmpty())
    {
        queryAdd.prepare("INSERT INTO Project (Name, Status, Clamping, "
                         "RawPart_X, RawPart_Y, RawPart_Z, "
                         "Component_X, Component_Y, Component_Z, "
                         "ZRawPart, ZeroPoint, Material, RawPartInspection, "
                         "CamFile, Comment, Last_Production, "
                         "XPlus_Max, XMinus_Max, "
                         "YPlus_Max, YMinus_Max, "
                         "ZPlus_Max, NPx, NPy, NPz) "
                         "VALUES (:Name, :Status, :Clamping, "
                         ":RawPart_X, :RawPart_Y, :RawPart_Z, "
                         ":Component_X, :Component_Y, :Component_Z, "
                         ":ZRawPart, :ZeroPoint, :Material, :RawPartInspection, "
                         ":CamFile, :Comment, :Last_Production, "
                         ":XPlus_Max, :XMinus_Max, "
                         ":YPlus_Max, :YMinus_Max, "
                         ":ZPlus_Max, :NPx, :NPy, :NPz)");

        queryAdd.bindValue(":Name", map_Data.value("Name"));
        queryAdd.bindValue(":Status", map_Data.value("Status"));
        queryAdd.bindValue(":Clamping", map_Data.value("Clamping"));

        queryAdd.bindValue(":CamFile", map_Data.value("CamFile"));
        queryAdd.bindValue(":Comment", map_Data.value("Comment"));

        queryAdd.bindValue(":Last_Production", map_Data.value("Last_Production"));

        queryAdd.bindValue(":RawPart_X", map_Data.value("RawPart_X"));
        queryAdd.bindValue(":RawPart_Y", map_Data.value("RawPart_Y"));
        queryAdd.bindValue(":RawPart_Z", map_Data.value("RawPart_Z"));

        queryAdd.bindValue(":Component_X", map_Data.value("Component_X"));
        queryAdd.bindValue(":Component_Y", map_Data.value("Component_Y"));
        queryAdd.bindValue(":Component_Z", map_Data.value("Component_Z"));

        queryAdd.bindValue(":ZRawPart", map_Data.value("ZRawPart"));
        queryAdd.bindValue(":ZeroPoint", map_Data.value("ZeroPoint"));
        queryAdd.bindValue(":Material", map_Data.value("Material"));
        queryAdd.bindValue(":RawPartInspection", map_Data.value("RawPartInspection"));

        queryAdd.bindValue(":XPlus_Max", map_Data.value("XPlus_Max"));
        queryAdd.bindValue(":XMinus_Max", map_Data.value("XMinus_Max"));
        queryAdd.bindValue(":YPlus_Max", map_Data.value("YPlus_Max"));
        queryAdd.bindValue(":YMinus_Max", map_Data.value("YMinus_Max"));
        queryAdd.bindValue(":ZPlus_Max", map_Data.value("ZPlus_Max"));

        queryAdd.bindValue(":NPx", map_Data.value("NPx"));
        queryAdd.bindValue(":NPy", map_Data.value("NPy"));
        queryAdd.bindValue(":NPz", map_Data.value("NPz"));

        qDebug() << map_Data;
        if(!queryAdd.exec())
        {
            // Wenn es einen Fehler gibt wird die Fehlermeldung an den Kommas
            // gesplittet und ausgegeben
            QStringList stringList_Split;
            stringList_Error.clear();
            stringList_Error.append(Q_FUNC_INFO);
            stringList_Error.append(" Project einfuegen fehlgeschlagen: ");
            stringList_Split = queryAdd.lastQuery().split(",");
            stringList_Error.append(stringList_Split);
            stringList_Split = queryAdd.lastError().text().split(",");
            stringList_Error.append(stringList_Split);
            log->frame_Error(stringList_Error);
            bool_Return = false;
            qDebug() << map_Data;
        }
    }

    //Wenn das Project schon existiert wird es mit den aktuellen Werten überschrieben
    else
    {
        queryAdd.prepare("UPDATE Project SET Status='" + map_Data.value("Status") + "', "
                         "RawPart_X='" + map_Data.value("RawPart_X") + "', "
                         "RawPart_Y='" + map_Data.value("RawPart_Y") + "', "
                         "RawPart_Z='" + map_Data.value("RawPart_Z") + "', "
                         "Component_X='" + map_Data.value("Component_X") + "', "
                         "Component_Y='" + map_Data.value("Component_Y") + "', "
                         "Component_Z='" + map_Data.value("Component_Z") + "', "
                         "ZRawPart='" + map_Data.value("ZRawPart") + "', "
                         "ZeroPoint='" + map_Data.value("ZeroPoint") + "', "
                         "Material='" + map_Data.value("Material") + "', "
                         "RawPartInspection='" + map_Data.value("RawPartInspection") + "', "
                         "CamFile='" + map_Data.value("CamFile") + "', "
                         "XPlus_Max='" + map_Data.value("XPlus_Max") + "', "
                         "XMinus_Max='" + map_Data.value("XMinus_Max") + "', "
                         "YPlus_Max='" + map_Data.value("YPlus_Max") + "', "
                         "YMinus_Max='" + map_Data.value("YMinus_Max") + "', "
                         "ZPlus_Max='" + map_Data.value("ZPlus_Max") + "', "
                         "NPx='" + map_Data.value("NPx") + "', "
                         "NPy='" + map_Data.value("NPy") + "', "
                         "NPz='" + map_Data.value("NPz") + "', "
                         "Last_Production='" + map_Data.value("Last_Production") + "', "                                                              
                         "Comment='" + map_Data.value("Comment") + "' "
                         "where Name = '" + map_Data.value("Name") + "' "
                         "and Clamping = '" + map_Data.value("Clamping") + "';");

        if(!queryAdd.exec())
        {
            // Wenn es einen Fehler gibt wird die Fehlermeldung an den Kommas
            // gesplittet und ausgegeben
            QStringList stringList_Split;
            stringList_Error.clear();
            stringList_Error.append(Q_FUNC_INFO);
            stringList_Error.append(" Project einfuegen fehlgeschlagen: ");
            stringList_Split = queryAdd.lastQuery().split(",");
            stringList_Error.append(stringList_Split);
            stringList_Split = queryAdd.lastError().text().split(",");
            stringList_Error.append(stringList_Split);
            log->frame_Error(stringList_Error);
            bool_Return = false;
        }
    }
    return bool_Return;
}

