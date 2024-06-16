#include "dialog_open.h"
#include "ui_dialog_open.h"

Dialog_Open::Dialog_Open(QWidget *parent,Logging* l, DataBase* db) :
    QDialog(parent),
    ui(new Ui::Dialog_Open)
{
    ui->setupUi(this);
    dataBase = db;
    logging = l;

    dialog_Tag = new Dialog_Tag(this, db);

    connect(this, SIGNAL(accepted()), this, SLOT(slot_accepted()));
    connect(ui->lineEdit_Project, SIGNAL(textChanged(QString)), this, SLOT(slot_TextChanged(QString)));
    connect(ui->listView_Project, SIGNAL(clicked(QModelIndex)), this, SLOT(slot_Clicked(QModelIndex)));
    connect(ui->toolButton_Tags, SIGNAL(released()), this, SLOT(slot_TagsClicked()));
    connect(dialog_Tag, SIGNAL(sig_NewProjectList(QStringList)), this, SLOT(slot_NewProjectList(QStringList)));
    connect(dialog_Tag, SIGNAL(sig_NoTagsSelected()), this, SLOT(slot_NoTagsSelected()));
}

Dialog_Open::~Dialog_Open()
{
    delete ui;
}

void Dialog_Open::slot_NoTagsSelected()
{
    //Lade alle Projekte aus der Datenbank in stringList_Projects
    stringList_Projects = dataBase->get_Project();
    //erstelle eine Kopie von stringList_Projects
    stringList_Model = stringList_Projects;

    //erstelle eine neues QStringListModel und
    //befülle es mit stringList_Model
    model->setStringList(stringList_Model);
}

void Dialog_Open::slot_ShowDialog()
{
    //Lade alle Projekte aus der Datenbank in stringList_Projects
    stringList_Projects = dataBase->get_Project();
    //erstelle eine Kopie von stringList_Projects
    stringList_Model = stringList_Projects;

    //erstelle eine neues QStringListModel und
    //befülle es mit stringList_Model
    model = new QStringListModel(this);
    model->setStringList(stringList_Model);

    //Übergebe das Model dem listView_Project
    ui->listView_Project->setModel(model);

    this->show();
}

void Dialog_Open::slot_accepted()
{
    QModelIndex index = ui->listView_Project->currentIndex();
    QString itemText = index.data(Qt::DisplayRole).toString();
    QStringList stringList;

    //Teile den String am Unterstrich für das Project und die Spannung
    // E69101001_Sp2
    stringList = itemText.split("_");
    if(stringList.size() == 2)
        sig_LoadProject(stringList.at(0), stringList.at(1));

}

void Dialog_Open::slot_TextChanged(QString str)
{
    //erstelle eine Kopie von stringList_Projects
    stringList_Model = stringList_Projects;
    foreach(QString string, stringList_Model)
    {
        if(!string.startsWith(str))
            stringList_Model.removeOne(string);
    }

    model->setStringList(stringList_Model);
}

void Dialog_Open::slot_Clicked(QModelIndex index)
{
    QString itemText = index.data(Qt::DisplayRole).toString();
    QStringList stringList;
    Item_Project itemProject;
    QList<QPixmap> picList;
    //Teile den String am Unterstrich für das Project und die Spannung
    // E69101001_Sp2
    stringList = itemText.split("_");
    if(stringList.size() == 2)
    {
        //Lade alle Daten des Projects, uns interessiert nur die DatenBank ID
        itemProject = dataBase->get_Project(stringList.at(0), stringList.at(1));

        //Lade alle Bilder aus dem Project
        picList = dataBase->get_Pixmap(itemProject.id);

        if(picList.size() > 0)
        {
            ui->label->setPixmap(picList.at(0));
        }
    }
}

void Dialog_Open::slot_TagsClicked()
{
    dialog_Tag->show();
}

void Dialog_Open::slot_NewProjectList(QStringList stringList)
{
    model->setStringList(stringList);
}
