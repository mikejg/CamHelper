#ifndef LICENSE_H
#define LICENSE_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class License : public QObject
{
    Q_OBJECT
private:
    QNetworkRequest req;
    QNetworkReply   *reply;

public:
    explicit License(QObject *parent = nullptr);
    void checkRemoteFile();

signals:
    sig_ValidLicense(bool);

public slots:
    void slotMetaDataChanged();
};

#endif // LICENSE_H
