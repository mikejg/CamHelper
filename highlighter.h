#ifndef HIGHLIGHTER_H
#define HIGHLIGHTER_H

#include <QSyntaxHighlighter>

class HighLighter : public QSyntaxHighlighter
{
    Q_OBJECT
private:
    int int_Pos;
    QColor color_Call;
    QColor color_Programm;
    QColor color_MFunction;
    QColor color_N;

    QStringList stringList_MFunction;
    QStringList stringList_N;

    QStringList scann_MFunction(QString);
    QStringList scann_N(QString);

public:
    HighLighter(QTextDocument *parent);

    void highlightBlock(const QString &text);
};

#endif // HIGHLIGHTER_H
