#ifndef TOOLSHEET_MODEL_H
#define TOOLSHEET_MODEL_H

#include <QAbstractTableModel>
#include <QObject>
#include <QFont>
#include <QBrush>

class ToolSheet_Model : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit ToolSheet_Model(QObject *parent = nullptr);

    void populateData(const QList<QString> &id,
                      const QList<QString> &description,
                      const QList<QString> &tgl,
                      const QList<QString> &tal,
                      const QList<QString> &tfl,
                      const QList<QString> &tcounter);

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

private:
    QList<QString> list_ID;
    QList<QString> list_Description;
    QList<QString> list_GageLength;
    QList<QString> list_ToolLength;
    QList<QString> list_TipLength;
    QList<QString> list_Counter;
};

#endif // TOOLSHEET_MODEL_H
