#include "tp_kante.h"
#include "ui_tp_kante.h"

TP_Kante::TP_Kante(QWidget *parent) :
    TP_Base(parent),
    ui(new Ui::TP_Kante)
{
    ui->setupUi(this);
    clipboard = QApplication::clipboard();

    /*palette = ui->lineEdit_Wert->palette();
    backroundColor = palette.color(QPalette::Base);
    palette.setColor(QPalette::Base, Qt::darkRed);
    ui->lineEdit_Wert->setPalette(palette);*/

    ui->lineEdit_Wert->set_TextNecessary(true);
    ui->lineEdit_Wert->state = MLineEdit::Digi;
    ui->lineEdit_Wert->check();

    ui->lineEdit_DFA->set_TextNecessary(true);
    ui->lineEdit_DFA->state = MLineEdit::Digi;
    ui->lineEdit_DFA->check();

    ui->lineEdit_TSA->set_TextNecessary(true);
    ui->lineEdit_TSA->state = MLineEdit::Digi;
    ui->lineEdit_TSA->check();

    ui->lineEdit_Wert->installEventFilter(this);
    ui->lineEdit_DFA->installEventFilter(this);
    ui->lineEdit_TSA->installEventFilter(this);

    tp_HighLighter = new TP_HighLighter(ui->textEdit_Anfahren->document());
    tp_HighLighter->set_TextEdit(ui->textEdit_Anfahren);

    connect(ui->comboBox_Frame, SIGNAL(currentTextChanged(QString)), this, SLOT(slot_currentFrameChanged(QString)));
    connect(ui->comboBox_Messrichtung, SIGNAL(currentTextChanged(QString)), this, SLOT(slot_AxesSignsChanged(QString)));
    connect(ui->comboBox_Messachse,  SIGNAL(currentTextChanged(QString)), this, SLOT(slot_AxesSignsChanged(QString)));
    connect(ui->textEdit_Anfahren, SIGNAL(textChanged()), this, SIGNAL(sig_ReCreate()));
    connect(ui->lineEdit_Wert, SIGNAL(editingFinished()), this, SIGNAL(sig_ReCreate()));
    connect(ui->lineEdit_DFA, SIGNAL(editingFinished()), this, SIGNAL(sig_ReCreate()));
    connect(ui->lineEdit_TSA, SIGNAL(editingFinished()), this, SIGNAL(sig_ReCreate()));
    connect(ui->toolButton_Paste, SIGNAL(released()),this, SLOT(slot_setTextFromCilpBoard()));
    connect(ui->pushButton_NPV, SIGNAL(released()), this, SLOT(slot_NPVClicked()));
}

TP_Kante::~TP_Kante()
{
    delete ui;
}

Struct_Kante TP_Kante::get_Data()
{
    Struct_Kante struct_Kante;

    struct_Kante.string_Frame =         ui->comboBox_Frame->currentText();
    struct_Kante.string_Messrichtung =  ui->comboBox_Messrichtung->currentText();
    struct_Kante.string_Messachse =     ui->comboBox_Messachse->currentText();
    struct_Kante.string_Wert =          ui->lineEdit_Wert->text();
    struct_Kante.string_DFA =           ui->lineEdit_DFA->text();
    struct_Kante.string_TSA =           ui->lineEdit_TSA->text();
    struct_Kante.string_Anfahren =      ui->textEdit_Anfahren->toPlainText();
    struct_Kante.string_X =              string_X;
    struct_Kante.string_Y =              string_Y;
    struct_Kante.string_Z =              string_Z;

    return struct_Kante;
}

void TP_Kante::set_Data(Struct_Kante struct_Kante)
{
    ui->comboBox_Frame->setCurrentText(struct_Kante.string_Frame);
    ui->comboBox_Messrichtung->setCurrentText(struct_Kante.string_Messrichtung);
    ui->comboBox_Messachse->setCurrentText(struct_Kante.string_Messachse);
    ui->lineEdit_Wert->setText(struct_Kante.string_Wert);
    ui->lineEdit_DFA->setText(struct_Kante.string_DFA);
    ui->lineEdit_TSA->setText(struct_Kante.string_TSA);
    ui->textEdit_Anfahren->append(struct_Kante.string_Anfahren);

    string_X = struct_Kante.string_X;
    string_Y = struct_Kante.string_Y;
    string_Z = struct_Kante.string_Z;

    qDebug() << Q_FUNC_INFO << "string_X" << string_X;
    qDebug() << Q_FUNC_INFO << "string_Y" << string_Y;
    qDebug() << Q_FUNC_INFO << "string_Z" << string_Z;
}

void TP_Kante::slot_AxesSignsChanged(QString str)
{
    Q_UNUSED(str);
    //emit sig_Err("test");

    ui->comboBox_Messrichtung->setEnabled(true);
    if(ui->comboBox_Messachse->currentText() == "Z")
    {
        ui->comboBox_Messrichtung->setEnabled(false);
        ui->comboBox_Messrichtung->setCurrentIndex(1);
        ui->label_Wert->setText("Z0");
        emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Kante/Z_Minus1.png"));
    }
    if(ui->comboBox_Messrichtung->currentText() == "+" &&
        ui->comboBox_Messachse->currentText() == "X")
    {
        ui->label_Wert->setText("X0");
        emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Kante/X_Plus1.png"));
    }

    if(ui->comboBox_Messrichtung->currentText() == "-" &&
        ui->comboBox_Messachse->currentText() == "X")
    {
        ui->label_Wert->setText("X0");
        emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Kante/X_Minus1.png"));
    }

    if(ui->comboBox_Messrichtung->currentText() == "-" &&
        ui->comboBox_Messachse->currentText() == "Y")
    {
        ui->label_Wert->setText("Y0");
        emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Kante/Y_Minus1.png"));
    }

    if(ui->comboBox_Messrichtung->currentText() == "+" &&
        ui->comboBox_Messachse->currentText() == "Y")
    {
        ui->label_Wert->setText("Y0");
        emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Kante/Y_Plus1.png"));
    }

    create_NewHeaderLine();
    emit sig_ReCreate();
}

bool TP_Kante::eventFilter(QObject *object, QEvent *ev)
{   
    /*if(object == ui->lineEdit_DFA)
        check_LineEdit(ui->lineEdit_DFA, true);

    if(object == ui->lineEdit_Wert)
       check_LineEdit(ui->lineEdit_Wert);

    if(object == ui->lineEdit_TSA)
        check_LineEdit(ui->lineEdit_TSA, true);*/

    if(object == ui->lineEdit_Wert)
        eventFilter_Wert(ev);

    if(object == ui->lineEdit_DFA)
        eventFilter_DFA(ev);
    return false;
}

void TP_Kante::eventFilter_DFA(QEvent *event)
{
    if (event->type() == QEvent::FocusIn)
    {
        if(ui->comboBox_Messrichtung->currentText() == "+" &&
            ui->comboBox_Messachse->currentText() == "X")
        {
            emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Kante/X_Plus3.png"));
        }
    }

    if (event->type() == QEvent::FocusIn)
    {
        if(ui->comboBox_Messrichtung->currentText() == "-" &&
            ui->comboBox_Messachse->currentText() == "X")
        {
            emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Kante/X_Minus3.png"));
        }
    }

    if (event->type() == QEvent::FocusIn)
    {
        if(ui->comboBox_Messrichtung->currentText() == "+" &&
            ui->comboBox_Messachse->currentText() == "Y")
        {
            emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Kante/Y_Plus3.png"));
        }
    }

    if (event->type() == QEvent::FocusIn)
    {
        if(ui->comboBox_Messrichtung->currentText() == "-" &&
            ui->comboBox_Messachse->currentText() == "Y")
        {
            emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Kante/Y_Minus3.png"));
        }
    }

    if (event->type() == QEvent::FocusIn)
    {
        if(ui->comboBox_Messrichtung->currentText() == "-" &&
            ui->comboBox_Messachse->currentText() == "Z")
        {
            emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Kante/Z_Minus3.png"));
        }
    }
}

void TP_Kante::eventFilter_Wert(QEvent *event)
{
    if (event->type() == QEvent::FocusIn)
    {
        if(ui->comboBox_Messrichtung->currentText() == "+" &&
            ui->comboBox_Messachse->currentText() == "X")
        {
            emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Kante/X_Plus2.png"));
        }
    }


    if (event->type() == QEvent::FocusIn)
    {
        if(ui->comboBox_Messrichtung->currentText() == "-" &&
            ui->comboBox_Messachse->currentText() == "X")
        {
            emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Kante/X_Minus2.png"));
        }
    }

    if (event->type() == QEvent::FocusIn)
    {
        if(ui->comboBox_Messrichtung->currentText() == "+" &&
            ui->comboBox_Messachse->currentText() == "Y")
        {
            emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Kante/Y_Plus2.png"));
        }
    }

    if (event->type() == QEvent::FocusIn)
    {
        if(ui->comboBox_Messrichtung->currentText() == "-" &&
            ui->comboBox_Messachse->currentText() == "Y")
        {
            emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Kante/Y_Minus2.png"));
        }
    }

    if (event->type() == QEvent::FocusIn)
    {
        if(ui->comboBox_Messrichtung->currentText() == "-" &&
            ui->comboBox_Messachse->currentText() == "Z")
        {
            emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Kante/Z_Minus2.png"));
        }
    }
}

void TP_Kante::set_Anfahren()
{
    this->read_Anfahren();
    foreach(QString str, stringList_ContentAnfahren)
    {
        ui->textEdit_Anfahren->append(str);
    }
}

QStringList TP_Kante::postProcessing()
{
    QString string_CYCLE978;
    QString string_CYCL800;
    string_HeaderLine = "";

    stringList_PostProcessing.clear();

    //A und C Achsen definieren
    switch(ui->comboBox_Frame->currentIndex())
    {
    case 0:
        string_CYCL800= "CYCLE800(1,\"HERMLE\",100000,39,0,0,0,0,0,0,0,0,0,-1,100,1)";
        break;

    case 1:
        string_CYCL800 = "CYCLE800(1,\"HERMLE\",100000,39,0,0,0,0,-90,0,0,0,0,-1,100,1)";
        break;

    case 2:
        string_CYCL800 = "CYCLE800(1,\"HERMLE\",100000,39,0,0,0,90,-90,0,0,0,0,-1,100,1)";
        break;

    case 3:
        string_CYCL800 = "CYCLE800(1,\"HERMLE\",100000,39,0,0,0,180,-90,0,0,0,0,-1,100,1)";
        break;

    case 4:
        string_CYCL800 = "CYCLE800(1,\"HERMLE\",100000,39,0,0,0,-90,-90,0,0,0,0,-1,100,1)";
        break;
    }

    //Cyclus einrichten
    if(ui->comboBox_Messrichtung->currentText() == "+" &&
        ui->comboBox_Messachse->currentText() == "X")
    {
        string_CYCLE978 = "CYCLE978(100,9000,,1,$Wert$,$DFA$,$TSA$,1,1,1,\"\",,0,1.01,1.01,-1.01,0.34,1,0,,1,1)";
    }

    if(ui->comboBox_Messrichtung->currentText() == "-" &&
        ui->comboBox_Messachse->currentText() == "X")
    {
        string_CYCLE978 = "CYCLE978(100,9000,,1,$Wert$,$DFA$,$TSA$,1,2,1,\"\",,0,1.01,1.01,-1.01,0.34,1,0,,1,1)";
    }

    if(ui->comboBox_Messrichtung->currentText() == "+" &&
        ui->comboBox_Messachse->currentText() == "Y")
    {
        string_CYCLE978 = "CYCLE978(100,9000,,1,$Wert$,$DFA$,$TSA$,2,1,1,\"\",,0,1.01,1.01,-1.01,0.34,1,0,,1,1)";
    }

    if(ui->comboBox_Messrichtung->currentText() == "-" &&
        ui->comboBox_Messachse->currentText() == "Y")
    {
        string_CYCLE978 = "CYCLE978(100,9000,,1,$Wert$,$DFA$,$TSA$,2,2,1,\"\",,0,1.01,1.01,-1.01,0.34,1,0,,1,1)";
    }

    if(ui->comboBox_Messrichtung->currentText() == "-" &&
        ui->comboBox_Messachse->currentText() == "Z")
    {
        string_CYCLE978 = "CYCLE978(100,9000,,1,$Wert$,$DFA$,$TSA$,3,2,1,\"\",,0,1.01,1.01,-1.01,0.34,1,0,,1,1)";
    }

    if(ui->pushButton_NPV->text() == "nur Messen")
        string_CYCLE978 = string_CYCLE978.replace("100,9000", "0,");
    //Tisch schwenken
    stringList_PostProcessing.append("                                                                          ");
    create_NewHeaderLine();
    stringList_PostProcessing.append(frame_HeaderLine());
    stringList_PostProcessing.append("G75 Z1");
    stringList_PostProcessing.append(string_CYCL800);

    //Body_Kante
    if(ui->pushButton_NPV->text() == "nur Messen")
        mfile->setFileName(QDir::homePath() + "/CamHelper/config/TouchProbe/Body_Kante_Messen.txt");
    else
        mfile->setFileName(QDir::homePath() + "/CamHelper/config/TouchProbe/Body_Kante.txt");
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
        str = str.replace("$CYCLE978$", string_CYCLE978);
        str = str.replace("$Wert$", replace_Comma(ui->lineEdit_Wert->text()));
        str = str.replace("$DFA$", replace_Comma(ui->lineEdit_DFA->text()));
        str = str.replace("$TSA$", replace_Comma(ui->lineEdit_TSA->text()));

        if(str.contains("$Anfahren$"))
        {
            foreach (QString str_Anfahren, ui->textEdit_Anfahren->toPlainText().split("\n"))
            {
                str_Anfahren = str_Anfahren.replace(",", ".");
                str_Anfahren = str_Anfahren.replace("$CYCLE978$", string_CYCLE978);
                str_Anfahren = str_Anfahren.replace("$Wert$", replace_Comma(ui->lineEdit_Wert->text()));
                str_Anfahren = str_Anfahren.replace("$DFA$", replace_Comma(ui->lineEdit_DFA->text()));
                str_Anfahren = str_Anfahren.replace("$TSA$", replace_Comma(ui->lineEdit_TSA->text()));
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

void TP_Kante::setPixmap()
{
    if(ui->comboBox_Messachse->currentText() == "Z")
    {
        emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Kante/Z_Minus1.png"));
    }

    if(ui->comboBox_Messrichtung->currentText() == "+" &&
        ui->comboBox_Messachse->currentText() == "X")
    {
        emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Kante/X_Plus1.png"));
    }

    if(ui->comboBox_Messrichtung->currentText() == "-" &&
        ui->comboBox_Messachse->currentText() == "X")
    {
        emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Kante/X_Minus1.png"));
    }

    if(ui->comboBox_Messrichtung->currentText() == "-" &&
        ui->comboBox_Messachse->currentText() == "Y")
    {
        emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Kante/Y_Minus1.png"));
    }

    if(ui->comboBox_Messrichtung->currentText() == "+" &&
        ui->comboBox_Messachse->currentText() == "Y")
    {
        emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Kante/Y_Plus1.png"));
    }
}

void TP_Kante::slot_currentFrameChanged(QString str)
{
    Q_UNUSED(str);

    create_NewHeaderLine();
    emit sig_ReCreate();
}

void TP_Kante::create_NewHeaderLine()
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

        //X+ antasten
        if(ui->comboBox_Messrichtung->currentText() == "+" && ui->comboBox_Messachse->currentText() == "X")
        {
            string_HeaderLine = "X+ " + string_HeaderLine;
        }

        //X- antasten
        if(ui->comboBox_Messrichtung->currentText() == "-" && ui->comboBox_Messachse->currentText() == "X")
        {
            string_HeaderLine = "X- " + string_HeaderLine;
        }

        //Y+ antasten
        if(ui->comboBox_Messrichtung->currentText() == "+" && ui->comboBox_Messachse->currentText() == "Y")
        {
            string_HeaderLine = "Y+ " + string_HeaderLine;
        }
        //Y- antasten
        if(ui->comboBox_Messrichtung->currentText() == "-" && ui->comboBox_Messachse->currentText() == "Y")
        {
            string_HeaderLine = "Y- " + string_HeaderLine;
        }

        if(ui->comboBox_Messrichtung->currentText() == "-" && ui->comboBox_Messachse->currentText() == "Z")
        {
            string_HeaderLine = "Z- " + string_HeaderLine;
        }

    string_HeaderLine = string_HeaderLine + " Wert: " + ui->label_Wert->text().remove("0") + " " + ui->lineEdit_Wert->text();
    string_HeaderLine = "Kante " + string_HeaderLine;
    emit sig_NewHeaderLine(string_HeaderLine);
}

void TP_Kante::slot_setTextFromCilpBoard()
{
    QString text = clipboard->text();

    if(!text.isEmpty())
        check_Clipboard(text);

    set_TextEditAnfahren();
}

void TP_Kante::set_TextEditAnfahren()
{
    QString string;
    this->read_Anfahren();
    ui->textEdit_Anfahren->clear();
    set_Anfahren();

    if(string_X.isEmpty() || string_Y.isEmpty() || string_Z.isEmpty())
            return;

    if(ui->comboBox_Messachse->currentText() == "Z")
       read_Anfahren("Anfahren_KanteZ.txt");
    else if (ui->pushButton_NPV->text() == "nur Messen")
        read_Anfahren("Anfahren_KanteXY_Messen.txt");
    else
        read_Anfahren("Anfahren_KanteXY.txt");

    ui->textEdit_Anfahren->clear();

    //Wenn die Messrichtung in Z ist
    if(ui->comboBox_Messachse->currentText() == "Z")
    {
       ui->lineEdit_Wert->setText(string_Z);
        foreach(QString str, stringList_ContentAnfahren)
        {
            str = str.replace("$Z$", string_Z);
            str = str.replace("$X$", string_X);
            str = str.replace("$Y$", string_Y);

            ui->textEdit_Anfahren->append(str);
        }
    }

    if(ui->comboBox_Messachse->currentText() == "X" && ui->comboBox_Messrichtung->currentText() == "+")
    {
        ui->lineEdit_Wert->setText(string_X);
        string = "=(" + string_X + "-7)";
        foreach(QString str, stringList_ContentAnfahren)
        {
            str = str.replace("$Z$", string_Z);
            str = str.replace("$X$", string);
            str = str.replace("$Y$", string_Y);

            ui->textEdit_Anfahren->append(str);
        }
    }

    if(ui->comboBox_Messachse->currentText() == "X" && ui->comboBox_Messrichtung->currentText() == "-")
    {
        ui->lineEdit_Wert->setText(string_X);
        string = "=(" + string_X + "+7)";
        foreach(QString str, stringList_ContentAnfahren)
        {
            str = str.replace("$Z$", string_Z);
            str = str.replace("$X$", string);
            str = str.replace("$Y$", string_Y);

            ui->textEdit_Anfahren->append(str);
        }
    }

    if(ui->comboBox_Messachse->currentText() == "Y" && ui->comboBox_Messrichtung->currentText() == "+")
    {
        ui->lineEdit_Wert->setText(string_Y);
        string = "=(" + string_Y + "-7)";
        foreach(QString str, stringList_ContentAnfahren)
        {
            str = str.replace("$Z$", string_Z);
            str = str.replace("$X$", string_X);
            str = str.replace("$Y$", string);

            ui->textEdit_Anfahren->append(str);
        }
    }

    if(ui->comboBox_Messachse->currentText() == "Y" && ui->comboBox_Messrichtung->currentText() == "-")
    {
        ui->lineEdit_Wert->setText(string_Y);
        string = "=(" + string_Y + "+7)";
        foreach(QString str, stringList_ContentAnfahren)
        {
            str = str.replace("$Z$", string_Z);
            str = str.replace("$X$", string_X);
            str = str.replace("$Y$", string);

            ui->textEdit_Anfahren->append(str);
        }
    }
    clipboard->clear(QClipboard::Clipboard);
}

void TP_Kante::slot_NPVClicked()
{
    if(ui->pushButton_NPV->text() == "aktive NPV")
    {
        ui->pushButton_NPV->setText("nur Messen");
        set_TextEditAnfahren();
    }
    else
    {
        ui->pushButton_NPV->setText("aktive NPV");
        set_TextEditAnfahren();
    }
}
