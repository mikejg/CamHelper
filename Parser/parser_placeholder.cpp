#include "parser_placeholder.h"

Parser_PlaceHolder::Parser_PlaceHolder(QObject *parent,
                                       Logging* l,
                                       Project* p)
    : QObject{parent}
{
    log = l;
    project = p;

    mfile = new MFile(this, log);
}

QStringList Parser_PlaceHolder::number_Programm(QStringList stringList)
{
    QStringList stringList_Return;
    int counter = 1;
    foreach(QString string, stringList)
    {
        if(string.contains("$Kopf")) continue;

        if(string.startsWith(";"))
        {
            stringList_Return.append(string);
            continue;
        }
        if(string.isEmpty())
        {
            stringList_Return.append(string);
            continue;
        }
        if(string == " ")
        {
            stringList_Return.append(string);
            continue;
        }
        if(string.startsWith("\n"))
        {
            stringList_Return.append(string);
            continue;
        }

        string = QString("N%1 ").arg(counter) + string;
        stringList_Return.append(string);
        counter++;
    }
    return stringList_Return;
}

QStringList Parser_PlaceHolder::set_PlaceHolder_Antasten(QStringList stringList_Content)
{
    QStringList stringList_ReturnList;

    foreach(QString string_Line, stringList_Content)
    {
        if(string_Line.startsWith("#"))
            continue;

        string_Line = string_Line.replace("$RX$", project->get_RawPartX());
        string_Line = string_Line.replace("$RY$", project->get_RawPartY());
        string_Line = string_Line.replace("$ZRT$", project->get_ZRawPart());
        stringList_ReturnList.append(string_Line);
    }

    return stringList_ReturnList;
}

QStringList Parser_PlaceHolder::set_PlaceHolder_Cleaning(QStringList stringList_Content)
{
    QStringList stringList_ReturnList;

    foreach(QString string_Line, stringList_Content)
    {
        if(string_Line.startsWith("#"))
            continue;

        string_Line = string_Line.replace("$RZ$", project->get_RawPartZ());
        stringList_ReturnList.append(string_Line);
    }

    return stringList_ReturnList;
}

QStringList Parser_PlaceHolder::set_PlaceHolder_MainProgramm(QStringList stringList_Content)
{
    //such in den Programmen nach TOFFL = true
    bool bool_TOFFL = false;
    foreach(Item_Programm item, project->get_ListProgramm())
    {
        if(item.TOFFL)
            bool_TOFFL = true;
    }

    // stringList_Content in stringList_tmp kopieren
    QStringList stringList_tmp = stringList_Content;

    // Inhalt von stringList_Content löschen
    stringList_Content.clear();

    foreach(QString string_Line, stringList_tmp)
    {
        //Wenn die Zeile eine # enthält wird die Zeile ignoriert
        if(string_Line.startsWith("#"))
            continue;

        /* Ersetze die Platzhalter */
        string_Line = string_Line.replace("$ZNr$",  project->get_ProjectName());
        string_Line = string_Line.replace("$ZStd$", project->get_ProjectStatus());
        string_Line = string_Line.replace("$RX$",   project->get_RawPartX());
        string_Line = string_Line.replace("$RY$",   project->get_RawPartY());
        string_Line = string_Line.replace("$RZ$",   project->get_RawPartZ());
        string_Line = string_Line.replace("$G5x$",  project->get_ProjectZeroPoint());
        string_Line = string_Line.replace("$ZRT$",  project->get_ZRawPart());
        string_Line = string_Line.replace("$Ma$",   project->get_Material());
        string_Line = string_Line.replace("$RTK$",  project->get_RawPartInspection());
        string_Line = string_Line.replace("$Comment$", project->get_Comment());

        /* Wenn die Zeile $G55$ enthält wird der Inhalt der Datei
         * "config/G55.txt" ausgegeben.
         * Falls das fehlschlägt wird die eine leere StringList
         * zurückgegeben und eine Fehlermeldung angezeigt */
        if(string_Line.contains("$G55$"))
        {
            if(writeG55(&stringList_Content))
                continue;
            else
            {
                stringList_Content.clear();
                return stringList_Content;
            }
        }

        if(string_Line.contains("$G54$"))
        {
            if(writeG54(&stringList_Content))
                continue;
            else
            {
                stringList_Content.clear();
                return stringList_Content;
            }
        }

        if(string_Line.contains("$TOFFL$"))
        {
            //Wenn in den Programmen TOFFL gesetzt ist schreibe
            //TOFFL = 0 in die stringList_Content
            if(bool_TOFFL)
            {
                //stringList_Content.append(";----------------------+");
                stringList_Content.append("TOFFL = 0; Reset TOFFL ");
                //stringList_Content.append(";----------------------+");
            }
            continue;
        }

        if(string_Line.contains("$ToolLife$"))
        {
            write_ToolLife(&stringList_Content);
            continue;
        }

        if(string_Line.contains("$Parts$"))
        {
            write_Parts(&stringList_Content);
            continue;
        }
        /* füge string_Line in stringList_Content ein */
        stringList_Content.append(string_Line);

        /* Wenn die Zeile ';Programme' enthält wird eine Liste der
         * Unterprogramme ausgegeben */
        if(string_Line.contains(";Programme"))
        {
            foreach(Item_Programm item, project->get_ListProgramm())
            {
                if(item.TOFFL)
                {
                    //Füge TOFFL = 0 ein
                    stringList_Content.append("TOFFL = 0");
                }
                if(item.NoXY)
                {
                    stringList_Content.append("M00 ;NoXY aktiv");
                }
                //Füge Programmaufruf ein
                string_Line = "call \"" +
                              item.Programm.left(item.Programm.length()-4) +
                              "\"";
                stringList_Content.append(string_Line);
                if(item.TOFFL)
                {
                    //Füge TOFFL = 0 ein
                    stringList_Content.append("TOFFL = 0");
                }
                stringList_Content.append(" ");
            }
        }
    }
    //number_Programm(&stringList_Content);
    return number_Programm(stringList_Content);
}

QStringList Parser_PlaceHolder::set_PlaceHolder_RawPartInspection(QStringList stringList_Content)
{
    //project->log_ProjectData();

    QStringList stringList_ReturnList;

    foreach(QString string_Line, stringList_Content)
    {
        if(string_Line.startsWith("#"))
            continue;

        string_Line = string_Line.replace("$ZRT$", project->get_ZRawPart());

        //Rohteil
        string_Line = string_Line.replace("$RX$", project->get_RawPartX());
        string_Line = string_Line.replace("$RY$", project->get_RawPartY());
        string_Line = string_Line.replace("$RZ$", project->get_RawPartZ());

        //Fertigteil
        string_Line = string_Line.replace("$BX$", project->get_ComponentPartX());
        string_Line = string_Line.replace("$BY$", project->get_ComponentPartY());
        string_Line = string_Line.replace("$BZ$", project->get_ComponentPartZ());

        string_Line = string_Line.replace("$Aufmass_Xplus_Max$",  project->get_XPlus_Max());
        string_Line = string_Line.replace("$Aufmass_Xminus_Max$", project->get_XMinus_Max());
        string_Line = string_Line.replace("$Aufmass_Yplus_Max$",  project->get_YPlus_Max());
        string_Line = string_Line.replace("$Aufmass_Yminus_Max$", project->get_YMinus_Max());
        string_Line = string_Line.replace("$Aufmass_Zplus_Max$",  project->get_ZPlus_Max());

        string_Line= string_Line.replace("$Aufmass_Xplus_Min$" , project->get_XPlus_Min());
        string_Line= string_Line.replace("$Aufmass_Xminus_Min$", project->get_XMinus_Min());
        string_Line= string_Line.replace("$Aufmass_Yplus_Min$" , project->get_YPlus_Min());
        string_Line= string_Line.replace("$Aufmass_Yminus_Min$", project->get_YMinus_Min());
        string_Line= string_Line.replace("$Aufmass_Zplus_Min$",  project->get_ZPlus_Min());
        stringList_ReturnList.append(string_Line);
    }

    return stringList_ReturnList;
}

bool Parser_PlaceHolder::writeG54(QStringList* stringList_Content)
{
    QStringList stringList_ContentG55;

    /* Versuche das File "config/G54.txt" zu öffnen
     * und den Inhalt einzulesen.
     * Wenn das fehl schlägt gib false zurück
     * Übergib den Inhalt der Datei an stringList_ContentG55 */
    mfile->setFileName(QDir::homePath() + "/CamHelper/config/G54.txt");
    if(!mfile->read_Content())
        return false;
    stringList_ContentG55 = mfile->get_Content();


    foreach(QString string_Line, stringList_ContentG55)
    {
        //Wenn die Zeile eine # enthält wird die Zeile ignoriert
        if(string_Line.startsWith("#"))
            continue;

        /* Ersetze den Platzhalter '$Z$' mit der Rohteil Höhe */
        if(string_Line.contains("$Z$"))
        {
            string_Line.replace("$Z$", project->get_RawPartZ());
        }

        /* füge string_Line in stringList_Content ein */
        stringList_Content->append(string_Line);
    }
    return true;
}

bool Parser_PlaceHolder::writeG55(QStringList* stringList_Content)
{
    QStringList stringList_ContentG55;

    /* Versuche das File "config/G55.txt" zu öffnen
     * und den Inhalt einzulesen.
     * Wenn das fehl schlägt gib false zurück
     * Übergib den Inhalt der Datei an stringList_ContentG55 */
    mfile->setFileName(QDir::homePath() + "/CamHelper/config/G55.txt");
    if(!mfile->read_Content())
        return false;
    stringList_ContentG55 = mfile->get_Content();


    foreach(QString string_Line, stringList_ContentG55)
    {
        //Wenn die Zeile eine # enthält wird die Zeile ignoriert
        if(string_Line.startsWith("#"))
            continue;

        /* Ersetze den Platzhalter '$Z$' mit der Rohteil Höhe */
        if(string_Line.contains("$NPz$"))
        {
            string_Line.replace("$NPz$", project->get_NPz());
        }

        /* füge string_Line in stringList_Content ein */
        stringList_Content->append(string_Line);
    }
    return true;
}

void Parser_PlaceHolder::write_Parts(QStringList* stringList_Content)
{
    QString string;
    foreach(Tool* tool, project->get_ToolList()->get_List())
    {
        if(!tool->get_ToolLife())
            continue;

        string = "; T" + tool->get_Number() + " ";
        if(tool->get_Parts() < 10)
            string = string + " ";
        string = string + QString("%1").arg(tool->get_Parts()) + " Teile";

        stringList_Content->append(string);
    }
}

void Parser_PlaceHolder::write_ToolLife(QStringList* stringList_Content)
{
    bool bool_CheckToolLife = false;
    //Überprüfe ob bei einem Tool die Standzeit aktiv ist
    foreach(Tool* tool, project->get_ToolList()->get_List())
    {
        if(tool->get_ToolLife())
            bool_CheckToolLife = true;
    }

    // Wenn bei keinem Tool die Standzeit aktiv ist brech hier ab
    if(!bool_CheckToolLife)
        return;

    // erstelle die Einträge für die Standzeit
    stringList_Content->append(";+------------------------------+");
    stringList_Content->append(";|  Standzeit herunter zaehlen  |");
    stringList_Content->append(";+------------------------------+");


    // Geh durch alle Tools und überprüfe ob die Standzeit aktiv ist
    // wenn ja, dann erstell den Eintrag für das Herunterzählen der
    // Standzeit
    foreach(Tool* tool, project->get_ToolList()->get_List())
    {
        if(!tool->get_ToolLife())
            continue;

        //stringList_Content->append("\n");
        stringList_Content->append("setpiece (0)");
        stringList_Content->append("T=\"" + tool->get_Number() + "\"");
        stringList_Content->append("M06");
        stringList_Content->append("setpiece (1)");
        stringList_Content->append("");
    }
    stringList_Content->append("setpiece (0)");
}

