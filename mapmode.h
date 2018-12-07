#ifndef MAPMODE_H
#define MAPMODE_H

#include "map.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>

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
private:
    QGraphicsView* view_;

    QGridLayout* movementLayout_;
    QGridLayout* battleLayout_;

    QHBoxLayout* mainLayout_;
    QVBoxLayout* screenControls_;

    QWidget* widget_;
};
}


#endif // MAPMODE_H
