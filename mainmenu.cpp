#include "mainmenu.h"

namespace menu
{
MainMenu::MainMenu():
    title_(new QLabel),
    startGame_(new QPushButton),
    exitGame_(new QPushButton),
    layout_(new QVBoxLayout)
{
    InitializeMenu();
}

void MainMenu::GoToGame()
{

}

void MainMenu::Exit()
{

}

void MainMenu::InitializeMenu()
{
    QColor colour(100,100,100);
    QPixmap colorMap(64,64);

    colorMap.fill(colour);
    title_->setPixmap(colorMap);

    startGame_->setText("Start");
    exitGame_->setText("Exit");
    layout_->addWidget(title_);
    layout_->addWidget(startGame_);
    layout_->addWidget(exitGame_);

    connect(exitGame_,&QPushButton::clicked,this,&MainMenu::close);

    setLayout(layout_);
}


}

