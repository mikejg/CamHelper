#include "pix_scrollcontent.h"
#include "ui_pix_scrollcontent.h"

Pix_ScrollContent::Pix_ScrollContent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Pix_ScrollContent)
{
    ui->setupUi(this);
}

Pix_ScrollContent::~Pix_ScrollContent()
{
    delete ui;
}

void Pix_ScrollContent::insert_Pixmap(QString string_File)
{
    QPixmap pixmap(string_File);
    MLabel* label = new MLabel(this);
    double ratio = pixmap.width() / pixmap.height();

    label->set_Ratio(ratio);
    label->setFixedWidth(this->width());
    label->setFixedHeight(this->width()/ratio);
    label->setPixmap(pixmap);

    //label->setScaledContents(true);

    //layout->removeItem(ui->verticalSpacer_Pictures);
    layout->addWidget(label);
    label_List.append(label);

    //layout->addItem(ui->verticalSpacer_Pictures);

}

void Pix_ScrollContent::resizeEvent(QResizeEvent *event)
{
    qDebug() << Q_FUNC_INFO << width();
    foreach(MLabel* label, label_List)
    {
        label->setMinimumWidth(width());
        label->setMinimumHeight(width()/label->get_Ratio());
    }
}
