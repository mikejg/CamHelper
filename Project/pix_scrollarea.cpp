#include "pix_scrollarea.h"
#include "ui_pix_scrollarea.h"

Pix_ScrollArea::Pix_ScrollArea(QWidget *parent) :
    QScrollArea(parent),
    ui(new Ui::Pix_ScrollArea)
{
    ui->setupUi(this);
}

Pix_ScrollArea::~Pix_ScrollArea()
{
    delete ui;
}

void Pix_ScrollArea::insert_Pixmap(QString string_File)
{
    /*
    QPixmap pixmap(string_File);
    MLabel* label = new MLabel(this);
    connect(label, SIGNAL(sig_DeleteLabel(MLabel*)), this, SLOT(slot_DeleteLabel(MLabel*)));
    double ratio = double(pixmap.width()) / double(pixmap.height());

    //label->set_Ratio(ratio);
    label->setFixedWidth(this->width());
    label->setFixedHeight(this->width()/ratio);
    label->setPixmap(pixmap,10);

    label->setScaledContents(true);

    layout->removeItem(spacerItem);
    layout->addWidget(label);
    label_List.append(label);
    layout->addItem(spacerItem);
    */
}

void Pix_ScrollArea::insert_Pixmap(QPixmap pixmap)
{
    MLabel* label = new MLabel(this);
    connect(label, SIGNAL(sig_DeleteLabel(MLabel*)), this, SLOT(slot_DeleteLabel(MLabel*)));
    double ratio = double(pixmap.width()) / double(pixmap.height());    //berechne das Seitenverhältnis

    label->set_Ratio(ratio);                                            //Speicher das Seitenverhältnis ins Label
    label->setPixmap(pixmap, 10);                                       //Setze das Bild für das Label

    layout->removeItem(spacerItem);                                     //Löscher den Sapcer am Ende des Scrollbereichs
    layout->addWidget(label);                                           //Füge dem Scrollbereich das Label hinzu
    label_List.append(label);                                           //Füge der Liste das Label hinzu
    layout->addItem(spacerItem);                                        //Setze am Ende wieder einen Spacer
}

void Pix_ScrollArea::resizeEvent(QResizeEvent* event)
{
    Q_UNUSED(event);

    int int_Width = this->width() - 30;                         //Zieh von der aktuellen Breite 30 Pixel ab
    foreach (MLabel* label, label_List)
    {
        label->setFixedWidth(int_Width);                        //setze die feste Breite mit dem Wert von int_Width
        label->setFixedHeight(int_Width/label->get_Ratio());    //setze die feste Höhe unter berücksichtigung des Seitenverhältnis
    }
}

void Pix_ScrollArea::slot_DeleteLabel(MLabel* label)
{
                                        //Löscht ein Label aus der Liste
    if(label_List.contains(label))      //Wenn es das Label in der Liste gibt
    {
        label_List.removeOne(label);    //Lösche das Label aus der Liste
        delete label;                   //Lösche das Label
    }
}

void Pix_ScrollArea::clear()
{
    foreach(MLabel* label, label_List)  //Löscht alle Labels aus der Liste
    {
        slot_DeleteLabel(label);
    }
}
