#include "toolsheet.h"
#include "ui_toolsheet.h"

ToolSheet::ToolSheet(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ToolSheet)
{
    ui->setupUi(this);

    toolList_IN      = new ToolList(this);
    toolList_OUT     = new ToolList(this);
    toolList_Project = new ToolList(this);

}

ToolSheet::~ToolSheet()
{
    delete ui;
}

void ToolSheet::showTable(ProjectData projectData, bool bool_Print)
{
    toolList_IN->clear();
    toolList_OUT->clear();
    toolList_Project->clear();

    list_ToolNumber.clear();
    list_ToolDescription.clear();
    list_GageLength.clear();
    list_ToolLength.clear();
    list_TipLength.clear();
    list_Counter.clear();

    int_Projects_Size = projectData.toolList->get_Size(); //Hol dir die Anzahl der benötigten Werkzeuge
    int_In_Size       = 0;
    int_Out_Size      = 0;
    int_Free_Size     = 0;
    int_Counter       = 0;

    //Kopiere die ToolList aus dem Projekt in toolList_Table
    //sortiere toolList_Table nach der Tool_ID
    foreach(Tool* tool, projectData.toolList->get_List())
        toolList_Project->insert_Tool(tool);
    toolList_Project->sort_Number();


}
