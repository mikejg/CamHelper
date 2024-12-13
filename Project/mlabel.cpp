#include "mlabel.h"

MLabel::MLabel(QWidget *parent) :
    QLabel(parent)
{
    this->setMinimumSize(1,1);
    setScaledContents(false);
}

void MLabel::setPixmap ( const QPixmap & p)
{
    pix = p;
    orginal_Pixmap = p;
    QLabel::setPixmap(scaledPixmap());
}

int MLabel::heightForWidth( int width ) const
{
    return pix.isNull() ? this->height() : ((qreal)pix.height()*width)/pix.width();
}

QSize MLabel::sizeHint() const
{
    int w = this->width();
    return QSize( w, heightForWidth(w) );
}

QPixmap MLabel::scaledPixmap() const
{
    return pix.scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
}

void MLabel::resizeEvent(QResizeEvent * e)
{
    if(!pix.isNull())
        QLabel::setPixmap(scaledPixmap());
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
