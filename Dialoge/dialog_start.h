#ifndef DIALOG_START_H
#define DIALOG_START_H

#include <QDialog>

namespace Ui {
class Dialog_Start;
}

class Dialog_Start : public QDialog
{
    Q_OBJECT
private:
    Ui::Dialog_Start *ui;

public:
    explicit Dialog_Start(QWidget *parent = nullptr);
    ~Dialog_Start();

signals:
    void sig_NewClicked();
    void sig_CheckFiles();
    void sig_OpenProject();
};

#endif // DIALOG_START_H
