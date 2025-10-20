#include "dialog_toolsearch.h"
#include "ui_dialog_toolsearch.h"

Dialog_ToolSearch::Dialog_ToolSearch(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_ToolSearch)
{
    ui->setupUi(this);

}

Dialog_ToolSearch::Dialog_ToolSearch(QWidget *parent, DataBase *db)
    : QDialog(parent)
    , ui(new Ui::Dialog_ToolSearch)
{
    ui->setupUi(this);
    dataBase = db;
    stringList_Tools = dataBase->get_Tools();
    ui->listWidget_Tools->addItems(stringList_Tools);

    connect(ui->listWidget_Tools, SIGNAL(currentTextChanged(QString)),
            this, SLOT(slot_CurrentTextChanged(QString)));
    connect(ui->lineEdit, SIGNAL(textEdited(QString)), this, SLOT(slot_textEdited(QString)));
}

Dialog_ToolSearch::~Dialog_ToolSearch()
{
    delete ui;
}

void Dialog_ToolSearch::slot_CurrentTextChanged(QString string_TNumber)
{
    QStringList stringList;

    stringList = dataBase->get_ProjectList(string_TNumber);
    emit sig_NewProjectList(stringList);
}

void Dialog_ToolSearch::slot_textEdited(QString str)
{
    //qDebug() << "str: " << str.length();
    QString string;
    if(str.length() < string_old.length())
    {
        string_old = ui->lineEdit->text();
        stringList_Temp.clear();
        foreach(QString str, stringList_Tools)
        {
            if(str.startsWith(string_old))
                stringList_Temp.append(str);
        }
        ui->listWidget_Tools->clear();
        ui->listWidget_Tools->addItems(stringList_Temp);
        return;
    }

    if(str.length() > 2 && !str.contains("_"))
    {
        string = ui->lineEdit->text();
        string = string.insert(2,"_");
        ui->lineEdit->setText(string);
    }

    if(str.length() > 6 && str.at(6) != QString("_"))
    {
        string = ui->lineEdit->text();
        string = string.insert(6,"_");
        ui->lineEdit->setText(string);
    }
    string_old = ui->lineEdit->text();
    stringList_Temp.clear();
    foreach(QString str, stringList_Tools)
    {
        if(str.startsWith(string_old))
            stringList_Temp.append(str);
    }
    ui->listWidget_Tools->clear();
    ui->listWidget_Tools->addItems(stringList_Temp);
}
