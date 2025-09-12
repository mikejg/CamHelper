#include "mcellwidget.h"
#include "ui_mcellwidget.h"

MCellWidget::MCellWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MCellWidget)
{
    ui->setupUi(this);

    string_StyleSheet = styleSheet();
}

MCellWidget::~MCellWidget()
{
    delete ui;
}

void MCellWidget::set_ProjectData(ProjectData pd)
{
    projectData = pd;
    if(pd.listPictures.size() > 0)
        ui->label_Pixmap->setPixmap(pd.listPictures.at(0), 10);

    ui->label_Text->setText(pd.name);
    setMinimumHeight(200);
}

void MCellWidget::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);

    setStyleSheet(string_StyleSheet + "QFrame:hover{border-color:rgb(128,255,128);} ");
}

void MCellWidget::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);

    setStyleSheet(string_StyleSheet);
    emit sig_Clicked(projectData.id);
}
