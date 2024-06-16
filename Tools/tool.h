#ifndef TOOL_H
#define TOOL_H

#include <QObject>
#include <QDebug>

class Tool : public QObject
{
    Q_OBJECT

private:


    QString number;
    QString description;
    QString gage_Length;
    QString tool_Length;
    QString tip_Length;
    //QString holder_Name;
    //QString halterComment;
    QString cut_Length;
    int counter;

public:
    enum State {In, Out, Disassembled};
    State   state;
    explicit Tool(QObject *parent = nullptr);

    void     set_Number (QString n)         {number = n;}
    QString  get_Number()                   {return number;}

    void     set_Description (QString d)    {description = d;}
    QString  get_Description()              {return description;}

    void     set_Counter(int c)             {counter = c;}
    int      get_Counter()                  {return counter;}
    void     inc_Counter()                  {counter++;}

    void    set_GageLength(QString tgl)     {gage_Length = tgl;}
    QString get_GageLength()                {return gage_Length;}

    void    set_ToolLength(QString agl)     {tool_Length = agl;}
    QString get_ToolLength()                {return tool_Length;}

    void    set_TipLength(QString tfl)      {tip_Length = tfl;}
    QString get_TipLength()                 {return tip_Length;}

    //void     set_HolderName (QString n)     {holder_Name = n;}
    //QString  get_HolderName()               {return holder_Name;}

    //void     set_HalterComment (QString n)  {halterComment = n;}
    //QString  get_HalterComment()            {return halterComment;}

    void  set_State(State s)                {state = s;}
    State get_State()                       {return state;}

    QString get_StateString();

    void    set_CutLength(QString s)    {cut_Length = s;}
    QString get_CutLength()             {return cut_Length;}
    void clear();
};

#endif // TOOL_H
