#include "toolsheet_model.h"

ToolSheet_Model::ToolSheet_Model(QObject *parent)
    : QAbstractTableModel{parent}
{}

// Create a method to populate the model with data:
void ToolSheet_Model::populateData(const QList<QString> &id,
                              const QList<QString> &description,
                              const QList<QString> &tgl,
                              const QList<QString> &tal,
                              const QList<QString> &tfl,
                              const QList<QString> &tcounter)
{
    list_ID.clear();
    list_ID = id;
    list_Description.clear();
    list_Description = description;
    list_GageLength.clear();
    list_GageLength = tgl;
    list_ToolLength.clear();
    list_ToolLength = tal;
    list_TipLength.clear();
    list_TipLength = tfl;
    list_Counter.clear();
    list_Counter = tcounter;

    return;
}

int ToolSheet_Model::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return list_ID.length();
}

int ToolSheet_Model::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 6;
}

QVariant ToolSheet_Model::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();

    switch (role)
    {
    case Qt::DisplayRole:
        if(col == 0) return list_Counter[row];
        if(col == 1) return list_ID[row];
        if(col == 2) return list_GageLength[row];
        if(col == 3) return list_ToolLength[row];
        if(col == 4) return list_TipLength[row];
        if(col == 5) return list_Description[row];

    case Qt::FontRole:
        if(row == 0 ||
            list_Description[row].contains("EINLAGERN") ||
            list_Description[row].contains("AUSLAGERN"))
        {
            QFont boldFont;
            boldFont.setBold(true);
            return boldFont;
        }

    case Qt::BackgroundRole:
        if (row == 0 ||
            list_Description[row].contains("EINLAGERN") ||
            list_Description[row].contains("AUSLAGERN"))
            return QBrush(Qt::darkGray);
        //if(list_ID[row].contains("_X"))
        //    return QBrush(Qt::red);
        break;
        //    break;
        //default:
        //    break;
    }
    return QVariant();
}

QVariant ToolSheet_Model::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
    {
        if (section == 0)
        {
            return QString("Nr");
        }
        else if (section == 1)
        {
            return QString("Tool ID");
        }
        else if (section == 2)
        {
            return QString("GL");
        }
        else if (section == 3)
        {
            return QString("AL");
        }
        else if (section == 4)
        {
            return QString("FL");
        }
        else if (section == 5)
        {
            return QString("Beschreibung");
        }
    }
    return QVariant();
}
