#include "dialog_tools.h"
#include "ui_dialog_tools.h"
#include <QPushButton>
#include <QToolButton>

Dialog_Tools::Dialog_Tools(QWidget *parent, ProjectData* pd) :
    QDialog(parent),
    ui(new Ui::Dialog_Tools)
{
    projectData = pd;
    ui->setupUi(this);
    ui->tableView_Tools->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    //erzeuge ein neues ToolModel
    toolModel = new ToolModel();
    ui->tableView_Tools->setItemDelegateForColumn(2, &delegate);

    //Überge dem ToolModel die ToolList
    toolModel->populateData(projectData->toolList);
    //setze das ToolModel in tableView_Tools
    ui->tableView_Tools->setModel(toolModel);
    int_OldRow = 0;

    connect(ui->tableView_Tools, SIGNAL(clicked(QModelIndex)), this, SLOT(slot_Clicked(QModelIndex)));
}

Dialog_Tools::~Dialog_Tools()
{
    delete ui;
}

void Dialog_Tools::slot_Clicked(QModelIndex modelIndex)
{
    QFrame* frame = new QFrame();
    frame->setStyleSheet("background: rgba(255,255,255,0);");
    ui->tableView_Tools->setIndexWidget(ui->tableView_Tools->model()->index(int_OldRow,3 ), frame);

    QToolButton* toolButton;
    toolButton = new QToolButton();
    toolButton->setMaximumSize(60,30);
    toolButton->setIcon(QIcon(":/Icons/TouchProbe/delete.png"));

    int_OldRow = modelIndex.row();
    ui->tableView_Tools->setIndexWidget(ui->tableView_Tools->model()->index(int_OldRow,3 ), toolButton);

    connect(toolButton, SIGNAL(released()), this, SLOT(slot_DeleteTool()));
}

void Dialog_Tools::slot_DeleteTool()
{
    QFrame* frame = new QFrame();
    ui->tableView_Tools->setIndexWidget(ui->tableView_Tools->model()->index(int_OldRow,3 ), frame);
    ToolList* toolList = projectData->toolList;
    toolList->delete_Tool(int_OldRow);
    toolModel->delete_Tool(int_OldRow);
    int_OldRow = 0;

    emit sig_NewToolList();
}

void Dialog_Tools::refresh()
{
    ToolList* toolList;
    toolList = projectData->toolList;
    toolList->sort_Number();

    qDebug() << Q_FUNC_INFO;
    //erzeuge ein neues ToolModel
    toolModel = new ToolModel();
    ui->tableView_Tools->setItemDelegateForColumn(2, &delegate);

    //Überge dem ToolModel die ToolList
    toolModel->populateData(toolList);
    //setze das ToolModel in tableView_Tools
    ui->tableView_Tools->setModel(toolModel);
    int_OldRow = 0;
}
