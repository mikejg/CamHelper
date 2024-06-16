#include "project.h"

Project::Project(QObject*  parent,
                 Logging*  l,
                 Settings* s,
                 DataBase* db,
                 ToolList* tl)
    : QObject{parent}
{
    log         = l;
    settings    = s;
    database    = db;
    toolList_In = tl;

    parser_Programm = new Parser_Programm(this,
                                          log,
                                          database);
    toolList = new ToolList(this);

    string_ProjectZeroPoint = "G___";
    string_RawPartInspection = "Rohteilkontrolle00";

    string_ProgrammDir = settings->get_ProgrammDir();
    bool_MaxOverSize   = settings->get_MaxOverSize();
    bool_Numbering     = settings->get_Numbering();
}

void Project::add_Tag(QString string_Tag)
{
    stringList_Tags.append(string_Tag);
}

QMap<QString, QString> Project::get_Data()
{
    //schreibe alle Parameter in eine Map und gib sie zurück
    QMap<QString, QString> map_Data;

    map_Data.insert("Name", string_ProjectName);
    map_Data.insert("Status", string_ProjectStatus);
    map_Data.insert("Clamping", string_ProjectClamping);
    map_Data.insert("CamFile", string_CamFile);
    map_Data.insert("Comment", string_Comment);

    map_Data.insert("RawPart_X", string_RawPartX);
    map_Data.insert("RawPart_Y", string_RawPartY);
    map_Data.insert("RawPart_Z", string_RawPartZ);

    map_Data.insert("Component_X", string_ComponentPartX);
    map_Data.insert("Component_Y", string_ComponentPartY);
    map_Data.insert("Component_Z", string_ComponentPartZ);

    map_Data.insert("ZRawPart", string_ZRawPart);
    map_Data.insert("ZeroPoint", string_ProjectZeroPoint);
    map_Data.insert("Material", string_Material);
    map_Data.insert("RawPartInspection", string_RawPartInspection);

    map_Data.insert("Last_Production", string_LastProduction);
    map_Data.insert("XPlus_Max", string_XPlus_Max_DB);
    map_Data.insert("XMinus_Max", string_XMinus_Max_DB);
    map_Data.insert("YPlus_Max", string_YPlus_Max_DB);
    map_Data.insert("YMinus_Max", string_YMinus_Max_DB);
    map_Data.insert("ZPlus_Max", string_ZPlus_Max_DB);

    //qDebug() << map_Data;
    return map_Data;
}

QStringList Project::get_ProgrammList()
{
    QStringList list;
    foreach(Item_Programm item, list_Programm)
    {
        list.append(item.Programm);
    }
    return list;
}

void Project::log_ProjectData()
{
    stringList_Message.clear();
    stringList_Message.append(Q_FUNC_INFO);
    stringList_Message.append("ProjectName:      " + string_ProjectName);
    stringList_Message.append("ProjectStatus:    " + string_ProjectStatus);
    stringList_Message.append("ProjectClamping:  " + string_ProjectClamping);
    stringList_Message.append("Cam File:         " + string_CamFile);
    stringList_Message.append("Hauptprogramm :   " + string_MainProgramm);
    stringList_Message.append("Material          " + string_Material);
    stringList_Message.append("Nullpunkt:        " + string_ProjectZeroPoint);
    stringList_Message.append("Rohteil:          " + string_RawPartX + " x "
                                                   + string_RawPartY + " x "
                                                   + string_RawPartZ);
    stringList_Message.append("Bauteil:          " + string_ComponentPartX + " x "
                                                   + string_ComponentPartY + " x "
                                                   + string_ComponentPartZ);
    stringList_Message.append("AntastPunkt Z:    " + string_ZRawPart);
    stringList_Message.append("RohteilKontrolle: " + string_RawPartInspection);

    log->frame_Message(stringList_Message);
}

void Project::save()
{
    QString string_ProjectID;

    // Speicher das Project in die Datenbank
    // Wenn das Project schon in der Datenbank ist,
    // wird das Project mit den neuen Daten überschrieben
    if(!database->save_Project(get_Data()))
        return;

    // hol die ProjectID aus der Datenbank
    // Wenn das Fehlschlägt gib eine Fehlermeldung aus
    // und brich die Funktion ab
    string_ProjectID = database->get_ProjectID(string_ProjectName, string_ProjectClamping);

    if(string_ProjectID.isEmpty())
    {
        stringList_Errors.clear();
        stringList_Errors.append(Q_FUNC_INFO);
        stringList_Errors.append("Es wurde keine ProjectID gefunden");
        stringList_Errors.append("Project Name:     " + string_ProjectName);
        stringList_Errors.append("Project Clamping: " + string_ProjectClamping);
        log->frame_Error(stringList_Errors);
        return;
    }

    save_NCTools(string_ProjectID);
    save_Programm(string_ProjectID);
    save_TPItems(string_ProjectID);
    save_Pictures(string_ProjectID);
    save_Tags(string_ProjectID);

    // Wenn wir hier angekommens sind sollte alles nach Plan gelaufen sein
    log->successful("Project: " + string_ProjectFullName + " erfolgreich gespeichert");
}

bool Project::scann_ForData()
{
    QDir        dir_ProgrammDir;
    QStringList filters;
    QStringList stringList_TMP;
    QStringList stringList_Projektnames;
    Item_Programm item_Programm;
    QStringList stringList_Programme;
    bool bool_first = true;
    //Nimm nur SPF-Files
    filters << "*.spf";
    dir_ProgrammDir.setNameFilters(filters);

    /* Erstellt ein Verzeichnis in dem die CNC-Programme sind
     * lädt alle CNC-Prammnamen in die stringList_Programme */
    dir_ProgrammDir.setPath(string_ProgrammDir);
    //stringList_Programme.clear();
    stringList_Programme = dir_ProgrammDir.entryList(QDir::Files);

    /* Befülle QList<Item_Programm> aus der ProgrammListe*/
    list_Programm.clear();
    foreach(QString string, stringList_Programme)
    {
        item_Programm.Programm = string;
        list_Programm.append(item_Programm);
    }

    /* Lösche alle Einträge in der StringList Projektnames */
    stringList_Projektnames.clear();

    /* Geh durch alle gefunden SPF-Dateien und such nach einen Projektnamen
     * Wenn es die erste SPF-Datei ist schreibe den Projektnamen in die Liste
     * ansonsten sieh in der Liste nach ob es den aktuellen Prjektnamen schon gibt
     * Wenn nicht sende eine Fehlermeldung*/
    foreach (QString string_Prg, stringList_Programme)
    {
        string_ProjectName = parser_Programm->parse_ProjectName(dir_ProgrammDir.path() + "/" + string_Prg);
        if(bool_first)
        {
            stringList_Projektnames.append(string_ProjectName);
            bool_first = false;
            continue;
        }

        if(!stringList_Projektnames.contains(string_ProjectName))
        {
            stringList_Errors.clear();

            stringList_Errors.append("SPF-Dateien unterschiedlicher Projekte gefunden");
            stringList_Errors.append("Lösche SPF-Dateien aus dem Programm Ordner");
            stringList_Errors.append("Führen Sie erneut den Postprozessor aus");
            stringList_Errors.append("Starten Sie diese Applikation neu");
            log->frame_Error(stringList_Errors);
            return false;
        }
    }

    /* Wenn die stringList_Programme Einträge hat, also wenn CNC-Programme
     * vorhanden sind, lade mir aus dem ersten CNC-Programm den Projektnamen */
    if(!stringList_Programme.isEmpty())
    {

        //string_Projektname = "nichts";
        /* Zieh den ProjektNamen und ProjektStand aus dem CNC-Programm */
        string_ProjectName = parser_Programm->parse_ProjectName(dir_ProgrammDir.path() + "/" + stringList_Programme.first());

        /* Ersetze alle Leerzeichen durch einen Unterstrich */
        string_ProjectName = string_ProjectName.replace(" ", "_");

        /* Splitte den String nach "_"
         * Erster Teil ist der ProjektName
         * Zweiter Teil ist der ProjektStand */
        if(!string_ProjectName.isEmpty())
        {
            stringList_TMP = string_ProjectName.split("_");
            if(stringList_TMP.size()>0)
            {
                string_ProjectName = stringList_TMP.at(0);
                //emit sig_Log("ProjectName:     " + string_ProjectName);
            }
            if(stringList_TMP.size()>1)
            {
                string_ProjectStatus = stringList_TMP.at(1);
                //emit sig_Log("ProjectStatus:   " + string_ProjectStatus);
            }
            if(stringList_TMP.size()>2)
            {
                string_ProjectClamping = stringList_TMP.at(2);
                //emit sig_Log("ProjectClamping: " + string_ProjectClamping);
            }

            string_ProjectFullName = string_ProjectName + "_" +
                                     string_ProjectStatus + "_" +
                                     string_ProjectClamping;
        }
    }

    if(!sort_Programms())
        return false;

    stringList_Message.clear();
    stringList_Message.append("Project::scann_PrgrammFiles()");
    stringList_Message.append("ProjectName:     " + string_ProjectName);
    stringList_Message.append("ProjectStatus:   " + string_ProjectStatus);
    stringList_Message.append("ProjectClamping: " + string_ProjectClamping);
    log->frame_Message(stringList_Message);

    stringList_Message.clear();
    stringList_Message.append("Project::scann_PrgrammFiles()");
    foreach(QString str, stringList_Programme)
        stringList_Message.append(str);
    log->frame_Message(stringList_Message);

    return true;
}

bool Project::scann_ForTools()
{
    toolList->clear();
    foreach (Item_Programm item, list_Programm)
    {
        if(!parser_Programm->parse_Tool(string_ProgrammDir + "/"+ item.Programm, toolList))
            return false;
    }
    toolList->sort_ID();

    stringList_Message.clear();
    stringList_Message.append(Q_FUNC_INFO);
    foreach(Tool* tool, toolList->get_List())
    {
        stringList_Message.append(tool->get_Number() + " " + tool->get_Description());
    }
    log->frame_Message(stringList_Message);
    return true;
}

void Project::set_ContentMainProgramm(QTextEdit* textEdit)
{
    stringList_ContentMainProgramm = textEdit->toPlainText().split("\n");
}

void Project::set_NCTools()
{
    database->fill_ToolList(string_ProjectName, string_ProjectClamping, toolList);
}

void Project::set_ProjectFullName()
{
    string_ProjectFullName = string_ProjectName + "_" +
                             string_ProjectStatus + "_" +
                             string_ProjectClamping;
}

bool Project::sort_Programms()
{
    QDir        dir_ProgrammDir;
    QStringList filters;
    QString     string_shortName;
    int         int_I;  Q_UNUSED(int_I);
    bool        bool_OK;
    Item_Programm item_Programm;
    QStringList stringList_Programme;

    dir_ProgrammDir.setPath(string_ProgrammDir);
    filters << "*.spf";
    dir_ProgrammDir.setNameFilters(filters);

    /* Lösche alle einträge in stringList_Programme
     * lade alle ProgrammNamen in stringList_Programme*/
    stringList_Programme = dir_ProgrammDir.entryList(QDir::Files);

    /* Erzeuge eine temporäre StringList tmp
     * geh durch stringList_Programme
     * wenn der Eintrag mit 1_ - 9_ stratet setze eine 0 davor
     * Überprüfe die länge des Progammnamens abhängig ob
     * eine Nummerierung vorgesehen ist oder nicht
     * schreibe den Eintrag in tmp*/
    QStringList tmp;
    foreach(QString str, stringList_Programme)
    {
        if (str.startsWith("1_") || str.startsWith("2_") || str.startsWith("3_") ||
            str.startsWith("4_") || str.startsWith("5_") || str.startsWith("6_") ||
            str.startsWith("7_") || str.startsWith("8_") || str.startsWith("9_") )
        {
            dir_ProgrammDir.rename(str, "0"+str);
            str = "0" + str;
        }

        if(!bool_Numbering && str.length() > 31)
        {
            if(str.startsWith("0"))
            {
                str = str.right(str.length()-1);
                dir_ProgrammDir.rename("0"+ str, str);
            }
            stringList_Errors.clear();
            stringList_Errors.append("Datei: " + str + " zu lang");
            stringList_Errors.append(" - Loeschen Sie die Datei");
            stringList_Errors.append(" - Kürzen Sie den Komponentenjob");
            stringList_Errors.append(" - Spielen sie die Datei neu aus");
            stringList_Errors.append(" - Starten Sie die Applikation neu");
            log->frame_Error(stringList_Errors);
            return false;
        }

        if(bool_Numbering && str.length() > 28)
        {
            qDebug() << str << ": " << str.length();
            if(str.startsWith("0"))
            {
                str = str.right(str.length()-1);
                dir_ProgrammDir.rename("0"+ str, str);
            }
            stringList_Errors.clear();
            stringList_Errors.append("Datei: " + str + " zu lang");
            stringList_Errors.append(" - Loeschen Sie die Datei");
            stringList_Errors.append(" - Kürzen Sie den Komponentenjob");
            stringList_Errors.append(" - Spielen sie die Datei neu aus");
            stringList_Errors.append(" - Starten Sie die Applikation neu");
            log->frame_Error(stringList_Errors);
            return false;
        }

        tmp.append(str);
    }

    /* Sortiere tmp
     * Lösche alle Einträge in stringList_Programme
     * geht durch tmp
     * Schreibe alle Einträge von tmp in stringList_Programme*/
    tmp.sort();
    stringList_Programme.clear();

    foreach(QString str, tmp)
    {
        /* Wenn keine Nummerierung der Programme vorgesehen ist
         * lösche die Nummerierung vor dem ProgrammNamen */
        if(!bool_Numbering)
        {
            /* Kopiere str nach string_shortName */
            string_shortName = str;

            /* Überprüfe ob das erste Zeichen von string_shortName eine
            * Zahl ist. Das Ergebniss wird in bool_OK gespeichert */
            int_I = string_shortName.left(1).toInt(&bool_OK, 10);

            while(bool_OK)
            {
                /* Lösche das erste Zeichen von string_shortName */
                string_shortName = string_shortName.right(string_shortName.length()-1);

                /* Überprüfe ob das erste Zeichen von string_shortName eine Zahl ist */
                int_I = string_shortName.left(1).toInt(&bool_OK, 10);

                /* Wenn das erste Zeichen ein '_' ist wird bool_OK auf true gesetzt */
                if(string_shortName.startsWith("_"))
                    bool_OK = true;
            }

            /* Benenne das SPF-File um */
            dir_ProgrammDir.rename(str, string_shortName);

            /* trage string_shortName in stringList_Progamme ein */
            stringList_Programme.append(string_shortName);
        }
        else
        {
            /* trage str in d stringList_Programme ein */
            stringList_Programme.append(str);
        }
    }

    /* Befülle QList<Item_Programm> aus der ProgrammListe*/
    list_Programm.clear();
    foreach(QString string, stringList_Programme)
    {
        item_Programm.Programm = string;
        list_Programm.append(item_Programm);
    }
    return true;
}

void Project::save_NCTools(QString string_ProjectID)
{
    bool bool_InsertTool;
    database->deleteFrom_NCToolsProject(string_ProjectID);

    // Speicher die Werkzeuge in die Datenbank
    // erstell einen Eintrag in der Zuordnungstabelle
    // NCTools_Project
    foreach(Tool* tool, toolList->get_List())
    {
        bool_InsertTool = database->insert_Tool(tool, string_ProjectID, string_ProjectName + "_"
                                                                            + string_ProjectClamping);
        if(!bool_InsertTool)
        {
            log->error("Fehler beim Speichern der Werkzeuge");
            break;
        }
    }

    /*
    bool bool_InsertTool;
    QList<Item_NCToolProject> list;
    Item_NCToolProject item_NCToolProject;

    // Hole mir alle Werkzeug-Verbindungen zu diesem Project
    //list = database->get_ConnectionNCToolsProject(string_ProjectID);

    // Lösche aus der Liste alle Verbindungen deren Werkzeug in der Werkzeugliste vorhanden
    // sind. Es bleiben die verwaisten Verbindung in der Liste
    foreach(Tool* tool, toolList->get_List())
    {
        item_NCToolProject = Item_NCToolProject(tool->get_Number(), string_ProjectID);
        if(list.contains(item_NCToolProject))
        {
            list.removeOne(item_NCToolProject);
        }
    }

    // Lösche alle verwaisten Verbindungen aus der Datenbank
    stringList_Message.clear();
    foreach(Item_NCToolProject item, list)
    {
        if(database->deleteFrom_NCToolsProject(item))
        {
            // Wenn in der stringList_Message noch keinen Eintrag hat
            // erstelle eine Kopfzeile und füge eine Meldung ein
            if(stringList_Message.isEmpty())
            {
                stringList_Message.append("gelöschte Verbindungen");
                stringList_Message.append(item.T_Number + " gelöscht");
            }
            else
                stringList_Message.append(item.T_Number + " gelöscht");
        }
    }

    // gib die Meldung nur aus wenn die stringList_Message Einträge hat
    if(!stringList_Message.isEmpty())
        log->frame_Message(stringList_Message);

   */
}

void Project::save_Programm(QString string_ProjectID)
{
    bool bool_InsertProgramm;

    database->deleteFrom_ProgrammProject(string_ProjectID);

    // Speicher die Programme in die Datenbank
    foreach(Item_Programm item, list_Programm)
    {
        bool_InsertProgramm = database->insert_Programm(item, string_ProjectID, string_ProjectName + "_"
                                                                                + string_ProjectClamping);
        if(!bool_InsertProgramm)
            break;
    }
}

void Project::save_TPItems(QString string_ProjectID)
{
    //loesche alle Items aus der Datenbank
    database->delete_TP_Items(string_ProjectID);

    Struct_Ausrichten struct_Ausrichten;
    Struct_Kante      struct_Kante;
    Struct_Ebenheit   struct_Ebenheit;
    Struct_Steg       struct_Steg;
    Struct_Bohrung    struct_Bohrung;
    Struct_Nut        struct_Nut;

    int pos = 0;
    foreach(TP_Item* tp_Item, tp_ItemList)
    {
        if(tp_Item->get_State() == TP_Item::Ausrichten)
        {
            struct_Ausrichten = tp_Item->get_Ausrichten();
            struct_Ausrichten.string_Pos = QString("%1").arg(pos);
            database->insert_TPAusrichten(struct_Ausrichten, string_ProjectID);
            pos++;
            continue;
        }

        if(tp_Item->get_State() == TP_Item::Kante)
        {
            struct_Kante = tp_Item->get_Kante();
            struct_Kante.string_Pos = QString("%1").arg(pos);
            database->insert_TPKante(struct_Kante, string_ProjectID);
            pos++;
            continue;
        }

        if(tp_Item->get_State() == TP_Item::Ebenheit)
        {
            struct_Ebenheit = tp_Item->get_Ebenheit();
            struct_Ebenheit.string_Pos = QString("%1").arg(pos);
            database->insert_TPEbenheit(struct_Ebenheit, string_ProjectID);
            pos++;
            continue;
        }

        if(tp_Item->get_State() == TP_Item::Steg)
        {
            struct_Steg = tp_Item->get_Steg();
            struct_Steg.string_Pos = QString("%1").arg(pos);
            database->insert_TPSteg(struct_Steg, string_ProjectID);
            pos++;
            continue;
        }

        if(tp_Item->get_State() == TP_Item::Bohrung)
        {
            struct_Bohrung = tp_Item->get_Bohrung();
            struct_Bohrung.string_Pos = QString("%1").arg(pos);
            database->insert_TPBohrung(struct_Bohrung, string_ProjectID);
            pos++;
            continue;
        }

        if(tp_Item->get_State() == TP_Item::Nut)
        {
            struct_Nut = tp_Item->get_Nut();
            struct_Nut.string_Pos = QString("%1").arg(pos);
            database->insert_TPNut(struct_Nut, string_ProjectID);
            pos++;
            continue;
        }

    }
}

void Project::save_Pictures(QString string_ProjectID)
{
    //loesche alle Bilder aus der Datenbank
    database->delete_Pictures(string_ProjectID);
    foreach(MLabel* label, pictureList)
    {
        database->insert_Picture(label, string_ProjectID);
    }
}

void Project::save_Tags(QString string_ProjectID)
{
    //loesche alle Tags aus der Datenbank
    qDebug() << Q_FUNC_INFO << stringList_Tags;
    database->delete_Tags(string_ProjectID);
    foreach(QString string_Tag, stringList_Tags)
    {
        database->insert_Tags(string_Tag, string_ProjectID);
    }
}

void Project::slot_NewProgrammList(QList<Item_Programm> list)
{
    qDebug() << Q_FUNC_INFO;

    list_Programm = list;
    QString string;
    stringList_Message.clear();
    stringList_Message.append("NoXY");
    foreach(Item_Programm item, list_Programm)
    {
        //qDebug() << item.Programm << item.TOFFL << item.NoXY;

        if(item.NoXY)
            string = "☑ ";
        else
            string = "☐ ";
        string = string + item.Programm;
        stringList_Message.append(string);
    }

    log->frame_Message(stringList_Message);

}
