#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QSettings>

class Settings : public QObject
{
    Q_OBJECT
private:
    QSettings*  settings;
    QString     string_ProgrammDir;
    QString     string_MagazinDir;
    QString     string_LocalDir;
    QString     string_RemoteDir;
    QString     string_ToolDB;
    int         int_ToolPlaces;
    float       float_OffsetX;
    float       float_OffsetY;
    float       float_OffsetZ;

public:
    explicit Settings(QObject *parent = nullptr);

    //get Funktionen
    QString get_ProgrammDir()    {return settings->value("ProgrammDir", "").toString();}
    QString get_MagazinDir()     {return settings->value("MagazinDir", "").toString();}
    QString get_LocalDir()       {return settings->value("LocalDir", "").toString();}
    QString get_RemoteDir()      {return settings->value("RemoteDir", "").toString();}
    QString get_ToolDB()         {return settings->value("ToolDB", "").toString();}
    int     get_ToolPlaces()     {return settings->value("ToolPlaces").toInt();}
    QString get_NextCheck()      {return settings->value("NextCheck","").toString();}
    float   get_OffsetX()        {return settings->value("OffsetX",999).toFloat();}
    float   get_OffsetY()        {return settings->value("OffsetY",999).toFloat();}
    float   get_OffsetZ()        {return settings->value("OffsetZ",999).toFloat();}

    //set Funktionen
    void set_ProgrammDir(QString str)   {settings->setValue("ProgrammDir", str);}
    void set_MagazinDir(QString str)    {settings->setValue("MagazinDir", str);}
    void set_LocalDir(QString str)      {settings->setValue("LocalDir", str);}
    void set_RemoteDir(QString str)     {settings->setValue("RemoteDir", str);}
    void set_ToolDB(QString str)        {settings->setValue("ToolDB", str);}
    void set_ToolPlaces(int p)          {settings->setValue("ToolPlaces",p);}
    void set_NextCheck(QString str)     {settings->setValue("NextCheck",str);}
    void set_OffsetX(float fl)          {settings->setValue("OffsetX", fl);}
    void set_OffsetY(float fl)          {settings->setValue("OffsetY", fl);}
    void set_OffsetZ(float fl)          {settings->setValue("OffsetZ", fl);}

signals:

};

#endif // SETTINGS_H
