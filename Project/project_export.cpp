#include "project_export.h"
#include "QDate"
#include <QDateTime>
Project_Export::Project_Export(QObject *parent)
    : QObject{parent}
{
}


void Project_Export::set_ContentMainProgramm(QTextEdit* textEdit)
{
    stringList_ContentMainProgramm = textEdit->toPlainText().split("\n");

    qDebug() << Q_FUNC_INFO << textEdit->objectName() << stringList_ContentMainProgramm.size();
}

void Project_Export::exportProject(ProjectData* pd)
{
    projectData = pd;
    QDate currentDate = QDate::currentDate();                   //Erstelle einen String des Datums
    pd->lastProduction = currentDate.toString("dd.MM.yyyy");

    QDateTime utcTime = QDateTime::currentDateTimeUtc();        //Erstelle einen Utc Zeitstempel
    qint64 epochSeconds = utcTime.toSecsSinceEpoch();
    pd->lastOpen = QString("%1").arg(epochSeconds);

    if(!dataBase->save(pd))
        return;


}
