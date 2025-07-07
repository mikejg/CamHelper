#ifndef MLABEL_H
#define MLABEL_H

#include <QLabel>
#include <QPixmap>
#include <QResizeEvent>
#include <QPainter>

class MLabel : public QLabel
{
    Q_OBJECT
private:
    //QPixmap pix;
    QPixmap orginal_Pixmap;
    double ratio;
    int border_Radius;

protected:
    void mouseReleaseEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent *event) override;

public:
    explicit MLabel(QWidget *parent = 0);
    //virtual int heightForWidth( int width ) const;
    //virtual QSize sizeHint() const;
    //QPixmap scaledPixmap() const;
    void set_Ratio(double);
    double get_Ratio() {return ratio;}
    QPixmap get_Pixmap() {return orginal_Pixmap;}
    void setPixmap(const QPixmap &pixmap, int radius = 5);

public slots:
    //void setPixmap ( const QPixmap & );
    //void resizeEvent(QResizeEvent *);
signals:
    void sig_DeleteLabel(MLabel*);
};

#endif // MLABEL_H
