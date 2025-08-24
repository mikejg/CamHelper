#include "mainprogramm.h"
#include <QDir>

MainProgramm::MainProgramm(QWidget *parent) : QTextEdit(parent)
{
    highLighter = new Highlighter840(document());
}

MainProgramm::~MainProgramm()
{

}

void MainProgramm::set_Logging(Logging* l)
{
    log = l;
    mfile = new MFile(this, log);
}

QStringList MainProgramm::number_Programm(QStringList stringList)
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
void MainProgramm::set_ProjectData(ProjectData pd)
{
    projectData = pd;
    QString string_MainProgramm;
    this->clear();

    if(pd.tension == "Sp1")
        string_MainProgramm = QDir::homePath()+"/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP1.MPF";
    if(pd.tension == "Sp2")
        string_MainProgramm = QDir::homePath()+"/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP2.MPF";
    if(pd.tension == "Sp3")
        string_MainProgramm = QDir::homePath()+"/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP3.MPF";
    if(pd.tension == "Sp4")
        string_MainProgramm = QDir::homePath()+"/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP4.MPF";

    mfile->setFileName(string_MainProgramm);
    if(!mfile->read_Content())
        return;

    foreach(QString str, set_PlaceHolder(mfile->get_Content()))
    {
        append(str);
    }

    this->moveCursor(QTextCursor::Start);
}

QStringList MainProgramm::set_PlaceHolder(QStringList stringList_Content)
{
    //such in den Programmen nach TOFFL = true
    bool bool_TOFFL = false;
    foreach(Programm programm, projectData.list_Programm)
    {
        if(programm.TOFFL)
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
        string_Line = string_Line.replace("$ZNr$",  projectData.name);
        string_Line = string_Line.replace("$ZStd$", projectData.state);
        string_Line = string_Line.replace("$RX$",   projectData.rawPart.x_Length);
        string_Line = string_Line.replace("$RY$",   projectData.rawPart.y_Width);
        string_Line = string_Line.replace("$RZ$",   projectData.rawPart.z_Height);
        string_Line = string_Line.replace("$G5x$",  projectData.zeroPoint.string_G);
        string_Line = string_Line.replace("$ZRT$",  projectData.rawPart.z_RawPart);
        string_Line = string_Line.replace("$Ma$",   projectData.material);
        string_Line = string_Line.replace("$RTK$",  projectData.rawPart_Inspection);
        string_Line = string_Line.replace("$Comment$", projectData.header);

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
            foreach(Programm programm, projectData.list_Programm)
            {
                if(programm.TOFFL)
                {
                    //Füge TOFFL = 0 ein
                    stringList_Content.append("TOFFL = 0");
                }
                if(programm.NoXY)
                {
                    stringList_Content.append("M00 ;NoXY aktiv");
                }
                //Füge Programmaufruf ein
                string_Line = "call \"" +
                              programm.ProgrammName.left(programm.ProgrammName.length()-4) +
                              "\"";
                stringList_Content.append(string_Line);
                stringList_Content.append("IF R199==1 GOTOF WKZ_Bruch");
                stringList_Content.append("IF WKZ_VERFUGBAR==FALSE GOTOF WKZ_NichtVerfugbar");

                if(programm.TOFFL)
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

bool MainProgramm::writeG54(QStringList* stringList_Content)
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
        if(string_Line.contains("$NPz$"))
        {
            string_Line.replace("$NPz$", projectData.zeroPoint.string_Z);
        }

        /* füge string_Line in stringList_Content ein */
        stringList_Content->append(string_Line);
    }
    return true;
}

bool MainProgramm::writeG55(QStringList* stringList_Content)
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
            string_Line.replace("$NPz$", projectData.zeroPoint.string_Z);
        }

        /* füge string_Line in stringList_Content ein */
        stringList_Content->append(string_Line);
    }
    return true;
}


void MainProgramm::write_ToolLife(QStringList* stringList_Content)
{
    bool bool_CheckToolLife = false;
    //Überprüfe ob bei einem Tool die Standzeit aktiv ist
    foreach(Tool* tool, projectData.toolList->get_List())
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
    foreach(Tool* tool, projectData.toolList->get_List())
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


void MainProgramm::write_Parts(QStringList* stringList_Content)
{
    QString string;
    foreach(Tool* tool, projectData.toolList->get_List())
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
