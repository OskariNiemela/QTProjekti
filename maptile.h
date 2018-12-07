#ifndef MAPTILE_H
#define MAPTILE_H

#include"coordinate.h"

#include <QGraphicsItem>
#include <QPainter>
#include <QObject>
#include <map>
#include <memory>

namespace mapSpace
{
int const TILE_SIZE = 64;

class MapTile : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    explicit MapTile();

    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget);
    virtual QPainterPath shape() const;

    void setPosition(mapSpace::Coordinate coord);

    void addNeighbour(mapSpace::Coordinate neighbourCoord,std::shared_ptr<MapTile> tile);

    mapSpace::Coordinate giveCoord() const;

private:
    int x_;
    int y_;
    mapSpace::Coordinate coord_;

    std::map<mapSpace::Coordinate,std::shared_ptr<MapTile>> neighbours;

    bool open_;
    bool empty_;


};

}


#endif // MAPTILE_H
