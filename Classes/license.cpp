#include "license.h"

License::License(QObject *parent)
    : QObject{parent}
{}

void License::checkRemoteFile()
{
    //qDebug() << Q_FUNC_INFO;
    /* Es wird versucht die Datei 'goeltenbodt.txt' von www.gareiss.org
    * runterzuladen. Danach siehe slotMetaDataChanged() */
    QNetworkAccessManager *nam = new QNetworkAccessManager(this);

    req = QNetworkRequest(QUrl("https://www.gareiss.org/CamHelper.txt"));
    reply = nam->get(req);
    connect(reply, SIGNAL(metaDataChanged()), this, SLOT(slotMetaDataChanged()));
}

void License::slotMetaDataChanged()
{
    /* lade int_Status mit dem Status des Download Versuchs,
     * zum Beispiel 200 erfolgreich
     *              404 File not Found */

    int int_Status = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

    if(int_Status == 200)
    {
        emit sig_ValidLicense(true);
    }
    else
    {
        emit sig_ValidLicense(false);
    }
}
