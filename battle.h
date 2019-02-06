#ifndef BATTLE_H
#define BATTLE_H
#include "enemy.h"

#include <string>
#include <QObject>
#include <QGraphicsView>

namespace Combat
{

class Battle
{
public:
    Battle();
    std::string damageCombatant(int damage, int pos);
    std::string enterBattle();
    QGraphicsView* getView();
private:
    void initCombat();
    Combat::Enemy* combatants[4];
    QGraphicsView* view_;
};

}



#endif // BATTLE_H
