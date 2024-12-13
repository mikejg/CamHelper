#ifndef DIALOG_TOOLS_H
#define DIALOG_TOOLS_H

#include <QDialog>
#include "../Project/project.h"
#include "../Model/toolmodel.h"
#include "../Model/spinboxdelegate.h"

namespace Ui {
class Dialog_Tools;
}

class Dialog_Tools : public QDialog
{
    Q_OBJECT

private:
    Ui::Dialog_Tools *ui;
    Project* project;
    ToolModel* toolModel;
    SpinBoxDelegate delegate;
    int int_OldRow;

public:
    explicit Dialog_Tools(QWidget *parent = nullptr, Project *p = nullptr);
    ~Dialog_Tools();
    void refresh();

public slots:
    void slot_Clicked(QModelIndex);
    void slot_DeleteTool();
};

#endif // DIALOG_TOOLS_H
