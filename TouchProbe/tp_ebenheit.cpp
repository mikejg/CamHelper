#include "tp_ebenheit.h"
#include "ui_tp_ebenheit.h"

TP_Ebenheit::TP_Ebenheit(QWidget *parent) :
    TP_Base(parent),
    ui(new Ui::TP_Ebenheit)
{
    ui->setupUi(this);
    clipboard = QApplication::clipboard();

    palette = ui->lineEdit_Vertrauensbereich->palette();
    backroundColor = palette.color(QPalette::Base);
    palette.setColor(QPalette::Base, Qt::darkRed);
    ui->lineEdit_Vertrauensbereich->setPalette(palette);

    ui->lineEdit_ZEbene->installEventFilter(this);
    ui->lineEdit_Vertrauensbereich->installEventFilter(this);
    ui->lineEdit_Punkt1X->installEventFilter(this);
    ui->lineEdit_Punkt1Y->installEventFilter(this);
    ui->lineEdit_Punkt2X->installEventFilter(this);
    ui->lineEdit_Punkt2Y->installEventFilter(this);

    connect(ui->toolButton_Paste, SIGNAL(released()),this, SLOT(slot_setTextFromCilpBoard()));
    connect(ui->toolButton_PasteP1, SIGNAL(released()),this, SLOT(slot_setTextFromCilpBoard()));
    connect(ui->toolButton_PasteP2, SIGNAL(released()),this, SLOT(slot_setTextFromCilpBoard()));
    connect(ui->toolButton_PasteP3, SIGNAL(released()),this, SLOT(slot_setTextFromCilpBoard()));
    connect(ui->toolButton_PasteP4, SIGNAL(released()),this, SLOT(slot_setTextFromCilpBoard()));
}

TP_Ebenheit::~TP_Ebenheit()
{
    delete ui;
}



bool TP_Ebenheit::eventFilter(QObject *object, QEvent *event)
{
    if(object == ui->lineEdit_Vertrauensbereich)
        check_LineEdit(ui->lineEdit_Vertrauensbereich);

    if(object == ui->lineEdit_ZEbene)
        check_LineEdit(ui->lineEdit_ZEbene);

    if(object == ui->lineEdit_Punkt1X)
        check_LineEdit(ui->lineEdit_Punkt1X);

    if(object == ui->lineEdit_Punkt1Y)
        check_LineEdit(ui->lineEdit_Punkt1Y);

    if(object == ui->lineEdit_Punkt2X)
        check_LineEdit(ui->lineEdit_Punkt2X);

    if(object == ui->lineEdit_Punkt2Y)
        check_LineEdit(ui->lineEdit_Punkt2Y);

    if (event->type() == QEvent::FocusIn)
    {}

    if (event->type() == QEvent::FocusOut)
    {}

    return false;
}

Struct_Ebenheit TP_Ebenheit::get_Data()
{
    Struct_Ebenheit struct_Ebenheit;

    struct_Ebenheit.string_Frame = ui->comboBox_Frame->currentText();
    struct_Ebenheit.string_ZEbene = ui->lineEdit_ZEbene->text();
    struct_Ebenheit.string_Vertrauensbereich = ui->lineEdit_Vertrauensbereich->text();
    struct_Ebenheit.string_Punkt1X = ui->lineEdit_Punkt1X->text();
    struct_Ebenheit.string_Punkt1Y = ui->lineEdit_Punkt1Y->text();
    struct_Ebenheit.string_Punkt2X = ui->lineEdit_Punkt2X->text();
    struct_Ebenheit.string_Punkt2Y = ui->lineEdit_Punkt2Y->text();
    struct_Ebenheit.string_Punkt3X = ui->lineEdit_Punkt3X->text();
    struct_Ebenheit.string_Punkt3Y = ui->lineEdit_Punkt3Y->text();
    struct_Ebenheit.string_Punkt4X = ui->lineEdit_Punkt4X->text();
    struct_Ebenheit.string_Punkt4Y = ui->lineEdit_Punkt4Y->text();
    struct_Ebenheit.bool_Jump1 = ui->checkBox_Jump1->isChecked();
    struct_Ebenheit.bool_Jump2 = ui->checkBox_Jump2->isChecked();
    struct_Ebenheit.bool_Jump3 = ui->checkBox_Jump3->isChecked();

    return struct_Ebenheit;
}

void TP_Ebenheit::set_Data(Struct_Ebenheit struct_Ebenheit)
{
    //Füllt die Felder mit den Werten aus der Datenbank aus
    ui->comboBox_Frame->setCurrentText(struct_Ebenheit.string_Frame);
    ui->lineEdit_Vertrauensbereich->setText(struct_Ebenheit.string_Vertrauensbereich);
    ui->lineEdit_ZEbene->setText(struct_Ebenheit.string_ZEbene);
    ui->lineEdit_Punkt1X->setText(struct_Ebenheit.string_Punkt1X);
    ui->lineEdit_Punkt1Y->setText(struct_Ebenheit.string_Punkt1Y);
    ui->lineEdit_Punkt2X->setText(struct_Ebenheit.string_Punkt2X);
    ui->lineEdit_Punkt2Y->setText(struct_Ebenheit.string_Punkt2Y);
    ui->lineEdit_Punkt3X->setText(struct_Ebenheit.string_Punkt3X);
    ui->lineEdit_Punkt3Y->setText(struct_Ebenheit.string_Punkt3Y);
    ui->lineEdit_Punkt4X->setText(struct_Ebenheit.string_Punkt4X);
    ui->lineEdit_Punkt4Y->setText(struct_Ebenheit.string_Punkt4Y);
    ui->checkBox_Jump1->setChecked(struct_Ebenheit.bool_Jump1);
    ui->checkBox_Jump2->setChecked(struct_Ebenheit.bool_Jump2);
    ui->checkBox_Jump3->setChecked(struct_Ebenheit.bool_Jump3);
}

QStringList TP_Ebenheit::postProcessing()
{
    QString string_Frame;

    stringList_PostProcessing.clear();

    switch(ui->comboBox_Frame->currentIndex())
    {
    case 0:
        string_Frame = "  Frame Oben  ";
        break;

    case 1:
        string_Frame = " Frame Hinten ";
        break;

    case 2:
        string_Frame = " Frame Links  ";
        break;

    case 3:
        string_Frame = "  Frame Vorne ";
        break;

    case 4:
        string_Frame = " Frame Rechts ";
        break;
    }

    //Tisch schwenken
    stringList_PostProcessing.append("                                                                          ");
    create_NewHeaderLine();
    stringList_PostProcessing.append(frame_HeaderLine());
    //stringList_PostProcessing.append("G75 Z1");
    //stringList_PostProcessing.append(string_CYCL800);

    //Body_Ebenheit
    mfile->setFileName(QDir::homePath() + "/CamHelper/config/TouchProbe/Ebenheit.txt");
    mfile->read_Content();
    stringList_Content = mfile->get_Content();
    foreach(QString str, stringList_Content)
        stringList_PostProcessing.append(str);

    //StringList_PostProcessing Parsen
    /*QStringList stringList_Temp = stringList_PostProcessing;
    stringList_PostProcessing.clear();
    foreach (QString str, stringList_Temp)
    {
        stringList_PostProcessing.append(str);
    }*/


    return stringList_PostProcessing;
}

QStringList TP_Ebenheit::postProcessing_Ebenheit()
{

    stringList_Ebenheit.clear();
    QString string_CYCL800;
    QString string_Punkt;

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


    mfile->setFileName(QDir::homePath() + "/CamHelper/config/TouchProbe/_Ebenheit.SPF");
    mfile->read_Content();
    stringList_Content = mfile->get_Content();
    foreach(QString str, stringList_Content)
    {
        if(str.startsWith("#"))
            continue;

        str = str.replace("$CYCL800$", string_CYCL800);
        str = str.replace("$Z_Ebene$", replace_Comma(ui->lineEdit_ZEbene->text()));
        str = str.replace("$VBereich$", replace_Comma(ui->lineEdit_Vertrauensbereich->text()));

        if(!ui->lineEdit_Punkt1X->text().isEmpty() && !ui->lineEdit_Punkt1Y->text().isEmpty())
        {
            string_Punkt = "Px = " + replace_Comma(ui->lineEdit_Punkt1X->text());
            str = str.replace("$Px$", string_Punkt);

            string_Punkt = "Py = " + replace_Comma(ui->lineEdit_Punkt1Y->text());
            str = str.replace("$Py$", string_Punkt);
        }

        if(!ui->lineEdit_Punkt2X->text().isEmpty() && !ui->lineEdit_Punkt2Y->text().isEmpty())
        {
            string_Punkt = "Px1 = " + replace_Comma(ui->lineEdit_Punkt2X->text());
            str = str.replace("$Px1$", string_Punkt);

            string_Punkt = "Py1 = " + replace_Comma(ui->lineEdit_Punkt2Y->text());
            str = str.replace("$Py1$", string_Punkt);
        }

        if(!ui->lineEdit_Punkt3X->text().isEmpty() && !ui->lineEdit_Punkt3Y->text().isEmpty())
        {
            string_Punkt = "Px2 = " + replace_Comma(ui->lineEdit_Punkt3X->text());
            str = str.replace("$Px2$", string_Punkt);

            string_Punkt = "Py2 = " + replace_Comma(ui->lineEdit_Punkt3Y->text());
            str = str.replace("$Py2$", string_Punkt);
        }
        else
        {
            str = str.replace("$Px2$", ";Px2 = 0 ; X für MessPunkt 2");
            str = str.replace("$Py2$", ";Py2 = 0 ; Y für MessPunkt 2");
        }

        if(!ui->lineEdit_Punkt4X->text().isEmpty() && !ui->lineEdit_Punkt4Y->text().isEmpty())
        {
            string_Punkt = "Px3 = " + replace_Comma(ui->lineEdit_Punkt4X->text());
            str = str.replace("$Px3$", string_Punkt);

            string_Punkt = "Py3 = " + replace_Comma(ui->lineEdit_Punkt4Y->text());
            str = str.replace("$Py3$", string_Punkt);
        }
        else
        {
            str = str.replace("$Px3$", ";Px3 = 0 ; X für MessPunkt 2");
            str = str.replace("$Py3$", ";Py3 = 0 ; Y für MessPunkt 2");
        }

        //Wenn die CheckBox gesetzt ist füge Sprungbefehle ein
        if(ui->checkBox_Jump1->isChecked())
        {
            str = str.replace("$UP1$", "G01 Z=(ANTAST_EBENE+50) F3000");
            str = str.replace("$DOWN1$", "G01 Z=(ANTAST_EBENE+10) F3000");
        }

        if(ui->checkBox_Jump2->isChecked())
        {
            str = str.replace("$UP2$", "G01 Z=(ANTAST_EBENE+50) F3000");
            str = str.replace("$DOWN2$", "G01 Z=(ANTAST_EBENE+10) F3000");
        }

        if(ui->checkBox_Jump3->isChecked())
        {
            str = str.replace("$UP3$", "G01 Z=(ANTAST_EBENE+50) F3000");
            str = str.replace("$DOWN3$", "G01 Z=(ANTAST_EBENE+10) F3000");
        }

        //Wenn keine Sprungbefehle eingesetzt wurden loesche Platzhalter
        if(str.contains("$UP1$"))
            continue;
        if(str.contains("DOWN1$"))
            continue;
        if(str.contains("$UP2$"))
            continue;
        if(str.contains("DOWN2$"))
            continue;
        if(str.contains("$UP3$"))
            continue;
        if(str.contains("DOWN3$"))
            continue;
        stringList_Ebenheit.append(str);
    }

    return stringList_Ebenheit;
}

void TP_Ebenheit::setPixmap()
{
    emit sig_NewPixmap(QPixmap(":/Icons/TouchProbe/Ebenheit/Ebenheit_01.png"));
}

void TP_Ebenheit::create_NewHeaderLine()
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

    string_HeaderLine = "Ebenheit " + string_HeaderLine;
}

void TP_Ebenheit::slot_setTextFromCilpBoard()
{
    double double_X, double_Y, double_Value;
    bool boolOK_X, boolOK_Y;

    QString text = clipboard->text();

    if(!text.isEmpty())
        check_Clipboard(text);

    if(string_X.isEmpty() || string_Y.isEmpty() || string_Z.isEmpty())
        return;

    //Wenn sich string_X oder string_Y in kein Double konvertrieren lassen
    //wird hier abgebrochen
    double_X = string_X.toDouble(&boolOK_X);
    double_Y = string_Y.toDouble(&boolOK_Y);
    if(!boolOK_X || !boolOK_Y)
        return;

    ui->lineEdit_ZEbene->setText(string_Z);

    if(sender() == ui->toolButton_Paste)
    {
        ui->lineEdit_Punkt1X->setText(string_X);
        ui->lineEdit_Punkt1Y->setText(string_Y);

        double_Value = double_Y * (-1);
        ui->lineEdit_Punkt2X->setText(string_X);
        ui->lineEdit_Punkt2Y->setText(QString::number(double_Value, 'f', 3));

        double_Value = double_X * (-1);
        ui->lineEdit_Punkt3X->setText(QString::number(double_Value, 'f', 3));
        double_Value = double_Y * (-1);
        ui->lineEdit_Punkt3Y->setText(QString::number(double_Value, 'f', 3));

        double_Value = double_X * (-1);
        ui->lineEdit_Punkt4X->setText(QString::number(double_Value, 'f', 3));
        ui->lineEdit_Punkt4Y->setText(string_Y);
    }

    if(sender() == ui->toolButton_PasteP1)
    {
        ui->lineEdit_Punkt1X->setText(string_X);
        ui->lineEdit_Punkt1Y->setText(string_Y);
    }

    if(sender() == ui->toolButton_PasteP2)
    {
        ui->lineEdit_Punkt2X->setText(string_X);
        ui->lineEdit_Punkt2Y->setText(string_Y);
    }

    if(sender() == ui->toolButton_PasteP3)
    {
        ui->lineEdit_Punkt3X->setText(string_X);
        ui->lineEdit_Punkt3Y->setText(string_Y);
    }

    if(sender() == ui->toolButton_PasteP4)
    {
        ui->lineEdit_Punkt4X->setText(string_X);
        ui->lineEdit_Punkt4Y->setText(string_Y);
    }

    clipboard->clear(QClipboard::Clipboard);
}
