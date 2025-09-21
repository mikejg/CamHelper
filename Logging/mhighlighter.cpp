#include "mhighlighter.h"

MHighLighter::MHighLighter(QTextDocument *parent)
    : QSyntaxHighlighter{parent}
{
    HighlightingRule rule;
    text_Color.setNamedColor("#BDAD7F");

    format_DiffInsert.setForeground(QColor(	187, 255, 180));
    rule.pattern = QRegularExpression(QStringLiteral("^\\+\\+ .*$"));
    rule.format = format_DiffInsert;
    rule.capture = 0;
    highlightingRules.append(rule);

    format_DiffDelete.setForeground(QColor(255,97,144));
    rule.pattern = QRegularExpression(QStringLiteral("^-- .*$"));
    rule.format = format_DiffDelete;
    rule.capture = 0;
    highlightingRules.append(rule);

    format_NoXY.setForeground(QColor(179, 218, 255));
    rule.pattern = QRegularExpression(QStringLiteral("^.*NoXY$"));
    rule.format = format_NoXY;
    rule.capture = 0;
    highlightingRules.append(rule);

    format_NoXYFile.setForeground(QColor(Qt::darkGreen));
    rule.pattern = QRegularExpression(QStringLiteral("^(.*NoXY.*)(☑)$"));
    rule.format = format_NoXYFile;
    rule.capture = 0;
    highlightingRules.append(rule);

    format_NoXYChecked.setForeground(QColor(0,170,255));
    rule.pattern = QRegularExpression(QStringLiteral("^(.*NoXY.*)(☑)$"));
    rule.format = format_NoXYChecked;
    rule.capture = 1;
    highlightingRules.append(rule);
}

void MHighLighter::highlightBlock(const QString &text)
{
    setFormat(0,text.length(),text_Color);

    QRegularExpressionMatchIterator matchIterator;
    QRegularExpressionMatch match;
    //HighlightingRule rule;



    foreach(HighlightingRule rule, highlightingRules)
    {

        matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext())
        {
            match = matchIterator.next();
            if(rule.capture == 0)
                setFormat(match.capturedStart(), match.capturedLength(), rule.format);
            else
                setFormat(match.capturedStart(), match.capturedLength(rule.capture), rule.format);

        }
    }

    if(text.startsWith("☑ "))
        setFormat(0,text.length(), Qt::darkGreen);

    if(text.startsWith("☒ "))
        setFormat(0,text.length(), Qt::darkRed);

    if(text.endsWith(".spf"))
        setFormat(0,text.length(), QColor(0,170,255));
}
