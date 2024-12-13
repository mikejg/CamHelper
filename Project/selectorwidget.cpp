#include "selectorwidget.h"
#include "ui_selectorwidget.h"
#include <QScreen>
#include <QMouseEvent>
#include <QPainter>
#include <QPainterPath>

/*SelectorWidget::SelectorWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectorWidget)
{
    ui->setupUi(this);
}*/

SelectorWidget::SelectorWidget(QWidget* parent) : QDialog(parent, Qt::FramelessWindowHint)
{
    setAttribute(Qt::WA_TranslucentBackground);
    setGeometry(screen()->geometry());
    desktopPixmap = grabScreenshot();
}

SelectorWidget::~SelectorWidget()
{
    delete ui;
}

void SelectorWidget::mousePressEvent(QMouseEvent* event)
{
    selectedRect.setTopLeft(event->globalPos());
}

void SelectorWidget::mouseMoveEvent(QMouseEvent* event)
{
    selectedRect.setBottomRight(event->globalPos());
    update();
}

void SelectorWidget::mouseReleaseEvent(QMouseEvent* event)
{
    selectedPixmap = desktopPixmap.copy(selectedRect.normalized());
    accept();
    emit sig_NewPixmap(selectedPixmap);
}

void SelectorWidget::paintEvent(QPaintEvent*)
{
    QPainter p (this);
    p.drawPixmap(0, 0, desktopPixmap);

    QPainterPath path;
    path.addRect(rect());
    path.addRect(selectedRect);
    p.fillPath(path, QColor::fromRgb(255,255,255,96));

    p.setPen(Qt::red);
    p.drawRect(selectedRect);
}

QPixmap SelectorWidget::grabScreenshot()
{
    QPixmap desktopPixmap = QPixmap(screen()->geometry().width(), screen()->geometry().height());
    QPainter p(&desktopPixmap);

    for (QScreen* screen : QApplication::screens())
        p.drawPixmap(screen->geometry().topLeft(), screen->grabWindow(0));

    return desktopPixmap;
}
