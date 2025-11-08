#ifndef MTOOLBUTTON_H
#define MTOOLBUTTON_H

#include <QObject>
#include <QToolButton>
#include <QMovie>

class MToolbutton : public QToolButton
{
    Q_OBJECT
private:
    QMovie* movie = nullptr;
public:
    MToolbutton(QWidget *parent = nullptr);

    void stopAnimation();
    void setGifAnimation(QString);
    void startAnimation();

public slots:
    void slot_FrameChanged(int);
};


#endif // MTOOLBUTTON_H
