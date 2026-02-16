#ifndef TP_KANTE_H
#define TP_KANTE_H

#include <QWidget>
#include <QClipboard>

#include "tp_base.h"
#include "tp_struct.h"
#include "tp_highlighter.h"

namespace Ui {
class TP_Kante;
}

class TP_Kante : public TP_Base
{
    Q_OBJECT

private:
    Ui::TP_Kante *ui;
    void eventFilter_DFA(QEvent*);
    void eventFilter_Wert(QEvent*);
    QStringList stringList_PostProcessing;
    QClipboard* clipboard;
    TP_HighLighter* tp_HighLighter;

protected:
    bool eventFilter(QObject *obj, QEvent *ev) override;

public:
    explicit TP_Kante(QWidget *parent = nullptr);
    ~TP_Kante();
    void set_Anfahren();
    void set_Data(Struct_Kante);
    QStringList postProcessing();
    void setPixmap();
    void set_TextEditAnfahren();
    void create_NewHeaderLine();
    Struct_Kante get_Data();

public slots:
    void slot_AxesSignsChanged(QString);
    void slot_currentFrameChanged(QString);
    void slot_setTextFromCilpBoard();
    void slot_NPVClicked();
signals:
};

#endif // TP_KANTE_H
