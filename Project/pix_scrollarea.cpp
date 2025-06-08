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
    QPixmap pixmap(string_File);
    MLabel* label = new MLabel(this);
    connect(label, SIGNAL(sig_DeleteLabel(MLabel*)), this, SLOT(slot_DeleteLabel(MLabel*)));
    double ratio = double(pixmap.width()) / double(pixmap.height());

    label->set_Ratio(ratio);
    label->setFixedWidth(this->width());
    label->setFixedHeight(this->width()/ratio);
    label->setPixmap(pixmap);

    label->setScaledContents(true);

    layout->removeItem(spacerItem);
    layout->addWidget(label);
    label_List.append(label);
    layout->addItem(spacerItem);

}

void Pix_ScrollArea::insert_Pixmap(QPixmap pixmap)
{
    MLabel* label = new MLabel(this);
    connect(label, SIGNAL(sig_DeleteLabel(MLabel*)), this, SLOT(slot_DeleteLabel(MLabel*)));
    double ratio = double(pixmap.width()) / double(pixmap.height());

    label->set_Ratio(ratio);
    label->setFixedWidth(this->width());
    label->setFixedHeight(this->width()/ratio);
    label->setPixmap(pixmap);

    label->setScaledContents(true);

    layout->removeItem(spacerItem);
    layout->addWidget(label);
    label_List.append(label);
    layout->addItem(spacerItem);

}

void Pix_ScrollArea::resizeEvent(QResizeEvent* event)
{

    foreach (MLabel* label, label_List)
    {

        label->setFixedWidth(this->width());
        label->setFixedHeight(this->width()/label->get_Ratio());
    }
}

void Pix_ScrollArea::slot_DeleteLabel(MLabel* label)
{
    if(label_List.contains(label))
    {
        label_List.removeOne(label);
        delete label;
    }
}

void Pix_ScrollArea::clear()
{
    foreach(MLabel* label, label_List)
    {
        slot_DeleteLabel(label);
    }
}
