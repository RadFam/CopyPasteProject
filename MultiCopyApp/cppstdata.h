#ifndef CPPSTDATA_H
#define CPPSTDATA_H

#include <QObject>

class CpPstData
{
public:
    CpPstData();
    CpPstData(const QString& text);
    ~CpPstData();

    QString getInternalData() const;
    void setInternalData(const QString &value);

private:
    QString internalData;
};

#endif // CPPSTDATA_H
