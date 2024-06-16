#ifndef TP_BOHRUNG_H
#define TP_BOHRUNG_H

#include <QWidget>
#include <QClipboard>

#include "tp_base.h"
#include "tp_struct.h"
#include "tp_highlighter.h"

namespace Ui {
class TP_Bohrung;
}

class TP_Bohrung : public TP_Base
{
    Q_OBJECT

private:
    Ui::TP_Bohrung *ui;
    void eventFilter_Durchmesser(QEvent*);
    QStringList stringList_PostProcessing;
    QClipboard* clipboard;
    TP_HighLighter* tp_HighLighter;

protected:
    bool eventFilter(QObject *obj, QEvent *ev) override;

public:
    explicit TP_Bohrung(QWidget *parent = nullptr);
    ~TP_Bohrung();
    void set_Data(Struct_Bohrung);
    void setPixmap();
    void set_Anfahren();
    QStringList postProcessing();
    void create_NewHeaderLine();
    Struct_Bohrung get_Data();

public slots:
    void slot_setTextFromCilpBoard();
};

#endif // TP_BOHRUNG_H
