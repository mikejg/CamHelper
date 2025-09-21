#include "database.h"
#include <QBuffer>

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

bool DataBase::delete_ProjectData(ProjectData* pd)
{
    QString string_ProjectID = pd->id;
    QSqlQuery query (main_DataBase);

    query.exec("DELETE FROM Project "
               "WHERE id = '" + string_ProjectID + "';");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
    {
        log->vailed(Q_FUNC_INFO);
        log->vailed(query.lastError().text());
        return false;
    }

    if(!delete_FromTable("RawPart", pd->id)) return false;
    if(!delete_FromTable("FinishPart", pd->id)) return false;
    if(!delete_FromTable("ZeroPoint", pd->id)) return false;
    if(!delete_FromTable("Programm_Project", pd->id)) return false;
    if(!delete_FromTable("Pictures", pd->id)) return false;
    if(!delete_FromTable("NCTools_Project", pd->id)) return false;
    if(!delete_FromTable("TP_Ausrichten", pd->id)) return false;
    if(!delete_FromTable("TP_Bohrung", pd->id)) return false;
    if(!delete_FromTable("TP_Ebenheit", pd->id)) return false;
    if(!delete_FromTable("TP_Kante", pd->id)) return false;
    if(!delete_FromTable("TP_Nut", pd->id)) return false;
    if(!delete_FromTable("TP_Steg", pd->id)) return false;
    if(!delete_FromTable("Tags", pd->id)) return false;
    if(!delete_FromTable("Offset_RawPart", pd->id)) return false;

    return true;
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

bool DataBase::delete_FromTable(QString string_Table, QString string_ProjectID)
{
    QSqlQuery query (main_DataBase);

    query.exec("DELETE FROM " + string_Table + " "
               "WHERE Project_ID = '" + string_ProjectID + "';");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
    {
        log->vailed(Q_FUNC_INFO);
        log->vailed(query.lastError().text());
        return false;
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

QString DataBase::get_GageLength(QString toolID)
{
    // Holt die Ausspannlaenge des Werkzeugs aus der Datenbank
    QSqlQuery query (tool_DataBase);
    QString string_GageLength;
    string_GageLength = "0";

    query.exec("select nc_number_str, gage_length from NCTools "
               "where nc_number_str = '" + toolID + "';");

    if(!query.lastError().text().isEmpty())
    {
        log->vailed(query.lastError().text());
        return "";
    }

    while (query.next())
    {
        string_GageLength = query.value("gage_length").toString();
    }
    return string_GageLength;
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
        insert_Picutres(&projectData);
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
               "WHERE Project_ID = '" + string_ProjectID +"' "
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

ProjectData* DataBase::get_Project(QString string_ProjectId)
{
    ProjectData* projectData;
    projectData =  new ProjectData();

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
        projectData->name                = query.value("Name").toString();
        projectData->id                  = query.value("id").toString();
        projectData->state               = query.value("State").toString();
        projectData->material            = query.value("Material").toString();
        projectData->tension             = query.value("Tension").toString();
        projectData->rawPart_Inspection  = query.value("RawPartInspection").toString();
        projectData->hyperMILL_File      = query.value("hyperMILL_File").toString();
        projectData->header              = query.value("Header").toString();
        projectData->lastProduction      = query.value("Last_Production").toString();
        projectData->lastOpen            = query.value("Last_Open").toString();

        insert_FinishPart(projectData);     //Schreib die Fertigteilmasse ins Projekt
        insert_Picutres(projectData);       //Schreib die Bilder ins Projekt
        insert_RawPart(projectData);        //Schreib die Rohteilmasse ins Projekt
        insert_ToolList(projectData);       //Schreib die Werkzeuge ins Projekt
        insert_ZeroPoint(projectData);      //Schreib den Nullpunkt ins Projekt
        insert_OffsetRawPart(projectData);  //Schreib die Rohteil Aufmasse ins Projekt
        insert_Programm(projectData);       //Schreib die Programm ins Projekt
        insert_TouchProbe(projectData);
    }

    return projectData;
}

ProjectData* DataBase::get_Project(QString string_Name, QString string_Tension)
{
    QSqlQuery query(main_DataBase);
    ProjectData* projectData;
    projectData =  new ProjectData();

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

bool DataBase::get_ProjectID(ProjectData* pd)
{
    QSqlQuery query (main_DataBase);

    //Suche nach dem Project in der Datenbank,
    query.exec("SELECT id, Name, Tension from Project "
               "where Name = '" + pd->name + "' "
               "and Tension = '" + pd->tension + "';");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
    {
        log->vailed(Q_FUNC_INFO);
        log->vailed(query.lastError().text());
        return false;
    }

    while (query.next())
    {
        pd->id = query.value("id").toString();
    }

    return true;
}

QStringList DataBase::get_ProjectFromTag(QString string_Tag)
{
    QSqlQuery query (main_DataBase);
    QStringList returnList;
    QString string;

    query.exec("SELECT Project.Name, Project.Tension FROM Tags "
               "INNER JOIN Project on "
               "Project.id = Tags.Project_ID "
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

bool DataBase::save(ProjectData* pd)
{
    if(!delete_ProjectData(pd))
        return false;

    QSqlQuery query (main_DataBase);

    if(!get_ProjectID(pd))  //Suche nach dem Project in der Datenbank und
        return false;       //schreibe die ID in ProjectData


    query.prepare("INSERT INTO Project (Name, State, Material, Tension, "
                  "RawPartInspection, hyperMILL_File, Header, "
                  "Last_Production, Last_Open) "
                  "VALUES (:Name, :State, :Material, :Tension, "
                  ":RawPartInspection, :hyperMILL_File, :Header, "
                  ":Last_Production, :Last_Open)");
    query.bindValue(":Name", pd->name);
    query.bindValue(":State", pd->state);
    query.bindValue(":Material", pd->material);
    query.bindValue(":Tension", pd->tension);
    query.bindValue(":RawPartInspection", pd->rawPart_Inspection);
    query.bindValue(":hyperMILL_File", pd->hyperMILL_File);
    query.bindValue(":Header",pd->header);
    query.bindValue(":Last_Production", pd->lastProduction);
    query.bindValue(":Last_Open", pd->lastOpen);


    if(!query.exec())
    {
        log->vailed(Q_FUNC_INFO);
        log->vailed(query.lastError().text());
        log->vailed(query.lastQuery());
        return false;
    }

    if(!get_ProjectID(pd))  //Suche nach dem Project in der Datenbank und
        return false;       //schreibe die ID in ProjectData

    if(!save_RawPart(pd)) return false;
    if(!save_FinishPart(pd)) return false;
    if(!save_ZeroPoint(pd)) return false;
    if(!save_Programm(pd)) return false;
    if(!save_Picture(pd)) return false;
    if(!save_NCTools(pd)) return false;
    if(!save_TouchProbe(pd)) return false;
    if(!save_Tags(pd)) return false;
    if(!save_Offset_RawPart(pd)) return false;

    return true;
}

bool DataBase::save_TouchProbe(ProjectData* pd)
{
    Struct_Ausrichten struct_Ausrichten;
    Struct_Kante      struct_Kante;
    Struct_Ebenheit   struct_Ebenheit;
    Struct_Steg       struct_Steg;
    Struct_Bohrung    struct_Bohrung;
    Struct_Nut        struct_Nut;

    int pos = 0;
    foreach (Item_TouchProbe item, pd->list_TouchProbe)
    {
        if(item.state == Item_TouchProbe::Ausrichten)
        {
            struct_Ausrichten = item.struct_Ausrichten;
            struct_Ausrichten.string_Pos = QString("%1").arg(pos);
            if(!create_TPAusrichten(struct_Ausrichten, pd->id))
                return false;
            pos++;
            continue;
        }

        if(item.state == Item_TouchProbe::Kante)
        {
            struct_Kante = item.struct_Kante;
            struct_Kante.string_Pos = QString("%1").arg(pos);
            if(!create_TPKante(struct_Kante, pd->id))
                return false;
            pos++;
            continue;
        }

        if(item.state == Item_TouchProbe::Ebenheit)
        {
            struct_Ebenheit = item.struct_Ebenheit;
            struct_Ebenheit.string_Pos = QString("%1").arg(pos);
            if(!create_TPEbenheit(struct_Ebenheit, pd->id))
                return false;
            pos++;
            continue;
        }

        if(item.state == Item_TouchProbe::Steg)
        {
            struct_Steg = item.struct_Steg;
            struct_Steg.string_Pos = QString("%1").arg(pos);
            if(!create_TPSteg(struct_Steg, pd->id))
                return false;
            pos++;
            continue;
        }

        if(item.state == Item_TouchProbe::Bohrung)
        {
            struct_Bohrung = item.struct_Bohrung;
            struct_Bohrung.string_Pos = QString("%1").arg(pos);
            if(!create_TPBohrung(struct_Bohrung, pd->id))
                return false;
            pos++;
            continue;
        }

        if(item.state == Item_TouchProbe::Nut)
        {
            struct_Nut = item.struct_Nut;
            struct_Nut.string_Pos = QString("%1").arg(pos);
            if(!create_TPNut(struct_Nut, pd->id))
                return false;
            pos++;
            continue;
        }
    }
    return true;
}

bool DataBase::save_Tags(ProjectData* pd)
{
    QSqlQuery query (main_DataBase);

    foreach (QString string_Tag, pd->listTags)
    {
        // Tag in Datenbank schreiben
        // Hinweis: Achte darauf, dass die :platzhalter in Klammern stehen
        query.prepare( "INSERT INTO Tags (Project_ID, tag) VALUES (:Project_ID, :tag)" );
        query.bindValue(":Project_ID", pd->id);
        query.bindValue( ":tag", string_Tag );

        if(!query.exec())
        {
            log->vailed(Q_FUNC_INFO);
            log->vailed(query.lastError().text());
            log->vailed(query.lastQuery());
            return false;
        }
    }
    return true;
}

bool DataBase::save_RawPart(ProjectData* pd)
{
    QSqlQuery query (main_DataBase);
    query.prepare("INSERT INTO RawPart (Project_ID, x_Length, y_Width, z_Height, z_RawPart) "
                  "VALUES (:Project_ID, :x_Length, :y_Width, :z_Height, :z_RawPart)");
    query.bindValue(":Project_ID", pd->id);
    query.bindValue(":x_Length", pd->rawPart.x_Length);
    query.bindValue(":y_Width", pd->rawPart.y_Width);
    query.bindValue(":z_Height", pd->rawPart.z_Height);
    query.bindValue(":z_RawPart", pd->rawPart.z_RawPart);

    if(!query.exec())
    {
        log->vailed(Q_FUNC_INFO);
        log->vailed(query.lastError().text());
        log->vailed(query.lastQuery());
        return false;
    }
    return true;
}

bool DataBase::save_Offset_RawPart(ProjectData* pd)
{
    QSqlQuery query (main_DataBase);
    query.prepare("INSERT INTO Offset_RawPart (Project_ID, X_Plus, X_Minus, Y_Plus, Y_Minus, Z_Plus) "
                  "VALUES (:Project_ID, :X_Plus, :X_Minus, :Y_Plus, :Y_Minus, :Z_Plus)");
    query.bindValue(":Project_ID", pd->id);
    query.bindValue(":X_Plus", pd->offset_RawPart.string_Max_XPlus);
    query.bindValue(":X_Minus", pd->offset_RawPart.string_Max_XMinus);
    query.bindValue(":Y_Plus", pd->offset_RawPart.string_Max_YPlus);
    query.bindValue(":Y_Minus", pd->offset_RawPart.string_Max_YMinus);
    query.bindValue(":Z_Plus", pd->offset_RawPart.string_Max_ZPlus);

    if(!query.exec())
    {
        log->vailed(Q_FUNC_INFO);
        log->vailed(query.lastError().text());
        log->vailed(query.lastQuery());
        return false;
    }
    return true;
}

bool DataBase::save_FinishPart(ProjectData* pd)
{
    QSqlQuery query (main_DataBase);
    query.prepare("INSERT INTO FinishPart (Project_ID, X_Length, Y_Width, Z_Height) "
                  "VALUES (:Project_ID, :X_Length, :Y_Width, :Z_Height)");
    query.bindValue(":Project_ID", pd->id);
    query.bindValue(":X_Length", pd->finishPart.x_Length);
    query.bindValue(":Y_Width", pd->finishPart.y_Width);
    query.bindValue(":Z_Height", pd->finishPart.z_Height);

    if(!query.exec())
    {
        log->vailed(Q_FUNC_INFO);
        log->vailed(query.lastError().text());
        log->vailed(query.lastQuery());
        return false;
    }
    return true;
}

bool DataBase::save_ZeroPoint(ProjectData* pd)
{
    QSqlQuery query (main_DataBase);
    query.prepare("INSERT INTO ZeroPoint (Project_ID, X, Y, Z, G) "
                  "VALUES (:Project_ID, :X, :Y, :Z, :G)");
    query.bindValue(":Project_ID", pd->id);
    query.bindValue(":X", pd->zeroPoint.string_X);
    query.bindValue(":Y", pd->zeroPoint.string_Y);
    query.bindValue(":Z", pd->zeroPoint.string_Z);
    query.bindValue(":G", pd->zeroPoint.string_G);

    if(!query.exec())
    {
        log->vailed(Q_FUNC_INFO);
        log->vailed(query.lastError().text());
        log->vailed(query.lastQuery());
        return false;
    }
    return true;
}

bool DataBase::save_Programm(ProjectData* pd)
{
    QSqlQuery query (main_DataBase);

    foreach(Programm programm, pd->list_Programm)
    {
       query.prepare("INSERT INTO Programm_Project (Programm, Project_ID, Project, "
                     "Offset_X, Offset_Y, Offset_Z, TOFFL, NoXY) "
                     "VALUES (:Programm, :Project_ID, :Project, "
                     ":Offset_X, :Offset_Y, :Offset_Z, :TOFFL, :NoXY)");
        query.bindValue(":Programm", programm.ProgrammName);
        query.bindValue(":Project_ID", pd->id);
        query.bindValue(":Project", pd->name);
        query.bindValue(":Offset_X", int(programm.Offset_X));
        query.bindValue(":Offset_Y", int(programm.Offset_Y));
        query.bindValue(":Offset_Z", int(programm.Offset_Z));
        query.bindValue(":TOFFL", int(programm.TOFFL));
        query.bindValue(":NoXY", int(programm.NoXY));

        if(!query.exec())
        {
            log->vailed(Q_FUNC_INFO);
            log->vailed(query.lastError().text());
            log->vailed(query.lastQuery());
            return false;
        }

    }
    return true;
}

bool DataBase::save_Picture(ProjectData* pd)
{
    QSqlQuery query (main_DataBase);

    foreach(QPixmap pixmap, pd->listPictures)
    {
        QByteArray inByteArray;
        QBuffer buffer(&inByteArray);
        buffer.open(QIODevice::WriteOnly);
        pixmap.save(&buffer, "PNG");

        query.prepare( "INSERT INTO Pictures (Project_ID, data) VALUES (:Project_ID, :Data)" );
        query.bindValue(":Project_ID", pd->id);
        query.bindValue( ":Data", inByteArray );

        if(!query.exec())
        {
            log->vailed(Q_FUNC_INFO);
            log->vailed(query.lastError().text());
            log->vailed(query.lastQuery());
            return false;
        }
    }
    return true;
}

bool DataBase::save_NCTools(ProjectData* pd)
{
    //Erzeuge für jedes Werkzeug einen Eintrag in der Zuordnungstabelle
    // NCTool_Project
    foreach(Tool* tool, pd->toolList->get_List())
    {
        if(!create_NCToolProject(tool, pd))
        {
            log->vailed(Q_FUNC_INFO);
            log->vailed("Fehler bei Tool:" + tool->get_Number());
            return false;
        }
    }

    return true;
}

bool DataBase::create_NCToolProject(Tool* tool, ProjectData* pd)
{
    QString string_ToolID;
    QString string_NCToolsProjectID;
    QSqlQuery queryAdd (main_DataBase);
    QString string_ProjectFullName = pd->name + "_" +
                                     pd->state + "_" +
                                     pd->tension;

    // Trage das Tool in die Datenbank ein
    // Wenn das Fehlschlägt gib FALSE zurück
    string_ToolID = create_Tool(tool);
    if(string_ToolID.isEmpty())
        return false;

    // Hol dir die ID aus NCTools-Project
    // Wenn es eine ID gibt, brech mit TRUE ab
    // Ansonsten trage eine neue Verbindung zwischen Werkzeug und Projekt ein
    string_NCToolsProjectID = get_NCToolProjectID(string_ToolID, pd->id);

    if(string_NCToolsProjectID != "-1")
    {
        return true;
    }

    queryAdd.prepare("INSERT INTO NCTools_Project (nctool_id, T_Number, Project_ID, "
                     "Project, ToolLife, Parts) "
                     "VALUES (:nctool_id, "
                     ":T_Number, "
                     ":Project_ID, "
                     ":Project, "
                     ":ToolLife,"
                     ":Parts)");
    queryAdd.bindValue(":nctool_id", string_ToolID);
    queryAdd.bindValue(":T_Number", tool->get_Number());
    queryAdd.bindValue(":Project_ID", pd->id);
    queryAdd.bindValue(":Project", string_ProjectFullName);
    queryAdd.bindValue(":ToolLife", int(tool->get_ToolLife()));
    queryAdd.bindValue(":Parts", tool->get_Parts());

    if(!queryAdd.exec())
    {
        log->vailed(Q_FUNC_INFO);
        log->vailed(queryAdd.lastError().text());
        log->vailed(queryAdd.lastQuery());
        return false;
    }

    return true;
}

bool DataBase::create_TPAusrichten(Struct_Ausrichten ausrichten, QString string_ProjectID)
{
    QSqlQuery query (main_DataBase);

    query.prepare("INSERT INTO TP_Ausrichten (Project_ID, Project, Pos, Frame, Messrichtung, "
                  "Messachse, Positionierachse, L2, TSA, Anfahren) "
                  "VALUES (:Project_ID, "
                  ":Project, "
                  ":Pos, "
                  ":Frame, "
                  ":Messrichtung, "
                  ":Messachse, "
                  ":Positionierachse, "
                  ":L2, "
                  ":TSA, "
                  ":Anfahren)");
    query.bindValue(":Project_ID", string_ProjectID);
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
        log->vailed(Q_FUNC_INFO);
        log->vailed(query.lastError().text());
        log->vailed(query.lastQuery());
        return false;
    }

    return true;
}

bool DataBase::create_TPKante(Struct_Kante kante, QString string_ProjectID)
{
    QSqlQuery query (main_DataBase);

    query.prepare("INSERT INTO TP_Kante (Project_ID, Project, Pos, Frame, Messrichtung, "
                  "Messachse, Wert, DFA, TSA, Anfahren) "
                  "VALUES (:Project_ID, "
                  ":Project, "
                  ":Pos, "
                  ":Frame, "
                  ":Messrichtung, "
                  ":Messachse, "
                  ":Wert, "
                  ":DFA, "
                  ":TSA, "
                  ":Anfahren)");
    query.bindValue(":Project_ID", string_ProjectID);
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
        log->vailed(Q_FUNC_INFO);
        log->vailed(query.lastError().text());
        log->vailed(query.lastQuery());
        return false;
    }

    return true;
}

bool DataBase::create_TPEbenheit(Struct_Ebenheit ebenheit, QString string_ProjectID)
{
    int int_Jump1 = int(ebenheit.bool_Jump1);
    int int_Jump2 = int(ebenheit.bool_Jump2);
    int int_Jump3 = int(ebenheit.bool_Jump3);

    QSqlQuery query (main_DataBase);

    query.prepare("INSERT INTO TP_Ebenheit (Project_ID, Project, Pos, Frame, ZEbene, Vertrauensbereich, "
                  "Punkt1X, Punkt1Y, Punkt2X, Punkt2Y, Punkt3X, Punkt3Y, Punkt4X, Punkt4Y, "
                  "Jump1, Jump2, Jump3) "
                  "VALUES (:Project_ID, "
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
    query.bindValue(":Project_ID", string_ProjectID);
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
        log->vailed(Q_FUNC_INFO);
        log->vailed(query.lastError().text());
        log->vailed(query.lastQuery());
        return false;
    }

    return true;
}

bool DataBase::create_TPSteg(Struct_Steg steg, QString string_ProjectID)
{
    QSqlQuery query (main_DataBase);

    query.prepare("INSERT INTO TP_Steg (Project_ID, Project, Pos, Frame, Messachse, "
                  "W, DZ, DFA, TSA, Anfahren) "
                  "VALUES (:Project_ID, "
                  ":Project, "
                  ":Pos, "
                  ":Frame, "
                  ":Messachse, "
                  ":W, "
                  ":DZ, "
                  ":DFA, "
                  ":TSA, "
                  ":Anfahren)");
    query.bindValue(":Project_ID", string_ProjectID);
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
        log->vailed(Q_FUNC_INFO);
        log->vailed(query.lastError().text());
        log->vailed(query.lastQuery());
        return false;
    }

    return true;
}

bool DataBase::create_TPBohrung(Struct_Bohrung bohrung, QString string_ProjectID)
{
    QSqlQuery query (main_DataBase);

    query.prepare("INSERT INTO TP_Bohrung (Project_ID, Project, Pos, Frame, Durchmesser, "
                  "TSA, Anfahren) "
                  "VALUES (:Project_ID, "
                  ":Project, "
                  ":Pos, "
                  ":Frame, "
                  ":Durchmesser, "
                  ":TSA, "
                  ":Anfahren)");
    query.bindValue(":Project_ID", string_ProjectID);
    query.bindValue(":Project", " ");
    query.bindValue(":Pos", bohrung.string_Pos);
    query.bindValue(":Frame", bohrung.string_Frame);
    query.bindValue(":Durchmesser", bohrung.string_Durchmesser);
    query.bindValue(":TSA", bohrung.string_TSA);
    query.bindValue(":Anfahren", bohrung.string_Anfahren);

    if(!query.exec())
    {
        log->vailed(Q_FUNC_INFO);
        log->vailed(query.lastError().text());
        log->vailed(query.lastQuery());
        return false;
    }

    return true;
}

bool DataBase::create_TPNut(Struct_Nut nut, QString string_ProjectID)
{
    QSqlQuery query (main_DataBase);

    query.prepare("INSERT INTO TP_Nut (Project_ID, Project, Pos, Frame, Messachse, "
                  "W, DFA, TSA, Anfahren) "
                  "VALUES (:Project_ID, "
                  ":Project, "
                  ":Pos, "
                  ":Frame, "
                  ":Messachse, "
                  ":W, "
                  ":DFA, "
                  ":TSA, "
                  ":Anfahren)");
    query.bindValue(":Project_ID", string_ProjectID);
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
        log->vailed(Q_FUNC_INFO);
        log->vailed(query.lastError().text());
        log->vailed(query.lastQuery());
        return false;
    }

    return true;
}

QString DataBase::create_Tool(Tool* tool)
{
    QSqlQuery query (main_DataBase);
    QSqlQuery queryAdd (main_DataBase);
    QString string_ToolID;

    // Suche nach dem Tool in der Datenbank,
    // wenn das Tool schon in der Datenbank existiert,
    // wird die ID zurückgeben
    query.exec("SELECT id, T_Number FROM NCTool "
               "WHERE T_Number = '" +
               tool->get_Number()+ "';");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
    {
        log->vailed(Q_FUNC_INFO);
        log->vailed(" Tool: " + tool->get_Number());
    }
    while (query.next())
    {
        string_ToolID = query.value("id").toString();
    }

    // Wenn es das Tool in der Datenbank gibt wird
    // die ID zurückgeben
    if(!string_ToolID.isEmpty())
        return string_ToolID;


    // Ab hier gibt es das Tool noch nicht, es wird in die Datenbank
    // eingetragen.
    queryAdd.prepare("INSERT INTO NCTool (T_Number, Description, Gage_Length, Tool_Length, Tip_Length, "
                     "counter) "
                     "VALUES (:T_Number, "
                     ":Description, "
                     ":Gage_Length, "
                     ":Tool_Length, "
                     ":Tip_Length, "
                     ":counter)");
    queryAdd.bindValue(":T_Number", tool->get_Number());
    queryAdd.bindValue(":Description", tool->get_Description());
    queryAdd.bindValue(":Gage_Length", tool->get_GageLength());
    queryAdd.bindValue(":Tool_Length", tool->get_ToolLength());
    queryAdd.bindValue(":Tip_Length", tool->get_TipLength());
    queryAdd.bindValue(":counter", 0);

    if(!queryAdd.exec())
    {
        log->vailed(Q_FUNC_INFO);
        log->vailed(queryAdd.lastError().text());
        log->vailed(queryAdd.lastQuery());
        return string_ToolID;
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

QString DataBase::get_NCToolProjectID(QString string_NCToolID, QString string_ProjectID)
{
    QString string_NCToolProjectID = "-1";
    QSqlQuery query (main_DataBase);

    //Suche nach dem Project in der Datenbank,
    query.exec("SELECT id, nctool_id, Project_ID FROM NCTools_Project "
               "WHERE nctool_id = '" + string_NCToolID + "' "
               "AND Project_ID = '" + string_ProjectID + "';");

    //qDebug() << query.lastQuery();

    if(!query.exec())
    {
        log->vailed(Q_FUNC_INFO);
        log->vailed(query.lastError().text());
        log->vailed(query.lastQuery());
    }

    while (query.next())
    {
        string_NCToolProjectID = query.value("id").toString();
    }

    return string_NCToolProjectID;
}

void DataBase::get_Top100(ToolList* toolList)
{
    toolList->clear();
    Tool* tool;

    QSqlQuery query (main_DataBase);

    query.exec("select T_Number, counter, Description FROM NCTool "
               "ORDER BY counter desc, T_Number ASC LIMIT 100;");

    // Wenn ein Fehler auftritt wird er gelogt
    if(!query.lastError().text().isEmpty())
    {
        log->vailed(Q_FUNC_INFO);
        log->vailed(query.lastError().text());
        return;
    }

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

void DataBase::insert_FinishPart(ProjectData* projectData)
{
    //suche die Fertigeildaten und schreib sie ins Projekt
    QSqlQuery query (main_DataBase);
    FinishPart finishPart;
    query.exec("SELECT * FROM FinishPart "
               "WHERE Project_ID = '" + projectData->id + "';");

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
        projectData->finishPart = finishPart;
    }

    return;
}

void DataBase::insert_Picutres(ProjectData* projectData)
{
    // sucht die Bilder aus der Datenbank und schreibt sie in das Projekt
    QSqlQuery query (main_DataBase);
    QList<QPixmap> list;
    QPixmap outPixmap;
    QByteArray byteArray;

    query.exec("SELECT * FROM Pictures "
               "WHERE Project_ID = '" + projectData->id + "';");

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

    projectData->listPictures = list;
}

void DataBase::insert_RawPart(ProjectData* projectData)
{
    //suche die Rohteildaten und schreib sie ins Projekt
    QSqlQuery query (main_DataBase);
    RawPart rawPart;
    query.exec("SELECT * FROM RawPart "
               "WHERE Project_ID = '" + projectData->id + "';");

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
        projectData->rawPart = rawPart;
    }
    return;
}

void DataBase::insert_ZeroPoint(ProjectData* projectData)
{
    //suche den Nullpunkt und schreib sie ins Projekt
    QSqlQuery query (main_DataBase);
    ZeroPoint zeroPoint;

    query.exec("SELECT * FROM ZeroPoint "
               "WHERE Project_ID = '" + projectData->id + "';");

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
        projectData->zeroPoint = zeroPoint;
    }
    return;
}

void DataBase::insert_ToolList(ProjectData* projectData)
{
    //such nach den Werkzeugen und schreib sie ins Projekt
    QSqlQuery query (main_DataBase);
    Tool* tool;

    query.exec("SELECT NCTool.T_Number, NCTool.Gage_Length, "
               "NCTool.Tool_Length, NCTool.Tip_Length, "
               "NCTool.Counter, NCTool.Description, "
               "nctool_id, Project_ID "
               "FROM NCTools_Project "
               "INNER JOIN NCTool on NCTool.id = NCTools_Project.nctool_id "
               "WHERE Project_ID = " + projectData->id + " ;");

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

        projectData->toolList->insert_Tool(tool);
    }
    return;
}

void DataBase::insert_OffsetRawPart(ProjectData* projectData)
{
    //such nach den Rohteil Aufmasse und schreib sie ins Projekt
    QSqlQuery query (main_DataBase);
    Offset_RawPart offset_RawPart;

    query.exec("SELECT * FROM Offset_RawPart "
               "WHERE Project_ID = '" + projectData->id + "';");

    if(!query.lastError().text().isEmpty())
    {
        log->vailed(Q_FUNC_INFO);
        log->vailed(query.lastError().text());
        return;
    }

    while (query.next())
    {
        offset_RawPart.id = query.value("id").toString();
        offset_RawPart.string_Max_XPlus = query.value("X_Plus").toString();
        offset_RawPart.string_Max_XMinus = query.value("X_Minus").toString();
        offset_RawPart.string_Max_YPlus = query.value("Y_Plus").toString();
        offset_RawPart.string_Max_YMinus = query.value("Y_Minus").toString();
        offset_RawPart.string_Max_ZPlus = query.value("Z_Plus").toString();

        projectData->offset_RawPart = offset_RawPart;
    }

    return;
}

void DataBase::insert_Programm(ProjectData* projectData)
{
    QSqlQuery query (main_DataBase);

    query.exec("SELECT * from Programm_Project "
               "WHERE Project_ID = " + projectData->id + " "
               "ORDER BY Programm;");

    if(!query.lastError().text().isEmpty())
    {
        log->vailed(Q_FUNC_INFO);
        log->vailed(query.lastError().text());
        return;
    }

    while(query.next())
    {
        Programm programm;
        programm.id = query.value("id").toString();
        programm.ProgrammName = query.value("Programm").toString();
        programm.Project_ID = query.value("Project_ID").toString();
        programm.Offset_X = query.value("Offset_X").toBool();
        programm.Offset_Y = query.value("Offset_Y").toBool();
        programm.Offset_Z = query.value("Offset_Z").toBool();
        programm.TOFFL = query.value("TOFFL").toBool();
        programm.NoXY = query.value("NoXY").toBool();

        projectData->list_Programm.append(programm);
    }

    return;
}

void DataBase::insert_TouchProbe(ProjectData* projectData)
{
    QList<Item_TouchProbe> list;
    QString string_ProjectID = projectData->id;
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
               "WHERE Project_ID = '" + string_ProjectID + "';");

    if(!query.lastError().text().isEmpty())
    {
       log->vailed(query.lastError().text());
        return;
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
               "WHERE Project_ID = '" + string_ProjectID + "';");

    if(!query.lastError().text().isEmpty())
    {
        log->vailed(query.lastError().text());
        return;
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
               "WHERE Project_ID = '" + string_ProjectID + "';");

    if(!query.lastError().text().isEmpty())
    {
        log->vailed(query.lastError().text());
        return;
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
               "WHERE Project_ID = '" + string_ProjectID + "';");

    if(!query.lastError().text().isEmpty())
    {
        log->vailed(query.lastError().text());
        return;
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
               "WHERE Project_ID = '" + string_ProjectID + "';");

    if(!query.lastError().text().isEmpty())
    {
        log->vailed(query.lastError().text());
        return;
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
               "WHERE Project_ID = '" + string_ProjectID + "';");

    if(!query.lastError().text().isEmpty())
    {
        log->vailed(query.lastError().text());
        return ;
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

    projectData->list_TouchProbe = list;
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
    {
        log->vailed(query.lastError().text());
        return " ";
    }

    while (query.next())
    {
        string_ToolLength = query.value("tool_length").toString();
    }
    return string_ToolLength;
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
    {
        log->vailed(query.lastError().text());
        return " ";
    }

    while (query.next())
    {
        string_TipLength = query.value("dbl_param5").toString();
        bool_Hals        = query.value("bool_param2").toBool();
    }

    if(!bool_Hals)
        string_TipLength = " - ";

    return string_TipLength;
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
    {
        log->vailed(query.lastError().text());
        return " ";
    }

    while (query.next())
    {
        string_Description = query.value("nc_name").toString();
    }
    return string_Description;
}

bool DataBase::inc_ToolCounter(ToolList* toolList)
{
    QSqlQuery query (main_DataBase);
    int int_ToolCounter;

    foreach(Tool* tool, toolList->get_List())
    {
        int_ToolCounter = -1;

        // hol dir den Counter
        query.exec("SELECT Counter FROM NCTool WHERE T_Number = '" + tool->get_Number() + "';");
        if(!query.lastError().text().isEmpty())
        {
            log->vailed(query.lastError().text());
            return false;
        }

        while (query.next())
        {
            int_ToolCounter = query.value("Counter").toString().toInt();
        }

        // Wenn der Counter immer noch -1 ist brich ab
        if(int_ToolCounter == -1)
        {
            log->vailed(tool->get_Number() + " Counter = -1");
            return false;
        }

        // setzt den Counter um eins hoch
        int_ToolCounter++;

        // Update das Werkzeug
        query.exec("UPDATE NCTool SET Counter=" + QString("%1").arg(int_ToolCounter) +
                   " WHERE T_Number = '" + tool->get_Number() + "';");

        if(!query.lastError().text().isEmpty())
        {
            log->vailed(Q_FUNC_INFO);
            log->vailed(query.lastError().text());
            return false;
        }
    }
    return true;
}
