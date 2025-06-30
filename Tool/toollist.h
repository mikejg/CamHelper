#ifndef TOOLLIST_H
#define TOOLLIST_H

#include <QObject>
#include <QList>
#include "tool.h"

class ToolList : public QObject
{
    Q_OBJECT

private:
    QList<Tool*> list;

public:
    explicit ToolList(QObject *parent = nullptr);

    void         clear() {list.clear();}                //Lösche alle Werkzeuge aus der Liste
    bool         contains(Tool*);                       //Ist das Werkzeug schon in der Liste?
    void         delete_Tool(int);                      //Löscht das Werkerzeug aus der Liste
    QList<Tool*> get_List() {return list;}              //Gibt die interne Liste zurück
    int          get_Size() {return list.size();}       //Gibt die Anzahl der Werkzeuge zurück
    void         insert_Tool(Tool*, bool check=true);   //Fügt ein Werkzeug in die Liste ein
    void         prepend(Tool*);                        //Fügt ein Werkzeug am Anfang der Liste ein
    void         set_Description(ToolList* tl);
    void         sort_Counter();                        //Sortiere die Liste nach dem Counter (Wie oft wurde das Werkzeug verwendet)
    void         sort_Number();                         //Sortiere die Liste nach der Werkzeugnummer

    //friend bool operator == (const ToolList&, const ToolList&);
    //friend bool operator != (const ToolList&, const ToolList&);
};

#endif // TOOLLIST_H
