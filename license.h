#ifndef LICENSE_H
#define LICENSE_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QDateTime>
#include "settings.h"
#include "logging.h"

class License : public QObject
{
    Q_OBJECT

private:
    QNetworkRequest req;
    QNetworkReply   *reply;
    QString         string_NextCheck;
    QDateTime       dateTime_NextCheck;
    QDateTime       dateTime_CurrentTime;

    Settings*       settings;
    Logging*        log;

    void checkRemoteFile();

public:
    explicit License(QObject *parent = nullptr,
                     Settings* s = nullptr,
                     Logging* l = nullptr);

    void checkLicense();

signals:
    void sig_LicenseFailed();

public slots:
    void slotMetaDataChanged();
signals:

};

#endif // LICENSE_H
