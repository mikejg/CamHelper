#include "tp_bohrung.h"
#include "ui_tp_bohrung.h"

TP_Bohrung::TP_Bohrung(QWidget *parent) :
    TP_Base(parent),
    ui(new Ui::TP_Bohrung)
{
    ui->setupUi(this);

    ui->lineEdit_Durchmesser->set_TextNecessary(true);
    ui->lineEdit_Durchmesser->state = MLineEdit::Digi;
    ui->lineEdit_Durchmesser->check();

    ui->lineEdit_TSA->set_TextNecessary(true);
    ui->lineEdit_TSA->state = MLineEdit::Digi;
    ui->lineEdit_TSA->check();

    /*palette = ui->lineEdit_Durchmesser->palette();
    backroundColor = palette.color(QPalette::Base);
    palette.setColor(QPalette::Base, Qt::darkRed);
    ui->lineEdit_Durchmesser->setPalette(palette);*/

    ui->lineEdit_Durchmesser->installEventFilter(this);

    clipboard = QApplication::clipboard();
    tp_HighLighter = new TP_HighLighter(ui->textEdit_Anfahren->document());
    tp_HighLighter->set_TextEdit(ui->textEdit_Anfahren);

    connect(ui->toolButton_Paste, SIGNAL(released()),this, SLOT(slot_setTextFromCilpBoard()));
}

TP_Bohrung::~TP_Bohrung()
{
    delete ui;
}

void TP_Bohrung::setPixmap()
{
    emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Bohrung/Bohrung01.png"));
}


bool TP_Bohrung::eventFilter(QObject *object, QEvent *ev)
{
    if(object == ui->lineEdit_Durchmesser)
        eventFilter_Durchmesser(ev);
    return false;
}

void TP_Bohrung::eventFilter_Durchmesser(QEvent* event)
{
    if (event->type() == QEvent::FocusIn)
    {
        emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Bohrung/Bohrung02.png"));
    }

    if (event->type() == QEvent::FocusOut)
    {
        emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Bohrung/Bohrung01.png"));
        create_NewHeaderLine();
    }
}

void TP_Bohrung::set_Anfahren()
{
    this->read_Anfahren();
    foreach(QString str, stringList_ContentAnfahren)
    {
        ui->textEdit_Anfahren->append(str);
    }
}


QStringList TP_Bohrung::postProcessing()
{
    QString string_CYCLE977;
    QString string_CYCL800;
    QString string_Frame;

    stringList_PostProcessing.clear();

    string_CYCLE977 = "CYCLE977(101,9000,,1,$Durchmesser$,,,10,$TSA$,0,1,1,,,1,\"\",,0,0.2,0.1,-0.1,0.34,1,0,,1,1)";

    switch(ui->comboBox_Frame->currentIndex())
    {
    case 0:
        string_CYCL800= "CYCLE800(1,\"HERMLE\",100000,39,0,0,0,0,0,0,0,0,0,-1,100,1)";
        string_Frame = "  Frame Oben  ";
        break;

    case 1:
        string_CYCL800 = "CYCLE800(1,\"HERMLE\",100000,39,0,0,0,0,-90,0,0,0,0,-1,100,1)";
        string_Frame = " Frame Hinten ";
        break;

    case 2:
        string_CYCL800 = "CYCLE800(1,\"HERMLE\",100000,39,0,0,0,90,-90,0,0,0,0,-1,100,1)";
        string_Frame = " Frame Links  ";
        break;

    case 3:
        string_CYCL800 = "CYCLE800(1,\"HERMLE\",100000,39,0,0,0,180,-90,0,0,0,0,-1,100,1)";
        string_Frame = "  Frame Vorne ";
        break;

    case 4:
        string_CYCL800 = "CYCLE800(1,\"HERMLE\",100000,39,0,0,0,-90,-90,0,0,0,0,-1,100,1)";
        string_Frame = " Frame Rechts ";
        break;
    }

    //Tisch schwenken
    stringList_PostProcessing.append("                                                                          ");
    create_NewHeaderLine();
    stringList_PostProcessing.append(frame_HeaderLine());
    stringList_PostProcessing.append("G75 Z1");
    stringList_PostProcessing.append(string_CYCL800);
    //Body_Bohrung
    mfile->setFileName(QDir::homePath() + "/CamHelper/config/TouchProbe/Body_Bohrung.txt");
    mfile->read_Content();
    stringList_Content = mfile->get_Content();
    foreach(QString str, stringList_Content)
        stringList_PostProcessing.append(str);

    //StringList_PostProcessing Parsen
    QStringList stringList_Temp = stringList_PostProcessing;
    stringList_PostProcessing.clear();
    foreach (QString str, stringList_Temp)
    {
        if(str.startsWith("#"))
            continue;

        //str = str.replace("$G5x$",  project->get_ProjectZeroPoint());
        str = str.replace("$CYCLE977$", string_CYCLE977);
        str = str.replace("$Durchmesser$", replace_Comma(ui->lineEdit_Durchmesser->text()));
        //str = str.replace("$DFA$", replace_Comma(ui->lineEdit_DFA->text()));
        str = str.replace("$TSA$", replace_Comma(ui->lineEdit_TSA->text()));
        if(str.contains("$Anfahren$"))
        {
            foreach (QString str_Anfahren, ui->textEdit_Anfahren->toPlainText().split("\n"))
            {
                str_Anfahren = str_Anfahren.replace(",", ".");
                stringList_PostProcessing.append(str_Anfahren);
            }
        }
        else
        {
            stringList_PostProcessing.append(str);
        }
    }
    return stringList_PostProcessing;
}

void TP_Bohrung::create_NewHeaderLine()
{
    string_HeaderLine = "";
    //A und C Achsen definieren
    switch(ui->comboBox_Frame->currentIndex())
    {
    case 0:
        string_HeaderLine = "Frame Oben";
        break;

    case 1:
        string_HeaderLine = "Frame Hinten";
        break;

    case 2:
        string_HeaderLine = "Frame Links";
        break;

    case 3:
        string_HeaderLine = "Frame Vorne";
        break;

    case 4:
        string_HeaderLine = "Frame Rechts";
        break;
    }

    string_HeaderLine = " Durchmesser: " + ui->lineEdit_Durchmesser->text() + " " + string_HeaderLine;
    emit sig_NewHeaderLine(string_HeaderLine);
}

Struct_Bohrung TP_Bohrung::get_Data()
{
    Struct_Bohrung struct_Bohrung;

    struct_Bohrung.string_Frame = ui->comboBox_Frame->currentText();
    struct_Bohrung.string_Durchmesser = ui->lineEdit_Durchmesser->text();
    struct_Bohrung.string_TSA = ui->lineEdit_TSA->text();
    struct_Bohrung.string_Anfahren = ui->textEdit_Anfahren->toPlainText();

    return struct_Bohrung;
}

void TP_Bohrung::set_Data(Struct_Bohrung struct_Bohrung)
{
    ui->comboBox_Frame->setCurrentText(struct_Bohrung.string_Frame);
    ui->lineEdit_Durchmesser->setText(struct_Bohrung.string_Durchmesser);
    ui->lineEdit_TSA->setText(struct_Bohrung.string_TSA);
    ui->textEdit_Anfahren->append(struct_Bohrung.string_Anfahren);
}

void TP_Bohrung::slot_setTextFromCilpBoard()
{
    QString text = clipboard->text();

    if(!text.isEmpty())
        check_Clipboard(text);

    if(string_X.isEmpty() || string_Y.isEmpty() || string_Z.isEmpty())
        return;

    read_Anfahren("Anfahren_Bohrung.txt");
    ui->textEdit_Anfahren->clear();
    foreach(QString str, stringList_ContentAnfahren)
    {
        str = str.replace("$Z$", string_Z);
        str = str.replace("$X$", string_X);
        str = str.replace("$Y$", string_Y);

        ui->textEdit_Anfahren->append(str);
    }
    clipboard->clear(QClipboard::Clipboard);
}
