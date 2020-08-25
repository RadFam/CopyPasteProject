#include "gamecontroller.h"

GameController::GameController(QObject *parent) : QObject(parent)
{

}

CpPstModel* GameController::getModel()
{
    return &cppstModel;
}
