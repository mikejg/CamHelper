#ifndef TOUCHPROBE_H
#define TOUCHPROBE_H

#include <QWidget>
#include <QDir>

#include "tp_highlighter.h"
#include "tp_item.h"
#include "../database_items.h"
#include "../mfile.h"
#include "../logging.h"
#include "../Project/project.h"

namespace Ui {
class TouchProbe;
}

class TouchProbe : public QWidget
{
    Q_OBJECT

private:
    Ui::TouchProbe *ui;
    MFile* mfile;
    Logging* log;
    TP_HighLighter* tp_HighLighter;
    int int_CounterEbenheit;

    QStringList stringList_Content;
    int         counter;
    void insert_Content();
    void insert_Content(TP_Item*);
    bool   bool_Create;
    void export_Ebenheit();

    Project* project;

public:
    explicit TouchProbe(QWidget *parent = nullptr);
    ~TouchProbe();
    void clear();
    void insert_Item();
    void insert_Item(QList<Item_TouchProbe>);
    void set_Project(Project* p) { project = p;}
    void set_Logging(Logging* l);
    QList<TP_Item*> get_ItemList();

public slots:
    void slot_NewPixmap(QPixmap);
    void slot_Create();
    void slot_ShowPix();
    void slot_Export();
    //void slot_NewTextCursor(QTextCursor);

signals:
    //void sig_Err(QString);
    //void sig_Log(QString);
};

#endif // TOUCHPROBE_H