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

    bool operator==(const Struct_Ausrichten& other) const
    {
        return (string_Pos               == other.string_Pos &&
                string_Frame             == other.string_Frame &&
                string_Messrichtung      == other.string_Messrichtung &&
                string_Positionierachse  == other.string_Positionierachse &&
                string_L2                == other.string_L2 &&
                string_TSA               == other.string_TSA &&
                string_Anfahren          == other.string_Anfahren);
    }

    bool operator!=(const Struct_Ausrichten& other) const
    {
        return !(*this == other);
    }
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

    bool operator==(const Struct_Kante& other) const
    {
        return (string_Pos               == other.string_Pos &&
                string_Frame             == other.string_Frame &&
                string_Messrichtung      == other.string_Messrichtung &&
                string_Messachse         == other.string_Messachse &&
                string_Wert              == other.string_Wert &&
                string_DFA               == other.string_DFA &&
                string_TSA               == other.string_TSA &&
                string_Anfahren          == other.string_Anfahren);
    }

    bool operator!=(const Struct_Kante& other) const
    {
        return !(*this == other);
    }
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

    bool operator==(const Struct_Ebenheit& other) const
    {
        return (string_Pos               == other.string_Pos &&
                string_Frame             == other.string_Frame &&
                string_ZEbene            == other.string_ZEbene &&
                string_Vertrauensbereich == other.string_Vertrauensbereich &&
                string_Punkt1X           == other.string_Punkt1X &&
                string_Punkt1Y           == other.string_Punkt1Y &&
                string_Punkt2X           == other.string_Punkt2X &&
                string_Punkt2Y           == other.string_Punkt2Y &&
                string_Punkt3X           == other.string_Punkt3X &&
                string_Punkt3Y           == other.string_Punkt3Y &&
                string_Punkt4X           == other.string_Punkt4X &&
                string_Punkt4Y           == other.string_Punkt4Y &&
                bool_Jump1               == other.bool_Jump1 &&
                bool_Jump2               == other.bool_Jump2 &&
                bool_Jump3               == other.bool_Jump3);
    }

    bool operator!=(const Struct_Ebenheit& other) const
    {
        return !(*this == other);
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

    bool operator==(const Struct_Steg& other) const
    {
        return (string_Pos               == other.string_Pos &&
                string_Frame             == other.string_Frame &&
                string_Messachse         == other.string_Messachse &&
                string_W                 == other.string_W &&
                string_DZ                == other.string_DZ &&
                string_DFA               == other.string_DFA &&
                string_TSA               == other.string_TSA &&
                string_Anfahren          == other.string_Anfahren);
    }

    bool operator!=(const Struct_Steg& other) const
    {
        return !(*this == other);
    }
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

    bool operator==(const Struct_Nut& other) const
    {
        return (string_Pos               == other.string_Pos &&
                string_Frame             == other.string_Frame &&
                string_Messachse         == other.string_Messachse &&
                string_W                 == other.string_W &&
                string_DFA               == other.string_DFA &&
                string_TSA               == other.string_TSA &&
                string_Anfahren          == other.string_Anfahren);
    }

    bool operator!=(const Struct_Nut& other) const
    {
        return !(*this == other);
    }
};

struct Struct_Bohrung
{
    QString string_Pos;
    QString string_Frame;
    QString string_Durchmesser;
    QString string_TSA;
    QString string_Anfahren;

    bool operator==(const Struct_Bohrung& other) const
    {
        return (string_Pos               == other.string_Pos &&
                string_Frame             == other.string_Frame &&
                string_Durchmesser       == other.string_Durchmesser &&
                string_TSA               == other.string_TSA &&
                string_Anfahren          == other.string_Anfahren);
    }

    bool operator!=(const Struct_Bohrung& other) const
    {
        return !(*this == other);
    }
};
#endif // TP_STRUCT_H
