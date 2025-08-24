#include "tp_item.h"
#include "ui_tp_item.h"
#include "tp_ausrichten.h"

TP_Item::TP_Item(QWidget *parent, Logging* l) :
    QFrame(parent),
    ui(new Ui::TP_Item)
{
    ui->setupUi(this);
    log = l;
    hideAll();
    slot_Fold_In();
    state = NoState;

    connect(ui->widget_TP_Kante, SIGNAL(sig_ReCreate()), this, SLOT(slot_ReCreate()));
    connect(ui->widget_TP_Kante, SIGNAL(sig_NewHeaderLine(QString)), this, SLOT(slot_NewHeaderLine(QString)));
    connect(ui->widget_TP_Ausrichten, SIGNAL(sig_ReCreate()), this, SLOT(slot_ReCreate()));
    connect(ui->widget_TP_Ausrichten, SIGNAL(sig_NewHeaderLine(QString)), this, SLOT(slot_NewHeaderLine(QString)));
    connect(ui->widget_TP_Ebenheit, SIGNAL(sig_ReCreate()), this, SLOT(slot_ReCreate()));
    connect(ui->widget_TP_Ebenheit, SIGNAL(sig_NewHeaderLine(QString)), this, SLOT(slot_NewHeaderLine(QString)));
    connect(ui->widget_TP_Steg, SIGNAL(sig_ReCreate()), this, SLOT(slot_ReCreate()));
    connect(ui->widget_TP_Steg, SIGNAL(sig_NewHeaderLine(QString)), this, SLOT(slot_NewHeaderLine(QString)));
    connect(ui->widget_TP_Bohrung, SIGNAL(sig_ReCreate()), this, SLOT(slot_ReCreate()));
    connect(ui->widget_TP_Bohrung, SIGNAL(sig_NewHeaderLine(QString)), this, SLOT(slot_NewHeaderLine(QString)));
    connect(ui->widget_TP_Nut, SIGNAL(sig_ReCreate()), this, SLOT(slot_ReCreate()));
    connect(ui->widget_TP_Nut, SIGNAL(sig_NewHeaderLine(QString)), this, SLOT(slot_NewHeaderLine(QString)));

    connect(ui->toolButton_Fold, SIGNAL(pressed()), this, SLOT(slot_Fold_Toggle()));

    connect(ui->toolButton_Steg, SIGNAL(pressed()), this, SLOT(slot_Show_TP_Steg()));
    connect(ui->toolButton_Kante, SIGNAL(pressed()), this, SLOT(slot_Show_TP_Kante()));
    connect(ui->toolButton_Ebenheit, SIGNAL(pressed()), this, SLOT(slot_Show_TP_Ebenheit()));
    connect(ui->toolButton_Ausrichten, SIGNAL(pressed()), this, SLOT(slot_Show_TP_Ausrichten()));
    connect(ui->toolButton_Bohrung, SIGNAL(pressed()), this, SLOT(slot_Show_TP_Bohrung()));
    connect(ui->toolButton_Nut, SIGNAL(pressed()), this, SLOT(slot_Show_TP_Nut()));
    connect(ui->toolButton_Add, SIGNAL(pressed()), this, SIGNAL(sig_NewItem()));
    connect(ui->toolButton_Trash, SIGNAL(pressed()), this, SLOT(slot_Delet_Item()));

    connect(ui->widget_TP_Kante, SIGNAL(sig_NewPixmap(QPixmap)), this, SIGNAL(sig_NewPixmap(QPixmap)));
    connect(ui->widget_TP_Ausrichten, SIGNAL(sig_NewPixmap(QPixmap)), this, SIGNAL(sig_NewPixmap(QPixmap)));
    connect(ui->widget_TP_Ebenheit, SIGNAL(sig_NewPixmap(QPixmap)), this, SIGNAL(sig_NewPixmap(QPixmap)));
    connect(ui->widget_TP_Steg, SIGNAL(sig_NewPixmap(QPixmap)),this, SIGNAL(sig_NewPixmap(QPixmap)));
    connect(ui->widget_TP_Bohrung, SIGNAL(sig_NewPixmap(QPixmap)), this, SIGNAL(sig_NewPixmap(QPixmap)));
    connect(ui->widget_TP_Nut, SIGNAL(sig_NewPixmap(QPixmap)), this, SIGNAL(sig_NewPixmap(QPixmap)));


    ui->widget_TP_Ausrichten->set_Logging(log);
    ui->widget_TP_Kante->set_Logging(log);
    ui->widget_TP_Ebenheit->set_Logging(log);
    ui->widget_TP_Steg->set_Logging(log);
    ui->widget_TP_Bohrung->set_Logging(log);
    ui->widget_TP_Nut->set_Logging(log);
}

TP_Item::~TP_Item()
{
    delete ui;
}

void TP_Item::set_Data(Item_TouchProbe item)
{
    if(item.state == Item_TouchProbe::Ausrichten)
    {
        hideAll();
        state = Ausrichten;
        ui->widget_TP_Ausrichten->setPixmap();
        ui->widget_TP_Ausrichten->show();
        ui->label_PreView_Icon->setPixmap(QPixmap(QString::fromUtf8(":/Icons/TouchProbe/Ausrichten.png")));
        ui->label_PreView_Text->setText("Ausrichten");
        ui->widget_TP_Ausrichten->set_Data(item.struct_Ausrichten);
        ui->widget_TP_Ausrichten->create_NewHeaderLine();
        slot_ReCreate();
    }

    if(item.state == Item_TouchProbe::Kante)
    {
        hideAll();
        state = Kante;
        ui->widget_TP_Kante->setPixmap();
        ui->widget_TP_Kante->show();
        ui->label_PreView_Icon->setPixmap(QPixmap(QString::fromUtf8(":/Icons/TouchProbe/Kante.png")));
        ui->label_PreView_Text->setText("Antasten Kante");
        ui->widget_TP_Kante->set_Data(item.struct_Kante);
        ui->widget_TP_Kante->create_NewHeaderLine();
        slot_ReCreate();
    }

    if(item.state == Item_TouchProbe::Steg)
    {
        hideAll();
        state = Steg;
        ui->widget_TP_Steg->setPixmap();
        ui->widget_TP_Steg->show();
        ui->label_PreView_Icon->setPixmap(QPixmap(QString::fromUtf8(":/Icons/TouchProbe/Steg.png")));
        ui->label_PreView_Text->setText("Antasten Steg");
        ui->widget_TP_Steg->set_Data(item.struct_Steg);
        ui->widget_TP_Steg->create_NewHeaderLine();
        slot_ReCreate();
    }

    if(item.state == Item_TouchProbe::Ebenheit)
    {
        hideAll();
        state = Ebenheit;
        ui->widget_TP_Ebenheit->setPixmap();
        ui->widget_TP_Ebenheit->show();
        ui->label_PreView_Icon->setPixmap(QPixmap(QString::fromUtf8(":/Icons/TouchProbe/Ebene.png")));
        ui->label_PreView_Text->setText("Ebenheit");
        ui->widget_TP_Ebenheit->set_Data(item.struct_Ebenheit);
        ui->widget_TP_Ebenheit->create_NewHeaderLine();
        slot_ReCreate();
    }

    if(item.state == Item_TouchProbe::Bohrung)
    {
        hideAll();
        state = Bohrung;
        ui->widget_TP_Bohrung->setPixmap();
        ui->widget_TP_Bohrung->show();
        ui->label_PreView_Icon->setPixmap(QPixmap(QString::fromUtf8(":/Icons/TouchProbe/Bohrung.png")));
        ui->label_PreView_Text->setText("Bohrung");
        ui->widget_TP_Bohrung->set_Data(item.struct_Bohrung);
        ui->widget_TP_Bohrung->create_NewHeaderLine();
        slot_ReCreate();
    }

    if(item.state == Item_TouchProbe::Nut)
    {
        hideAll();
        state = Nut;
        ui->widget_TP_Nut->setPixmap();
        ui->widget_TP_Nut->show();
        ui->label_PreView_Icon->setPixmap(QPixmap(QString::fromUtf8(":/Icons/TouchProbe/Nut.png")));
        ui->label_PreView_Text->setText("Antasten Steg");
        ui->widget_TP_Nut->set_Data(item.struct_Nut);
        ui->widget_TP_Nut->create_NewHeaderLine();
        slot_ReCreate();
    }
}

void TP_Item::set_Text(QString str)
{
    ui->label_PreView_Text->setText(str);
}

Struct_Ausrichten TP_Item::get_Ausrichten()
{
    return ui->widget_TP_Ausrichten->get_Data();
}

Struct_Bohrung TP_Item::get_Bohrung()
{
    return ui->widget_TP_Bohrung->get_Data();
}

Struct_Kante TP_Item::get_Kante()
{
    return ui->widget_TP_Kante->get_Data();
}

Struct_Ebenheit TP_Item::get_Ebenheit()
{
    return ui->widget_TP_Ebenheit->get_Data();
}

Struct_Steg TP_Item::get_Steg()
{
    return ui->widget_TP_Steg->get_Data();
}

Struct_Nut TP_Item::get_Nut()
{
    return ui->widget_TP_Nut->get_Data();
}

QString TP_Item::get_Text()
{
    return ui->label_PreView_Text->text();
}

void TP_Item::slot_Fold_In()
{
    ui->widget_FullView->hide();
    bool_Fold = false;
    emit sig_HighLightLineNumber(QStringList());
}

void TP_Item::slot_Fold_Out()
{
    ui->widget_FullView->show();
    bool_Fold = true;

    emit sig_Create();
    emit sig_HighLightLineNumber(stringList_LineNumber);
    switch(state)
    {
        case Kante:
            ui->widget_TP_Kante->setPixmap();
            break;
        case Ausrichten:
            ui->widget_TP_Ausrichten->setPixmap();
            break;
        case Steg:
            ui->widget_TP_Steg->setPixmap();
            break;
        case Ebenheit:
            ui->widget_TP_Ebenheit->setPixmap();
            break;
        case Bohrung:
            ui->widget_TP_Bohrung->setPixmap();
            break;
        case Nut:
            ui->widget_TP_Nut->setPixmap();
            break;
    }
}

void TP_Item::slot_Fold_Toggle()
{
    if(bool_Fold)
        slot_Fold_In();
    else
        slot_Fold_Out();
}

void TP_Item::slot_ReCreate()
{
    emit sig_Create();
    emit sig_HighLightLineNumber(stringList_LineNumber);
}

void TP_Item::slot_Show_TP_Kante()
{
    hideAll();
    state = Kante;
    ui->widget_TP_Kante->show();
    ui->widget_TP_Kante->setPixmap();
    ui->label_PreView_Icon->setPixmap(QPixmap(QString::fromUtf8(":/Icons/TouchProbe/Kante.png")));
    ui->label_PreView_Text->setText("Antasten Kante");
}

void TP_Item::slot_Show_TP_Ebenheit()
{
    hideAll();
    state = Ebenheit;
    ui->widget_TP_Ebenheit->show();
    ui->widget_TP_Ebenheit->setPixmap();
    ui->label_PreView_Icon->setPixmap(QPixmap(QString::fromUtf8(":/Icons/TouchProbe/Ebene.png")));
    ui->label_PreView_Text->setText("Ebenheit");
}

void TP_Item::slot_Show_TP_Ausrichten()
{
    hideAll();
    state = Ausrichten;
    ui->widget_TP_Ausrichten->setPixmap();
    ui->widget_TP_Ausrichten->show();
    ui->label_PreView_Icon->setPixmap(QPixmap(QString::fromUtf8(":/Icons/TouchProbe/Ausrichten.png")));
    ui->label_PreView_Text->setText("Ausrichten");
    ui->widget_TP_Ausrichten->create_NewHeaderLine();
    slot_ReCreate();
}

void TP_Item::slot_Show_TP_Steg()
{
    hideAll();
    state = Steg;
    ui->widget_TP_Steg->setPixmap();
    ui->widget_TP_Steg->show();
    ui->label_PreView_Icon->setPixmap(QPixmap(QString::fromUtf8(":/Icons/TouchProbe/Steg.png")));
    ui->label_PreView_Text->setText("Steg");
    ui->widget_TP_Steg->create_NewHeaderLine();
    slot_ReCreate();
}

void TP_Item::slot_Show_TP_Nut()
{
    hideAll();
    state = Nut;
    ui->widget_TP_Nut->setPixmap();
    ui->widget_TP_Nut->show();
    ui->label_PreView_Icon->setPixmap(QPixmap(QString::fromUtf8(":/Icons/TouchProbe/Nut.png")));
    ui->label_PreView_Text->setText("Nut");
    ui->widget_TP_Nut->create_NewHeaderLine();
    slot_ReCreate();
}

void TP_Item::slot_Show_TP_Bohrung()
{
    hideAll();
    state = Bohrung;
    ui->widget_TP_Bohrung->setPixmap();
    ui->widget_TP_Bohrung->show();
    ui->label_PreView_Icon->setPixmap(QPixmap(QString::fromUtf8(":/Icons/TouchProbe/Bohrung.png")));
    ui->label_PreView_Text->setText("Bohrung");
    ui->widget_TP_Bohrung->create_NewHeaderLine();
    slot_ReCreate();
}

void TP_Item::slot_NewHeaderLine(QString str)
{
    ui->label_PreView_Text->setText(str);
}

void TP_Item::hideAll()
{
    ui->widget_TP_Kante->hide();
    ui->widget_TP_Ausrichten->hide();
    ui->widget_TP_Steg->hide();
    ui->widget_TP_Ebenheit->hide();
    ui->widget_TP_Bohrung->hide();
    ui->widget_TP_Nut->hide();
}

void TP_Item::read_Anfahren()
{
    ui->widget_TP_Kante->set_Anfahren();
    ui->widget_TP_Ausrichten->set_Anfahren();
    ui->widget_TP_Steg->set_Anfahren();
    ui->widget_TP_Bohrung->set_Anfahren();
    ui->widget_TP_Nut->set_Anfahren();
}

QStringList TP_Item::postProcessing()
{
    stringList_PostProcessing.clear();

    if(state == Kante)
    {
        stringList_PostProcessing = ui->widget_TP_Kante->postProcessing();
    }

    if(state == Ausrichten)
    {
        stringList_PostProcessing = ui->widget_TP_Ausrichten->postProcessing();
    }

    if(state == Steg)
    {
        stringList_PostProcessing = ui->widget_TP_Steg->postProcessing();
    }

    if(state == Ebenheit)
    {
        stringList_PostProcessing = ui->widget_TP_Ebenheit->postProcessing();
    }

    if(state == Bohrung)
    {
        stringList_PostProcessing = ui->widget_TP_Bohrung->postProcessing();
    }

    if(state == Nut)
    {
        stringList_PostProcessing = ui->widget_TP_Nut->postProcessing();
    }
    return stringList_PostProcessing;
}

QStringList TP_Item::postProcessing_Ebenheit()
{
    qDebug() << Q_FUNC_INFO;
    stringList_PostProcessing_Ebenheit = ui->widget_TP_Ebenheit->postProcessing_Ebenheit();
    return stringList_PostProcessing_Ebenheit;
}

void TP_Item::slot_Delet_Item()
{
    emit sig_DeleteItem(this);
}



