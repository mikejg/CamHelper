#ifndef PARSER_PROGRAMM_H
#define PARSER_PROGRAMM_H

#include <QObject>
#include "../database.h"
#include "../logging.h"
#include "../mfile.h"
#include "../Tools/toollist.h"

class Parser_Programm : public QObject
{
    Q_OBJECT

private:
    enum Marker {kein_Marker, werkzeugliste_Anfang, werkzeugliste_Ende, Messerkopf, neuesWerkzeug,
                 Schwenkung};

    QStringList            stringList_Content;
    DataBase*              database;
    bool                   bool_EinlippenBohrer;
    bool                   bool_ersterBruch;
    Logging*               log;
    QMap<QString, QString> map_Bruch;
    Marker                 marker;
    bool                   bool_Messerkopf;
    MFile*                 mfile;
    QString                string_Line;
    QStringList            stringList_Log;

    void insert_Tool(QString, ToolList*);

public:
    explicit Parser_Programm(QObject *parent = nullptr,
                             Logging* l = nullptr,
                             DataBase* db = nullptr);

    void compare(QStringList, QStringList);
    void finish(QString stringFile, Item_Programm);
    bool loadBruch();
    QString  parse_ProjectName(QString);
    bool parse_Tool(QString, ToolList*);
signals:

};

#endif // PARSER_PROGRAMM_H
