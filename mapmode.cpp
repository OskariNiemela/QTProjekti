#include "mapmode.h"

namespace mapSpace
{
MapMode::MapMode():
    view_(new QGraphicsView),
    mainLayout_(new QHBoxLayout),
    screenControls_(new QVBoxLayout),
    widget_ (new QWidget)
{
    initLayouts();
    initMap();
}

void MapMode::initMap()
{
    mapSpace::Map map;

    view_->setScene(map.giveScene());

    QColor colour(100,100,100);
    QPixmap colorMap(64,64);
    QLabel label;

    colorMap.fill(colour);
    label.setPixmap(colorMap);

    screenControls_->addWidget(view_);
    screenControls_->addWidget(&label);

    mainLayout_->addLayout(screenControls_);

    widget_->setLayout(mainLayout_);

    widget_->show();
}

void MapMode::initLayouts()
{

}
}


