#ifndef MAPMODE_H
#define MAPMODE_H

#include "map.h"
#include "player.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QGridLayout>

#include <QPixmap>
#include <QLabel>
#include <QColor>


namespace mapSpace
{
class MapMode : public QObject
{
    Q_OBJECT
public:
    MapMode();
    void initMap();
    void initLayouts();
    void movePlayer(mapSpace::Coordinate coord);
public slots:
    void movePlayerNorth();
    void movePlayerWest();
    void movePlayerSouth();
    void movePlayerEast();

private:
    QGraphicsView* view_;

    QGridLayout* movementLayout_;
    QGridLayout* battleLayout_;

    QHBoxLayout* mainLayout_;
    QVBoxLayout* screenControls_;

    QWidget* widget_;
    QWidget* controlWidget_;

    player::Player* player_;
    mapSpace::Map* map_;
};
}


#endif // MAPMODE_H
