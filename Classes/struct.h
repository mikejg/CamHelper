#ifndef STRUCT_H
#define STRUCT_H

#include <QPixmap>
#include <QList>

#include "../Tool/toollist.h"
#include "../TouchProbe/tp_struct.h"

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

struct Offset_RawPart
{
    QString id;
    QString string_XPlus = "2";
    QString string_XMinus = "2";
    QString string_YPlus = "2";
    QString string_YMinus = "2";
    QString string_ZPlus= "2";
};

struct Programm
{
    QString id;
    QString ProgrammName;
    QString Project_ID;
    bool Offset_X;
    bool Offset_Y;
    bool Offset_Z;
    bool TOFFL;
    bool NoXY;

    Programm(QString prg = "", QString p = "") : ProgrammName(prg), Project_ID(p)
    {
        Offset_X = false;
        Offset_Y = false;
        Offset_Z = false;
        TOFFL    = false;
        NoXY     = false;
    }
};

struct Item_TouchProbe
{
    enum State{NoState, Kante, Ausrichten, Steg, Bohrung, Ebenheit, Nut};

    int Pos;
    State state;
    Struct_Ausrichten struct_Ausrichten;
    Struct_Kante struct_Kante;
    Struct_Ebenheit struct_Ebenheit;
    Struct_Steg struct_Steg;
    Struct_Bohrung struct_Bohrung;
    Struct_Nut struct_Nut;

    bool operator!=(const Item_TouchProbe& t) const
    {
        if(Pos != t.Pos) return true;
        if(state != t.state) return true;
        if(struct_Ausrichten != t.struct_Ausrichten) return true;
        if(struct_Kante != t.struct_Kante) return true;
        if(struct_Ebenheit != t.struct_Ebenheit) return true;
        if(struct_Steg != t.struct_Steg) return true;
        if(struct_Bohrung != t.struct_Bohrung) return true;
        if(struct_Nut != t.struct_Nut) return true;

        return false;
    }
};


struct ProjectData
{
    QString id;                             //DatenBank ID
    QString name;                           //Name des Projekts
    QString state;                          //Entwicklungsstand
    QString tension;                        //Spannung Sp1 Sp2 ..
    QString hyperMILL_File;                 //hyperMILL File zum öffnen des Projects in hyperMILL
    QString material;                       //Material des Bauteils
    QString header;                         //Programmkopf des Hauptprogramms;
    QString rawPart_Inspection;             //Die zu verwendende Rohteilkontrolle
    QString lastOpen;                       //Zeitpunt des letzen Öffnens
    QString lastProduction;                 //Wann war das Project das letzte mal auf der Maschine
    QList<QPixmap> listPictures;            //Liste der Bilder;
    QStringList listTags;                   //Liste der Tags;

    RawPart rawPart;                        //Struktur für Rohteilmasse
    FinishPart finishPart;                  //Struktur für Fertigteilmasse
    ZeroPoint zeroPoint;                    //Struktur für Nullpunkt
    Offset_RawPart offset_RawPart;          //Struktur für Rohteil Aufmass
    ToolList* toolList = new ToolList();    //Liste der Werkzeuge
    QList<Programm> list_Programm;          //Liste der Programme
    QList<Item_TouchProbe> list_TouchProbe; //Liste der Antastzyklen
};

#endif // STRUCT_H

