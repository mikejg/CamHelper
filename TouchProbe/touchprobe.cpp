#include "touchprobe.h"
#include "ui_touchprobe.h"

TouchProbe::TouchProbe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TouchProbe)
{
    ui->setupUi(this);
    ui->textEdit->hide();

    bool_Create = false;

    // Highlighter
    tp_HighLighter = new TP_HighLighter(ui->textEdit->document());
    tp_HighLighter->set_TextEdit(ui->textEdit);

    //connect(tp_HighLighter, SIGNAL(sig_NewTextCursor(QTextCursor)), this, SLOT(slot_NewTextCursor(QTextCursor)));

    ui->scrollAreaWidgetContents->set_Layout(ui->verticalLayout_scrollArea);
    ui->scrollAreaWidgetContents->set_SpacerItem(ui->verticalSpacer_ScrollContent);
    ui->scrollAreaWidgetContents->set_HighLighter(tp_HighLighter);
    connect(ui->scrollAreaWidgetContents, SIGNAL(sig_NewPixmap(QPixmap)),
            this, SLOT(slot_NewPixmap(QPixmap)));
    connect(ui->scrollAreaWidgetContents, SIGNAL(sig_Create()),this, SLOT(slot_Create()));

    connect(ui->toolButton_Edit, SIGNAL(pressed()), this, SLOT(slot_Create()));
    connect(ui->toolButton_Pix, SIGNAL(pressed()), this, SLOT(slot_ShowPix()));
    connect(ui->toolButton_Export, SIGNAL(pressed()),this, SLOT(slot_Export()));

}

TouchProbe::~TouchProbe()
{
    delete ui;
}

void TouchProbe::clear()
{
    ui->scrollAreaWidgetContents->clear();
}
void TouchProbe::set_Logging(Logging *l)
{
    log = l;
    mfile = new MFile(this, log);
    ui->scrollAreaWidgetContents->set_Logging(log);
}

void TouchProbe::slot_Create()
{
    qDebug() << Q_FUNC_INFO << sender();

    // Wenn der ToolButton_Edit geklickt wurde und somit der Editor sichtbar
    // wird, setze bool_Create auf TRUE und erstelle das Antastprogramm neu.
    if(sender() == ui->toolButton_Edit || sender() == ui->toolButton_Export)
        bool_Create = true;

    // Erstelle das Antastprogramm nur neu wenn bool_Create TRUE ist. Ansonsten
    // brich die Funktion ab
    if(!bool_Create)
        return;

    createTouchprobe();
}

void TouchProbe::createTouchprobe()
{
    int_CounterEbenheit = 0;
    int pos = 1;
    //Loesche alles im Editor und schalte auf den Editor um
    ui->textEdit->clear();
    ui->label_Pix->hide();
    ui->textEdit->show();

    //Zaehler auf 0 setzen
    counter = 0;

    //Kopf für das Antastpromm laden und in den Editor
    //mittels der Funktion insert_Content einfürgen
    mfile->setFileName(QDir::homePath() + "/CamHelper/config/TouchProbe/Header.txt");
    mfile->read_Content();
    stringList_Content = mfile->get_Content();
    insert_Content();

    foreach(TP_Item* item, ui->scrollAreaWidgetContents->get_ItemList())
    {
        stringList_Content.clear();
        stringList_Content = item->postProcessing();
        insert_Content(item);
        if(item->get_State() == TP_Item::Ebenheit)
            int_CounterEbenheit++;
    }

    //Ende für das Antastpromm laden und in den Editor
    //mittels der Funktion insert_Content einfürgen
    mfile->setFileName(QDir::homePath() + "/CamHelper/config/TouchProbe/Footer.txt");
    mfile->read_Content();
    stringList_Content = mfile->get_Content();
    insert_Content();
}

void TouchProbe::slot_ShowPix()
{
    // Setze bool_Create auf FALSE und unterdrücke damit aufrufe von slot_Create
    // zum neuerstellen und anzeigen des Antastprogramms
    bool_Create = false;

    ui->textEdit->hide();
    ui->label_Pix->show();
}

/*void TouchProbe::slot_NewTextCursor(QTextCursor textCursor)
{
    qDebug() << Q_FUNC_INFO;
    ui->textEdit->setTextCursor(textCursor);
}*/

void TouchProbe::slot_NewPixmap(QPixmap p)
{
    ui->label_Pix->setPixmap(p);
}

void TouchProbe::insert_Item()
{
    ui->scrollAreaWidgetContents->slot_InsertItem();
}

void TouchProbe::insert_Item(QList<Item_TouchProbe> list)
{
    ui->scrollAreaWidgetContents->insertItem(list);
}

void TouchProbe::insert_Content()
{
    foreach (QString str, stringList_Content)
    {
        if(str.startsWith("#"))
            continue;

        counter++;
        //Header
        str = str.replace("$G5x$",  projectData->zeroPoint.string_G);

        str = QString("N%1 ").arg(counter) + str;
        ui->textEdit->append(str);
    }
}

void TouchProbe::insert_Content(TP_Item* tp_Item)
{
    QStringList stringList_LineNumber;
    foreach (QString str, stringList_Content)
    {
        if(str.startsWith("#"))
            continue;

        counter++;
        //Header
        str = str.replace("$G5x$",  projectData->zeroPoint.string_G);
        //Zähler für Ebenheit
        str = str.replace("$N$", QString("%1").arg(int_CounterEbenheit));

        str = QString("N%1 ").arg(counter) + str;
        ui->textEdit->append(str);
        stringList_LineNumber.append(QString("N%1 ").arg(counter));
    }
    tp_Item->set_LineNumber(stringList_LineNumber);
}

void TouchProbe::slot_Export()
{
    //Allei Einstellungen übernehmen und das Programm im Editor neu erstellen
    slot_Create();

    exportTouchprobe();
}

void TouchProbe::slot_ExportTouchprobe()
{
    createTouchprobe();
    exportTouchprobe();
}

void TouchProbe::exportTouchprobe()
{
    /* Muss noch umgeschrieben werden */
     /*
    QString str;
    QDir dir;
    // Wenn es ProjecName oder ProjectFullName leer sind wird nur in das Programmverzeichnis geschrieben
    // Programme\_Antasten.SPF
    if(project->get_ProjectName().isEmpty() || project->get_ProjectFullName().isEmpty())
    {
        str = project->get_ProgrammDir() + "_Antasten.SPF";
    }

    // Ansonsten wird in die Datei
    // Programme\E12345678.WPD\E12345678_E01_Sp2.WPD\_Antasten.SPF
    // geschrieben
    else
    {
        str = project->get_ProgrammDir() + "/"
              + project->get_ProjectName() + ".WPD/"
              + project->get_ProjectFullName() + ".WPD/_Antasten.SPF";

        // Wenn es das Verzeichnis
        // Programme\E12345678.WPD\E12345678_E01_Sp2.WPD
        // noch nicht gibt dann erstelle es
        dir.setPath(project->get_ProgrammDir() + "/"
                    + project->get_ProjectName() + ".WPD/"
                    + project->get_ProjectFullName() + ".WPD");

        if(!dir.exists())
        {
            dir.mkpath(project->get_ProgrammDir() + "/"
                       + project->get_ProjectName() + ".WPD/"
                       + project->get_ProjectFullName() + ".WPD");
        }
    }

    QFile file(str);

    if(file.open(QFile::WriteOnly))
    {
        //qDebug() << "File is open";
        //Oeffne stream und schreib jede Zeile aus textEdit in den Stream
        QTextStream stream(&file);
        foreach(QString string_Line, ui->textEdit->toPlainText().split("\n"))
        {
            //qDebug() << string_Line;
            stream << string_Line << "\n";
        }
        file.close();
    }

    export_Ebenheit();
    */
}

void TouchProbe::export_Ebenheit()
{
    /* Muss noch umgeschrieben werden */
    /*
    QString str;
    QDir dir;
    int_CounterEbenheit = 0;
    foreach(TP_Item* item, ui->scrollAreaWidgetContents->get_ItemList())
    {

        if(item->get_State() == TP_Item::Ebenheit)
        {
            counter = 0;
            stringList_Content.clear();
            foreach (QString str, item->postProcessing_Ebenheit())
            {
                if(str.startsWith("#"))
                    continue;

                counter++;
                //Header
                str = str.replace("$G5x$",  projectData->zeroPoint.string_G);

                str = QString("N%1 ").arg(counter) + str;
                stringList_Content.append(str);
            }
            //stringList_Content = item->postProcessing_Ebenheit();
            //insert_Content();

            // Wenn es ProjecName oder ProjectFullName leer sind wird nur in das Programmverzeichnis geschrieben
            // Programme\_C_Ausrichten.SPF
            if(project->get_ProjectName().isEmpty() || project->get_ProjectFullName().isEmpty())
            {
                str = project->get_ProgrammDir() + "_Ebenheit_" + QString("%1").arg(int_CounterEbenheit) + ".SPF";
            }

            // Ansonsten wird in die Datei
            // Programme\E12345678.WPD\E12345678_E01_Sp2.WPD\_C_Ausrichten.SPF
            // geschrieben
            else
            {
                str = project->get_ProgrammDir() + "/"
                      + project->get_ProjectName() + ".WPD/"
                      + project->get_ProjectFullName() + ".WPD/_Ebenheit_"
                      + QString("%1").arg(int_CounterEbenheit) + ".SPF";

                // Wenn es das Verzeichnis
                // Programme\E12345678.WPD\E12345678_E01_Sp2.WPD
                // noch nicht gibt dann erstelle es
                dir.setPath(project->get_ProgrammDir() + "/"
                            + project->get_ProjectName() + ".WPD/"
                            + project->get_ProjectFullName() + ".WPD");

                if(!dir.exists())
                {
                    dir.mkpath(project->get_ProgrammDir() + "/"
                               + project->get_ProjectName() + ".WPD/"
                               + project->get_ProjectFullName() + ".WPD");
                }
            }

            QFile file(str);

            if(file.open(QFile::WriteOnly))
            {
                //qDebug() << "File is open";
                //Oeffne stream und schreib jede Zeile aus textEdit in den Stream
                QTextStream stream(&file);
                foreach(QString string_Line, stringList_Content)
                {
                    //qDebug() << string_Line;
                    stream << string_Line << "\n";
                }
                file.close();
            }
            int_CounterEbenheit++;
        }
    }
    */
}

QList<TP_Item*> TouchProbe::get_ItemList()
{
    return ui->scrollAreaWidgetContents->get_ItemList();
}
