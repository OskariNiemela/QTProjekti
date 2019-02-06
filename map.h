#ifndef MAP_H
#define MAP_H
#include "coordinate.h"
#include "maptile.h"

#include <map>
#include <QGraphicsScene>
#include <QObject>
#include <string>
#include <memory>
#include <string>

namespace mapSpace
{
class Map : public QObject
{
    Q_OBJECT
public:
    Map();

    QGraphicsScene *giveScene();
    mapSpace::Coordinate givePlayerStart() const;
    bool mapTileIsMovable(mapSpace::Coordinate coord);
    Combat::Battle* playerComes(mapSpace::Coordinate coord);
private:
    std::map<mapSpace::Coordinate,std::shared_ptr<mapSpace::MapTile>> currMap;
    QGraphicsScene* scene_;
    mapSpace::Coordinate playerStart_;
    Combat::Battle* currentBattle_;

    void initMap();

signals:
    void giveSceneDesc(std::string);
public slots:
    void getSceneDesc(std::string desc);
};
}


#endif // MAP_H
