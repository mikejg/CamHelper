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
    QIcon mIcon;
public:
    MToolbutton(QWidget *parent = nullptr);  
    void setGifAnimation(QString);

public slots:
    void slot_FrameChanged(int);
    void stopAnimation();
    void startAnimation();
};


#endif // MTOOLBUTTON_H
