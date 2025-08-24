#include "toolmodel.h"

ToolModel::ToolModel(QObject *parent)
    : QAbstractTableModel{parent}
{

}

// Create a method to populate the model with data:
void ToolModel::populateData(ToolList* tl)
{
    list_Tools = tl->get_List();
}

int ToolModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return list_Tools.length();
}

int ToolModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 4;
}

QVariant ToolModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();
    bool bool_Checked;

    switch (role)
    {
    case Qt::DisplayRole:
        if(col == 0) return list_Tools[row]->get_Number();
        if(col == 1) return "";
        if(col == 2) return list_Tools[row]->get_Parts();

    case Qt::CheckStateRole:
        if(col == 1)
        {
            bool_Checked = list_Tools[row]->get_ToolLife();
            if(bool_Checked)
                return Qt::Checked;
            else
                return Qt::Unchecked;
        }

    }
    return QVariant();
}

bool ToolModel::setData(const QModelIndex& index, const QVariant& value, int role)
{

    int row = index.row();
    int col = index.column();
    if(role == Qt::CheckStateRole)
    {
        if(col == 1)
        {
            if ((Qt::CheckState)value.toInt() == Qt::Checked)
            {
                list_Tools[row]->set_ToolLife(true);
                //emit sig_NewProgrammList(list_Programme);
                return true;
            }
            else
            {
                list_Tools[row]->set_ToolLife(false);
                //emit sig_NewProgrammList(list_Programme);
                return true;
            }
        }

        /*if(col == 2)
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
       */
    }
    if(role == Qt::EditRole)
    {
        if(col == 2)
        {
            list_Tools[row]->set_Parts(value.toInt());
        }
    }
    return true;
}

QVariant ToolModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
    {
        if (section == 0)
        {
            return QString("T_Nummer");
        }
        else if (section == 1)
        {
            return QString("Standzeit");
        }
        else if (section == 2)
        {
            return QString("Teile");
        }
        else if (section == 3)
        {
            return QString("Loeschen");
        }
    }
    return QVariant();
}

Qt::ItemFlags ToolModel::flags(const QModelIndex &index) const
{
    //int col = index.column();
    int row = index.row();
    if(index.column() == 1 )
        return Qt::ItemIsUserCheckable | Qt::ItemIsEnabled;
    if(index.column() == 2 )
    {
        if(list_Tools[row]->get_ToolLife())
            return Qt::ItemIsEditable | Qt::ItemIsEnabled;
        else
            return Qt::NoItemFlags;
    }

    //Qt::ItemFlags flags = QAbstractItemModel::flags(index);
    return QAbstractItemModel::flags(index);

}

void ToolModel::delete_Tool(int int_Row)
{
    beginRemoveRows(QModelIndex(), int_Row, int_Row);
    list_Tools.removeAt(int_Row);
    endRemoveRows();
}
