#ifndef MFILE_H
#define MFILE_H

#include <QFile>
#include <QStringList>
#include <QTextStream>

#include "../Logging/logging.h"

class MFile : public QFile
{
    Q_OBJECT

private:
    Logging*     log;
    QTextStream* textStream_Read;
    QTextStream* textStream_Write;
    QStringList  stringList_Content;

public:
    explicit MFile(QObject *parent = nullptr, Logging* l = nullptr);
    MFile(QString name, Logging* l);

    QStringList get_Content() {return stringList_Content;}
    bool        read_Content();
    void        save(QStringList);
    void        set_Logging(Logging* l) {log = l;}
signals:
};

#endif // MFILE_H
