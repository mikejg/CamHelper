#include "tpcombobox.h"

TPComboBox::TPComboBox(QWidget *parent) : QComboBox(parent)
{
    this->setFocusPolicy(Qt::StrongFocus);
}

void TPComboBox::wheelEvent(QWheelEvent *e)
{
    // Mausrad komplett ignorieren
    /*
    if (this->hasFocus())
    {
        QComboBox::wheelEvent(e);
    }
    */
}

