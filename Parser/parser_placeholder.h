#ifndef PARSER_PLACEHOLDER_H
#define PARSER_PLACEHOLDER_H

#include <QObject>
#include "../logging.h"
#include "../mfile.h"
#include "../Project/project.h"

class Parser_PlaceHolder : public QObject
{
    Q_OBJECT
private:
    Logging* log;
    Project* project;
    MFile*   mfile;

    bool writeG55(QStringList*);

public:
    explicit Parser_PlaceHolder(QObject* parent = nullptr,
                                Logging* l = nullptr,
                                Project* p = nullptr);

    QStringList set_PlaceHolder_Antasten(QStringList);
    QStringList set_PlaceHolder_Cleaning(QStringList);
    QStringList set_PlaceHolder_MainProgramm(QStringList);
    QStringList set_PlaceHolder_RawPartInspection(QStringList);

    void set_Project(Project* p) {project = p;}
signals:

};

#endif // PARSER_PLACEHOLDER_H
