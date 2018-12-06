#ifndef MAPMODE_H
#define MAPMODE_H

#include "map.h"

#include <QGraphicsView>
#include <QGraphicsScene>

namespace mapSpace
{
class MapMode
{
public:
    MapMode();

private:
    QGraphicsScene* scene_;
};
}


#endif // MAPMODE_H
