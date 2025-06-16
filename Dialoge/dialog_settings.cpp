#include "dialog_settings.h"
#include "ui_dialog_settings.h"

//Dialog_Settings::Dialog_Settings(QWidget *parent, Logging* l) :
Dialog_Settings::Dialog_Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Settings)
{
    //log = l;

    settings = new Settings(this);

    ui->setupUi(this);

    ui->lineEdit_ProgrammDir->set_TextNecessary(true);
    ui->lineEdit_ToolDB->set_TextNecessary(true);
    ui->lineEdit_ToolMagazin->set_TextNecessary(true);

    paletteInValid = new QPalette();
    paletteInValid->setColor(QPalette::Text,Qt::red);

    paletteValid = new QPalette();
    *paletteValid = palette();

    fileDialog = new QFileDialog(this);
    fileDialog->setFileMode(QFileDialog::Directory);
    fileDialog->setFilter(QDir::Dirs);

    bool bool_OffsetOK;
    settings->set_ProgrammDir(ui->lineEdit_ProgrammDir->text());
    settings->set_MagazinDir(ui->lineEdit_ToolMagazin->text());
    settings->set_ToolDB(ui->lineEdit_ToolDB->text());
    settings->set_ToolPlaces(ui->spinBox_WerkzeugPlatze->value());
    settings->set_OffsetX(ui->lineEdit_X->text().toFloat(&bool_OffsetOK));
    settings->set_OffsetY(ui->lineEdit_Y->text().toFloat(&bool_OffsetOK));
    settings->set_OffsetZ(ui->lineEdit_Z->text().toFloat(&bool_OffsetOK));

    ui->lineEdit_ProgrammDir->setText(settings->get_ProgrammDir());
    ui->lineEdit_ToolMagazin->setText(settings->get_MagazinDir());
    ui->lineEdit_ToolDB->setText(settings->get_ToolDB());
    ui->spinBox_WerkzeugPlatze->setValue(settings->get_ToolPlaces());
    ui->lineEdit_X->setText(QString("%1").arg(settings->get_OffsetX()));
    ui->lineEdit_Y->setText(QString("%1").arg(settings->get_OffsetY()));
    ui->lineEdit_Z->setText(QString("%1").arg(settings->get_OffsetZ()));

    connect(ui->buttonBox,              SIGNAL(accepted()),    this, SLOT(writeSettings()));
    connect(ui->toolButton_ProgrammDir, SIGNAL(clicked(bool)), this, SLOT(toolButton_ProgrammDir_clicked(bool)));
    connect(ui->toolButton_ToolMagazin, SIGNAL(clicked(bool)), this, SLOT(toolButton_ToolMagazin_clicked(bool)));
    connect(ui->toolButton_ToolDB,      SIGNAL(clicked(bool)), this, SLOT(toolButton_ToolDB_clicked(bool)));

    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(QColor(255,255,255,64)));

    this->setPalette(palette);
}

Dialog_Settings::~Dialog_Settings()
{
    delete ui;
}

void Dialog_Settings::set_Settings(Settings* s)
{
    settings = s;

    // Befuelle die Eingabenfenster mit den settings
    ui->lineEdit_ProgrammDir->setText(s->get_ProgrammDir());
    ui->lineEdit_ToolMagazin->setText(s->get_MagazinDir());
    ui->lineEdit_ToolDB->setText(s->get_ToolDB());
    ui->spinBox_WerkzeugPlatze->setValue(s->get_ToolPlaces());
    ui->lineEdit_X->setText(QString("%1").arg(s->get_OffsetX()));
    ui->lineEdit_Y->setText(QString("%1").arg(s->get_OffsetY()));
    ui->lineEdit_Z->setText(QString("%1").arg(s->get_OffsetZ()));
}

bool Dialog_Settings::checkSettings()
{
    bool bool_Return = true;
    QFile file;
    QDir dir;

    //Überprüfe ob der Pfad im Eingabefeld richtig ist
    if(ui->lineEdit_ProgrammDir->text().isEmpty() ||
        !QDir(ui->lineEdit_ProgrammDir->text()).exists())
    {
        qDebug() << Q_FUNC_INFO << "Einstellungen: Konnte Verzeichnis für Programm nicht finden";
        ui->lineEdit_ProgrammDir->set_Invalid();
        bool_Return = false;
    }
    else
        ui->lineEdit_ProgrammDir->set_Valid();
    //Wenn das Eingabefeld leer ist wird es auf rot gesetzt
    ui->lineEdit_ProgrammDir->check_Empty();

    //Überprüfe ob der Pfad im Eingabefeld richtig ist
    dir = QDir(ui->lineEdit_ToolMagazin->text());
    file.setFileName(dir.path() + "/Magazin.INI");
    if(ui->lineEdit_ToolMagazin->text().isEmpty() ||
        !dir.exists())
    {
        qDebug() << Q_FUNC_INFO << "Einstellungen: Konnte Verzeichnis für Magazin.INI nicht finden";
        ui->lineEdit_ToolMagazin->set_Invalid();
        bool_Return = false;
    }
    //Überprüfe ob das File Magazin.INI im Verzeichnis ist
    else if(!file.exists())
    {
        qDebug() << Q_FUNC_INFO << "Konnte Magazin.INI nicht finden";
        ui->lineEdit_ToolMagazin->set_Invalid();
        bool_Return = false;
    }
    else
        ui->lineEdit_ToolMagazin->set_Valid();
    //Wenn das Eingabefeld leer ist wird es auf rot gesetzt
    ui->lineEdit_ToolMagazin->check_Empty();

    //Überprüfe ob das Datenbank File existiert
    file.setFileName(ui->lineEdit_ToolDB->text());
    if (!file.exists())
    {
        qDebug() << Q_FUNC_INFO << "Einstellungen: Konnte Datenbank File nicht finden";
        ui->lineEdit_ToolDB->set_Invalid();
        bool_Return = false;
    }
    else
        ui->lineEdit_ToolDB->set_Valid();
    //Wenn das Eingabefeld leer ist wird es auf rot gesetzt
    ui->lineEdit_ToolDB->check_Empty();


    return bool_Return;
}

/*
bool Dialog_Settings::checkSettings()
{
    qDebug() << Q_FUNC_INFO;
    bool bool_Return = true;
    bool bool_OffsetOK;
    //float float_OffsetTest;
    QString string_OffsetTest;

    QFile file;
    QDir dir;

    // Überprüfe ob der Ordner im Eingabenfeld Programme existiert.
    // Wenn nicht dann setze bool_Return auf FALSE und das Eingabenfeld
    // auf ungültig.
    //Wenn der Ordner existiert setze das Eingabenfeld auf gültig.
    ui->lineEdit_ProgrammDir->check_Empty();
    dir = QDir(ui->lineEdit_ProgrammDir->text());
    if (!dir.exists())
    {
        ui->lineEdit_ProgrammDir->set_Invalid();
        bool_Return = false;
    }
    else
        ui->lineEdit_ProgrammDir->set_Valid();

    // siehe Oben mit dem Ordner Programme
    dir = QDir(ui->lineEdit_ToolMagazin->text());
    if (!dir.exists())
    {
        qDebug() << Q_FUNC_INFO << "ToolMagazin";
        ui->lineEdit_ToolMagazin->setPalette(*paletteInValid);
        bool_Return = false;
    }
    else
        ui->lineEdit_ToolMagazin->setPalette(*paletteValid);

    // Überprüfe ob das File "Magazin.INI" im Verzeichnis existiert
    // wenn das nicht der Fall ist gib eine Fehlermeldung raus und
    // setze bool_Return auf FALSE
    file.setFileName(dir.path() + "/Magazin.INI");
    if (!file.exists())
    {
        //log->error("File " + dir.path() + "/Magazin.INI" +
        //             " konnte nicht gefunden werden");
        bool_Return = false;
    }

    // Überprüfe ob die Vorlagen für die Hauptprogramme existieren
    // Wenn das nicht der Fall ist gib eine Fehlermeldung raus und
    // setze bool_Return auf FALSE
    file.setFileName(QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP0.MPF");
    if (!file.exists())
    {
        //log->error("File " + QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP0.MPF" +
        //             " konnte nicht gefunden werden");
        bool_Return = false;
    }

    file.setFileName(QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP1.MPF");
    if (!file.exists())
    {
        //log->error("File " + QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP1.MPF" +
        //             " konnte nicht gefunden werden");
        bool_Return = false;
    }

    file.setFileName(QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP2.MPF");
    if (!file.exists())
    {
        //log->error("File " + QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP2.MPF" +
        //             " konnte nicht gefunden werden");
        bool_Return = false;
    }

    file.setFileName(QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP3.MPF");
    if (!file.exists())
    {
        //log->error("File " + QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP3.MPF" +
        //             " konnte nicht gefunden werden");
    }

    file.setFileName(QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP4.MPF");
    if (!file.exists())
    {
        //log->error("File " + QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP4.MPF" +
        //             " konnte nicht gefunden werden");
        bool_Return = false;
    }

    file.setFileName(QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP5.MPF");
    if (!file.exists())
    {
        //log->error("File " + QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP5.MPF" +
        //             " konnte nicht gefunden werden");
        bool_Return = false;
    }

    // Überprüfe ob das File aus dem Eingabenfenster existiert
    // wenn das nicht der Fall ist wird das Eingabenfenster auf ungültig gestzt
    // setze bool_Return auf FALSE
    file.setFileName(ui->lineEdit_ToolDB->text());
    if (!file.exists())
    {
        ui->lineEdit_ToolDB->setPalette(*paletteInValid);
        bool_Return = false;
    }
    else
        ui->lineEdit_ToolDB->setPalette(*paletteValid);

    //Überprüfe ob sich der Text in OffsetX in ein float
    //konvertieren lässt
    ui->lineEdit_X->setPalette(*paletteValid);
    string_OffsetTest = ui->lineEdit_X->text();
    //float_OffsetTest = string_OffsetTest.toFloat(&bool_OffsetOK);
    string_OffsetTest.toFloat(&bool_OffsetOK);
    if(!bool_OffsetOK)
    {
        bool_Return = false;
        ui->lineEdit_X->setPalette(*paletteInValid);
    }

    ui->lineEdit_Y->setPalette(*paletteValid);
    string_OffsetTest = ui->lineEdit_Y->text();
    //float_OffsetTest = string_OffsetTest.toFloat(&bool_OffsetOK);
    string_OffsetTest.toFloat(&bool_OffsetOK);
    if(!bool_OffsetOK)
    {
        bool_Return = false;
        ui->lineEdit_Y->setPalette(*paletteInValid);
    }

    ui->lineEdit_Z->setPalette(*paletteValid);
    string_OffsetTest = ui->lineEdit_Z->text();
    //float_OffsetTest = string_OffsetTest.toFloat(&bool_OffsetOK);
    string_OffsetTest.toFloat(&bool_OffsetOK);
    if(!bool_OffsetOK)
    {
        bool_Return = false;
        ui->lineEdit_Z->setPalette(*paletteInValid);
    }
    return bool_Return;
}
*/

void Dialog_Settings::writeSettings()
{
    bool bool_OffsetOK;

    //überprüfe die Settings, wenn das fehlschlägt zeige den Dialog
    // bis alles ok ist
    if(!checkSettings())
    {
        this->show();
        return;
    }

    //Speicher die settings
    settings->set_ProgrammDir(ui->lineEdit_ProgrammDir->text());
    settings->set_MagazinDir(ui->lineEdit_ToolMagazin->text());
    settings->set_ToolDB(ui->lineEdit_ToolDB->text());
    settings->set_ToolPlaces(ui->spinBox_WerkzeugPlatze->value());
    settings->set_OffsetX(ui->lineEdit_X->text().toFloat(&bool_OffsetOK));
    settings->set_OffsetY(ui->lineEdit_Y->text().toFloat(&bool_OffsetOK));
    settings->set_OffsetZ(ui->lineEdit_Z->text().toFloat(&bool_OffsetOK));

    emit settingsOK();
}

void Dialog_Settings::toolButton_ProgrammDir_clicked(bool b)
{
    // setze das Eingabenfenster auf gültig
    // Öffne einen FileDialg um das Verzeichnis für die Programme auszuwählen
    Q_UNUSED(b);
    ui->lineEdit_ProgrammDir->setPalette(*paletteValid);
    ui->lineEdit_ProgrammDir->setText( fileDialog->getExistingDirectory(this,tr("Verzeichnis Programme"), ""));
}

void Dialog_Settings::toolButton_ToolMagazin_clicked(bool b)
{
    //Siehe void Dialog_Settings::toolButton_Programme_clicked(bool b)
    Q_UNUSED(b);
    ui->lineEdit_ToolMagazin->setPalette(*paletteValid);
    ui->lineEdit_ToolMagazin->setText( fileDialog->getExistingDirectory(this,tr("Verzeichnis Werkzeugmagazin"), ""));
}

void Dialog_Settings::toolButton_ToolDB_clicked(bool b)
{
    //Siehe void Dialog_Settings::toolButton_Programme_clicked(bool b)
    Q_UNUSED(b);
    ui->lineEdit_ToolDB->setPalette(*paletteValid);
    ui->lineEdit_ToolDB->setText( fileDialog->getOpenFileName(this,"Werkzeug Datenbank",QDir::homePath(),tr("Main Programm File(*.db)")));
}
