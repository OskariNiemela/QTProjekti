#include "mainmenu.h"
#include "mapmode.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    menu::MainMenu menu;

    mapSpace::MapMode screen;

    return a.exec();
}
