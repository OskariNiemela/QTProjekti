#include "mainmenu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    menu::MainMenu menu;

    menu.show();
    return a.exec();
}
