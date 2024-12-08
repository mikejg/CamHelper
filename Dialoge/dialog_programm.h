#ifndef DIALOG_PROGRAMM_H
#define DIALOG_PROGRAMM_H

#include <QDialog>
#include "../Model/programmmodel.h"
#include "../Project/project.h"

namespace Ui {
class Dialog_Programm;
}

class Dialog_Programm : public QDialog
{
    Q_OBJECT

private:
    Ui::Dialog_Programm *ui;
    Project* project;
    ProgrammModel* programmModel;

public:
    explicit Dialog_Programm(QWidget *parent = nullptr, Project *p = nullptr);
    ~Dialog_Programm();
};

#endif // DIALOG_PROGRAMM_H
