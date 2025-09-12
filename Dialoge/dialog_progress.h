#ifndef DIALOGPROGRESS_H
#define DIALOGPROGRESS_H
#include <QVBoxLayout>
#include <QDialog>
#include <QTimer>
#include <QDir>
#include <QProgressBar>
#include "../Classes/struct.h"

namespace Ui {
class Dialog_Progress;
}

class Dialog_Progress : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Progress(QWidget *parent = nullptr);
    ~Dialog_Progress();
    void set_Value(QString, int);
    void set_Maximum(int i);
    void init_Dialog(QList<Programm>);

private:
    Ui::Dialog_Progress *ui;

public slots:

signals:
    void sig_Finished();
};

#endif // DIALOGWRITE_H
