#include "mlineedit.h"

MLineEdit::MLineEdit(QWidget *parent) : QLineEdit(parent)
{
    bool_TextNecessary = false;

    palette_InValid = new QPalette();
    palette_InValid->setColor(QPalette::Text,Qt::red);

    palette_Valid = new QPalette();
    *palette_Valid = palette();

    palette_Empty = new QPalette();
    palette_Empty->setColor(QPalette::Base, Qt::darkRed);

    connect(this, SIGNAL(textChanged(QString)), this, SLOT(slot_textChanged(QString)));
}

void MLineEdit::set_Invalid()
{
    setPalette(*palette_InValid);
}

void MLineEdit::set_Valid()
{
    setPalette(*palette_Valid);
}

void MLineEdit::set_Empty()
{
    //qDebug() << Q_FUNC_INFO;
    setPalette(*palette_Empty);
}

void MLineEdit::slot_textChanged(QString newText)
{
    //setze die Palette auf valid
    setPalette(*palette_Valid);

    //Wenn ein Text vorhanden sein muss und das Feld leer ist
    //färbe das feld rot ein
    if(bool_TextNecessary && newText.isEmpty())
        set_Empty();
}

bool MLineEdit::is_Empty()
{
    if(text().isEmpty())
        return true;
    else
        return false;
}

void MLineEdit::check_Empty()
{
    //qDebug() << Q_FUNC_INFO;

    //Wenn ein Text vorhanden sein muss und das Feld leer ist
    //färbe das feld rot ein
    if(bool_TextNecessary && text().isEmpty())
        set_Empty();
}
