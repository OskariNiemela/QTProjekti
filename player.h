#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsObject>
#include <QImage>

namespace player
{
class Player: public QObject, public QGraphicsObject
{
    Q_OBJECT
public:
    Player();


private:
    int x_;
    int y_;



};

}


#endif // PLAYER_H
