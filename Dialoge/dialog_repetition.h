#ifndef DIALOGREPETITION_H
#define DIALOGREPETITION_H

#include <QDialog>
#include <QRadioButton>

namespace Ui {
class Dialog_Repetition;
}

class Dialog_Repetition : public QDialog
{
    Q_OBJECT

private:
    Ui::Dialog_Repetition *ui;

public:
    explicit Dialog_Repetition(QWidget *parent = nullptr);
    ~Dialog_Repetition();

    QRadioButton* radioButton_Repetition;
    QRadioButton* radioButton_Paket;
    void set_LastProduction(QString);
};

#endif // DIALOGREPETITION_H
