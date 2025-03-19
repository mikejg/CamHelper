#include "tp_steg.h"
#include "ui_tp_steg.h"

TP_Steg::TP_Steg(QWidget *parent) :
    TP_Base(parent),
    ui(new Ui::TP_Steg)
{
    ui->setupUi(this);
    ui->lineEdit_W->installEventFilter(this);
    ui->lineEdit_DFA->installEventFilter(this);
    ui->lineEdit_TSA->installEventFilter(this);
    ui->lineEdit_DZ->installEventFilter(this);

    palette = ui->lineEdit_W->palette();
    backroundColor = palette.color(QPalette::Base);
    palette.setColor(QPalette::Base, Qt::darkRed);
    ui->lineEdit_W->setPalette(palette);

    tp_HighLighter = new TP_HighLighter(ui->textEdit_Anfahren->document());
    tp_HighLighter->set_TextEdit(ui->textEdit_Anfahren);

    connect(ui->comboBox_Messachse, SIGNAL(currentTextChanged(QString)), this, SLOT(slot_AxesChanged(QString)));
    connect(ui->comboBox_Frame, SIGNAL(currentTextChanged(QString)), this, SLOT(slot_AxesChanged(QString)));
    connect(ui->toolButton_Paste, SIGNAL(released()),this, SLOT(slot_setTextFromCilpBoard()));
}

TP_Steg::~TP_Steg()
{
    delete ui;    
}

Struct_Steg TP_Steg::get_Data()
{
    Struct_Steg struct_Steg;

    struct_Steg.string_Frame = ui->comboBox_Frame->currentText();
    struct_Steg.string_Messachse = ui->comboBox_Messachse->currentText();
    struct_Steg.string_W = ui->lineEdit_W->text();
    struct_Steg.string_DZ = ui->lineEdit_DZ->text();
    struct_Steg.string_DFA = ui->lineEdit_DFA->text();
    struct_Steg.string_TSA = ui->lineEdit_TSA->text();
    struct_Steg.string_Anfahren = ui->textEdit_Anfahren->toPlainText();

    return struct_Steg;
}

void TP_Steg::set_Data(Struct_Steg struct_Steg)
{
    ui->comboBox_Frame->setCurrentText(struct_Steg.string_Frame);
    ui->comboBox_Messachse->setCurrentText(struct_Steg.string_Messachse);
    ui->lineEdit_W->setText(struct_Steg.string_W);
    ui->lineEdit_DZ->setText(struct_Steg.string_DZ);
    ui->lineEdit_DFA->setText(struct_Steg.string_DFA);
    ui->lineEdit_TSA->setText(struct_Steg.string_TSA);
    ui->textEdit_Anfahren->append(struct_Steg.string_Anfahren);
}

void TP_Steg::set_Anfahren()
{
    this->read_Anfahren();
    foreach(QString str, stringList_ContentAnfahren)
    {
        ui->textEdit_Anfahren->append(str);
    }
}

void TP_Steg::setPixmap()
{
    if(ui->comboBox_Messachse->currentText() == "X")
    {
        emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Steg/Steg_X1.png"));
    }

    if(ui->comboBox_Messachse->currentText() == "Y")
    {
        emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Steg/Steg_Y1.png"));
    }
}

void TP_Steg::slot_AxesChanged(QString str)
{
    Q_UNUSED(str);

    if(ui->comboBox_Messachse->currentText() == "X")
       emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Steg/Steg_X1.png"));

    if(ui->comboBox_Messachse->currentText() == "Y")
        emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Steg/Steg_Y1.png"));

    create_NewHeaderLine();
}

bool TP_Steg::eventFilter(QObject *object, QEvent *ev)
{
    //Überprüfe ob sich der Inhalt von LineEdit_W in ein double konvertieren läss.
    //Wenn das fehlschlägt setze den Hintergrund rot

    if(object == ui->lineEdit_DFA)
        check_LineEdit(ui->lineEdit_DFA, true);

    if(object == ui->lineEdit_TSA)
        check_LineEdit(ui->lineEdit_TSA, true);

    if(object == ui->lineEdit_DZ)
        check_LineEdit(ui->lineEdit_DZ, true);

    if(object == ui->lineEdit_W)
       check_LineEdit(ui->lineEdit_W, true);

    if(object == ui->lineEdit_W)
        eventFilter_Wert(ev);

    if(object == ui->lineEdit_DFA)
        eventFilter_DFA(ev);
    if(object == ui->lineEdit_DZ)
        eventFilter_DZ(ev);
    return false;
}

void TP_Steg::eventFilter_Wert(QEvent* event)
{
    if (event->type() == QEvent::FocusIn)
    {
        if(ui->comboBox_Messachse->currentText() == "X")
            emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Steg/Steg_X2.png"));

        if(ui->comboBox_Messachse->currentText() == "Y")
            emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Steg/Steg_Y2.png"));
    }
}

void TP_Steg::eventFilter_DFA(QEvent* event)
{
    if (event->type() == QEvent::FocusIn)
    {
        emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Steg/Steg_DFA.png"));
    }
}

void TP_Steg::eventFilter_DZ(QEvent* event)
{
    if (event->type() == QEvent::FocusIn)
    {
        if(ui->comboBox_Messachse->currentText() == "X")
            emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Steg/Steg_X3.png"));

        if(ui->comboBox_Messachse->currentText() == "Y")
            emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Steg/Steg_Y3.png"));
    }
}

QStringList TP_Steg::postProcessing()
{
    QString string_CYCLE977;
    QString string_CYCL800;
    QString string_Axes;
    QString string_Frame;

    stringList_PostProcessing.clear();

    //Cyclus einrichten
    if(ui->comboBox_Messachse->currentText() == "X")
    {
        string_CYCLE977 = "CYCLE977(104,9000,,1,$Lange$,,,$DFA$,$TSA$,0,$DZ$,1,,1,1,\"\",,0,1.01,1.01,-1.01,0.34,1,0,,1,1)";
        string_Axes = "X";
    }

    if(ui->comboBox_Messachse->currentText() == "Y")
    {
        string_CYCLE977 = "CYCLE977(104,9000,,1,$Lange$,,,$DFA$,$TSA$,0,$DZ$,1,,2,1,\"\",,0,1.01,1.01,-1.01,0.34,1,0,,1,1)";
        string_Axes = "Y";
    }

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
    //Body_Kante
    mfile->setFileName(QDir::homePath() + "/CamHelper/config/TouchProbe/Body_Steg.txt");
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
        str = str.replace("$Lange$", replace_Comma(ui->lineEdit_W->text()));
        str = str.replace("$DFA$", replace_Comma(ui->lineEdit_DFA->text()));
        str = str.replace("$TSA$", replace_Comma(ui->lineEdit_TSA->text()));
        str = str.replace("$DZ$", replace_Comma(ui->lineEdit_DZ->text()));
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

void TP_Steg::create_NewHeaderLine()
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

    if(ui->comboBox_Messachse->currentText() == "X")
    {
        string_HeaderLine = "Steg X " + string_HeaderLine;
    }

    if(ui->comboBox_Messachse->currentText() == "Y")
    {
        string_HeaderLine = "Steg Y " + string_HeaderLine;
    }

    emit sig_NewHeaderLine(string_HeaderLine);
}

void TP_Steg::slot_setTextFromCilpBoard()
{
    QString text = clipboard->text();

    if(!text.isEmpty())
        check_Clipboard(text);

    if(string_X.isEmpty() || string_Y.isEmpty() || string_Z.isEmpty())
        return;

    read_Anfahren("Anfahren_Steg.txt");
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
