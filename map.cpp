#include "map.h"
namespace mapSpace
{
Map::Map():
    scene_(new QGraphicsScene)
{
    initMap();
}

void Map::initMap()
{
    int width = 15;
    int height = 15;

    for(int yCoord = 0;yCoord < height;++yCoord)
    {
        for(int xCoord = 0;xCoord < width;++xCoord)
        {
            Coordinate newCoord(xCoord,yCoord);
            std::shared_ptr<MapTile> newTile = std::make_shared<MapTile>();
            scene_->addItem(newTile.get());
            newTile->setPosition(newCoord);
            int y = 0;
            currMap[newCoord] = newTile;
            for(int x = -1;x<=0;++x)
            {
                Coordinate coordComp(xCoord+x,yCoord+y);
                if(currMap.find(coordComp) != currMap.end())
                {
                    currMap.at(coordComp)->addNeighbour(newCoord,newTile);
                    currMap.at(newCoord)->addNeighbour(currMap.at(coordComp)->giveCoord(),newTile);
                }
                --y;
            }

        }
    }
}

QGraphicsScene* Map::giveScene()
{
    return scene_;
}
}

