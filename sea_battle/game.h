#ifndef GAME_H
#define GAME_H

#include <QObject>
#include "model.h"

class Game : public QObject
{
    Q_OBJECT
    SeaBattleModel model;
public:
    explicit Game(QObject *parent = nullptr);
    Q_INVOKABLE SeaBattleModel* getModel();
};

#endif // GAME_H
