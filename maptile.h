#ifndef MAPTILE_H
#define MAPTILE_H

#include "coordinate.h"
#include "battle.h"

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

    Combat::Battle* playerComin();

    bool impassable();
    Combat::Battle giveBattle();

private:
    int x_;
    int y_;
    mapSpace::Coordinate coord_;

    std::map<mapSpace::Coordinate,std::shared_ptr<MapTile>> neighbours;

    Combat::Battle* battle_;

    bool open_;
    bool impassable_;

    std::string desc_;

    void setDesc();
signals:
    void giveDesc(std::string);
};

}


#endif // MAPTILE_H
