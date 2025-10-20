#include "tp_scrollcontent.h"
#include "ui_tp_scrollcontent.h"

#include <QtWidgets>

TP_ScrollContent::TP_ScrollContent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TP_ScrollContent)
{
    ui->setupUi(this);
}

TP_ScrollContent::~TP_ScrollContent()
{
    delete ui;
}

void TP_ScrollContent::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata"))
    {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else
    {
        event->ignore();
    }    
}

void TP_ScrollContent::dragMoveEvent(QDragMoveEvent *event)
{

    if (event->mimeData()->hasFormat("application/x-dnditemdata"))
    {
        if (event->source() == this)
        {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }
        else
        {
            event->acceptProposedAction();
        }
    }
    else
    {
        event->ignore();
    }
}

void TP_ScrollContent::dropEvent(QDropEvent *event)
{
    qDebug() << Q_FUNC_INFO;
    if (event->mimeData()->hasFormat("application/x-dnditemdata"))
    {
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QString string;
        QPoint offset;
        dataStream >> string >> offset;

        child->move(event->pos() - offset);
        if (event->source() == this)
        {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }

        else
        {
            event->acceptProposedAction();
        }
    }
    else
    {
        event->ignore();
    }
}

//! [1]
void TP_ScrollContent::mousePressEvent(QMouseEvent *event)
{
    child = static_cast<TP_Item*>(childAt(event->pos()));

    if(child == nullptr) return;

    while(child->parent() != this)
    {
        child = static_cast<TP_Item*>(child->parent());
    }

    if (!child)
        return;

    child->highLight();
    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    QString string = child->get_Text();
    dataStream << string << QPoint(event->pos() - child->pos());
//! [1]

//! [2]
    QMimeData *mimeData = new QMimeData;
    mimeData->setData("application/x-dnditemdata", itemData);
//! [2]

//! [3]
    QPixmap pixmap = child->grab();
    QPainter painter;
    painter.begin(&pixmap);
    painter.fillRect(pixmap.rect(), QColor(127, 127, 127, 127));
    painter.end();

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(event->pos() - child->pos());
//! [3

    if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction)
    {
        //qDebug() << "(drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction)";
        //child->close();
    }
    else
    {
        //qDebug() << "else (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction) ";
        child->show();
    }

    //Alle Widgets aus dem Layout loeschen
    layout->removeItem(spacerItem);
    foreach(TP_Item* item, item_List)
    {
        this->layout->removeWidget(item);
    }

   for (int i = 0; i<item_List.size(); i++)
   {

       for(int j = 0; j<i; j++)
       {
           if(item_List.at(i)->geometry().y() < item_List.at(j)->geometry().y())// + item_List.at(j)->geometry().height())
           {
               item_List.move(i,j);
               break;
           }
       }
   }

   foreach(TP_Item* item, item_List)
   {
       this->layout->addWidget(item);
   }

   emit sig_Create();
   child->highLight();

   layout->addItem(spacerItem);
}

void TP_ScrollContent::insertItem(QList<Item_TouchProbe> list)
{
   foreach(Item_TouchProbe item, list)
   {
       layout->removeItem(spacerItem);
       tp_Item = new TP_Item(this, log);

       connect(tp_Item, SIGNAL(sig_NewPixmap(QPixmap)), this, SIGNAL(sig_NewPixmap(QPixmap)));
       connect(tp_Item, SIGNAL(sig_DeleteItem(TP_Item*)), this, SLOT(slot_DeleteItem(TP_Item*)));
       connect(tp_Item, SIGNAL(sig_HighLightLineNumber(QStringList)),
               highLighter, SLOT(slot_HighLightLineNumer(QStringList)));
       connect(tp_Item, SIGNAL(sig_Create()), this, SIGNAL(sig_Create()));
       connect(tp_Item, SIGNAL(sig_NewItem()), this, SLOT(slot_InsertItem()));

       tp_Item->set_Data(item);
       layout->addWidget(tp_Item);
       layout->addItem(spacerItem);
       item_List.append(tp_Item);
   }
   if(item_List.isEmpty())
       slot_InsertItem();
}

void TP_ScrollContent::slot_InsertItem()
{
    layout->removeItem(spacerItem);
    tp_Item = new TP_Item(this, log);

    connect(tp_Item, SIGNAL(sig_NewPixmap(QPixmap)), this, SIGNAL(sig_NewPixmap(QPixmap)));
    connect(tp_Item, SIGNAL(sig_DeleteItem(TP_Item*)), this, SLOT(slot_DeleteItem(TP_Item*)));
    connect(tp_Item, SIGNAL(sig_HighLightLineNumber(QStringList)),
            highLighter, SLOT(slot_HighLightLineNumer(QStringList)));
    connect(tp_Item, SIGNAL(sig_Create()), this, SIGNAL(sig_Create()));

    layout->addWidget(tp_Item);
    layout->addItem(spacerItem);
    item_List.append(tp_Item);

    tp_Item->read_Anfahren();
    tp_Item->set_Text("Neues Item");
    connect(tp_Item, SIGNAL(sig_NewItem()), this, SLOT(slot_InsertItem()));
}

void TP_ScrollContent::slot_DeleteItem(TP_Item* tp_Item)
{
    if(item_List.contains(tp_Item))
    {
       item_List.removeOne(tp_Item);
       delete tp_Item;
    }
}

void TP_ScrollContent::clear()
{
    foreach(TP_Item* item, item_List)
    {
       slot_DeleteItem(item);
    }
    //slot_InsertItem();
}
