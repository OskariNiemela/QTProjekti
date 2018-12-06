#ifndef MAP_H
#define MAP_H
#include "coordinate.h"
#include "maptile.h"

#include <map>
#include <QGraphicsScene>


namespace mapSpace
{
class Map
{
public:
    Map();
private:
    std::map<mapSpace::Coordinate,mapSpace::MapTile> currMap;
    QGraphicsScene* scene_;

    void initMap();
};
}


#endif // MAP_H
