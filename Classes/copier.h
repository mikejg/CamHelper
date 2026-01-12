#ifndef COPIER_H
#define COPIER_H

#include <QThread>
#include <QString>

class Copier : public QThread
{
    Q_OBJECT

public:
    explicit Copier(QObject *parent = nullptr);

    // Methode zum Starten des Kopiervorgangs mit Pfaden
    void startCopy(const QString &sourcePath, const QString &destinationPath);

   // Signal, das das Ende des Kopiervorgangs meldet


protected:
    void run() override;

private:
    QString m_sourcePath;
    QString m_destinationPath;

    // Funktion zur rekursiven Zählung aller Dateien
    int countFiles(const QString &path);

    // Funktion zur rekursiven Kopie
    bool copyRecursively(const QString &source, const QString &destination, int &copiedCount);
    bool moveRecursively(const QString &source, const QString &destination, int &copiedCount);

signals:
    // Signal, das die Gesamtanzahl der Dateien für den QProgressDialog meldet
    void fileCountReady(int count);
    // Signal, das den Fortschritt meldet (Anzahl der bisher kopierten Dateien)
    void progress(int value);
    void sig_FileName(QString);
    void finishedCopy(bool success);
};

#endif // COPIER_H
