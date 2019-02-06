#include "battle.h"
#include "skelton.h"

namespace Combat
{

Battle::Battle()
{

}

void Battle::initCombat()
{
    combatants[0] = new Skelton();
}

std::string Battle::damageCombatant(int damage, int pos)
{
    return "U do dmg";
}

std::string Battle::enterBattle()
{
    return "Im going into Battle";
}

}


