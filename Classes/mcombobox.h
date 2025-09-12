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
    void set_Empty();
public slots:
    void slot_CurrentTextChanged(QString);
};

#endif // MCOMBOBOX_H
