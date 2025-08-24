#include "tp_highlighter.h"

TP_HighLighter::TP_HighLighter(QTextDocument *parent) : QSyntaxHighlighter(parent)
{
    color_Axes = QColor(255,128,255);
    color_Call = Qt::cyan;
    color_Programm = QColor(214, 207, 154);
    color_Loop = QColor(128,128,255);
    color_MFunction = QColor(0, 170, 255);
    color_F = QColor(0, 255, 180);
    color_G0 = QColor(255,97,144);
    color_T = QColor(255,255,128);
    color_Var = QColor(192,128,115);

    stringList_Loops << "IF" << "ENDIF";
    stringList_Loops << "FOR" << "ENDFOR";
    stringList_Loops << "WHILE" << "ENDWHILE";
    stringList_Loops << "GOTOB" << "GOTOF";

    stringList_Variables << "Z_EBENE";
}

void TP_HighLighter::highlightBlock(const QString &text)
{

    //myClassFormat.setFontItalic(true);
    myClassFormat.setFontWeight(true);

    stringList = text.split(" ");
    string_Line = text;

    stringList_Axes.clear();
    stringList_F.clear();
    stringList_G0.clear();
    stringList_G1.clear();
    stringList_MFunction.clear();
    stringList_ToolCall.clear();
    //stringList_Var.clear();


    stringList_Axes = scann_Real(text, "A");
    stringList_Axes = stringList_Axes + scann_Real(text, "C");
    stringList_Axes = stringList_Axes + scann_Real(text, "X");
    stringList_Axes = stringList_Axes + scann_Real(text, "Y");
    stringList_Axes = stringList_Axes + scann_Real(text, "Z");
    scann_AxesFormel("Z=(");

    stringList_F = scann_Int(text, "F");
    stringList_G0 = scann_G0(text);
    stringList_G1 = scann_G1(text);
    stringList_MFunction = scann_Int(text, "M");
    stringList_Variables += scann_Int(text, "R");
    scann_Variables(text);
    stringList_ToolCall = scann_ToolCall(text);

    setFormat(0,text.length(),color_Programm); //"#D6CF9A"));

    set_Color(stringList_F, color_F);
    set_Color(stringList_G0, color_G0);
    set_Color(stringList_G1, color_F);
    set_Color(stringList_MFunction, color_MFunction);
    set_Color(stringList_ToolCall, color_T);
    set_Color(stringList_Axes, color_Axes);
    set_KeyWordColor();


    if(text.contains(";"))
    {
        int_Pos = text.indexOf(";");
        setFormat(int_Pos,text.length(),Qt::darkGray);
    }

    foreach(QString string_LineNumber, stringList_LineNumbers)
    {
        myClassFormat.setForeground(Qt::darkYellow);
        if(text.contains(string_LineNumber))
        {
            setFormat(0,text.length(),myClassFormat);
            set_Italic(stringList_F, color_F);
            set_Italic(stringList_G0, color_G0);
            set_Italic(stringList_G1, color_F);
            set_Italic(stringList_MFunction, color_MFunction);
            set_Italic(stringList_ToolCall, color_T);
            set_Italic(stringList_Axes, color_Axes);
            set_KeyWordItalic();
        }


    }
}

void TP_HighLighter::set_Color(QStringList stringList, QColor color)
{
    foreach(QString string, stringList)
    {
        int_Pos = string_Line.indexOf(string);
        setFormat(int_Pos,string.length(),color);
    }
}

void TP_HighLighter::set_Italic(QStringList stringList, QColor color)
{
    int r , g , b;
    color.getRgb(&r, &g , &b);
    r = (int)(r * 0.66);
    g = (int)(g * 0.66);
    b = (int)(b * 0.66);
    QColor c(r, g, b);
    myClassFormat.setForeground(c);
    foreach(QString string, stringList)
    {
        int_Pos = string_Line.indexOf(string);
        setFormat(int_Pos,string.length(),myClassFormat);
    }
}

void TP_HighLighter::set_KeyWordColor()
{
    foreach(QString string_Word, stringList)
    {
        foreach(QString string_Var, stringList_Variables)
        {
           if(string_Word.contains(string_Var))
           {
               int_Pos = string_Line.indexOf(string_Var);
               setFormat(int_Pos,string_Var.length(),color_Var);
           }
        }

        foreach(QString string_Loop, stringList_Loops)
        {
           if(string_Word.contains(string_Loop))
           {
               int_Pos = string_Line.indexOf(string_Loop);
               setFormat(int_Pos,string_Loop.length(),color_Loop);
           }
        }

    }
}

void TP_HighLighter::set_KeyWordItalic()
{
    int r , g , b;
    QColor color_Italic;
    color_Var.getRgb(&r, &g , &b);
    r = (int)(r * 0.66);
    g = (int)(g * 0.66);
    b = (int)(b * 0.66);
    color_Italic = QColor(r, g, b);
    myClassFormat.setForeground(color_Italic);

    foreach(QString string_Word, stringList)
    {
        foreach(QString string_Var, stringList_Variables)
        {
           if(string_Word.contains(string_Var))
           {
               int_Pos = string_Line.indexOf(string_Var);
               setFormat(int_Pos,string_Var.length(),myClassFormat);
           }
        }
    }

    color_Loop.getRgb(&r, &g, &b);
    r = (int)(r * 0.66);
    g = (int)(g * 0.66);
    b = (int)(b * 0.66);
    color_Italic = QColor(r, g, b);
    myClassFormat.setForeground(color_Italic);

    foreach(QString string_Word, stringList)
    {
        foreach(QString string_Loop, stringList_Loops)
        {
           if(string_Word.contains(string_Loop))
           {
               int_Pos = string_Line.indexOf(string_Loop);
               setFormat(int_Pos,string_Loop.length(),myClassFormat);
           }
        }
    }
}
void TP_HighLighter::slot_HighLightLineNumer(QStringList stringList)
{
    //qDebug() << Q_FUNC_INFO;
    stringList_LineNumbers = stringList;

    rehighlight();

    // Wenn stringList_LineNumer leer ist, beende hier die Funktion
    if(stringList_LineNumbers.isEmpty())
        return;

    //Scroll zu dem Prg-Code des Items
    QString string_LineNumber = stringList_LineNumbers.first();
    string_LineNumber = string_LineNumber.remove("N");
    int int_LineNumber = string_LineNumber.toInt();
    QTextCursor textCursor(document()->findBlockByLineNumber(int_LineNumber - 6));
    textEdit->setTextCursor(textCursor);
}

QStringList TP_HighLighter::scann_Int(QString str, QString string_Letter)
{
    QStringList stringList_Return;
    QStringList stringList_Words = str.split(" ");
    bool boolOK;
    //bool bool_isNumber;
    foreach(QString string, stringList_Words)
    {
        if(string.startsWith(string_Letter))
        {
            for(int pos = 1; pos < string.length(); pos++)
            {
                string.sliced(pos,1).toInt(&boolOK);
                if(!boolOK)
                {
                    break;
                }
            }
            if(boolOK)
                stringList_Return.append(string);
        }

    }
    return stringList_Return;
}

QStringList TP_HighLighter::scann_Real(QString str, QString string_Letter)
{
    QStringList stringList_Return;
    QStringList stringList_Words = str.split(" ");
    bool boolOK;
    QString string_Real;

    foreach(QString string, stringList_Words)
    {
        if(string.startsWith(string_Letter))
        {
            string_Real = string.right(string.length()-1);
            string_Real.toDouble(&boolOK);
            if(boolOK)
                stringList_Return.append(string);
        }

    }
    return stringList_Return;
}

QStringList TP_HighLighter::scann_ToolCall(QString str)
{
    QStringList stringList_Return;
    QStringList stringList_Words = str.split(" ");
    foreach(QString string, stringList_Words)
    {
        if(string.startsWith("T=\"") && string.endsWith("\""))
        {
            stringList_Return.append(string);
        }
    }
    return stringList_Return;
}

QStringList TP_HighLighter::scann_G1(QString str)
{
    QStringList stringList_Return;
    QStringList stringList_Words = str.split(" ");
    foreach(QString string, stringList_Words)
    {
        if(string == "G1" || string == "G01" ||
           string == "g1" || string == "g01")
        {
            stringList_Return.append(string);
        }

    }
    return stringList_Return;
}

QStringList TP_HighLighter::scann_G0(QString str)
{
    QStringList stringList_Return;
    QStringList stringList_Words = str.split(" ");
    foreach(QString string, stringList_Words)
    {
        if(string == "G0" || string == "G00" ||
            string == "g0" || string == "g00")
        {
            stringList_Return.append(string);
        }

    }
    return stringList_Return;
}

void TP_HighLighter::scann_Variables(QString str)
{
    QStringList stringList_Words = str.split(" ");
    int int_Index;

    if(stringList_Words.contains("DEF"))
    {
        int_Index = stringList_Words.indexOf("DEF");
        if(int_Index +2 < stringList_Words.length())
        {
            if(stringList_Words.at(int_Index +1) == "REAL")
            {
                if(!stringList_Variables.contains(stringList_Words.at(int_Index+2)))
                    stringList_Variables.append(stringList_Words.at(int_Index+2));
            }
        }
    }
}

void TP_HighLighter::scann_AxesFormel(QString string_Formel)
{
    foreach (QString string , stringList)
    {
        if(string.startsWith(string_Formel) && string.endsWith(")"))
            stringList_Axes.append(string);
    }
}
