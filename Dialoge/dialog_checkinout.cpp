#include "dialog_checkinout.h"
#include <QMessageBox>
#include <QGuiApplication>

Dialog_CheckInOut::Dialog_CheckInOut(QWidget* parent, Qt::WindowFlags f)
    : QProgressDialog(parent, f)
{
    setWindowTitle("Ordner kopieren");
    setMinimum(0);
    setMaximum(0); // Wird auf die Gesamtanzahl der Dateien gesetzt
    setWindowModality(Qt::WindowModal);
    setCancelButtonText("Abbrechen");
}

void Dialog_CheckInOut::set_Copier(Copier* c)
{
    copier = c;
}

void Dialog_CheckInOut::slot_FileName(QString str)
{
    setLabelText(str);
}

void Dialog_CheckInOut::slot_Finished(bool bool_Success)
{
    if (bool_Success)
    {
        QMessageBox::information(nullptr, "Fertig", "Das Kopieren wurde erfolgreich abgeschlossen.");
    }
    else if (wasCanceled())
    {
        QMessageBox::warning(nullptr, "Abgebrochen", "Der Kopiervorgang wurde abgebrochen.");
        // HINWEIS: Ein Abbruch erfordert das manuelle Aufräumen von Teilkopien.
    }
    else
    {
        QMessageBox::critical(nullptr, "Fehler", "Fehler beim Kopieren aufgetreten.");
    }
}

void Dialog_CheckInOut::slot_SetValue(int value)
{
    //QGuiApplication::processEvents();
    setValue(value);
    if (wasCanceled())
        copier->requestInterruption();
}
