#include "cppstdata.h"

CpPstData::CpPstData()
{
    internalData = "QWERTY";
}

CpPstData::CpPstData(const QString &text)
{
    internalData = text;
}

CpPstData::~CpPstData()
{

}

QString CpPstData::getInternalData() const
{
    return internalData;
}

void CpPstData::setInternalData(const QString &value)
{
    internalData = value;
}
