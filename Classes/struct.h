#ifndef STRUCT_H
#define STRUCT_H

#include <QPixmap>
#include <QList>

#include "../Tool/toollist.h"

struct RawPart
{
    QString id;                     //DatenBank ID
    QString x_Length;
    QString y_Width;
    QString z_Height;
    QString z_RawPart;              //Z-Wert für Rohteil Oberkante
};

struct FinishPart
{
    QString id;                     //DatenBank ID
    QString x_Length;
    QString y_Width;
    QString z_Height;
};

struct ZeroPoint
{
    QString id;                     //DatenBank ID
    QString string_X;
    QString string_Y;
    QString string_Z;
    QString string_G;
};


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
    QString lastProduction;         //Wann war das Project das letzte mal auf der Maschine
    QList<QPixmap> listPictures;    //Liste der Bilder;

    RawPart rawPart;                //Struktur für Rohteilmasse
    FinishPart finishPart;          //Struktur für Fertigteilmasse
    ZeroPoint zeroPoint;            //Struktur für Nullpunkt

    ToolList* toolList = new ToolList();                 //Liste der Werkzeuge
};

#endif // STRUCT_H

