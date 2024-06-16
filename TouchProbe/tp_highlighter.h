#ifndef TP_HIGHLIGHTER_H
#define TP_HIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QTextEdit>

class TP_HighLighter : public QSyntaxHighlighter
{
    Q_OBJECT
private:
    QStringList stringList_LineNumbers;
    QTextEdit* textEdit;
    int int_Pos;
    QString string_Line;
    QStringList stringList;
    QStringList stringList_Axes;
    QStringList stringList_Loops;
    QStringList stringList_MFunction;
    QStringList stringList_F;
    QStringList stringList_ToolCall;
    QStringList stringList_G1;
    QStringList stringList_G0;
    QStringList stringList_Variables;

    QColor color_Axes;
    QColor color_Call;
    QColor color_F;
    QColor color_G0;
    QColor color_Loop;
    QColor color_Programm;
    QColor color_MFunction;
    QColor color_T;
    QColor color_Var;

    QTextCharFormat myClassFormat;

    void        scann_AxesFormel(QString);
    QStringList scann_G0(QString str);
    QStringList scann_G1(QString str);
    QStringList scann_Int(QString, QString);
    QStringList scann_Real(QString, QString);
    QStringList scann_ToolCall(QString);
    void        scann_Variables(QString);

    void set_Color(QStringList, QColor);
    void set_Italic(QStringList, QColor);
    void set_KeyWordColor();
    void set_KeyWordItalic();

public:
    TP_HighLighter(QTextDocument *parent);

    void highlightBlock(const QString &text);
    void set_TextEdit(QTextEdit* te) {textEdit = te;}

public slots:
    void slot_HighLightLineNumer(QStringList);

signals:
    //void sig_NewTextCursor(QTextCursor);
};

#endif // HIGHLIGHTER_H
