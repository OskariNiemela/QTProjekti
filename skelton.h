#ifndef SKELTON_H
#define SKELTON_H
#include "enemy.h"

namespace Combat
{
class Skelton : public Enemy
{
public:
    Skelton();
    void attack();
    bool takeDamage();
private:
    int hp;
    int speed;
    int strength;
};

}
#endif // SKELTON_H
