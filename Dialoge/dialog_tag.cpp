#include "dialog_tag.h"
#include "ui_dialog_tag.h"


Dialog_Tag::Dialog_Tag(QWidget *parent, ProjectData* pd, DataBase* db, MToolbutton* tb) :
    QDialog(parent),
    ui(new Ui::Dialog_Tag)
{
    projectData = pd;
    database = db;
    toolButton = tb;

    ui->setupUi(this);

    create_Tags();
    connect(ui->toolButton_Add, SIGNAL(released()), this, SLOT(slot_NewTag()));

    delete ui->buttonBox;
}

Dialog_Tag::Dialog_Tag(QWidget *parent, DataBase *db) :
    QDialog(parent),
    ui(new Ui::Dialog_Tag)
{
    database = db;
    ui->setupUi(this);
    //ui->lineEdit->setEnabled(false);
    //ui->toolButton_Add->setEnabled(false);
    ui->lineEdit->hide();
    ui->toolButton_Add->hide();

    toolButton = nullptr;
    delete ui->buttonBox;

    create_TagsForOpenFile();
}

Dialog_Tag::~Dialog_Tag()
{
    delete ui;
}

void Dialog_Tag::create_Tags()
{

    //Hole dir die ProjectID vom aktuellen Project
    //QString string_ProjectID = database->get_ProjectID(project->get_ProjectName(),
    //                                                   project->get_ProjectClamping());

    //lade alle Tags aus der Datenbank
    QStringList strList = database->get_Tags();

    //lade nur die Tags von dem aktuellen Projekt aus der Datenbank
    QStringList stringList_Tags = database->get_Tags(projectData->id);

    //füge alle Tags in ListWdiget_Tags ein
    ui->listWidget_Tags->addItems(strList);

    // Geh durch alle Tags und vergleiche sie mit den Tags der aktuellen Projekts
    // Wenn sie gleich sind wird der Tag angehackt
    QListWidgetItem* item = 0;
    for(int i = 0; i < ui->listWidget_Tags->count(); ++i)
    {
        item = ui->listWidget_Tags->item(i);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
        if(stringList_Tags.contains(item->text()))
        {
            item->setCheckState(Qt::Checked);
            item->setForeground(Qt::darkYellow);
        }
    }

    // Ändert sich der Zustand eines Items, wird der SLOT highlightCheckd aufgerufen
    connect(ui->listWidget_Tags, SIGNAL(itemChanged(QListWidgetItem*)),
                     this, SLOT(highlightChecked(QListWidgetItem*)));
}

void Dialog_Tag::create_TagsForOpenFile()
{ 
    QStringList strList = database->get_Tags();                     //lade alle Tags aus der Datenbank
    ui->listWidget_Tags->addItems(strList);                         //füge alle Tags in ListWdiget_Tags ein

    QListWidgetItem* item = 0;
    for(int i = 0; i < ui->listWidget_Tags->count(); ++i)           //Gehe durch alle Tags
    {
        item = ui->listWidget_Tags->item(i);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);    //Versehe den Tag mit einer CheckBox
        item->setCheckState(Qt::Unchecked);                         //Der Tag ist nicht angeclickt
    }

    // Ändert sich der Zustand eines Items, wird der SLOT highlightCheckd aufgerufen
    connect(ui->listWidget_Tags, SIGNAL(itemChanged(QListWidgetItem*)),
            this, SLOT(slot_TagHighlighted(QListWidgetItem*)));
}

void Dialog_Tag::slot_NewTag()
{
    QString string_Tag = ui->lineEdit->text();
    if(string_Tag.isEmpty())
        return;

    ui->listWidget_Tags->addItem(string_Tag);
    QListWidgetItem* item;
    item = ui->listWidget_Tags->item(ui->listWidget_Tags->count() - 1);
    item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
    item->setCheckState(Qt::Unchecked);
}

void Dialog_Tag::highlightChecked(QListWidgetItem* item)
{

    static bool blockFunction = false;
    if(blockFunction)
       return;

    blockFunction = true;
    if(item->checkState() == Qt::Checked)
    {
        //item->setForeground(Qt::darkYellow);
        item->setForeground(QBrush(QColor(128,128,192)));
        projectData->listTags.append(item->text());
    }
    else
    {
        item->setForeground(Qt::gray);
        projectData->listTags.removeOne(item->text());
    }

    if(projectData->listTags.isEmpty())
        toolButton->startAnimation();
    else
        toolButton->stopAnimation();

    blockFunction = false;
}

void Dialog_Tag::slot_TagHighlighted(QListWidgetItem* item)
{
    static bool blockFunction = false;
    if(blockFunction)
    {
        return;
    }
    blockFunction = true;
    QStringList stringList_Projects;
    QStringList stringList_Temp;

    if(item->checkState() == Qt::Checked)
    {
        item->setForeground(Qt::darkYellow);
    }
    else
    {
        item->setForeground(Qt::white);
    }

    //Gehe durch alle Items, wenn es angehakt ist lade alle Projecte zu dem Tag
    //und speicher sie in stringList_Temp;
    QListWidgetItem* item_Tag = 0;
    for(int i = 0; i < ui->listWidget_Tags->count(); ++i)
    {
        item_Tag = ui->listWidget_Tags->item(i);
        if(item_Tag->checkState() == Qt::Checked)
            stringList_Temp = stringList_Temp + database->get_ProjectFromTag(item_Tag->text());
    }

    //schreibe alle Tags in die stringList_Project, aber nicht doppelt
    foreach(QString str, stringList_Temp)
    {
        if(!stringList_Projects.contains(str))
        {
            stringList_Projects.append(str);
        }
    }

    if(stringList_Projects.isEmpty())
    {
        emit sig_NoTagsSelected();
    }
    else
    {
        emit sig_NewProjectList(stringList_Projects);
    }

    if(toolButton == nullptr)
    {
        blockFunction = false;
        this->close();
        return;
    }

    if(projectData->listTags.isEmpty())
        toolButton->startAnimation();
    else
        toolButton->stopAnimation();
    blockFunction = false;

    qDebug() << Q_FUNC_INFO << "End";
}
