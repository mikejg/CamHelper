#include "tab_project.h"
#include "ui_tab_project.h"

Tab_Project::Tab_Project(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Tab_Project)
{
    ui->setupUi(this);
    ui->scrollArea->set_Layout(ui->verticalLayout_Pictures);
    ui->scrollArea->set_Spacer(ui->verticalSpacer_Pictures);
}

Tab_Project::~Tab_Project()
{
    delete ui;
}
void Tab_Project::insert_Pixmap(QPixmap p)
{
    ui->scrollArea->insert_Pixmap(p);
}

bool Tab_Project::load_Material()
{

    // Einlesen der Materialien
    // setze das File für die Materialien und lies es ein
    // gib alle Materialien in die ComboBox Material
    // tritt ein Fehler auf, gibt die Funktion FALSE zurück
    mfile->setFileName(QDir::homePath() + "/CamHelper/config/Material.txt");
    if(!mfile->read_Content())
        return false;

    log->successful("Materialliste geladen");
    ui->comboBox_Material->addItem("");
    ui->comboBox_Material->addItems(mfile->get_Content());

    return true;
}

void Tab_Project::set_Logging(Logging *l)
{
    log = l;
    mfile = new MFile(this, log);
}

void Tab_Project::slot_OpenProject(QString string_ProjectId)
{
    ProjectData projectData;

    ui->scrollArea->clear();                                //Lösche die Bilder
    ui->textEdit_Header->clear();                           //Lösche den Header

    project = new Project(this);                            //erstelle ein neues Project

    projectData = dataBase->get_Project(string_ProjectId);  //Lade die Projekdaten aus der DatenBank
    project->set_ProjectData(projectData);                  //Übergebe die ProjektDaten dem neuen Projekt

    //Befülle die Felder mit Daten
    ui->lineEdit_ProjectName->setText(projectData.name);
    ui->lineEdit_ProjectState->setText(projectData.state);
    ui->lineEdit_Tension->setText(projectData.tension);
    ui->lineEdit_hyperMILL_File->setText(projectData.hyperMILL_File);
    ui->textEdit_Header->append(projectData.header);

    ui->lineEdit_RawPartX->setText(projectData.rawPart.x_Length);
    ui->lineEdit_RawPartY->setText(projectData.rawPart.y_Width);
    ui->lineEdit_RawPartZ->setText(projectData.rawPart.z_Height);
    ui->doubleSpinBox_ZRawPart->setValue(projectData.rawPart.z_RawPart.toFloat());

    ui->lineEdit_FinishPartX->setText(projectData.finishPart.x_Length);
    ui->lineEdit_FinishPartY->setText(projectData.finishPart.y_Width);
    ui->lineEdit_FinishPartZ->setText(projectData.finishPart.z_Height);

    foreach(QPixmap pixmap, projectData.listPictures)
        insert_Pixmap(pixmap);
}
