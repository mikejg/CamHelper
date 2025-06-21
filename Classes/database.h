#ifndef DATABASE_H
#define DATABASE_H

#include <QDir>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include "struct.h"
#include "../Logging/logging.h"

class DataBase : public QObject
{
    Q_OBJECT

private:
    Logging* log;

    QSqlDatabase tool_DataBase;
    QSqlDatabase main_DataBase;

    QString string_ToolDB;
    QString string_MainDB;


public:
    explicit DataBase(QObject *parent = nullptr, Logging* l = nullptr);

    bool open();

    QList<ProjectData>  get_LastOpen();         //Hole mir die letzten 10 Projekt aus der Datenbank
    ProjectData         get_Project(QString);   //Hole mir ein Project mit der ProjctId aus der Datenbank

    void insertPicutres(ProjectData &);         //Schreibt die Bilder in ein Projekt
};

#endif // DATABASE_H
