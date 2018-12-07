#include "maptile.h"

namespace mapSpace
{

MapTile::MapTile()
{

}

QRectF MapTile::boundingRect() const
{
    return QRectF(-TILE_SIZE,-TILE_SIZE,TILE_SIZE,TILE_SIZE);
}

void MapTile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRect rect(-TILE_SIZE,-TILE_SIZE,TILE_SIZE,TILE_SIZE);

    painter->drawRect(rect);
}

QPainterPath MapTile::shape() const
{
    QRect rect(-TILE_SIZE,-TILE_SIZE,TILE_SIZE,TILE_SIZE);
    QPainterPath path;
    path.addRect(rect);

    return path;
}

void MapTile::setPosition(Coordinate coord)
{
    int xpos = coord.x*TILE_SIZE;
    int ypos = coord.y*TILE_SIZE;
    coord_ = coord;
    setPos(xpos,ypos);
}

void MapTile::addNeighbour(Coordinate neighbourCoord, std::shared_ptr<MapTile> tile)
{
    neighbours[neighbourCoord] = tile;
}

Coordinate MapTile::giveCoord() const
{
    return coord_;
}



}
