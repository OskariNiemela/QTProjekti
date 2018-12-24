#include "maptile.h"

namespace mapSpace
{

MapTile::MapTile():
    open_(false),
    impassable_(false)
{
    setDesc();
}

QRectF MapTile::boundingRect() const
{
    return QRectF(0,0,TILE_SIZE,TILE_SIZE);
}

void MapTile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{


    if(!impassable_)
    {
        if(open_)
        {
            //Draw the stuff on the tile

        }
        else
        {
            QColor gray(100,100,100);
            QBrush brush(gray);
            painter->setBrush(brush);
            //Draw a gray background

        }
    }
    else
    {
        QColor black(255,255,255);
        QBrush brush(black);
        painter->setBrush(brush);
        //Draw a blackbackground
    }
    QRect rect(0,0,TILE_SIZE,TILE_SIZE);

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

void MapTile::playerComin()
{
    open_ = true;
    update();
    emit giveDesc(desc_);
}

bool MapTile::impassable()
{
    return impassable_;
}

void MapTile::setDesc()
{
    desc_ = "You see open space to the north, west, south and east";
}



}
