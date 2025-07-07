#ifndef DIALOG_RAWPARTINSPECTION_H
#define DIALOG_RAWPARTINSPECTION_H

#include <QDialog>
#include "../Project/project.h"

namespace Ui {
class Dialog_RawPartInspection;
}

class Dialog_RawPartInspection : public QDialog
{
    Q_OBJECT
private:
    Ui::Dialog_RawPartInspection *ui;

public:
    explicit Dialog_RawPartInspection(QWidget *parent = nullptr);
    ~Dialog_RawPartInspection();

public slots:
    void slot_Selected();

signals:
    void sig_NewInspection(QString);
};

#endif // DIALOG_RAWPARTINSPECTION_H
