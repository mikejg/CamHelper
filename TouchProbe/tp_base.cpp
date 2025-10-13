#include "tp_base.h"

//#include "ui_tp_base.h"

/*TP_Base::TP_Base(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TP_Base)*/

TP_Base::TP_Base(QWidget *parent) :
      QWidget(parent)
{
    //mfile = new MFile(this);

}

TP_Base::~TP_Base()
{

}

void TP_Base::check_Clipboard(QString string_Text)
{
    string_X = "";
    string_Y = "";
    string_Z = "";

    // zerlege den String in Zeilen
    QStringList stringList = string_Text.split("\n");

    //geh durch alle Zeilen
    for(int i = 0; i<stringList.size(); i++)
    {
        // Wenn in der Zeile das Schlüsselwort Endpunkt vorkommt lies
        // die nächsten 3 Zeilen ein
        if(stringList.at(i).contains("Endpunkt") && i+3 < stringList.size())
        {
            string_X = stringList.at(i+1);
            string_Y = stringList.at(i+2);
            string_Z = stringList.at(i+3);
        }
    }

    if(!string_X.isEmpty())
        string_X = filter_Value(string_X);
    if(!string_Y.isEmpty())
        string_Y = filter_Value(string_Y);
    if(!string_Z.isEmpty())
        string_Z = filter_Value(string_Z);

    //qDebug() << string_X << string_Y << string_Z;

}

/*void TP_Base::check_LineEdit(QLineEdit* lineEdit, bool bool_Unsigned)
{
    double double_Value;
    QString string_Text = lineEdit->text();
    if(string_Text.contains(","))
    {
        string_Text = string_Text.replace("," , ".");
        lineEdit->setText(string_Text);
    }
    bool bool_ok;
    double_Value = lineEdit->text().toDouble(&bool_ok);

    //Wenn die Konvertierung des Strings zu Double erfolgreich war setze die normale
    //Hintergrundfarbe. Wenn sie fehlschlägt setze Rot
    if(bool_ok)
        palette.setColor(QPalette::Base, backroundColor);
    else
        palette.setColor(QPalette::Base, Qt::darkRed);

    // Wenn die Konvertierung geklappt hat, aber der Wert
    // kein Vorzeichen haben soll, der Wert aber ein Vorzeichen hat
    // weil der Wert kleiner 0 ist
    // dann setze Rot.
    if(bool_ok && bool_Unsigned && double_Value < 0)
    {
        palette.setColor(QPalette::Base, Qt::darkRed);
    }
    lineEdit->setPalette(palette);
}*/

QString TP_Base::filter_Value(QString string)
{
    double double_Value;
    bool bool_OK;
    QStringList stringList_Parts;
    QString string_Return;

    stringList_Parts = string.split(" ");
    foreach(QString str, stringList_Parts)
    {
        str.toDouble(&bool_OK);
        if(bool_OK)
        {
            double_Value = str.toDouble(&bool_OK);
            break;
        }
    }

    // runde auf 3 stellen nach dem komma ab
    if(bool_OK)
        string_Return = QString::number(double_Value, 'f', 3);
    return string_Return;
}

void TP_Base::read_Anfahren(QString string_File)
{
    mfile->setFileName(QDir::homePath() + "/CamHelper/config/TouchProbe/" + string_File);
    mfile->read_Content();
    stringList_ContentAnfahren = mfile->get_Content();
}

void TP_Base::read_Anfahren()
{
    mfile->setFileName(QDir::homePath() + "/CamHelper/config/TouchProbe/Anfahren.txt");
    mfile->read_Content();
    stringList_ContentAnfahren = mfile->get_Content();
}

QString TP_Base::replace_Comma(QString str)
{
    QString returnString;
    returnString = str.replace(",",".");
    while(returnString.endsWith("0") && returnString.contains("."))
    {
        returnString = returnString.left(returnString.length()-1);
        //qDebug() << returnString;
    }
    return returnString;
}

void TP_Base::set_Logging(Logging* l)
{
    //qDebug() << Q_FUNC_INFO;
    log = l;
    mfile = new MFile(this, log);
}

QStringList TP_Base::frame_HeaderLine()
{
    // Zieht einen ASCII Rahmen um string_HeaderLine */

    QStringList stringList;
    int     maxLength = 0;
    QString string_Bar;

    maxLength = string_HeaderLine.length();

    while(maxLength < 55)
    {
        string_HeaderLine = " " + string_HeaderLine + " ";
        maxLength = string_HeaderLine.length();
    }

    // Erzeuge einen Balken mit der länge der
    // längsten Fehlermeldung
    // und hänge am Schluss noch mal 3 '-' an
    string_Bar = "+";
    while(string_Bar.length() <= maxLength)
    {
        string_Bar = string_Bar + "-";
    }
    string_Bar = string_Bar +"--+";

    // gib den Balken als oberen Balken aus
    stringList.append("; " + string_Bar);

    // gib die Kopfzeile aus
    stringList.append("; | " + string_HeaderLine + " |");

    // gib den Balken als unteren Balken aus
    stringList.append("; " + string_Bar);

    return stringList;
}

