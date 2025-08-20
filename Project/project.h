#ifndef PROJECT_H
#define PROJECT_H

#include <QObject>

#include "../Classes/struct.h"

class Project : public QObject
{
    Q_OBJECT

private:
    ProjectData* projectData;

public:
    explicit Project(QObject *parent = nullptr);
    void set_ProjectData(ProjectData* pd) {projectData = pd;}
};

#endif // PROJECT_H
