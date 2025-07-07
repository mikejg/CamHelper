#include "mlabel.h"

MLabel::MLabel(QWidget *parent) :
    QLabel(parent)
{
    this->setMinimumSize(100,100);
    setScaledContents(false);
}

void MLabel::setPixmap(const QPixmap &pixmap, int radius)
{
    orginal_Pixmap = pixmap;    //Setzt das orgingal_Pixmap
    border_Radius = radius;     //Setzt den Radius
    update();                   //erzwingt ein Neuzeichnen des Labes mit dem neuen Bild und Radius
}

void MLabel::set_Ratio(double r)
{
    QWidget* widget = qobject_cast<QWidget*>(parent()); //Hole dir Parent und caste es zu einen QWidget
    int int_Width = widget->width();                    //schreibe die Breite von deinem Parent in int_Width
    ratio = r;                                          //Setze das Seitenverhältnis
    setFixedWidth(int_Width);                           //setze die feste Breite mit dem Wert von int_Width
    setFixedHeight(int_Width/ratio);                    //setze die feste Höhe unter Berücksichtigung des Seitenverhältnis
}

void MLabel::mouseReleaseEvent(QMouseEvent* event)
{
    //Wenn man einen Rechtsklick auf das Bild macht wird es
    //gelöscht
    if(event->button() == Qt::RightButton)
    {
        sig_DeleteLabel(this);
    }
}

void MLabel::paintEvent(QPaintEvent *event)
{
    //von Google KI generiert
    int x=0; int y=0;
    if (orginal_Pixmap.isNull())    //Wenn kein orginal_Pixmap da ist
    {
        QLabel::paintEvent(event);  //Ruf die Basisfunktion 'paintEvent' von QLabel auf
        return;
    }

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);

    QPixmap scaledPix = orginal_Pixmap.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

    // Create a QBitmap with rounded corners
    QBitmap mask(scaledPix.size());
    mask.fill(Qt::color0); // Transparent
    QPainter maskPainter(&mask);
    maskPainter.setRenderHint(QPainter::Antialiasing, true);
    maskPainter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    maskPainter.setBrush(Qt::color1); // Opaque
    maskPainter.drawRoundedRect(mask.rect(), border_Radius, border_Radius);

    // Apply the mask to the pixmap
    scaledPix.setMask(mask);

    // Draw the masked pixmap
    if(scaledPix.size().width() < size().width())
        x = (size().width() - scaledPix.size().width()) / 2;

    if(scaledPix.size().height() < size().height())
        y = (size().height() - scaledPix.height()) / 2;
    painter.drawPixmap(x, y, scaledPix);
}
