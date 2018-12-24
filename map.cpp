#include "map.h"
namespace mapSpace
{
Map::Map():
    scene_(new QGraphicsScene),
    playerStart_(Coordinate(1,1))
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
            connect(newTile.get(),&mapSpace::MapTile::giveDesc,this,&Map::getSceneDesc);
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
    Coordinate playerCoord(1,1);
    playerStart_ = playerCoord;
}

void Map::getSceneDesc(std::string desc)
{
    emit giveSceneDesc(desc);
}

QGraphicsScene* Map::giveScene()
{
    return scene_;
}

Coordinate Map::givePlayerStart() const
{
    return playerStart_;
}

bool Map::mapTileIsMovable(Coordinate coord)
{
    if(currMap.find(coord) != currMap.end())
    {
        return !currMap.find(coord)->second->impassable();
    }
    return false;
}

void Map::playerComes(Coordinate coord)
{
    currMap.find(coord)->second->playerComin();
    scene_->update();
}
}

