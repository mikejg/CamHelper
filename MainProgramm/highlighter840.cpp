#include "highlighter840.h"

//Highlighter840::Highlighter840(QObject *parent)
//    : QSyntaxHighlighter{parent}
//{}

Highlighter840::Highlighter840(QTextDocument *parent) : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;
    text_Color.setNamedColor("#BDAD7F");
    number_Color.setNamedColor("#748DA6");
    keyword_Color.setNamedColor("#62A8D1");
    axis_Color.setNamedColor("#AEE2FF");
    label_Color.setNamedColor("#92DCD8");

    m_Format.setForeground(QColor(0, 170, 255));
    rule.pattern = QRegularExpression(QStringLiteral("\\b[Mm]\\d*\\b"));
    rule.format = m_Format;
    rule.capture = 0;
    highlightingRules.append(rule);

    g00_Format.setForeground(QColor(255,97,144));
    rule.pattern = QRegularExpression(QStringLiteral("\\b[Gg]0*\\b"));
    rule.format = g00_Format;
    rule.capture = 0;
    highlightingRules.append(rule);

    programmName_Format.setForeground(QColor(160,120,120));
    rule.pattern = QRegularExpression(QStringLiteral("(?:call\\s+)\"([^\"]*)\""));
    rule.format = programmName_Format;
    rule.capture = 0;
    highlightingRules.append(rule);

    label_Format.setForeground(label_Color);
    rule.pattern = QRegularExpression(QStringLiteral("(?:GOTOF\\s+)([^\"]*)"));
    rule.format = label_Format;
    rule.capture = 0;
    highlightingRules.append(rule);

    rule.pattern = QRegularExpression(QStringLiteral("(\\w+):$"));
    rule.format = label_Format;
    rule.capture = 0;
    highlightingRules.append(rule);

    r_Format.setForeground(QColor(185, 107, 29));
    rule.pattern = QRegularExpression(QStringLiteral("\\bR(\\d+)\\b"));
    rule.format = r_Format;
    rule.capture = 0;
    highlightingRules.append(rule);

    //realNumbers_Format.setForeground(QColor(120, 120, 160));
    realNumbers_Format.setForeground(number_Color);
    rule.pattern = QRegularExpression(QStringLiteral("[-+]?\\b\\d*\\.?\\d+\\b"));
    rule.format = realNumbers_Format;
    rule.capture = 0;
    highlightingRules.append(rule);

    rule.pattern = QRegularExpression(QStringLiteral("[AaBbCcXxYyZz]([-+]?\\d*\\.?\\d+)"));
    rule.format = realNumbers_Format;
    rule.capture = 0;
    highlightingRules.append(rule);

    axis_Format.setForeground(axis_Color);
    rule.pattern = QRegularExpression(QStringLiteral("([AaBbCcXxYyZz])([+-.\\d])"));
    rule.format = axis_Format;
    rule.capture = 1;
    highlightingRules.append(rule);

    string_Format.setForeground(Qt::darkYellow);
    rule.pattern = QRegularExpression(QStringLiteral("\"([^\"]*)\""));
    rule.format = string_Format;
    rule.capture = 0;
    highlightingRules.append(rule);

    n_Format.setForeground(Qt::gray);
    rule.pattern = QRegularExpression(QStringLiteral("^[Nn]\\d+"));
    rule.format = n_Format;
    rule.capture = 0;
    highlightingRules.append(rule);

    keywordFormat.setForeground(keyword_Color);
    const QString keywordPatterns[] = { QStringLiteral("\\bcall\\b"), QStringLiteral("\\bGOTOF\\b"), QStringLiteral("\\bIF\\b"),
                                        QStringLiteral("\\bSTOPRE\\b"), QStringLiteral("\\bWRITE\\b")};
    for (const QString &pattern : keywordPatterns)
    {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        rule.capture = 0;
        highlightingRules.append(rule);
    }


    QString text = "N74 WRITE(LOG_ERROR,\"_N_LogFile\",\";--- \" << LOG_DATUM << \" - \" << LOG_ZEIT << \" ---\")";

    QRegularExpression re(QStringLiteral("\"[^;]*;[^\"]*\""));
    QRegularExpressionMatch match = re.match(text);

    if (match.hasMatch()) {
        qDebug() << "Gefundene Zeichenkette mit Semikolon:" << match.captured(0);
    } else {
        qDebug() << "Kein Match gefunden.";
    }
}

Highlighter840::~Highlighter840()
{

}

void Highlighter840::highlightBlock(const QString &text)
{
    setFormat(0,text.length(),text_Color);

    QRegularExpressionMatchIterator matchIterator;
    QRegularExpressionMatch match;
    HighlightingRule rule;



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

    QRegularExpression re(QStringLiteral("^[^;]*\"[^\"]*;[^\"]*\""));
    match = re.match(text);
    if (match.hasMatch())
        qDebug() << "Gefundene Zeichenkette mit Semikolon:" << match.captured(0);

    if(!match.hasMatch())
    {
        quotationFormat.setForeground(Qt::darkGray);
        rule.pattern = QRegularExpression(QStringLiteral(";.*"));
        rule.format = quotationFormat;

        matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext())
        {
            match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }
}
