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

    string_StyleSheet = styleSheet();
    connect(this, SIGNAL(textChanged(QString)), this, SLOT(slot_textChanged(QString)));
}

void MLineEdit::set_Invalid()
{
    setStyleSheet(string_StyleSheet + "color:rgb(255,0,0);");
}

void MLineEdit::set_Valid()
{
    setStyleSheet(string_StyleSheet);
}

void MLineEdit::set_Empty()
{
    setStyleSheet(string_StyleSheet + "background-color:rgb(255,116,108);");
}

void MLineEdit::slot_textChanged(QString newText)
{

    set_Valid();

    //Wenn ein Text vorhanden sein muss und das Feld leer ist
    //färbe das feld rot ein
    if(bool_TextNecessary && newText.isEmpty())
        set_Empty();

    if(state == State::Digi)
    {
        string_Text = text();
        string_Text.replace(",", ".");
        setText(string_Text);

        string_Text.toFloat(&bool_OK);
        if(!bool_OK)
            set_Invalid();
    }
}

bool MLineEdit::check()
{
    //qDebug() << Q_FUNC_INFO << text();
    if(bool_TextNecessary && text().isEmpty())
    {
        set_Empty();
        return false;
    }

    if(state == State::Dir && !QDir(text()).exists())
    {
        set_Invalid();
        return false;
    }

    if(state == State::File && !QFile(text().toCaseFolded()).exists())
    {
        set_Invalid();
        return false;
    }

    if(state == State::Digi)
    {
        text().toFloat(&bool_OK);
        if(!bool_OK)
            return false;
    }

    return true;
}
