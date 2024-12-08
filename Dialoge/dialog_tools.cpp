#include "dialog_tools.h"
#include "ui_dialog_tools.h"
#include <QPushButton>
#include <QToolButton>

Dialog_Tools::Dialog_Tools(QWidget *parent, Project* p) :
    QDialog(parent),
    ui(new Ui::Dialog_Tools)
{
    project = p;
    ui->setupUi(this);
    ui->tableView_Tools->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    //erzeuge ein neues ToolModel
    toolModel = new ToolModel();
    ui->tableView_Tools->setItemDelegateForColumn(2, &delegate);

    //Überge dem ToolModel die ToolList
    toolModel->populateData(project->get_ToolList());
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

    ToolList* toolList = project->get_ToolList();
    toolList->delete_Tool(int_OldRow);
    toolModel->delete_Tool(int_OldRow);
    int_OldRow = 0;

    emit project->sig_NewToolList();
}

void Dialog_Tools::refresh()
{
    ToolList* toolList;
    toolList = project->get_ToolList();
    toolList->sort_ID();

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
