#ifndef TP_ITEM_H
#define TP_ITEM_H

#include <QFrame>
#include <QPixmap>

#include "tp_struct.h"
//#include "../mfile.h"
#include "../Logging/logging.h"
#include "../Classes/struct.h"
namespace Ui {
class TP_Item;
}

class TP_Item : public QFrame
{
    Q_OBJECT

public:
    explicit TP_Item(QWidget *parent = nullptr, Logging* l = nullptr);
    ~TP_Item();
    enum State{NoState, Kante, Ausrichten, Steg, Bohrung, Ebenheit, Nut};

    void              highLight() {emit sig_HighLightLineNumber(stringList_LineNumber);}
    Struct_Ausrichten get_Ausrichten();
    Struct_Bohrung    get_Bohrung();
    Struct_Ebenheit   get_Ebenheit();
    Struct_Kante      get_Kante();
    State             get_State() {return state;}
    Struct_Steg       get_Steg();
    Struct_Nut        get_Nut();
    QString           get_Text();

    QStringList       postProcessing();
    QStringList       postProcessing_Ebenheit();
    void              read_Anfahren();
    void              set_Data(Item_TouchProbe);
    void              set_Text(QString str);
    void              set_LineNumber(QStringList sl) {stringList_LineNumber = sl;}

private:
    Ui::TP_Item *ui;
    bool bool_Fold;
    Logging*    log;
    QStringList stringList_LineNumber;
    //MFile*      mfile;
    QStringList stringList_ContentAnfahren;
    QStringList stringList_PostProcessing;
    QStringList stringList_PostProcessing_Ebenheit;
    void hideAll();

    State state;

public slots:
    void slot_Fold_In();
    void slot_Fold_Out();
    void slot_Fold_Toggle();
    void slot_Show_TP_Kante();
    void slot_Show_TP_Ausrichten();
    void slot_Show_TP_Steg();
    void slot_Show_TP_Ebenheit();
    void slot_Show_TP_Nut();
    void slot_Delet_Item();
    void slot_Show_TP_Bohrung();
    void slot_ReCreate();
    void slot_NewHeaderLine(QString);

signals:
    void sig_NewPixmap(QPixmap);
    void sig_NewItem();
    void sig_DeleteItem(TP_Item*);
    void sig_Err(QString);
    void sig_Log(QString);
    void sig_HighLightLineNumber(QStringList);
    //sig_Create -> TP_ScrollContent::sig_Create() -> TouchProbe::slot_Create();
    void sig_Create();
};

#endif // TP_ITEM_H
