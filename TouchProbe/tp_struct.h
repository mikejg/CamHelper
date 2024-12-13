#ifndef TP_STRUCT_H
#define TP_STRUCT_H
#include <QString>

struct Struct_Ausrichten
{
    QString string_Pos;
    QString string_Frame;
    QString string_Messrichtung;
    QString string_Messachse;
    QString string_Positionierachse;
    QString string_L2;
    QString string_TSA;
    QString string_Anfahren;

};

struct Struct_Kante
{
    QString string_Pos;
    QString string_Frame;
    QString string_Messrichtung;
    QString string_Messachse;
    QString string_Wert;
    QString string_DFA;
    QString string_TSA;
    QString string_Anfahren;
};

struct Struct_Ebenheit
{
    QString string_Pos;
    QString string_Frame;
    QString string_ZEbene;
    QString string_Vertrauensbereich;
    QString string_Punkt1X;
    QString string_Punkt1Y;
    QString string_Punkt2X;
    QString string_Punkt2Y;
    QString string_Punkt3X;
    QString string_Punkt3Y;
    QString string_Punkt4X;
    QString string_Punkt4Y;
    bool bool_Jump1;
    bool bool_Jump2;
    bool bool_Jump3;

    Struct_Ebenheit()
    {
        bool_Jump1 = false;
        bool_Jump2 = false;
        bool_Jump3 = false;
    }
};

struct Struct_Steg
{
    QString string_Pos;
    QString string_Frame;
    QString string_Messachse;
    QString string_W;
    QString string_DZ;
    QString string_DFA;
    QString string_TSA;
    QString string_Anfahren;
};

struct Struct_Nut
{
    QString string_Pos;
    QString string_Frame;
    QString string_Messachse;
    QString string_W;
    QString string_DFA;
    QString string_TSA;
    QString string_Anfahren;
};
struct Struct_Bohrung
{
    QString string_Pos;
    QString string_Frame;
    QString string_Durchmesser;
    QString string_TSA;
    QString string_Anfahren;
};
#endif // TP_STRUCT_H
