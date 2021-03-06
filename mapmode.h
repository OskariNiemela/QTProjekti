#ifndef MAPMODE_H
#define MAPMODE_H

#include "map.h"
#include "player.h"
#include "textdescription.h"

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
    void initBattle();
    void initLayouts();
    void movePlayer(mapSpace::Coordinate coord);
public slots:
    void movePlayerNorth();
    void movePlayerWest();
    void movePlayerSouth();
    void movePlayerEast();

private:
    QGraphicsView* view_;
    QGraphicsView* battleView_;


    QGridLayout* movementLayout_;
    QGridLayout* battleLayout_;

    QHBoxLayout* mainLayout_;
    QHBoxLayout* battleScreen_;
    QVBoxLayout* battleVBox_;

    QVBoxLayout* screenControls_;

    QWidget* widget_;
    QWidget* controlWidget_;
    QWidget* battleWidget_;
    QWidget* battleControl_;

    player::Player* player_;
    mapSpace::Map* map_;
    description::TextDescription* desc_;

    Combat::Battle* currentBattle_;

    void goIntoBattle();
};
}


#endif // MAPMODE_H
