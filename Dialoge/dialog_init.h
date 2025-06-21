#ifndef DIALOG_INIT_H
#define DIALOG_INIT_H

#include <QWidget>
#include "../Classes/struct.h"

namespace Ui {
class Dialog_Init;
}

class Dialog_Init : public QWidget
{
    Q_OBJECT

public:
    explicit Dialog_Init(QWidget *parent = nullptr);
    ~Dialog_Init();
    void set_Pictures(QList<ProjectData>);

private:
    Ui::Dialog_Init *ui;

signals:
    void sig_Clicked(QString);
};

#endif // DIALOG_INIT_H
