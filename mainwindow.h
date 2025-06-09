#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "Dialoge/dialog_settings.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    Dialog_Settings *dialog_Settings;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void slot_InitApp();

};
#endif // MAINWINDOW_H
