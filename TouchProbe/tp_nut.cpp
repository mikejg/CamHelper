#include "tp_nut.h"
#include "ui_tp_nut.h"

TP_Nut::TP_Nut(QWidget *parent) :
    TP_Base(parent),
    ui(new Ui::TP_Nut)
{
    ui->setupUi(this);

    ui->lineEdit_W->installEventFilter(this);
    ui->lineEdit_TSA->installEventFilter(this);

    /*palette = ui->lineEdit_W->palette();
    backroundColor = palette.color(QPalette::Base);
    palette.setColor(QPalette::Base, Qt::darkRed);
    ui->lineEdit_W->setPalette(palette);*/

    ui->lineEdit_W->set_TextNecessary(true);
    ui->lineEdit_W->state = MLineEdit::Digi;
    ui->lineEdit_W->check();

    ui->lineEdit_DFA->set_TextNecessary(true);
    ui->lineEdit_DFA->state = MLineEdit::Digi;
    ui->lineEdit_DFA->check();

    ui->lineEdit_TSA->set_TextNecessary(true);
    ui->lineEdit_TSA->state = MLineEdit::Digi;
    ui->lineEdit_TSA->check();

    tp_HighLighter = new TP_HighLighter(ui->textEdit_Anfahren->document());
    tp_HighLighter->set_TextEdit(ui->textEdit_Anfahren);

    connect(ui->comboBox_Messachse, SIGNAL(currentTextChanged(QString)), this, SLOT(slot_AxesChanged(QString)));
    connect(ui->comboBox_Frame, SIGNAL(currentTextChanged(QString)), this, SLOT(slot_AxesChanged(QString)));
    connect(ui->toolButton_Paste, SIGNAL(released()),this, SLOT(slot_setTextFromCilpBoard()));
}

TP_Nut::~TP_Nut()
{
    delete ui;
}

Struct_Nut TP_Nut::get_Data()
{
    Struct_Nut struct_Nut;

    struct_Nut.string_Frame = ui->comboBox_Frame->currentText();
    struct_Nut.string_Messachse = ui->comboBox_Messachse->currentText();
    struct_Nut.string_W = ui->lineEdit_W->text();
    struct_Nut.string_DFA = ui->lineEdit_DFA->text();
    struct_Nut.string_TSA = ui->lineEdit_TSA->text();
    struct_Nut.string_Anfahren = ui->textEdit_Anfahren->toPlainText();

    return struct_Nut;
}

void TP_Nut::set_Data(Struct_Nut struct_Nut)
{
    ui->comboBox_Frame->setCurrentText(struct_Nut.string_Frame);
    ui->comboBox_Messachse->setCurrentText(struct_Nut.string_Messachse);
    ui->lineEdit_W->setText(struct_Nut.string_W);
    ui->lineEdit_DFA->setText(struct_Nut.string_DFA);
    ui->lineEdit_TSA->setText(struct_Nut.string_TSA);
    ui->textEdit_Anfahren->append(struct_Nut.string_Anfahren);
}

bool TP_Nut::eventFilter(QObject *object, QEvent *ev)
{
    if(object == ui->lineEdit_W && ev->type() == QEvent::FocusIn)
        emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Nut/Nut_W.png"));

    if(object == ui->lineEdit_TSA)
        eventFilter_TSA(ev);

    return false;
}

void TP_Nut::eventFilter_TSA(QEvent* event)
{
    if (event->type() == QEvent::FocusIn)
    {
        emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Nut/Nut_TSA.png"));
    }
}

void TP_Nut::slot_AxesChanged(QString str)
{
    Q_UNUSED(str);

    if(ui->comboBox_Messachse->currentText() == "X")
        emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Nut/Nut_X.png"));

    if(ui->comboBox_Messachse->currentText() == "Y")
        emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Nut/Nut_Y.png"));

    create_NewHeaderLine();
}

void TP_Nut::set_Anfahren()
{
    this->read_Anfahren();
    foreach(QString str, stringList_ContentAnfahren)
    {
        ui->textEdit_Anfahren->append(str);
    }
}

void TP_Nut::setPixmap()
{
    if(ui->comboBox_Messachse->currentText() == "X")
    {
        emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Nut/Nut_X.png"));
    }

    if(ui->comboBox_Messachse->currentText() == "Y")
    {
        emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Nut/Nut_Y.png"));
    }
}

QStringList TP_Nut::postProcessing()
{
    QString string_CYCLE977;
    QString string_CYCL800;
    QString string_Axes;
    QString string_Frame;

    stringList_PostProcessing.clear();

    //Cyclus einrichten
    if(ui->comboBox_Messachse->currentText() == "X")
    {
        string_CYCLE977 = "CYCLE977(103,9000,,1,$W$,,,10,$TSA$,0,10,28,,1,1,\"\",,0,1.01,1.01,-1.01,0.34,1,0,,1,1)";
        string_Axes = "X";
    }

    if(ui->comboBox_Messachse->currentText() == "Y")
    {
        string_CYCLE977 = "CYCLE977(103,9000,,1,$W$,,,10,$TSA$,0,10,28,,2,1,\"\",,0,1.01,1.01,-1.01,0.34,1,0,,1,1)";
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
    mfile->setFileName(QDir::homePath() + "/CamHelper/config/TouchProbe/Body_Nut.txt");
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
        str = str.replace("$W$", replace_Comma(ui->lineEdit_W->text()));
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

void TP_Nut::create_NewHeaderLine()
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
        string_HeaderLine = "Nut X " + string_HeaderLine;
    }

    if(ui->comboBox_Messachse->currentText() == "Y")
    {
        string_HeaderLine = "Nut Y " + string_HeaderLine;
    }

    emit sig_NewHeaderLine(string_HeaderLine);
}

void TP_Nut::slot_setTextFromCilpBoard()
{
    QString text = clipboard->text();

    if(!text.isEmpty())
        check_Clipboard(text);

    if(string_X.isEmpty() || string_Y.isEmpty() || string_Z.isEmpty())
        return;

    read_Anfahren("Anfahren_Nut.txt");
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
