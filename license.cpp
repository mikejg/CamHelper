#include "license.h"

License::License(QObject *parent, Settings* s, Logging* l)
    : QObject{parent}
{
    settings = s;
    log = l;
}

void License::checkLicense()
{
    //qDebug() << Q_FUNC_INFO;
    /* Hole aus den Settings das Datum für den nächsten Check*/
    string_NextCheck = settings->get_NextCheck();
    log->message( string_NextCheck);

    //checkRemoteFile();
    /* Wenn es keinen Eintrag in den Settings gibt führe den Check aus */
  if(string_NextCheck.isEmpty())
  {
      checkRemoteFile();
      return;
  }

  /* erstelle dateTime_CurrentTime mit dem aktuellen Datum */
    dateTime_CurrentTime = QDateTime::currentDateTime();
    /* erstelle dateTime_NextCheck aus string_NextCheck */
    dateTime_NextCheck = QDateTime::fromString(string_NextCheck);

   /* Wenn das aktuelle Datum nach dem dateTime_NextCheck liegt
   * führe den Check aus. */
  if(dateTime_CurrentTime > dateTime_NextCheck)
  {
      checkRemoteFile();
  }

  return;
}

void License::checkRemoteFile()
{
  //qDebug() << Q_FUNC_INFO;
  /* Es wird versucht die Datei 'goeltenbodt.txt' von www.gareiss.org
    * runterzuladen. Danach siehe slotMetaDataChanged() */
  QNetworkAccessManager *nam = new QNetworkAccessManager(this);

  req = QNetworkRequest(QUrl("https://www.gareiss.org/goeltenbodt.txt"));
  reply = nam->get(req);
  connect(reply, SIGNAL(metaDataChanged()), this, SLOT(slotMetaDataChanged()));
}

void License::slotMetaDataChanged()
{
  /* lade int_Status mit dem Status des Download Versuchs,
     * zum Beispiel 200 erfolgreich
     *              404 File not Found
     *
     * Wenn der Download erfolgreich war wird das Datum für den
     * nächsten Check um 90 Tage erhöht
     * ist der Download fehlgeschlagen wird das Signal sig_LicenseFailed()
     * gesendet und das Programm beendet */
  int int_Status = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

  if(int_Status == 200)
  {
      log->successful(QString("Status: %1").arg(int_Status));
      dateTime_NextCheck = QDateTime::currentDateTime().addDays(30);
      //dateTime_NextCheck = QDateTime::currentDateTime().addSecs(300);
      string_NextCheck = dateTime_NextCheck.toString();
      settings->set_NextCheck(string_NextCheck);
      return;
  }

  log->error(QString("Status: %1").arg(int_Status));
  log->error("Keine gültige Lizenz gefunden");

  emit sig_LicenseFailed();
}
