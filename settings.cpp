#include "settings.h"

Settings::Settings(QObject *parent)
    : QObject{parent}
{
    settings = new QSettings("Gareiss", "CamHelper");
    string_ProgrammDir = settings->value("ProgrammDir", "").toString();
    string_MagazinDir  = settings->value("MagazinDir", "").toString();
    string_ToolDB      = settings->value("ToolDB", "").toString();
    int_ToolPlaces     = settings->value("ToolPlaces").toInt();
}
