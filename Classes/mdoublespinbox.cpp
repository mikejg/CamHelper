#include "mdoublespinbox.h"

MDoubleSpinBox::MDoubleSpinBox(QWidget *parent) : QDoubleSpinBox(parent)
{
    connect(this, SIGNAL(valueChanged(double)), this, SLOT(slot_ValueChanged(double)));
}

bool MDoubleSpinBox::check()
{
    //Wenn der Wert 0 ist und bool_Zero auf false gesetzt ist
    //gibe false zurück.
    if(this->value() == 0 && !bool_Zero)
        return false;
    return true;
}

void MDoubleSpinBox::set_Null()
{
    setStyleSheet("color:rgb(255,0,0);");
}


void MDoubleSpinBox::slot_ValueChanged(double d)
{
    //Wenn der Wert 0 ist und bool_Zero auf false gesetzt ist
    //färbe die Spinbox Rot ein
    if(d == 0 && !bool_Zero)
        setStyleSheet("QDoubleSpinBox{color:rgb(255,0,0);}\n"
                      "QDoubleSpinBox:focus{color:rgb(255,0,0);"
                      "border: 1px solid;"
                      "border-color: rgb(255,116,108);"
                      "selection-background-color: rgb(255,116,108);}");
    else
        setStyleSheet("");
}
