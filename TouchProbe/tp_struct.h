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

    bool operator!=(const Struct_Ausrichten& t) const
    {
        if(string_Pos              == t.string_Pos &&
           string_Frame            == t.string_Frame &&
           string_Messrichtung     == t.string_Messrichtung &&
           string_Messachse        == t.string_Messachse &&
           string_Positionierachse == t.string_Positionierachse &&
           string_L2               == t.string_L2 &&
           string_TSA              == t.string_TSA &&
           string_Anfahren         == t.string_Anfahren)
            return false;

        return true;
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

    bool operator!=(const Struct_Kante& t) const
    {
        if(string_Pos           == t.string_Pos &&
            string_Frame        == t.string_Frame &&
            string_Messrichtung == t.string_Messrichtung &&
            string_Messachse    == t.string_Messachse &&
            string_Wert         == t.string_Wert &&
            string_DFA          == t.string_DFA &&
            string_TSA          == t.string_TSA &&
            string_Anfahren     == t.string_Anfahren)
            return false;

        return true;
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

    bool operator!=(const Struct_Ebenheit& t) const
    {
        if(string_Pos               == t.string_Pos &&
           string_Frame             == t.string_Frame &&
           string_ZEbene            == t.string_ZEbene &&
           string_Vertrauensbereich == t.string_Vertrauensbereich &&
           string_Punkt1X           == t.string_Punkt1X &&
           string_Punkt1Y           == t.string_Punkt1Y &&
           string_Punkt2X           == t.string_Punkt2X &&
           string_Punkt2Y           == t.string_Punkt2Y &&
           string_Punkt3X           == t.string_Punkt3X &&
           string_Punkt3Y           == t.string_Punkt3Y &&
           string_Punkt4X           == t.string_Punkt4X &&
           string_Punkt4Y           == t.string_Punkt4Y &&
           bool_Jump1               == t.bool_Jump1 &&
           bool_Jump2               == t.bool_Jump2 &&
           bool_Jump3               == t.bool_Jump3)
            return false;

        return true;
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

    bool operator!=(const Struct_Steg& t) const
    {
        if(string_Pos           == t.string_Pos &&
            string_Frame        == t.string_Frame &&
            string_Messachse    == t.string_Messachse &&
            string_W            == t.string_W &&
            string_DZ           == t.string_DZ &&
            string_DFA          == t.string_DFA &&
            string_TSA          == t.string_TSA &&
            string_Anfahren     == t.string_Anfahren)
            return false;

        return true;
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

    bool operator!=(const Struct_Nut& t) const
    {
        if(string_Pos           == t.string_Pos &&
            string_Frame        == t.string_Frame &&
            string_Messachse    == t.string_Messachse &&
            string_W            == t.string_W &&
            string_DFA          == t.string_DFA &&
            string_TSA          == t.string_TSA &&
            string_Anfahren     == t.string_Anfahren)
            return false;

        return true;
    }
};

struct Struct_Bohrung
{
    QString string_Pos;
    QString string_Frame;
    QString string_Durchmesser;
    QString string_TSA;
    QString string_Anfahren;

    bool operator!=(const Struct_Bohrung& t) const
    {
        if(string_Pos           == t.string_Pos &&
            string_Frame        == t.string_Frame &&
            string_Durchmesser  == t.string_Durchmesser &&
            string_TSA          == t.string_TSA &&
            string_Anfahren     == t.string_Anfahren)
            return false;

        return true;
    }
};
#endif // TP_STRUCT_H
