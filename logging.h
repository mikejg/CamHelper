#ifndef LOGGING_H
#define LOGGING_H

#include <QTextEdit>

#include "highlighter.h"

class Logging : public QTextEdit
{
    Q_OBJECT

private:
    bool bool_Error = false;
    QStringList stringList_Text;
    HighLighter* highLighter;

public:
    explicit Logging(QWidget *parent = nullptr);
    ~Logging();

    void error(QString);

    void frame(QStringList, QString);
    void frame_Error(QStringList);
    void frame_Message(QStringList);
    void frame_Successful(QStringList strList);
    void frame_Warning(QStringList);

    void message(QString);

    void successful(QString);

    void warning(QString);

signals:
    void sig_ShowLog();
};

#endif // LOGGING_H
