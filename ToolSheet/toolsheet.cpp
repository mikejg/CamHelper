#include "toolsheet.h"
#include "ui_toolsheet.h"

ToolSheet::ToolSheet(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ToolSheet)
{
    ui->setupUi(this);
    ui->tableView_ToolSheet->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    toolList_IN      = new ToolList(this);
    toolList_OUT     = new ToolList(this);
    toolList_Project = new ToolList(this);

    bool_PrintIn         = true;
    bool_PrintOut        = true;
    bool_PrintProject    = true;

}

ToolSheet::~ToolSheet()
{
    delete ui;
}

void ToolSheet::printTable()
{
    QPrintPreviewDialog dialogPrint;
    dialogPrint.setWindowTitle("Drucken");
    dialogPrint.setWindowIcon(QIcon(":/Icons/Main/print2.png"));
    connect(&dialogPrint, SIGNAL(paintRequested(QPrinter*)), this, SLOT(slot_PrintPage(QPrinter*)));
    connect(&dialogPrint, SIGNAL(finished(int)), this, SIGNAL(sig_DialogPrintFinished(int)));
    dialogPrint.exec();
}

void ToolSheet::set_DataBase(DataBase *db)
{
    dataBase = db;
    toolList_Top100 = new ToolList(this);       //erstelle eine leere Liste der meist benutzten Werkzeuge
    dataBase->get_Top100(toolList_Top100);      //befülle die Liste der meist benutzen Werkzeuge
}

void ToolSheet::showTable(ProjectData pd, bool bool_Print)
{
    projectData = pd;

    toolList_IN->clear();
    toolList_OUT->clear();
    toolList_Project->clear();

    list_ToolNumber.clear();
    list_ToolDescription.clear();
    list_GageLength.clear();
    list_ToolLength.clear();
    list_TipLength.clear();
    list_Counter.clear();

    int_Projects_Size = projectData.toolList->get_Size();   //Hol dir die Anzahl der benötigten Werkzeuge
    int_In_Size       = 0;
    int_Out_Size      = 0;
    int_Free_Size     = 0;
    int_Counter       = 0;

    //Kopiere die ToolList aus dem Projekt in toolList_Table
    //sortiere toolList_Table nach der Tool_Nummer
    foreach(Tool* tool, projectData.toolList->get_List())
        toolList_Project->insert_Tool(tool);
    toolList_Project->sort_Number();

    foreach(Tool* tool, toolList_Project->get_List())           //Geh durch alle Werkzeuge für das Project
    {
        if(!magazin->contains(tool))                            //Wenn das Werkzeug nicht im Magazin ist
            toolList_IN->insert_Tool(tool);                     //Füge das Werkzeug in die Lister der zu rüstenden Werkzeuge ein
    }
    int_In_Size = toolList_IN->get_Size();                      //Speicher die Anzahl zu rüstenden Werkzeuge in int_In_Size

    foreach(Tool* tool, magazin->get_ToolList()->get_List())    //Geh durch alle Werkzeuge im Magazin
    {
        if(!toolList_Top100->contains(tool) &&                  //Wenn das Werkzeug NICHT unter den Top 100 ist
            !toolList_Project->contains(tool) &&                //Wenn das Werkzeug NICHT für das Projekt gebraucht wird
            tool->get_State() == Tool::In)                      //Wenn das Werkzeug im Magazin ist
            toolList_OUT->insert_Tool(tool);                    //Dann füge das Werkzeug in die Liste auszulagernden Werkzeuge ein
    }
    toolList_OUT->sort_Counter();                               //Sortiere die Liste wie häuffig das Werkzeug benutzt wurde
    int_Out_Size = toolList_OUT->get_Size();                    //Speich die Anzahl auszulagernden Werkzeuge in int_Out_Size

    /* Wenn bool_Print = false ODER bool_PrintProject = true
     * dann wird die Kopfzeile für das Projekt angezeig.
     * Das bedeutet, wenn ein Druckauftrag ansteht und das Projekt
     * ausgebledet werden soll wird die Kopfzeile ignoriert */
    if(!bool_Print || bool_PrintProject)
    {
        //erzeuge erste Zeile mit ProjektNamen und Anzahl der verwendeten Werkzeuge
        list_ToolDescription.append(QString(projectData.name + "_" +
                                            projectData.state+ "_" +
                                            projectData.tension + "  %1 Werkzeuge").arg(int_Projects_Size));
        list_ToolNumber.append(" ");
        list_GageLength.append(" ");
        list_ToolLength.append(" ");
        list_TipLength.append(" ");
        list_Counter.append(" ");
    }

    /* Zeige die Werkzeuge für das Projekt nur an wenn bool_PrintProject = true
     * bool_PrintProject wird im slot_TableClicked(const QModelIndex &)
     * gesteuert. Wenn man auf die Kopfzeile klickt wird bool_PrintProject
     * umgeschalten */
    if(bool_PrintProject)
    {
        //Füge die Werkzeuge ein
        foreach(Tool* tool, toolList_Project->get_List())
        {
            int_Counter++;
            list_Counter.append(QString("%1").arg(int_Counter));
            list_ToolDescription.append(tool->get_Description());
            list_ToolNumber.append(tool->get_Number());
            list_GageLength.append(tool->get_GageLength());
            list_ToolLength.append(tool->get_ToolLength());
            list_TipLength.append(tool->get_TipLength());
        }

        //erzeuge eine Leerzeile
        list_ToolDescription.append(" ");
        list_ToolNumber.append(" ");
        list_GageLength.append(" ");
        list_ToolLength.append(" ");
        list_TipLength.append(" ");
        list_Counter.append(" ");
    }

    /* Dokumentation Siehe oben
     * if(!bool_Print || bool_PrintProject) */
    if(!bool_Print || bool_PrintIn)
    {
        //erzeuge eine Zeile: 10 Werkzeuge EINLAGERN - 15 Freie Plätze im Magazin"
        int_Free_Size = int_MagazineCapacity - magazin->get_Size();

        list_ToolDescription.append(QString("  %1 Werkzeuge EINLAGERN  -  %2 Frei Plätze im Magazin").arg(int_In_Size).arg(int_Free_Size));
        list_ToolNumber.append(" ");
        list_GageLength.append(" ");
        list_ToolLength.append(" ");
        list_TipLength.append(" ");
        list_Counter.append(" ");
    }

    /* Dokumentation Siehe oben
     * if(bool_PrintProject) */
    if(bool_PrintIn)
    {
        //Füge alle Werkzeuge aus der toolList_IN ein
        foreach(Tool* tool, toolList_IN->get_List())
        {
            int_Counter++;
            list_Counter.append(QString("%1").arg(int_Counter));
            list_ToolDescription.append(tool->get_Description());
            list_GageLength.append(tool->get_GageLength());
            list_ToolLength.append(tool->get_ToolLength());
            list_TipLength.append(tool->get_TipLength());

            //qDebug() << tool->get_Number() << ": " << tool->get_State();
            if(tool->get_State() == Tool::Disassembled)
            {
                list_ToolNumber.append(tool->get_Number() + "_X");
            }
            else
                list_ToolNumber.append(tool->get_Number());
        }

        //erzeuge eine Leerzeile
        list_ToolDescription.append(" ");
        list_ToolNumber.append(" ");
        list_GageLength.append(" ");
        list_ToolLength.append(" ");
        list_TipLength.append(" ");
        list_Counter.append(" ");
    }

    /* Dokumentation Siehe oben
     * if(!bool_Print || bool_PrintProject) */
    if(!bool_Print || bool_PrintOut)
    {
        //erzeuge eine Zeile: 15 Werkzeuge Auslagen
        list_ToolDescription.append(QString("  %1 Werkzeuge AUSLAGERN ").arg(int_Out_Size));
        list_ToolNumber.append(" ");
        list_GageLength.append(" ");
        list_ToolLength.append(" ");
        list_TipLength.append(" ");
        list_Counter.append(" ");
    }

    /* Dokumentation Siehe oben
     * if(bool_PrintProject) */
    if(bool_PrintOut)
    {
        //Füge alle Werkzeuge aus der toolList_Out ein
        foreach(Tool* tool, toolList_OUT->get_List())
        {
            int_Counter++;
            list_Counter.append(QString("%1").arg(int_Counter));
            list_ToolDescription.append(tool->get_Description());
            list_ToolNumber.append(tool->get_Number());
            list_GageLength.append(tool->get_GageLength());
            list_ToolLength.append(tool->get_ToolLength());
            list_TipLength.append(QString("%1").arg(tool->get_Counter()));
        }
    }

    toolSheet_Model = new ToolSheet_Model(this);
    // Populate model with data:
    toolSheet_Model->populateData(list_ToolNumber,
                                  list_ToolDescription,
                                  list_GageLength,
                                  list_ToolLength,
                                  list_TipLength,
                                  list_Counter);

    if(!bool_Print)
    {
        ui->tableView_ToolSheet->setModel(toolSheet_Model);
    }
}

void ToolSheet::slot_PrintPage(QPrinter *printer)
{
    showTable(projectData, true);
    QPainter painter;
    if(!painter.begin(printer))
    {
        qDebug() << Q_FUNC_INFO << ("cant start printer");
        //logging->warning( "can't start printer");
        return;
    }
    // print table
    TablePrinter tablePrinter(&painter, printer);
    QVector<int> columnStretch = QVector<int>() << 2 << 5 << 3 << 2 << 2 << 20;
    QVector<QString> columnHeaders = QVector<QString>() << "Nr" << "Tool ID" << "GL" << "AL" << "FL" << "Beschreibung";
    //if(!tablePrinter.printTable(ui->tableView_Rustplan->model(), columnStretch, columnHeaders))
    if(!tablePrinter.printTable(toolSheet_Model, columnStretch, columnHeaders))
    {
        qDebug() << Q_FUNC_INFO << tablePrinter.lastError();
    }
    painter.end();
    //qDebug() << "Start: " << Q_FUNC_INFO;
}
