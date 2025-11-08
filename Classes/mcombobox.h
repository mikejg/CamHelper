#ifndef MCOMBOBOX_H
#define MCOMBOBOX_H

#include <QComboBox>
#include <QObject>

class MComboBox : public QComboBox
{
    Q_OBJECT
public:
    MComboBox(QWidget *parent = nullptr);
    void set_Empty();

protected:
    void showPopup() override
    {
        emit popupShown(true);
        QComboBox::showPopup();
    }

    void hidePopup() override {
        QComboBox::hidePopup();
        emit popupShown(false);
    }

signals:
    void popupShown(bool); // Signal, wenn das Dropdown angezeigt wird

public slots:
    void slot_CurrentTextChanged(QString);
};

#endif // MCOMBOBOX_H
