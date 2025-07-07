#ifndef TOOLSHEET_H
#define TOOLSHEET_H

#include <QWidget>

#include "../Tool/toollist.h"
#include "../Classes/struct.h"

namespace Ui {
class ToolSheet;
}

class ToolSheet : public QWidget
{
    Q_OBJECT

public:
    explicit ToolSheet(QWidget *parent = nullptr);
    ~ToolSheet();

void showTable(ProjectData, bool bool_Print=false);

private:
    Ui::ToolSheet *ui;

    ToolList* toolList_IN;                  //Liste der Werkzeuge die eingelagert werden müssen
    ToolList* toolList_OUT;                 //Liste der Werkzeuge die ausgelagert werden müssen
    ToolList* toolList_Project;             //Liste der Werkzeuge die für das Projekt benötigt werden
    ToolList* toolList_Top100;              //Liste der 100 meist benutzten Werkzeuge

    //Listen für den Header
    QList<QString> list_Counter;            //Zähler wie oft wurde das Werkzeug verwendet
    QList<QString> list_ToolNumber;         //Werkezgnummer
    QList<QString> list_ToolDescription;    //Werkzeug Beschreibung
    QList<QString> list_GageLength;         //Gesamtlänge
    QList<QString> list_ToolLength;         //Ausspannlänge
    QList<QString> list_TipLength;          //Schneidlänge

    int int_Projects_Size;                  //Anzahl der Werkzeuge des Projects
    int int_In_Size;                        //Anzahl der Werkzeuge die eingelagert werden müssen
    int int_Out_Size;                       //Anzahl der Werkzeuge die ausgelagert werden müssen
    int int_Free_Size;                      //Anzahl der freien Werkzeugplätze im Magazin
    int int_Counter;                        //Ein Zähler


};

#endif // TOOLSHEET_H
