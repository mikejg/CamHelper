#include "mhighlighter.h"

MHighLighter::MHighLighter(QTextDocument *parent)
    : QSyntaxHighlighter{parent}
{

}

void MHighLighter::highlightBlock(const QString &text)
{

    if(text.startsWith("☑ "))
        setFormat(0,text.length(), Qt::darkGreen);

    if(text.startsWith("☒ "))
        setFormat(0,text.length(), Qt::darkRed);
}
