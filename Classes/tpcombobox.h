#ifndef TPCOMBOBOX_H
#define TPCOMBOBOX_H

#include <QComboBox>

class TPComboBox : public QComboBox
{
    Q_OBJECT
public:
    TPComboBox(QWidget *parent = nullptr);
    void wheelEvent(QWheelEvent *e) override;
};

#endif // TPCOMBOBOX_H
