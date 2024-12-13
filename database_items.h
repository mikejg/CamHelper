#ifndef DATABASE_ITEMS_H
#define DATABASE_ITEMS_H

#include "TouchProbe/tp_struct.h"

struct Item_NCToolProject
{
    QString id;
    QString T_Number;
    QString Project_ID;

    Item_NCToolProject(QString tn = "", QString p = "") : T_Number(tn), Project_ID(p)
    {}

    bool operator==(const Item_NCToolProject& t) const
    {
        return T_Number == t.T_Number && Project_ID == t.Project_ID;
    }
};


struct Item_Programm
{
    QString id;
    QString Programm;
    QString Project_ID;
    bool Offset_X;
    bool Offset_Y;
    bool Offset_Z;
    bool TOFFL;
    bool NoXY;

    Item_Programm(QString prg = "", QString p = "") : Programm(prg), Project_ID(p)
    {
        Offset_X = false;
        Offset_Y = false;
        Offset_Z = false;
        TOFFL    = false;
        NoXY     = false;
    }

    bool operator==(const Item_Programm& t) const
    {
        return Programm == t.Programm && Project_ID == t.Project_ID;
    }
};


struct Item_Project
{
    QString id;
    QString Name;
    QString Status;
    QString ZeroPoint;
    QString Material;
    QString RawPart_X;
    QString RawPart_Y;
    QString RawPart_Z;
    QString Component_X;
    QString Component_Y;
    QString Component_Z;
    QString ZRawPart;
    QString Clamping;
    QString RawPartInspection;
    QString CamFile;
    QString Comment;
    //QStringList Programme;
    QString Last_Production;
    QString XPlus_Max, XMinus_Max;
    QString YPlus_Max, YMinus_Max;
    QString ZPlus_Max;
    QString NPx;
    QString NPy;
    QString NPz;

    QList<Item_Programm> list_Programme;

    Item_Project(QString n = "", QString c = "") : Name(n), Clamping(c)
    {
        XPlus_Max = "2", XMinus_Max = "2";
        YPlus_Max = "2", YMinus_Max = "2";
        ZPlus_Max = "2";
        RawPartInspection = "Rohteilkontrolle";
        ZRawPart = "1";
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

};


#endif // DATABASE_ITEMS_H
