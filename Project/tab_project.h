#ifndef TAB_PROJECT_H
#define TAB_PROJECT_H

#include <QWidget>

namespace Ui {
class Tab_Project;
}

class Tab_Project : public QWidget
{
    Q_OBJECT

public:
    explicit Tab_Project(QWidget *parent = nullptr);
    ~Tab_Project();

private:
    Ui::Tab_Project *ui;
};

#endif // TAB_PROJECT_H
