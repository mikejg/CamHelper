#ifndef TOOLSHEET_H
#define TOOLSHEET_H

#include <QWidget>
#include <QPrintPreviewDialog>
#include <QPainter>
#include <QPrinter>

#include "toolsheet_model.h"
#include "tableprinter.h"
#include "../Classes/database.h"
#include "../Magazin/magazin.h"
#include "../Tool/tool.h"
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

    void set_Magazin(Magazin* m) {magazin = m;}
    void set_MagazinCapacity(int mc) {int_MagazineCapacity = mc;}
    void set_DataBase(DataBase* db);

    void showTable(ProjectData*, bool bool_Print=false);

    void printTable();
private:
    Ui::ToolSheet *ui;

    DataBase* dataBase;
    Magazin* magazin;
    ToolSheet_Model* toolSheet_Model;
    ProjectData* projectData;

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
    int int_MagazineCapacity;               //Anzahl der Magazinplätze
    bool bool_PrintIn;
    bool bool_PrintOut;
    bool bool_PrintProject;

public slots:
    void slot_PrintPage(QPrinter*);

signals:
    void sig_DialogPrintFinished(int);
};

#endif // TOOLSHEET_H
