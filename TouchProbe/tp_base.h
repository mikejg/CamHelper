#ifndef TP_BASE_H
#define TP_BASE_H

#include <QWidget>
#include <QDir>
#include <QLineEdit>
#include "../Classes/mfile.h"
#include "../Logging/logging.h"

//namespace Ui {
//class TP_Base;
//}

class TP_Base : public QWidget
{
    Q_OBJECT

private:
    //Ui::TP_Base *ui;


protected:
    Logging* log;
    MFile*   mfile;
    QString  replace_Comma(QString);
    QString  string_HeaderLine;
    QString  string_X;
    QString  string_Y;
    QString  string_Z;
    //QPalette palette;
    QColor backroundColor;

    QStringList frame_HeaderLine();
    QString     filter_Value(QString);
    //void check_LineEdit(QLineEdit*, bool bool_Unsigned = false);

public:
    explicit TP_Base(QWidget *parent = nullptr);
    ~TP_Base();
    QStringList stringList_ContentAnfahren;
    QStringList stringList_Content;
    void read_Anfahren();
    void read_Anfahren(QString);
    void set_Logging (Logging*);
    void check_Clipboard(QString);

signals:
    void sig_NewPixmap(QPixmap);
    void sig_ReCreate();
    void sig_NewHeaderLine(QString);
};

#endif // TP_BASE_H
