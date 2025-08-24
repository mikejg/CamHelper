#include "programmmodel.h"

ProgrammModel::ProgrammModel(QObject *parent)
    : QAbstractTableModel{parent}
{

}

// Create a method to populate the model with data:
void ProgrammModel::populateData(const QList<Programm> &prg)
{
    list_Programme = prg;
}

int ProgrammModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return list_Programme.length();
}

int ProgrammModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 3;
}

QVariant ProgrammModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();
    bool bool_Checked;

    switch (role)
    {
        case Qt::DisplayRole:
            if(col == 0) return list_Programme[row].ProgrammName;
            if(col == 1) return "";
            if(col == 2) return "";

        case Qt::CheckStateRole:
            if(col == 1)
            {
                bool_Checked = list_Programme[row].TOFFL;
                if(bool_Checked)
                    return Qt::Checked;
                else
                    return Qt::Unchecked;
            }

            if(col == 2)
            {
                bool_Checked = list_Programme[row].NoXY;
                if(bool_Checked)
                    return Qt::Checked;
                else
                    return Qt::Unchecked;
            }
    }
    return QVariant();
}

bool ProgrammModel::setData(const QModelIndex& index, const QVariant& value, int role)
{

    int row = index.row();
    int col = index.column();
    if(role == Qt::CheckStateRole)
    {
        if(col == 1)
        {
            if ((Qt::CheckState)value.toInt() == Qt::Checked)
            {
                list_Programme[row].TOFFL = true;
                emit sig_NewProgrammList(list_Programme);
                return true;
            }
            else
            {
                list_Programme[row].TOFFL = false;
                emit sig_NewProgrammList(list_Programme);
                return true;
            }
        }

        if(col == 2)
        {
            if ((Qt::CheckState)value.toInt() == Qt::Checked)
            {
                list_Programme[row].NoXY = true;
                emit sig_NewProgrammList(list_Programme);
                return true;
            }
            else
            {
                list_Programme[row].NoXY = false;
                emit sig_NewProgrammList(list_Programme);
                return true;
            }
        }
    }

    return true;
}

QVariant ProgrammModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
    {
        if (section == 0)
        {
            return QString("Programme");
        }
        else if (section == 1)
        {
            return QString("TOFFL");
        }
        else if (section == 2)
        {
            return QString("Kein X/Y");
        }
        /*else if (section == 3)
        {
            return QString("Y");
        }
        else if (section == 4)
        {
            return QString("Z");
        }
        */
    }
    return QVariant();
}

Qt::ItemFlags ProgrammModel::flags(const QModelIndex &index) const
{

    if(index.column() == 1 )
        return Qt::ItemIsUserCheckable | Qt::ItemIsEnabled;
    if(index.column() == 2 )
        return Qt::ItemIsUserCheckable | Qt::ItemIsEnabled;
    //Qt::ItemFlags flags = QAbstractItemModel::flags(index);
    return QAbstractItemModel::flags(index);

}
