#include "logging.h"

Logging::Logging(QWidget *parent) : QTextEdit(parent)
{
    highLighter = new HighLighter(document());
}

Logging::~Logging()
{

}

void Logging::message(QString m)
{
    //wenn schon mal ein Fehler aufgetreten ist
    // logge keine Message mehr
    if(bool_Error)
        return;

    append(QString("Ⓜ ") + m);
}

void Logging::successful(QString s)
{
    //wenn schon mal ein Fehler aufgetreten ist
    // logge keine Message mehr
    if(bool_Error)
        return;

    append(QString("Ⓢ " ) + s);
}

void Logging::warning(QString w)
{
    /*
    // siehe void Logging::message(QString m)
    stringList_Text.clear();
    stringList_Text.append("Warning");
    stringList_Text.append(w);
    frame_Warning(stringList_Text);
    */

    append(QString("Ⓦ " ) + w);
}

void Logging::error(QString e)
{
    append(QString("Ⓔ " ) + e);
}

void Logging::frame(QStringList stringList, QString code)
{
    // Zieht einen ASCII Rahmen um die Fehlermeldungen */

    //füge eine Leerzeile ein
    //append("\n");

    int     maxLength = 0;
    QString string_Bar;
    bool    bool_Bar = false;

    /* ermittle den längsten String */
    foreach (QString str, stringList)
    {
        if(str.length() > maxLength)
            maxLength = str.length();
    }

    // Erzeuge einen Balken mit der länge der
    // längsten Fehlermeldung
    // und hänge am Schluss noch mal 3 '-' an
    string_Bar = "+";
    while(string_Bar.length() <= maxLength)
    {
        string_Bar = string_Bar + "-";
    }
    string_Bar = string_Bar +"--+";

    // gib den Balken als obern Balken aus
    //append(string_Bar);
    append(code + string_Bar);

    foreach (QString str, stringList)
    {
        // Wenn es die erste Fehlermeldung ist setze dir einen Merker */
        if(str == stringList.first())
            bool_Bar = true;

        // Verlängere die Fehlermeldung mit Leerzeichen auf die
        // Länge des Balkens.
        // Hänge am Anfang und am Ende ein '|' an und gib die
        // Fehlermeldung aus
        while(str.length() < maxLength)
            str = str + " ";

        append(code + "| " + str + " |");

        // Wenn es sich um die erste Fehlermeldung gib einen Balken aus */
        if(bool_Bar)
        {
            append(code + string_Bar);
            bool_Bar = false;
        }
    }

    // gib den Balken als unteren Balken aus
    append(code + string_Bar +"\n");

}

void Logging::frame_Error(QStringList strList)
{
    // Erstelle einen Rahmen mit der Fehlermedung
    // setzte bool_Error auf true
    frame(strList, QString("Ⓔ " ));
    bool_Error = true;
    //bringt das Tab Log in den Vordergrund
    emit sig_ShowLog();
}

void Logging::frame_Message(QStringList strList)
{
    //wenn schon mal ein Fehler aufgetreten ist
    // logge keine Message mehr
    if(bool_Error)
        return;

    // Erstelle einen Rahmen mit der Meldung
    frame(strList, QString("Ⓜ "));
}

void Logging::frame_Warning(QStringList strList)
{
    // Erstelle einen Rahmen mit der Warnung
    frame(strList, QString("Ⓦ " ));
}

void Logging::frame_Successful(QStringList strList)
{
    //wenn schon mal ein Fehler aufgetreten ist
    // logge keine Erfolgsmeldung mehr
    if(bool_Error)
        return;

    // Erstelle einen Rahmen mit der
    // Erfolgsmeldung
    frame(strList, QString("Ⓢ " ));
    emit sig_ShowLog();
}
