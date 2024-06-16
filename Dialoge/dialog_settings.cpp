#include "dialog_settings.h"
#include "ui_dialog_settings.h"

Dialog_Settings::Dialog_Settings(QWidget *parent, Logging* l) :
    QDialog(parent),
    ui(new Ui::Dialog_Settings)
{
    log = l;
    ui->setupUi(this);

    paletteInValid = new QPalette();
    paletteInValid->setColor(QPalette::Text,Qt::red);

    paletteValid = new QPalette();
    *paletteValid = palette();

    fileDialog = new QFileDialog(this);
    fileDialog->setFileMode(QFileDialog::Directory);
    fileDialog->setFilter(QDir::Dirs);

    connect(ui->buttonBox,             SIGNAL(accepted()),    this, SLOT(writeSettings()));
    connect(ui->toolButton_Programme,  SIGNAL(clicked(bool)), this, SLOT(toolButton_Programme_clicked(bool)));
    connect(ui->toolButton_Magazin,    SIGNAL(clicked(bool)), this, SLOT(toolButton_Magazin_clicked(bool)));
    connect(ui->toolButton_WerkzeugDB, SIGNAL(clicked(bool)), this, SLOT(toolButton_WerkzeugDB_clicked(bool)));
}

Dialog_Settings::~Dialog_Settings()
{
    delete ui;
}

void Dialog_Settings::set_Settings(Settings* s)
{
    settings = s;

    // Befuelle die Eingabenfenster mit den settings
    ui->lineEdit_Programme->setText(s->get_ProgrammDir());
    ui->lineEdit_Magazin->setText(s->get_MagazinDir());
    ui->lineEdit_WerkzeugDB->setText(s->get_WerkzeugDB());
    ui->checkBox_Numbering->setChecked(s->get_Numbering());
    ui->spinBox_WerkzeugPlatze->setValue(s->get_WerkzeugPlatze());
    ui->checkBox_AufmassMax->setChecked(s->get_MaxOverSize());
}

bool Dialog_Settings::checkSettings()
{
    bool bool_Return = true;
    QFile file;
    QDir dir;

    // Überprüfe ob der Ordner im Eingabenfeld Programme existiert.
    // Wenn nicht dann setze bool_Return auf FALSE und das Eingabenfeld
    // auf ungültig.
    //Wenn der Ordner existiert setze das Eingabenfeld auf gültig.
    dir = QDir(ui->lineEdit_Programme->text());
    if (!dir.exists())
    {
        ui->lineEdit_Programme->setPalette(*paletteInValid);
        bool_Return = false;
    }
    else
        ui->lineEdit_Programme->setPalette(*paletteValid);

    // siehe Oben mit dem Ordner Programme
    dir = QDir(ui->lineEdit_Magazin->text());
    if (!dir.exists())
    {
        ui->lineEdit_Magazin->setPalette(*paletteInValid);
        bool_Return = false;
    }
    else
        ui->lineEdit_Magazin->setPalette(*paletteValid);

    // Überprüfe ob das File "Magazin.INI" im Verzeichnis existiert
    // wenn das nicht der Fall ist gib eine Fehlermeldung raus und
    // setze bool_Return auf FALSE
    file.setFileName(dir.path() + "/Magazin.INI");
    if (!file.exists())
    {
        log->error("File " + dir.path() + "/Magazin.INI" +
                     " konnte nicht gefunden werden");
        bool_Return = false;
    }

    // Überprüfe ob die Vorlagen für die Hauptprogramme existieren
    // Wenn das nicht der Fall ist gib eine Fehlermeldung raus und
    // setze bool_Return auf FALSE
    file.setFileName(QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP0.MPF");
    if (!file.exists())
    {
        log->error("File " + QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP0.MPF" +
                     " konnte nicht gefunden werden");
        bool_Return = false;
    }

    file.setFileName(QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP1.MPF");
    if (!file.exists())
    {
        log->error("File " + QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP1.MPF" +
                     " konnte nicht gefunden werden");
        bool_Return = false;
    }

    file.setFileName(QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP2.MPF");
    if (!file.exists())
    {
        log->error("File " + QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP2.MPF" +
                     " konnte nicht gefunden werden");
        bool_Return = false;
    }

    file.setFileName(QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP3.MPF");
    if (!file.exists())
    {
        log->error("File " + QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP3.MPF" +
                     " konnte nicht gefunden werden");
    }

    file.setFileName(QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP4.MPF");
    if (!file.exists())
    {
        log->error("File " + QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP4.MPF" +
                     " konnte nicht gefunden werden");
        bool_Return = false;
    }

    file.setFileName(QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP5.MPF");
    if (!file.exists())
    {
        log->error("File " + QDir::homePath() + "/CamHelper/Vorlagen/Hauptprogramme/Hauptprogramm_SP5.MPF" +
                     " konnte nicht gefunden werden");
        bool_Return = false;
    }

    // Überprüfe ob das File aus dem Eingabenfenster existiert
    // wenn das nicht der Fall ist wird das Eingabenfenster auf ungültig gestzt
    // setze bool_Return auf FALSE
    file.setFileName(ui->lineEdit_WerkzeugDB->text());
    if (!file.exists())
    {
        ui->lineEdit_WerkzeugDB->setPalette(*paletteInValid);
        bool_Return = false;
    }
    else
        ui->lineEdit_WerkzeugDB->setPalette(*paletteValid);
    return bool_Return;
}

void Dialog_Settings::writeSettings()
{
    //überprüfe die Settings, wenn das fehlschlägt zeige den Dialog
    // bis alles ok ist
    if(!checkSettings())
    {
        this->show();
        return;
    }

    //Speicher die settings
    bool bool_Numbering = ui->checkBox_Numbering->isChecked();
    bool bool_AufmassMax = ui->checkBox_AufmassMax->isChecked();
    settings->set_ProgrammDir(ui->lineEdit_Programme->text());
    settings->set_MagazinDir(ui->lineEdit_Magazin->text());
    settings->set_WerkzeugDB(ui->lineEdit_WerkzeugDB->text());
    settings->set_Numbering(QVariant(bool_Numbering).toString());
    settings->set_WerkzeugPlatze(ui->spinBox_WerkzeugPlatze->value());
    settings->set_AufmassMax(QVariant(bool_AufmassMax).toString());

    emit settingsOK();
}

void Dialog_Settings::toolButton_Programme_clicked(bool b)
{
    // setze das Eingabenfenster auf gültig
    // Öffne einen FileDialg um das Verzeichnis für die Programme auszuwählen
    Q_UNUSED(b);
    ui->lineEdit_Programme->setPalette(*paletteValid);
    ui->lineEdit_Programme->setText( fileDialog->getExistingDirectory(this,tr("Verzeichnis Programme"), ""));
}

void Dialog_Settings::toolButton_Magazin_clicked(bool b)
{
    //Siehe void Dialog_Settings::toolButton_Programme_clicked(bool b)
    Q_UNUSED(b);
    ui->lineEdit_Magazin->setPalette(*paletteValid);
    ui->lineEdit_Magazin->setText( fileDialog->getExistingDirectory(this,tr("Verzeichnis Werkzeugmagazin"), ""));
}

void Dialog_Settings::toolButton_WerkzeugDB_clicked(bool b)
{
    //Siehe void Dialog_Settings::toolButton_Programme_clicked(bool b)
    Q_UNUSED(b);
    ui->lineEdit_WerkzeugDB->setPalette(*paletteValid);
    ui->lineEdit_WerkzeugDB->setText( fileDialog->getOpenFileName(this,"Werkzeug Datenbank",QDir::homePath(),tr("Main Programm File(*.db)")));
}
