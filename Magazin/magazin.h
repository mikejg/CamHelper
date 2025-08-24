#ifndef MAGAZIN_H
#define MAGAZIN_H

#include <QWidget>
#include <QFileSystemWatcher>
#include <thread>
#include "magazinmodel.h"
#include "../Classes/database.h"
#include "../Logging/logging.h"
#include "../Classes/mfile.h"
#include "../Tool/toollist.h"

namespace Ui {
class Magazin;
}

class Magazin : public QWidget
{
    Q_OBJECT

private:
    Ui::Magazin *ui;
    DataBase*      dataBase;
    QString        string_DirPath;
    Logging*       log;
    MFile*         mfile;
    ToolList*      toolList;
    ToolList*      searchList;
    int            sizeIn;
    MagazinModel*  tableModel;
    QFileSystemWatcher fileSystemWatcher;

    QList<QString> list_ToolID;
    QList<QString> list_ToolDescription;
    QList<QString> list_GageLength;
    QList<QString> list_ToolLength;
    QList<QString> list_TipLength;
    QList<QString> list_ToolState;
    QList<QString> list_CutLength;

    QString string_old;
    QColor text_Color;

    void contains(QString, ToolList*);
public:
    explicit Magazin(QWidget *parent = nullptr);
    ~Magazin();

    bool      contains(Tool*);
    bool      create_ToolList();
    int       get_Size(){return sizeIn;}
    ToolList* get_ToolList() {return toolList;}
    void      set_DataBase(DataBase* db) {dataBase = db;}
    void      set_FilePath(QString str) {mfile->setFileName(str);
                                         fileSystemWatcher.addPath(str);}
    void      set_Logging(Logging* l) {log = l; mfile->set_Logging(l);}
    void      showToolList(ToolList*);

signals:
    void sig_NewMagazin();

public slots:
    void slot_TableClicked(const QModelIndex &);
    void slot_textEdited(QString);
    void slot_MagazinChanged(QString);
};

#endif // MAGAZIN_H
