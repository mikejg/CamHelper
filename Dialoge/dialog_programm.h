#ifndef DIALOG_PROGRAMM_H
#define DIALOG_PROGRAMM_H

#include <QDialog>
#include "../Model/programmmodel.h"
#include "../Classes/struct.h"

namespace Ui {
class Dialog_Programm;
}

class Dialog_Programm : public QDialog
{
    Q_OBJECT

private:
    Ui::Dialog_Programm *ui;
    ProjectData* projectData;
    ProgrammModel* programmModel;

public:
    explicit Dialog_Programm(QWidget *parent = nullptr, ProjectData *pd = nullptr);
    ~Dialog_Programm();

public slots:
    void slot_NewProgrammList(QList<Programm>);
};

#endif // DIALOG_PROGRAMM_H
