#ifndef ROUNDEDLABEL_H
#define ROUNDEDLABEL_H

#include <QLabel>
#include <QPainter>

//erstellt mit Google Gemeni
//Promt: "Schreibe mir ein Programm in Qt dass ein QPixmap mit
//        runden Ecken in ein QLabel zeichnet"

class RoundedLabel : public QLabel
{
    Q_OBJECT
public:
    RoundedLabel();
    explicit RoundedLabel(QWidget *parent = nullptr);
    void setPixmap(const QPixmap &pixmap, int radius = 5);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QPixmap m_originalPixmap;
    int m_borderRadius;
};

#endif // ROUNDEDLABEL_H
