#ifndef MCOMBOBOX_H
#define MCOMBOBOX_H

#include <QComboBox>
#include <QObject>

class MComboBox : public QComboBox
{
    Q_OBJECT
public:
    MComboBox(QWidget *parent = nullptr);

    void wheelEvent(QWheelEvent *e) override;
};

#endif // MCOMBOBOX_H
