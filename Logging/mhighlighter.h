#ifndef MHIGHLIGHTER_H
#define MHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QRegularExpression>

class MHighLighter : public QSyntaxHighlighter
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

    QColor text_Color;
    QTextCharFormat format_DiffInsert;
    QTextCharFormat format_DiffDelete;
    QTextCharFormat format_NoXY;
    QTextCharFormat format_NoXYFile;
    QTextCharFormat format_NoXYChecked;
    QTextCharFormat format_FilePath;

public:
    MHighLighter(QTextDocument *parent);
    //explicit MHighLighter(QObject *parent = nullptr);

    void highlightBlock(const QString &text);
signals:
};

#endif // MHIGHLIGHTER_H
