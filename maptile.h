#ifndef MAPTILE_H
#define MAPTILE_H

#include"coordinate.h"

#include <QGraphicsItem>
#include <QPainter>
#include <QObject>

namespace mapSpace
{
int const TILE_SIZE = 64;

class MapTile : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    MapTile();
    virtual ~MapTile();

    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget);
    virtual QPainterPath shape() const;

    void setPosition(map::Coordinate);

private:
    int x_;
    int y_;

    bool open_;
    bool empty_;


};

}


#endif // MAPTILE_H
