#ifndef TP_AUSRICHTEN_H
#define TP_AUSRICHTEN_H

#include <QWidget>
#include <QComboBox>
#include <QStandardItemModel>
#include <QClipboard>

#include "tp_base.h"
#include "tp_struct.h"
#include "tp_highlighter.h"

namespace Ui {
class TP_Ausrichten;
}

class TP_Ausrichten : public TP_Base
{
    Q_OBJECT

private:
    Ui::TP_Ausrichten *ui;

    void SetComboBoxItemEnabled(QComboBox * comboBox, int index, bool enabled);
    QStringList stringList_PostProcessing;
    QClipboard* clipboard;
    TP_HighLighter* tp_HighLighter;

public:
    explicit TP_Ausrichten(QWidget *parent = nullptr);
    ~TP_Ausrichten();
    void set_Anfahren();
    QStringList postProcessing();
    void setPixmap();
    void create_NewHeaderLine();
    Struct_Ausrichten get_Data();
    void set_Data(Struct_Ausrichten);

protected:
    bool eventFilter(QObject *obj, QEvent *ev) override;

public slots:
    void slot_currentFrameChanged(QString);
    void slot_currentTextChanged(QString);
    void slot_setTextFromCilpBoard();

signals:
};

#endif // TP_AUSRICHTEN_H
