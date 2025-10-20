#ifndef DIALOG_TOOLSEARCH_H
#define DIALOG_TOOLSEARCH_H

#include <QDialog>
#include "../Classes/database.h"
namespace Ui {
class Dialog_ToolSearch;
}

class Dialog_ToolSearch : public QDialog
{
    Q_OBJECT
private:
    Ui::Dialog_ToolSearch *ui;
    DataBase* dataBase;
    QString string_old;
    QStringList stringList_Tools;
    QStringList stringList_Temp;

public:
    explicit Dialog_ToolSearch(QWidget *parent = nullptr);
    Dialog_ToolSearch(QWidget *parent = nullptr,
               DataBase* db = nullptr);
    ~Dialog_ToolSearch();

signals:
    void sig_NewProjectList(QStringList);

public slots:
    void slot_CurrentTextChanged(QString);
    void slot_textEdited(QString);
};

#endif // DIALOG_TOOLSEARCH_H
