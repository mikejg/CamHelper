#ifndef PROJECT_H
#define PROJECT_H

#include <QObject>

#include <QDir>
#include "logging.h"
#include "settings.h"
#include "mlabel.h"
#include "../database.h"
#include "../Tools/toollist.h"
#include "../Parser/parser_programm.h"
#include "../TouchProbe/tp_item.h"

class Project : public QObject
{
    Q_OBJECT

private:
    Logging* log;
    Parser_Programm* parser_Programm;
    Settings*        settings;
    DataBase*        database;

    QString string_ComponentPartX, string_ComponentPartY, string_ComponentPartZ;
    QStringList stringList_ContentMainProgramm;

    QList<Item_TouchProbe> list_TouchProbe;
    QList<Item_Programm> list_Programm;

    bool bool_MaxOverSize;

    QStringList stringList_Errors;

    QString         string_MainProgramm;
    QString         string_Material;
    QStringList stringList_Message;

    bool bool_Numbering;

    QString         string_ProgrammDir;
    //QStringList stringList_Programme;
    QString         string_ProjectClamping;
    QString         string_ProjectFullName;
    QString         string_ProjectName;
    QString         string_ProjectStatus;
    QString         string_ProjectZeroPoint;
    QString         string_CamFile;
    QString         string_Comment;

    QString string_RawPartX, string_RawPartY, string_RawPartZ;
    QString string_RawPartInspection;

    ToolList* toolList;
    ToolList* toolList_In;
    QList<TP_Item*> tp_ItemList;
    QList<MLabel*> pictureList;

    QString string_XPlus_Min, string_XPlus_Max, string_XMinus_Min, string_XMinus_Max;
    QString string_YPlus_Min, string_YPlus_Max, string_YMinus_Min, string_YMinus_Max;
    QString string_ZPlus_Min, string_ZPlus_Max;

    QString string_XPlus_Max_DB, string_XMinus_Max_DB;
    QString string_YPlus_Max_DB, string_YMinus_Max_DB;
    QString string_ZPlus_Max_DB;

    QString string_LastProduction;
    QString string_ZRawPart;
    QStringList stringList_Tags;

    QString string_NPx, string_NPy, string_NPz;

    bool sort_Programms();

public:
    explicit Project(QObject*  parent = nullptr,
                     Logging*  l = nullptr,
                     Settings* s = nullptr,
                     DataBase* db = nullptr,
                     ToolList* tl = nullptr);

    void add_Tag(QString);

    QMap<QString, QString> get_Data();

    QString     get_CamFile()             {return string_CamFile;}
    QString     get_Comment()             {return string_Comment;}
    QString     get_ComponentPartX()      {return string_ComponentPartX;}
    QString     get_ComponentPartY()      {return string_ComponentPartY;}
    QString     get_ComponentPartZ()      {return string_ComponentPartZ;}
    QStringList get_ContentMainProgramm() {return stringList_ContentMainProgramm;}
    QString     get_LastProduction()      {return string_LastProduction;}
    QList<Item_TouchProbe>  get_ListTouchProbe() {return list_TouchProbe;}
    QString     get_MainProgramm()        {return string_MainProgramm;}
    QString     get_Material()            {return string_Material;}
    bool        get_MaxOverSize()         {return bool_MaxOverSize;}
    bool        get_Numbering()           {return bool_Numbering;}
    QString     get_NPx()                 {return string_NPx;}
    QString     get_NPy()                 {return string_NPy;}
    QString     get_NPz()                 {return string_NPz;}
    QString     get_ProgrammDir()         {return string_ProgrammDir;}
    QStringList get_ProgrammList();
    QList<Item_Programm> get_ListProgramm() {return list_Programm;}
    QString     get_ProjectClamping()     {return string_ProjectClamping;}
    QString     get_ProjectFullName()     {return string_ProjectFullName;}
    QString     get_ProjectName()         {return string_ProjectName;}
    QString     get_ProjectStatus()       {return string_ProjectStatus;}
    QString     get_ProjectZeroPoint()    {return string_ProjectZeroPoint;}
    QString     get_RawPartInspection()   {return string_RawPartInspection;}
    QString     get_RawPartX()            {return string_RawPartX;}
    QString     get_RawPartY()            {return string_RawPartY;}
    QString     get_RawPartZ()            {return string_RawPartZ;}
    ToolList*   get_ToolList()            {return toolList;}
    ToolList*   get_ToolListIN()          {return toolList_In;}
    QString     get_XPlus_Min()           {return string_XPlus_Min;}
    QString     get_XPlus_Max()           {return string_XPlus_Max;}
    QString     get_XPlus_Max_DB()        {return string_XPlus_Max_DB;}
    QString     get_XMinus_Min()          {return string_XMinus_Min;}
    QString     get_XMinus_Max()          {return string_XMinus_Max;}
    QString     get_XMinus_Max_DB()       {return string_XMinus_Max_DB;}
    QString     get_YPlus_Min()           {return string_YPlus_Min;}
    QString     get_YPlus_Max()           {return string_YPlus_Max;}
    QString     get_YPlus_Max_DB()        {return string_YPlus_Max_DB;}
    QString     get_YMinus_Min()          {return string_YMinus_Min;}
    QString     get_YMinus_Max()          {return string_YMinus_Max;}
    QString     get_YMinus_Max_DB()       {return string_YMinus_Max_DB;}
    QString     get_ZPlus_Min()           {return string_ZPlus_Min;}
    QString     get_ZPlus_Max()           {return string_ZPlus_Max;}
    QString     get_ZPlus_Max_DB()        {return string_ZPlus_Max_DB;}
    QString     get_ZRawPart()            {return string_ZRawPart;}
    Settings*   get_Settings()            {return settings;}
    void log_ProjectData();

    void remove_Tag(QString str) {stringList_Tags.removeOne(str);}

    void save();
    void save_NCTools(QString);
    void save_Programm(QString);
    bool scann_ForData();
    bool scann_ForTools();

    void set_CamFile(QString c)              {string_CamFile = c;}
    void set_Comment(QString c);
    void set_ComponentPartX(QString d)       {string_ComponentPartX = d;}
    void set_ComponentPartY(QString d)       {string_ComponentPartY = d;}
    void set_ComponentPartZ(QString d)       {string_ComponentPartZ = d;}
    void set_ContentMainProgramm(QTextEdit*);
    void set_LastProduction(QString str)     {string_LastProduction = str;}
    void set_ListTouchProbe(QList<Item_TouchProbe> l) {list_TouchProbe = l;}
    void set_MainProgramm(QString str)       {string_MainProgramm = str;}
    void set_Material(QString str)           {string_Material = str;}
    void set_NCTools();
    void set_NPx(QString str)                {string_NPx = str;}
    void set_NPy(QString str)                {string_NPy = str;}
    void set_NPz(QString str)                {string_NPz = str;}
    void set_PictureList(QList<MLabel*> p)   {pictureList = p;}
    void set_Programms(QList<Item_Programm> list) {list_Programm = list;}
    void set_ProjectClamping(QString str)    {string_ProjectClamping = str;}
    void set_ProjectFullName();
    void set_ProjectName(QString str)        {string_ProjectName = str;}
    void set_ProjectStatus(QString str)      {string_ProjectStatus = str;}
    void set_ProjectZeroPoint(QString str)   {string_ProjectZeroPoint = str;}
    void set_RawPartInspection(QString str)  {string_RawPartInspection = str;}
    void set_RawPartX(QString d)             {string_RawPartX = d;}
    void set_RawPartY(QString d)             {string_RawPartY = d;}
    void set_RawPartZ(QString d)             {string_RawPartZ = d;}
    void set_TPItemList(QList<TP_Item*> tpl) {tp_ItemList = tpl;}
    void set_XPlus_Min(QString str)          {string_XPlus_Min = str;}
    void set_XPlus_Max(QString str)          {string_XPlus_Max = str;}
    void set_XPlus_Max_DB(QString str)       {string_XPlus_Max_DB = str;}
    void set_XMinus_Min(QString str)         {string_XMinus_Min = str;}
    void set_XMinus_Max(QString str)         {string_XMinus_Max = str;}
    void set_XMinus_Max_DB(QString str)      {string_XMinus_Max_DB = str;}
    void set_YPlus_Min(QString str)          {string_YPlus_Min = str;}
    void set_YPlus_Max(QString str)          {string_YPlus_Max = str;}
    void set_YPlus_Max_DB(QString str)       {string_YPlus_Max_DB = str;}
    void set_YMinus_Min(QString str)         {string_YMinus_Min = str;}
    void set_YMinus_Max(QString str)         {string_YMinus_Max = str;}
    void set_YMinus_Max_DB(QString str)      {string_YMinus_Max_DB = str;}
    void set_ZPlus_Min(QString str)          {string_ZPlus_Min = str;}
    void set_ZPlus_Max(QString str)          {string_ZPlus_Max = str;}
    void set_ZPlus_Max_DB(QString str)       {string_ZPlus_Max_DB = str;}
    void set_ZRawPart(QString d)             {string_ZRawPart = d;}


    void save_TPItems(QString);
    void save_Pictures(QString);
    void save_Tags(QString);

public slots:
    void slot_NewProgrammList(QList<Item_Programm>);

signals:
    void sig_NewToolList();
};

#endif // PROJECT_H
