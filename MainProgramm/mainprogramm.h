#ifndef MAINPROGRAMM_H
#define MAINPROGRAMM_H

#include <QObject>
#include <QTextEdit>

class MainProgramm : public QTextEdit
{
    Q_OBJECT
public:
    explicit MainProgramm(QWidget *parent = nullptr);

};

#endif // MAINPROGRAMM_H
