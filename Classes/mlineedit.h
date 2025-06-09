#ifndef MLINEEDIT_H
#define MLINEEDIT_H

#include <QLineEdit>

class MLineEdit : public QLineEdit
{
    Q_OBJECT
private:
    QPalette *palette_InValid;
    QPalette *palette_Valid;
    QPalette *palette_Empty;

    bool bool_TextNecessary;
public:
    explicit MLineEdit(QWidget *parent = nullptr);

    void check_Empty();

    bool is_Empty();

    void set_Empty();
    void set_Invalid();
    void set_TextNecessary(bool n) {bool_TextNecessary = n;}
    void set_Valid();


public slots:
    void slot_textChanged(QString);
};

#endif // MLINEEDIT_H
