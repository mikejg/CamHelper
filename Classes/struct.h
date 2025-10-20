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

    bool operator==(const RawPart& other) const {
        return (x_Length  == other.x_Length &&
                y_Width   == other.y_Width &&
                z_Height  == other.z_Height &&
                z_RawPart == other.z_RawPart);
    }

    bool operator!=(const RawPart& other) const {
        return !(*this == other);
    }
};

struct FinishPart
{
    QString id;                     //DatenBank ID
    QString x_Length;
    QString y_Width;
    QString z_Height;

    bool operator==(const FinishPart& other) const {
        return (x_Length  == other.x_Length &&
                y_Width   == other.y_Width &&
                z_Height  == other.z_Height);
    }

    bool operator!=(const FinishPart& other) const {
        return !(*this == other);
    }
};

struct ZeroPoint
{
    QString id;                     //DatenBank ID
    QString string_X;
    QString string_Y;
    QString string_Z;
    QString string_G;

    bool operator==(const ZeroPoint& other) const {
        return (string_X == other.string_X &&
                string_Y == other.string_Y &&
                string_Z == other.string_Z &&
                string_G == other.string_G);
    }

    bool operator!=(const ZeroPoint& other) const {
        return !(*this == other);
    }
};

struct Offset_RawPart
{
    QString id;
    QString string_Max_XPlus  = "2";
    QString string_Max_XMinus = "2";
    QString string_Max_YPlus  = "2";
    QString string_Max_YMinus = "2";
    QString string_Max_ZPlus  = "2";

    QString string_Min_XPlus  = "0.8";
    QString string_Min_XMinus = "0.8";
    QString string_Min_YPlus  = "0.8";
    QString string_Min_YMinus = "0.8";
    QString string_Min_ZPlus  = "0.8";

    //Werte für die Rohteilkontrolle
    QString string_Max_XPlus_RawpartInspection;
    QString string_Max_XMinus_RawpartInspection;
    QString string_Max_YPlus_RawpartInspection;
    QString string_Max_YMinus_RawpartInspection;
    QString string_Max_ZPlus_RawpartInspection;

    bool operator==(const Offset_RawPart& other) const
    {
        return (string_Max_XPlus  == other.string_Max_XPlus &&
                string_Max_XMinus == other.string_Max_XMinus &&
                string_Max_YPlus  == other.string_Max_YPlus &&
                string_Max_YMinus == other.string_Max_YMinus &&

                string_Min_XMinus == other.string_Min_XMinus &&
                string_Min_XPlus  == other.string_Min_XPlus &&
                string_Min_YMinus == other.string_Min_YMinus &&
                string_Min_YPlus  == other.string_Min_YPlus &&
                string_Min_ZPlus  == other.string_Min_ZPlus &&

                string_Max_XMinus_RawpartInspection == other.string_Max_XMinus_RawpartInspection &&
                string_Max_XPlus_RawpartInspection  == other.string_Max_XPlus_RawpartInspection &&
                string_Max_YMinus_RawpartInspection == other.string_Max_YMinus_RawpartInspection &&
                string_Max_YPlus_RawpartInspection  == other.string_Max_YPlus_RawpartInspection &&
                string_Max_ZPlus_RawpartInspection  == other.string_Max_ZPlus_RawpartInspection);
    }

    bool operator!=(const Offset_RawPart& other) const
    {
        return !(*this == other);
    }

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

    bool operator==(const Programm& other) const
    {
        return (ProgrammName == other.ProgrammName &&
                Offset_X     == other.Offset_X &&
                Offset_Y     == other.Offset_Y &&
                Offset_Z     == other.Offset_Z &&
                TOFFL        == other.TOFFL &&
                NoXY         == other.NoXY);
    }

    bool operator!=(const Programm& other) const
    {
        return !(*this == other);
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

    bool operator==(const Item_TouchProbe& other) const
    {
        return (Pos                 == other.Pos &&
                state               == other.state &&
                struct_Ausrichten   == other.struct_Ausrichten &&
                struct_Kante        == other.struct_Kante &&
                struct_Ebenheit     == other.struct_Ebenheit &&
                struct_Steg         == other.struct_Steg &&
                struct_Bohrung      == other.struct_Bohrung &&
                struct_Nut          == other.struct_Nut);
    }

    bool operator!=(const Item_TouchProbe& other) const
    {
        return !(*this == other);
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
    QString string_ProgrammDir;             //Pfad wo die Programme liegen

    RawPart rawPart;                        //Struktur für Rohteilmasse
    FinishPart finishPart;                  //Struktur für Fertigteilmasse
    ZeroPoint zeroPoint;                    //Struktur für Nullpunkt
    Offset_RawPart offset_RawPart;          //Struktur für Rohteil Aufmass
    ToolList* toolList = new ToolList();    //Liste der Werkzeuge
    ToolList* toolList_IN;                  //Liste der Werkzeuge die Eingelagert werden müssen
    QList<Programm> list_Programm;          //Liste der Programme
    QList<Item_TouchProbe> list_TouchProbe; //Liste der Antastzyklen


    bool operator==(const ProjectData& other) const
    {
        return (name == other.name &&
                state               == other.state &&
                tension             == other.tension &&
                hyperMILL_File      == other.hyperMILL_File &&
                material            == other.material &&
                header              == other.header &&
                rawPart_Inspection  == other.rawPart_Inspection &&
                lastOpen            == other.lastOpen &&
                lastProduction      == other.lastProduction &&
                //listPictures        == other.listPictures &&
                listTags            == other.listTags &&
                string_ProgrammDir  == other.string_ProgrammDir &&
                rawPart             == other.rawPart &&
                finishPart          == other.finishPart &&
                zeroPoint           == other.zeroPoint &&
                //*toolList           == *other.toolList &&
                list_Programm       == other.list_Programm &&
                list_TouchProbe     == other.list_TouchProbe);
    }

    bool operator!=(const ProjectData& other) const
    {
        return !(*this == other);
    }
};

#endif // STRUCT_H

