#ifndef TP_EBENHEIT_H
#define TP_EBENHEIT_H

#include <QWidget>
#include <QClipboard>
#include <QLineEdit>

#include "tp_base.h"
#include "tp_struct.h"

namespace Ui {
class TP_Ebenheit;
}

class TP_Ebenheit : public TP_Base
{
    Q_OBJECT
private:
    Ui::TP_Ebenheit *ui;
    QStringList stringList_PostProcessing;
    QStringList stringList_Ebenheit;
    QClipboard* clipboard;


protected:
    //bool eventFilter(QObject *obj, QEvent *ev) override;

public:
    explicit TP_Ebenheit(QWidget *parent = nullptr);
    ~TP_Ebenheit();
    void set_Data(Struct_Ebenheit);
    Struct_Ebenheit get_Data();
    QStringList postProcessing();
    QStringList postProcessing_Ebenheit();
    void setPixmap();
    void create_NewHeaderLine();

public slots:
    void slot_setTextFromCilpBoard();
};

#endif // TP_EBENHEIT_H
