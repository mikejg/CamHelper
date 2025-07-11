#include "mfile.h"

MFile::MFile(QObject *parent, Logging* l)
    : QFile{parent}
{
    log = l;
}

MFile::MFile(QString name, Logging* l)
    : QFile{name}
{
    log = l;
}

bool MFile::read_Content()
{
    /* Versuche das File zu öffnen,
     * wenn das fehl schlägt gib eine Fehlermeldung raus
     * und bende die Funktion mit false */
    if(!this->open(QFile::ReadOnly))
    {
        log->vailed("Konnte " + fileName() + " nicht oeffenen");
        return false;
    }

    /* Erzeuge einen QStream auf das File
     * Setze die Codierung auf Latin1 */
    textStream_Read = new QTextStream(this);
    textStream_Read->setAutoDetectUnicode(false);
    textStream_Read->setEncoding(QStringConverter::Latin1);

    /* Lösche den Inhalt von stringList_Content
     * Lese Zeile für Zeile und schreibe jede Zeile in die QStringList stringList_Content
     * schliesse das File */
    stringList_Content.clear();
    while(!textStream_Read->atEnd())
    {
        stringList_Content.append(textStream_Read->readLine());
    }
    this->close();
    return true;
}

void MFile::save(QStringList stringList)
{
    this->remove();
    if(!this->open(QFile::WriteOnly))
    {
        log->vailed("Konnte " + fileName() + " nicht oeffenen");
        return;
    }

    textStream_Write = new QTextStream(this);
    textStream_Write->setAutoDetectUnicode(false);
    textStream_Write->setEncoding(QStringConverter::Latin1);
    foreach(QString str, stringList)
    {
        *textStream_Write << str << '\n';
    }
    this->close();
    return;
}
