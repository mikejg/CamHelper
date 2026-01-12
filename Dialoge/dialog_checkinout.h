#ifndef DIALOG_CHECKINOUT_H
#define DIALOG_CHECKINOUT_H

#include <QProgressDialog>
#include "../Classes/copier.h"

class Dialog_CheckInOut : public QProgressDialog
{
    Q_OBJECT
private:
    Copier* copier;

public:
    Dialog_CheckInOut(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    void set_Copier(Copier* c);

public slots:
    void slot_FileName(QString);
    void slot_Finished(bool);
    void slot_SetValue(int);
};

#endif // DIALOG_CHECKINOUT_H
