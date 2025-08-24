#include "magazin.h"
#include "ui_magazin.h"

Magazin::Magazin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Magazin)
{
    ui->setupUi(this);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->verticalHeader()->hide();

    mfile = new MFile(this);

    connect(ui->lineEdit, SIGNAL(textEdited(QString)), this, SLOT(slot_textEdited(QString)));
    connect(ui->tableView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(slot_TableClicked(const QModelIndex &)));

    toolList = new ToolList(this);
    searchList = new ToolList(this);

    QPalette palette;
    text_Color = QColor(128,128,128);
    palette.setColor(QPalette::Highlight, ui->tableView->palette().color(QPalette::Base));
    //palette.setColor(QPalette::Highlight, QColor(128,128,192));
    palette.setColor(QPalette::HighlightedText, ui->tableView->palette().color(QPalette::Text));
    palette.setColor(QPalette::Text,text_Color);
    ui->tableView->setPalette(palette);
    connect(&fileSystemWatcher, SIGNAL(fileChanged(QString)), this, SLOT(slot_MagazinChanged(QString)));
}

Magazin::~Magazin()
{
    delete ui;
}

bool Magazin::contains(Tool* tool)
{
    foreach (Tool* toolList_Tool, toolList->get_List())
    {
        if(tool->get_Number() == toolList_Tool->get_Number()
            && toolList_Tool->get_State() == 0)
        {
            return true;
        }

        if(toolList_Tool->get_Number().contains(tool->get_Number()) &&
            toolList_Tool->get_State() == Tool::Disassembled)
            tool->set_State(Tool::Disassembled);
    }

    return false;
}

void Magazin::contains(QString str, ToolList* list)
{
    searchList->clear();
    foreach (Tool* tool, toolList->get_List())
    {
        if(tool->get_Number().startsWith(str))
            list->insert_Tool(tool, false);
    }
}

bool Magazin::create_ToolList()
{
    QStringList stringList_ToolData;
    sizeIn = 0;

    if(!mfile->read_Content())
        return false;

    toolList->clear();
    QString string_ToolID;
    QString string_Temp;
    bool bool_X;
    Tool* tool = new Tool(this);
    foreach(QString string_Line, mfile->get_Content())
    {
        bool_X = false;
        /* Wenn string_Line mit $TC_TP2 startet
         * schneide solage von Links ein Zeichen ab bis du auf ein " stoesst
         * entferne am ende das "
         * schreibe den uebrig gebliebenen string_Line in string_ToolID
         * */
        if(string_Line.startsWith("$TC_TP2"))
        {
            while(!string_Line.startsWith("\"") && string_Line.size() > 0)
            {
                string_Line = string_Line.right(string_Line.length()-1);
            }
            string_Line.remove("\"");
            string_ToolID=string_Line;
        }

        /* Wenn string_Line mit $A_TOOLMN startet
         * schneide solage von Links ein Zeichen ab bis du auf ein = stoesst
         * entferne am Ende das =
         * Wenn string_Line nicht leer ist und string_Line nicht 0 ist
         * erstelle das Tool und schreibe ist in die toolList */

        if(string_Line.startsWith(";$A_TOOLMN"))
        {
            while(!string_Line.startsWith("=") && string_Line.size() > 0)
            {
                string_Line = string_Line.right(string_Line.length()-1);
            }
            string_Line.remove("=");

            if(!string_Line.isEmpty() && string_Line != "0")
            {
                tool->set_State(Tool::In);
                sizeIn++;
            }
            else
            {
                tool->set_State(Tool::Out);
            }

            if(string_ToolID.contains("X") || string_ToolID.contains("x"))
            {
                tool->set_State(Tool::Disassembled);
                bool_X = true;
                string_ToolID = string_ToolID.remove("_X");
                string_ToolID = string_ToolID.remove("_x");
            }
            if(string_ToolID.contains("_"))
            {
                stringList_ToolData = dataBase->get_ToolData(string_ToolID);
                if(stringList_ToolData.size() < 5)
                {
                    log->warning("Unvollstandige Tooldaten: " + string_ToolID);
                    continue;
                }
                tool->clear();
                tool->set_Number(string_ToolID);
                tool->set_Description(stringList_ToolData.at(3));
                //tool->set_Description(dbManager->getDescription(string_ToolID));

                string_Temp = stringList_ToolData.at(1);
                if(string_Temp.length() > 7)
                    string_Temp = string_Temp.left(7);
                tool->set_ToolLength(string_Temp);

                string_Temp = stringList_ToolData.at(2);
                if(string_Temp.length() > 7)
                    string_Temp = string_Temp.left(7);
                tool->set_TipLength(string_Temp);

                string_Temp = stringList_ToolData.at(0);
                if(string_Temp.length() > 7)
                    string_Temp = string_Temp.left(7);
                tool->set_GageLength(string_Temp);

                string_Temp = stringList_ToolData.at(4);
                if(string_Temp.length() > 7)
                    string_Temp = string_Temp.left(7);
                tool->set_CutLength(string_Temp);

                if(bool_X)
                    string_ToolID += "_X";
                tool->set_Number(string_ToolID);

                toolList->insert_Tool(tool, false);
            }
        }
    }

    foreach (tool, toolList->get_List())
    {
        tool->set_Counter(dataBase->get_Counter(tool->get_Number()));
    }

    showToolList(toolList);
    return true;
}

void Magazin::showToolList(ToolList* list)
{
    list->sort_Number();
    list_ToolID.clear();
    list_ToolDescription.clear();
    list_GageLength.clear();
    list_ToolLength.clear();
    list_TipLength.clear();
    list_ToolState.clear();
    list_CutLength.clear();

    //Füge die Werkzeuge ein
    foreach(Tool* tool, list->get_List())
    {
        list_ToolDescription.append(tool->get_Description());
        list_ToolID.append(tool->get_Number());
        list_GageLength.append(tool->get_GageLength());
        list_ToolLength.append(tool->get_ToolLength());
        list_TipLength.append(tool->get_TipLength());
        list_ToolState.append(tool->get_StateString());
        list_CutLength.append(tool->get_CutLength());
    }

    tableModel = new MagazinModel(this);

    // Populate model with data:
    tableModel->populateData(list_ToolID,
                             list_ToolDescription,
                             list_GageLength,
                             list_ToolLength,
                             list_TipLength,
                             list_ToolState,
                             list_CutLength);

    ui->tableView->setModel(tableModel);

}

void Magazin::slot_TableClicked(const QModelIndex &modelIndex)
{
    QPalette palette;

    if(list_ToolState[modelIndex.row()] == "In")
    {
        //palette.setColor(QPalette::Highlight, ui->tableView->palette().color(QPalette::Base));
        palette.setColor(QPalette::Highlight, QColor(128,128,192));
        palette.setColor(QPalette::HighlightedText, Qt::green);
        palette.setColor(QPalette::Text,text_Color);
    }
    else if(list_ToolState[modelIndex.row()] == "Out")
    {
        palette.setColor(QPalette::Highlight, QColor(128,128,192));
        palette.setColor(QPalette::HighlightedText, Qt::yellow);
        palette.setColor(QPalette::Text, text_Color);
    }
    else if(list_ToolState[modelIndex.row()] == "Disassembled")
    {
        palette.setColor(QPalette::Highlight, QColor(128,128,192));
        palette.setColor(QPalette::HighlightedText, Qt::red);
        palette.setColor(QPalette::Text, text_Color);
    }
    else
    {
        palette.setColor(QPalette::Highlight, ui->tableView->palette().color(QPalette::Base));
        palette.setColor(QPalette::HighlightedText, ui->tableView->palette().color(QPalette::Text));
    }
    ui->tableView->setPalette(palette);
}

void Magazin::slot_textEdited(QString str)
{
    //qDebug() << "str: " << str.length();
    QString string;
    if(str.length() < string_old.length())
    {
        string_old = ui->lineEdit->text();
        contains(string_old, searchList);
        showToolList(searchList);
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

    contains(string_old, searchList);
    showToolList(searchList);
}

void Magazin::slot_MagazinChanged(QString str)
{
    disconnect(&fileSystemWatcher, SIGNAL(fileChanged(QString)), this, SLOT(slot_MagazinChanged(QString)));
    fileSystemWatcher.removePath(str);

    qDebug() << Q_FUNC_INFO << str;
    //log->message("void Magazin::slot_MagazinChanged " + str);

    //Warte 10 Sekunden bis die Daten vollständig geschrieben wurden
    std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    create_ToolList();

    //log->message("add " + str + " to QSytemFileWatcher");
    fileSystemWatcher.addPath(str);
    connect(&fileSystemWatcher, SIGNAL(fileChanged(QString)), this, SLOT(slot_MagazinChanged(QString)));
    qDebug() << Q_FUNC_INFO << "emit sig_NewMagazin()";
    emit sig_NewMagazin();
}
