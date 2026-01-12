#include "dialog_licensekey.h"
#include "ui_dialog_licensekey.h"

Dialog_LicenseKey::Dialog_LicenseKey(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_LicenseKey)
{
    ui->setupUi(this);

    ui->lineEdit->setEchoMode(QLineEdit::Password);
    connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(slot_ReturnPressed()));
}

Dialog_LicenseKey::~Dialog_LicenseKey()
{
    delete ui;
}

void Dialog_LicenseKey::slot_ReturnPressed()
{
    QString dataToHash = ui->lineEdit->text();

    // 1. Initialisiere die Hash-Klasse mit dem MD5-Algorithmus
    QCryptographicHash hash(QCryptographicHash::Md5);

    // 2. Füge die Daten hinzu. QCryptographicHash arbeitet mit QByteArray.
    // Daher muss der QString in QByteArray (z.B. mittels UTF-8 Kodierung) umgewandelt werden.
    hash.addData(dataToHash.toUtf8());

    // 3. Berechne den finalen Hash-Wert als QByteArray
    QByteArray md5HashByteArray = hash.result();

    // 4. Konvertiere den QByteArray-Hash in eine lesbare Hexadezimal-Darstellung (QString)
    QString md5HashString = md5HashByteArray.toHex();

    if(md5HashString == "07fc15c9d169ee48573edd749d25945d")
    {
        emit accept();
        this->close();
    }
    else
    {
        ui->lineEdit->clear();
    }
}
