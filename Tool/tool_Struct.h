#ifndef TOOL_STRUCT_H
#define TOOL_STRUCT_H

struct ToolData
{
    QString number;                 //Werkzeugnummer 60_120_00
    QString description;            //Beschreibung
    QString gage_Length;            //Gesammtlänge
    QString tool_Length;            //Ausspannlänge
    QString tip_Length;             //Freistelllänge
    QString cut_Length;             //Schneidlänge
    int counter;                    //Zähler, wie oft wurde das Werkzeug verwendet
    bool toolLife;
    int  parts;                     //Wieviele Teile schafft das Werkezug
};

#endif // TOOL_STRUCT_H
