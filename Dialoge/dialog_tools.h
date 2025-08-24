#ifndef DIALOG_TOOLS_H
#define DIALOG_TOOLS_H

#include <QDialog>
#include "../Model/toolmodel.h"
#include "../Classes/struct.h"
#include "../Model/spinboxdelegate.h"

namespace Ui {
class Dialog_Tools;
}

class Dialog_Tools : public QDialog
{
    Q_OBJECT

private:
    Ui::Dialog_Tools *ui;
    ProjectData* projectData;
    ToolModel* toolModel;
    SpinBoxDelegate delegate;
    int int_OldRow;

public:
    explicit Dialog_Tools(QWidget *parent = nullptr, ProjectData *pd = nullptr);
    ~Dialog_Tools();
    void refresh();
signals:
    void sig_NewToolList();

public slots:
    void slot_Clicked(QModelIndex);
    void slot_DeleteTool();
};

#endif // DIALOG_TOOLS_H
