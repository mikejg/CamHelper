#ifndef PIX_SCROLLAREA_H
#define PIX_SCROLLAREA_H

#include <QScrollArea>
#include <QVBoxLayout>
#include "mlabel.h"

namespace Ui {
class Pix_ScrollArea;
}

class Pix_ScrollArea : public QScrollArea
{
    Q_OBJECT
private:
    Ui::Pix_ScrollArea *ui;
    QVBoxLayout* layout;
    QList<MLabel*> label_List;
    QSpacerItem* spacerItem;

protected:
    void resizeEvent(QResizeEvent *);
public:
    explicit Pix_ScrollArea(QWidget *parent = nullptr);
    ~Pix_ScrollArea();
    void clear();
    void set_Layout(QVBoxLayout* l) {layout = l;}
    void set_Spacer(QSpacerItem* s) {spacerItem = s;}
    void insert_Pixmap(QString);
    void insert_Pixmap(QPixmap);
    QList<MLabel*> get_PictureList() {return label_List;}

public slots:
    void slot_DeleteLabel(MLabel*);
};

#endif // PIX_SCROLLAREA_H
