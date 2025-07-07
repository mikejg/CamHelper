#include "logging.h"

Logging::Logging(QWidget *parent) : QTextEdit(parent)
{
    highLighter = new MHighLighter(document());
}

Logging::~Logging()
{

}

void Logging::successful(QString s)
{
    //wenn schon mal ein Fehler aufgetreten ist
    // logge keine Message mehr
    //if(bool_Error)
    //    return;

    append(QString("☑ " ) + s);
}

void Logging::vailed(QString s)
{
    append(QString("☒ " ) +s);
}

void Logging::warning(QString s)
{
    append(QString("⚠ " ) +s);
}
