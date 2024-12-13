#ifndef SELECTORWIDGET_H
#define SELECTORWIDGET_H

#include <QDialog>
#include <QApplication>

namespace Ui {
class SelectorWidget;
}

class SelectorWidget : public QDialog
{
    Q_OBJECT
private:
    Ui::SelectorWidget *ui;
    QPixmap desktopPixmap;
    QRect selectedRect;
    QPixmap grabScreenshot();

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent* event) override;

public:
    explicit SelectorWidget(QWidget *parent = nullptr);
    ~SelectorWidget();
    QPixmap selectedPixmap;

signals:
    void sig_NewPixmap(QPixmap);
};

#endif // SELECTORWIDGET_H
