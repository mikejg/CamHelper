#ifndef TP_NUT_H
#define TP_NUT_H

#include <QWidget>
#include <QClipboard>

#include "tp_base.h"
#include "tp_struct.h"
#include "tp_highlighter.h"

namespace Ui {
class TP_Nut;
}

class TP_Nut : public TP_Base
{
    Q_OBJECT

private:
    Ui::TP_Nut *ui;
    //void eventFilter_Wert(QEvent*);
    void eventFilter_TSA(QEvent*);
    QClipboard* clipboard;
    TP_HighLighter* tp_HighLighter;
    QStringList stringList_PostProcessing;

protected:
    bool eventFilter(QObject *obj, QEvent *ev) override;

public:
    explicit TP_Nut(QWidget *parent = nullptr);
    ~TP_Nut();

    void create_NewHeaderLine();
    void set_Anfahren();
    void setPixmap();
    QStringList postProcessing();
    Struct_Nut get_Data();
    void set_Data(Struct_Nut);

public slots:
    void slot_AxesChanged(QString);
    void slot_setTextFromCilpBoard();
};

#endif // TP_NUT_H
