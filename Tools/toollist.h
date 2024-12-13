#ifndef TOOLLIST_H
#define TOOLLIST_H

#include "tool.h"
#include <QObject>
#include <QList>

class ToolList : public QObject
{
    Q_OBJECT

private:
    QList<Tool*> list;

public:
    explicit ToolList(QObject *parent = nullptr);

    void         clear() {list.clear();}
    bool         contains(Tool*);
    void         delete_Tool(int);
    QList<Tool*> get_List() {return list;}
    int          get_Size() {return list.size();}
    void         insert_Tool(Tool*, bool check=true);
    void         prepend(Tool*);
    void         set_Description(ToolList* tl);
    void         sort_Counter();
    //void       sort_Top100();
    void         sort_ID();
};

#endif // TOOLLIST_H
