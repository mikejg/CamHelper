#ifndef DIALOG_LICENSEKEY_H
#define DIALOG_LICENSEKEY_H

#include <QDialog>
#include <QCryptographicHash>

namespace Ui {
class Dialog_LicenseKey;
}

class Dialog_LicenseKey : public QDialog
{
    Q_OBJECT
private:
    Ui::Dialog_LicenseKey *ui;

public:
    explicit Dialog_LicenseKey(QWidget *parent = nullptr);
    ~Dialog_LicenseKey();


public slots:
    void slot_ReturnPressed();
};

#endif // DIALOG_LICENSEKEY_H
