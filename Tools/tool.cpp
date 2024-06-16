#include "tool.h"

Tool::Tool(QObject *parent)
    : QObject{parent}
{
    counter = 0;
    number          = " ";
    description     = " ";
    gage_Length   = " ";
    tool_Length     = " ";
    tip_Length      = " ";
    //halterComment   = " ";
    //holder_Name      = " ";
    cut_Length      = " ";
    state           = Out;
}

void Tool::clear()
{
    number = " ";
    description   = " ";
    gage_Length = " ";
    tool_Length   = " ";
    tip_Length    = " ";
    //halterComment = " ";
    //holder_Name    = " ";
    cut_Length    = " ";
    counter = 0;
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
