#ifndef MDOUBLESPINBOX_H
#define MDOUBLESPINBOX_H

#include <QDoubleSpinBox>
#include <QObject>

class MDoubleSpinBox : public QDoubleSpinBox
{
    Q_OBJECT
private:
    bool bool_Zero;
public:
    MDoubleSpinBox(QWidget *parent = nullptr);
    void set_Zero(bool b) {bool_Zero = b;}
    bool check();
    void set_Null();
public slots:
    void slot_ValueChanged(double);
};

#endif // MDOUBLESPINBOX_H
