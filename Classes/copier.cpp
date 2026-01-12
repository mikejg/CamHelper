#include "copier.h"
#include <QDir>
#include <QDirIterator>
#include <QFile>
#include <QDebug>

Copier::Copier(QObject *parent) : QThread{parent}
{}

void Copier::startCopy(const QString &sourcePath, const QString &destinationPath)
{
    m_sourcePath = sourcePath;
    m_destinationPath = destinationPath;
    start(); // Startet den Thread und ruft run() auf
}

void Copier::run()
{
    //qDebug() << Q_FUNC_INFO ;
    // 1. Dateien zählen (um Maximum für den Fortschrittsbalken zu bestimmen)
    int totalFiles = countFiles(m_sourcePath);
    emit fileCountReady(totalFiles);


    // 2. Kopieren starten und Fortschritt melden
    int copiedCount = 0;
    bool success = moveRecursively(m_sourcePath, m_destinationPath, copiedCount);

    // 3. Ergebnis melden
    emit finishedCopy(success);
}

int Copier::countFiles(const QString &path)
{
    int count = 0;
    QDirIterator it(path, QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);

    while (it.hasNext()) {
        it.next();
        if (it.fileInfo().isFile()) {
            count++;
        }
    }
    return count;
}

bool Copier::copyRecursively(const QString &source, const QString &destination, int &copiedCount)
{
    QStringList stringList;
    QDir sourceDir(source);
    if (!sourceDir.exists())
        return false;

    QDir destDir(destination);
    if (!destDir.exists() && !destDir.mkpath(destination))
        return false;

    QDirIterator it(source, QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDirIterator::NoIteratorFlags);

    while (it.hasNext()) {
        it.next();
        QString srcPath = it.filePath();
        QString fileName = it.fileName();
        QString destPath = destination + QDir::separator() + fileName;

        if (it.fileInfo().isDir())
        {
            // Rekursiver Aufruf für Unterordner
            if (!copyRecursively(srcPath, destPath, copiedCount))
                return false;
        }
        else if (it.fileInfo().isFile())
        {
            // Datei kopieren
            if (!QFile::copy(srcPath, destPath)) {
                qWarning() << "Fehler beim Kopieren von:" << srcPath << "nach" << destPath;
                return false;
            }
            copiedCount++;
            stringList = srcPath.split("/");
            emit sig_FileName(stringList.last());
            emit progress(copiedCount); // Fortschritt melden
        }
    }
    return true;
}

bool Copier::moveRecursively(const QString &source, const QString &destination, int &movedCount)
{
    QStringList stringList;
    QDir sourceDir(source);
    QDir destDir;

    // Zielverzeichnis erstellen
    if (!destDir.mkpath(destination)) return false;

    QDirIterator it(source, QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDirIterator::NoIteratorFlags);

    while (it.hasNext())
    {
        it.next();
        QString srcPath = it.filePath();
        QString destPath = destination + "/" + it.fileName();

        if (it.fileInfo().isDir())
        {
            // Rekursion für Unterordner
            if (!moveRecursively(srcPath, destPath, movedCount)) return false;
        }
        else
        {
            // Prüfung: Existiert die Datei am Ziel schon? (Optional: Löschen oder Überspringen)
            if (QFile::exists(destPath))
            {
                if (!QFile::remove(destPath)) return false;
            }

            // VERSUCH 1: Direktes Verschieben (schnell, falls gleicher Datenträger)
            if (!QFile::rename(srcPath, destPath))
            {

                // VERSUCH 2: Fallback für unterschiedliche Datenträger (Kopieren + Löschen)
                if (QFile::copy(srcPath, destPath))
                {
                    if (!QFile::remove(srcPath))
                    {
                        qWarning() << "Kopie erfolgreich, aber Quell-Datei konnte nicht gelöscht werden:" << srcPath;
                    }
                }
                else
                {
                    qWarning() << "Kopieren fehlgeschlagen:" << srcPath;
                    return false; // Abbruch bei Fehler
                }
            }

            movedCount++;
            stringList = srcPath.split("/");
            emit sig_FileName(stringList.last());
            emit progress(movedCount);
        }

        // Abbruchprüfung, falls der Nutzer auf "Abbrechen" geklickt hat
        if (this->isInterruptionRequested()) return false;
    }

    // Am Ende den leeren Quellordner entfernen
    return sourceDir.rmdir(source);
}
