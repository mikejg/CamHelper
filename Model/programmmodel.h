#ifndef PROGRAMMMODEL_H
#define PROGRAMMMODEL_H

#include <QAbstractTableModel>
#include "../Classes/struct.h"

class ProgrammModel : public QAbstractTableModel
{
    Q_OBJECT

private:
    QList<Programm> list_Programme;

public:
    explicit ProgrammModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    void populateData(const QList<Programm> &prg);

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex& index, const QVariant& value, int role);

signals:
    void sig_NewProgrammList(QList<Programm>);
    void sig_ProgrammChanged();
};



#endif // PROGRAMMMODEL_H
