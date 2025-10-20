#include "mcombobox.h"

MComboBox::MComboBox(QWidget *parent) : QComboBox(parent)
{
    this->setFocusPolicy(Qt::StrongFocus);
    connect(this,SIGNAL(currentTextChanged(QString)), this, SLOT(slot_CurrentTextChanged(QString)));
}

/*void MComboBox::wheelEvent(QWheelEvent *e)
{
    // Mausrad komplett ignorieren

    if (this->hasFocus())
    {
        QComboBox::wheelEvent(e);
    }

}*/

void MComboBox::set_Empty()
{
    setStyleSheet("background-color:rgb(255,116,108);");
}

void MComboBox::slot_CurrentTextChanged(QString string)
{
    if(string.isEmpty())
    {
        setStyleSheet("background-color:rgb(255,116,108);");
    }
    else
    {
       setStyleSheet("");
    }
}
