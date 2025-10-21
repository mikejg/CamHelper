#include "tool.h"

Tool::Tool(QObject *parent)
    : QObject{parent}
{
    toolData.counter        = 0;
    toolData.number         = " ";
    toolData.description    = " ";
    toolData.gage_Length    = " ";
    toolData.tool_Length    = " ";
    toolData.tip_Length     = " ";
    toolData.cut_Length     = " ";
    state                   = Out;
    toolData.toolLife       = false;
    toolData.parts          = 0;
}

void Tool::clear()
{
    toolData.number         = " ";
    toolData.description    = " ";
    toolData.gage_Length    = " ";
    toolData.tool_Length    = " ";
    toolData.tip_Length     = " ";
    toolData.cut_Length     = " ";
    toolData.counter        = 0;
}

QString Tool::get_StateString()
{
    QString string_Return = "";
    if(state == Tool::In)
        string_Return = "In";
    if(state == Tool::Out)
        string_Return = "Out";
    if(state == Tool::Disassembled)
        string_Return = "Disassembled";

    return string_Return;
}

bool operator == (const Tool &t1, const Tool &t2)
{
    return (t1.toolData == t2.toolData);
}

bool operator != (const Tool &t1, const Tool &t2)
{
    return !(t1 == t2);
}
