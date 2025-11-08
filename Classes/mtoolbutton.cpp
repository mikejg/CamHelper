#include "mtoolbutton.h"

MToolbutton::MToolbutton(QWidget *parent) : QToolButton(parent)
{}

void MToolbutton::stopAnimation()
{
    if(movie != nullptr)
        movie->stop();
    this->setIcon(QIcon(":/Icons/Project/tag.png"));
}

void MToolbutton::startAnimation()
{
    if(movie != nullptr)
    {
        movie->start();
    }
}
void MToolbutton::setGifAnimation(QString string_Animation)
{
    movie = new QMovie(string_Animation, QByteArray(), this);
    connect(movie, SIGNAL(frameChanged(int)), this, SLOT(slot_FrameChanged(int)));
}

void MToolbutton::slot_FrameChanged(int i)
{
    Q_UNUSED(i);
    this->setIcon(QIcon(movie->currentPixmap()));
}
