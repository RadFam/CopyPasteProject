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

    clipboard = QGuiApplication::clipboard();
    clipString = "";
    //qInfo() << "Model initialized";
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

void CpPstModel::getClipboardData(int ind)
{
    //changeData[ind]->setInternalData(clipboard->text());
    setData(index(ind, 0), clipboard->text(), Qt::EditRole);
    qInfo() << "Model changed " << changeData[ind]->getInternalData();
}

void CpPstModel::setClipboardData(int ind)
{
    clipboard->setText(changeData[ind]->getInternalData());
    qInfo() << "Model saved " << changeData[ind]->getInternalData();
}

int CpPstModel::rowCount(const QModelIndex &/*parent*/) const
{
    return static_cast<int>(defaultLength);
}

QVariant CpPstModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole)
    {
        return {};
    }

    const auto index_row {static_cast<size_t>(index.row())};

    if (role == Qt::DisplayRole){
        return changeData[index_row]->getInternalData();
        //return QVariant(static_cast<QString>(changeData[index_row]->getInternalData()));

    }

    return {};
}


bool CpPstModel::setData(const QModelIndex &ind, const QVariant &value, int role)
{
    if (ind.isValid() && role == Qt::EditRole)
    {
        const auto index_row {static_cast<size_t>(ind.row())};

        changeData[index_row]->setInternalData(value.toString());
        emit dataChanged(ind, ind, { Qt::EditRole, Qt::DisplayRole });
        qInfo() << "Model added " << changeData[index_row]->getInternalData();

        return true;
    }
    qInfo() << "Model not added";

    return false;
}

QString CpPstModel::getClipString() const
{
    return clipString;
}

void CpPstModel::setClipString(const QString &value)
{
    clipString = value;
}

