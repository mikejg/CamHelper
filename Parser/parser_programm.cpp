#include "parser_programm.h"

Parser_Programm::Parser_Programm(QObject *parent,
                                 Logging* l,
                                 DataBase* db)
    : QObject{parent}
{
    log = l;
    database = db;

    mfile = new MFile(this, log);
}

void Parser_Programm::compare(QStringList stringList_Orginal, QStringList stringList_Copy)
{
    QString string_Source;
    QString string_Target;
    bool firstLog = false;

    stringList_Log.clear();
    for(int i = 0; i< stringList_Orginal.size(); i++)
    {
        string_Source = stringList_Orginal.at(i);
        string_Target = stringList_Copy.at(i);

        if(string_Target != string_Source)
        {
            if(!firstLog)
            {
                stringList_Log.append(mfile->fileName());
                firstLog = true;
            }
            stringList_Log.append(string_Source);
            stringList_Log.append(string_Target);
        }
    }
    if(!stringList_Log.isEmpty())
        log->frame_Warning(stringList_Log);
    //qDebug() << Q_FUNC_INFO;
}

void Parser_Programm::finish(QString stringFile, Item_Programm item)
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

            marker = neuesWerkzeug;
        }

        if(!bool_ersterBruch && str.contains("call"))
        {
            if(!str.contains(";"))
            {
                str = str.replace("call", ";call");
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

    if(item.NoXY)
    {
        log->message(item.Programm + " NoXY " + " ☑");
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
            string_GageLength = database->get_GageLength(string_ToolID);


            if(!string_GageLength.isEmpty())
            {
                int_GageLength = string_GageLength.toInt();
            }
            else
            {
                int_GageLength = 9999;
            }

        }

        if(str.contains("Reset - Cycle800") && int_GageLength <= 150)
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
                    log->message(string_ToolID + " : GageLength = " + QString("%1").arg(int_GageLength) +
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
    compare(mfile->get_Content(), stringList_Content);
    mfile->save(stringList_Content);

    return;
}

void Parser_Programm::insert_Tool(QString str, ToolList* toolList)
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
        tool->set_ToolLength(database->get_ToolLength(string_TNumber));
        tool->set_TipLength(database->get_TipLength(string_TNumber));
        //tool->set_HolderName(database->get_HolderName(string_TNumber));
        tool->set_Description(database->get_Description(string_TNumber));
        tool->set_Counter(database->get_Counter(string_TNumber));
        toolList->insert_Tool(tool);
    }
}

bool Parser_Programm::loadBruch()
{
    /*Öffne das File "/CamHelper/config/Bruch.txt" und lies es
     * in die stringList_Lines ein.
     * Geh durch stringList_Lines und splitte jede Zeile.
     * Füge die ersten zwei Strings in QMap map_Bruch */

    map_Bruch.clear();
    QStringList stringList_Bruch;
    mfile->setFileName(QDir::homePath() + "/CamHelper/config/Bruch.txt");
    if(!mfile->read_Content())
        return false;

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

    return true;
}

QString Parser_Programm::parse_ProjectName(QString stringFile)
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

bool Parser_Programm::parse_Tool(QString stringFile, ToolList* toolList)
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
