#include "toollist.h"

ToolList::ToolList(QObject *parent)
    : QObject{parent}
{

}

bool ToolList::contains(Tool* t)
{
    foreach(Tool* tool, list)
    {
        if(tool->get_Number() == t->get_Number())
        {
            return true;
        }
    }
    return false;
}

void ToolList::delete_Tool(int int_Row)
{
    list.removeAt(int_Row);
}

void ToolList::insert_Tool(Tool* tool, bool check)
{
    bool match = false;
    int i = 0;
    Tool* t;

    /* Wenn eine Überprüfung stattfinden soll
     * Überprüfe in der Liste ob es das Tool schon gibt*/
    if(check)
    {
        while(i<list.size() && !match)
        {
            if(list.at(i)->get_Number() == tool->get_Number())
            {
                match = true;
            }
            i++;
        }
    }

    if(!match)
    {
       t = new Tool(this);
       t->set_Number(tool->get_Number());
       t->set_Description(tool->get_Description());
       t->set_GageLength(tool->get_GageLength());
       t->set_ToolLength(tool->get_ToolLength());
       t->set_TipLength(tool->get_TipLength());
       t->set_Counter(tool->get_Counter());
       t->set_State(tool->get_State());
       t->set_CutLength(tool->get_CutLength());
       t->set_ToolLife(tool->get_ToolLife());
       t->set_Parts(tool->get_Parts());
       list.append(t);
    }

    return;
}

void ToolList::prepend(Tool* tool)
{
    Tool* t = new Tool(this);
    t->set_Number(tool->get_Number());
    t->set_Description(tool->get_Description());
    t->set_GageLength(tool->get_GageLength());
    t->set_ToolLength(tool->get_ToolLength());
    t->set_TipLength(tool->get_TipLength());
    list.prepend(t);
}

void ToolList::set_Description(ToolList* tl)
{
    QList<Tool*> list_Source = tl->get_List();
    for(int i = 0; i < list.size(); i++)
    {
       for(int j = 0; j< list_Source.size(); j++)
       {
            if(list.at(i)->get_Number() == list_Source.at(j)->get_Number())
                list.at(i)->set_Description(list_Source.at(j)->get_Description());
       }
    }
}

void ToolList::sort_Number()
{
    for (int i = 0; i<list.size(); i++)
    {

        for(int j = 0; j<i; j++)
        {
            if(list.at(i)->get_Number() < list.at(j)->get_Number())
            {
                list.move(i,j);
                break;
            }
        }
    }
}

void ToolList::sort_Counter()
{
    for (int i = 0; i<list.size(); i++)
    {

        for(int j = 0; j<i; j++)
        {
            if(list.at(i)->get_Counter() < list.at(j)->get_Counter())
            {
                list.move(i,j);
                break;
            }
        }
    }
}
bool operator == (const ToolList& tl1, const ToolList& tl2)
{
    for(int i = 0; i < tl1.list.size(); i++)
    {
        if(*tl1.list.at(i) != *tl2.list.at(i))
        {
            return false;
        }
    }
    return true;
}

bool operator != (const ToolList& tl1, const ToolList& tl2)
{
    return !(tl1 == tl2);
}

