#include "mlineedit.h"
#include <QRegularExpression>

MLineEdit::MLineEdit(QWidget *parent) : QLineEdit(parent)
{
    bool_TextNecessary = false;
    state = State::noState;

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
    qDebug() << Q_FUNC_INFO << string_StyleSheet;
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
    {
        set_Empty();
        return;
    }

    if(state == State::Digi)
    {
        string_Text = text();
        string_Text.replace(",", ".");
        setText(string_Text);

        string_Text.toFloat(&bool_OK);
        if(!bool_OK)
            set_Invalid();
    }

    if(state == State::ZeroPointG)
    {
        if(!check_ZeroPointG(text()))
            set_Invalid();
    }

    if(state == State::Tension)
    {
        if(!check_Tension(text()))
            set_Invalid();
    }
}

bool MLineEdit::check()
{
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

    if(state == State::ZeroPointG)
    {
        if(!check_ZeroPointG(text()))
            return false;
    }

    if(state == State::Tension)
    {
        if(!check_Tension(text()))
            return false;
    }
    return true;
}

bool MLineEdit::check_ZeroPointG(QString string)
{
    QRegularExpression regex("G5\\d+$");

    // Führe die Suche im Text durch.
    return regex.match(string).hasMatch();
}

bool MLineEdit::check_Tension(QString string)
{
    QRegularExpression regex("Sp\\d+$");

    // Führe die Suche im Text durch.
    return regex.match(string).hasMatch();
}
