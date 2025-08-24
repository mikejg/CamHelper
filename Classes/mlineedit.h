#ifndef MLINEEDIT_H
#define MLINEEDIT_H

#include <QLineEdit>
#include <QDir>

class MLineEdit : public QLineEdit
{
    Q_OBJECT
private:
    QString string_StyleSheet;
    QPalette *palette_InValid;
    QPalette *palette_Valid;
    QPalette *palette_Empty;

    bool bool_TextNecessary;
    QDir dir;
    QFile file;
    QString string_Text;
    bool bool_OK;

    bool check_ZeroPointG(QString);
    bool check_Tension(QString);

public:
    explicit MLineEdit(QWidget *parent = nullptr);
    enum State{Dir, File, Digi, Tension, noState, ZeroPointG};
    State state;

    //void set_Text(QString);
    void set_Empty();
    void set_Invalid();
    void set_TextNecessary(bool n) {bool_TextNecessary = n;}
    void set_Valid();

    bool check();
public slots:
    void slot_textChanged(QString);
};

#endif // MLINEEDIT_H
