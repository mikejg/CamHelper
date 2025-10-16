#ifndef DIALOG_OPEN_H
#define DIALOG_OPEN_H

#include <QDialog>
#include <QStringListModel>

#include "dialog_tag.h"
#include "../Classes/database.h"
#include "../Classes/struct.h"
//#include "../Logging//logging.h"

namespace Ui {
class Dialog_Open;
}

class Dialog_Open : public QDialog
{
    Q_OBJECT

private:
    Ui::Dialog_Open *ui;
    DataBase* dataBase;
    Dialog_Tag* dialog_Tag;
    //Logging* logging;
    QStringList stringList_Projects;
    QStringList stringList_Model;
    QStringListModel *model;

public:
    explicit Dialog_Open(QWidget *parent = nullptr,
                         DataBase* db = nullptr);
    ~Dialog_Open();

public slots:
    void slot_ShowDialog();
    void slot_accepted();
    void slot_TextChanged(QString);
    void slot_Clicked(QModelIndex);
    void slot_TagsClicked();
    void slot_NewProjectList(QStringList);
    void slot_NoTagsSelected();
signals:
    void sig_OpenProject(QString, QString);

};

#endif // DIALOG_OPEN_H
