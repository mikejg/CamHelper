#ifndef DIALOGSETTINGS_H
#define DIALOGSETTINGS_H

#include <QDebug>
#include <QDialog>
#include <QFileDialog>
#include <QVBoxLayout>
#include "../logging.h"
#include "../settings.h"

namespace Ui {
class Dialog_Settings;
}

class Dialog_Settings : public QDialog
{
    Q_OBJECT

private:
    Ui::Dialog_Settings *ui;
    Settings* settings;
    QFileDialog* fileDialog;
    QPalette* paletteInValid;
    QPalette* paletteValid;
    bool send_SettingOK;
    Logging* log;

public:

    explicit Dialog_Settings(QWidget *parent = nullptr, Logging* l = nullptr);
    ~Dialog_Settings();

    void set_Settings(Settings* s);
    bool checkSettings();

signals:
    void sig_Genarete_MPF();
    void settingsOK();

public slots:
    void writeSettings();
    void toolButton_Programme_clicked(bool);
    void toolButton_Magazin_clicked(bool);
    void toolButton_WerkzeugDB_clicked(bool);
};

#endif // DIALOGSETTINGS_H
