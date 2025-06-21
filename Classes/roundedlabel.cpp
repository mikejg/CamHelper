#include "roundedlabel.h"

RoundedLabel::RoundedLabel() {}

RoundedLabel::RoundedLabel(QWidget *parent)
    : QLabel(parent), m_borderRadius(0)
{
    // Ensure background is transparent for rounded corners
    setAttribute(Qt::WA_TranslucentBackground);
}

void RoundedLabel::setPixmap(const QPixmap &pixmap, int radius)
{
    m_originalPixmap = pixmap;
    m_borderRadius = radius;
    // Request a repaint to apply the new pixmap and radius
    update();
}

void RoundedLabel::paintEvent(QPaintEvent *event)
{
    int x=0; int y=0;
    if (m_originalPixmap.isNull()) {
        QLabel::paintEvent(event); // Call base class if no pixmap is set
        return;
    }

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);

    QPixmap scaledPixmap = m_originalPixmap.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

    // Create a QBitmap with rounded corners
    QBitmap mask(scaledPixmap.size());
    mask.fill(Qt::color0); // Transparent
    QPainter maskPainter(&mask);
    maskPainter.setRenderHint(QPainter::Antialiasing, true);
    maskPainter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    maskPainter.setBrush(Qt::color1); // Opaque
    maskPainter.drawRoundedRect(mask.rect(), m_borderRadius, m_borderRadius);

    // Apply the mask to the pixmap
    scaledPixmap.setMask(mask);

    // Draw the masked pixmap
    if(scaledPixmap.size().width() < size().width())
        x = (size().width() - scaledPixmap.size().width()) / 2;

    if(scaledPixmap.size().height() < size().height())
        y = (size().height() - scaledPixmap.height()) / 2;
    painter.drawPixmap(x, y, scaledPixmap);
}
