#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include "cppstmodel.h"

class GameController : public QObject
{
    Q_OBJECT
public:
    explicit GameController(QObject *parent = nullptr);

    Q_INVOKABLE CpPstModel* getModel();

private:
    CpPstModel cppstModel;

};

#endif // GAMECONTROLLER_H
