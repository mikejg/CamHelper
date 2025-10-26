#ifndef DIALOG_SAVE_H
#define DIALOG_SAVE_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class Dialog_Save;
}

class Dialog_Save : public QDialog
{
    Q_OBJECT

private:
    Ui::Dialog_Save *ui;

public:
    explicit Dialog_Save(QWidget *parent = nullptr);
    ~Dialog_Save();

public slots:
    void slot_Clicked(QAbstractButton* );

signals:
    void discard();
};

#endif // DIALOG_SAVE_H
