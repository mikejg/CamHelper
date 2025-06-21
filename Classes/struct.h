#ifndef STRUCT_H
#define STRUCT_H

#include <QPixmap>
#include <QList>

struct ProjectData
{
    QString id;                     //DatenBank ID
    QString name;                   //Name des Projekts
    QString state;                  //Entwicklungsstand
    QString tension;                //Spannung Sp1 Sp2 ..
    QString hyperMILL_File;         //hyperMILL File zum öffnen des Projects in hyperMILL
    QString material;               //Material des Bauteils
    QString header;                 //Programmkopf des Hauptprogramms;
    QString rawPart_Inspection;     //Die zu verwendende Rohteilkontrolle
    QString lastOpen;               //Zeitpunt des letzen Öffnens
    QString lastProduction;          //Wann war das Project das letzte mal auf der Maschine
    QList<QPixmap> listPictures;    //Liste der Bilder;
};

#endif // STRUCT_H

