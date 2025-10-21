#ifndef TOOL_H
#define TOOL_H

#include <QObject>
#include "tool_Struct.h"

class Tool : public QObject
{
    Q_OBJECT

private:
    ToolData toolData;

public:
    enum State {In, Out, Disassembled};
    State   state;

    explicit Tool(QObject *parent = nullptr);

    void     set_Number (QString n)         {toolData.number = n;}
    QString  get_Number()                   {return toolData.number;}

    void     set_Description (QString d)    {toolData.description = d;}
    QString  get_Description()              {return toolData.description;}

    void     set_Counter(int c)             {toolData.counter = c;}
    int      get_Counter()                  {return toolData.counter;}
    void     inc_Counter()                  {toolData.counter++;}

    void    set_GageLength(QString tgl)     {toolData.gage_Length = tgl;}
    QString get_GageLength()                {return toolData.gage_Length;}

    void    set_ToolLength(QString agl)     {toolData.tool_Length = agl;}
    QString get_ToolLength()                {return toolData.tool_Length;}

    void    set_ToolLife(bool tl)           {toolData.toolLife = tl;}
    bool    get_ToolLife()                  {return toolData.toolLife;}

    void    set_TipLength(QString tfl)      {toolData.tip_Length = tfl;}
    QString get_TipLength()                 {return toolData.tip_Length;}

    void    set_Parts(int p)                {toolData.parts = p;}
    int     get_Parts()                     {return toolData.parts;}

    void  set_State(State s)                {state = s;}
    State get_State()                       {return state;}

    QString get_StateString();

    void    set_CutLength(QString s)    {toolData.cut_Length = s;}
    QString get_CutLength()             {return toolData.cut_Length;}

    void clear();

    friend bool operator == (const Tool &t1, const Tool &t2);
    friend bool operator != (const Tool &t1, const Tool &t2);
};

#endif // TOOL_H
