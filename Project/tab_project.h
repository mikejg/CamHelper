#ifndef TAB_PROJECT_H
#define TAB_PROJECT_H

#include <QWidget>

#include "../Classes/database.h"
#include "../Classes/mfile.h"
#include "../Logging/logging.h"

#include "project.h"

namespace Ui {
class Tab_Project;
}

class Tab_Project : public QWidget
{
    Q_OBJECT
private:
    Ui::Tab_Project *ui;
    DataBase* dataBase;
    Logging* log;
    MFile* mfile; // wird in set_Logging erstellt
    ProjectData projectData;

    void insert_Pixmap(QPixmap p);

public:
    explicit Tab_Project(QWidget *parent = nullptr);
    ~Tab_Project();

    bool load_Material();
    //void set_DataBase(DataBase* db) {dataBase = db;}
    void set_Logging(Logging* l); //Logging wird gesetzt und MFile mit Logging erstellt
    void set_ProjectData(ProjectData);

public slots:
};

#endif // TAB_PROJECT_H
