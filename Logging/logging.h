#ifndef LOGGING_H
#define LOGGING_H

#include <QTextEdit>
#include "mhighlighter.h"

class Logging : public QTextEdit
{
    Q_OBJECT

private:
    MHighLighter* highLighter;

public:
    explicit Logging(QWidget *parent = nullptr);
    ~Logging();

    void successful(QString);
    void vailed(QString);
    void warning(QString);
    void log(QString s) {append(s);}
};

#endif // LOGGING_H
