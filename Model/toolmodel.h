#ifndef TOOLMODEL_H
#define TOOLMODEL_H

#include <QAbstractTableModel>
#include "../Tool/toollist.h"

class ToolModel : public QAbstractTableModel
{
    Q_OBJECT
private:
    QList<Tool*> list_Tools;

public:
    explicit ToolModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    void populateData(ToolList*);

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex& index, const QVariant& value, int role);

    void delete_Tool(int int_Row);

signals:
    //void sig_NewToolList(QList<Item_Programm>);
};

#endif // TOOLMODEL_H
