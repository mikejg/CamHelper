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

void Tab_Project::set_ProjectData(ProjectData pd)
{
    projectData = pd;

    ui->scrollArea->clear();                                //Lösche die Bilder
    ui->textEdit_Header->clear();                           //Lösche den Header

    //Befülle die Felder mit Daten
    ui->lineEdit_ProjectName->setText(projectData.name);                            //Name des Projects
    ui->lineEdit_ProjectState->setText(projectData.state);                          //Der Modellstand des Projekts
    ui->lineEdit_Tension->setText(projectData.tension);                             //Die Spannung des Projekts
    ui->lineEdit_hyperMILL_File->setText(projectData.hyperMILL_File);               //Das hyperMIll File für das Projekt
    ui->textEdit_Header->append(projectData.header);                                //Infotext am Anfanger des Hauptprogramms

    ui->lineEdit_RawPartX->setText(projectData.rawPart.x_Length);                   //Rohteil Länge in X
    ui->lineEdit_RawPartY->setText(projectData.rawPart.y_Width);                    //Rohteil Breite in Y
    ui->lineEdit_RawPartZ->setText(projectData.rawPart.z_Height);                   //Rohteil Höhe in Z
    ui->doubleSpinBox_ZRawPart->setValue(projectData.rawPart.z_RawPart.toFloat());  //Z-Rohteil

    ui->lineEdit_FinishPartX->setText(projectData.finishPart.x_Length);             //Fertigteil Länge in X
    ui->lineEdit_FinishPartY->setText(projectData.finishPart.y_Width);              //Fertigteil Breite in Y
    ui->lineEdit_FinishPartZ->setText(projectData.finishPart.z_Height);             //Fertigteil Höhe in Z

    ui->comboBox_Material->setCurrentText(projectData.material);                    //Material

    ui->lineEdit_ZeroPointG->setText(projectData.zeroPoint.string_G);               //Nullpunkt G (G55 G506 etc)
    ui->lineEdit_ZeroPointX->setText(projectData.zeroPoint.string_X);               //Nullpunkt X
    ui->lineEdit_ZeroPointY->setText(projectData.zeroPoint.string_Y);               //Nullpunkt Y
    ui->lineEdit_ZeroPointZ->setText(projectData.zeroPoint.string_Z);               //Nullpunkt Z

    foreach(QPixmap pixmap, projectData.listPictures)                               //Bilder werden eingefügt
        insert_Pixmap(pixmap);

    foreach(Tool* tool, projectData.toolList->get_List())
        log->successful(tool->get_Number() + " " +tool->get_Description());
}
