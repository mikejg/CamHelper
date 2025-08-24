#include "mcombobox.h"

MComboBox::MComboBox(QWidget *parent) : QComboBox(parent)
{
    this->setFocusPolicy(Qt::StrongFocus);
}

void MComboBox::wheelEvent(QWheelEvent *e)
{
    // Mausrad komplett ignorieren
    /*
    if (this->hasFocus())
    {
        QComboBox::wheelEvent(e);
    }
    */
}
