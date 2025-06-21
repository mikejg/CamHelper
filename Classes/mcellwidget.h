#ifndef MCELLWIDGET_H
#define MCELLWIDGET_H

#include <QWidget>
#include "struct.h"

namespace Ui {
class MCellWidget;
}

class MCellWidget : public QWidget
{
    Q_OBJECT
private:
    Ui::MCellWidget *ui;
    QString string_StyleSheet;
    ProjectData projectData;

public:
    explicit MCellWidget(QWidget *parent = nullptr);
    ~MCellWidget();
    void set_ProjectData (ProjectData pd);

protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

signals:
    //sendet einen Click mit der Datenbank ID des Projects;
    void sig_Clicked(QString);
};

#endif // MCELLWIDGET_H
