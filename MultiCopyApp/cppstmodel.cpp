#include<QDebug>
#include "cppstmodel.h"

CpPstModel::CpPstModel(QObject* parent, size_t lengo):
    QAbstractListModel {parent},
    defaultLength {lengo}
{
    changeData = QList<CpPstData*>();
    for (size_t i = 0; i < defaultLength; ++i)
    {
        changeData.append(new CpPstData());
    }
    for (size_t i = 0; i < defaultLength; ++i)
    {
        qInfo() << changeData[i]->getInternalData();
    }
    qInfo() << "Model initialized";
}


CpPstModel::~CpPstModel()
{
    QList< CpPstData* >::iterator cpData = changeData.begin();

        while( changeData.end() != cpData )
        {
            // Release the memory associated with the task.
            delete (*cpData);
            ++cpData;
        }

        changeData.clear();
}

void CpPstModel::CopyData(int index, const QString &text)
{

}


int CpPstModel::rowCount(const QModelIndex &/*parent*/) const
{
    qInfo() << "Default Length " << defaultLength;
    return static_cast<int>(defaultLength);
}

QVariant CpPstModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole)
    {
        return {};
    }

    const auto index_row {static_cast<size_t>(index.row())};

    //return QVariant(static_cast<QString>(changeData[index_row].getInternalData()));
    return {};
}


bool CpPstModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole)
    {
        const auto index_row {static_cast<size_t>(index.row())};

        changeData[index_row]->setInternalData(value.toString());

        // Возможно, тут надо эмитировать сигнал
        //.....
        qInfo() << "Model added " << changeData[index_row]->getInternalData();

        return true;
    }

    return false;
}

