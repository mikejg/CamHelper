#include "project_export.h"
#include "QDate"
#include <QDateTime>

Project_Export::Project_Export(QObject *parent)
    : QObject{parent}
{
    dialog_Progress = new Dialog_Progress();
}


void Project_Export::set_ContentMainProgramm(QTextEdit* textEdit)
{
    stringList_ContentMainProgramm = textEdit->toPlainText().split("\n");
}

void Project_Export::exportProject(ProjectData* pd, bool bool_IncToolCount)
{
    projectData = pd;
    QDate currentDate = QDate::currentDate();                   //Erstelle einen String des Datums
    pd->lastProduction = currentDate.toString("dd.MM.yyyy");

    QDir dir_Template;
    QStringList stringList_Files;

    QDateTime utcTime = QDateTime::currentDateTimeUtc();        //Erstelle einen Utc Zeitstempel
    qint64 epochSeconds = utcTime.toSecsSinceEpoch();
    pd->lastOpen = QString("%1").arg(epochSeconds);

    if(!dataBase->save(pd))                                     //Wenn es einen Fehler beim Speichern gibt
    {                                                           //lösche das unvollständige Project wieder aus der Datenbank
        dataBase->delete_ProjectData(pd);                       //und brich den Export ab
        return;
    }

    //Erzeuge das Verzeichenis Programme/E123456789.WDP/E123456789_E1_Sp1.WDP
    dir_Destination.mkpath(pd->string_ProgrammDir + "/" +
                          pd->name + ".WDP/" +
                          pd->name + "_" + pd->state + "_" + pd->tension + ".WPD");
    dir_Destination.setPath(pd->string_ProgrammDir + "/" +
                           pd->name + ".WDP/" +
                           pd->name + "_" + pd->state + "_" + pd->tension + ".WPD");
    //Erzeuge das Hauptprogramm 00_E123456789_E1_Sp1.MPF
    QFile file(pd->string_ProgrammDir + "/" + "00_" +  pd->name + "_" + pd->state + "_" + pd->tension + ".MPF");
    if(file.open(QFile::WriteOnly))
    {
        QTextStream stream(&file);
        foreach(QString string_Line, stringList_ContentMainProgramm)
        {
            stream << string_Line << "\n";
        }
        file.close();
    }
    else
    {
        log->vailed(Q_FUNC_INFO);
        log->vailed("Konnte Hauptprogramm nicht erstellen");
        return;
    }

    //Erzeuge QDir mit den Vorlagen
    dir_Template.setPath( QDir::homePath() + "/CamHelper/Vorlagen/Verzeichnisse/" + pd->tension + ".WPD");

    if(!dir_Template.exists())
    {
        log->vailed(Q_FUNC_INFO);
        log->vailed("konnte Vorlagen nicht finden");
    }


    stringList_Files = dir_Template.entryList(QDir::Files);                 //Lies alle Dateien aus den Vorlagen
    for(int i = stringList_Files.size() - 1; i >= 0; --i)                   //und lösche alle _Sp1_Rohteilkontrolle
    {
        if(stringList_Files.at(i).startsWith("_Sp1_Rohteilkontrolle"))
            stringList_Files.removeAt(i);
    }
    stringList_Files.append("_Sp1_" + pd->rawPart_Inspection + ".SPF");     //Füge die aktuelle Rohteilkontrolle in die Liste mit ein

    foreach(QString f, stringList_Files)                                    //Kopiere die Dateien nach E123456789.WPD/E123456789_E1_Sp1.WPD
    {
        QFile::copy(dir_Template.path() + QDir::separator() + f,
                    dir_Destination.path() + QDir::separator() + f);

    }

    if(bool_IncToolCount && !dataBase->inc_ToolCounter(pd->toolList))       //erhöhe den Zähler der Werkzeuge um eins
        return;

    spf_Parser = new SPF_Parser(this,pd->string_ProgrammDir,log,dataBase);  //erzeuge einen neuen SPF Parser
    spf_Parser->set_ProjectData(projectData);                               //übergebe dem spf_Parser die Projekt Daten
    counter = 0;                                                            //bereite alles für den Export vor. Setze Programmzähler auf 0
    dialog_Progress->init_Dialog(pd->list_Programm.size());                 //Übergebe die Anzahl der Programm an den Fortschritt Dialog
    dialog_Progress->show();                                                //Zeige den FortschrittDialog
    QTimer::singleShot(0,this,SLOT(slot_NextProgramm()));                   //starte den Export

    return;
}

void Project_Export::slot_NextProgramm()
{
    QFileInfo fileInfo;
    programm = projectData->list_Programm.at(counter);                      //setze programm auf das aktuelle Programm
    dialog_Progress->set_Value(programm.ProgrammName, counter);             //Aktualisiere den Dialog Fortschritt

    mfile->setFileName(projectData->string_ProgrammDir + "/" +              //setze den ProgrammPfad
                       programm.ProgrammName);
    fileInfo = QFileInfo(*mfile);                                           //erstelle fileInfo mit mfile
    if(mfile->exists())
    {
        log->log("----------------------------------------");
        spf_Parser->finish(fileInfo.absoluteFilePath(), programm);          //gehe durch das SPF-File und ersetze Bruch, NoXY, stopre etc
        //Kopiere das SPF-File nach Programme/E123456789/E123456789_Ex_SpX/01_SpX_XXXXXXXXXX.spf
        QFile::copy(projectData->string_ProgrammDir + QDir::separator() + programm.ProgrammName,
                    dir_Destination.path() + QDir::separator() + programm.ProgrammName);
        //Lösche das SPF-File
        QFile::remove(projectData->string_ProgrammDir + QDir::separator() + programm.ProgrammName);
        log->log("----------------------------------------");
    }
    else                                                                    //Wenn das SPF-File nicht da ist wird es übersprungen
    {
        log->log("----------------------------------------");
        log->log(programm.ProgrammName + " übersprungen");
        log->log("----------------------------------------");
    }

    counter++;                                                              //Counter um eins hochzaehlen und Fortschrittbalken aktualisieren
    dialog_Progress->update();

    // Wenn Counter kleiner als projectData->list_Programm.size eine halbe Sekunde warten,
    // damit der Fortschrittbalken neu angezeigt wird, dann slot_nextProgramm neu aufrufen
    if(counter < projectData->list_Programm.size())
    {
        QTimer::singleShot(100,this,SLOT(slot_NextProgramm()));
    }
    else //Kopiere das Hauptprogramm und lösche das Orginal
    {
        QFile::copy(projectData->string_ProgrammDir + QDir::separator() +
                    "00_" +  projectData->name + "_" + projectData->state + "_" + projectData->tension +".MPF",
                    dir_Destination.path() + QDir::separator() +
                    "00_" +  projectData->name + "_" + projectData->state + "_" + projectData->tension +".MPF");
        QFile::remove(projectData->string_ProgrammDir + QDir::separator() +
                      "00_" +  projectData->name + "_" + projectData->state + "_" + projectData->tension +".MPF");

        if(projectData->tension == "Sp1")
        {
            if(!replace_Wildcart(dir_Destination.path() + "/_Sp1_Rohteil_antasten.SPF"))
                return;

            if(!replace_Wildcart(dir_Destination.path() + "/_Sp1_" + projectData->rawPart_Inspection + ".SPF"))
                return;

            if(!replace_Wildcart(dir_Destination.path() + "/_Sp1_Reinigen.SPF"))
                return;
        }

        if(!finish_Load())
            return;

        dialog_Progress->hide();
    }
}

bool Project_Export::replace_Wildcart(QString string_FilePath)
{
    QStringList stringList_Content;
    mfile->setFileName(string_FilePath);
    if(!mfile->read_Content())
        return false;
    stringList_Content = mfile->get_Content();
    stringList_Content = spf_Parser->replace_Wildcard(stringList_Content);
    mfile->save(stringList_Content);
    return true;
}

void Project_Export::set_Logging(Logging *l)
{
    log = l;
    mfile = new MFile(this,log);
}


bool Project_Export::finish_Load()
{
    if(!loadBruch())
        return false;

    QString string_Loading_Source;
    QString string_Loading_Destination;
    QString string_ToolID;
    QString string_Bruch;

    QStringList stringList_Head;
    QStringList stringList_Body;
    QStringList stringList_End;
    QStringList stringList_File;

    /*string_Destination = string_ProgrammDir + "/" +
                         string_ProjectName + ".WPD/" +
                         string_ProjectFullName + ".WPD";*/

    /*Kopiert den Ordner Vorlagen.WPD/WKZ_beladen.WPD nach
     * Programme/E123456789.WPD/E123456789_E0_Sp1.WPD/E123456789_E0_Sp1_In.WPD*/

    string_Loading_Destination = dir_Destination.path() + "/Rusten_" + projectData->name +"_" + projectData->state + "_" + projectData->tension + ".WPD";
    string_Loading_Source      = QDir::homePath() + "/CamHelper/Vorlagen/Verzeichnisse/WKZ_beladen.WPD";

    QDir dir_Vorlagen(string_Loading_Source);
    if(!dir_Vorlagen.exists())
    {
        log->vailed(QDir::homePath() + "/CamHelper/Vorlagen/Verzeichnisse/WKZ_beladen.WPD");
        return false;
    }
    dir_Vorlagen.mkpath(string_Loading_Destination);

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

    mfile->setFileName(string_Loading_Destination + QDir::separator() + "_WKZ_Kontrolle.spf");

    /*Gehe durch die stringList_Kopf
     * Schreibe string_Line in das File
     * Wenn du zum Marker 'Werkzeugliste Anfang' kommst gehe durch die Liste
     * der einzulagernden Werkzeuge. */
    int count = 1;
    foreach(QString string_Line, stringList_Head)
    {
        stringList_File.append(QString("N%1 ").arg(count) + string_Line);
        count++;
        if(string_Line.contains("Werkzeugliste Anfang"))
        {
            foreach(Tool* tool, projectData->toolList_IN->get_List())
            {
                stringList_File.append(QString("N%1 ").arg(count) +
                                       "; T " + tool->get_Number() +
                                       "  " + tool->get_Description());
                count++;
            }
        }
    }

    /*Geh durch die Liste der einzulagernden Werkzeuge
     * Geh durch stringList_Rumpf
     * Ersetze '$TNumber$ durch die ToolID und ToolBeschreibung
     * Wenn die ToolID mit 29 beginnt (Einlippenbohrer) dann
     * ersetze 'BRUCH' mit 'BRUCH2' */
    foreach (Tool* tool, projectData->toolList_IN->get_List())
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

            stringList_File.append(QString("N%1 ").arg(count) + string_Body);
            count++;
        }
    }

    foreach(QString string_Line, stringList_End)                                //Schreibe das Ende ins File
    {
        stringList_File.append(QString("N%1 ").arg(count) + string_Line);
        count++;
    }

    mfile->save(stringList_File);                                               //Speicher das File
    //spf_Parser->finish(mfile->fileName(),programm);                             //Geh nochmal durch das File und ändere die Bruchkontrolle

    mfile->setFileName(QDir::homePath() + "/CamHelper/config/Nullpunkt.spf");
    if(!mfile->read_Content())
        return false;
    stringList_Body = mfile->get_Content();
    stringList_File.clear();

    foreach(QString string, stringList_Body)
    {
        if(string.contains("$G$"))
            string = string.replace("$G$", "\"" + projectData->zeroPoint.string_G + "\"");
        if(string.contains("$NPx$"))
            string = string.replace("$NPx$", projectData->zeroPoint.string_X);
        if(string.contains("$NPy$"))
            string = string.replace("$NPy$", projectData->zeroPoint.string_Y);
        if(string.contains("$NPz$"))
            string = string.replace("$NPz$", projectData->zeroPoint.string_Z);

        stringList_File.append(string);
    }

    mfile->setFileName(string_Loading_Destination + QDir::separator() + "_NP_Setzen.spf");
    mfile->save(stringList_File);

    int i = 1;
    foreach(QPixmap pixmap, projectData->listPictures)
    {
        QFile file(string_Loading_Destination + QDir::separator() + QString("Bild_%1.png").arg(i));
        pixmap.save(&file, "PNG");
        i++;
    }

    return true;
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
