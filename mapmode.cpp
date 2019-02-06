#include "mapmode.h"

namespace mapSpace
{
MapMode::MapMode():
    view_(new QGraphicsView),
    battleView_(new QGraphicsView),
    movementLayout_(new QGridLayout),
    battleLayout_(new QGridLayout),
    mainLayout_(new QHBoxLayout),
    battleVBox_(new QVBoxLayout),
    screenControls_(new QVBoxLayout),
    widget_ (new QWidget),
    controlWidget_(new QWidget),
    player_(new player::Player),
    desc_(new description::TextDescription)
{
    initLayouts();
    initMap();
}

void MapMode::initMap()
{
    map_ = new mapSpace::Map();


    connect(map_,&mapSpace::Map::giveSceneDesc,desc_,&description::TextDescription::changeText);
    QGraphicsScene* scene = map_->giveScene();
    scene->addItem(player_);
    player_->setCoordinate(map_->givePlayerStart());
    view_->setScene(map_->giveScene());

    QColor colour(100,100,100);
    QPixmap colorMap(64,64);
    QLabel label;

    colorMap.fill(colour);
    label.setPixmap(colorMap);

    screenControls_->addWidget(view_);


    controlWidget_->setLayout(movementLayout_);
    screenControls_->addWidget(controlWidget_);



    mainLayout_->addLayout(screenControls_);
    mainLayout_->addWidget(desc_);
    widget_->setLayout(mainLayout_);

    widget_->show();

    movePlayer(map_->givePlayerStart());
}

void MapMode::initLayouts()
{
    QPushButton* north = new QPushButton;
    QPushButton* west = new QPushButton;
    QPushButton* south = new QPushButton;
    QPushButton* east = new QPushButton;

    connect(north,&QPushButton::clicked,this,&MapMode::movePlayerNorth);
    connect(west,&QPushButton::clicked,this,&MapMode::movePlayerWest);
    connect(south,&QPushButton::clicked,this,&MapMode::movePlayerSouth);
    connect(east,&QPushButton::clicked,this,&MapMode::movePlayerEast);

    north->setText("N");
    west->setText("W");
    south->setText("S");
    east->setText("E");

    QPushButton* inventory = new QPushButton;
    QPushButton* save = new QPushButton;

    inventory->setText("Inventory");
    save->setText("Save");

    movementLayout_->addWidget(north,0,1,1,1);
    movementLayout_->addWidget(west,1,0,1,1);
    movementLayout_->addWidget(south,2,1,1,1);
    movementLayout_->addWidget(east,1,2,1,1);
    movementLayout_->addWidget(inventory,1,4,1,3);
    movementLayout_->addWidget(save,2,4,1,2);

    QPushButton* attack = new QPushButton;
    QPushButton* abilities = new QPushButton;
    QPushButton* useItem = new QPushButton;

    attack->setText("Attack");
    abilities->setText("Abilities");
    useItem->setText("Item");

    battleLayout_->addWidget(attack,0,0,4,1);
    battleLayout_->addWidget(abilities,0,1,4,1);
    battleLayout_->addWidget(useItem,0,2,4,1);

}

void MapMode::movePlayer(Coordinate coord)
{
    if(map_->mapTileIsMovable(coord))
    {
        //TO DO Check for doors
        currentBattle_ = map_->playerComes(coord);
        player_->setCoordinate(coord);

        if (currentBattle_ != nullptr)
        {
            goIntoBattle();
        }
    }
}

void MapMode::movePlayerNorth()
{
    int x = player_->getX();
    int y = player_->getY()-1;

    mapSpace::Coordinate coord(x,y);

    movePlayer(coord);
}

void MapMode::movePlayerWest()
{
    int x = player_->getX()-1;
    int y = player_->getY();

    mapSpace::Coordinate coord(x,y);

    movePlayer(coord);
}

void MapMode::movePlayerSouth()
{
    int x = player_->getX();
    int y = player_->getY()+1;

    mapSpace::Coordinate coord(x,y);

    movePlayer(coord);
}

void MapMode::movePlayerEast()
{
    int x = player_->getX()+1;
    int y = player_->getY();

    mapSpace::Coordinate coord(x,y);

    movePlayer(coord);
}

void MapMode::goIntoBattle()
{
    widget_->hide();
    //delete (widget_);

    battleWidget_ = new QWidget;
    battleControl_ = new QWidget;
    battleScreen_ = new QHBoxLayout;
    desc_->changeText(currentBattle_->enterBattle());
    view_ = battleView_;

    battleVBox_->addWidget(view_);
    battleVBox_->addLayout(battleLayout_);


    battleControl_->setLayout(battleVBox_);

    battleScreen_->addWidget(battleControl_);

    battleScreen_->addWidget(desc_);

    battleWidget_->setLayout(battleScreen_);
    battleWidget_->show();
}

}


