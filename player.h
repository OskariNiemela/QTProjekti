#ifndef PLAYER_H
#define PLAYER_H
#include "coordinate.h"
#include "maptile.h"

#include <QGraphicsObject>
#include <QImage>

namespace player
{
class Player: public QGraphicsObject
{
    Q_OBJECT
public:
    explicit Player();
    void setCoordinate(mapSpace::Coordinate coord);

    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget);
    virtual QPainterPath shape() const;

    int getX() const;
    int getY() const;

private:
    int x_;
    int y_;
    mapSpace::Coordinate coord_;


};

}


#endif // PLAYER_H
