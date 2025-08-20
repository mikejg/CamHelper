#ifndef MAINPROGRAMM_H
#define MAINPROGRAMM_H

#include <QObject>
#include <QTextEdit>
#include "highlighter840.h"
#include "../Logging/logging.h"
#include "../Classes/mfile.h"
#include "../Classes/struct.h"

class MainProgramm : public QTextEdit
{
    Q_OBJECT

private:
    MFile* mfile;
    Logging* log;
    ProjectData projectData;
    Highlighter840* highLighter;

    QStringList number_Programm(QStringList);
    QStringList set_PlaceHolder(QStringList);
    void write_Parts(QStringList*);
    void write_ToolLife(QStringList*);
    bool writeG54(QStringList*);
    bool writeG55(QStringList*);

public:
    explicit MainProgramm(QWidget *parent = nullptr);
    ~MainProgramm();

    void set_ProjectData(ProjectData);
    void set_Logging(Logging*); //Logging wird übergeben, und damit mfile erzeugt
};

#endif // MAINPROGRAMM_H
