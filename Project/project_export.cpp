#include "project_export.h"

Project_Export::Project_Export(QObject *parent,
                               Logging* l,
                               Project* p,
                               Dialog_Progress* dp,
                               DataBase* db)
    : QObject{parent}
{
    log = l;
    project = p;
    dialog_Progress = dp;
    database = db;

    parser_PlaceHolder = new Parser_PlaceHolder(this, log, project);
    parser_Programm = new Parser_Programm(this, log, db);
    mfile = new MFile(this,log);
    timer = new QTimer(this);
}

bool Project_Export::finish_Cleaning()
{
    QStringList stringList_Content;
    mfile->setFileName(string_Destination + "/_Sp1_Reinigen.SPF");
    if(!mfile->read_Content())
        return false;
    stringList_Content = mfile->get_Content();
    stringList_Content = parser_PlaceHolder->set_PlaceHolder_Cleaning(stringList_Content);
    mfile->save(stringList_Content);
    return true;
}

bool Project_Export::finish_Load()
{
    loadBruch();
    QString string_Loading_Source;
    QString string_Loading_Destination;
    QString string_ToolID;
    QString string_Bruch;

    QStringList stringList_Head;
    QStringList stringList_Body;
    QStringList stringList_End;
    QStringList stringList_File;

    string_Destination = string_ProgrammDir + "/" +
                         string_ProjectName + ".WPD/" +
                         string_ProjectFullName + ".WPD";

    /*Kopiert den Ordner Vorlagen.WPD/WKZ_beladen.WPD nach
     * Programme/E123456789.WPD/E123456789_E0_Sp1.WPD/E123456789_E0_Sp1_In.WPD*/

    string_Loading_Destination = string_Destination + "/Rusten_" + string_ProjectFullName + ".WPD";
    string_Loading_Source      = QDir::homePath() + "/CamHelper/Vorlagen/Verzeichnisse/WKZ_beladen.WPD";

    QDir dir_Vorlagen(string_Loading_Source);
    if(!dir_Vorlagen.exists())
    {
        stringList.clear();
        stringList.append("Konnte Verzeichnis");
        stringList.append(string_Loading_Source);
        stringList.append("Nicht finden");
        log->frame_Error(stringList);
        return false;
    }
    dir_Vorlagen.mkpath(string_Loading_Destination);

    /*foreach (QString f, dir_Vorlagen.entryList(QDir::Files))
    {
        QFile::copy(string_Loading_Source + QDir::separator() + f,
                    string_Destination + "/Rusten_" + string_ProjectFullName + ".WPD" + QDir::separator() + f);
    }*/

    // Lese den Inhalt der Datei WKZ_beladen_Kopf.spf in stringList_Head ein
    // Das gleiche gilt für stringList_Body und stringList_End
    mfile->setFileName(QDir::homePath() + "/CamHelper/config/ToolIn/Header.spf");
    if(!mfile->read_Content())
        return false;
    stringList_Head = mfile->get_Content();

    mfile->setFileName(QDir::homePath() + "/CamHelper/config/ToolIn/Body.spf");
    if(!mfile->read_Content())
        return false;
    stringList_Body = mfile->get_Content();

    mfile->setFileName(QDir::homePath() + "/CamHelper/config/ToolIn/Footer.spf");
    if(!mfile->read_Content())
        return false;
    stringList_End = mfile->get_Content();

    mfile->setFileName(string_Destination + "/Rusten_" + string_ProjectFullName + ".WPD" + QDir::separator() + "_WKZ_Kontrolle.spf");

    /*Gehe durch die stringList_Kopf
     * Schreibe string_Line in das File
     * Wenn du zum Marker 'Werkzeugliste Anfang' kommst gehe durch die Liste
     * der einzulagernden Werkzeuge. */
    int count = 1;
    //qDebug() << Q_FUNC_INFO;
    foreach(QString string_Line, stringList_Head)
    {
        stringList_File.append(QString("N%1 ").arg(count) + string_Line); // + "\n" );
        count++;
        if(string_Line.contains("Werkzeugliste Anfang"))
        {
            foreach(Tool* tool, project->get_ToolListIN()->get_List())
            {
                stringList_File.append(QString("N%1 ").arg(count) +
                                       "; T " + tool->get_Number() +
                                           "  " + tool->get_Description()); //+
                                       //"\n");
                count++;
            }
        }
    }

    /*Geh durch die Liste der einzulagernden Werkzeuge
     * Geh durch stringList_Rumpf
     * Ersetze '$TNumber$ durch die ToolID und ToolBeschreibung
     * Wenn die ToolID mit 29 beginnt (Einlippenbohrer) dann
     * ersetze 'BRUCH' mit 'BRUCH2' */
    foreach (Tool* tool, project->get_ToolListIN()->get_List())
    {
        foreach (QString string_Body, stringList_Body)
        {
            if(string_Body.contains("$TNumber$"))
            {
                string_Body.replace("$TNumber$", tool->get_Number());
                string_Body = string_Body + " ; " + tool->get_Description();
            }

            if(string_Body.contains("BRUCH"))
            {
                string_ToolID = tool->get_Number();
                QMapIterator<QString, QString> iterator(map_Bruch);
                while (iterator.hasNext())
                {
                    iterator.next();
                    if(string_ToolID.first(iterator.key().length()) == iterator.key())
                    {
                        string_Bruch = iterator.value();
                        string_Bruch = string_Bruch.remove("\"");
                        string_Bruch = string_Bruch.remove("call");
                        string_Body.replace("BRUCH", string_Bruch);
                        break;
                    }
                }
            }
            stringList_File.append(QString("N%1 ").arg(count) + string_Body); // + "\n");
            count++;
        }
    }

    /*Geh durch stringList_End und schreib jede Zeile in das File*/
    foreach(QString string_Line, stringList_End)
    {
        stringList_File.append(QString("N%1 ").arg(count) + string_Line); // + "\n" );
        count++;
    }

    mfile->save(stringList_File);

    mfile->setFileName(QDir::homePath() + "/CamHelper/config/Nullpunkt.spf");
    if(!mfile->read_Content())
        return false;
    stringList_Body = mfile->get_Content();
    stringList_File.clear();

    foreach(QString string, stringList_Body)
    {
        if(string.contains("$G$"))
            string = string.replace("$G$", "\"" + project->get_ProjectZeroPoint() + "\"");
        if(string.contains("$NPx$"))
            string = string.replace("$NPx$", project->get_NPx());
        if(string.contains("$NPy$"))
            string = string.replace("$NPy$", project->get_NPy());
        if(string.contains("$NPz$"))
            string = string.replace("$NPz$", project->get_NPz());

        stringList_File.append(string);
    }

    mfile->setFileName(string_Destination + "/Rusten_" + string_ProjectFullName + ".WPD" + QDir::separator() + "_NP_Setzen.spf");
    mfile->save(stringList_File);

    int i = 1;
    foreach(MLabel* label, project->get_PictureList())
    {
        QFile file(string_Destination + "/Rusten_" + string_ProjectFullName + ".WPD" + QDir::separator() + QString("Bild_%1.png").arg(i));
        label->get_Pixmap().save(&file, "PNG");
        i++;
    }

    return true;
}

bool Project_Export::finish_RawPartInspection()
{
    QStringList stringList_Content;
    mfile->setFileName(string_Destination + "/_Sp1_" + project->get_RawPartInspection() + ".SPF");
    if(!mfile->read_Content())
        return false;
    stringList_Content = mfile->get_Content();
    stringList_Content = parser_PlaceHolder->set_PlaceHolder_RawPartInspection(stringList_Content);
    mfile->save(stringList_Content);
    return true;
}

bool Project_Export::finish_TouchSp1()
{
    QStringList stringList_Content;
    mfile->setFileName(string_Destination + "/_Sp1_Rohteil_antasten.SPF");
    if(!mfile->read_Content())
        return false;
    stringList_Content = mfile->get_Content();
    stringList_Content = parser_PlaceHolder->set_PlaceHolder_Antasten(stringList_Content);
    mfile->save(stringList_Content);
    return true;
}

bool Project_Export::finish_TouchSp0()
{
    QStringList stringList_Content;
    mfile->setFileName(string_Destination + "/_Sp0_Rohteil_antasten.SPF");
    if(!mfile->read_Content())
        return false;
    stringList_Content = mfile->get_Content();
    stringList_Content = parser_PlaceHolder->set_PlaceHolder_Antasten(stringList_Content);
    mfile->save(stringList_Content);
    return true;
}

QString Project_Export::formatString(QString str)
{
    int len = str.length();
    if(len < 75)
    {
        while(len < 75)
        {
            str = str.append(" ");
            len++;
        }
    }

    len = str.length();
    while(len > 75 && str.right(1) == " ")
    {
        str = str.left(len - 1);
        len = str.length();
    }
    return str;
}

void Project_Export::init_ExportFiles()
{
    /*Zähler wird auf Null gesetzt
     * Die Länge des Fortschritsbalken ist die anzahl der Programme
     * Zeige den Dialog an
     * starte slot_nextProgramm*/
    counter = 0;
    dialog_Progress->init_Dialog(list_ItemProgramm);
    dialog_Progress->show();
    timer->singleShot(0, this, SLOT(slot_NextProgramm()));
}

bool Project_Export::loadBruch()
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

    foreach(QString string_Line, mfile->get_Content())
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

void Project_Export::slot_ExportProject(bool b)
{
    bool_IncToolCounter = b;
    stringList_ContentMainProgramm = project->get_ContentMainProgramm();

    string_ProgrammDir     = project->get_ProgrammDir();
    string_ProjectName     = project->get_ProjectName();
    string_ProjectFullName = project->get_ProjectFullName();
    string_ProjectClamping = project->get_ProjectClamping();

    list_ItemProgramm = project->get_ListProgramm();

    /*Erzeugt im Ordern Programme den Ordner ProjektName.WPD/SpannungX.WPD
     * Programme/E123456789.WPD/Spannung1.WPD
     * Erstellt QDir dir_Vorlagen mit dem Pfad, in dem die Vorlagen für die Spannung sind
     * Erstellt QDir dir_Programme mit dem Pfad 'Programme/E123456789.WPD/Spannung1.WPD'
    */

    /*Bereite den Parser_Programm für die Bruchkontrolle vor*/
    if(!parser_Programm->loadBruch())
        return;

    string_Destination = string_ProgrammDir + "/" +
                         string_ProjectName + ".WPD/" +
                         string_ProjectFullName + ".WPD";

    string_Source = QDir::homePath() + "/CamHelper/Vorlagen/Verzeichnisse/" + string_ProjectClamping + ".WPD";

    QDir dir_Vorlagen(string_Source);
    if(!dir_Vorlagen.exists())
    {
        stringList.clear();
        stringList.append("Konnte Verzeichnis");
        stringList.append(string_Source);
        stringList.append("Nicht finden");
        log->frame_Error(stringList);
        return;
    }

    dir_Vorlagen.mkpath(string_Destination);

    /*Öffnet das File Programme/00_E123456789.MPF"
    * Schreibt alles aus dem Reiter Hauptprgramm in das File*/
    QString str = string_ProgrammDir + "/" + string_ProjectFullName +".MPF";

    QFile file(str);
    if(file.open(QFile::WriteOnly))
    {
        marker = keinMarker;
        QTextStream stream(&file);
        foreach(QString string_Line, stringList_ContentMainProgramm)
        {
            if(string_Line.contains("$KopfStart$"))
            {
                marker = KopfStart;
                continue;
            }

            if(string_Line.contains("$KopfEnd$"))
            {
                marker = KopfEnd;
                continue;
            }

            if(marker == KopfStart)
            {
                string_Line = formatString(string_Line);
            }

            stream << string_Line << "\n";
        }
        file.close();
    }

    /* Kopiert den Ordner Vorlagen/Verzeichnisse/Sp1.WPD nach
    * Programme/E123456789.WPD/E123456789_E1_Sp1.WPD*/
    QStringList stringList_Files = dir_Vorlagen.entryList(QDir::Files);
    QStringList stringList_Temp;

    // Durchsuche stringList_Files nach Einträgen die mit Rohteilkontrolle beginnen
    // und speicher sie in stringList_Temp
    foreach (QString str, stringList_Files)
    {
        if(str.contains("Rohteilkontrolle"))
            stringList_Temp.append(str);
    }

    // geh stringList_Temp durch und lösche jeden Eintrag von stringList_Temp in
    // stringList_Files
    foreach (QString str, stringList_Temp)
    {
        stringList_Files.removeAll(str);
    }

    // Füge Rohteilkontrolle aus dem Project in stringList_Files
    stringList_Files.append("_Sp1_" + project->get_RawPartInspection() + ".SPF");

    // Kopiere alle Files aus stringList_Files ins ProjectVerzeichnis
    foreach (QString f, stringList_Files)
    {
        QFile::copy(string_Source + QDir::separator() + f, string_Destination + QDir::separator() + f);
    }

    // Wenn der Werkzeugzähler um eins erhöht werden soll und es nicht klappt
    // brech die Funktion ab
    if(bool_IncToolCounter && !database->inc_ToolCounter(project->get_ToolList()))
    {
        return;
    }


    init_ExportFiles();

    return;
}

void Project_Export::slot_NextProgramm()
{
    item_Programm = list_ItemProgramm.at(counter);
    string_Programm = item_Programm.Programm;
    dialog_Progress->set_Value(string_Programm, counter);

    // Setze den ProgrammPfad in MFile und überprüfe ob das Programm existiert
    // wenn ja, dann verschiebe das Programm
    mfile->setFileName(string_ProgrammDir + "/" + string_Programm);
    if(mfile->exists())
    {
        parser_Programm->finish(string_ProgrammDir+ "/" + string_Programm, item_Programm);

        QFile::copy(string_ProgrammDir + QDir::separator() + string_Programm,
                    string_Destination + QDir::separator() + string_Programm);

        QFile::remove(string_ProgrammDir + QDir::separator() + string_Programm);
    }
    else
    {
        stringList_Log.clear();
        stringList_Log.append(string_Programm);
        stringList_Log.append("Konnte Datei nicht finden");
        stringList_Log.append("Datei wurde uebersprungen");
        log->frame_Warning(stringList_Log);
    }

    // Counter um eins hochzaehlen und Fortschrittbalken aktualisieren
    counter++;
    dialog_Progress->update();

    // Wenn Counter kleiner als list_ItemProgramme.size eine halbe Sekunde warten,
    // damit der Fortschrittbalken neu angezeigt wird, dann slot_nextProgramm neu aufrufen
    if(counter < list_ItemProgramm.size())
        timer->singleShot(500, this, SLOT(slot_NextProgramm()));


    else
    {
        // Wenn die Nummerierung der Programme DEAKTIVIERT ist füge vor dem Hauptprgamm einen
        // Unterstrich ein _E12345678_E1_Sp1.MPF
        if(!project->get_Numbering())
        {
            QFile::copy(string_ProgrammDir + QDir::separator() + string_ProjectFullName +".MPF",
                        string_Destination + QDir::separator() + "_" + string_ProjectFullName +".MPF");
            QFile::remove(string_ProgrammDir + QDir::separator() + string_ProjectFullName + ".MPF");
        }
        // Wenn die Nummerierung der Programme AKTIVIERT ist füge vor dem Hauptprgamm "00_" ein
        // 00_E12345678_E1_Sp1.MPF
        else
        {
            QFile::copy(string_ProgrammDir + QDir::separator() + string_ProjectFullName +".MPF",
                        string_Destination + QDir::separator() + "00_" + string_ProjectFullName +".MPF");
            QFile::remove(string_ProgrammDir + QDir::separator() + string_ProjectFullName + ".MPF");
        }

        // Abschiessende Automatiesrung wie Antasten, Rohteilkontrolle und Reinigung für Spannung1
        if(project->get_ProjectClamping().contains("Sp1"))
        {
            if(!finish_TouchSp1())
                return;
            if(!finish_RawPartInspection())
                return;
            if(!finish_Cleaning())
                return;
        }

        if(project->get_ProjectClamping().contains("Sp0"))
        {
            if(!finish_TouchSp0())
                return;
        }

        if(project->get_ProjectClamping().contains("Sp2"))
        {
            emit sig_ExportTouchProbe();
        }

        if(!finish_Load())
            return;

        dialog_Progress->hide();
    }
}
