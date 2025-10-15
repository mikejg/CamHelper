#ifndef TOUCHPROBE_H
#define TOUCHPROBE_H

#include <QWidget>
#include <QDir>

#include "tp_highlighter.h"
#include "tp_item.h"
#include "../Classes/struct.h"
#include "../Classes/mfile.h"
#include "../Logging/logging.h"
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

    ProjectData* projectData;

public:
    explicit TouchProbe(QWidget *parent = nullptr);
    ~TouchProbe();
    void clear();
    void createTouchprobe();
    void exportTouchprobe();
    void insert_Item();
    void insert_Item(QList<Item_TouchProbe>);
    //void set_Project(Project* p) { project = p;}
    void set_ProjectData(ProjectData* pd) {projectData = pd;}
    void set_Logging(Logging* l);
    QList<TP_Item*> get_ItemList();

public slots:
    void slot_NewPixmap(QPixmap);
    void slot_Create();
    void slot_ShowPix();
    void slot_Export();
    void slot_ExportTouchprobe();

signals:
};

#endif // TOUCHPROBE_H
