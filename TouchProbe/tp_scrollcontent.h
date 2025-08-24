#ifndef TP_SCROLLCONTENT_H
#define TP_SCROLLCONTENT_H

#include <QWidget>
#include <QList>
#include <QVBoxLayout>
#include <QSpacerItem>
#include "tp_highlighter.h"
#include "tp_item.h"
#include "../Logging/logging.h"
#include "../Classes/struct.h"

QT_BEGIN_NAMESPACE
class QDragEnterEvent;
class QDropEvent;
QT_END_NAMESPACE

namespace Ui
{
class TP_ScrollContent;
}

class TP_ScrollContent : public QWidget
{
    Q_OBJECT

private:
    Ui::TP_ScrollContent *ui;
    QList<TP_Item*> item_List;
    TP_Item* tp_Item;
    QVBoxLayout* layout;
    QSpacerItem* spacerItem;
    TP_Item *child;
    Logging* log;
    TP_HighLighter* highLighter;

public:
    explicit TP_ScrollContent(QWidget *parent = nullptr);
    ~TP_ScrollContent();
    void clear();
    void insertItem(QList<Item_TouchProbe>);
    void set_HighLighter(TP_HighLighter* h) {highLighter = h;}
    void set_Layout(QVBoxLayout* l) {layout = l;}
    void set_Logging(Logging* l) { log = l;}
    void set_SpacerItem(QSpacerItem* si) {spacerItem = si;}
    QList<TP_Item*> get_ItemList() {return item_List;}

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

public slots:
    void slot_InsertItem();
    void slot_DeleteItem(TP_Item*);

signals:
    void sig_NewPixmap(QPixmap);

    // sig_Create() -> TouchProbe::slot_Create()
    // generiert Antastprogramm neu
    void sig_Create();
};

#endif // TP_SCROLLCONTENT_H
