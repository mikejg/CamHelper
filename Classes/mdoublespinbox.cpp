#include "mdoublespinbox.h"

MDoubleSpinBox::MDoubleSpinBox(QWidget *parent) : QDoubleSpinBox(parent)
{
    connect(this, SIGNAL(valueChanged(double)), this, SLOT(slot_ValueChanged(double)));
}

void MDoubleSpinBox::set_Null()
{
    setStyleSheet("color:rgb(255,0,0);");
}


void MDoubleSpinBox::slot_ValueChanged(double d)
{
    if(d == 0)
        setStyleSheet("QDoubleSpinBox{color:rgb(255,0,0);}\n"
                      "QDoubleSpinBox:focus{color:rgb(255,0,0);"
                      "border: 1px solid;"
                      "border-color: rgb(255,116,108);"
                      "selection-background-color: rgb(255,116,108);}");
    else
        setStyleSheet("");
}
