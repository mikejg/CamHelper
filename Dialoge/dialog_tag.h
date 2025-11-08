#ifndef DIALOG_TAG_H
#define DIALOG_TAG_H

#include <QDialog>
#include "../Classes/database.h"
#include "../Classes/struct.h"
#include "../Classes/mtoolbutton.h"
#include <QListWidgetItem>

namespace Ui {
class Dialog_Tag;
}

class Dialog_Tag : public QDialog
{
    Q_OBJECT
private:
    Ui::Dialog_Tag *ui;
    DataBase* database;
    ProjectData* projectData;
    MToolbutton* toolButton;

    QString lastText;
    Qt::CheckState lastState;

    void create_Tags();
    void create_TagsForOpenFile();

public:
    explicit Dialog_Tag(QWidget *parent = nullptr,
                        ProjectData* pd = nullptr,
                        DataBase* db = nullptr,
                        MToolbutton* tb = nullptr);

    Dialog_Tag(QWidget *parent = nullptr,
               DataBase* db = nullptr);

    ~Dialog_Tag();

signals:
    void sig_NewProjectList(QStringList);
    void sig_NoTagsSelected();

public slots:
    void slot_NewTag();
    void slot_TagHighlighted(QListWidgetItem*);
    void highlightChecked(QListWidgetItem*);
};

#endif // DIALOG_TAG_H
