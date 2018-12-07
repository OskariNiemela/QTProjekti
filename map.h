#ifndef MAP_H
#define MAP_H
#include "coordinate.h"
#include "maptile.h"

#include <map>
#include <QGraphicsScene>
#include <string>
#include <memory>

namespace mapSpace
{
class Map
{
public:
    Map();

    QGraphicsScene *giveScene();
private:
    std::map<mapSpace::Coordinate,std::shared_ptr<mapSpace::MapTile>> currMap;
    QGraphicsScene* scene_;

    void initMap();
};
}


#endif // MAP_H
