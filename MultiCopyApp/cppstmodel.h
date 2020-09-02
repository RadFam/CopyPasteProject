#ifndef CPPSTMODEL_H
#define CPPSTMODEL_H

#include <QObject>
#include <QClipboard>
#include <QGuiApplication>
#include <QAbstractListModel>
#include "cppstdata.h"

class CpPstModel : public QAbstractListModel
{
    Q_OBJECT

public:
    static constexpr size_t DEFAULT_VOLUME {5};

    CpPstModel(QObject *parent = nullptr, size_t lengo = DEFAULT_VOLUME);
    ~CpPstModel() override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant& value, int role = Qt::EditRole) override;

    QString getClipString() const;
    void setClipString(const QString &value);

    Q_INVOKABLE
    void getClipboardData(int index);
    Q_INVOKABLE
    void setClipboardData(int index);

private:
    const size_t defaultLength;
    QList<CpPstData*> changeData;
    QClipboard *clipboard;
    QString clipString;
};

#endif // CPPSTMODEL_H
