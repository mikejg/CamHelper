#ifndef PROJECT_EXPORT_H
#define PROJECT_EXPORT_H

#include <QObject>
#include <QStringList>
#include <QWidget>
#include <QTextEdit>

#include "../Dialoge/dialog_progress.h"
#include "../Classes/struct.h"
#include "../Classes/database.h"

class Project_Export : public QObject
{
    Q_OBJECT
private:
    Dialog_Progress* dialog_Progress;
    QStringList stringList_ContentMainProgramm;
    ProjectData* projectData;
    DataBase* dataBase;

public:
    explicit Project_Export(QObject *parent = nullptr);
    void set_ContentMainProgramm(QTextEdit*);
    void set_DataBase(DataBase* db) {dataBase = db;}    //Übernehme die Datenbank in den Zeiger dataBase
    void exportProject(ProjectData*);
signals:
};

#endif // PROJECT_EXPORT_H
