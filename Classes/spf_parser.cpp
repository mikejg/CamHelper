#include "spf_parser.h"

SPF_Parser::SPF_Parser(QObject *parent, QString string_PD, Logging* l, DataBase* db)
    : QObject{parent}
{
    string_ProgrammDir = string_PD;
    log = l;
    dataBase = db;
    mfile = new MFile(this,log);
    loadBruch();
}

void SPF_Parser::insert_Tool(QString str, ToolList* toolList)
{
    QString string_TNumber;
    QStringList stringList_Parts;

    Tool* tool = new Tool(this);

    //Alle Zeichen am Anfang Löschen bis die Zeile mit einem T anfängt
    while(!str.startsWith("T"))
    {
        str = str.right(str.length()-1);
    }

    //Das T löschen
    str = str.right(str.length()-1);

    //Leerzeichen am Anfang löschen
    while(str.startsWith(" "))
    {
        str = str.right(str.length()-1);
    }


    /* Splitte den QString str bei jedem '||' und
     * schreibe den Teilstring in die QStringList stringList_Part */
    stringList_Parts = str.split("||");

    if(stringList_Parts.size() >= 4)
    {
        tool->clear();
        string_TNumber = stringList_Parts.at(0);
        string_TNumber = string_TNumber.remove(" ");
        tool->set_Number(string_TNumber);
        tool->set_GageLength(stringList_Parts.at(2));
        tool->set_ToolLength(dataBase->get_ToolLength(string_TNumber));
        tool->set_TipLength(dataBase->get_TipLength(string_TNumber));
        tool->set_Description(dataBase->get_Description(string_TNumber));
        tool->set_Counter(dataBase->get_Counter(string_TNumber));
        toolList->insert_Tool(tool);
    }
}

bool SPF_Parser::scann_ForData()
{
    QDir        dir_ProgrammDir;
    QStringList filters;
    QStringList stringList_TMP;
    QStringList stringList_Projektnames;
    Programm programm;
    QStringList stringList_Programme;
    QString string_PostProcessor;

    bool bool_first = true;
    //Nimm nur SPF-Files
    filters << "*.spf";
    dir_ProgrammDir.setNameFilters(filters);

    /* Erstellt ein Verzeichnis in dem die CNC-Programme sind
     * lädt alle CNC-Prammnamen in die stringList_Programme */
    dir_ProgrammDir.setPath(string_ProgrammDir);
    stringList_Programme = dir_ProgrammDir.entryList(QDir::Files);

    /* Befülle QList<Programm> aus der ProgrammListe*/
    projectData->list_Programm.clear();                 //Lösche alle Proamme aus dem ProjectData;
    foreach(QString string, stringList_Programme)       //geh durch die Liste der Programme
    {
        programm.ProgrammName = string;                 //setze den ProgrammNamen in der Struktur programm
        projectData->list_Programm.append(programm);    //Füge die Struktur programm in die Liste ein
    }

    /* Lösche alle Einträge in der StringList Projektnames */
    stringList_Projektnames.clear();

    /* Geh durch alle gefunden SPF-Dateien und such nach einen Projektnamen
     * Wenn es die erste SPF-Datei ist schreibe den Projektnamen in die Liste
     * ansonsten sieh in der Liste nach ob es den aktuellen Prjektnamen schon gibt
     * Wenn nicht sende eine Fehlermeldung*/
    foreach (QString string_Prg, stringList_Programme)
    {
        projectData->name = parse_ProjectName(dir_ProgrammDir.path() + "/" + string_Prg);
        if(bool_first)
        {
            stringList_Projektnames.append(projectData->name);
            bool_first = false;
            continue;
        }

        string_PostProcessor = parse_PostProcessor(dir_ProgrammDir.path() + "/" + string_Prg);
        if(string_PostProcessor != "PP V2 ||")
        {
            log->vailed("Falser Postprocessor");
            return false;
        }

        if(!stringList_Projektnames.contains(projectData->name))
        {
            log->vailed("SPF-Dateien unterschiedlicher Projekte gefunden");
            return false;
        }
    }

    /* Wenn die stringList_Programme Einträge hat, also wenn CNC-Programme
     * vorhanden sind, lade mir aus dem ersten CNC-Programm den Projektnamen */
    if(!stringList_Programme.isEmpty())
    {
        /* Zieh den ProjektNamen und ProjektStand aus dem CNC-Programm */
        projectData->name = parse_ProjectName(dir_ProgrammDir.path() + "/" + stringList_Programme.first());

        /* Ersetze alle Leerzeichen durch einen Unterstrich */
        projectData->name = projectData->name.replace(" ", "_");

        /* Splitte den String nach "_"
         * Erster Teil ist der ProjektName
         * Zweiter Teil ist der ProjektStand */
        if(!projectData->name.isEmpty())
        {
            stringList_TMP = projectData->name.split("_");
            if(stringList_TMP.size()>0)
            {
                projectData->name = stringList_TMP.at(0);
            }
            if(stringList_TMP.size()>1)
            {
                projectData->state = stringList_TMP.at(1);
            }
            if(stringList_TMP.size()>2)
            {
                projectData->tension = stringList_TMP.at(2);
            }

            //string_ProjectFullName = string_ProjectName + "_" +
            //                         string_ProjectStatus + "_" +
            //                         string_ProjectClamping;
        }
    }

    if(!sort_Programms())
        return false;

    log->successful("ProjectName:     " + projectData->name);
    log->successful("ProjectStatus:   " + projectData->state);
    log->successful("ProjectClamping: " + projectData->tension);

    return true;
}

bool SPF_Parser::scann_ForTools()
{
    projectData->toolList->clear();
    foreach (Programm programm, projectData->list_Programm)
    {
        if(!parse_Tool(string_ProgrammDir + "/"+ programm.ProgrammName, projectData->toolList))
            return false;
    }
    projectData->toolList->sort_Number();

    /*
    stringList_Message.clear();
    stringList_Message.append(Q_FUNC_INFO);
    foreach(Tool* tool, toolList->get_List())
    {
        stringList_Message.append(tool->get_Number() + " " + tool->get_Description());
    }
    log->frame_Message(stringList_Message);
    */

    return true;
}

bool SPF_Parser::scann_ForNoXY()
{
    QString str;
    QString string_ToolID;
    QString string_GageLength;
    int int_GageLength;

    //foreach (Programm programm, projectData->list_Programm)
    for(auto& programm : projectData->list_Programm)
    {
        mfile->setFileName(string_ProgrammDir + "/" + programm.ProgrammName);

        if(!mfile->read_Content())
        {
            log->vailed(Q_FUNC_INFO);
            return false;
        }

        stringList_Content = mfile->get_Content();

        for(int i = 0; i < stringList_Content.size(); i++)
        {
            str = stringList_Content.at(i);
            if(str.contains("T=\""))
            {
                string_ToolID = str;
                while(!string_ToolID.startsWith("\"") && string_ToolID.length()>0)
                {
                    string_ToolID = string_ToolID.right(string_ToolID.length()-1);
                }

                while(!string_ToolID.endsWith("\"") && string_ToolID.length()>0)
                {
                    string_ToolID = string_ToolID.left(string_ToolID.length()-1);
                }

                string_ToolID = string_ToolID.remove("\"");
                string_GageLength = dataBase->get_GageLength(string_ToolID);


                if(!string_GageLength.isEmpty())
                {
                    int_GageLength = string_GageLength.toInt();
                }
                else
                {
                    int_GageLength = 9999;
                }

            }

            if(str.contains("Reset - Cycle800") && int_GageLength <= 160)
            {
                //Ich möchte 6 Zeilen vorlesen
                if(i+6 < stringList_Content.size())
                {
                    //Folgende Zeilen müssen so nach dem "Reset - Cycle800" kommen
                    //N89 CYCLE800()
                    //N90 D0
                    //N91 G0 G153 Z499.9
                    //N92 G0 G153 X325. Y640.
                    //N93 D1
                    //N94 CYCLE800 (0,"HERMLE",100000,57,0.,42.5,-30.265,-90.,0.,180.,0,0,0,-1,0,0)

                    if(stringList_Content.at(i+1).contains("CYCLE800()") &&
                        stringList_Content.at(i+2).contains("D0") &&
                        stringList_Content.at(i+3).contains("G0 G153 Z499.9") &&
                        stringList_Content.at(i+4).contains("G0 G153 X325. Y640.") &&
                        stringList_Content.at(i+5).contains("D1") &&
                        stringList_Content.at(i+6).contains("CYCLE800 (0,\"HERMLE\""))
                    {
                        log->successful(programm.ProgrammName);
                        programm.NoXY = true;
                        break;
                    }
                }
            }
        }
    }

    return true;
}

QString SPF_Parser::parse_ProjectName(QString stringFile)
{
    mfile->setFileName(stringFile);
    QString returnString;
    QString string_TMP;
    QStringList stringList_Split;

    // lies das File ein
    if(!mfile->read_Content())
    {
        return returnString;
    }

    // suche in dem File nach einer Zeile die ";Project:" enthält
    foreach(QString string_Line, mfile->get_Content())
    {
        if(string_Line.contains(";Projekt:"))
        {
            string_TMP = string_Line;
        }
    }

    // wenn was gefunden wurde, splitte den String nach " || " auf
    // und gib den zweiten Teil zurück
    if(!string_TMP.isEmpty())
    {
        stringList_Split = string_TMP.split(" || ");
        if (stringList_Split.size() >1)
        {
            returnString = stringList_Split.at(1);
        }
    }
    return returnString;
}

QString SPF_Parser::parse_PostProcessor(QString stringFile)
{
    mfile->setFileName(stringFile);
    QString returnString;
    QString string_TMP;
    QStringList stringList_Split;

    // lies das File ein
    if(!mfile->read_Content())
    {
        return returnString;
    }

    // suche in dem File nach einer Zeile die ";Project:" enthält
    foreach(QString string_Line, mfile->get_Content())
    {
        if(string_Line.contains(";Projekt:"))
        {
            string_TMP = string_Line;
        }
    }

    // wenn was gefunden wurde, splitte den String nach " || " auf
    // und gib den zweiten Teil zurück
    if(!string_TMP.isEmpty())
    {
        stringList_Split = string_TMP.split(" || ");
        if (stringList_Split.size() >2)
        {
            returnString = stringList_Split.at(2);
        }
    }

    return returnString;
}

bool SPF_Parser::parse_Tool(QString stringFile, ToolList* toolList)
{
    mfile->setFileName(stringFile);

    if(!mfile->read_Content())
    {
        return false;
    }

    marker = kein_Marker;

    /* geht durch die QStringList stringList_Lines (Programmzeilen siehe readFile)
     * Wenn in der Zeile 'Werkzeugliste Anfang' vorhanden ist wird der Marker auf
     * werkzeugliste_Anfang gesetzt
     * Wenn in der Zeile 'Werkzeugliste Ende' vorhanden ist wird der Marker auf
     * kein_Marker gesetzt und die Schleife beendet
     * Wenn der Marker gleich werkzeugliste_Anfag und
     * QString string_Line '||' enthält wird die Funktion insertTool aufgerufen */

    foreach(QString string_Line, mfile->get_Content())
    {
        if(string_Line.contains("Werkzeugliste Anfang"))
        {
            marker = werkzeugliste_Anfang;
            continue;
        }

        if(string_Line.contains("Werkzeugliste Ende"))
        {
            marker = kein_Marker;
            break;
        }

        if(marker == werkzeugliste_Anfang && string_Line.contains("||"))
        {
            insert_Tool(string_Line, toolList);
        }
    }
    return true;
}

bool SPF_Parser::sort_Programms()
{
    QDir        dir_ProgrammDir;
    QStringList filters;
    Programm    programm;
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
     * Überprüfe die länge des Progammnamens und
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

        if(str.length() > 28)
        {
            if(str.startsWith("0"))
            {
                str = str.right(str.length()-1);
                dir_ProgrammDir.rename("0"+ str, str);
            }
            log->vailed("Datei: " + str + " zu lang");
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
        /* trage str in d stringList_Programme ein */
        stringList_Programme.append(str);

    }

    /* Befülle QList<Item_Programm> aus der ProgrammListe*/
    projectData->list_Programm.clear();
    foreach(QString string, stringList_Programme)
    {
        programm.ProgrammName = string;
        projectData->list_Programm.append(programm);
    }
    return true;
}

void SPF_Parser::finish(QString stringFile, Programm programm)
{
    QString string_ToolID;
    QString str;
    QString string_Temp;
    QString string_GageLength;
    int int_GageLength;

    bool_ersterBruch = false;
    bool_Messerkopf = false;
    bool_EinlippenBohrer = false;
    marker = kein_Marker;

    mfile->setFileName(stringFile);
    if(!mfile->read_Content())
        return;

    /*Geh durch stringList_Lines.
     * Wenn ein String die Zeichenfolge T=" enthält, filter mir die Nummer raus
     * Beispiel: N34 T="90_063_00"
     * setze den marker auf neuesWerkzeug
     * Wenn zum ersten mal call auftaucht ändere es in ;call
     * Wenn marker gleich neuesWerkzeug und call auftaucht dann
     * geh durch map_Bruch und vergleiche string_ToolID mit dem Key
     * wenn da was passt ersetze call"BRUCH" mit dem Value */
    stringList_Content = mfile->get_Content();

    for(int i = 0; i < stringList_Content.size(); i++)
    {
        str = stringList_Content.at(i);
        //Wenn str die Zeichfolge T=" beinhaltet
        if(str.contains("T=\""))
        {
            //Kopiere str nach string_ToolID
            string_ToolID = str;

            //schneide solange das erste Zeichen von string_ToolID ab bis
            //string_ToolID mit " beginnt
            while(!string_ToolID.startsWith("\"") && string_ToolID.length()>0)
            {
                string_ToolID = string_ToolID.right(string_ToolID.length()-1);
            }
            //schneide solange das letzte Zeichen von string_ToolID ab bis
            //string_ToolID mit " endet
            while(!string_ToolID.endsWith("\"") && string_ToolID.length()>0)
            {
                string_ToolID = string_ToolID.left(string_ToolID.length()-1);
            }

            string_ToolID = string_ToolID.remove("\"");

            marker = neuesWerkzeug;
        }

        //Wenn es noch keine erstern Aufruf der Bruchkontrolle gab
        // ersteze die Zeilen
        // N20 call"BRUCH"
        // N21 IF R199==1 GOTOF UP_ENDE
        // in
        // N20 ;call"BRUCH"
        // N21 ;IF R199==1 GOTOF UP_ENDE
        if(!bool_ersterBruch && str.contains("call"))
        {
            if(!str.contains(";"))
            {
                str = str.replace("call", ";call");
                stringList_Content.removeAt(i);
                stringList_Content.insert(i,str);
            }

            //gehe in die nächste Zeile
            i++;
            str = stringList_Content.at(i);
            if(!str.contains(";"))
            {
                str = str.replace("IF", ";IF");
                stringList_Content.removeAt(i);
                stringList_Content.insert(i,str);
            }
            bool_ersterBruch = true;
        }


        if(marker == neuesWerkzeug && str.contains("call"))
        {
            QMapIterator<QString, QString> iterator(map_Bruch);
            while (iterator.hasNext())
            {
                iterator.next();
                if(string_ToolID.first(iterator.key().length()) == iterator.key())
                {
                    str = str.replace("call\"BRUCH\"", iterator.value());
                    stringList_Content.removeAt(i);
                    stringList_Content.insert(i,str);
                }
            }
            marker = kein_Marker;
        }
    }

    //Wenn für das Programm NoXY gesetzt ist
    if(programm.NoXY)
    {
        log->log(programm.ProgrammName + " NoXY " + " ☑");

        for(int i = 0; i < stringList_Content.size(); i++)
        {
            str = stringList_Content.at(i);
            if(str.contains("T=\""))
            {
                string_ToolID = str;
                while(!string_ToolID.startsWith("\"") && string_ToolID.length()>0)
                {
                    string_ToolID = string_ToolID.right(string_ToolID.length()-1);
                }

                while(!string_ToolID.endsWith("\"") && string_ToolID.length()>0)
                {
                    string_ToolID = string_ToolID.left(string_ToolID.length()-1);
                }

                string_ToolID = string_ToolID.remove("\"");
                string_GageLength = dataBase->get_GageLength(string_ToolID);


                if(!string_GageLength.isEmpty())
                {
                    int_GageLength = string_GageLength.toInt();
                }
                else
                {
                    int_GageLength = 9999;
                }

            }

            if(str.contains("Reset - Cycle800") && int_GageLength <= 160)
            {
                //Ich möchte 6 Zeilen vorlesen
                if(i+6 < stringList_Content.size())
                {
                    //Folgende Zeilen müssen so nach dem "Reset - Cycle800" kommen
                    //N89 CYCLE800()
                    //N90 D0
                    //N91 G0 G153 Z499.9
                    //N92 G0 G153 X325. Y640.
                    //N93 D1
                    //N94 CYCLE800 (0,"HERMLE",100000,57,0.,42.5,-30.265,-90.,0.,180.,0,0,0,-1,0,0)

                    if(stringList_Content.at(i+1).contains("CYCLE800()") &&
                        stringList_Content.at(i+2).contains("D0") &&
                        stringList_Content.at(i+3).contains("G0 G153 Z499.9") &&
                        stringList_Content.at(i+4).contains("G0 G153 X325. Y640.") &&
                        stringList_Content.at(i+5).contains("D1") &&
                        stringList_Content.at(i+6).contains("CYCLE800 (0,\"HERMLE\""))
                    {
                        log->log(string_ToolID + " : GageLength = " + QString("%1").arg(int_GageLength) +
                                     " : setze NoXY");
                        string_Temp = stringList_Content.at(i+4);
                        string_Temp = string_Temp.replace("G0", ";G0");
                        stringList_Content.removeAt(i+4);
                        stringList_Content.insert(i+4,string_Temp);
                    }
                }
            }
        }
    }


    checkOptimiertesTieflochbohren();
    compare(mfile->get_Content(), stringList_Content);
    mfile->save(stringList_Content);

    return;
}

void SPF_Parser::checkOptimiertesTieflochbohren()
{
    bool opt = false;
    bool first_F;
    QString str;
    QRegularExpression re(QStringLiteral("F\\d+"));
    //QRegularExpressionMatchIterator matchIterator;
    QRegularExpressionMatch match;
    for(int i = 0; i < stringList_Content.size(); i++)
    {
        str = stringList_Content.at(i);
        //N30 ;( T29_033_00  FID=22 Optimiertes Tieflochbohren  D03.3  OPERATION 102 )
        //Wenn so eine Zeile kommt sind wir im Optimierten Tieflochbohren
        //und setzen opt und first_F auf true
        if(str.contains("Optimiertes Tieflochbohren"))
        {
            opt = true;
            first_F = true;
        }

        //N58 ;( END  OPERATION 102 )
        //Wenn diese Zeile kommt ist das Optimierte Tieflochbohren beendet
        if(str.contains("END") && str.contains("OPERATION"))
        {
            opt = false;
        }

        match = re.match(str);
        if (match.hasMatch() && opt == true)
        {
            /* Wenn wir das erste mal auf einen Vorschub treffen soll kein STOPRE
             * eingefügt werden. */
            if(first_F == true)
            {
                first_F = false;
                continue;
            }

            /* STOPRE soll nur eingefügt werden wenn in der Programmzeile kein G4 und kein G04
             * vorkommt. Der Vorschub darf nicht grösser als 1000 sein */
            if(!str.contains("G04") && !str.contains("G4") && match.captured(0).length() < 5)
            {
                //qDebug() << Q_FUNC_INFO << match.captured(0);
                stringList_Content.insert(i, "STOPRE");
                i++;
            }
        }
    }
}

void SPF_Parser::compare(QStringList stringList_Orginal, QStringList stringList_Copy)
{
    QString string_Orginal;
    QString string_Copy;
    bool firstLog = false;
    int count_Copy = 0;

    stringList_Log.clear();
    for(int i = 0; i< stringList_Orginal.size(); i++)
    {
        string_Orginal = stringList_Orginal.at(i);
        string_Copy = stringList_Copy.at(count_Copy);

        if(string_Orginal != string_Copy)
        {
            if(!firstLog)
            {
                stringList_Log.append(mfile->fileName());
                firstLog = true;
            }

            if(string_Orginal == stringList_Copy.at(count_Copy+1))
            {
                stringList_Log.append("-- " + string_Orginal);
                stringList_Log.append("++ " + string_Copy);
                stringList_Log.append("++ " + stringList_Copy.at(count_Copy+1));
                //stringList_Log.append(" ");
                count_Copy++;
            }
            else
            {
                stringList_Log.append("-- " + string_Orginal);
                stringList_Log.append("++ " + string_Copy);
                //stringList_Log.append(" ");
            }
        }
        count_Copy++;
    }

    foreach (QString string_Log, stringList_Log)
    {
        log->log(string_Log);
    }

    //if(!stringList_Log.isEmpty())
    //    log->frame_Warning(stringList_Log);
    //qDebug() << Q_FUNC_INFO;
}

void SPF_Parser::loadBruch()
{
    /*Öffne das File "/CamHelper/config/Bruch.txt" und lies es
     * in die stringList_Lines ein.
     * Geh durch stringList_Lines und splitte jede Zeile.
     * Füge die ersten zwei Strings in QMap map_Bruch */
    qDebug() << Q_FUNC_INFO;
    map_Bruch.clear();
    QStringList stringList_Bruch;
    mfile->setFileName(QDir::homePath() + "/CamHelper/config/Bruch.txt");
    if(!mfile->read_Content())
        return;

    foreach(string_Line, mfile->get_Content())
    {
        if(string_Line.contains(" || "))
        {
            stringList_Bruch = string_Line.split(" || ");
            if(stringList_Bruch.size()>1)
            {
                map_Bruch.insert(stringList_Bruch.at(0), stringList_Bruch.at(1));
            }
        }
    }
    return;
}

QStringList SPF_Parser::replace_Wildcard(QStringList stringList)
{
    QStringList stringList_ReturnList;

    foreach(QString string_Line, stringList)
    {
        if(string_Line.startsWith("#"))
            continue;

        //Rohteil
        string_Line = string_Line.replace("$RX$", projectData->rawPart.x_Length);
        string_Line = string_Line.replace("$RY$", projectData->rawPart.y_Width);
        string_Line = string_Line.replace("$RZ$", projectData->rawPart.z_Height);
        string_Line = string_Line.replace("$ZRT$", projectData->rawPart.z_RawPart);

        //Fertigteil
        string_Line = string_Line.replace("$BX$", projectData->finishPart.x_Length);
        string_Line = string_Line.replace("$BY$", projectData->finishPart.y_Width);
        string_Line = string_Line.replace("$BZ$", projectData->finishPart.z_Height);

        //Aufmasse Max
        string_Line = string_Line.replace("$Aufmass_Xplus_Max$", projectData->offset_RawPart.string_Max_XPlus_RawpartInspection);
        string_Line = string_Line.replace("$Aufmass_Xminus_Max$", projectData->offset_RawPart.string_Max_XMinus_RawpartInspection);
        string_Line = string_Line.replace("$Aufmass_Yplus_Max$", projectData->offset_RawPart.string_Max_YPlus_RawpartInspection);
        string_Line = string_Line.replace("$Aufmass_Yminus_Max$", projectData->offset_RawPart.string_Max_YMinus_RawpartInspection);
        string_Line = string_Line.replace("$Aufmass_Zplus_Max$", projectData->offset_RawPart.string_Max_ZPlus_RawpartInspection);

        //Aufmasse Min
        string_Line = string_Line.replace("$Aufmass_Xplus_Min$", projectData->offset_RawPart.string_Min_XPlus);
        string_Line = string_Line.replace("$Aufmass_Xminus_Min$", projectData->offset_RawPart.string_Min_XMinus);
        string_Line = string_Line.replace("$Aufmass_Yplus_Min$", projectData->offset_RawPart.string_Min_YPlus);
        string_Line = string_Line.replace("$Aufmass_Yminus_Min$", projectData->offset_RawPart.string_Min_YMinus);
        string_Line = string_Line.replace("$Aufmass_Zplus_Min$", projectData->offset_RawPart.string_Min_ZPlus);
        stringList_ReturnList.append(string_Line);
    }

    return stringList_ReturnList;
}
