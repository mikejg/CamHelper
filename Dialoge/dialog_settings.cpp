#include "dialog_settings.h"
#include "ui_dialog_settings.h"

//Dialog_Settings::Dialog_Settings(QWidget *parent, Logging* l) :
Dialog_Settings::Dialog_Settings(QWidget *parent, Logging* l) :
    QDialog(parent),
    ui(new Ui::Dialog_Settings)
{
    log = l;

    settings = new Settings(this);

    ui->setupUi(this);

    fileDialog = new QFileDialog(this);
    fileDialog->setFileMode(QFileDialog::Directory);
    fileDialog->setFilter(QDir::Dirs);

    ui->lineEdit_ProgrammDir->setText(settings->get_ProgrammDir());
    ui->lineEdit_ProgrammDir->state = MLineEdit::Dir;
    ui->lineEdit_ProgrammDir->set_TextNecessary(true);

    ui->lineEdit_ToolMagazin->setText(settings->get_MagazinDir());
    ui->lineEdit_ToolMagazin->state = MLineEdit::File;
    ui->lineEdit_ToolMagazin->set_TextNecessary(true);

    ui->lineEdit_ToolDB->setText(settings->get_ToolDB());
    ui->lineEdit_ToolDB->set_TextNecessary(true);
    ui->lineEdit_ToolDB->state = MLineEdit::File;

    ui->lineEdit_X->setText(QString("%1").arg(settings->get_OffsetX()));
    ui->lineEdit_X->set_TextNecessary(true);
    ui->lineEdit_X->state = MLineEdit::Digi;

    ui->lineEdit_Y->setText(QString("%1").arg(settings->get_OffsetY()));
    ui->lineEdit_Y->set_TextNecessary(true);
    ui->lineEdit_Y->state = MLineEdit::Digi;

    ui->lineEdit_Z->setText(QString("%1").arg(settings->get_OffsetZ()));
    ui->lineEdit_Z->set_TextNecessary(true);
    ui->lineEdit_Z->state = MLineEdit::Digi;

    ui->spinBox_WerkzeugPlatze->setValue(settings->get_ToolPlaces());

    connect(ui->buttonBox,              SIGNAL(accepted()),    this, SLOT(writeSettings()));
    connect(ui->toolButton_ProgrammDir, SIGNAL(clicked(bool)), this, SLOT(toolButton_ProgrammDir_clicked(bool)));
    connect(ui->toolButton_ToolMagazin, SIGNAL(clicked(bool)), this, SLOT(toolButton_ToolMagazin_clicked(bool)));
    connect(ui->toolButton_ToolDB,      SIGNAL(clicked(bool)), this, SLOT(toolButton_ToolDB_clicked(bool)));
}

Dialog_Settings::~Dialog_Settings()
{
    delete ui;
}

/*void Dialog_Settings::set_Settings(Settings* s)
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
}*/

bool Dialog_Settings::checkSettings()
{
    qDebug() << Q_FUNC_INFO;

    if(!ui->lineEdit_ProgrammDir->check())
    {
        log->vailed("Settings: Verzeichnis Programme");
        return false;
    }
    else
    {
        log->successful("Settings: Verzeichnis Programme");
    }

    if(!ui->lineEdit_ToolMagazin->check())
    {
        log->vailed("Settings: Datei Werkzeug Magazin");
        return false;
    }
    else
    {
        log->successful("Settings: Datei Werkzeug Magazin");
    }

   if(!ui->lineEdit_ToolDB->check())
    {
        log->vailed("Settings: Datei Werkzeug Datenbank");
        return false;
    }
    else
    {
        log->successful("Settings: Datei Werkzeug Datenbank");
    }

   if(!ui->lineEdit_X->check())
       return false;

   if(!ui->lineEdit_Y->check())
       return false;

   if(!ui->lineEdit_Z->check())
       return false;
    return true;
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
    settings->set_ProgrammDir(ui->lineEdit_ProgrammDir->text());
    settings->set_MagazinDir(ui->lineEdit_ToolMagazin->text());
    settings->set_ToolDB(ui->lineEdit_ToolDB->text());
    settings->set_ToolPlaces(ui->spinBox_WerkzeugPlatze->value());
    settings->set_OffsetX(ui->lineEdit_X->text().toFloat());
    settings->set_OffsetY(ui->lineEdit_Y->text().toFloat());
    settings->set_OffsetZ(ui->lineEdit_Z->text().toFloat());

    emit settingsOK();
}

void Dialog_Settings::toolButton_ProgrammDir_clicked(bool b)
{
    // Öffne einen FileDialg um das Verzeichnis für die Programme auszuwählen
    Q_UNUSED(b);
    ui->lineEdit_ProgrammDir->setText( fileDialog->getExistingDirectory(this,tr("Verzeichnis Programme"), ""));
}

void Dialog_Settings::toolButton_ToolMagazin_clicked(bool b)
{
    Q_UNUSED(b);
    ui->lineEdit_ToolMagazin->setText( fileDialog->getOpenFileName(this,"Werkzeug Magazin",QDir::homePath(),tr("Magazin File(*.INI)")));
}

void Dialog_Settings::toolButton_ToolDB_clicked(bool b)
{
    Q_UNUSED(b);
    ui->lineEdit_ToolDB->setText( fileDialog->getOpenFileName(this,"Werkzeug Datenbank",QDir::homePath(),tr("Main Programm File(*.db)")));
}
