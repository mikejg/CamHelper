#ifndef HIGHLIGHTER840_H
#define HIGHLIGHTER840_H

#include <QSyntaxHighlighter>
#include <QRegularExpression>

class Highlighter840 : public QSyntaxHighlighter
{
    Q_OBJECT
private:
    struct HighlightingRule
    {
        QRegularExpression pattern;
        QTextCharFormat format;
        int capture = 0;
    };
    QList<HighlightingRule> highlightingRules;

    QTextCharFormat keywordFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat m_Format;
    QTextCharFormat g00_Format;
    QTextCharFormat programmName_Format;
    QTextCharFormat r_Format;
    QTextCharFormat label_Format;
    QTextCharFormat axis_Format;
    QTextCharFormat realNumbers_Format;
    QTextCharFormat string_Format;
    QTextCharFormat n_Format;

    QColor text_Color;
    QColor number_Color;
    QColor keyword_Color;
    QColor axis_Color;
    QColor label_Color;
    QColor n_Color;
public:
    //explicit Highlighter840(QObject *parent = nullptr);
    Highlighter840(QTextDocument *parent);
    ~Highlighter840();
    void highlightBlock(const QString &text);
};

#endif // HIGHLIGHTER840_H
