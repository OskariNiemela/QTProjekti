#include "player.h"

namespace player
{
Player::Player()
{

}

void Player::setCoordinate(mapSpace::Coordinate coord)
{
    coord_ = coord;
    x_ = coord.x;
    y_ = coord.y;

    setPos(x_*mapSpace::TILE_SIZE,y_*mapSpace::TILE_SIZE);
    update();
}

QRectF Player::boundingRect() const
{
    return QRectF(-5,-5,5,5);
}
void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
      painter->drawText(QPoint(32,32),"x");
}

QPainterPath Player::shape() const
{
    QRect rect(-5,-5,5,5);
    QPainterPath path;
    path.addRect(rect);
    return path;
}

int Player::getX() const
{
    return x_;
}

int Player::getY() const
{
    return y_;
}
}


