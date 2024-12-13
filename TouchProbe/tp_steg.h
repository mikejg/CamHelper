#ifndef TP_STEG_H
#define TP_STEG_H

#include <QWidget>
#include <QClipboard>

#include "tp_base.h"
#include "tp_struct.h"
#include "tp_highlighter.h"

namespace Ui {
class TP_Steg;
}

class TP_Steg : public TP_Base
{
    Q_OBJECT

private:
    Ui::TP_Steg *ui;
    void eventFilter_Wert(QEvent*);
    void eventFilter_DFA(QEvent*);
    void eventFilter_DZ(QEvent*);
    QClipboard* clipboard;
    TP_HighLighter* tp_HighLighter;
    QStringList stringList_PostProcessing;

protected:
    bool eventFilter(QObject *obj, QEvent *ev) override;

public:
    explicit TP_Steg(QWidget *parent = nullptr);
    ~TP_Steg();
    void set_Anfahren();
    void setPixmap();
    QStringList postProcessing();
    void create_NewHeaderLine();
    Struct_Steg get_Data();
    void set_Data(Struct_Steg);

public slots:
    void slot_AxesChanged(QString);
    void slot_setTextFromCilpBoard();
};

#endif // TP_STEG_H
