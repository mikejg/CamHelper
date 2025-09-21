#ifndef SPF_PARSER_H
#define SPF_PARSER_H

#include <QObject>
#include <QDir>
#include <QRegularExpression>
#include "mfile.h"
#include "struct.h"
#include "database.h"
#include "../Logging/logging.h"
#include "../Tool/tool.h"

class SPF_Parser : public QObject
{
    Q_OBJECT

private:
    enum Marker {kein_Marker, werkzeugliste_Anfang, werkzeugliste_Ende, Messerkopf, neuesWerkzeug,
                  Schwenkung};
    Marker marker;
    QString string_ProgrammDir;
    ProjectData* projectData;
    Logging * log;
    MFile* mfile;
    DataBase* dataBase;
    QStringList stringList_Content;
    QMap<QString, QString> map_Bruch;
    bool bool_ersterBruch;
    bool bool_Messerkopf;
    bool bool_EinlippenBohrer;
    QString string_Line;
    QStringList stringList_Log;

    void checkOptimiertesTieflochbohren();
    void insert_Tool(QString, ToolList*);
    QString parse_ProjectName(QString);
    QString parse_PostProcessor(QString);
    bool parse_Tool(QString, ToolList*);
    bool sort_Programms();
    void loadBruch();
    void compare(QStringList, QStringList);

public:
    explicit SPF_Parser(QObject *parent = nullptr,
                        QString string_PD = "",
                        Logging* l = nullptr,
                        DataBase* db = nullptr);
    bool scann_ForData();
    bool scann_ForTools();
    bool scann_ForNoXY();
    void set_ProjectData(ProjectData* pd) {projectData = pd;}
    void finish(QString, Programm);

    QStringList replace_Wildcard(QStringList);
signals:
};

#endif // SPF_PARSER_H
