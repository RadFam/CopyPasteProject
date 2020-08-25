#ifndef CPPSTMODEL_H
#define CPPSTMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include "cppstdata.h"

class CpPstModel : public QAbstractListModel
{
    Q_OBJECT

public:
    static constexpr size_t DEFAULT_VOLUME {5};

    CpPstModel(QObject *parent = nullptr, size_t lengo = DEFAULT_VOLUME);
    ~CpPstModel() override;
    //Q_INVOKABLE void PasteData(int index);
    Q_INVOKABLE void CopyData(int index, const QString& text);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant& value, int role = Qt::EditRole) override;

private:
    const size_t defaultLength;
    QList<CpPstData*> changeData;
};

#endif // CPPSTMODEL_H
