#ifndef MHIGHLIGHTER_H
#define MHIGHLIGHTER_H

#include <QSyntaxHighlighter>

class MHighLighter : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    MHighLighter(QTextDocument *parent);
    //explicit MHighLighter(QObject *parent = nullptr);

    void highlightBlock(const QString &text);
signals:
};

#endif // MHIGHLIGHTER_H
