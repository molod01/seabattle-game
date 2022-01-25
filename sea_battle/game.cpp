#include "game.h"

Game::Game(QObject *parent) : QObject{parent}{}

SeaBattleModel *Game::getModel()
{
    return &model;
}
