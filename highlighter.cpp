#include "highlighter.h"

HighLighter::HighLighter(QTextDocument *parent) : QSyntaxHighlighter(parent)
{
    color_Call = Qt::cyan;
    color_Programm = QColor("#D69542");
    color_MFunction = QColor("#FF8080");
    color_N = QColor("#778899");
}

void HighLighter::highlightBlock(const QString &text)
{
    stringList_MFunction.clear();
    stringList_MFunction = scann_MFunction(text);

    stringList_N.clear();
    stringList_N = scann_N(text);

    setFormat(0,text.length(),QColor("#D6CF9A"));

    int index;
    QString string_MFunction;

    if(text.contains("TOFFL"))
    {
        index = text.indexOf("TOFFL");
        setFormat(index,text.length(),Qt::darkYellow);
    }

    if(text.contains("call"))
    {
        index = text.indexOf("call");
        setFormat(index,4,color_Call);
        setFormat(index+4, text.length(),color_Programm);
    }

    if(text.contains(";"))
    {
        int_Pos = text.indexOf(";");
        setFormat(int_Pos,text.length(),Qt::darkGray);
    }

    foreach(QString string_MFunction, stringList_MFunction)
    {
        int_Pos = text.indexOf(string_MFunction);
        setFormat(int_Pos,string_MFunction.length(),color_MFunction);
    }

    foreach(QString string_N, stringList_N)
    {
        int_Pos = text.indexOf(string_N);
        setFormat(int_Pos,string_N.length(),color_N);
    }

    if(text.startsWith("Ⓦ "))
    {
        setFormat(0,text.length(), Qt::darkYellow);
    }

    if(text.startsWith("Ⓢ "))
    {
        setFormat(0,text.length(), Qt::darkGreen);
    }

    if(text.startsWith("Ⓔ "))
    {
        setFormat(0,text.length(), Qt::red);
    }
}

QStringList HighLighter::scann_MFunction(QString str)
{
    QStringList stringList_Return;
    QStringList stringList_Words = str.split(" ");
    bool boolOK;
    bool bool_isNumber;
    foreach(QString string, stringList_Words)
    {
        if(string.startsWith("M"))
        {
            //bool_isNumber = true;
            for(int pos = 1; pos < string.length(); pos++)
            {
                string.sliced(pos,1).toInt(&boolOK);
                if(!boolOK)
                {
                    //bool_isNumber = false;
                    //qDebug() << string;
                    break;
                }
            }
            if(boolOK)
                stringList_Return.append(string);
        }

    }
    return stringList_Return;
}

QStringList HighLighter::scann_N(QString str)
{
    QStringList stringList_Return;
    QStringList stringList_Words = str.split(" ");
    bool boolOK;
    bool bool_isNumber;
    foreach(QString string, stringList_Words)
    {
        if(string.startsWith("N"))
        {
            //bool_isNumber = true;
            for(int pos = 1; pos < string.length(); pos++)
            {
                string.sliced(pos,1).toInt(&boolOK);
                if(!boolOK)
                {
                    //bool_isNumber = false;
                    //qDebug() << string;
                    break;
                }
            }
            if(boolOK)
                stringList_Return.append(string);
        }

    }
    return stringList_Return;
}
