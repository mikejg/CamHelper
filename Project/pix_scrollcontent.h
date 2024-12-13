#ifndef PIX_SCROLLCONTENT_H
#define PIX_SCROLLCONTENT_H

#include <QWidget>
#include <QVBoxLayout>
#include "mlabel.h"

namespace Ui {
class Pix_ScrollContent;
}

class Pix_ScrollContent : public QWidget
{
    Q_OBJECT
private:
    Ui::Pix_ScrollContent *ui;
    QList<MLabel*> label_List;

    QVBoxLayout* layout;
protected:
    void resizeEvent(QResizeEvent *event);

public:
    explicit Pix_ScrollContent(QWidget *parent = nullptr);
    ~Pix_ScrollContent();
    void set_Layout(QVBoxLayout* l) {layout = l;}
    void insert_Pixmap(QString);
};

#endif // PIX_SCROLLCONTENT_H
