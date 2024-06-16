#ifndef MAGAZIN_H
#define MAGAZIN_H

#include <QWidget>

#include "magazinmodel.h"
#include "../database.h"
#include "../logging.h"
#include "../mfile.h"
#include "../Tools/toollist.h"

namespace Ui {
class Magazin;
}

class Magazin : public QWidget
{
    Q_OBJECT

private:
    Ui::Magazin *ui;
    DataBase*      dataBase;
    Logging*       log;
    MFile*         mfile;
    ToolList*      toolList;
    ToolList*      searchList;
    int            sizeIn;
    MagazinModel*  tableModel;

    QList<QString> list_ToolID;
    QList<QString> list_ToolDescription;
    QList<QString> list_GageLength;
    QList<QString> list_ToolLength;
    QList<QString> list_TipLength;
    QList<QString> list_ToolState;
    QList<QString> list_CutLength;

    QString string_old;

    void contains(QString, ToolList*);
public:
    explicit Magazin(QWidget *parent = nullptr);
    ~Magazin();

    bool      contains(Tool*);
    bool      create_ToolList();
    int       get_Size(){return sizeIn;}
    ToolList* get_ToolList() {return toolList;}
    void      set_DataBase(DataBase* db) {dataBase = db;}
    void      set_FilePath(QString str) {mfile->setFileName(str);}
    void      set_Logging(Logging* l) {log = l; mfile->set_Logging(l);}
    void      showToolList(ToolList*);

signals:
    //void sig_Err(QString);
    //void sig_Log(QString);

public slots:
    void slot_TableClicked(const QModelIndex &);
    void slot_textEdited(QString);
};

#endif // MAGAZIN_H
