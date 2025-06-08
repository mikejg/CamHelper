#ifndef MLABEL_H
#define MLABEL_H

#include <QLabel>
#include <QPixmap>
#include <QResizeEvent>

class MLabel : public QLabel
{
    Q_OBJECT
private:
    QPixmap pix;
    QPixmap orginal_Pixmap;
    double ratio;

protected:
    void mouseReleaseEvent(QMouseEvent* event) override;
public:
    explicit MLabel(QWidget *parent = 0);
    virtual int heightForWidth( int width ) const;
    virtual QSize sizeHint() const;
    QPixmap scaledPixmap() const;
    void set_Ratio(double r) {ratio = r;}
    double get_Ratio() {return ratio;}
    QPixmap get_Pixmap() {return orginal_Pixmap;}

public slots:
    void setPixmap ( const QPixmap & );
    void resizeEvent(QResizeEvent *);
signals:
    void sig_DeleteLabel(MLabel*);
};

#endif // MLABEL_H
